# problem-of-three-bodies
A simple simulation of the problem of three bodies in C++. 

## Executing the program

You should have installed in your machine `raylib`.

```bash
make
```

```bash
./main
```

When working on macOS, you should not use the `Makefile` (at the moment). Instead, use the following command:

```bash
clang++ main.cpp -I/opt/homebrew/Cellar/raylib/5.5/include -L/opt/homebrew/Cellar/raylib/5.5/lib -lraylib -o main -std=c++11
```

The installation of the library `raylib` has been used with homebrew. You may need to change the directory folders in order to make this to work.

### Steps 

1. Render the planets
2. Assume colitions are not possible. Execute the gravitational force formula for each element.
3. Calculate the vectors vx, vy, ax, ay.
4. Render the vector v and a.
5. Move the planets
