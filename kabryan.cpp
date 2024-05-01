#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertNode(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(Node*& head, int position) {
    Node* temp = head;
    int currentPosition = 1;

    while (temp != NULL && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "node " << temp->data << " : " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    int numNodes;
    cout << "Input the number of nodes (3 or more ): ";
    cin >> numNodes;
    for (int i = 1; i <= numNodes; i++) {
        int data;
        cout << "Input data for node " << i << ": ";
        cin >> data;
        insertNode(head, data);
    }

   
    cout << "\nData entered in the list are:" << endl;
    displayList(head);

  
    int position;
    cout << "Input the position (1 to " << numNodes << ") to delete a node: ";
    cin >> position;

   
    deleteNode(head, position);


    cout << "\nAfter deletion the new list are:" << endl;
    displayList(head);

    return 0;
}
