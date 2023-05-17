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

    int pairSum(ListNode* head) {
        auto *fast = head, *slow = head;
        while(fast) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto *startReversed = reverseList(slow);
        int ans = 0;
        while(startReversed) {
            ans = max(ans, head->val + startReversed->val);
            head = head->next;
            startReversed = startReversed->next;
        }
        return ans;
    }
};