using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using UndertaleModLib;
using UndertaleModLib.Compiler;
using UndertaleModLib.Decompiler;
using Underanalyzer.Decompiler;

static class RoundTrip
{
    // Mirrors upstream CheckDecompiler.csx, but snapshots ALL originals before
    // any compilation and never writes mutated UndertaleData back to disk.
    public static bool Run(UndertaleData data, string output)
    {
        var codes = data.Code.ToArray();
        var before = codes.Select(c => c.Disassemble(data.Variables, data.CodeLocals?.For(c))).ToArray();
        var global = new GlobalDecompileContext(data);
        var differences = Path.Combine(output, "roundtrip-differences");
        Directory.CreateDirectory(differences);
        using var log = new StreamWriter(Path.Combine(output, "roundtrip.jsonl"), false, new UTF8Encoding(false)) { AutoFlush = true };
        int compiled = 0, failed = 0, sameAssembly = 0, sameGml = 0, warned = 0;
        for (int id = 0; id < codes.Length; id++)
        {
            var code = codes[id];
            var name = code.Name.Content;
            try
            {
                var gml = File.ReadAllText(Path.Combine(output, $"code/{id:D4}.gml"));
                var group = new CompileGroup(data, global);
                group.QueueCodeReplace(code, gml);
                var result = group.Compile();
                if (!result.Successful)
                    throw new InvalidDataException("GML compile failed: " + string.Join("\n", result.Errors.Select(e => e.ToString())));
                var assembly = code.Disassemble(data.Variables, data.CodeLocals?.For(code));
                var context = new DecompileContext(global, code, data.ToolInfo.DecompilerSettings);
                var secondGml = context.DecompileToString();
                compiled++;
                bool assemblyEqual = before[id] == assembly;
                bool gmlEqual = gml == secondGml;
                if (assemblyEqual) sameAssembly++;
                if (gmlEqual) sameGml++;
                if (context.Warnings.Count > 0) warned++;
                if (!assemblyEqual || !gmlEqual)
                {
                    File.WriteAllText(Path.Combine(differences, $"{id:D4}.before.asm"), before[id]);
                    File.WriteAllText(Path.Combine(differences, $"{id:D4}.after.asm"), assembly);
                    File.WriteAllText(Path.Combine(differences, $"{id:D4}.after.gml"), secondGml);
                }
                log.WriteLine(JsonSerializer.Serialize(new { id, name, status = "compiled", assembly_equal = assemblyEqual,
                    redecompiled_text_equal = gmlEqual, warnings = context.Warnings.Select(w => w.ToString()).ToArray() }));
            }
            catch (Exception error)
            {
                failed++;
                log.WriteLine(JsonSerializer.Serialize(new { id, name, status = "failed", error = error.ToString() }));
            }
            if ((id + 1) % 50 == 0 || id + 1 == codes.Length)
                Console.WriteLine($"roundtrip={id + 1}/{codes.Length} compiled={compiled} failed={failed} same_assembly={sameAssembly} same_gml={sameGml}");
        }
        var summary = new { code_count = codes.Length, compiled, failed,
            same_symbolic_disassembly = sameAssembly, same_redecompiled_text = sameGml, warned,
            raw_binary_equality_verified = false, runtime_verified = false,
            scope = "in-memory sequential per-CODE compile; original assembly snapshots taken before mutation; no game.droid write" };
        File.WriteAllText(Path.Combine(output, "roundtrip-summary.json"), JsonSerializer.Serialize(summary, new JsonSerializerOptions { WriteIndented = true }));
        Console.WriteLine(JsonSerializer.Serialize(summary));
        return failed == 0;
    }
}
