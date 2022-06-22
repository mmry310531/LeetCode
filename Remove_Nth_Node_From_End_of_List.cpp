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
    
    // method 1
    // remove n_th element from the end 
    // In other word, we move (k-n)_th element from the start
    // First we need the total number(k) of List
    // Then Remove (k-n)th element
    
    // Important!! If we want remove the first element, just return head->next;
    
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int length = 0;
//         auto travel = head;
//         while(travel != NULL){
//             length++;
//             travel = travel->next;
//         }
//         n = length - n;
//         travel = head;
//         for(int i=0;i<n-1;i++){
//             travel = travel->next;
//         }
        
//         if(n==0){
//             return head->next;
//         }
        
//         if(travel->next != NULL){
//             travel->next = travel->next->next;
//         }

        
//         return head;
//     }
    
    // method 2
    //// main idea ////
    // We create fast and slow node, and fast would pre-run x steps.
    // If fast is null, then slow would stop at the element we want to remove
    // However, we need dummy node to make slow stop at previous one.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        
        while(fast!=nullptr){

            fast=fast->next;
            slow=slow->next;
            
        }
        

        slow->next = slow->next->next;
        
        
        return dummy->next;
        
    }
};