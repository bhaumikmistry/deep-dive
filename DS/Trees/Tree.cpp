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
    }

    private:
    void print(BSTNode * node)
    {   
        std::cout << " --> ";
        if(node==nullptr){
            std::cout << " |||";
            std::cout << std::endl;
        }else
        {
            std::cout << " " << std::to_string(node->_data) << " " << std::endl;
            print(node->_left);
            print(node->_right);
        }
        
    }

};

int main( int args, char ** argv){

    BSTree btr;
    btr.insert(4);
    btr.insert(1);
    btr.insert(2);
    btr.insert(5);
    btr.insert(6);
    btr.print();
    return 0;
}