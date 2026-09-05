using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using UndertaleModLib;
using UndertaleModLib.Decompiler;
using Underanalyzer.Decompiler;

// A batch adapter for the pinned upstream decompiler; not a new decompiler.
// Input bytes are never written back. Per-entry failures survive in JSONL.
if (args.Length is < 2 or > 3 || (args.Length == 3 && args[2] != "--roundtrip"))
    throw new ArgumentException("usage: Recover INPUT OUTPUT [--roundtrip]");
const string ExpectedHash = "9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6";
const string UmtCommit = "f43e12c445c37d50dc6244caa12ccab232983f3f";
const string AnalyzerCommit = "4ff50a866b4c1a7acee8cebe6a56d6a48709b453";
var input = Path.GetFullPath(args[0]);
var output = Path.GetFullPath(args[1]);
var inputHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(input))).ToLowerInvariant();
if (inputHash != ExpectedHash) throw new InvalidDataException("input SHA256 mismatch");
if (Directory.Exists(output) && Directory.EnumerateFileSystemEntries(output).Any())
    throw new IOException("output must be empty to prevent stale GML being reported");
Directory.CreateDirectory(Path.Combine(output, "code"));
var jsonOptions = new JsonSerializerOptions { WriteIndented = true };
var loadWarnings = new List<object>();
using var stream = File.OpenRead(input);
var data = UndertaleIO.Read(stream, (message, important) => loadWarnings.Add(new { message, important }));
File.WriteAllText(Path.Combine(output, "load-warnings.json"), JsonSerializer.Serialize(loadWarnings, jsonOptions));
if (data.GeneralInfo.BytecodeVersion != 16 || data.Code.Count != 1354)
    throw new InvalidDataException("unexpected bytecode version or CODE count");
var global = new GlobalDecompileContext(data);
using var manifest = new StreamWriter(Path.Combine(output, "entries.jsonl"), false, new UTF8Encoding(false)) { AutoFlush = true };
int succeeded = 0, failed = 0, warned = 0;
for (int id = 0; id < data.Code.Count; id++)
{
    var code = data.Code[id];
    var name = code.Name.Content;
    try
    {
        if (code.ParentEntry is not null) throw new InvalidDataException("child CODE cannot be independently decompiled");
        var context = new DecompileContext(global, code, data.ToolInfo.DecompilerSettings);
        var text = context.DecompileToString();
        var bytes = new UTF8Encoding(false).GetBytes(text);
        // Numeric IDs are authoritative; resource names never become paths.
        var file = $"code/{id:D4}.gml";
        File.WriteAllBytes(Path.Combine(output, file), bytes);
        var warnings = context.Warnings.Select(w => new { type = w.GetType().FullName, text = w.ToString() }).ToArray();
        manifest.WriteLine(JsonSerializer.Serialize(new { id, name, status = "exported", file, bytes = bytes.Length,
            sha256 = Convert.ToHexString(SHA256.HashData(bytes)).ToLowerInvariant(), warnings,
            semantics_verified = false, runtime_verified = false }));
        succeeded++;
        if (warnings.Length > 0) warned++;
    }
    catch (Exception error)
    {
        manifest.WriteLine(JsonSerializer.Serialize(new { id, name, status = "failed", error = error.ToString() }));
        failed++;
    }
    if ((id + 1) % 50 == 0 || id + 1 == data.Code.Count)
        Console.WriteLine($"processed={id + 1}/{data.Code.Count} exported={succeeded} failed={failed} warned={warned}");
}
var summary = new { input_sha256 = inputHash, umt_commit = UmtCommit, underanalyzer_commit = AnalyzerCommit,
    code_count = data.Code.Count, exported = succeeded, failed, warned,
    load_warning_count = loadWarnings.Count, semantics_verified = 0, runtime_verified = 0 };
File.WriteAllText(Path.Combine(output, "summary.json"), JsonSerializer.Serialize(summary, jsonOptions));
Console.WriteLine(JsonSerializer.Serialize(summary));
Environment.ExitCode = failed == 0 ? 0 : 2;
if (failed == 0 && args.Length == 3 && !RoundTrip.Run(data, output))
    Environment.ExitCode = 3;
