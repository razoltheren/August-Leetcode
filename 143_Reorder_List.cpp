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
    void reorderList(ListNode* head) {
        if(head==NULL ||  head->next==NULL) return;
        ListNode *slow=head, *fast=head, *prev;
        while( fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* l1=head;
        ListNode* l2=reverse(slow);
        merge(l1,l2);
    }
    
    void merge(ListNode* l1,ListNode* l2){
        while(l2!=NULL){
            ListNode* agla=l1->next;
            l1->next=l2;
            l1=l2;
            l2=agla;
        }
    }
    
    ListNode* reverse(ListNode * head){
        if(head==NULL)  return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* agla=head->next;
        while(curr!=NULL){
            agla=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agla;
        }
        return prev;
    }
};