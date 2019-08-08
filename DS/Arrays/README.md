[<-Back](../README.md)

## Arrays 
> Contiguous area of memory consisting of equal-size elements indexed by cintiguous integers.
> Defining array
+ One dimensional array
    ```
    data-type array-name[index-count];
    ```
+ Multi dimensional array
    ```
    data-type array-name[index-count][index-count];
    ```
+ Jagged Arrays
    ```
    int [][] jaggedArray = new int[n][]
    ```
+ [Links](#Links)


## Special about array
+ Constant-time access, add/remove
    ``` 
    array_addr+elem_size*(index-index_first_element)
    ```
+ Multi-Dimensional Arrays
    ```
    array_addr + elem_size * ((index_row-1)*width +(index_col-1))
    ```
    + Row-Major Row-Indexing
        + C++
        + java
    + Col-Major Col-indexing
        + Fortran
        + R
        + Julia
+ Linear-time to add/remove form beginning and middle

## Time for common Operation
|           |Add    |Remove |
|-----------|-------|-------|
|Beginning  |O(n)   |O(n)   |
|End        |O(1)   |O(1)   |
|Middle     |O(n)   |O(n)   |


## Links
+ [Coursera singly linked lists](https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK)
+ [UCBerkeley Webcast](https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE)

## Things to keep in mind
+ Constraints makes the data structiure faster and better with speed access.
+ Flexiblity comes with overhead.

# Arrays vs Vector
|       Arrays         |        Vector    |
|-------------------|------------------|
|Are a builtin language construct | Is a template class|
|Come almost unmodified form c89| Is a c++ only construct|
|Provide just a contiguous, indexable sequence of elements|Is implemented as dynamic array |
|Fixed size, cant resize in c++|grows and shrinks dynamically|
[link](https://stackoverflow.com/a/15079462)

# Vector implementation
+ [Explanation](https://codereview.stackexchange.com/a/60502)
+ [Short notes](https://codereview.stackexchange.com/a/60488)