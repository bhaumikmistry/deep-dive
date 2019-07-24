## Big-O Algorithmic complexity/ Asymptotic analysis
How time scales with respect to some input variable.

+ Different steps get added 
+ Drop constants
+ Different input different variable

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