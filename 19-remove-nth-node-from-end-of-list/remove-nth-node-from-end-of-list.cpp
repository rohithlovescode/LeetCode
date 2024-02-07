/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* nody;
        int leng=1;
        while(temp->next!=nullptr){
            leng++;
            nody=temp;
            temp=temp->next;
        }
        if(leng==n)
        return head->next;
        if(n==1){
            if(leng==1){
                return nullptr;
            }
            nody->next=nullptr;
            return head;
        }
        temp=head;
        ListNode* temp2=(head->next)->next;
        int index=leng-n;

        for(int i=1;i<index;i++){
            temp=temp->next;
            temp2= temp->next->next;
        }
        temp->next=temp2;
        return head;
    }
};