class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str; // ddd linked list values to the string
        while(head) {
            str.push_back(head->val + '0'); // convert the number to char and push it back to the string
            head = head->next; // move to the next node
        }
        return stoi(str, 0, 2); // convert the string to decimal
    }
};