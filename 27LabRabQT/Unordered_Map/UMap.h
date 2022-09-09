#ifndef UMAP_H
#define UMAP_H
#include"Forward_List.h"
#include<memory>
using namespace std;
template<typename T, typename U>
struct my_pair {
public:
    T key;
    U data;
    my_pair() {}
    my_pair(T first, U second) :key(first), data(second) {}
    void swap(my_pair<T, U>& other) {
        auto temp1 = std::move(this->key);
        auto temp2 = std::move(this->data);
        this->key = std::move(other.key);
        this->data = std::move(other.data);
        other.key = std::move(temp1);
        other.data = std::move(temp2);
    }
    void operator=(my_pair<T, U>& other) {
        this->key = std::move(other.key);
        this->data = std::move(other.data);
    }
    void operator=(my_pair<T, U>&& other) {
        this->key = std::move(other.key);
        this->data = std::move(other.data);
    }
};
template<typename T, typename U, typename Hasher>
class UMap {
    template<typename T, typename U>
    class Node {
    public:
        my_pair < T, U> block;
        size_t hashkey;
        Node(){}
        Node(T key) { this->block.key = key; }
        Node(T key, U data) {
            this->block = my_pair<T, U>(key, data);
        }
    };
public:
    size_t count = 0;
    size_t capacity = 8;
    Hasher hasher;
    my_list<Node<T, U>>* arr_list = new my_list<Node<T, U>>[capacity];
   // UMap(Hasher hasher):hasher(hasher) {}
    UMap(){}
    ~UMap() { delete[] arr_list; }
    my_list<Node<T, U>>& at(size_t index) {
            return arr_list[index];
        }
    void insert(T key, U data) {
        Node<T, U> node(key, data);
       // std::hash<T> hasher;
        node.hashkey = hasher(key) % capacity;
        size_t index = node.hashkey;
        arr_list[index].emplace(std::move(node));
        ++count;
        if (count / capacity > 2) { resize(); }
    }
    U& insert(T key) {
        Node<T, U> node(key);
      //  std::hash<T> hasher;
        node.hashkey = hasher(key) % capacity;
        size_t index = node.hashkey;
        arr_list[index].emplace(std::move(node));
        ++count;
        if (count / capacity > 2) { resize(); }
        return arr_list[index].top().block.data;
    }
    void insert_to_new_arr(my_pair<T, U>& block, my_list<Node<T, U>>* newarr, size_t newcapacity) {
        Node<T, U> node(block.key, block.data);
        //std::hash<T> hasher;
        node.hashkey = hasher(block.key) % (newcapacity);
        size_t index = node.hashkey;
        newarr[index].emplace(std::move(node));
    }
    void resize() {
        size_t newcapacity = capacity * 2;//новый размер
        my_list<Node<T, U>>* newarr_list = new my_list<Node<T, U>>[newcapacity];//создали новый массив
        for (size_t k = 0; k < capacity; ++k) {//пробегаем по всем строкам
            my_list<Node<T, U>>& cur_list = arr_list[k];//ссылка на текущий лист;
            if (!cur_list.empty()) {
                for (auto now = cur_list.begin(); now != cur_list.end(); ++now) {
                    insert_to_new_arr((*now).block, newarr_list, newcapacity);
                }
            }
        }
        delete[] arr_list;
        capacity = newcapacity;
        arr_list = newarr_list;
    }
     Node<T, U>* find(T key) {
     //   std::hash<T> hasher;
        size_t index = hasher(key) % (capacity);//нашли номер листа
        my_list<Node<T, U>>& cur_list = arr_list[index];
        if (cur_list.empty()) { return nullptr; }
        for (auto now = cur_list.begin(); now != cur_list.end(); ++now) {
            if ((*now).block.key == key) {
                return &(*now);
            }
        }
        return nullptr;
    }
    void eraze(T key) {//удаление
        //std::hash<T> hasher;
        size_t hashkey = hasher(key);
        size_t index = hashkey % capacity;//нашли индекс
        my_list<Node<T, U>>& cur_list = arr_list[index];
        for (auto now = cur_list.begin(); now != cur_list.end(); ++now) {
            if ((*now).block.key == key) {
                now.del();
            }
        }
    }
    size_t Count(T key) {
        if (find(key) == nullptr) {
            return 0;
        }
        else { return 1; }
    }
    bool contains(T key){
        return find(key) != nullptr;
    }
    size_t size() { return count; }
    size_t Capacity() { return capacity; }
   U& operator[](T key) {
       Node<T, U>* node= find(key);
       if (node == nullptr) {
           return insert(key);
       }
       else {
           return node->block.data;
       }
}
   void clear() {
       delete[] arr_list;
       count = 0;
       capacity = 0;
       arr_list = new my_list<Node<T,U>>[capacity];
   }
   template< typename... Args>
   void emplace(Args&&... args) {
       Node<T, U> node(std::forward<Args>(args)...);
      // std::hash<T> hasher;
       node.hashkey = hasher(node.block.key) % capacity;
       size_t index = node.hashkey;
       arr_list[index].emplace(std::move(node));
       ++count;
       if (count / capacity > 2) { resize(); }
       //return arr_list[index].top_node();
   }
};
#endif // UMAP_H
