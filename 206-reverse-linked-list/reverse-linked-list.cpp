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


//Using recursion:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* smallhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallhead;
    }
};
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* next=head->next;
        head->next=NULL;
        ListNode* prev;
        while(true){
            if(next==NULL){
                break;
            }
            prev=head;
            head=next;
            next=head->next;
            head->next=prev;
        }
        return head;
    }
};*/