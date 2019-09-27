#include <iostream>

struct BSTNode
{
    BSTNode(int i):_data(i){}
    int _data;
    BSTNode * _left=nullptr;
    BSTNode * _right=nullptr;
};

class BSTree
{
    private:
    BSTNode * _tree=nullptr;
    int print_helper = 0;
    public:
    void insert(int i)
    {
        _tree = insert(i,_tree);
    }

    private:
    BSTNode * insert(int i,BSTNode * node){
        if(node==nullptr)
        {
            node = new BSTNode(i);
        }else if(node->_data > i)
        {
            node->_left = insert(i,node->_left);
        }else
        {
            node->_right = insert(i,node->_right);
        }
        return node;
    }

    public:
    bool remove(int i,BSTNode * _node)
    {
        return false;
    }

    bool search(int i)
    {
        return false;
    }

    public:
    void print()
    {
        print(_tree);
        std::cout << std::endl;
    }

    private:
    void print(BSTNode * node)
    {   
        if(node==nullptr){
            std::cout << "X";      
        }else
        {
            std::cout << "{";
            std::cout << std::to_string(node->_data);
            std::cout << ",";
            print(node->_left);
            std::cout << ",";
            print(node->_right);
            std::cout << "}";
        }
    }

};

int main( int args, char ** argv){

    BSTree btr;
    btr.insert(4);
    btr.insert(1);
    btr.insert(2);
    btr.insert(0);
    btr.insert(6);
    btr.insert(5);
    btr.insert(7);
    btr.print();
    return 0;
}