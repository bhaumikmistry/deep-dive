#include <iostream>

struct node{

    int _data;
    node * _node = nullptr;

    ~node(){
        if(_node==nullptr){
            delete _node;
        }
    }

    node(const int& data,node *n){
        _data = data;
        _node = n;
    }

};

class queue{

    public:
    queue(){
        head = new node(0,nullptr);
        tail = new node(0,nullptr);
    }
    ~queue(){}

    int _size = 0;
    node * head=nullptr;
    node * tail;

    void add(const int& data){
        node * n = new node(data,nullptr);
        if(_size==0){
            head->_node = n;
        }
        tail->_node=n;
        tail = tail->_node;
        _size++;
    }

    node * remove()
    {
        if(_size==0)
            return nullptr;

        node * n = head->_node;
        head->_node = head->_node->_node;
        --_size;
        
        return n;
    }
    
    void print()
    {
        node * n=head;
        for(int i=0;i<_size;i++)
        {
            n=n->_node;
            std::cout << n->_data << ",";
        }
        std::cout << std::endl;
        std::cout << "size:" << _size << std::endl;
    }

};

int main( int arg, char ** args)
{
    queue q;
    q.print();
    for (int i=0;i<7;i++)
    {
        q.add(i*i*i*2);
        q.print();
    }
    for (int i=0;i<7;i++)
    {
        delete q.remove();
        q.print();
    }
    return 0;
}