#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (head == nullptr)
        return nullptr;

    // Create a mapping between original nodes and their copies
    unordered_map<Node*, Node*> nodeMap;

    // Create a new copy of each node and link them together
    Node* curr = head;
    Node* newHead = nullptr;
    Node* newPrev = nullptr;

    while (curr != nullptr) {
        Node* newNode = new Node(curr->data);
        nodeMap[curr] = newNode;

        if (newPrev != nullptr)
            newPrev->next = newNode;
        else
            newHead = newNode;

        newPrev = newNode;
        curr = curr->next;
    }

    // Set the random pointers of the copied nodes
    curr = head;
    Node* newCurr = newHead;

    while (curr != nullptr) {
        newCurr->random = nodeMap[curr->random];
        curr = curr->next;
        newCurr = newCurr->next;
    }

    return newHead;
}

// Function to create a special linked list
Node* createSpecialLinkedList(int arr[], int n, int pairs[][2], int m) {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Create nodes with values
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Set random pointers
    for (int i = 0; i < m; i++) {
        int a = pairs[i][0];
        int b = pairs[i][1];

        Node* curr = head;
        Node* randomNode = nullptr;
        int count = 1;

        while (curr != nullptr) {
            if (count == a) {
                randomNode = curr;
                break;
            }
            curr = curr->next;
            count++;
        }

        curr = head;
        count = 1;

        while (curr != nullptr) {
            if (count == b) {
                randomNode->random = curr;
                break;
            }
            curr = curr->next;
            count++;
        }
    }

    return head;
}

// Function to print the copied linked list
void printCopiedList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << "Node " << curr->data << ": ";
        if (curr->random != nullptr)
            cout << "Random -> " << curr->random->data;
        else
            cout << "Random -> NULL";
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pairs[][2] = {{1, 2}, {2, 4}};
    int m = sizeof(pairs) / sizeof(pairs[0]);

    Node* head = createSpecialLinkedList(arr, n, pairs, m);

    cout << "Original linked list:" << endl;
    printCopiedList(head);

    Node* newHead = copyRandomList(head);

    cout << "Copied linked list:" << endl;
    printCopiedList(newHead);

    return 0;
}

