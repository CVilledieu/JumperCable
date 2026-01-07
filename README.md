# JumperCable

A C application using Nuklear GUI framework with GLFW and OpenGL.

## Dependencies

- GLFW 3.4
- GLEW 2.2.0
- OpenGL 3.3+
- Nuklear (included)

## Building

### MSYS2 UCRT64

Install dependencies:
```bash
pacman -S --needed mingw-w64-ucrt-x86_64-glfw mingw-w64-ucrt-x86_64-glew
```

Compile:
```bash
gcc src/main.c -Iinclude -lglfw3 -lglew32 -lopengl32 -lgdi32 -o jumpercable.exe
```

Or use make:
```bash
make
```

Run:
```bash
./jumpercable.exe
```


## Features

- Immediate-mode GUI with Nuklear
- OpenGL 3.3 rendering
- Cross-platform window management with GLFW
- Interactive widgets and tools