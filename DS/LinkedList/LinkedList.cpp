

template<class T>
class node
{
    public:
    node(const T& item,node<T>  * next=nullptr)
    {
        _data = T;
        _next = next;
    }

    T _data;

    void InsertAfter(T data_to_add)
    {
        _next = new node(data_to_add,_next);
    }

    node<T> * DeleteAfter()
    {
        node<T> * temp = _next;
        if(_next!=NULL)
        {
            _next = _next->_next;
        }
        return _next;
    }

    private:
    node * _next = nullptr;    

};


int main( int arg, char ** args)
{



    return 0;
}