class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false; // If there's no nodes, there's no cycles
        auto *fast = head;
        while(fast->next and fast->next->next) { // While there's 2 nodes forward
            fast = fast->next->next; // Move fast pointer 2 nodes forward
            head = head->next; // Move head pointer one node forward
            if(head == fast) // If they meet again there's a cycle
                return true;
        }
        return false; // No cycle found
    }
};