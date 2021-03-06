@echo on

set PATH=%PATH%;C:\Program Files\Git\cmd
set PATH=%PATH%;C:\Program Files\CMake\bin
set PATH=%PATH%;C:\Program Files\Git\mingw64\bin
set "VSCMD_START_DIR=%CD%"
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

set build_root=build_windows_x86_msvc
call :compile "%build_windows_x86_gcc%_nointr"   "-DMIPP_NO_INTRINSICS"
call :compile "%build_windows_x86_gcc%_sse2"     "/arch:SSE2"
call :compile "%build_windows_x86_gcc%_sse3"     "/arch:SSE3"
call :compile "%build_windows_x86_gcc%_ssse3"    "/arch:SSSE3"
call :compile "%build_windows_x86_gcc%_sse4_1"   "/arch:SSE4.1"
call :compile "%build_windows_x86_gcc%_sse4_2"   "/arch:SSE4.2"
call :compile "%build_windows_x86_gcc%_avx"      "/arch:AVX"
call :compile "%build_windows_x86_gcc%_avx2_fma" "/arch:AVX2"
call :compile "%build_windows_x86_gcc%_avx512f"  "/arch:AVX512"

exit /B %ERRORLEVEL%

:compile
set build=%~1%
set params=%~2%
mkdir %build%
cd %build%
cmake .. -G"Visual Studio 15 2017 Win64" -DCMAKE_CXX_FLAGS="-D_CRT_SECURE_NO_DEPRECATE /EHsc %params%"
if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%
devenv /build Release run_tests.sln
if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%
cd ..
exit /B 0