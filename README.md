# IndividualProject 2020 Elliot Carter

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
    
    
 
 
    
