// Zeyad Nasef
class Solution {
public:
    vector<int> store; // Used to store the values of the linked list
    Solution(ListNode* head) {
        while(head) { // Traverse the linked list
            store.emplace_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int idx = rand() % (int) store.size(); // Generate a random index
        return store[idx]; // Return the value at that index
    }
};