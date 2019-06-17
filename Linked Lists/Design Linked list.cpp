/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
deque<int> data;

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void addAtHead(int val) {
    data.push_front(val);
}

/** Append a node of value val to the last element of the linked list. */
void addAtTail(int val) {
    data.push_back(val);
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void addAtIndex(int index, int val) {
    if ((index >= 0) && (index <= data.size())) {
        data.insert(data.begin() + index, val);
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void deleteAtIndex(int index) {
    if ((index >= 0) && (index < data.size())) {
        data.erase(data.begin() + index);
    }
}
 
ListNode* Solution::solve(vector<vector<int> > &A) 
{
    
    data.clear();
    
    for(int i=0; i<A.size(); i++)
    {
        
        if(A[i][0] == 0)
        {
            
            addAtHead(A[i][1]);
            
        }
        
        else if(A[i][0] == 1)
        {
            
            addAtTail(A[i][1]);
            
        }
        
        else if(A[i][0] == 2)
        {
            
            addAtIndex(A[i][2], A[i][1]);
            
        }
        
        else
        {
            
            deleteAtIndex(A[i][1]);
            
        }
        
    }
    
    ListNode *head = NULL;
    
    ListNode *track = NULL;
    
    for(int i=0; i<data.size(); i++)
    {
        
        ListNode *temp = new ListNode(data[i]);
        
        if(head == NULL)
        {
            
            head = temp;
            
        }
        
        else
        {
            
            track->next = temp;
            
        }
        
        track = temp;
        
    }
    
    return head;
    
}
