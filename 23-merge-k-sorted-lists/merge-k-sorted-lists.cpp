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

class compare{
    public:
    bool operator()(const ListNode* a,const ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        
        for(ListNode* list:lists){
            if(list!=nullptr)
                pq.push(list);
        }

        ListNode* finalRoot=new ListNode(-1);
        ListNode* iterNode=finalRoot;

        while(!pq.empty()){
            ListNode* top=pq.top();
            pq.pop();
            iterNode->next=top;
            iterNode=iterNode->next;
            if(top->next!=nullptr){
                pq.push(top->next);
            }            
        }

        finalRoot=finalRoot->next;
        return finalRoot;
    }
};