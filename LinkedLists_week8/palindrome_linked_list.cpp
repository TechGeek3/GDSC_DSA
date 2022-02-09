//Given the head of a singly linked list, return true if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode* mid_ele = mid(head);                         //end of first half
        ListNode* newHead = reverse(mid_ele->next);            //start of second half
        
        ListNode* slow = head;
        ListNode* fast = newHead;
        
        while(fast != NULL)                                   //checking for palindrome
        {
            if(slow->val != fast->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        
        mid_ele->next = reverse(newHead);                   //reversing the second half again - Inplace
        return true;
    }
    ListNode* reverse(ListNode* head)                       //reverse the second half
    {
        ListNode* temp = head;
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newHead = reverse(head->next);
        (head->next)->next = head;
        head->next = NULL;
        
        return newHead;
    }
    ListNode* mid(ListNode* head)                            //end of first half - middle element
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && (fast->next)->next)
        {
            slow = slow->next;
            fast = (fast->next)->next;
        }
        return slow;
    }
};

//Method1: Push elements of linked list in a vector -> check for palindrome - O(n), O(n)
//Method2: Recursively check for palindrome in linked list using 2 pointers - O(n), O(n)
//Method3: Reverse the 2nd half of linked list -> compare nodes of both the halves for palindrome -> reverse the linked list again(In-place) - O(n), O(1)