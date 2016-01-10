Edinburgh Handedness Inventory
==============================

This is an implementation of the Edinburgh Handedness Inventory. In this app, there will be a window with 10 questions. For each question, there are 5 possible answers:

+ Always left
+ Usually left
+ No preference
+ Usually right
+ Always right

After answering these questions, the subject will press the `Score me!` button. Another window will popup giving your result. Answer every question

Laterality Index
----------------

To calculate the result, the program will calculate the subject's Laterality Index using the equation:

```
LI := 2*sum("always right") + sum("usually right") - sum("usually left") - 2*sum("always left")
```

After calculating the index, it will relate this number to this table:

```
if LI > 2: right handed
if LI < 2: left handed
else: ambidextrous
```

And give the final result.
