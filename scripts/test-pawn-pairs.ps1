param([string]$Compiler = 'g++')
$ErrorActionPreference = 'Stop'
$repo = Split-Path $PSScriptRoot -Parent
$output = Join-Path ([System.IO.Path]::GetTempPath()) ('integral-pawn-pairs-' + [guid]::NewGuid().ToString('N') + '.exe')
$sources = @(
    'tests/pawn_pair_accumulator_test.cc',
    'src/engine/evaluation/nnue/threat_accumulator.cc',
    'src/engine/evaluation/nnue/pawn_pair/pawn_pair_features.cc',
    'src/engine/evaluation/nnue/threats/threat_features.cc',
    'src/chess/move_gen.cc',
    'src/magics/attacks.cc'
) | ForEach-Object { Join-Path $repo $_ }
try {
    & $Compiler '-std=c++20' '-O1' '-msse4.1' '-mpopcnt' '-DBUILD_SSE41_POPCNT' '-DFMT_HEADER_ONLY' "-I$repo" "-I$repo/third-party/fmt/include" '-fconstexpr-ops-limit=1000000000' @sources '-o' $output
    if ($LASTEXITCODE -ne 0) { throw 'Pawn-pair test compilation failed' }
    & $output
    if ($LASTEXITCODE -ne 0) { throw 'Pawn-pair tests failed' }
} finally {
    if (Test-Path -LiteralPath $output) { Remove-Item -LiteralPath $output }
}
