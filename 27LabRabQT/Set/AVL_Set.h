#ifndef AVL_SET_H
#define AVL_SET_H
#include <memory>
#include<QListWidget>
using namespace std;
template<typename T>
class avl_set {
private:
    template<typename T>
    class Node {
    public:
        Node() {}
        Node<T>* left = nullptr;
        Node<T>* right = nullptr;
        Node<T>* parent = nullptr;
        size_t height;
        T key;
        bool filled = false;
    };
    template<typename T>
    class Iterator {
        Node<T>* cur = nullptr;
        avl_set<T>* tree_ptr;
    public:
        Iterator(Node<T>* current, avl_set<T>* ptr) {
            this->cur = current;
            this->tree_ptr = ptr;
        }
        bool Empty() {
            return !(cur->filled);
        }
        Iterator operator++ ()
        {
            if (cur == nullptr)
            {
                cur = tree_ptr->find_min();
            }
            else
                if (cur->right != nullptr)
                {
                    // successor is the farthest left node of
                    // right subtree
                    cur = cur->right;

                    while (cur->left != nullptr) {//Минимальный элемент в правом поддереве
                        cur = cur->left;
                    }
                }
                else//Если мы уже в минимальном элементе
                {
                    Node<T>* p;
                    {
                        p = cur->parent;
                        while (p != nullptr && cur == p->right)//мы должны подниматься вверх, если мы пришли из правого потомка
                        {
                            cur = p;
                            p = p->parent;
                        }
                        cur = p;
                    }
                }
            return *this;
        }
        Iterator operator--() {
            if (cur == nullptr) {
                cur = tree_ptr->find_max();
            }
            else {
                if (cur->left != nullptr)
                {
                    cur = cur->left;
                    while (cur->right != nullptr) {//Максимальный элемент в левом поддереве
                        cur = cur->right;
                    }
                }
                else {
                    Node<T>* p;
                    p = cur->parent;
                    while (p != nullptr && cur == p->left)//мы должны подниматься вверх, если мы пришли из левого потомка
                    {
                        cur = p;
                        p = p->parent;
                    }
                    cur = p;
                }
            }
            return *this;
        }
        bool is_valid() { return cur != nullptr; }
        T& operator*() {
            if (cur != nullptr) { return cur->key; }
        }
        bool operator!=(const Iterator& other) { return this->cur != other.cur; }
    };
    Node<T>* Root = nullptr;
    size_t count = 0;
    size_t Gl_Count;
    static int Height(Node<T>*& kernel) {
        if (kernel == nullptr) { return -1; }
        else { return kernel->height; }
    }
    static int Max(int Lhs, int Rhs) {
        return Lhs > Rhs ? Lhs : Rhs;
    }
    Node<T>* Search(T key, Node<T>* kernel) {
        if (kernel == nullptr) {
            return nullptr;
        }
        if (key < kernel->key) { return Search(key, kernel->left); }
        else if (key > kernel->key) {
            return Search(key, kernel->right);
        }
        else {
            return kernel;
        }
    }
    Node<T>*& SearchMin(Node<T>* kernel) {
        if (kernel != nullptr) {
            if (kernel->left == nullptr) { return kernel; }
            else { return SearchMin(kernel->left); }
        }
    }
    Node<T>*& SearchMax(Node<T>* kernel) {
        if (kernel != nullptr) {
            if (kernel->right == nullptr) { return kernel; }
            else { return SearchMax(kernel->right); }
        }
    }
    Node<T>* SingleRotateLeft(Node<T>* kernel) {//with right
        Node<T>* newkernel = kernel->right;//b
        kernel->right = newkernel->left;
        //newkernel->left->parent = kernel;
        if (kernel->right != nullptr) {
            kernel->right->parent = kernel;
        }
        Node<T>* old_ker_parent = kernel->parent;
        kernel->parent = newkernel;
        newkernel->parent = old_ker_parent;
        newkernel->left = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->right), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T>* SingleRotateRight(Node<T>* kernel) {//with left
        Node<T>* newkernel = kernel->left;//b
        kernel->left = newkernel->right;
        if (kernel->left != nullptr) {
            kernel->left->parent = kernel;
        }
        Node<T>* old_ker_parent = kernel->parent;
        kernel->parent = newkernel;
        newkernel->parent = old_ker_parent;
        newkernel->right = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->left), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T>* DoubleRotateLeft(Node<T>* kernel) {//LR//With Right
        kernel->right = SingleRotateRight(kernel->right);
        return SingleRotateLeft(kernel);
    }
    Node<T>* DoubleRotateRight(Node<T>* kernel) {//Rl//With Left
        kernel->left = SingleRotateLeft(kernel->left);
        return SingleRotateRight(kernel);
    }
    Node<T>* insert1(T key, Node<T>*& kernel, Node<T>* father) {//возвращает поддерево с корнем в вершине applicant после вставки элемента
        if (kernel == nullptr) {
            kernel = new Node<T>();
            kernel->height = 0;
            kernel->left = nullptr;
            kernel->right = nullptr;
            kernel->parent = father;
            kernel->key = std::move(key);
            ++count;
        }
        else if (key < kernel->key) {//после вставки элемента с лева
            kernel->left = insert1(key, kernel->left, kernel);
            if (Height(kernel->left) - Height(kernel->right) == 2) {
                if (key < kernel->left->key) {
                    kernel = SingleRotateRight(kernel);
                }
                else {
                    kernel = DoubleRotateRight(kernel);
                }
            }
        }
        else if (key > kernel->key) {//right
            kernel->right = insert1(key, kernel->right, kernel);
            if (Height(kernel->right) - Height(kernel->left) == 2) {
                if (key > kernel->right->key) {
                    kernel = SingleRotateLeft(kernel);
                }
                else {
                    kernel = DoubleRotateLeft(kernel);
                }
            }
        }
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        return kernel;
    }

    Node<T>* subtree_after_eraze(T key, Node<T>*& kernel) {
        if (kernel == nullptr) {
            return nullptr;
        }
        if (key == kernel->key) {//3 examples
            if (kernel->left == nullptr && kernel->right == nullptr) {
                delete kernel;
                --count;
                kernel = nullptr;
                return kernel;
            }
            else if (kernel->left == nullptr) {
                Node<T>* temp = kernel->right;
                temp->parent = kernel->parent;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else if (kernel->right == nullptr) {
                Node<T>* temp = kernel->left;
                temp->parent = kernel->parent;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else {
                Node<T>* min_from_right_subtree = SearchMin(kernel->right);
                kernel->key = std::move(min_from_right_subtree->key);
                subtree_after_eraze(min_from_right_subtree->key, kernel->right);
                return kernel;
            }

        }
        else if (key < kernel->key) {//идём удалять влево
            kernel->left = subtree_after_eraze(key, kernel->left);//после того как мы изменили левое поддерево этой вершины необходимо пересчитать высоту этой вершины
            kernel->height = Max(Height(kernel->left) - 1, Height(kernel->right)) + 1;
            if (Height(kernel->right) - Height(kernel->left) >= 2) {
                Node<T>* B = kernel->right;
                if (B->left != nullptr && B->right != nullptr) {
                    int deltaB = B->left->height - B->right->height;
                    if ((deltaB == 0) || (deltaB == -1)) {
                        kernel = SingleRotateLeft(kernel);
                    }
                    else {// else if (deltaB == 1)
                        kernel = SingleRotateLeft(kernel);
                    }
                }
            }
        }
        else if (key > kernel->key) {//идём удалять вправо
            kernel->right = subtree_after_eraze(key, kernel->right);
            kernel->height = Max(Height(kernel->left), Height(kernel->right) - 1) + 1;
            if (Height(kernel->left) - Height(kernel->right) >= 2) {
                Node<T>* B = kernel->left;
                if (B->left != nullptr && B->right != nullptr) {
                    int deltaB = B->left->height - B->right->height;
                    if (deltaB == 0 || deltaB == 1) {
                        kernel = SingleRotateRight(kernel);
                    }
                    else {//if (deltaB == -1) {
                        kernel = DoubleRotateRight(kernel);//тянем вправо
                    }
                }
            }
        }
        return kernel;
    }
    void preOrder(Node<T>* root,QListWidget* ptr) {
        if (root) {
           // qDebug()<<root->key<<" - " << root->data <<'\n';
            ptr->addItem(QString::number(root->key));
            preOrder(root->left,ptr);
            preOrder(root->right,ptr);
        }
    }

    void inOrder(Node<T>* root,QListWidget* ptr) {
        if (root) {
            inOrder(root->left,ptr);
            //qDebug() << root->key << " - " << root->data << '\n';
            ptr->addItem(QString::number(root->key));
            inOrder(root->right,ptr);
        }
    }

    void postOrder(Node<T>* root,QListWidget* ptr) {
        if (root) {
            postOrder(root->left,ptr);
            postOrder(root->right,ptr);
           // qDebug() << root->key << " - " << root->data << '\n';
            ptr->addItem(QString::number(root->key));
        }
    }
    void tree_traversal(size_t length, Node<T>*& ptr) {
        if (ptr == nullptr) {
            if (length > Gl_Count) {
                Gl_Count = length;
            }
        }
        else {
            tree_traversal(length + 1, ptr->left);
            tree_traversal(length + 1, ptr->right);
        }
    }
public:
    Node<T>* get_root() { return Root; }
    avl_set() {}
    void destroy(Node<T>* father) {
        if (father != nullptr) {
            destroy(father->left);
            destroy(father->right);
            delete father;
        }
    }
    void clear() {
        destroy(Root);
        Root = nullptr;
        count = 0;
    }
    Node<T>* find(T key) {
        return Search(key, Root);
    }
    Iterator<T> ItFind(T key) {
        Iterator<T> ItFind(find_min(), this);
        if (*ItFind > key) {
            return ItFind;
        }
        while ((*ItFind) != key) {
            ++ItFind;
        }
        return ItFind;
    }
    Node<T>* find_min_rec() { return SearchMin(Root); }
    Node<T>* find_max_rec() { return SearchMax(Root); }
    Node<T>* find_max() {
        Node<T>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->right != nullptr) {
                kernel = kernel->right;
            }
            return kernel;
        }
    }
    Node<T>* find_min() {
        Node<T>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->left != nullptr) {
                kernel = kernel->left;
            }
            return kernel;
        }
    }
    size_t size() { return count; }
    ~avl_set() {
        destroy(Root);
    }
    void insert(T key) {
        insert1(key, Root, nullptr);
    }
    void emplace(T&& key) {
        insert1(key, Root, nullptr);
    }
    void eraze(T key) {
        subtree_after_eraze(key, Root);
    }
    void pre_travel(QListWidget* ptr) {
        preOrder(Root,ptr);
    }
    void in_travel(QListWidget* ptr) {
        inOrder(Root,ptr);
    }
    void post_travel(QListWidget* ptr) {
        postOrder(Root,ptr);
    }
    bool empty() { return !count; }
    void swap(avl_set& other) {
        Node<T>* root1 = std::move(this->Root);
        size_t count1 = std::move(this->count);
        this->Root = std::move(other.Root);
        this->count = std::move(other.count);
        other.Root = std::move(root1);
        other.count = std::move(count1);
    }
    size_t the_longest_way() {
        Gl_Count = 0;
        tree_traversal(0, Root);
        return Gl_Count;
    }
    // U& operator[]=
    size_t Count(T key) {
        Node<T>* node = find(key);
        if (node == nullptr) {
            return 0;
        }
        else {
            return 1;
        }
    }
    Iterator<T> lower_bound(T key){// ищем элемент с нижней границей key
       Iterator<T> ItFind(find_min(), this);
       while (ItFind.is_valid()&&*ItFind < key) {
           ++ItFind;
       }
       if(ItFind.is_valid())
       {
       return ItFind;
       }else{
           return --ItFind;
       }
    }
    Iterator<T> upper_bound(T key) {// ищем элемент с верхней границей key
        Iterator<T> ItFind(find_max(), this);
        while (ItFind.is_valid() && *ItFind >= key) {
            --ItFind;
        }
        if(ItFind.is_valid())
        {
        return ItFind;
        }else{
            return ++ItFind;
        }
    }
    Iterator<T> begin() { return Iterator<T>(find_min(), this); }
    Iterator<T> end() { return Iterator<T>(nullptr, this); }
    Iterator<T> rbegin() { return Iterator<T>(find_max(), this); }
    Iterator<T>rend() { return Iterator<T>(nullptr, this); }
};
#endif // AVL_SET_H
