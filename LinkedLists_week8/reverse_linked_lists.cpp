//Given the head of a singly linked list, reverse the list, and return the reversed list.

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
class Solution {                                                   //Iterative Approach
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *f = NULL;
        ListNode *curr = head;
        while(curr!=NULL)
        {
            f = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = f;
            
        }
        return prev;
    }
};

//class Solution {                                                   //Recursive Approach
//public:
//    ListNode* recursive(ListNode* head)
//    {
//        if(head==NULL || head->next == NULL)
//            return head;
//        
//        ListNode* newHead = recursive(head->next);          //tail of initial list will be the head for reversed List
//        (head->next)->next = head;                          //reversing the links between nodes
//       head->next = NULL;                                  //tail of new list should point to NULL
//      
//     return newHead;
//}
// 
//ListNode* reverseList(ListNode* head) {
//    return recursive(head);
//}
//};