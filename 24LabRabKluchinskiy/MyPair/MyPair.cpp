// MyPair.cpp : Defines the functions for the static library.
//
#include<iostream>
#include "pch.h"
#include "framework.h"

//template <typename T>
//std::remove_reference_t<T>&& Move(T&& x) noexcept {
//    return static_cast<std::remove_reference_t<T>&&>(x);
//}

template<typename T, typename U>
struct my_pair {
public:
    T first;
    U second;
    my_pair(){}
    my_pair(T first, U second) :first(first), second(second) {}
    void swap(my_pair<T, U>& other) {
        auto temp1 = Move(this->first);
        auto temp2 = Move(this->second);
        this->first = Move(other.first);
        this->second = Move(other.second);
        other.first = Move(temp1);
        other.second = Move(temp2);
    }
    void operator=(const my_pair<T, U>& other) {
        this->first = Move(other.first);
        this->second = Move(other.second);
    }
};