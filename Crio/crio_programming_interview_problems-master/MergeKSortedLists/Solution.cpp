
/*
// Definition for ListNode
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
*/

class Solution
{
	public:
		ListNode * mergeKSortedList(vector<ListNode*> list)
		{
                // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
			
			int low = 0 , high = list.size();
        	ListNode* answer = mergeListsRecur(low , high-1 , list);

        	return answer;
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
		}

                // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		ListNode * mergeListsRecur(int low , int high , vector<ListNode *> list)
		{
	        if(low  > high) {
	            return NULL;
	        }
	        if(low == high) {
	            return list[low];
	        }
	        int mid = (low + high)/2;
	        ListNode* left = mergeListsRecur(low , mid , list);
	        ListNode* right = mergeListsRecur(mid+1 , high , list);
	        ListNode* merged = mergeTwoList(left , right);
	        return merged;  
   		}
   		ListNode * mergeTwoList(ListNode * left, ListNode * right)
   		{
   			ListNode * answer;
	        answer->next = NULL;
	        ListNode * i = left ;
	        ListNode * j = right ;
	        ListNode * temp = answer;
	        while(i != NULL && j != NULL)
	        {
	            if(i->val < j->val)
	            {
	                temp->next = i;
	                i = i->next;
	                temp = temp->next;
	            }
	            else
	            {
	                temp->next = j;
	                j = j->next;
	                temp = temp->next;
	            }
	        }
	        while(i != NULL)
	        {
	            temp->next = i;
	            i = i->next;
	            temp = temp->next;
	        }
	        while(j != NULL) 
	        {
	            temp->next = j;
	            j = j->next;
	            temp = temp->next;
	        }
	    	answer = answer->next;
	    	return answer;
   		}
                // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

};
