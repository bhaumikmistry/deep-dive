#C++

+ C++ data types
    + [link](https://www.geeksforgeeks.org/c-data-types/)
+ [RValue](#RValues)
+ [Const Correctness](#Const-Correctness)
+ [new vs malloc()](#new-malloc()) 

---
## RValues
>&& is new in C++11, and it signifies that the function accepts an RValue-Reference -- that is, a reference to an argument that is about to be destroyed.
```
void foo(int&& a)
{
    //Some magical code...
}

int main()
{
    int b;
    foo(b); //Error. An rValue reference cannot be pointed to a lValue.
    foo(5); //Compiles with no error.
    foo(b+3); //Compiles with no error.

    int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
    int&& d = 5; //Compiles with no error.
}
```
+ [link](https://stackoverflow.com/a/39480244)
+ [link](https://stackoverflow.com/a/5481588)
---
## Const Correctness
+ [link](https://www.cprogramming.com/tutorial/const_correctness.html)
---
## new-malloc()
+ `malloc` is library function of stdlib.h and it was used in c langugae to allocate memory for N blocks at run time, it can be used in c++ programming langugae. Whenever a program needs memory to declare at run time we can use this fuction. It does not call the constructor of the object. Slower than new
+ `new` is an operator in c__ programming langugae it is also used to declasre memory for N blocks at run time. new also calls the constructor of the object initialized. Faster than malloc(); operator is always faster.
+ [link](https://www.geeksforgeeks.org/malloc-vs-new/)
---
