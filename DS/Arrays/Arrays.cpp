#include <stddef.h>

/* template vector class */
template<class T>
class bVector
{
private:
    T * _array;
    /* init 0, used in reserve for 
    setting new size and capacity */
    int _size=0;
    int _capacity=0;
    void reserve(int n,bool copy);

public:
    T & operator[](unsigned int i);
    void push_back(T&& data);
    void emplase_back(T data);
    int size();
    int capacity();
    bool is_empty();
    void insert(int index, T data);
    void pop_back();
    void erase(int index);
    void remove(int index);
    int find(T data);
    void resize();
};

template<class T>
void bVector<T>::reserve(int n,bool copy)
{
    /* check if reserve gets a 0 size array to reserve */
    if(n==0)
        return;

    /* create new array */
    T * temp = new T[n];
    if(temp == NULL)
    {
        throw 0;
    }
    /* check if this reserve requires copy data */
    if(copy)
    {
        /* to check if this reserve was reduced 
        to srink the size of the array refrain 
        from running into undefined memory */
        int items_to_copy = _size;
        if(_size>n)
        {
            items_to_copy = n;
        }
        for(int i=0;i<this->items_to_copy;i++)
        {
            temp[i] = _array[i];
        }
    }

    /* clear old data before copy */
    if(_array!=NULL)
        {
            delete [] _array;
        }
    _array = temp;
    _capacity = n;

}

template<class T>
void bVector<T>::push_back( T&& value)
{
    if(_size==_capacity)
    {
        /* if it is first time push */
        if(_capacity==0)
        {
            reserve(1,false);
        }
        /* if the array needs expansion */
        else
        {
            reserve(_capacity*2,true);
        }
    }
    _array[_size]=value;
    _size++;

}