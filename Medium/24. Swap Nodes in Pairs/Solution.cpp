class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        auto * ret = new ListNode(0);
        ret->next = head;
        auto *first = head;
        auto *prev = ret;

        while(first and first->next) {
            auto *go = first->next->next;
            auto *second = first->next;

            first->next = go;
            second->next = first;
            prev->next = second;

            prev = first;
            first = go;
        }

        return ret->next;
    }
};