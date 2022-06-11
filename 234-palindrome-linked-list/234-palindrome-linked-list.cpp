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
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL){
           return true;
        }
        
        ListNode* middle=getMid(head);
        
        // ListNode* temp=middle->val;
        
        
        
        // ListNode* head1=head;
        ListNode* head2=reverse(middle);
        
        while(head2!=NULL && head!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        
//         temp=middle->val;
        
//         middle->val=reverse(temp);
        return true;
    }
};