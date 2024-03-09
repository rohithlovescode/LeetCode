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
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;

        priority_queue<ListNode*, vector<ListNode*>,compare> minHeap;
        
        int n=lists.size();

        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
                minHeap.push(lists[i]);
            }
        }

        while(!minHeap.empty()){
            ListNode* topp=minHeap.top();
            curr->next=topp;
            curr=curr->next;
            minHeap.pop();

            if(topp&&topp->next){
                minHeap.push(topp->next);
            }
        }
        return dummy->next;

    }
};