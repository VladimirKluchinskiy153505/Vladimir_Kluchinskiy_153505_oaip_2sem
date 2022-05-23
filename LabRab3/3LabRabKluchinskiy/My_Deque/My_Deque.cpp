// My_Deque.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\Weak_Shared\Weak_Shared.cpp>
// TODO: This is an example of a library function
template<class T>
class Node {
public:
    my_weak_ptr<Node<T>> prev;
    shar_ptr<Node<T>> next;
    T core;
    Node(const T& core) {
        this->core = core;
        cout << "constr node\n";
    }
    ~Node() {
        cout << "destr node "<<core<<"\n";
        //next.~shar_ptr();
    }
};
template <typename T>
class my_deque {
public:
    my_deque();
    ~my_deque();

    shar_ptr<Node<T>> search_from_begin(T key);
    shar_ptr<Node<T>> search_from_end(T key);

    void push_back(T core);
    void push_front(T core);
    //void print();

    void pop_front();
    void pop_behind();

    void insert(T core, int number);
    void eraze(int number);
    void Delete();
    //void print();

    int count_nodes();
    void qsort1();
    void qsort2();
    void Swap(T& val1, T& val2);
    T& operator[](int num);
public:
    void QuickSort1(my_deque<T>& list, int start, int end);
    void QuickSort2(my_deque<T>& list, int start, int end);
    int Partition1(my_deque<T>& list, int start, int end);
    int Partition2(my_deque<T>& list, int start, int end);
    shar_ptr<Node<T>> head;
    shar_ptr<Node<T>> tail;
    int number_of_nodes;
};


template<typename T>
my_deque<T>::my_deque()
{
    this->number_of_nodes = 0;
}

template<class Type>
my_deque<Type>::~my_deque()
{
   // head.~shar_ptr();
   // tail.make_null();
}

template<typename T>
shar_ptr<Node<T>> my_deque<T>::search_from_begin(T key)
{
    shar_ptr<Node<T>> temp(head);
    while (temp->core != key) {
        temp.new_own(temp->next);
    }
    return temp;
}

template<typename T>
shar_ptr<Node<T>> my_deque<T>::search_from_end(T key)
{
    shar_ptr<Node<T>> temp (tail);
    while (temp->core != key) {
        temp.new_own(temp->prev.lock());
    }
    return temp;
}

template<typename T>
void my_deque<T>::push_back(T core)
{
    shar_ptr<Node<T>> obj (new Node<T>(core));
    if (number_of_nodes) {
        tail->next.new_own(obj);

        obj->prev = Move(my_weak_ptr<Node<T>>(tail));
        tail.new_own(obj);
    }
    else {
        head.new_own( obj);
        
        tail.new_own(obj);

    }
    number_of_nodes++;
}

template<typename T>
void my_deque<T>::push_front(T core)
{
    shar_ptr<Node<T>> obj (new Node<T>(core));
    if (number_of_nodes) {
        obj->next.new_own(head);

        head->prev = Move(my_weak_ptr<Node<T>>(obj));
        head.new_own(obj);

    }
    else {
        head.new_own(obj);
        tail.new_own(obj);
    }
    number_of_nodes++;
}

template<typename T>
void my_deque<T>::pop_front()
{
    if (!number_of_nodes) {

        return;
    }
    else if (number_of_nodes == 1) {
        head.~shar_ptr();
    }
    else {
        shar_ptr<Node<T>> temp (head->next);
         head.del_with_change(temp);
    }
    number_of_nodes--;
}
template<typename T>
void my_deque<T>::pop_behind()
{
    if (!number_of_nodes) {
        return;
    }
    else if (number_of_nodes == 1) {
        head.~shar_ptr();
    }
    else {
        shar_ptr<Node<T>> temp (tail->prev.lock());
        
        tail.del_with_change(temp);
    }
    number_of_nodes--;
}
template<class T>
void my_deque<T>::insert(T core, int index)
{
    if ((index < 0) || (index > number_of_nodes - 1)) {

        return;
    }
    if (!number_of_nodes || number_of_nodes == 1 || index == number_of_nodes - 1) {
        this->push_back(core);
    }

    else
    {
        shar_ptr<Node<T>> obj_prev;
        if (index < (number_of_nodes / 2)) {
            obj_prev.new_own(head);
            for (int i = 0; i < index; i++) {
                obj_prev.new_own(obj_prev->next);
            }
        }
        else {
            obj_prev.new_own(tail);
            for (int i = number_of_nodes - 1; i > index; i--) {
                obj_prev.new_own(obj_prev->prev.lock());
            }
        }
        shar_ptr<Node<T>> obj_next(obj_prev->next);
        shar_ptr<Node<T>> obj (new Node<T>(core));
        obj_prev->next.new_own(obj);
        obj->prev = Move(my_weak_ptr<Node<T>>(obj_prev));
        obj->next.new_own(obj_next);
        obj_next->prev = Move(my_weak_ptr<Node<T>>(obj));
        number_of_nodes++;
    }
}
template<typename T>
void my_deque<T>::eraze(int index)
{
    if ((index < 0) || (index > number_of_nodes - 1)) {

        return;
    }
    if (number_of_nodes == 1) {
        this->pop_front();
        return;
    }
    else if (!index) {
        this->pop_front();
        return;
    }
    else if (index == number_of_nodes - 1)
    {
        this->pop_behind();
        return;
    }
    else
    {
        shar_ptr<Node<T>> obj_to_del;
        if (index < (number_of_nodes / 2)) {
            obj_to_del.new_own(head);
            for (int i = 0; i < index; i++) {
                obj_to_del.new_own(obj_to_del->next);
            }
        }
        else {
            obj_to_del.new_own(tail);
            for (int i = number_of_nodes - 1; i > index; i--) {
                obj_to_del = Move(obj_to_del->prev.lock());
            }
        }
        shar_ptr<Node<T>> obj_next(obj_to_del->next);
        shar_ptr<Node<T>> obj_prev(obj_to_del->prev.lock());
        obj_prev->next.new_own(obj_next);
        obj_next->prev = Move(my_weak_ptr<Node<T>>(obj_prev));
        number_of_nodes--;
    }
}

template<typename T>
void my_deque<T>::Delete()
{
    head.~shar_ptr();
}
template<typename T>
int my_deque<T>::count_nodes()
{
    return number_of_nodes;
}
template<typename T>
void my_deque<T>::QuickSort1(my_deque<T>& list, int start, int end)
{
    if (start < end) {
        int q = Partition1(list, start, end);
        QuickSort1(list, start, q - 1);
        QuickSort1(list, q + 1, end);
    }
}
template<typename T>
void my_deque<T>::QuickSort2(my_deque<T>& list, int start, int end)
{
    if (start < end) {
        int q = Partition2(list, start, end);
        QuickSort2(list, start, q - 1);
        QuickSort2(list, q + 1, end);
    }
}
template<typename T>
int my_deque<T>::Partition1(my_deque<T>& list, int start, int end)
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
template<typename T>
int my_deque<T>::Partition2(my_deque<T>& list, int start, int end)
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
template<typename T>
void my_deque<T>::qsort1()
{
    QuickSort1(*this, 0, number_of_nodes - 1);
}
template<typename T>
void my_deque<T>::qsort2()
{
    QuickSort2(*this, 0, number_of_nodes - 1);
}
template<typename T>
void my_deque<T>::Swap(T& val1, T& val2)
{
    T temp = Move(val1);
    val1 = Move(val2);
    val2 = Move(temp);
}

template<typename T>
T& my_deque<T>::operator[](int num)
{
    shar_ptr<Node<T>> temp;
    if (num < (number_of_nodes / 2)) {
        temp.new_own(head);
        for (int i = 0; i < num; i++) {
            temp.new_own(temp->next);
        }
    }
    else {
        temp.new_own(tail);
        for (int i = number_of_nodes - 1; i > num; i--) {
            temp.new_own(temp->prev.lock());
        }
    }
    return temp->core;
}
