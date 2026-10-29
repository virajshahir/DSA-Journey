/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        stack<ListNode*> st;

        // Step 1: Count the number of nodes
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        // Step 2: Push the second half into the stack
        temp = head;

        for (int i = 0; i < n / 2; i++) {
            temp = temp->next;
        }

        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        // Step 3: Create an array to store the reordered nodes
        vector<ListNode*> output(n);

        temp = head;

        // Put first-half nodes at alternate positions
        for (int i = 0; i < n; i += 2) {
            output[i] = temp;
            temp = temp->next;
        }

        // Step 4: Fill the remaining positions using the stack
        for (int i = 1; i < n; i += 2) {
            output[i] = st.top();
            st.pop();
        }

        // Step 5: Connect the nodes in the new order
        for (int i = 0; i < n - 1; i++) {
            output[i]->next = output[i + 1];
        }

        output[n - 1]->next = NULL;
    }
};