



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