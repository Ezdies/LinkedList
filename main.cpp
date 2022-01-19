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

    void append(int number);

    Node *getHead() const;

    int size();

    int &at(int index);

    int *find(int number);

    void clear();

    void insert(int index, int number);
};

void LinkedList::append(int number) {
    Node *newNode = new Node;
    newNode->data = number;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

int LinkedList::size() {
    Node *tmp = head;
    int counter = 0;

    while (tmp) {
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
            counter++;
        }
    }
}

int *LinkedList::find(int number) {
    Node *tmp = head;

    while (tmp) {
        if (tmp->data == number) {
            return &tmp->data;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

void LinkedList::clear() {
    Node *tmp = head;
    Node *tmp2 = head->next; //starting from second element
    while (tmp2) {
        delete tmp;
        tmp = tmp2;
        tmp2 = tmp2->next;
    }
    head = nullptr;
}

void LinkedList::insert(int index, int number) {
    Node *tmp = head;
    int counter = 0;

    while (tmp) {
        if (counter == index) {
            Node *newNode = new Node;
            newNode->data = number;
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        tmp = tmp->next;
        counter++;
    }
}

Node *LinkedList::getHead() const {
    return head;
}

void printList(const LinkedList &list) {
    Node *tmp = list.getHead();
    while (tmp) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int main() {

    LinkedList list;

    list.append(9);
    list.append(8);
    list.append(7);

    printList(list);

    std::cout << std::endl;

    std::cout << list.size() << std::endl;
    std::cout << list.at(1) << std::endl;

    std::cout << *list.find(7) << std::endl;

    //   list.clear();
    std::cout << std::endl;
    list.insert(2, 2);
    printList(list);

    return 0;
}
