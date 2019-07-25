# Big-O Algorithmic complexity/ Asymptotic analysis
How time scales with respect to some input variable.

+ [Different steps get added](#Different-steps-get-added) 
+ [Drop constants](#Drop-Constants)
+ [Different input different variable](#Give-separate-input-separate-variable)
+ [Drop non dominant term](#Drop-non-dominant-term)

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

## bigO(N)
Code
```
BigONotation bigON1(10000);
bigON1.generateRandomArray();
bigON1.linearSearchForValue(123);

BigONotation bigON2(15000);
bigON2.generateRandomArray();
bigON2.linearSearchForValue(123);

BigONotation bigON3(30000);
bigON3.generateRandomArray();
bigON3.linearSearchForValue(123);

BigONotation bigON4(70000);
bigON4.generateRandomArray();
bigON4.linearSearchForValue(123);
```
Time for O(N)
```
Time Taken by LinearSearchForValue = 30[µs] Found? False
Time Taken by LinearSearchForValue = 43[µs] Found? False
Time Taken by LinearSearchForValue = 89[µs] Found? False
Time Taken by LinearSearchForValue = 219[µs] Found? False
```