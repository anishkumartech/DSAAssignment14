
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> nextGreaterNodes(ListNode* head) {
    vector<int> values;

    // Store the values of the linked list in a vector
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }

    int n = values.size();
    vector<int> result(n, 0);
    stack<int> st;

    // Traverse the values in reverse order
    for (int i = n - 1; i >= 0; i--) {
        int curr = values[i];

        // Pop nodes with values less than or equal to the current value
        while (!st.empty() && st.top() <= curr)
            st.pop();

        if (!st.empty())
            result[i] = st.top();  // Next greater node
        st.push(curr);
    }

    return result;
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

int main() {
    // Example usage
    int arr1[] = {2, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, n1);
    vector<int> result1 = nextGreaterNodes(head1);
    cout << "Output: ";
    for (int val : result1)
        cout << val << " ";
    cout << endl;

    int arr2[] = {2, 7, 4, 3, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, n2);
    vector<int> result2 = nextGreaterNodes(head2);
    cout << "Output: ";
    for (int val : result2)
        cout << val << " ";
    cout << endl;

    return 0;
}
