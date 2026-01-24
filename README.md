# 🎮 Circular Wars

<div align="center">

![Game Screenshot](./assets/InShot_20250430_133148594.gif)

*A fast-paced circular shooter game with enemies attacking from all directions!*

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Raylib](https://img.shields.io/badge/Raylib-5.0-green.svg)](https://www.raylib.com/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20|%20Windows%20|%20macOS-lightgrey.svg)]()

</div>

## 🚀 Features

- **360° Combat**: Enemies attack from all directions
- **Dynamic Projectiles**: Shoot with mouse controls
- **Health System**: Visual health bar with numeric display
- **Score Tracking**: Real-time score calculation
- **Audio System**: Background music and sound effects
- **Smooth Animations**: Particle-like effects and smooth movement
- **Pause/Resume**: Game state management

## 📁 Project Structure

```
CircularWars/
├── app/                      # Compiled executable
│   └── circular_wars
├── assets/                   # Game assets
│   ├── health.png           # Health bar texture
│   ├── health_original.png  # Original health texture
│   └── Screenshot*.png      # Game screenshots
├── audio/                   # Sound effects and music
│   ├── laser-gun-81720.mp3
│   ├── game-over-deep-robotic-voice-tomas-herudek-1-1-00-03.mp3
│   └── Warriyo - Mortals (feat. Laura Brehm).mp3
├── bin/                     # Build scripts
│   ├── compile.sh          # Linux/macOS build script
│   └── compile.cmd         # Windows build script
├── fonts/                   # Custom fonts
│   ├── BAUHS93.TTF
│   ├── FiraCode-Medium.ttf
│   └── impact.ttf
├── header/                  # Header files
│   └── declare.h           # Main declarations
├── raylib/                  # Raylib library
│   ├── libraylib.a         # Static library
│   ├── raylib.h           # Header
│   └── raygui.h           # GUI extension
├── src/                     # Source code
│   ├── main.cpp           # Entry point
│   ├── game.cc            # Game logic
│   └── tools.cc           # Utility classes
├── Dockerfile              # Containerization
├── CircularWars.code-workspace # VS Code workspace
└── README.md               # This file
```

## 🛠️ Installation

### Prerequisites

- **C++17 compiler** (g++, clang++, or MSVC)
- **CMake** (optional, for alternative builds)
- **Make** or equivalent build system

### Method 1: Using Provided Build Scripts (Recommended)

#### Linux/macOS:
```bash
# Make the build script executable
chmod +x ./bin/compile.sh

# Run the build script
./bin/compile.sh

# The executable will be created in ./app/circular_wars
```

#### Windows:
```bash
# Run the Windows batch script
./bin/compile.cmd

# Or double-click compile.cmd in File Explorer
```

### Method 2: Manual Compilation

#### Linux:
```bash
# Install Raylib dependencies
sudo apt-get update
sudo apt-get install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

# Compile the game
g++ -o ./app/circular_wars ./src/*.cc ./src/*.cpp -I./header -I./raylib -L./raylib -lraylib -lm -lpthread -ldl -lX11 -std=c++17

# Run the game
./app/circular_wars
```

#### macOS:
```bash
# Install Raylib via Homebrew (if not using provided library)
brew install raylib

# Compile with system Raylib
clang++ -o ./app/circular_wars ./src/*.cc ./src/*.cpp -I./header -I/usr/local/include -L/usr/local/lib -lraylib -std=c++17 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# Or use the provided library
clang++ -o ./app/circular_wars ./src/*.cc ./src/*.cpp -I./header -I./raylib -L./raylib -lraylib -std=c++17 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
```

#### Windows (MinGW/MSYS2):
```bash
# Install Raylib dependencies via MSYS2
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib

# Compile
g++ -o ./app/circular_wars.exe ./src/*.cc ./src/*.cpp -I./header -I./raylib -L./raylib -lraylib -std=c++17 -lopengl32 -lgdi32 -lwinmm

# Or using Visual Studio
# Open Developer Command Prompt and navigate to project directory
cl /EHsc /I./header /I./raylib ./src/*.cc ./src/*.cpp ./raylib/libraylib.a /link opengl32.lib gdi32.lib winmm.lib /out:./app/circular_wars.exe
```

### Method 3: Using CMake

Create a `CMakeLists.txt` in the root directory:

```cmake
cmake_minimum_required(VERSION 3.16)
project(CircularWars)

set(CMAKE_CXX_STANDARD 17)

# Find Raylib
find_package(raylib REQUIRED)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/header)
include_directories(${PROJECT_SOURCE_DIR}/raylib)

# Source files
file(GLOB SOURCES "src/*.cc" "src/*.cpp")

# Create executable
add_executable(circular_wars ${SOURCES})

# Link Raylib
target_link_libraries(circular_wars raylib)

# Set output directory
set_target_properties(circular_wars PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/app"
)
```

Then build:
```bash
mkdir build && cd build
cmake ..
make
# Executable will be in ./app/circular_wars
```

### Method 4: Docker Build

```bash
# Build the Docker image
docker build -t circular-wars .

# Run the game in a container
docker run -it --rm \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  circular-wars

# For Windows with WSL2, enable X11 forwarding first:
export DISPLAY=$(grep -m 1 nameserver /etc/resolv.conf | awk '{print $2}'):0
```

## 🎮 How to Play

| Control | Action |
|---------|--------|
| **Left Mouse Button** | Shoot projectile towards cursor |
| **Right Mouse Button** | Shoot projectile towards cursor |
| **Move Mouse** | Aim direction |
| **ESC** | Exit game |

### Game Rules:
1. **Objective**: Survive as long as possible while shooting incoming enemies
2. **Scoring**: Score increases over time (+1 every 0.2 seconds)
3. **Health**: Starts at 100, decreases by 20 when hit by enemy
4. **Game Over**: When health reaches 0

### Enemy Behavior:
- Enemies spawn from screen edges
- They move directly toward the player
- Different sizes (10-50px radius)
- Red color indicates enemies

## 🔧 Development

### Adding New Features

1. **New Enemy Types**:
   ```cpp
   // Add to game.cc spawnEnemies() function
   enemies.push_back(Game::Sprite(
       pos, 
       RAND(e) * (50 - 10) + 10, 
       vel, 
       Color{ 255, 100, 100, 255 }  // Different color
   ));
   ```

2. **Power-ups**:
   - Add new `PowerUp` class in `declare.h`
   - Implement spawning logic in `game.cc`
   - Add collision detection with player

3. **New Weapons**:
   ```cpp
   // Modify projectile creation in main.cpp
   if (IsKeyDown(KEY_SPACE)) {
       // Create spread shot
       for (int i = -2; i <= 2; i++) {
           float angle = atan2(GetMouseY() - screenY/2, GetMouseX() - screenX/2) + i * 0.2f;
           projectiles.push_back(Game::Sprite(...));
       }
   }
   ```

### Building from Source with Custom Raylib

If you want to use a different Raylib version:

```bash
# Clone and build Raylib
git clone https://github.com/raysan5/raylib.git
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=OFF ..
make

# Copy the library to your project
cp libraylib.a ../../CircularWars/raylib/
cp ../src/raylib.h ../../CircularWars/raylib/
```

## 📊 Performance

The game is optimized for 60 FPS on modern hardware:
- **CPU**: Minimal usage with efficient collision detection
- **GPU**: 2D rendering with Raylib's hardware acceleration
- **Memory**: Automatic cleanup of off-screen entities

## 🐛 Troubleshooting

### Common Issues:

1. **"raylib.h: No such file or directory"**
   ```bash
   # Install Raylib system-wide or adjust include paths
   sudo apt-get install libraylib-dev  # Ubuntu/Debian
   brew install raylib                 # macOS
   ```

2. **Undefined reference to raylib functions**
   ```bash
   # Ensure you're linking the library correctly
   # Add -lraylib to your linker flags
   ```

3. **Audio not working**
   ```bash
   # Install audio dependencies
   sudo apt-get install libasound2-dev  # Linux
   # Or check volume/mute settings
   ```

4. **X11/Wayland issues on Linux**
   ```bash
   # Try setting display backend
   export DISPLAY=:0
   # Or use software rendering
   export RAYLIB_DISPLAY_BACKEND=DRM
   ```

### Debug Build:
```bash
# Compile with debug symbols
g++ -g -o ./app/circular_wars_debug ./src/*.cc ./src/*.cpp \
  -I./header -I./raylib -L./raylib -lraylib -std=c++17

# Run with gdb
gdb ./app/circular_wars_debug
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Code Style:
- Use 4 spaces for indentation
- Class names in `PascalCase`
- Variables in `snake_case`
- Constants in `UPPER_SNAKE_CASE`
- Add comments for complex logic

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **[Raylib](https://www.raylib.com/)** - Simple and easy-to-use game library
- **Raylib Community** - For tutorials and examples
- **Game asset creators** - For the audio and visual assets
- **You** - For playing the game! 🎉

## 📞 Support

If you encounter any issues:
1. Check the [Troubleshooting](#troubleshooting) section
2. Open an [Issue](https://github.com/yourusername/CircularWars/issues)
3. Email: your.email@example.com

---

<div align="center">
Made with ❤️ and C++

⭐ Star this repo if you found it useful!
</div>