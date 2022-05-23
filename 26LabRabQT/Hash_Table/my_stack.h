#ifndef MY_STACK_H
#define MY_STACK_H
template <typename T>
class my_stack {
public:
    template<typename T>
    class Node {
    public:
        Node(const T core) {
            this->core = core;
        }
        ~Node() {
        }
        //my_unique_ptr<Node<U>> prev;
        Node<T>* prev=nullptr;
        T core;
    };
    my_stack();
    ~my_stack();
    void clear(Node<T>* root);
    void eraze(size_t num);
    void push(T core);
    void pop();
    T& top();
    Node<T>* top_node() {
        if (number_of_nodes) { return head; }
        else { return nullptr; }
    }
    bool empty();
    T& operator[](size_t num);
    void operator=(my_stack<T>& otherlist);
    //void print();

    size_t size();

private:

    Node<T>* head=nullptr;
    int number_of_nodes;
};

template<typename T>
my_stack<T>::my_stack()
{
    this->number_of_nodes = 0;
}

template<typename T>
my_stack<T>::~my_stack()
{
    clear(head);
}

template<typename T>
void my_stack<T>::clear(Node<T>* root)
{
    if (root != nullptr) {
        clear(root->prev);
        delete root;
    }
}

template<typename T>
void my_stack<T>::eraze(size_t num)
{
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
void my_stack<T>::push(T core)
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
void my_stack<T>::pop()
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
T& my_stack<T>::top()
{
    if (number_of_nodes) { return head->core; }
    //else { return nullptr; }
}

template<typename T>
bool my_stack<T>::empty()
{
    return !number_of_nodes;
}

template<typename T>
T& my_stack<T>::operator[](size_t num)
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
void my_stack<T>::operator=(my_stack<T>& otherlist)
{
    clear(head);
    Node<T>* temp = otherlist.head;
       while (temp != nullptr) {
           push(temp->core);
           temp = temp->prev;
   }
}
template<typename T>
size_t my_stack<T>::size()
{
    return number_of_nodes;
}
#endif // MY_STACK_H
