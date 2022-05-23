#ifndef MY_VEC_H
#define MY_VEC_H
typedef  unsigned int sizet;
template<typename T>
class my_vec {
    sizet v_size=0;
    sizet capacity=2;
    T* arr=nullptr;
public:
    class Iterator;
    class Rev_Iterator;
    Iterator begin() { return arr; }
    Iterator end() { return arr + v_size;}
    Rev_Iterator rbegin() { return arr + v_size-1; }
    Rev_Iterator rend() { return arr-1; }
    my_vec() {
        arr = new T[capacity];
    }
    my_vec(sizet n) {
        if (n) {
            v_size = n;
            capacity = n;
        }
        arr = new T[capacity];
    }
    ~my_vec() {
        delete[] arr;
    }
    class Iterator {
        T* cur;
    public:
        Iterator (T* first):cur(first){}
        T& operator+ (int n) { return *(cur + n); }
        T& operator- (int n) { return *(cur - n); }

        T& operator++(int) { return *cur++; }
        T& operator--(int) { return *cur--; }
        T& operator++() { return *++cur; }
        T& operator--() { return *--cur; }

        bool operator!=(const Iterator& it){return cur != it.cur;}
        bool operator==(const Iterator& it) { return cur == it.cur; }
        T& operator* () { return *cur; }
    };
    class Rev_Iterator {
        T* cur;
    public:
        Rev_Iterator(T* first):cur(first){}
        T& operator+ (int n) { return *(cur - n); }
        T& operator- (int n) { return *(cur + n); }

        T& operator++(int) { return *cur--; }
        T& operator--(int) { return *cur++; }
        T& operator++() { return *--cur; }
        T& operator--() { return *++cur; }

        bool operator!=(const Rev_Iterator& it) { return cur != it.cur; }
        bool operator==(const Rev_Iterator& it) { return cur == it.cur; }
        T& operator* () { return *cur; }
    };
    void assign(sizet first, sizet last) {
        if ((last >= v_size - 1) || (first >= v_size - 1)) { return; }
        sizet count = last - first;
        T* newarr = new T[count];
        for (int i = 0; i < count; ++i) {
            newarr[i] = arr[first + i];
        }
        delete arr;
        arr = newarr;
        v_size = count;
        capacity = count;
    }
    T& at(sizet num) {
        if (num >= v_size) { return arr[v_size - 1]; }
        return arr[num];
    }
    T*& data(){
        return arr;
    }
    void emplace(sizet pos, T&& obj) {
        if (pos >= v_size) {
            return push_back(obj);
        }
        else {
            if (v_size + 1 >= capacity) {
                capacity *= 2;
            }
            T* newarr = new T[capacity];
            int i = 0;
            for (; i < pos; ++i) {
                newarr[i] = arr[i];
            }
            newarr[pos] = obj;
            for (; i < v_size; ++i) {
                newarr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            ++v_size;
        }
    }
    void emplace_back(T&& obj) {
        if (v_size >= capacity) {
            capacity *= 2;
            T* newarr = new T[capacity];
            for (int i = 0; i < v_size; i++) {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
        }
        arr[v_size] = obj;
        ++v_size;
    }
    bool empty() {
        return (!v_size);
    }
    void erase(sizet start, sizet end) {
        if ((start >= v_size - 1) || (end >= v_size - 1)) {
            return pop_back();
        }
        sizet count = end - start + 1;
        T* newarr = new T[capacity];
        int i = 0;
        for (; i < start; ++i) {
            newarr[i] = arr[i];
        }
        for (; i < v_size; ++i) {
            newarr[i] = arr[i + count];
        }
        delete[] arr;
        arr = newarr;
        v_size -= count;
    }
    void erase(sizet pos) {
        if (pos>=v_size-1) {
            return pop_back();
        }
        else {
            T* newarr = new T[capacity];
            int i = 0;
            for (; i < pos; ++i) {
                newarr[i] = arr[i];
            }
            ++i;
            for (; i < v_size; ++i) {
                newarr[i-1] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            --v_size;
        }
    }
    T& front() {
        return arr[0];
    }
    void insert(sizet pos, T obj) {
        if (pos >= v_size){
         return push_back(obj);
        }
        else {
            if (v_size + 1 >= capacity) {
                capacity *= 2;
            }
            T* newarr = new T[capacity];
            int i = 0;
            for (; i < pos; ++i) {
                newarr[i] =arr[i];
            }
            newarr[pos] = obj;
            for (; i < v_size; ++i) {
                newarr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            ++v_size;
        }
    }
    sizet max_size() {
        return capacity;
    }
    void pop_back() {
        arr[v_size - 1].~T();
        --v_size;
    }
    void push_back(T obj)
    {
        if (v_size+1 >= capacity) {
            capacity *= 2;
            T* newarr = new T[capacity];
            for (int i = 0; i < v_size; i++) {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
        }
        arr[v_size] = obj;
        ++v_size;
    }
    void clear() {
        delete[] arr;
        capacity = 2;
        v_size = 0;
        arr = new T[2];
    }
    void clear2() {
        for (int i = 0; i < v_size; ++i) {
            arr[i].~my_vec();
        }
        //delete[] arr;
        capacity = 2;
        v_size = 0;
        arr = new T[2];
    }
    void reserve(sizet new_size) {
        if (new_size <= capacity) {
            return;
        }
        T* newarr = new T[new_size];
        for (int i = 0; i < v_size; ++i) {
            newarr[i] = arr[i];
        }
        capacity = new_size;
        delete[] arr;
        arr = newarr;
    }
    void resize(sizet new_size) {

        if (new_size>capacity) {
            T* newarr = new T[new_size];
            for (int i = 0; i < v_size; ++i) {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            capacity = new_size;
        }
        v_size = new_size;
    }
    sizet size() {
        return v_size;
    }
    void swap(my_vec<T>& other) {
        auto temp = move(this->arr);
        this->arr = move(other.arr);
        other.arr = move(temp);
    }
    T& operator[](sizet ind) {
        return arr[ind];
    }
    void operator=(my_vec<T>& other) {
        delete arr;
        this->v_size = other.v_size;
        this->capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < v_size; ++i) {
            arr[i] = other.arr[i];
        }
    }
};

#endif // MY_VEC_H
