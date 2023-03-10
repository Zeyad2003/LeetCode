// Zeyad Nasef
class Solution {
public:
    ListNode* head; // Linked List start pointer
    Solution(ListNode* head) {
        srand(time(nullptr)); // Seed the random number generator
        this->head = head; // Set the head pointer
    }

    int getRandom() {
        int num = head->val; // Take the first element as the result
        ListNode* cur = head->next; // Start from the second element
        int i = 2; // The number of elements processed so far is 2
        while(cur) { // Explore the linked list
            if(!(rand() % i)) // Generate a random number in the range [0, i) and check if it is 0
                num = cur->val; // Replace num with cur->val with probability 1/i
            cur = cur->next; // Move to the next node
            i++; // Increment the count of nodes processed so far
        }
        return num; // Return the result
    }
};