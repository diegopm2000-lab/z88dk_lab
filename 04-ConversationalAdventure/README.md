# Conversational Adventure for ZX Spectrum

Extracted from tutorial:

https://wiki.speccy.org/cursos/z88dk/avent1

It has been modified to conveniently adapt it to the latest version of the z88dk and correct any errors.

### 1. Compiling and taping the source file:

```shell
$ zcc +zx -clib=ansi -lm -lndos -create-app -o aventura aventura.c
```

This will create the following files:

- a.tap
- a.bin
- a.BANK_7.bin

### 2. Load the .tap file generated in the Fuse

It can be loaded as usual in FUSE and see how it runs.

