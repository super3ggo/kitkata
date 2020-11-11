#include <iostream>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
public:
    LinkedList(int data);
    ~LinkedList();

    void  drop();
    void  dropEnd();
    void  insert(int data);
    void  show();
    Node *getHead();
    int   getSize();
private:
    Node *head;
};

LinkedList::LinkedList(int data) {
    head = new Node();
    head->data = data;
    head->next = NULL;
}

LinkedList::~LinkedList() {
    Node *current = head;

    while(current != NULL) {
        Node *tmp = current->next;
        delete(current);
        current = tmp;
    }
    head = NULL;
}

void LinkedList::drop() {
    if (head == NULL) {
        std::cout << "LL empty!" << std::endl;
    } else if (head->next == NULL) {
        std::cout << "LL size one!" << std::endl;
    } else {
        Node *tmp = head;
        head = head->next;
        delete(tmp);
    }
}

void LinkedList::dropEnd() {
    if (head == NULL) {
        std::cout << "LL empty!" << std::endl;
    } else if (head->next == NULL) {
        std::cout << "LL size one!" << std::endl;
    } else {
        Node *ref=head;
        while(ref != NULL) {
            if (ref->next->next == NULL) {
                // Remove the next Node, i.e. the last one.
                Node* tmp = ref->next;
                ref->next = NULL;
                delete(tmp);
                return;
            } else {
                ref = ref->next;
            }
        }
    }
}

void LinkedList::insert(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head          = newNode;
}

void LinkedList::show() {
    if (head == NULL) {
        std::cout << "LL empty!" << std::endl;
        return;
    } else {
        Node *ref = head;
        while(ref != NULL) {
            if (ref->next == NULL) {
                std::cout << ref->data << std::endl;
            } else {
                std::cout << ref->data << ",";
            }
            ref = ref->next;
        }
    }
}

Node *LinkedList::getHead() {
    return head;
}

int LinkedList::getSize() {
    int counter = 0;

    while(head != NULL) {
        counter++;
        head = head->next;
    }

    return counter;
}
