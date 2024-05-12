#include <iostream>
#include <initializer_list>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    Node<T>* head;
    LinkedList() : head(nullptr) {}

    LinkedList(std::initializer_list<T> values) : head(nullptr) {
        for (const auto& value : values) {
            pushBack(value);
        }
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pushBack(const T& value) {
        if (!head) {
            head = new Node<T>(value);
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node<T>(value);
        }
    }

    void removeHead() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeAfter(Node<T>* node) {
        if (node && node->next) {
            Node<T>* temp = node->next;
            node->next = temp->next;
            delete temp;
        }
    }

    void insertAfter(Node<T>* node, const T& value) {
        if (node == nullptr) {
            std::cerr << "Error: Cannot insert after a nullptr node." << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = node->next;
        node->next = newNode;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list = { 1, 2, 3, 4, 5 };
    std::cout << "Original list: ";
    list.print();

    list.removeHead();
    std::cout << "List after removing head: ";
    list.print();

    Node<int>* node = list.head;
    list.insertAfter(node, 10);
    std::cout << "List after inserting 10 after head: ";
    list.print();

    return 0;
}
