#include <vector>
#include <string>
#include <iostream>

/**
 * @brief HashEntry node used for linked list
 * 
 */
struct HashEntry{
    int _key;
    int _data;
    HashEntry * _next_node=nullptr;
    HashEntry(int k,int d):_key(k),_data(d){}
    ~HashEntry(){
        std::cout << "delete of " << this->_key << " " << this->_data << " called!" << std::endl;
    }
};

/**
 * @brief HashTable holds the array of nodes for link lists associated with hash codes.
 * 
 */
class HashTable{
    public:
    HashEntry** _table;
    std::vector<int> test;
    int _size=0;

    /**
     * @brief Construct a new Hash Table object
     * 
     * @param s size of the array 
     */
    HashTable(int s){
        _size=s;
        _table = new HashEntry*[_size];
        for(int i =0;i<_size;i++){
            _table[i]=nullptr;
        }
    }

    /**
     * @brief Destroy the Hash Table object
     * Deletes all the pointers created in the linked lists
     * 
     */
    ~HashTable()
    {
        std::cout << " Delete HashTable" << std::endl ;
        for(int i =0;i<_size;i++){
            HashEntry * next = nullptr;
            HashEntry * curr = nullptr;
            curr = _table[i];
            while(curr!=nullptr)
            {
                next = curr->_next_node;
                delete curr;
                curr = next;
            }
        }
    }

    /**
     * @brief 
     * Generates simple hash keys
     * @param k 
     * @return int 
     */
    int hashKey(int k){
        return k % _size;
    }

    /**
     * @brief Simple insert keys and data 
     * 
     * @param k 
     * @param d 
     */
    void insertKey(int k,int d){
        int hash_key = hashKey(k);
        HashEntry * prev=nullptr;
        HashEntry * curr = _table[hash_key];
        while(curr!=nullptr)
        {
            prev = curr;
            curr = curr->_next_node;
        }
        if(curr==nullptr)
        {
            curr = new HashEntry(k,d);
            if(prev==nullptr)
                _table[hash_key]=curr;
            else
                prev->_next_node = curr;            
            return;
        }
        std::cout << "error case insertKey" << std::endl; 
    }

    HashEntry * deleteKey(int k)
    {
        int hash_key = hashKey(k);
        HashEntry * prev=nullptr;
        HashEntry * curr = _table[hash_key];

        while(curr!=nullptr)
        {
            if( curr!=nullptr && curr->_key == k)
            {
                if(prev==nullptr){
                    prev = curr->_next_node;
                    if(prev!=nullptr)
                    {
                        _table[hash_key]=prev;
                    }
                    else{
                        _table[hash_key]=nullptr;
                    }
                }else{
                    prev->_next_node = curr->_next_node;
                }
                return curr;
            }
            prev = curr;
            curr = curr->_next_node;

        }
        std::cout<<"entry not presetn " << k << std::endl;

        return nullptr;
    }

    /**
     * @brief 
     * Ease for visual understanding
     * 
     */
    void printKey()
    {
        for(int i =0; i<_size;i++)
        {
            std::cout << "[" << i << "] \t";
            HashEntry * prev;
            HashEntry * curr = _table[i];
            while(curr!=nullptr)
            {
                std::cout << " --> ";
                std::cout << "(" << curr->_key << "," << curr->_data << ")";
                prev = curr;
                curr = curr->_next_node;
            }
            std::cout << std::endl;
        }
    }


};

int main( int args, char ** argv)
{
    HashTable * ht =  new HashTable(2);
    std::vector<int> keys;
    keys.push_back(39);
    keys.push_back(43);
    for(int i=0;i<5;i++){
        keys.push_back(i);
        ht->insertKey(i,i*2*i*i);
    }
    ht->printKey();
    
    for(int i=0;i<5;i++){
        HashEntry * temp = ht->deleteKey(i);
        delete temp; temp = nullptr;
        ht->printKey();
    }
    
    ht->printKey();

    delete ht;
}