#include <iostream>
#include"C:\Users\avdot\Desktop\LabWorks\26LabRab\List\List.cpp"
//#include"C:\Users\avdot\Desktop\LabWorks\LabRab3\3LabRabKluchinskiy\New_Stack\New_Stack.cpp"
using namespace std;
template<typename T,typename U>
class Node {
public:
    Node(T key, U data) {
        this->key = key;
        std::hash<T> hasher;
        hashkey = hasher(key);
        this->data = data;
    }
    Node(){}
    T key;
    size_t hashkey;
    U data;
    //unsigned long long int hashkey;
};
template<typename T, typename U>
class HashTable {
private:
    size_t capacity = 4;
    size_t rows = 0;
    my_list<Node<T, U>>* arr_list = new my_list<Node<T, U>>[capacity];
public:
    HashTable() {

    }
    ~HashTable() {
        delete[] arr_list;
    }
    void push_back(Node<T,U> obj) {
        if (rows + 1 > capacity) {
            capacity *= 2;
            my_list<Node<T, U>>* newarr_list = new my_list<Node<T, U>>[capacity];
            for (int i = 0; i < rows; ++i) {
                newarr_list[i] = arr_list[i];
            }
            delete[] arr_list;
            arr_list = newarr_list;
        }
        arr_list[rows].push(obj); ;
        ++rows;
    }
    void insert(T key,U data){
        Node<T,U> node(key,data);//создали узел
      
        //делаем проверку на совдадение
        for (int i = 0; i < rows; ++i) {//пробегаем по всем строкам

            if (arr_list[i].top().hashkey==node.hashkey) {//если нашли совпадение в начале lista по hashcode

                size_t k = 0;
                auto temp = arr_list[i].top_node();
                while (k < arr_list[i].size()) {
                    if (temp->core.key == node.key) {//если элемент уже есть, то делаем выход из функции
                        return ;
                    }
                    temp = temp->prev;
                    ++k;
                }
                arr_list[i].push(node);
                return;
            }
        }
        push_back(node);//нужно создать новый лист
    }
    Node<T,U>* find(size_t key) {
        std::hash<T> hasher;
        size_t hashkey = hasher(key);
        //делаем проверку на совдадение
        for (int i = 0; i < rows; ++i) {//пробегаем по всем строкам

            if (arr_list[i].top().hashkey == hashkey) {//если нашли совпадение в начале lista по hashcode

                size_t k = 0;
                auto temp = arr_list[i].top_node();
                while (k < arr_list[i].size()) {
                    if (temp->core.key == key) {
                        return &arr_list[i][k];
                    }
                    temp = temp->prev;
                    ++k;
                }
            }
        }
        return nullptr;
    }
    Node<T,U>* find_with_min_key() {
        auto node=arr_list[0].top_node();//нашли первый существ элемент Node<T> in list
        size_t k = 0;
        for (; k < rows; ++k) {
            if (arr_list[k].top_node() != nullptr) {
                node = arr_list[k].top_node();
                break;
            }
        }
        T min_key = node->core.key;//minimal key
        for (; k < rows; ++k) {//пробегаем по всем строкам
            auto temp = arr_list[k].top_node();
                size_t q = 0;
                while (q < arr_list[k].size()) {
                    if (temp->core.key < min_key) {
                        min_key = temp->core.key;
                        node = temp;
                    }
                    if (temp->prev == nullptr) { break; }
                    else {
                        temp = temp->prev;
                        ++q;
                    }
                }
        }
        return &node->core;
    }
    void show() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < arr_list[i].size(); ++j) {
                cout << arr_list[i][j].key << " " << arr_list[i][j].hashkey << " " << arr_list[i][j].data << "   ";
            }
            cout << '\n';
        }
    }
    void eraze(T key) {
        std::hash<T> hasher;
        size_t hashkey = hasher(key);
        //делаем проверку на совдадение
        for (int i = 0; i < rows; ++i) {//пробегаем по всем строкам

            if (arr_list[i].top().hashkey == hashkey) {//если нашли совпадение в начале lista по hashcode
                size_t k = 0;
                auto temp = arr_list[i].top_node();
                while (k < arr_list[i].size()) {
                    if (temp->core.key == key) {
                        arr_list[i].eraze(k);
                    }
                    temp = temp->prev;
                    ++k;
                }
       
                    
            }
        }
    }
};
int main()
{
    HashTable<int, string> table;
    table.insert(11, "Ivan");
   table.insert(22, "Oleg");
    table.insert(0, "Alice");
    table.insert(73, "Kate");
    table.insert(99, "Kate");
    table.eraze(11);

    cout << table.find_with_min_key()->key<< '\n';
    table.show();
    return 0;
}

