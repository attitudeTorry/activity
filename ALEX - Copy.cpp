#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

Node* deleteNode(Node* head, int position) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return NULL;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* prevNode = NULL;
        Node* currentNode = head;
        int count = 1;

        while (currentNode != NULL && count < position) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }

        if (currentNode == NULL) {
            cout << "Invalid position. Cannot delete." << endl;
            return head;
        }

        prevNode->next = currentNode->next;
        delete currentNode;
    }

    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        cout << "node " << position++ << " : " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    int numNodes, value, position;

    cout << "Input the number of nodes (3 or more): ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cout << "Input data for node " << i + 1 << ": ";
        cin >> value;
        head = insertAtEnd(head, value);
        cout << "List after insertion: " << endl;
        displayList(head);
    }

    cout << "Data entered in the list: " << endl;
    displayList(head);

    cout << "Input the position (1 to " << numNodes << ") to delete a node: ";
    cin >> position;

    head = deleteNode(head, position);
    cout << "After deletion, the new list is: " << endl;
    displayList(head);

    return 0;
}


