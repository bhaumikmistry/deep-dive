#include <vector>
#include <string>
#include <iostream>

struct HashEntry{
    int _key;
    int _data;
    HashEntry * _next_node=nullptr;
    HashEntry(int k,int d):_key(k),_data(d){}
    ~HashEntry(){
        std::cout << "delete of " << this->_key << " " << this->_data << " called!" << std::endl;
    }
};

class HashTable{
    public:
    HashEntry** _table;
    std::vector<int> test;
    int _size=0;
    HashTable(int s){
        _size=s;
        _table = new HashEntry*[_size];
        for(int i =0;i<_size;i++){
            _table[i]=nullptr;
        }
    }

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

    int hashKey(int k){
        return k % _size;
    }

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
        return nullptr;
    }

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
    HashTable * ht =  new HashTable(10);
    for(int i=0;i<25;i++){
        ht->insertKey(i,i*2*i*i);
    }
    ht->printKey();
    delete ht;
}