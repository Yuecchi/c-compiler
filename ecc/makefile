###############################################################################
#
# RDP release 1.50 by Adrian Johnstone (A.Johnstone@rhbnc.ac.uk) 20 December 1997
#
###############################################################################
#
# Configuration section: uncomment one of the following blocks for gcc, g++,
# djgpp, acc on Sunos, Borland C++ or Microsoft C++.
#
###############################################################################

# Configuration for g++ on Unix. Also works for gcc if you set CC = g++
CC      = gcc
OBJ     = .o
EXE     =
DIFF    = diff -s
RM      = rm
CP      = cp
SUPP_DIR = ./rdp_supp/
CFLAGS = -I$(SUPP_DIR) -g
LINK    = $(CC) -o ./
MATHS   = -lm
HERE    = ./
OBJ_ONLY = -c
# End of gcc on Unix configuration

###############################################################################
#
# End of configuration : don't alter anything below this line
#
###############################################################################

# Standard macros

RDP_AUX = rdp_aux$(OBJ) rdp_gram$(OBJ) rdp_prnt$(OBJ)
RDP_SUPP = arg$(OBJ) graph$(OBJ) memalloc$(OBJ) scan$(OBJ) scanner$(OBJ) set$(OBJ) symbol$(OBJ) textio$(OBJ)
RDP_OBJ = rdp_*$(OBJ)

# Standard suffix rules

.c$(OBJ):
	$(CC) $(CFLAGS) $(OBJ_ONLY) $*.c

# default target: do everything

# Build the support modules: do this locally in case user wants debug options
arg$(OBJ): $(SUPP_DIR)arg.h $(SUPP_DIR)arg.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)arg.c

graph$(OBJ): $(SUPP_DIR)graph.h $(SUPP_DIR)graph.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)graph.c

memalloc$(OBJ): $(SUPP_DIR)memalloc.h $(SUPP_DIR)memalloc.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)memalloc.c

scan$(OBJ): $(SUPP_DIR)scan.h $(SUPP_DIR)scan.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)scan.c

scanner$(OBJ): $(SUPP_DIR)scan.h $(SUPP_DIR)scanner.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)scanner.c

set$(OBJ): $(SUPP_DIR)set.h $(SUPP_DIR)set.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)set.c

symbol$(OBJ): $(SUPP_DIR)symbol.h $(SUPP_DIR)symbol.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)symbol.c

textio$(OBJ): $(SUPP_DIR)textio.h $(SUPP_DIR)textio.c
	$(CC) $(CFLAGS) $(OBJ_ONLY) $(SUPP_DIR)textio.c

# compile distributed rdp
rdp$(EXE): rdp$(OBJ) $(RDP_AUX) $(RDP_SUPP)
	$(LINK)rdp$(EXE) rdp$(OBJ) $(RDP_OBJ) $(RDP_SUPP)


#general targets to build parser for grammar defined in GRAMMAR macro
parser: $(RDP_SUPP)
	$(HERE)rdp $(GRAMMAR)
	$(CC) $(CFLAGS) $(OBJ_ONLY) rdparser.c
	$(LINK)rdparser$(EXE) rdparser$(OBJ) $(RDP_SUPP) $(MATHS)
	$(HERE)rdparser -v -Vrdparser.vcg -l $(GRAMMAR).str

parserf: $(RDP_SUPP)
	$(HERE)rdp -F $(GRAMMAR)
	$(CC) $(CFLAGS) $(OBJ_ONLY) rdparser.c
	$(LINK)rdparser$(EXE) rdparser$(OBJ) $(RDP_SUPP) $(MATHS)
	$(HERE)rdparser -v -Vrdparser.vcg -l $(GRAMMAR).str
	
parsera: $(RDP_SUPP)
	$(HERE)rdp $(GRAMMAR)
	$(CC) $(CFLAGS) $(OBJ_ONLY) rdparser.c
	$(LINK)rdparser$(EXE) rdparser$(OBJ) $(RDP_SUPP) ma_aux.o $(MATHS)
	$(HERE)rdparser -v -Vrdparser.vcg -l $(GRAMMAR).str

eac: ./rdp ma_aux.o
	 ./rdp -F -o eac eac.bnf
	$(CC) -I rdp_supp/ -P -w -c eac.c
	$(CC) -o eac eac.o ma_aux.o arg.o symbol.o graph.o memalloc.o scan.o scanner.o set.o textio.o

cgen: 
	$(CC) cgen.c tac.c quad.c mips.c -o cgen

# get rid of intermediate files
clean:
	-$(RM) *$(OBJ)

# return to intial distribution state by deleting executables
veryclean: clean
	-$(RM) rdparser.c
	-$(RM) rdparser.h
	-$(RM) rdparser$(EXE)

