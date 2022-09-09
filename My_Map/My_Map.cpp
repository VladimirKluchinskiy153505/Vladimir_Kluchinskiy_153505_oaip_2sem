#include <iostream>
using namespace std;
template<typename T, typename U>
struct my_pair {
public:
    T first;
    U second;
    my_pair() {}
    my_pair(T first, U second) :first(first), second(second) {}
    void swap(my_pair<T, U>& other) {
        auto temp1 = std::move(this->first);
        auto temp2 = std::move(this->second);
        this->first = std::move(other.first);
        this->second = std::move(other.second);
        other.first = std::move(temp1);
        other.second = std::move(temp2);
    }
    void operator=(const my_pair<T, U>& other) {
        this->first = std::move(other.first);
        this->second = std::move(other.second);
    }
};
template<typename T, typename U>
class avl_map {
private:
    template<typename T, typename U>
    class Node {
    public:
        Node() {}
        Node<T, U>* left = nullptr;
        Node<T, U>* right = nullptr;
        Node<T, U>* parent = nullptr;
        size_t height;
        T key;
        U data;
        my_pair<const T, U> block;
    };
    Node<T, U>* Root = nullptr;
    size_t count = 0;
    size_t Gl_Count;
    static int Height(Node<T, U>*& kernel) {
        if (kernel == nullptr) { return -1; }
        else { return kernel->height; }
    }
    static int Max(int Lhs, int Rhs) {
        return Lhs > Rhs ? Lhs : Rhs;
    }
    Node<T, U>* Search(T key, Node<T, U>* kernel) {
        if (kernel == nullptr) {
            return Root;
        }
        if (key < kernel->key) { return Search(key, kernel->left); }
        else if (key > kernel->key) {
            return Search(key, kernel->right);
        }
        else {
            return kernel;
        }
    }
    Node<T, U>*& SearchMin(Node<T, U>* kernel) {
        if (kernel != nullptr) {
            if (kernel->left == nullptr) { return kernel; }
            else { return SearchMin(kernel->left); }
        }
    }
    Node<T, U>*& SearchMax(Node<T, U>* kernel) {
        if (kernel != nullptr) {
            if (kernel->right == nullptr) { return kernel; }
            else { return SearchMax(kernel->right); }
        }
    }
    Node<T, U>* SingleRotateLeft(Node<T, U>* kernel) {//with right
        Node<T, U>* newkernel = kernel->right;//b
        kernel->right = newkernel->left;
        //newkernel->left->parent = kernel;
        if (kernel->right != nullptr) {
            kernel->right->parent = kernel;
        }
        Node<T, U>* old_ker_parent = kernel->parent;
        kernel->parent = newkernel;
        newkernel->parent = old_ker_parent;
        newkernel->left = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->right), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T, U>* SingleRotateRight(Node<T, U>* kernel) {//with left
        Node<T, U>* newkernel = kernel->left;//b
        kernel->left = newkernel->right;
        if (kernel->left != nullptr) {
            kernel->left->parent = kernel;
        }
        Node<T, U>* old_ker_parent = kernel->parent;
        kernel->parent = newkernel;
        newkernel->parent = old_ker_parent;
        newkernel->right = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->left), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T, U>* DoubleRotateLeft(Node<T, U>* kernel) {//LR//With Right
        kernel->right = SingleRotateRight(kernel->right);
        return SingleRotateLeft(kernel);
    }
    Node<T, U>* DoubleRotateRight(Node<T, U>* kernel) {//Rl//With Left
        kernel->left = SingleRotateLeft(kernel->left);
        return SingleRotateRight(kernel);
    }
    Node<T, U>* insert(T key, U data, Node<T, U>*& kernel,Node<T,U>* father) {//возвращает поддерево с корнем в вершине applicant после вставки элемента
        if (kernel == nullptr) {
            kernel = new Node<T, U>();
            kernel->height = 0;
            kernel->left = nullptr;
            kernel->right = nullptr;
            kernel->parent = father;
            kernel->key = std::move(key);
            kernel->data = std::move(data);
            ++count;
        }
        else if (key < kernel->key) {//после вставки элемента с лева
            kernel->left = insert(key, data, kernel->left,kernel);
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
            kernel->right = insert(key, data, kernel->right,kernel);
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
        //  kernel->height = Height(kernel->left), Height(kernel->right);
        return kernel;
    }
    Node<T, U>* subtree_after_eraze(T key, Node<T, U>*& kernel) {
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
                Node<T, U>* temp = kernel->right;
                temp->parent = kernel->parent;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else if (kernel->right == nullptr) {
                Node<T, U>* temp = kernel->left;
                temp->parent = kernel->parent;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else {
                Node<T, U>* min_from_right_subtree = SearchMin(kernel->right);
                kernel->data = min_from_right_subtree->data;
                kernel->key = min_from_right_subtree->key;
                subtree_after_eraze(min_from_right_subtree->key, kernel->right);
                return kernel;
            }
        }
        else if (key < kernel->key) {//идём удалять влево
            kernel->left = subtree_after_eraze(key, kernel->left);//после того как мы изменили левое поддерево этой вершины необходимо пересчитать высоту этой вершины
            kernel->height = Max(Height(kernel->left) - 1, Height(kernel->right)) + 1;
            if (Height(kernel->right) - Height(kernel->left) >= 2) {
                Node<T, U>* B = kernel->right;
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
                Node<T, U>* B = kernel->left;
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
    void preOrder(Node<T, U>* root) {
        if (root) {
            cout << root->key << " - " << root->data << '\n';
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node<T, U>* root) {
        if (root) {
            inOrder(root->left);
            cout << root->key << " - " << root->data << '\n';
            inOrder(root->right);
        }
    }

    void postOrder(Node<T, U>* root) {
        if (root) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->key << " - " << root->data << " parent: ";
            if (root->parent != nullptr) { cout<<root->parent->key; };
            cout << '\n';
        }
    }
    void tree_traversal(size_t length, Node<T, U>*& ptr) {
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
    Node<T, U>* get_root() { return Root; }
    avl_map() {}
    void destroy(Node<T, U>* father) {
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
    Node<T, U>* find(T key) {
        return Search(key, Root);
    }
    Node<T, U>* find_min_rec() { return SearchMin(Root); }
    Node<T, U>* find_max_rec() { return SearchMax(Root); }
    Node<T, U>* find_max() {
        Node<T, U>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->right != nullptr) {
                kernel = kernel->right;
            }
            return kernel;
        }
    }
    Node<T, U>* find_min() {
        Node<T, U>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->left != nullptr) {
                kernel = kernel->left;
            }
            return kernel;
        }
    }
    size_t size() { return count; }
    ~avl_map() {
        destroy(Root);
    }
    void insert(T key, U data) {
        insert(key, data, Root,nullptr);
    }
    void eraze(T key) {
        subtree_after_eraze(key, Root);
    }
    void pre_travel() {
        preOrder(Root);
    }
    void in_travel() {
        inOrder(Root);
    }
    void post_travel() {
        postOrder(Root);
    }
    size_t the_longest_way() {
        Gl_Count = 0;
        tree_traversal(0, Root);
        return Gl_Count;
    }
    template<typename T, typename U>
    class Iterator {
        Node<T, U>* cur=nullptr;
        avl_map<T, U>* tree_ptr;
    public:
        Iterator(Node<T,U>* current,avl_map<T,U>* ptr) {
            this->cur = current;
            this->tree_ptr = ptr;
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
             Node<T, U>* p;
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
                    // successor is the farthest left node of
                    // right subtree
                    cur = cur->left;

                    while (cur->right != nullptr) {//Максимальный элемент в левом поддереве
                        cur = cur->right;
                    }
                }
            else {
                    Node<T, U>* p;
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
        T& operator*(){return cur->key; }
        bool operator!=(const Iterator& other) { return this->cur != other.cur; }
    };
    Iterator<T, U> begin() { return Iterator<T, U>(find_min(),this); }
    Iterator<T, U> end() { return Iterator<T, U>(nullptr, this); }
    Iterator<T, U> rbegin() { return Iterator<T, U>(find_max(), this); }
    Iterator<T, U>rend() { return Iterator<T, U>(nullptr, this); }
};
int main()
{
    avl_map<int, int> tree;
       for (int i = 1; i <= 200; ++i) {
       tree.insert(i, i + 1000);
   }
       tree.post_travel();
    for (int i = 1; i <= 180; ++i) {
        tree.eraze(i);
    }

  /*  for (int i = 1; i <= 4; ++i) {
        tree.eraze(i);
        cout << '\n'; tree.post_travel();
    }*/
   // tree.post_travel();
    cout << "\nroot: " << tree.get_root()->key << '\n';
    for (auto now = tree.begin(); now != tree.end();++now) {
        cout << *now << " ";
    }
    cout << '\n';
    for (auto now = tree.rbegin(); now != tree.rend(); --now) {
        cout << *now << " ";
    }
    return 0;
}
