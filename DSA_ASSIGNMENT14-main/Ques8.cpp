
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    unordered_map<int, ListNode*> prefixSumMap;
    int prefixSum = 0;
    ListNode* curr = dummy;

    while (curr != nullptr) {
        prefixSum += curr->val;

        if (prefixSumMap.count(prefixSum)) {
            ListNode* prev = prefixSumMap[prefixSum]->next;
            int removeSum = prefixSum + prev->val;

            while (prev != curr) {
                removeSum += prev->val;
                prefixSumMap.erase(removeSum);
                prev = prev->next;
            }

            prefixSumMap[prefixSum]->next = curr->next;
        } else {
            prefixSumMap[prefixSum] = curr;
        }

        curr = curr->next;
    }

    return dummy->next;
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
    int arr1[] = {1, 2, -3, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, n1);
    cout << "Input: ";
    printLinkedList(head1);
    ListNode* result1 = removeZeroSumSublists(head1);
    cout << "Output: ";
    printLinkedList(result1);

    int arr2[] = {1, 2, 3, -3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, n2);
    cout << "Input: ";
    printLinkedList(head2);
    ListNode* result2 = removeZeroSumSublists(head2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
