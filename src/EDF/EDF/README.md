EDF class
=========

These files implement a representation to the EDF standard in C++ language. Now, only the 1997 EDF is implemented, and it can be used using the `edf.hpp` header.

Methods
-------

From the `edf.hpp` file,

``` C++
class EDF
{
	/*...*/
public:
	EDF(void) {};
	~EDF(void) {};
	void read_file(const char*);
	void write_file(const char*);
	void yaml(const char*);
	void csv(const char*);
	friend class DATA_RECORD;
};
```

EDFP class
==========

This header implement the EDF+ standard. Basically, it works just like the EDF class, but it extracts the annotations channel from it.

Methods
-------

From the `edfp.hpp` file,

``` C++
class EDFP
{
	/*...*/
public:
	EDFP(void);
	~EDFP(void) {};
	void read_file(const char*, bool);
	void csv(const char*);
	friend class DATA_RECORD;
};
```
