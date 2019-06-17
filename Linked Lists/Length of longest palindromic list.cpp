/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // function for counting the common elements 
int countCommon(ListNode *a, ListNode *b) 
{ 
    int count = 0; 
  
    // loop to count coomon in the list starting 
    // from node a and b 
    for (; a && b; a = a->next, b = b->next) 
  
        // increment the count for same values 
        if (a->val == b->val) 
            ++count; 
        else
            break; 
  
    return count; 
} 
  
// Returns length of the longest palindrome 
// sublist in given list 
int maxPalindrome(ListNode *head) 
{ 
    int result = 0; 
    ListNode *prev = NULL, *curr = head; 
  
    // loop till the end of the linked list 
    while (curr) 
    { 
        // The sublist from head to current 
        // reversed. 
        ListNode *next = curr->next; 
        curr->next = prev; 
  
        // check for odd length palindrome 
        // by finding longest common list elements 
        // beginning from prev and from next (We 
        // exclude curr) 
        result = max(result, 2*countCommon(prev, next)+1); 
  
        // check for even length palindrome 
        // by finding longest common list elements 
        // beginning from curr and from next 
        result = max(result, 2*countCommon(curr, next)); 
  
        // update prev and curr for next iteration 
        prev = curr; 
        curr = next; 
    } 
    return result; 
}
 
int Solution::solve(ListNode* A) 
{
    
    return maxPalindrome(A);
    
}
