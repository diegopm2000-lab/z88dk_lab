# Z88dk Miniguía de Instalación

## 1. Sistema operativo usado 

Estamos usando Ubuntu 18.04.03 Budgie a la hora de escribir esta mini guia.

## 2. Instalación de FUSE

FUSE es el Emulador de ZX-Spectrum que vamos a usar para Linux.

Hay dos versiones disponibles:

- Fuse (SDL): SDL (Simple DirectMedia Layer) 
- Fuse (GTK+)

Escogemos la SDL y la instalamos desde el centro de software.

Al arrancar FUSE, nos indicará que no ha encontrado las ROM de ZX-Spectrum.

Para instalar las roms, tenemos que hacer:

```shell
$ sudo apt-get install spectrum-roms fuse-emulator-utils
```

Con esto, al arrancar FUSE, ya debería reconocer las ROM.

## 3. Descarga del software z88dk

Se puede descargar de aquí: 

```html
 https://sourceforge.net/projects/z88dk/
```

Lo que nos descarga el fichero z88dk-src-1.99B.

O bien haciendo:

```shell
$ wget http://nightly.z88dk.org/z88dk-latest.tgz
```

Lo que nos descarga el fichero z88dk-latest-tgz.

Nos vamos a quedar con el latest.

## 4. Descomprimir y copiar a la carpeta de trabajo

Descomprimimos el fichero z88dk-latest.tgz y copiamos el contenido a la carpeta Programas de nuestro directorio home.

## 5. Creación de los binarios

La carpeta /bin inicialmente se encuentra vacía, y tenemos que construir los binarios del z88dk.

Aquí viene explicado como se instala:

```html
https://www.z88dk.org/wiki/doku.php?id=temp:front#linux_unix
```

### 5.1 Instalaciones previas

Necesitamos las siguientes librerías:

```
dos2unix
libboost-all-dev
texinfo
texi2html
libxml2-dev
subversion
bison
flex
zlib1g-dev
```

Además, añadimos la librería m4


```shell
$ sudo apt-get update
$ sudo apt-get install dos2unix
$ sudo apt-get install libboost-all-dev
$ sudo apt-get install texinfo
$ sudo apt-get install texi2html
$ apt-cache search libxml2
$ sudo apt-get install libxml2-dev
$ sudo apt-get subversion
$ sudo apt-get install bison
$ sudo apt-get install flex
$ sudo apt-get install zlib1g-dev
$ sudo apt-get install m4
```

### 5.3 Construcción de los binarios

Para ello, hay que ejecutar el fichero build.sh que se encuentra en la carpeta principal del z88dk:

```
$ cd z88dk
$ chmod 777 build.sh
$ ./build.sh
```

Si todo ha ido bien, al final ha de aparecer la siguiente traza:

```
ZX7: Optimal LZ77/LZSS compression by Einar Saukas
File converted from 13400 to 5886 bytes! (delta 3)
z80asm -mz80n  -xlib/sccz80/zxn @target/zxn/library/zxn_sccz80.lst
z80asm -mz80n  -xlib/sdcc_ix/zxn -D__SDCC -D__SDCC_IX @target/zxn/library/zxn_sdcc_ix.lst
z80asm -mz80n  --IXIY -xlib/sdcc_iy/zxn -D__SDCC -D__SDCC_IY @target/zxn/library/zxn_sdcc_iy.lst
make: se sale del directorio '/home/user/Programas/z88dk/libsrc/_DEVELOPMENT'
make: se entra en el directorio '/home/user/Programas/z88dk/include/_DEVELOPMENT'
cp -r sccz80/adt ../
cp -r sccz80/alloc ../
cp -r sccz80/arch/zx/esxdos.h ../arch/zx/esxdos.h
cp -r sccz80/arch/zxn/esxdos.h ../arch/zxn/esxdos.h
make: se sale del directorio '/home/user/Programas/z88dk/include/_DEVELOPMENT'
```

## 5. Configuración de variables de entorno

Añadimos al fichero .profile lo siguiente:

```
#z88dk
export PATH=${PATH}:${HOME}/Programas/z88dk/bin
export ZCCCFG=${HOME}/Programas/z88dk/lib/config
```

Salimos y volvemos a entrar en la sesión



