#ifndef MY_STACK_H
#define MY_STACK_H
template<class Type>
class Node {
public:
    Node* next;
    Node* prev;
    Type core;
    Node(const Type& core) {
        this->next = nullptr;
        this->prev = nullptr;
        this->core = core;
    }
};

template <class Type>
class my_stack {
public:
    my_stack();
    ~my_stack();


    void push(Type core);
     void pop();
     Type& top();
     bool empty();

    void Delete();
    //void print();

    int size();

private:

    Node<Type>* head;
    Node<Type>* tail;
    int number_of_nodes;
};

template<class Type>
my_stack<Type>::my_stack()
{
    this->number_of_nodes = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<class Type>
my_stack<Type>::~my_stack()
{
    if (!number_of_nodes) {
        return;
    }
    Node<Type>* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        delete head;
        head = temp;
    }
    delete head;
}

template<class Type>
void my_stack<Type>::push(Type core)
{
    Node<Type>* obj = new Node<Type>(core);
    if (number_of_nodes) {
        tail->next = obj;

        obj->prev = tail;
        obj->next = nullptr;
        tail = obj;
    }
    else {
        head = obj;
        tail = head;
    }
    number_of_nodes++;
}

template<class Type>
void my_stack<Type>::pop()
{
    if (!number_of_nodes) {
        return;
    }
    else if (number_of_nodes == 1) {
        delete head;
    }
    else {
        Node<Type>* temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    number_of_nodes--;
}

template<class Type>
Type& my_stack<Type>::top()
{
    return tail->core;
}

template<class Type>
bool my_stack<Type>::empty()
{
    return !number_of_nodes;
}

template<class Type>
void my_stack<Type>::Delete()
{
    if (!number_of_nodes) {
        return;
    }
    Node<Type>* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        delete head;
        head = temp;
    }
    delete head;
    number_of_nodes = 0;
}

template<class Type>
int my_stack<Type>::size()
{
    return number_of_nodes;
}
#endif // MY_STACK_H
