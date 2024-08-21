#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int item) : data(item), next(nullptr) {}
};

class LinkedList {
private:
    Node *first;
    Node *last;

public:
    LinkedList() : first(nullptr), last(nullptr) {}

  

    void insertAtFirst(int item) {
        Node *nn = new Node(item);
        if (first == nullptr) {
            first = nn;
            last = nn;
        } else {
            nn->next = first;
            first = nn;
        }
    }

  

  
       
    void deletionAtFront() {
        if (first == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node *temp = first;
       
        first = temp->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete temp;
    }

  
    void display() const {
        if (first == nullptr) {
            cout << "Underflow\n";
        } else {
            Node *temp = first;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    LinkedList list;
    int choice ,item;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert at front\n";
        
        cout << "2. Delete at front\n";
       
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to insert at front: ";
                cin >> item;
                list.insertAtFirst(item);
                break;

           

            case 2:
                list.deletionAtFront();
                break;

         

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}