#include <chrono>
#include <string>
#include <iostream>

class BigONotation
{
public:
    int * theArray;
    int arraySize;
    int itemsInArray;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    BigONotation(int size)
    {
        arraySize = size;
        theArray = new int[size];
    }

    ~BigONotation(){}

    void generateRandomArray()
    {
        for(int i=0;i<arraySize;i++)
        {
            theArray[i] = (int)(rand()%1000);
        }
        itemsInArray = arraySize-1;
    }


    /* O(1) Runs at the same time no matter how long the array is */
    void addItemToArray(int newItem)
    {
        theArray[itemsInArray++] = newItem;
    }

    /* O(N) linear Search*/
    void linearSearchForValue(int value)
    {
        bool valueInArray = false;
        std::string indexsWithValue = "";

        begin  = std::chrono::steady_clock::now();

        for(int i =0;i<arraySize;i++)
        {
            if(theArray[i]==value)
            {
                valueInArray = true;
                indexsWithValue += std::to_string(i) + " ";
            }
        }


        end = std::chrono::steady_clock::now();

        std::cout   << "Time Taken by LinearSearchForValue = " 
                    << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
                    << "[µs] " ;
        std::string val = (valueInArray)? "True" : "False" ;
        std::cout << "Found? " << val << std::endl;
    }

    /* O(n^2) */
    void BubbleSort()
    {

        begin = std::chrono::steady_clock::now();

        for(int i=arraySize-1; i>1; i--)
        {
            for(int j=0; j<i; j++)
            {
                if(theArray[j]>theArray[j+1])
                {
                    int temp = theArray[j];
                    theArray[j] = theArray[j+1];
                    theArray[j+1] = temp;
                }
            }
        }

        end = std::chrono::steady_clock::now();

        std::cout   << "Time Taken by BubbleSort = " 
                    << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
                    << "[µs] " << std::endl;
    }

    /* O(log N) */
    void BinarySearch(int value)
    {
        begin = std::chrono::steady_clock::now();

        int lowIndex = 0;
        int highIndex = arraySize -1;
        
        int timesThrough = 0;

        while(lowIndex <= highIndex)
        {
            int middleIndex = (highIndex + lowIndex)/2;
            if(theArray[middleIndex] <value)
            {
                lowIndex = middleIndex+1;
            }
            else if(theArray[middleIndex] > value)
            {
                highIndex = middleIndex-1;
            }
            else
            {
                std::cout << "Found match at "<< middleIndex << std::endl;
                lowIndex = highIndex+1;
            }

            timesThrough++;            
            
        }

        end = std::chrono::steady_clock::now();

        std::cout   << "Time Taken by BinarySearch = " 
                    << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
                    << "[µs] " << std::endl;
        std::cout << "iteration "<< timesThrough << std::endl;

    }

    /* O(NlogN) */
    void QS(int low,int high)
    {
        begin = std::chrono::steady_clock::now();
        this->QuickSort(low,high);
        end = std::chrono::steady_clock::now();
        std::cout   << "Time Taken by QuickSort = " 
                    << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
                    << "[µs] " << std::endl;
    }
    void QuickSort(int low,int high)
    {
        if(low>=high)
        {
            return;
        }
        else
        {
            int pivotLocation = partitionArray(low,high);
            QuickSort(low,pivotLocation-1);
            QuickSort(pivotLocation+1,high);
        }
    }

    int partitionArray(int low,int high){

        int pivot = theArray[high];
        int i = (low-1);

        for(int j=low;j<=high-1;j++)
        {
            if(theArray[j] <=pivot)
            {
                i++;
                int temp = theArray[i];
                theArray[i] = theArray[j];
                theArray[j] = temp;

            }
        }
        
        int temp = theArray[i+1];
        theArray[i+1] = theArray[high];
        theArray[high] = temp;
        return i+1;

    }

    void printArray()
    {
        for(int i = 0; i<=arraySize-1;i++)
        {
            std::cout << " " << theArray[i] << " ";
        }
        std::cout << std::endl;
    }

};