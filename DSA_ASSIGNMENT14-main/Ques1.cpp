#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void removeLoop(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode* slow = head;
    ListNode* fast = head;

    // Detect the loop
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If loop exists, find the start of the loop
    if (slow == fast) {
        slow = head;

        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = nullptr;  // Remove the loop
    }
}

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0)
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, n1);
    head1->next->next->next->next = head1->next;  // Creating a loop
    cout << "Linked list with a loop: ";
    //printLinkedList(head1);
    removeLoop(head1);
    cout << "After removing the loop: ";
    printLinkedList(head1);

    int arr2[] = {1, 8, 3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, n2);
    cout << "Linked list without a loop: ";
    //printLinkedList(head2);
    removeLoop(head2);
    cout << "After removing the loop: ";
    printLinkedList(head2);

    return 0;
}
