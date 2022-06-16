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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* curr=head;;
        ListNode* leftprev=dummy;
        
        for(int i=0;i<left-1;i++){
            leftprev=curr;
            curr=curr->next;
        }
        
        ListNode* prev=NULL;
        
        for(int i=0;i<right-left+1;i++){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        leftprev->next->next=curr;
        leftprev->next=prev;
        return dummy->next;
    }
};