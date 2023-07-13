
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode* bottom;
    ListNode(int x) : data(x), next(nullptr), bottom(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    ListNode* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = mergeLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeLists(a, b->bottom);
    }

    result->next = nullptr;
    return result;
}

// Function to flatten the linked list
ListNode* flatten(ListNode* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr)
        return head;

    // Merge the current list with the flattened rest
    head->next = flatten(head->next);

    // Merge the current list with the bottom list
    head = mergeLists(head, head->next);

    // Return the merged list
    return head;
}

// Function to create a sub-linked list
ListNode* createSubList(int arr[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->bottom = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print the flattened linked list
void printFlattenedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->bottom != nullptr)
            cout << " -> ";
        curr = curr->bottom;
    }
    cout << endl;
}

int main() {
    // Example usage
    int arr[] = {5, 10, 19, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createSubList(arr, n);

    head->next = createSubList(arr, n);
    head->next->next = createSubList(arr, n);
    head->next->next->next = createSubList(arr, n);

    cout << "Flattened linked list: ";
    head = flatten(head);
    printFlattenedList(head);

    return 0;
}
