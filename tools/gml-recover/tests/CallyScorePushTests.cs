using Underanalyzer.Mock;

namespace UnderanalyzerTest;

public class CallyScorePushTests
{
    [Fact]
    public void Gml1SpecializedSelfReadKeepsOrdinaryAssignment()
    {
        TestUtil.VerifyDecompileResult(
            """
            pushbltn.v self.score
            pushi.e 4
            add.i.v
            pop.v.v self.score
            """,
            "score = score + 4;",
            new GameContextMock { UsingGMLv2 = false, Bytecode14OrLower = false, UsingGMS2OrLater = false });
    }

    [Fact]
    public void Gml1RegularSelfReadKeepsCompoundAssignment()
    {
        TestUtil.VerifyDecompileResult(
            """
            push.v self.score
            pushi.e 4
            add.i.v
            pop.v.v self.score
            """,
            "score += 4;",
            new GameContextMock { UsingGMLv2 = false, Bytecode14OrLower = false, UsingGMS2OrLater = false });
    }

    [Fact]
    public void Gml2SelfExceptionRemainsUnchanged()
    {
        TestUtil.VerifyDecompileResult(
            """
            pushbltn.v self.score
            pushi.e 4
            add.i.v
            pop.v.v self.score
            """,
            "score += 4;",
            new GameContextMock { UsingGMLv2 = true, Bytecode14OrLower = false });
    }
}
