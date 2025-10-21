#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteNode(int val) {
        Node* temp = head;

        // If list is empty
        if (temp == nullptr) return;

        // If head needs to be deleted
        if (temp->data == val) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        // Traverse to find the node
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // Not found

        // Update links
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        cout << "List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) return;
        Node* temp = head;

        // Go to last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "List (backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function to test the list
int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    dll.displayForward();
    dll.displayBackward();

    dll.deleteNode(20);
    dll.displayForward();

    dll.deleteNode(40);
    dll.displayForward();

    return 0;
}
