#include <iostream>
#include <exception>


/**
 * @brief 
 * Node used for the tree
 */
struct BSTNode
{
    BSTNode(int i):_data(i){}
    int _data;
    BSTNode * _left=nullptr;
    BSTNode * _right=nullptr;
};

/**
 * @brief 
 * Tree class that holds the tree and the calls to manipulate the tree.
 */
class BSTree
{
    private:
    BSTNode * _tree=nullptr;
    int print_helper = 0;

    public:
    /**
     * @brief Insert
     * insert item to the tree in form of a node.
     * @param i 
     */
    void insert(int i)
    {
        _tree = insert(i,_tree);
    }

    private:
    /**
     * @brief Insert
     * Private insert call used recursion
     * @param i 
     * @param node 
     * @return BSTNode* 
     */
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
    /**
     * @brief 
     * Delete entire tree
     */
    void deleteTree()
    {
        _tree = deleteTree(_tree);
    }

    private:
    /**
     * @brief 
     * delete tree using recursion
     * @param node 
     * @return BSTNode* 
     */
    BSTNode *  deleteTree(BSTNode * node)
    {
        if (node == nullptr) return nullptr;  
  
        /* first delete both subtrees */
        node->_left = deleteTree(node->_left);  
        node->_right = deleteTree(node->_right);  
            
        /* then delete the node */
        std::cout << "\n Deleting node: " << node->_data;  
        delete node; node=nullptr;
        return node; 
    }
    public:
    /**
     * @brief 
     * search item.
     * @param i 
     * @return true 
     * @return false 
     */
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

    private:
    /**
     * @brief 
     * Search call used for recursion
     * @param i 
     * @param _node 
     * @return true 
     * @return false 
     */
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
    /**
     * @brief Print tree
     * 
     */
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
    /**
     * @brief public access to delete item
     * 
     * @param data 
     */
    void deleteNode(int data)
    {
        _tree = deleteNode(_tree,data);
    }

    private:
    /**
     * @brief delete node
     * delete call for recursion use.
     * @param node 
     * @param data 
     * @return BSTNode* 
     */
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
                delete node; node = nullptr;
                return node;
            }
            else if(node->_left == nullptr)
            {
                BSTNode * temp = node;
                node = node->_right;
                delete temp; temp=nullptr;
                
            }
            else if(node->_right == nullptr)
            {
                BSTNode * temp = node;
                node = node->_left;
                delete temp; temp=nullptr;
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
        BSTNode * current = node;
        while(current&&current->_left !=nullptr)
            current=current->_left;
        
        return current;
    }
};



int main( int args, char ** argv){

    BSTree btr;
    btr.insert(4);
    btr.insert(1);
    btr.insert(2);
    btr.insert(3);
    btr.insert(5);
    btr.insert(6);
    btr.insert(7);
    btr.print();
    btr.deleteNode(4);
    btr.print();
    btr.deleteNode(5);
    btr.print();
    btr.deleteTree();
    btr.print();
    return 0;
}