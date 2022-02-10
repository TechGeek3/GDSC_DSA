//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked 
//lists have no intersection at all, return null.

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
    
    ListNode* removeCycle(ListNode* ptr, ListNode* head)      //Finding the intersecting node
    {
        int k = 1;
        for(ListNode* node = ptr; node->next != ptr; node = node->next)         //Count the nodes involved in loop
            k++;
        
        ListNode* curr = head;
        for(int i=0; i<k; ++i)                               //Placing curr pointer at kth node
        {
            curr = curr->next;
        }
        
        while(head != curr)                                  //Increment head, curr until intersecting node isn't found
        {
            curr = curr->next;
            head = head->next;
        }
        
        return curr;
    }
    
    ListNode* detectCycle(ListNode* head)                     //detect a loop / cycle in linked list  
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            
            slow = slow->next;
            fast = (fast->next)->next;
            
            if(slow == fast)
                return slow;
        }
        
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB) {
        
        ListNode* temp = headA;                               //Floyd's Cycle Detection Method
        ListNode* prev = NULL;
        
        while(temp)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if(prev)                                              //connecting the tail to head
            prev->next = headA;
        
        ListNode* ptr = detectCycle(headB);                   //Find cycle in second list
        
        ListNode* node = NULL;
        if(ptr)
            node = removeCycle(ptr, headB);                  //Find the intersection node
        
        if(prev)
            prev->next = NULL;                               //Pointing the tail of list1 back to NULL
        
        return node;
    }
 
};

/*
class Solution {
public:
    
    int size(ListNode* head)                                             //Size of linked list
    {
        ListNode* temp = head;
        int count = 0;
        
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* Intersection(ListNode* headA, ListNode* headB, int k)      //Difference in count nodes
    {
        for(int i = 0; i<k && headA; i++)                                //Traverse bigger list by k nodes
        {
            headA = headA->next;
        }
        
        while(headA && headB)                                            //Traverse both the lists at the same pace
        {
            if(headA == headB)                                           //if intersection found then return
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int diff = size(headA) - size(headB);                            //Difference between the no of nodes
        
        if(diff<0)                                                       //Swap in case first list < second list
            swap(headA, headB);
        
        ListNode* ptr = Intersection(headA, headB, abs(diff));           //Find intersection
        return ptr;
    }
};*/