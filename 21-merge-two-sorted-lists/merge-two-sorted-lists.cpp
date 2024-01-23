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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1=list1,* curr2=list2;
        ListNode* dummyHead= new ListNode(-1);
        ListNode* solTail=dummyHead;
        while(curr1!=NULL&&curr2!=NULL){
            if(curr1->val<=curr2->val){
                solTail->next=curr1;
                curr1=curr1->next;
                solTail=solTail->next;
            }
            else{
                solTail->next=curr2;
                curr2=curr2->next;
                solTail=solTail->next;
            }
        }
        while(curr1!=nullptr){
            solTail->next=curr1;
            solTail=solTail->next;
            curr1=curr1->next;
        }
        while(curr2!=nullptr){
            solTail->next=curr2;
            solTail=solTail->next;
            curr2=curr2->next;
        }
        return dummyHead->next;
    }
};
 /*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        else if(list1->val<=list2->val){
            ans=list1;
            ans->next=mergeTwoLists(list1->next,list2);
        }else{
            ans=list2;
            ans->next=mergeTwoLists(list1,list2->next);
        }
        return ans;
    }
};
*/