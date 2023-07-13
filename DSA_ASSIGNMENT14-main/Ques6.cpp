
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateLeft(ListNode* head, int k) {
    if (head == nullptr || k <= 0)
        return head;

    // Find the k+1th node from the start
    ListNode* curr = head;
    for (int i = 0; i < k; i++) {
        if (curr->next == nullptr)
            curr = head;  // Wrap around to the head if k > length of list
        else
            curr = curr->next;
    }

    // Set the new head of the shifted list
    ListNode* newHead = curr;

    // Traverse to the end of the list
    while (curr->next != nullptr)
        curr = curr->next;

    // Connect the end of the list to the original head
    curr->next = head;

    // Update the next pointer of the kth node to nullptr
    ListNode* kthNode = head;
    for (int i = 0; i < k - 1; i++)
        kthNode = kthNode->next;
    kthNode->next = nullptr;

    return newHead;
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
    int arr1[] = {2, 4, 7, 8, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 3;
    ListNode* head1 = createLinkedList(arr1, n1);
    cout << "Original List: ";
    printLinkedList(head1);
    ListNode* shiftedHead1 = rotateLeft(head1, k1);
    cout << "Shifted List: ";
    printLinkedList(shiftedHead1);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 4;
    ListNode* head2 = createLinkedList(arr2, n2);
    cout << "Original List: ";
    printLinkedList(head2);
    ListNode* shiftedHead2 = rotateLeft(head2, k2);
    cout << "Shifted List: ";
    printLinkedList(shiftedHead2);

    return 0;
}
