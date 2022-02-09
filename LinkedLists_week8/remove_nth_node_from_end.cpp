//Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
class Solution {                                                     //Optimised Approach
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* temp = head;
        
        int i = 0;
        while(slow!=NULL)
        {
            i++;
            if(i == n)
            {
                if(slow->next == NULL)               //if first node is to be deleted
                    return head->next;
                
                while(slow->next != NULL)           //at the end of this loop 
                {                                   //prev - before the node to be deleted
                    prev = temp;                    //temp - node to be deleted
                    temp = temp->next;              //slow - next to the node to be deleted
                    slow = slow->next;
                }
                prev->next = (prev->next)->next;    //remove the nth node by changing the connection
                return head;
            }
            slow = slow->next;
        }
        return head;
    }
};

//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        int total = 0, count = 0;
//        ListNode* temp = head;
//        
//        while(temp!=NULL)                                 //calculate the length of linked list
//        {
//            total++;
//            temp = temp->next;
//            //total++;
//        }
//       temp = head;
//        if(total == n)
//        {
//            return head->next;
//        }
//        while(count < total - n - 1 && temp != NULL)        //find the node prev to nth node
//        {
//            count++;
//            temp = temp->next;
//            cout<<temp->val;
//            cout<<count;
//            //count++;
//            cout<<count;
//        }
//        
//        if(temp == NULL || temp->next == NULL)
//            return NULL;
//    
//        temp->next = (temp->next)->next;  
//        return head;
//    }
//};
