#include <bits/stdc++.h>
using namespace std;

class Solution {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    // Solution is based on binary search technique
    // TC : O ( log n) for each query where n is the no of the elements of the vector
    // SC : O ( 1 )
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public:
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int findOccurenceOfElement(vector<int> &nums, int  target, bool find_first_or_last){

            // intialising the low ptr        
            int lowptr = 0;
            
            // initializing the high ptr
            int highptr = nums.size() -1;

            // result variable will hold the position of the element 
            int result = -1;

            while(lowptr <= highptr){
                
                // finding the mid position
                int mid = (lowptr + highptr) / 2;
                
                // if middle element is lesser than target
                if(nums[mid] < target)
                    lowptr = mid + 1;
                
                // if middle element is greater than target
                if(nums[mid] > target)
                    highptr = mid - 1;
                
                // if middle element is equal to the target
                if(nums[mid] == target){
                    
                    // store the occurence of the element in result
                    result = mid;

                    // if we are finding the first occurence of the target
                    if(find_first_or_last){
                        highptr = mid - 1;
                    }
                    // if we are finding the last occurence of the target
                    else{
                        lowptr = mid+1;
                    }
                }
            }
        
        return result;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        vector<int> searchRange(vector<int> &nums, int target) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            // first and last will store the first and last occurences of the element in the vector
            int first,last;
            
            // find the first occurence of the element in the vector
            first = findOccurenceOfElement(nums, target , 1);
            
            // if the element is found in the vector then find out the last occurence of that element 
            if(first!=-1)
                last = findOccurenceOfElement(nums, target, 0);
            else
                // if the first occurence of the no is not found then the last occurence too will not be found
                last = -1;
            
            // answer vector will be returned 
            vector<int> answer;

            answer.push_back(first);
            answer.push_back(last); 
            
            return answer;       
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};
