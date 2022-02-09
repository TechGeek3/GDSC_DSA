//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and 
//each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        
        else if(l2 == NULL)
            return l1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        int c = 0;
        while(head1 != NULL || head2 != NULL || c != 0)
        {
            int sum = (head1 != NULL ? head1->val : 0) + (head2 != NULL ? head2->val : 0) + c;
            
            ListNode* node = new ListNode(sum % 10);               //initialise a node with val sum%10
            c = sum / 10;
            
            prev->next = node;
            prev = prev->next;
            
            if(head1 != NULL)
                head1 = head1->next;
            
            if(head2 != NULL)
                head2 = head2->next;
        }
        return dummy->next;
    }
};