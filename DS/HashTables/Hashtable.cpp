#include <vector>
#include <string>

struct HashEntry{
    int _key;
    int _data;
    HashEntry * _next_node;
    HashEntry(int k,int d):_key(k),_data(d){}
};

class HashTable{

    std::vector<HashEntry*> _table;
    int _size=0;
    HashTable(int s):_size(s){
        _table.resize(_size);
        for(int i =0;i<_size;i++){
            _table[i]=nullptr;
        }
    }

    void insertKey(int k,int d){

    }

    HashEntry * deleteKey(int k)
    {
        return nullptr;
    }

    void printKey()
    {

    }


};


int main( int args, char ** argv)
{

}