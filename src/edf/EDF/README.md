# EDF class

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

# EDF+ class

An alternative (but hopefully soon to be the effective) solution to this problem is the `edfp.hpp` header, which tries to implement the ability to separate EDF annotations from the rest of the channels. Currently, it works for simple test cases, but we couldn't test it with an extreme case yet to know if it works of not.

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
	void read_file(const char*);
	friend class DATA_RECORD;
};
```

The `void EDFP::read_file(const char*)` method writes a simple YAML of the EDF+ file header to the console as an side-effect, but this will be removed on later versions of the header.