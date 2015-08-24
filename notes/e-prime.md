# E-Prime

Structure
---------

Lists call procedures. Procedures are like functions. They can access parameters that are given to them. 

### SessionProc

This procedure is like `C`'s `int main(int, char**)` function. It will begin and end our experiment, and make the appropriate data loggings. 

Issues and solutions
--------------------

+ For each E-object, we can access and set many properties, including duration and onset delay. Therefore, we might create a "Trial" object, which will be a procedure E-object, which will be called by the Main pocedure. 

  - [ ] Search for InLine object. Is the sound E-object a global?
