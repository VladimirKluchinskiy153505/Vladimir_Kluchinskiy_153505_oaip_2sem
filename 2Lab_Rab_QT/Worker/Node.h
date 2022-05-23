#ifndef NODE_H
#define NODE_H
template<class Type>
class Node {
public:
    Node* prev;
    Node* next;
    Type core;
    Node(const Type& core) {
        this->next = nullptr;
        this->prev = nullptr;
        this->core = core;
    }
};
#endif // NODE_H

