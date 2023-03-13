class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto *fast = head, *slow = head; // Set both pointers to the head
        while(fast and fast->next) { // While fast can move two steps forward
            slow = slow->next; // Move slow one step
            fast = fast->next->next; // Move fast two steps
        }
        return slow; // Slow will be the middle at this point, so return it.
    }
};
