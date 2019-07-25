# Big-O Algorithmic complexity/ Asymptotic analysis
How time scales with respect to some input variable.

+ [Different steps get added](#Different-steps-get-added) 
+ [Drop constants](#Drop-Constants)
+ [Different input different variable](#Give-separate-input-separate-variable)
+ [Drop non dominant term](#Drop-non-dominant-term)

+ [Links](#Links)

## Different steps get added 
> Different steps of the alogrithm contributes to asymptotic analysis for instance.
```
function something()
    step(); // O(a)
    step(); // O(b)

Total O(a+b)
```
## Drop Constants
> Give more importance to the scalable factor and drop the constants.
```
function something()
    step(); // O(n)
    step(); // O(n)

Total O(2n) -> O(n)
```

## Give separate input separate variable
> Different Inputs gives different scalability
```
function something()
    for a in array
        for b in array
            step();

Total O(n^2) -> O(a * b)
```
> a & b can vary independently and change the scaled time.

## Drop non dominant term
> The impact of higher term will always dominate the most whent he scale is very high.
```
45N^3+3N
N^3 will dominate the total when the solution is scaled

O(n^3) will be the best case
```

## Time to see the difference
```
O(N)
Time Taken by LinearSearchForValue = 30[µs] Found? False
Time Taken by LinearSearchForValue = 43[µs] Found? False
Time Taken by LinearSearchForValue = 89[µs] Found? False
Time Taken by LinearSearchForValue = 219[µs] Found? False

O(N^2)
Time Taken by BubbleSort = 306377[µs] 
Time Taken by BubbleSort = 698673[µs] 
Time Taken by BubbleSort = 2986870[µs] 
Time Taken by BubbleSort = 16684941[µs] 

O(logN)
Time Taken by BinarySearch = 26[µs] Found match at 369 iteration 9
Time Taken by BinarySearch = 7[µs] Found match at 715 iteration 10
Time Taken by BinarySearch = 7[µs] Found match at 818 iteration 8
Time Taken by BinarySearch = 11[µs] Found match at 2254 iteration 10

O(NlogN)
Time Taken by QuickSort = 1361[µs] 
Time Taken by QuickSort = 1798[µs] 
Time Taken by QuickSort = 1655[µs] 
Time Taken by QuickSort = 1755[µs] 

```

## Links
+ [Youtube code help](https://www.youtube.com/watch?v=V6mKVRU1evU)
+ [stonybrook.edu](http://www3.cs.stonybrook.edu/~algorith/video-lectures/2007/lecture2.pdf)
+ [Complexity blog](http://discrete.gr/complexity/)
+ TopCoder
    + [Part1](https://www.topcoder.com/community/competitive-programming/tutorials/computational-complexity-section-1/)
    + [Part2](https://www.topcoder.com/community/competitive-programming/tutorials/computational-complexity-section-2/)