#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include<QDebug>
template <typename T>
class my_list {
public:
    template<typename T>
    class Node {
    public:
        Node(){}
    /*Node(T core):core(core){
    }*/
        Node( T& core) {
            this->core = core;
        }

        Node(T&& core):core(core){
        }
        ~Node() {
            qDebug() << "Destr Node\n";
        }
        Node<T>* prev = nullptr;
        T core;
    };
    class List_Iterator {
        Node<T>* cur;
        my_list<T>* ptr;
        size_t index;
    public:
        List_Iterator( Node<T>* cur,my_list<T>* ptr):cur(cur),ptr(ptr),index(0){}
        List_Iterator operator++() {
            if (cur->prev != nullptr) { cur = cur->prev; ++index; }
            else { cur = nullptr; }
            return *this;
        }
        void del() { ptr->eraze(index); }
         T& operator*() { return cur->core; }
        bool operator!=(const List_Iterator& other) { return this->cur != other.cur; }
    };
    List_Iterator begin() { return List_Iterator(head, this); }
    List_Iterator end() { return List_Iterator(nullptr, this); }
    my_list();
    ~my_list();
    void clear(Node<T>* root);
    void eraze(size_t num);
    void push(T&& core);
    void emplace(T&& core);
    void pop();
    T& top();
    Node<T>* top_node() {
        if (number_of_nodes) { return head; }
        else { return nullptr; }
    }
    bool empty();
    T& operator[](size_t num);
    void operator=(my_list<T>& otherlist);
    //void print();

    size_t size();

private:

    Node<T>* head = nullptr;
    size_t number_of_nodes;
};

template<typename T>
my_list<T>::my_list()
{
    this->number_of_nodes = 0;
}

template<typename T>
my_list<T>::~my_list()
{
    clear(head);
}

template<typename T>
void my_list<T>::clear(Node<T>* root)
{
    if (root != nullptr) {
        clear(root->prev);
        delete root;
    }
}

template<typename T>
void my_list<T>::eraze(size_t num)
{
    if (number_of_nodes == 0) { return; }
    if (num >= number_of_nodes) {
        num = number_of_nodes - 1;
    }
    Node<T>* temp = head;
    if (!num) {
        head = head->prev;
        delete temp;
    }
    else {
        size_t k = 0;
        while (k < num - 1) {
            temp = temp->prev;
            ++k;
        }
        Node<T>* temp2 = temp->prev->prev;
        delete temp->prev;
        temp->prev = temp2;
    }
    --number_of_nodes;
}

template<typename T>
void my_list<T>::push(T&& core)
{
    Node<T>* obj = new Node<T>(core);
    if (number_of_nodes) {
        obj->prev = head;
        head = obj;
    }
    else {
        head = obj;
    }
    ++number_of_nodes;
}

template<typename T>
void my_list<T>::emplace(T&& core)
{
    Node<T>* obj = new Node<T>(core);
    if (number_of_nodes) {
        obj->prev = head;
        head = obj;
    }
    else {
        head = obj;
    }
    ++number_of_nodes;
}

template<typename T>
void my_list<T>::pop()
{
    if (!number_of_nodes) {
        return;
    }
    else if (number_of_nodes == 1) {
        delete head;
    }
    else {
        Node<T>* temp = head;
        head = head->prev;
        delete temp;
    }
    --number_of_nodes;
}

template<typename T>
T& my_list<T>::top()
{
    if (number_of_nodes) { return head->core; }
    //else { return nullptr; }
}

template<typename T>
bool my_list<T>::empty()
{
    return !number_of_nodes;
}
template<typename T>
T& my_list<T>::operator[](size_t num)
{
    if (num >= number_of_nodes) {
        num = number_of_nodes - 1;
    }
    Node<T>* temp = head;
    for (int i = 0; i < num; ++i) {
        temp = temp->prev;
    }
    return temp->core;
}

template<typename T>
void my_list<T>::operator=(my_list<T>& otherlist)
{
    clear(head);
    Node<T>* temp = otherlist.head;
    while (temp != nullptr) {
        push(temp->core);
        temp = temp->prev;
    }
}
template<typename T>
size_t my_list<T>::size()
{
    return number_of_nodes;
}

#endif // FORWARD_LIST_H
