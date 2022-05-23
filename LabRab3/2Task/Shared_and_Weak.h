#ifndef SHARED_AND_WEAK_H
#define SHARED_AND_WEAK_H
#include <iostream>
#include <QDebug>
using namespace std;
template <typename T>
std::remove_reference_t<T>&& Move(T&& x) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(x);
}

template<typename U>
struct ControlBlock {
    size_t counter;
    size_t weak_counter;
    U object;
};
template <typename T>
class my_weak_ptr;
template<class T>
class shar_ptr {
    template <typename T> friend class my_weak_ptr;
public:
    shar_ptr() {
    }
    shar_ptr(T* ptr) {
        if (ptr != nullptr) {
            this->cptr = new ControlBlock<T>{ 1,0,*ptr };
            delete ptr;
        }
    }
    shar_ptr(const shar_ptr<T>& other) {
       // cout << "lvalue constr for shar\n";
        if ((other.cptr != nullptr) && (&other != this)) {
            this->cptr = other.cptr;
            ++(cptr->counter);
        }
    }
    shar_ptr(const my_weak_ptr<T>& other) {
        this->cptr = other.cptr;
        ++(cptr->counter);
    }
    shar_ptr(shar_ptr<T>&& other) {
       // cout << "rvalue constr for shar\n";
        this->cptr = Move(other.cptr);
        other.cptr = nullptr;
    }
    ~shar_ptr() {
        if (this->cptr != nullptr) {
            --(cptr->counter);

            if (cptr->counter > 0) {
                return;
            }

            if (cptr->weak_counter == 0) {
                delete cptr;
              //  cout << "Shar Destructor was called\n";
                return;
            }

            //cptr->object.~T();
            delete cptr;
           // cout << "Shar_obj deleted\n";
        }
    }
    void new_own(const shar_ptr<T>& other) {
        if (this->cptr != nullptr) {
            --(cptr->counter);
            if (cptr->counter == 0) {
                this->~shar_ptr();
            }
        }
        if ((other.cptr != nullptr) && (&other != this)) {
            this->cptr = other.cptr;
            ++(cptr->counter);
        }
    }
       void del_with_change(shar_ptr<T>&other) {//отнять объект у указателя
            auto temp = Move(this->cptr);
            this->cptr = Move(other.cptr);
            other.cptr = nullptr;
            delete temp;
        }

    void del() {
        this->~shar_ptr();
    }
    void swap(shar_ptr<T>& other) {
        auto tempptr = Move(this->cptr);
        this->cptr = Move(other.cptr);
        other.cptr = Move(tempptr);
    }
    bool unique() {
        return (cptr->counter == 1);
    }
    shar_ptr<T>& operator=(const shar_ptr<T>& other) {
        if ((this == &other) || (other.cptr == nullptr)) {
            return *this;
        }
        this->cptr = other.cptr;
        ++(cptr->counter);
        return *this;

    }
    shar_ptr<T>& operator=(shar_ptr<T>&& other) {
       // cout << "rvalue = for shar\n";
        this->cptr = Move(other.cptr);
        other.cptr = nullptr;
        return *this;
    }
    T& operator*() const {
        return cptr->object;
    }
    T* operator->() const {
        return &(cptr->object);
    }
    T& operator[](int num) {
        T* ptr = &(cptr->object);
        return *(ptr + num);
    }
    T& get() {
        return &(cptr->object);
    }
    size_t use_count() {
        return cptr->counter;
    }
    size_t use_weak_count() {
        return cptr->weak_counter;
    }
    void decr() {
        --(cptr->counter);
    }
private:
    ControlBlock<T>* cptr = nullptr;

    template <typename U, typename... Args>
    friend shar_ptr<U> make_shar(Args&&... args);
    shar_ptr(ControlBlock<T>* storage_ptr) :
        cptr(storage_ptr) {}
};

template <typename T, typename... Args>
shar_ptr<T> make_shar(Args&&... args) {
    auto cptr = new ControlBlock<T>{ 1,0, T{ std::forward<Args>(args)... } };
    return shar_ptr<T>(cptr);
}



template <typename T>
class my_weak_ptr {
    template <typename T> friend class shar_ptr;
public:

    my_weak_ptr() { cptr = nullptr; }
    my_weak_ptr(const my_weak_ptr<T>& other) :cptr(other.cptr) {
        if (cptr != nullptr) {
            ++(cptr->weak_counter);
        }
    }
    my_weak_ptr( my_weak_ptr<T>&& other) :cptr(other.cptr) {
        if (cptr != nullptr) {
            ++(cptr->weak_counter);
        }
    }
    my_weak_ptr(const shar_ptr<T>& other) :cptr(other.cptr) {
        ++(cptr->weak_counter);
    }
    my_weak_ptr<T>& operator=(my_weak_ptr<T>&& other) {
       // cout << "rvalue = for weak\n";
            this->cptr = other.cptr;
            other.cptr = nullptr;
            return *this;
    }
    bool expired() const {
        return (cptr->counter == 0);
    }

    ~my_weak_ptr() {
        if (cptr != nullptr) {
            --(cptr->weak_counter);
           // cout << "weak decreased\n";
            if (cptr->counter == 0 && cptr->weak_counter == 0) {
               qDebug()<<"clear\n";
                //delete cptr;

            }
        }
    }
    shar_ptr<T> lock() const {

        if (!expired()) {
          return (shar_ptr<T>(*this));
        }
        else {
            return shar_ptr<T>();
        }
    }
    size_t use_weak_count() {
        return cptr->weak_counter;
    }
    void swap(my_weak_ptr<T>& other) {
        auto tempptr = Move(this->cptr);
        this->cptr = Move(other.cptr);
        other.cptr = Move(tempptr);
    }
public:
    ControlBlock<T>* cptr = nullptr;
};
#endif // SHARED_AND_WEAK_H
