# DS
 
## Arrays
> Contiguous area of memory consisting of equal-size elements indexed by cintiguous integers.
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