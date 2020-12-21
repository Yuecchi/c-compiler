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

  - Refactored the grammar to imrpvoe readability and modularity.
  - Added the following functionality to eac and cgen:
    - if / else if / else conditional statements
    - subtraction
    
ISSUES

  - cgen sourcecode needs heavy refactoring
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
     
  
    
    
 
 
    
