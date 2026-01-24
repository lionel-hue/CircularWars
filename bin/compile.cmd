@echo off
echo 🔨 Building Circular Wars...

REM Create app directory if it doesn't exist
if not exist "app" mkdir app

REM Check for MinGW or MSYS2
where g++ >nul 2>nul
if %errorlevel% equ 0 (
    echo ✅ Found g++ compiler
    g++ -o "app/circular_wars.exe" src/*.cc src/*.cpp -Iheader -Iraylib -Lraylib -lraylib -std=c++17 -lopengl32 -lgdi32 -lwinmm
    if %errorlevel% equ 0 (
        echo ✅ Build successful!
        echo 🎮 Run the game with: app\circular_wars.exe
        for %%F in ("app/circular_wars.exe") do (
            set size=%%~zF
            set /a size_kb=!size! / 1024
            echo 📦 Executable size: !size_kb! KB
        )
    ) else (
        echo ❌ Build failed!
        exit /b 1
    )
) else (
    echo Checking for Visual Studio...
    where cl >nul 2>nul
    if %errorlevel% equ 0 (
        echo ✅ Found Visual Studio compiler
        cl /EHsc /Iheader /Iraylib src\*.cc src\*.cpp raylib\libraylib.lib /link opengl32.lib gdi32.lib winmm.lib /out:app\circular_wars.exe
        if %errorlevel% equ 0 (
            echo ✅ Build successful!
            echo 🎮 Run the game with: app\circular_wars.exe
            for %%F in ("app/circular_wars.exe") do (
                set size=%%~zF
                set /a size_kb=!size! / 1024
                echo 📦 Executable size: !size_kb! KB
            )
        ) else (
            echo ❌ Build failed!
            exit /b 1
        )
    ) else (
        echo ❌ No C++ compiler found!
        echo Please install MinGW or Visual Studio
        exit /b 1
    )
)

pause