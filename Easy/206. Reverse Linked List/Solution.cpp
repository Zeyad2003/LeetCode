class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        auto *cur = head->next;
        head->next = nullptr;
        while(cur) {
            auto *go = cur->next;
            cur->next = head;
            head = cur;
            cur = go;
        }
        return head;
    }
};