#include <stddef.h>
#include <assert.h>

template<class T>
class node
{
    public:
    node(const T& item,node<T> * n)
    {
        _data = item;
        _next = n;
    }

    T _data;
    node<T> * _next;
};

template<class T>
class hNode
{
    private:
    int _size;
    node<T> * _head;

    void push_front(T item)
    {
        _size++;
        _head = new node<T>(item,_head); 
    }

    void push_back(T item)
    {
        node<T> * temp = _head;
        while (temp->_next!=NULL)
        {
            temp = temp->_next;                
        }
        temp->_next = new node<T>(item,NULL);
        _size++;
    }

    bool empty()
    {
        return !(_size>0);
    }

    T value_at(int index)
    {
        int count =0;
        node<T> * temp = _head;
        while(temp!=NULL)
        {
            if(count==index)
            {
                return temp->_data;
            }
            count++;
        }
        assert(0);
    }

    void reverse()
    {
        node<T> * prev = NULL;
        node<T> * next = NULL;
        node<T> * current = _head;
        while(current!=NULL)
        {
            next = current->_next;
            current->_next = prev;
            prev = current;
            current = next;
        }
        _head = prev;
    }

    //more
    // fornt(); //same as value_at(0);
    // back(); // same as value_at(size-0);
    // insert(int data,int index);
    // erase(int index);
    // value_from_end_(); // use help of size and get index
    // remove_value();

};


int main( int arg, char ** args)
{
    return 0;
}