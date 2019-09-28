# Aventura Conversacional para ZX Spectrum

Extraído del tutorial:

https://wiki.speccy.org/cursos/z88dk/avent1

Se ha modificado para adaptarlo convenientemente a la última versión del z88dk y corregir algún error.

### 1. Compilamos y tapeamos el fichero fuente:

```shell
$ zcc +zx -clib=ansi -lm -lndos -create-app -o aventura aventura.c
```

Esto creará los siguientes ficheros:

- a.tap
- a.bin
- a.BANK_7.bin

### 2. Cargar el fichero .tap generado en el Fuse

Se puede cargar de la forma habitual en FUSE y ver como se ejecuta.

