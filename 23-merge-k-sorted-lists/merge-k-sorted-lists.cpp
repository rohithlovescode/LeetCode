class Solution {
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* result = NULL;
        ListNode* tail = NULL;

        while(ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                if (tail) {
                    tail->next = ptr1;
                    tail = tail->next;
                } else {
                    result = tail = ptr1;
                }
                ptr1 = ptr1->next;
                tail->next = NULL;
            } else {
                if (tail) {
                    tail->next = ptr2;
                    tail = tail->next;
                } else {
                    result = tail = ptr2;
                }
                ptr2 = ptr2->next;
                tail->next = NULL;
            }
        }

        if (ptr1) {
            tail->next = ptr1;
        } else {
            tail->next = ptr2;
        }
        return result;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return {};
        if (n == 1) {
            return lists[0];
        }
        int lim = log2(n);
        for (int x = 0; x <= lim; x++) {
            int step = 2 << x;
            int next = step >> 1;
            for (int i = 0; i < n; i += step) {
                if (i + next < n)
                    lists[i] = merge(lists[i], lists[i + next]);
            }
        }
        return lists[0];
    }
};