#include <iostream>

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int number);

    Node *getHead() const;

    int size();

    int &at(int index);
};

void LinkedList::insert(int number) {
    Node *newNode = new Node;
    newNode->data = number;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

int LinkedList::size() {
    Node *tmp = head;
    int counter = 0;

    while (tmp != nullptr) {
        tmp = tmp->next;
        counter++;
    }
    return counter;
}

int &LinkedList::at(int index) {
    int counter = 0;
    Node *tmp = head;

    while (true) {
        if (counter == index) {
            return tmp->data;
        } else {
            tmp = tmp->next;
        }
    }
}

Node *LinkedList::getHead() const {
    return head;
}

void printList(const LinkedList &list) {
    Node *tmp = list.getHead();
    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int main() {

    LinkedList list;

    list.insert(9);
    list.insert(8);
    list.insert(7);

    printList(list);

    std::cout << std::endl;

    std::cout << list.size();



    return 0;
}
