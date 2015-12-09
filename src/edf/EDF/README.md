# EDF class

These files implement a representation to the EDF standard in C++ language. Now, only the 1997 EDF is implemented, and it can be used using the `edf.hpp` header. The EDF+ is to be implemented, and currently it can be accessed in the `edfp.hpp` header;

# Methods

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
