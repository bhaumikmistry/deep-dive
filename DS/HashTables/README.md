[<- Back](../README.md)

# Hash Tables

Hashing is a technique that is used to uniquely a specific object from a group of similar objects. Some examples of how hashing is used in our lives includes:

* Roll number or Uni. Id of each student to retrieve students information.

* Each book is assigned a unique number in a library.

In hashing large keys are converted into an keys by using a hash function. The values are then stored in a data structure called Hash Table, the idea of hashing is to distribute entries uniformly across an array. Each element is assigned a key, by using that key you can access the element in O(1) and worst case O(n).

* The element is converted into an integer by using a hashing function. This element can be used as an index to store the original element, which falls into the hash table.

* THe element is stored in the hash table where it can be quickly retrieved using hashed key. 
Hash = hash_func(key)
index = hash % array_size

### Hash Function

A hash function is an function that can be used to map a data set of an arbitrary size to a data set of a fixed size. Values returned are called hash codes, hashes, ir hash sums.

* Easy to compute
* Uniform distribution
* Less collisions

### Collision resolution techniques
* Separate Chaining (open hashing)

    Separate hashing is one of the most commonly used collision resolution techniques. Usually implemented using ```Linked Lists```. In separate chaining each element of the hash table is linked list. To store an element in the hash table you must insert it into a specific linked list. Items with same hash values gets stored in the same linked list.

* Linear Probing or Open addressing or Closed hashing.

    In open addressing, instead of in linked list, all entry records are stored in the same array itself. When a new entry has to be inserted, the hash index of the hashed value is compared and then the array is examined. If the slot at the hashed index in unoccupied, then the entry record is inserted in slot at the hashed index else it proceeds in some prove sequence until it finds an unoccupied slot.

    Linear probing when the interval between successive proves is fixed.

    ```
    index = index % hashTableSize
    index = index+1 % hashTableSize
    
    ```

* Quadratic Probing

    Quadratic probing is similar to linear probing and the only difference is the interval between successive probes or entry slots. Here, when the slot at a hashed index for an entry record is already occupied, you must start traversing until you find an unoccupied slot. The interval between slots is computed by adding the successive value of arbitrary polynomial in the original hashed index.

    ```
    index = index % hashTableSize
    index = index+1*1 % hashTableSize
    index = index+2*2 % hashTableSize    
    ```

* Double Hashing

    The interval between probes is computed by two different two hash functions.