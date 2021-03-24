# ecc - C Compiler By Elliot Carter

Final Year Project Repository

CHANGE LOG

05/12/2020
  
  - Made initial commit containing the compilation of work produced
    during the first term. This includes:
    - a bunch of stuff

20/12/2020

CHANGES

  - Created new grammar 'eac' which now emits three address code.
    Currently functionality of eac includes:
    - Declaration of integer variables.
    - Value assignment to interger variables via arithmetic expressions.
    - Arithmetic expressions currently handle addition.
    - Detects variable redeclaration and attempted use of undeclared variables.
    - Contains provisionary logic for "if / else if / else" statements.
  - Created a program 'cgen' which takes as input the three address code produced
    by 'eac' and generates the appropriate mips assembly code. cgen currently
    handles:
      - declaration of integer variables
      - assignment to integer variables
      - addition
      
ISSUES

  - Grammar needs cleaning up.
        
21/12/2020

CHANGES

  - Refactored the grammar to improve readability and modularity.
  - Modified ma_aux. Now includes a stack which holds labels. This
    has been added to facilitate the new break statement implementation
  - Added the following functionality to eac and cgen:
    - if / else if / else conditional statements
    - subtraction
    - printing integers
    - while loops
    - break statements
      
ISSUES

  - cgen sourcecode needs heavy refactoring,
  - Grammar needs cleaning up again.
  - Review break statement implementation.
  - Conditional statements can not be inlined, eg:
      
        if (0) x = 3;
        else x = 5;
      
     This is due to a FIRST / FOLLOW conflict which I believe
     can not be resolved due to the limitations of LL1 parsers.
     Therefore, it is likely conditional staements will only be
     followed by compound statements, eg:
     
        if (0) { x = 3; }
        else { x = 5; }
     
     The issue does not occur here due to the closing brace preceeding 
     else (thus eliminating the FIRST / FOLLOW conflict).

     
23/12/2020

CHANGES

  - Modified the label stack in ma_aux so it now holds two labels.
    This change has been made to facilitate the implementation of
    both the break and continue statements.
  - Added 'peek' functions to the label stack. This was done in order 
    to fix a bug in the grammar where calling break more than once inside 
    a loop would cause all subsequent breaks to jump to a null address.
  - Added boolean expressions to the grammar
  - Added unary expressions to the grammar
  - Modified the semantics of addition expressions so the code generation 
    closer matches that of boolean expressions. Binary expression will no
    longer contain integer literals.
  - Began rewriting cgen to account for the changes made to expression
    semantics, and to improve the modularity of the code. Cgen now converts
    the conents of the .tac file to quadruples. This should make mips code
    generation a more natural process. 
      
ISSUES

  - cgen rewrite needs finishing.
  
24/12/2020

CHANGES

  - cgen has been completely rewritten and now supports all the same features 
    as the previous version of cgen plus boolean expression. cgen is now much
    easier to to add new features to and has been written to support targeting
    of multiple architectures.
  - Fixed a bug where while loops were only checking their condition upon first
    entering the loop and then not performing any checks on subsequent iterations
    of the loop.
      
ISSUES

  - cgen needs commenting.
    
25/01/2021

CHANGES

  - The project has now officially been named "ecc", short for "Elliot's C Compiler".
  - ecc now supports functions. This includes:
    - Declaration of functions in the global scope.
    - Scope, local variable declaration and shadowing.
    - Use of function calls from within any scope including their own, meaning ecc 
      supports recursion.
    - The use of functions calls within expressions.  
  - In order to facilitate the large changes which were necessary to implement 
    functions, the grammar has once again been rewritten, and is now stored in a 
    file named "func.bnf". A lot of the old grammar was reintegrated into this new
    grammar once functions were workking, however several changes were madae to 
    account for the addition of functions.
      - The terminal symbol "PRIMITIVE" now includes function calls, enabling the
        use of functions in expressions.
      - Operations involving symbol table lookups have been rewritten to account 
        for multiple scopes.
      - The grammar now supports the use of arbitrary scopes
      - The grammar now expects the translation unit to contain a main function
      - The symbol table file "func.tbl" now stores the names of variables and
        functions declared in the global scope. Additionally, each symbol written
        to the file is now accompanied with a value representing whether it is an
        integer or a function, and for functions, a value indiciating the number of
        local variables declared within the function.
  - The IR has has several new commands added:
    - push, which indicates the allocation or deallocation of stack space.
    - call, which indicates a function call
    - return, which indicates returning from a function
  - "ma_aux.c" has been modified so now labels are preceeded by '#' symbols and 
    temps are preceeded by '$' symbols. This change was made to make parsing the
    IR simpler and to avoid clashes with variable names.
  - The implementation of a stack which held labels of active loops has been removed
    from "ma_aux". I am now instead using a general stack implementation I wrote in
    files "stack.c" and "stack.h". The header contains a stack named "loop_stack" 
    which stores the start labels of currently active loops. Using this stack, the 
    parser is able to tell at any point when a loop is active, and which labels to
    use if either BREAK or CONTINUE are used.
  - A support header "type.h" has been added. This contains a enum which is used to 
    identify what type a a declared symbol is. Currently this only support integers
    and functions which return integeres.
  - A support header "scope_chain.h" has been added to assist rdp with tracking the 
    current scope.

ISSUES

  - Both the semantics and grammar of func.bnf will need refactoring
  - Global variables can technically only be declared currently. If a value
    is assigned to them it will not be assigned correctly during runtime as
    this will be unreachable code in the generated assembly.
  - It is currently uncertain whether or not programs will behave as intended
    if a function is passed as an argument to a function.
  - Dynamic stack allocation is still being used for function arguments. It would
    be best to change this to a batch allocation as to match how allocation is 
    performed for all other parts of stack frames.
  - The register allocation strategy is currently only rudimentary and could cause
    potential issues, however no such issues occured since the fix to improve 
    robustness was applied.
  
26/01/2021

CHANGES

  - ecc now supports division, multiplication and modulo arithmetic operations
    as well as bracketed expressions
  - The repository now includes some example programs, currently located inside
    the "examples" folder.
  - Global variables can now have values correctly assigned to them upon declaration.

ISSUES

  - No new issues.
 
 24/03/2021
 
 CHANGES
 
 - ecc now supports arrays. 
 - A bubsort program has been added to the examples folder as a means of demmonstrating
   arrays.
 
 ISSUES
 
 - Arrays can not be passed as arguments to functions.
 - Arrays can not be set as paramaters of functions.
 - Functions can not return array types.
    
