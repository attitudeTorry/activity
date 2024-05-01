#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

LinkedList* createLinkedList() {
    LinkedList* list = new LinkedList();
    list->head = NULL;
    list->tail = NULL;

    return list;
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = createNode(value);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

Node* deleteNode(LinkedList* list, int position) {
    if (list->head == NULL) {
        cout << "List are empty. Cannot delete." << endl;
        return NULL;
    }

    if (position == 1) {
        Node* temp = list->head;
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        delete temp;
    } else {
        Node* currentNode = list->head;
        int count = 2;

        while (currentNode != NULL && count < position - 1) {
            currentNode = currentNode->next;
            count++;
        }

        if (currentNode == NULL || currentNode->next == NULL) {
            cout << "It is invalid position. Cannot delete." << endl;
            return list->head;
        }

        Node* nodeToDelete = currentNode->next;
        currentNode->next = nodeToDelete->next;
        if (list->tail == nodeToDelete) {
            list->tail = currentNode;
        }
        delete nodeToDelete;
    }

    return list->head;
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
    LinkedList* list = createLinkedList();

    int numNodes;
    cout << "Input the number of nodes : ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int value;
        cout << "Input data for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(list, value);
    }

    cout << "Data entered in the list are: " << endl;
    displayList(list->head);

    int position;
    cout << "Input the position (1 to " << numNodes << ") to delete a node: ";
    cin >> position;

    list->head = deleteNode(list, position);
    cout << "After deletion, the new list is: " << endl;
    displayList(list->head);

    return 0;
}
