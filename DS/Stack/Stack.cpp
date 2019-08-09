#include <stddef.h>
#include <iostream>

class node
{
    public:
    int i;
    node * link;
    node(int data,node * n);
};

node::node(int data, node * n)
{
    i = data;
    link = n;
}

class Stack
{
public:
    node * head=NULL;
    int size=0;
    int max;
    Stack(int max=1000);
    ~Stack();
    bool push(int i);
    int pop();
};

Stack::Stack(int m){max = m;}

Stack::~Stack(){}

bool Stack::push(int i)
{   
    if(size==max)
    {
        return false;
    }
    head = new node(i,head);
    size++;
    return true;
}

int Stack::pop()
{
    if(size==0)
    {
        throw "error underflow";
    }
    int temp = head->i;
    node * tempN = head->link;
    delete head;
    head = tempN;
    size--;
    return temp;
}

int main(int arg,char ** args)
{
    std::cout << "main()" << std::endl;

    Stack s(10);

    for(int i=0;i<5;i++)
    {
        s.push(i);
        std::cout << s.head->i << " " << s.size << std::endl;
    }

    for(int i=0;i<5;i++)
    {
        
        std::cout << s.size << " " << s.pop() << std::endl;
    }

    return 0;
}