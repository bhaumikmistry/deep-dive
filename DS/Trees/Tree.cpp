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
        if(search (i,_tree)){
            std::cout << i << " Found" << std::endl;
            return true;
        }
        else
        {
            std::cout << i << " Not found" << std::endl;
            return false;
        }
    }

    bool search (int i, BSTNode * _node)
    {
        if(_node!=nullptr){
            if(_node->_data==i){
                return true;
            }
            else if(_node->_data>i)
            {
                return search(i,_node->_left);
            }
            else{
                return search(i,_node->_right);
            }
        }else
        {
            return false;
        }
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

    public:
    void deleteNode(int data)
    {
        BSTNode * temp = deleteNode(_tree,data);
        if(temp!=nullptr)
            delete temp;
    }

    private:
    BSTNode * deleteNode(BSTNode * node,int data)
    {
        if(node==nullptr)
            return node;
        else if(data < node->_data)
            node->_left = deleteNode(node->_left,data);
        else if(data > node->_data)
            node->_right = deleteNode(node->_right,data);
        else
        {
            if(node->_left == nullptr && node->_right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if(node->_left==nullptr)
            {
                BSTNode * temp = node->_right;
                node = node->_right;
                delete temp;
            }
            else if(node->_right == nullptr)
            {
                BSTNode * temp = node->_right;
                node = node->_left;
                delete temp;
            }
            else
            {
                BSTNode * temp = findMin(node->_right);
                node->_data = temp->_data;
                node->_right = deleteNode(node->_right,temp->_data);
            }
        }
        return node;
    }

    BSTNode * findMin(BSTNode * node)
    {
        if(node==nullptr)
        {
            return node;
        }
        else if(node->_left ==nullptr && node->_right==nullptr)
        {   
            return node;
        }
        else if(node->_left->_data < node->_data)
        {
            return findMin(node->_left);
        }else
        {
            return findMin(node->_right);
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
    btr.insert(8);
    btr.print();
    btr.search(7);
    btr.search(2);
    btr.search(34);
    btr.insert(34);
    btr.print();
    btr.search(34);
    btr.deleteNode(34);
    btr.deleteNode(8);
    btr.print();

    return 0;
}