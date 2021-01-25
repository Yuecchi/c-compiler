make GRAMMAR=func parsera
gcc cgen.c tac.c quad.c mips.c sym_tbl.c -o cgen
./cgen
