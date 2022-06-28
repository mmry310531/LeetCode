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
    
    
    //// main idea 
    //// 因為是link_list 不需要考慮大數的問題
    //// 剩餘部分只需要注意carry, l1、l2長度不相同的情況即可
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            ListNode *tmp = new ListNode(0);
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            tmp->val = sum;

            cur->next = tmp;
            cur = cur->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL){
            ListNode *tmp = new ListNode(0);
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            tmp->val = sum;
            
            cur->next = tmp;
            cur = cur->next;
            
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            ListNode *tmp = new ListNode(0);
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            tmp->val = sum;

            cur->next = tmp;
            cur = cur->next;
            
            l2 = l2->next;
        }
        
        if(carry==1){
            ListNode *tmp = new ListNode(0);
            tmp->val = 1;
            cur->next = tmp;
            cur = cur->next;
        }
        
        return ans->next;
    }
};