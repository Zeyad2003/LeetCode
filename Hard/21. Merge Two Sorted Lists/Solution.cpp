class Solution {
public:

    // Function to merge 2 sorted lists together
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2; // No elements in list1, so return the remaining in list2
        if(!list2) return list1; // No elements in list2, so return the remaining in list1

        if(list1->val < list2->val) { // Move the pointer of list1 to the next node
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        else { // Move the pointer of list2 to the next node
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = (int) lists.size();
        if(!n) return nullptr; // No lists to merge
        if(n == 1) return lists[0]; // Only one list, so return it

        while((int) lists.size() > 1) { // While there are more than 1 lists -> you can merge them
            auto *l1 = lists.back(); lists.pop_back(); // Get the last list
            auto *l2 = lists.back(); lists.pop_back(); // Get the second last list
            lists.emplace_back(mergeTwoLists(l1, l2)); // Merge the 2 lists and add the result to the end of the vector
        }

        return lists[0]; // Return the merged list
    }
};
\