
#include <vector>

/* template vector class */
template<class T>
class bVector
{
private:
    T * array;
    int size;
    int capacity;
    void reserve(int n,bool copy);

public:
    T & operator[](unsigned int i);
    void push_back(T int);
    void emplase_back(T int);
    int size();
    int capacity();
    bool is_empty();
    void insert(int index, T data);
    void pop_back();
    void delete(int index);
    void remove(int index);
    int fine(T data)
    void resize();

    std::vector<int> test;

};

template<class T>
void bVector<T>::reserve(int n,bool copy)
{
    if(n==0)
        return;

    T * temp = new T[n];
    if(temp == NULL)
    {
        throw memoryAllocationError("Error creating new vector");
    }
    if(copy)
    {
        if(size>n)
        {
            size = n;
        }
        for(i=0;i<this->size;i++)
        {
            temp[i] = array[i];
        }
    }

    if(array!=NULL)
        {
            delete [] array;
        }
    array = temp;
    capacity = n;

}