# raylib-c-screen-tearing-test
A screen tearing test written in c using raylib.

## Building and Running

### Requirements
- cmake
- make
- a working c compiler

### Building:
```bash
mkdir build && cd build
cmake ..
make
```

### Running
Running normally:
```bash
./raylib-c-screen-tearing-test
```

The test can be configured using the enviroment variables:

| Variable | Standard value | Description |
| ------------- |------------- |-------------|
| `FULLSCREEN` | 0 | 1 fullscreen, 0 windowed |
| `WIDTH` | 800 | sets width |
| `HEIGHT` | 600 | sets height |
| `FPS` | 60 | sets target fps |
| `SPEED` | 5 | sets speed |

Example:
```bash
FULLSCREEN=1 WIDTH=1920 HEIGHT=1080 FPS=144 SPEED=-25 ./raylib-c-screen-tearing-test
```

## Credit
- Raylib, by raysan5: https://github.com/raysan5/raylib