# IndividualProject 2020 Elliot Carter

Final Year Project Repository

CHANGE LOG

05/12/2020
  
  - Made initial commit containing the compilation of work produced
    during the first term. This includes:
    - a bunch of stuff

20/12/2020

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
    
