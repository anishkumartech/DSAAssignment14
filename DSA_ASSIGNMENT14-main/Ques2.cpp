#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addOne(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* newHead = nullptr;

    int carry = 1;  // Initialize carry as 1 for addition of 1

    // Traverse the linked list in reverse order
    while (curr != nullptr) {
        int sum = curr->val + carry;  // Add the current digit and the carry

        carry = sum / 10;  // Calculate the new carry

        curr->val = sum % 10;  // Update the value of the current digit

        prev = curr;
        curr = curr->next;
    }

    // If there is a carryover after traversing all digits, create a new node
    if (carry > 0) {
        ListNode* newNode = new ListNode(carry);
        prev->next = newNode;
    }

    // Reverse the modified linked list
    curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = newHead;
        newHead = curr;
        curr = nextNode;
    }

    return newHead;
}

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    int arr[] = {4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, n);

    cout << "Original linked list: ";
    printLinkedList(head);

    head = addOne(head);

    cout << "Linked list after adding 1: ";
    printLinkedList(head);

    return 0;
}

