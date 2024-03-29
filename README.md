# Z88dk Laboratory

General purpose z88dk Laboratory

### 1. Z88dk Cross Compiler

__z88dk__ is a z80 __C__ cross compiler supplied with an assembler/linker and a set of libraries implementing the C standard library for a number of different z80 based machines. The name z88dk originates from the time when the project was founded and targetted only the Cambridge z88 portable.

The compiler featured in z88dk is a much enhanced Small C compiler; the compiler accepts many features of ANSI C and is only deficient in a few areas where implementation on a z80 processor might prove inefficient. The compiler performs simple optimisations, but the bulk of the optimisation is achieved by a set of peep-hole rules, which will typically reduce the size of a large project by up to a third.

The libraries supplied with z88dk are designed to be as generic as possible, indeed it is possible to port to a new machine simply by supplying two library routines and some startup code. It is hoped that one day z88dk will support as many z80 based machines as there is information available and sufficient interest in. Currently z88dk supports more than eighty z80 family targets with the level of library support for each target varying with interest shown by users.
