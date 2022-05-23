#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <memory>
using namespace std;
template<typename T>
class Node {
public:
    weak_ptr<Node<T>> prev;
    shared_ptr<Node<T>> next;
    T core;
    Node() {};
    Node(T core) {
        this->core = core;
    }
    ~Node() {
       qDebug() << "\ndestr was called for "<<static_cast<int>(core)<<'\n';
    }
};
template <typename T>
class my_queue {
   // friend Bubble_queue;
public:
    my_queue();
    ~my_queue();


    void push_back(T core);//push
    void push_front(T core);
    void clear();
    void pop_front();//pop
    void pop_behind();
    T& front();//front
    T& back();//back
    bool empty();//empty
    int size();//size

    T& operator[](int num);
protected:

    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    int number_of_nodes;
};

template<typename T>
void my_queue<T>::clear()
{
    while (number_of_nodes) {
        this->pop_front();
    }
}

template<typename T>
my_queue<T>::my_queue()
{
    this->number_of_nodes = 0;
}

template<typename T>
my_queue<T>::~my_queue()
{

}

template<typename T>
bool my_queue<T>::empty() {
    return !number_of_nodes;
}
template<typename T>
void my_queue<T>::push_back(T core)
{
    shared_ptr<Node<T>> obj(new Node<T>(core));
    if (number_of_nodes) {
        tail->next=shared_ptr<Node<T>>(obj);
       // weak_ptr<Node<T>> temp(tail);

        obj->prev=weak_ptr<Node<T>>(tail);

        obj->next = nullptr;
        tail=shared_ptr<Node<T>>(obj);
    }
    else {
        head=shared_ptr<Node<T>>(obj);
        tail= obj;
    }
    ++number_of_nodes;
}

template<class T>
void my_queue<T>::push_front(T core)
{
    shared_ptr<Node<T>> obj(new Node<T>(core));
    if (number_of_nodes) {
        obj->next = shared_ptr<Node<T>>(head);

        head->prev = weak_ptr<Node<T>>(obj);
        head = obj;

    }
    else {
        head = shared_ptr<Node<T>>(obj);
        tail = obj;
    }
    ++number_of_nodes;
}

template<class T>
void my_queue<T>::pop_behind()
{
    if (!number_of_nodes) {

        return;
    }
    else if (number_of_nodes == 1) {
        head.~shared_ptr();
        tail.~shared_ptr();
    }
    else {
        tail.~shared_ptr();
        tail = shared_ptr<Node<T>>(tail->prev.lock());

    }
    --number_of_nodes;
}
template<typename T>
T& my_queue<T>::front()
{
    return head->core;
}
template<typename T>
T& my_queue<T>::back()
{
    return tail->core; // TODO: insert return statement here
}
template<typename T>
void my_queue<T>::pop_front()
{
    if (!number_of_nodes) {
        return;
    }
    else if (number_of_nodes == 1) {
        head.~shared_ptr();
        tail.~shared_ptr();
    }
    else {
        head = shared_ptr<Node<T>>(head->next);

    }
    --number_of_nodes;
}


template<typename Type>
int my_queue<Type>::size()
{
    return number_of_nodes;
}

template<typename T>
T& my_queue<T>::operator[](int num)
{

    shared_ptr<Node<T>> temp;
    if (num < (number_of_nodes / 2)) {
        temp=shared_ptr<Node<T>>(head);
        for (int i = 0; i < num; i++) {
            temp=shared_ptr<Node<T>>(temp->next);
        }
    }
    else {
        temp=shared_ptr<Node<T>>(tail);
        for (int i = number_of_nodes - 1; i > num; i--) {
            temp = (temp->prev).lock();
        }
    }
    return temp->core;
}
template<typename U>
class BuQueue :public my_queue<U> {
public:
    void bubble_sort2() {
        for (size_t i = 0; i < this->number_of_nodes - 1; ++i) {
            for (size_t j = 0; j < this->number_of_nodes - i - 1; ++j) {
                if (this->operator[](j+1) > this->operator[](j)) {
                    swap(this->operator[](j), this->operator[](j+1));
                }
            }
        }
    }
    void bubble_sort() {
        for (size_t i = 0; i < this->number_of_nodes - 1; ++i) {
            shared_ptr<Node<U>> temp(this->head);
            for (size_t j = 0; j < this->number_of_nodes - i - 1; ++j) {

                if (temp->core > (temp->next->core)) {
                    swap(temp->core, temp->next->core);
                }
                temp = shared_ptr<Node<U>>(temp->next);
            }
        }
    }
};

#endif // QUEUE_H
