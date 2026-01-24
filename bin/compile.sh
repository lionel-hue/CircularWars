#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}🔨 Building Circular Wars...${NC}"

# Create app directory if it doesn't exist
mkdir -p app

# Detect OS and set compiler/linker flags
OS="$(uname -s)"
case "${OS}" in
    Linux*)
        echo -e "${GREEN}Detected: Linux${NC}"
        COMPILER="g++"
        FLAGS="-std=c++17 -I./header -I./raylib -L./raylib -lraylib -lm -lpthread -ldl -lX11"
        ;;
    Darwin*)
        echo -e "${GREEN}Detected: macOS${NC}"
        COMPILER="clang++"
        FLAGS="-std=c++17 -I./header -I./raylib -L./raylib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL"
        ;;
    MINGW*|MSYS*|CYGWIN*)
        echo -e "${GREEN}Detected: Windows (MinGW)${NC}"
        COMPILER="g++"
        FLAGS="-std=c++17 -I./header -I./raylib -L./raylib -lraylib -lopengl32 -lgdi32 -lwinmm"
        EXE_EXT=".exe"
        ;;
    *)
        echo -e "${RED}Unsupported OS: ${OS}${NC}"
        exit 1
        ;;
esac

# Compile
${COMPILER} -o "./app/circular_wars${EXE_EXT}" ./src/*.cc ./src/*.cpp ${FLAGS}

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ Build successful!${NC}"
    echo -e "${YELLOW}🎮 Run the game with: ./app/circular_wars${EXE_EXT}${NC}"
    
    # Get file size
    if [ -f "./app/circular_wars${EXE_EXT}" ]; then
        FILE_SIZE=$(stat -f%z "./app/circular_wars${EXE_EXT}" 2>/dev/null || stat -c%s "./app/circular_wars${EXE_EXT}" 2>/dev/null)
        echo -e "${GREEN}📦 Executable size: $((${FILE_SIZE}/1024)) KB${NC}"
    fi
else
    echo -e "${RED}❌ Build failed!${NC}"
    exit 1
fi