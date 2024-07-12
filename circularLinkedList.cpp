#include <iostream>
#include<string>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data=data;
      this->next = NULL;
  }
};

class CircularLinkedList{
    private:
    Node* head;
    public:
    CircularLinkedList(){
        head=NULL;
    }
    
    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return ;
        }
        Node* temp = head;
        while(temp->next != head){
            temp=temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return ;
        }
        Node* temp = head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    void deleteNode(int key) {
        if (head == nullptr) {
            return;
        }

        if (head->data == key && head->next == head) { // Single node case
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;
        Node* d;

        if (head->data == key) { // If head is to be deleted
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            delete head;
            head = last->next;
        } else {
            while (last->next != head && last->next->data != key) {
                last = last->next;
            }

            if (last->next->data == key) {
                d = last->next;
                last->next = d->next;
                delete d;
            }
        }
    }
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "HEAD" << std::endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        Node* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "Circular Linked List: ";
    list.display();

    cout << "Deleting 20..." << endl;
    list.deleteNode(20);
    list.display();

    cout << "Deleting 5..." << endl;
    list.deleteNode(5);
    list.display();

    return 0;
}
