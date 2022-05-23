// Unique_ptr.cpp : Defines the functions for the static library.
//
#include <iostream>
#include "pch.h"
#include "framework.h"
using namespace std;
// TODO: This is an example of a library function
template <typename T>
std::remove_reference_t<T>&& Move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}
template<typename T>
class my_unique_ptr {
public:
    my_unique_ptr() { ptr = nullptr; }
    my_unique_ptr(T* ptr) :ptr(ptr) {
        cout << "unique_ptr_constr\n";
    }
    my_unique_ptr(my_unique_ptr<T>& other) {
        this->ptr = Move(other.ptr);
        other.ptr = nullptr;
    }
    my_unique_ptr(my_unique_ptr<T>&& other) {
        this->ptr = Move(other.ptr);
        other.ptr = nullptr;
    }


    void del_with_change(my_unique_ptr<T>& other) {//перемещение с удалением
        T* temp = this->ptr;
        this->ptr = Move(other.ptr);
        other.ptr = nullptr;
        delete temp;
    }
    my_unique_ptr<T>& operator=(my_unique_ptr<T>& other) {

        this->ptr = Move(other.ptr);
        other.ptr = nullptr;
        return *this;
    }
    my_unique_ptr<T>& operator=(my_unique_ptr<T>&& other) {

        this->ptr = Move(other.ptr);
        other.ptr = nullptr;
        return *this;
    }

    ~my_unique_ptr() {
        delete ptr;
    }
    void make_null() {
        ptr = nullptr;
    }
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }
private:
    T* ptr;
};
