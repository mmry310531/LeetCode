/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // method 1
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> visited;
//         while(head){
//             if(visited.count(head)) return true;
            
//             visited.insert(head);
//             head = head->next;
//         }
//         return false;
//     }
    
    //// main idea ////
    //// There are two people are running. One run faster than the other one. 
    // If ther is a cycle, chance is that the slower has same position with the faster
    
    // method 2
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        
        while(fast!=NULL){
            if(fast->next == NULL) return false;
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
            
        }
        
        return false;
        
    }
};