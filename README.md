# Hello World Gtk4

## Project structure

- [builder.ui](builder.ui)
- [main.c](main.c)

## Compile

```shell
gcc $( pkg-config --cflags gtk4 ) -o main main.c $( pkg-config --libs gtk4 )
```

## Run
```shell
./main
```
