#include <iostream>
#include <stdexcept>  

using namespace std;

template <typename T>
class List {
private:

    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size; 

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++; 
    }

    bool remove(const T& value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; \
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; 
                }

                delete current;
                size--; 
                return true; 
            }
            current = current->next;
        }
        return false; 
    }

    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Индекс за пределами списка");
        }

        if (index == size) {
            push_back(value);  
            return;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
        } else {
            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }

            newNode->next = current;
            newNode->prev = current->prev;

            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
        size++; 
    }

    void deleteAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс за пределами списка");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next; 
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; 
        }

        delete current;
        size--; 
    }

    void swap(size_t index1, size_t index2) {
        if (index1 >= size || index2 >= size) {
            throw std::out_of_range("Один или оба индекса за пределами списка");
        }

        if (index1 == index2) {
            return; 
        }

        Node* node1 = head;
        for (size_t i = 0; i < index1; ++i) {
            node1 = node1->next;
        }

        Node* node2 = head;
        for (size_t i = 0; i < index2; ++i) {
            node2 = node2->next;
        }

        std::swap(node1->data, node2->data);
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    List<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    std::cout << "Список после push_back: ";
    myList.print(); 
    myList.remove(20);
    std::cout << "Список после remove(20): ";
    myList.print(); 
    myList.insert(1, 25);
    std::cout << "Список после insert(1, 25): ";
    myList.print(); 
    myList.deleteAt(2);
    std::cout << "Список после deleteAt(2): ";
    myList.print(); 
    myList.swap(0, 2);
    std::cout << "Список после swap(0, 2): ";
    myList.print(); 

    std::cout << "Размер списка: " << myList.getSize() << std::endl;

    try {
        myList.insert(10, 50); 
    } catch (const std::out_of_range& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}