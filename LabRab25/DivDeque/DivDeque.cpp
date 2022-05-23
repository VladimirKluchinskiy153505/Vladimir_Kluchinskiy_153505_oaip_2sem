
#include "pch.h"
#include "framework.h"

using namespace std;
class pointer {
public:
    int x, y;
    pointer() {};
    pointer(int x, int y) :x(x), y(y) {};
    void set(int x,int y) {
        this->x = x;
        this->y = y;
    }
    pointer& operator++(){
        if (y < 3) { ++y; }
        else {
            ++x; y = 0;
        }
        return *this;
    }
    pointer& operator++(int) {
        if (y < 3) { ++y; }
        else {
            ++x; y = 0;
        }
        return *this;
    }
    bool operator!=(const pointer& other) {
        return((other.x != this->x) || (other.y != this->y));
    }
};

template <typename T>
class DivDeque {
public:
    template <typename T>
    class Iterator;
    DivDeque() {
        arr = new T* [rows];
        for (int i = 0; i < cols; ++i) {
            arr[i] = new int[cols];
        }
        First.set(0, 0);
        Last.set(0, -1);
        End.set(0, 0);
        capacity = 8;
        size = 0;
    }
    ~DivDeque() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        //delete[] arr;
    }

    void push_back(T core);//push
    void push_front(T core);

    void pop_front();//pop
    void pop_behind();
    void clear();
    void resize();
    size_t count();
    bool empty();
    Iterator<T> begin() {
        return Iterator<T>(First, arr);;
    }
    Iterator<T> end() {
        return Iterator<T>(End, arr);
    }
   template<typename T>
   class Iterator {
       //pointer cur;
       T** arr;
       pointer cur;
   public:
       // Iterator(pointer cur) :cur(cur) {}
       Iterator() {};
       Iterator(pointer ptr, T** arr) :cur(ptr), arr(arr) {}

       T& operator++() { ++cur; return arr[cur.x][cur.y]; }
       T& operator* () { return arr[cur.x][cur.y]; }
       bool operator!=(const Iterator& it) { return cur != it.cur; }
       void operator=(const Iterator& it) {
           this->cur = it.cur;
       }

   };
private:
    
    T** arr;//массив указателей на блоки
    size_t cols = 4;
    size_t rows=2;
    size_t capacity;
    size_t size;
    pointer First;
    pointer Last;
    pointer End;
};
template<typename T>
void DivDeque<T>::push_back(T core)
{
    if(this->size+1>this->capacity){
        this->resize();
    }
    this->arr[this->End.x][this->End.y] = core;//на свободное место после last
    ++this->End;
    ++this->Last;
    ++size;
}

template<typename T>
void DivDeque<T>::resize()
{
    T** newarr = new T * [rows * 2];//создаЄм новый двумерный массив с кол-вом р€дов в 2 раза больше
    for (int i = 0; i < rows*2; ++i) {//создаЄм в нЄм €чейки
        newarr[i] = new T[cols];
    }

    for (int i = 0; i < rows; ++i) {//копируем элементы из старого
        for (int j = 0; j < cols; ++j) {
            newarr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {//удал€ем старый массив
        delete[] arr[i];
    }
    delete[] **arr;
    arr = newarr;
    rows *= 2;
    capacity *= 2;
}

template<typename T>
size_t DivDeque<T>::count()
{
    return size;
}

template<typename T>
bool DivDeque<T>::empty()
{
    return !size;
}

