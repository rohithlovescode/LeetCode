
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        int temp=1;
        ListNode* tempNode=head;
        while(tempNode->next!= nullptr){
            tempNode=tempNode->next;
            temp++;
            if(temp>=k){
                break;
            }
        }
        if(temp<k){
            return head;
        }
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;
        while(curr!=NULL&&count++<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;  
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};
/*
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr)
      return nullptr;

    ListNode* tail = head;

    for (int i = 0; i < k; ++i) {
      if (tail == nullptr)  // Less than k nodes, do nothing
        return head;
      tail = tail->next;
    }

    ListNode* newHead = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
  }

 private:
  // Reverses [head, tail)
  ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != tail) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};*/