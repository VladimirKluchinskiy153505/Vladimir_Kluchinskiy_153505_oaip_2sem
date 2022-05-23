// GreatDeque.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
using namespace std;
class pointer {
public:
    int x, y;
    pointer() {};
    pointer(int x, int y) :x(x), y(y) {};
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void setx(int x) {
        this->x = x;
    }
    void sety(int y) {
        this->y = y;
    }
    /*pointer& operator+(int num) {
    }*/
    pointer& operator++() {
        if (y < 3) { ++y; }
        else {
            ++x; y = 0;
        }
        return *this;
    }
    pointer& operator--() {
        if (y >0) { --y; }
        else {
            --x; y = 3;
        }
        return *this;
    }
    pointer& operator--(int) {
        pointer temp(this->x, this->y);
        if (temp.y > 0) { --temp.y; }
        else {
            --temp.x; temp.y = 3;
        }
        return temp;
    }
    pointer& operator++(int) {
        pointer temp(this->x,this->y);
        if (temp.y < 3) { ++temp.y; }
        else {
            ++temp.x; temp.y = 0;
        }
        return temp;
    }
    bool operator!=(const pointer& other) {
        return((other.x != this->x) || (other.y != this->y));
    }
};

template <typename T>
class GreatDeque {
public:
    template <typename T>
    class Iterator;
    GreatDeque() {
        vec_ptr = new T * [blocks];
        for (int i = 0; i < blocks; ++i) {
            vec_ptr[i] = new int[k];
        }

        First.set(0, 0);
       // Last.set(0, -1);
        End.set(0, 0);
    }
    ~GreatDeque() {
        for (int i = 0; i < blocks; ++i) {
            delete[] vec_ptr[i];
        }
        delete[] vec_ptr;
    }
   void print() {
       cout << '\n';
        for (int i = 0; i < blocks; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << vec_ptr[i][j] << " ";
            }
            cout << '\n';
        }
    }
    void push_back(T core);//push
    void push_front(T core);

    void pop_front();//pop
    void pop_behind();
    void clear();
    void resize_back();
    void resize_front();
    size_t count();
    bool empty();
    Iterator<T> begin() {
        return Iterator<T>(First, this);;
    }
    Iterator<T> end() {
        return Iterator<T>(End, this);
    }
    T& operator[](size_t num) {
        if (num >= size) { num = size - 1; }
        size_t dest = (First.x) * (k) + (First.y) + num;
        pointer temp(dest / 4, dest % 4);
        return vec_ptr[temp.x][temp.y];
    }
    template<typename T>
    class Iterator {
        //pointer cur;
        GreatDeque* dptr;
        pointer cur;
    public:
        // Iterator(pointer cur) :cur(cur) {}
        Iterator() {};
        Iterator(pointer ptr,GreatDeque* deque ) :cur(ptr),dptr(deque) {}

        T& operator++() { ++cur; return dptr->vec_ptr[cur.x][cur.y]; }
        T& operator--() { --cur; return dptr->vec_ptr[cur.x][cur.y]; }
        T& operator* () { return dptr->vec_ptr[cur.x][cur.y]; }
        T& operator[](size_t num) {
            if (num >= size) { num = size - 1; }
            size_t dest = (dptr->First.x)*(dptr->k)+(dptr->First.y)+num;
            pointer temp(dest / 4, dest % 4);
            return dptr->vec_ptr[temp.x][temp.y];
        }
        T& operator+=(size_t n) {
            size_t dest = (cur.x * dptr->k + cur.y + n);
            if (dest >= dptr->size) { dest = dptr->size; }
            else if (dest < 0) { dest = 0; }
            pointer temp(dest / 4, dest % 4);
            cur = temp;
            return dptr->vec_ptr[temp.x][temp.y];
        }
        T& operator-=(size_t n) {
            size_t dest = (cur.x * dptr->k + cur.y - n);
            if (dest >= dptr->size) { dest = dptr->size; }
            else if (dest < 0) { dest = 0; }
            pointer temp(dest / 4, dest % 4);
            cur = temp;
            return dptr->vec_ptr[temp.x][temp.y];
        }
        bool operator!=(const Iterator& it) { return cur != it.cur; }
        void operator=(const Iterator& it) {
            this->cur = it.cur;
        }

    };
private:
    T** vec_ptr;//массив указателей на блоки
    size_t blocks=1;//кол-во блоков
    size_t k=4;//кол-во ячеей в блоке
    size_t capacity=4;
    size_t size = 0;
    pointer First;
    pointer End;
};
template<typename T>
void GreatDeque<T>::push_back(T core)
{
    if ((End--).x==blocks-1 && (End--).y==3) {
        this->resize_back();
    }
    this->vec_ptr[this->End.x][this->End.y] = core;//на свободное место после last
    ++this->End;
    ++size;

}
template<typename T>
void GreatDeque<T>::push_front(T core)
{
    if (this->First.x==0 && this->First.y==0) {
        this->resize_front();
    }
   // --First;//сдвигаем первый на единицу влево
    if (size) {
        --First;
    }
    this->vec_ptr[this->First.x][this->First.y]=core;
    ++size;
}
template<typename T>
void GreatDeque<T>::pop_front()
{
    if (size) {
        vec_ptr[First.x][First.y].~T();//удаляем объект по первому адресу
        ++First;//сдвигаем указатель вправо
        --size;
    }
}
template<typename T>
void GreatDeque<T>::pop_behind()
{
    if (size) {
        vec_ptr[(--End).x][End.y].~T();//сдвигаем влево end, уничтожаем объект по крайнему адресу
        --size;
    }
}
template<typename T>
void GreatDeque<T>::clear()
{
    for (int i = 0; i < blocks; ++i) {
        for (int j = 0; j < k; ++j) {
            vec_ptr[i][j] = 0;
        }
    }
    First.set(blocks / 2, 0);
    End.set(blocks / 2, 0);
    size = 0;
}
template<typename T>
void GreatDeque<T>::resize_back()
{
    T** new_vec_ptr = new T * [blocks * 2];//увеличивает число блоков в два раза
        for (int i = 0; i < blocks; ++i) {//скопировали указатели на имеющиеся блоки
            new_vec_ptr[i] = vec_ptr[i];
        }
    for (int i = blocks; i < 2 * blocks; ++i) {
        new_vec_ptr[i] = new T [k];//выделяем память для новых справа
    }
    vec_ptr = new_vec_ptr;
    new_vec_ptr = nullptr;
    blocks *= 2;
    capacity *= 2;
  
}
template<typename T>
void GreatDeque<T>::resize_front()
{
     T** new_vec_ptr = new T * [blocks * 2];//увеличивает число блоков в два раза
        for (int i = 0; i < blocks; ++i) {//скопировали указатели на имеющиеся блоки
            new_vec_ptr[i] = new T[k];//выделяем память для новых слева
        }
        for (int i = blocks; i < 2 * blocks; ++i) {
            new_vec_ptr[i] = vec_ptr[i-blocks];
        }
        vec_ptr = new_vec_ptr;
        new_vec_ptr = nullptr;
        First.setx(First.x+blocks);
        End.setx(End.x + blocks);
        blocks *= 2;
        capacity *= 2;
}
template<typename T>
size_t GreatDeque<T>::count()
{
    return size;
}

template<typename T>
bool GreatDeque<T>::empty()
{
    return !size;
}
