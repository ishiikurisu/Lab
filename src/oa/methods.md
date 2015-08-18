# String

+ int strlen(char*)
+ char* concat(char*, char*)
+ char* ctos(char)
+ char* itos(int)
+ char* substr(char*, int, int)
+ int compare(char*, char*)
+ char last_char(char*)
+ char* tidy_string(char*)
+ char** strsplit(char*,char) -- under construction

# Linked data types

Every function in those headers use the following convention:

    type_method(obj, args...)

## Available LDTs

+ Lists
+ Maps
+ Sets -- under construction

## Methods

+ new
+ length
+ get
+ add
+ find
+ print
  - yaml
+ contains
+ to_string
+ remove
+ free

## Specific to every type

+ Lists
  - add_at
  - pop
  - push
  - sort
  - split(char*, char)
  - associate
  - strsplit

+ Maps
  - put

Under construction. 	