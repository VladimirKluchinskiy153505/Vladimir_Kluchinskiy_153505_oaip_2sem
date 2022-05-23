#ifndef MY_DEQUE_H
#define MY_DEQUE_H
#include "Node.h"
#include <QDebug>
template <class Type>
class my_deque {
public:
    my_deque();
    ~my_deque();

    Node<Type>* search_from_begin(Type key);
    Node<Type>* search_from_end(Type key);

    void push_back(Type core);
    void push_front(Type core);
    //void print();

    void pop_front();
    void pop_behind();

    void insert(Type core, int number);
    void eraze( int number);
    void Delete();
    //void print();

    int count_nodes();
    void qsort1();
     void qsort2();
    void Swap(Type& val1, Type& val2);
    Type& operator[](int num);
private:
    void QuickSort1(my_deque<Type>& list, int start, int end);
      void QuickSort2(my_deque<Type>& list, int start, int end);
    int Partition1(my_deque<Type>& list, int start, int end);
    int Partition2(my_deque<Type>& list, int start, int end);
    Node<Type>* head;
    Node<Type>* tail;
    int number_of_nodes;
};


template<class Type>
my_deque<Type>::my_deque()
{
    this->number_of_nodes = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<class Type>
my_deque<Type>::~my_deque()
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
Node<Type>* my_deque<Type>::search_from_begin(Type key)
{
    Node<Type>* temp = head;
    while (temp->core != key) {
        temp = temp->next;
    }
    return temp;
}

template<class Type>
Node<Type>* my_deque<Type>::search_from_end(Type key)
{
    Node<Type>* temp = tail;
    while (temp->core != key) {
        temp = temp->prev;
    }
    return temp;
}

template<class Type>
void my_deque<Type>::push_back(Type core)
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
void my_deque<Type>::push_front(Type core)
{
    Node<Type>* obj = new Node<Type>(core);
    if (number_of_nodes) {
        obj->prev = nullptr;
        obj->next = head;

        head->prev = obj;
        head = obj;

    }
    else {
        head = obj;
        tail = head;
    }
    number_of_nodes++;
}

template<class Type>
void my_deque<Type>::pop_front()
{
    if (!number_of_nodes) {

        return;
    }
    else if (number_of_nodes == 1) {
        delete head;
    }
    else {
        Node<Type>* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;

    }
    number_of_nodes--;
}
template<class Type>
void my_deque<Type>::pop_behind()
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
void my_deque<Type>::insert(Type core, int index)
{
    if ((index < 0) || (index > number_of_nodes-1)) {

        return;
    }
    if (!number_of_nodes || number_of_nodes == 1 || index == number_of_nodes-1) {
        this->push_back(core);
    }

    else
    {
        Node<Type>* obj_prev;
        if (index < (number_of_nodes / 2)) {
            obj_prev = head;
            for (int i = 0; i < index; i++) {
                obj_prev = obj_prev->next;
            }
        }
        else {
            obj_prev = tail;
            for (int i = number_of_nodes-1; i > index; i--) {
                obj_prev = obj_prev->prev;
            }
        }
        Node<Type>* obj_next = obj_prev->next;
        Node<Type>* obj = new Node<Type>(core);
        obj_prev->next = obj;
        obj->prev = obj_prev;
        obj->next = obj_next;
        obj_next->prev = obj;
        number_of_nodes++;
    }
}
template<class Type>
void my_deque<Type>::eraze( int index)
{
    if ((index < 0) || (index > number_of_nodes-1)) {

        return;
    }
    if ( number_of_nodes == 1) {
        this->pop_front();
    }
    else if (!index) {
        this->pop_front();
    }
    else if (index == number_of_nodes-1)
    {
        this->pop_behind();
    }
    else
    {
        Node<Type>* obj_to_del;
        if(index<(number_of_nodes/2)){
        obj_to_del=head;
        for (int i = 0; i < index; i++) {
            obj_to_del = obj_to_del->next;
        }
        }
        else {
             obj_to_del = tail;
            for (int i = number_of_nodes-1; i > index; i--) {
                obj_to_del = obj_to_del->prev;
            }
        }
        Node<Type>* obj_next = obj_to_del->next;
        Node<Type>* obj_prev = obj_to_del->prev;
        obj_prev->next = obj_next;
        obj_next->prev = obj_prev;
        number_of_nodes--;
    }
}

template<class Type>
void my_deque<Type>::Delete()
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
    number_of_nodes=0;
}
//template<class Type>
//void my_deque<Type>::print()
//{
//    Node<Type>* temp = head;
//    for (int i = 0; i < number_of_nodes; i++) {
//        temp->print();
//        temp = temp->next;
//    }
//}
template<class Type>
int my_deque<Type>::count_nodes()
{
    return number_of_nodes;
}
template<class Type>
void my_deque<Type>::QuickSort1(my_deque<Type>& list, int start, int end)
{
    if (start < end) {
        int q = Partition1(list, start, end);
        QuickSort1(list, start, q - 1);
        QuickSort1(list, q + 1, end);
    }
}
template<class Type>
void my_deque<Type>::QuickSort2(my_deque<Type>& list, int start, int end)
{
    if (start < end) {
        int q = Partition2(list, start, end);
        QuickSort2(list, start, q - 1);
        QuickSort2(list, q + 1, end);
    }
}
template<class Type>
int my_deque<Type>::Partition1(my_deque<Type>& list, int start, int end)
{
    int graw = start;
    for (int i = start; i < end; i++) {
        if (list[i] <= list[end]) {
            Swap(list[i], list[graw]);
            graw++;
        }
    }
    Swap(list[graw], list[end]);
    return graw;
}
template<class Type>
int my_deque<Type>::Partition2(my_deque<Type>& list, int start, int end)
{
    int graw = start;
    for (int i = start; i < end; i++) {
        if (list[i] >= list[end]) {
            Swap(list[i], list[graw]);
            graw++;
        }
    }
    Swap(list[graw], list[end]);
    return graw;
}
template<class Type>
void my_deque<Type>::qsort1()
{
    QuickSort1(*this, 0, number_of_nodes - 1);
}
template<class Type>
void my_deque<Type>::qsort2()
{
    QuickSort2(*this, 0, number_of_nodes - 1);
}
template<class Type>
void my_deque<Type>::Swap(Type& val1, Type& val2)
{
    Type temp = val1;
    val1 = val2;
    val2 = temp;
}

template<class Type>
Type& my_deque<Type>::operator[](int num)
{
    Node<Type>* temp;
    if (num < (number_of_nodes / 2)) {
        temp = head;
        for (int i = 0; i < num; i++) {
            temp = temp->next;
        }
    }
    else {
        temp = tail;
        for (int i = number_of_nodes - 1; i > num; i--) {
            temp = temp->prev;
        }
    }
    return temp->core;
}
#endif // MY_DEQUE_H
