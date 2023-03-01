# [143. Reorder List](https://leetcode.com/problems/reorder-list/)

## Solution
- Creat a new list and add values in reversed manner.
- Loop on the list until the middle point and for each step, add the first element and the last element to the list.
- If the list size is odd, add the middle element to the list manually.
## Complexity
- Time complexity: `O(n)`, where n is the size of the list.

- Space complexity: `O(n)`

## Code
``` cpp
class Solution {
private:
    ListNode *tmp = new ListNode(0); // tmp pointer to be used when it's need to save specific pointer
public:
    int sz = 0; // to get the size of the List

    void dfs(ListNode *head) {
        if(!head) return;
        sz++; // we have one more element
        dfs(head->next); // go to the next
        tmp->val = head->val; // put the reversed value
        tmp->next = new ListNode(0);
        tmp = tmp->next;
    }

    // this function is used to copy head list to cur
    void fill(ListNode *head, ListNode *copy) {
        tmp = head; // use tmp to avoid losing head pointer
        while(tmp) { // copy all values
            copy->val = tmp->val;
            copy->next = new ListNode();
            copy = copy->next;
            tmp = tmp->next;
        }
    }

    void reorderList(ListNode *head) {
        if (!head->next) return; // there's just one element no need to do anything

        auto * reverse = tmp; // put the first pointer to tmp then fill new list with reversed values
        dfs(head); // fill the reversed list with reversed values

        auto * copiedList = new ListNode();
        fill(head, copiedList); // copy the head into copiedList list

        int mid = sz / 2; // loop until the middle point of the list

        // update the head list
        while(mid--) {
            head->val = copiedList->val;
            head = head->next;
            copiedList = copiedList->next;
            head->val = reverse->val;
            head = head->next;
            reverse = reverse->next;
        }

        if(sz & 1) head->val = copiedList->val; // if the size is odd -> the middle element should be added manually

        // delete all other pointers to avoid memory leaks
        delete reverse, reverse = nullptr;
        delete copiedList, copiedList = nullptr;
        delete tmp, tmp = nullptr;
    }
};
```