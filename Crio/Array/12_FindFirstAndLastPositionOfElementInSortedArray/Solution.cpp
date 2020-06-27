#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int findOccurenceOfElement(vector<int> &nums, int  target, bool find_first_or_last){

            int lowptr = 0;
            
            int highptr = nums.size() -1;

            int result = -1;

            while(lowptr <= highptr){
                
                int mid = (lowptr + highptr) / 2;
                
                if(nums[mid] < target)
                    lowptr = mid + 1;
                
                if(nums[mid] > target)
                    highptr = mid - 1;
                
                if(nums[mid] == target){
                    
                    result = mid;

                    if(find_first_or_last){
                        highptr = mid - 1;
                    }
                    else{
                        lowptr = mid+1;
                    }
                }
            }
        
        return result;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        vector<int> findFirstAndLastPositionOfElementInSortedArray(vector<int> &nums, int target) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            int first,last;
            
            first = findOccurenceOfElement(nums, target , 1);
            
            if(first!=-1)
                last = findOccurenceOfElement(nums, target, 0);
            else
                last = -1; 
            vector<int> answer;

            answer.push_back(first);
            answer.push_back(last); 
            
            return answer;       
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};
