# E-Prime

Structure
---------

The main procedure is called `SessionProc`, and it can call other procedures, e-objects (which are special object within e-prime), and lists of procedures. Procedures are like common CS's functions, and work on a linear manner. Lists are packages that call many procedures, and can change their parameters by the `attributes` feature. 

E-Basic is the scripting language underlying E-Prime. It works based on a context beahviour, which means it can read and write variables not only on its own scope, but on the procedure's it is inserted. *Apparently this is not completely true. Tests have shown its context definition is a bit confusing, and not all variables and properties can be changed.* It's _supposedly_ based on the `BASIC` programming language.

Issues and solutions
--------------------

- [x] For each E-object, we can access and set many properties, including duration and onset delay. Therefore, we might create a "Trial" object, which will be a procedure E-object, which will be called by the Main pocedure. Search for InLine object. Is the sound E-object a global?

- [ ] Discover how to choose between two procedures and how to log its data. 

- [ ] Regarding the license key issue, we might try [this](http://www.pstnet.com/support/kb.asp?TopicID=5539).
