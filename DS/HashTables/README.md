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

