#ifndef AVL_TREE_H
#define AVL_TREE_H
#include<memory>
#include<QDebug>
#include<QListWidget>
template<typename T,typename U>
class AVL_Tree {
private:
    template<typename T, typename U>
    class Node {
    public:
        Node() {}
        Node<T, U>* left = nullptr;
        Node<T, U>* right = nullptr;
        size_t height;
        T key;
        U data;
    };
    Node<T,U>* Root=nullptr;
    size_t count = 0;
    size_t Gl_Count;
    static int Height(Node<T,U>*& kernel) {
        if (kernel == nullptr) { return -1; }
        else { return kernel->height; }
    }
    static int Max(int Lhs, int Rhs) {
        return Lhs > Rhs ? Lhs : Rhs;
    }
    Node<T,U>* Search(T key, Node<T, U>* kernel) {
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
    Node<T,U>*& SearchMin(Node<T,U>* kernel) {
        if (kernel != nullptr) {
            if (kernel->left == nullptr) { return kernel; }
            else { return SearchMin(kernel->left); }
        }
    }
    Node<T,U>*& SearchMax(Node<T,U>* kernel) {
        if (kernel != nullptr) {
            if (kernel->right == nullptr) { return kernel; }
            else { return SearchMax(kernel->right); }
        }
    }
    Node<T,U>* SingleRotateLeft(Node<T,U>* kernel) {//with right
        Node<T,U>* newkernel = kernel->right;
        kernel->right = newkernel->left;
        newkernel->left = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->right), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T,U>* SingleRotateRight(Node<T,U>* kernel) {//with left
        Node<T,U>* newkernel = kernel->left;
        kernel->left = newkernel->right;
        newkernel->right = kernel;
        kernel->height = Max(Height(kernel->left), Height(kernel->right)) + 1;
        newkernel->height = Max(Height(newkernel->left), Height(kernel)) + 1;
        return newkernel;
    }
    Node<T,U>* DoubleRotateLeft(Node<T,U>* kernel) {//LR//With Right
        kernel->right = SingleRotateRight(kernel->right);
        return SingleRotateLeft(kernel);
    }
    Node<T,U>* DoubleRotateRight(Node<T,U>* kernel) {//Rl//With Left
        kernel->left = SingleRotateLeft(kernel->left);
        return SingleRotateRight(kernel);
    }
    Node<T,U>* insert(T key,U data, Node<T,U>*& kernel) {//возвращает поддерево с корнем в вершине applicant после вставки элемента
        if (kernel == nullptr) {
            kernel = new Node<T,U>();
            kernel->height = 0;
            kernel->left = nullptr;
            kernel->right = nullptr;
            kernel->key = std::move(key);
            kernel->data = std::move(data);
        }
        else if (key < kernel->key) {//после вставки элемента с лева
            kernel->left = insert(key,data, kernel->left);
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
            kernel->right = insert(key,data, kernel->right);
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
    Node<T,U>* subtree_after_eraze(T key, Node<T,U>*& kernel) {
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
                Node<T,U>* temp = kernel->right;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else if (kernel->right == nullptr) {
                Node<T,U>* temp = kernel->left;
                delete kernel;
                --count;
                kernel = temp;
                return kernel;
            }
            else {
                T min_val_from_right_subtree = SearchMin(kernel->right)->key;
                kernel->key = min_val_from_right_subtree;
                subtree_after_eraze(min_val_from_right_subtree, kernel->right);
                return kernel;
            }
        }
        else if (key < kernel->key) {//идём удалять влево
            kernel->left = subtree_after_eraze(key, kernel->left);//после того как мы изменили левое поддерево этой вершины необходимо пересчитать высоту этой вершины
            kernel->height = Max(Height(kernel->left) - 1, Height(kernel->right)) + 1;
            if (Height(kernel->right) - Height(kernel->left) >= 2) {
                //if (kernel->right != nullptr && kernel->right->left != nullptr) {
                //    kernel = DoubleRotateLeft(kernel);//тянем влево
                //}
                //else {
                //    kernel = SingleRotateLeft(kernel);
                //}
                kernel = SingleRotateLeft(kernel);
            }
        }
        else if (key > kernel->key) {//идём удалять вправо
            kernel->right = subtree_after_eraze(key, kernel->right);
            kernel->height = Max(Height(kernel->left), Height(kernel->right) - 1) + 1;
            if (Height(kernel->left) - Height(kernel->right) >= 2) {
                //if (kernel->left != nullptr && kernel->left->right != nullptr) {
                //    kernel = DoubleRotateRight(kernel);//тянем вправо
                //}
                //else {
                //    kernel = SingleRotateRight(kernel);
                //}
                kernel = SingleRotateRight(kernel);
            }
        }
        return kernel;
    }
    void preOrder(Node<T,U>* root,QListWidget* ptr) {
        if (root) {
           // qDebug()<<root->key<<" - " << root->data <<'\n';
            ptr->addItem(QString::number(root->key)+" "+QString(root->data));
            preOrder(root->left,ptr);
            preOrder(root->right,ptr);
        }
    }

    void inOrder(Node<T,U>* root,QListWidget* ptr) {
        if (root) {
            inOrder(root->left,ptr);
            //qDebug() << root->key << " - " << root->data << '\n';
            ptr->addItem(QString::number(root->key)+" "+QString(root->data));
            inOrder(root->right,ptr);
        }
    }

    void postOrder(Node<T,U>* root,QListWidget* ptr) {
        if (root) {
            postOrder(root->left,ptr);
            postOrder(root->right,ptr);
           // qDebug() << root->key << " - " << root->data << '\n';
            ptr->addItem(QString::number(root->key)+" "+QString(root->data));
        }
    }
    void tree_traversal(size_t length, Node<T,U>*& ptr) {
          if (ptr == nullptr) {
              if (length > Gl_Count) {
                  Gl_Count = length;
              }
          }
          else {
              tree_traversal(length+1,ptr->left);
              tree_traversal(length + 1, ptr->right);
          }
      }
public:
   Node<T,U>* get_root() { return Root; }
    AVL_Tree() {}
    void destroy(Node<T,U>* father) {
        if (father != nullptr) {
            destroy(father->left);
            destroy(father->right);
            delete father;
        }
    }
    void clear(){
        destroy(Root);
        Root=nullptr;
        count=0;
    }
    Node<T,U>* find(T key) {
        return Search(key, Root);
    }
    Node<T,U>* find_min_rec() { return SearchMin(Root); }
    Node<T,U>* find_max_rec() { return SearchMax(Root); }
    Node<T,U>* find_max() {
        Node<T,U>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->right != nullptr) {
                kernel = kernel->right;
            }
            return kernel;
        }
    }
    Node<T,U>* find_min() {
        Node<T,U>* kernel = Root;
        if (kernel != nullptr) {
            while (kernel->left != nullptr) {
                kernel = kernel->left;
            }
            return kernel;
        }
    }
    size_t size() { return count; }
    ~AVL_Tree() {
        destroy(Root);
    }
    void insert(T key,U data) {
        insert(key,data, Root);
        ++count;
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
    size_t the_longest_way() {
        Gl_Count=0;
        tree_traversal(0, Root);
        return Gl_Count;
    }
};
#endif // AVL_TREE_H
