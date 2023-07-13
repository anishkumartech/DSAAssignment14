
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* oddHead = head;
    ListNode* evenHead = head->next;
    ListNode* oddTail = oddHead;
    ListNode* evenTail = evenHead;

    ListNode* curr = evenHead->next;
    bool isOdd = true;

    while (curr != nullptr) {
        if (isOdd) {
            oddTail->next = curr;
            oddTail = curr;
        } else {
            evenTail->next = curr;
            evenTail = curr;
        }

        curr = curr->next;
        isOdd = !isOdd;
    }

    oddTail->next = evenHead;
    evenTail->next = nullptr;

    return oddHead;
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
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, n1);
    cout << "Original List: ";
    printLinkedList(head1);
    ListNode* reorderedHead1 = oddEvenList(head1);
    cout << "Reordered List: ";
    printLinkedList(reorderedHead1);

    int arr2[] = {2, 1, 3, 5, 6, 4, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, n2);
    cout << "Original List: ";
    printLinkedList(head2);
    ListNode* reorderedHead2 = oddEvenList(head2);
    cout << "Reordered List: ";
    printLinkedList(reorderedHead2);

    return 0;
}
