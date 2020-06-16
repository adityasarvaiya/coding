#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;


class ThreeSum {
public:

    // Implement your solution here 
    
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    // Two - pointer solution
    // TC: O( n^2 )
    // SC: O( 1 )
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    vector<vector<int>> threeSum(vector<int>& nums) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
          
        // declaring answer variable which the function will return 
        
        vector<vector<int> > answer;
        
        // we need to sort the given vector for using the two pointer approach to solve the problem 
        
        sort(nums.begin(), nums.end());
        
        //iterating over all the vector elements one by one
        
        for (int i = 0; i < nums.size(); i++) {
            
            // since the present element is nums[i] we need to take -nums[i] as the target so that the sum of all the 3 elements can be 0
            
            int target = -nums[i];
        
            // we will keep one pointer just next to the element for which we are iterating  
            
            int front = i + 1;
         
            // we will keep another pointer to the last element of the vector(which is the greatest element always)
            
            int back = nums.size() - 1;

            // since the elements have to be unique we loop until front < back
            
            while (front < back) {

                // the current sum is the sum of the front and the back elements
                
                int sum = nums[front] + nums[back];
            
                // if the present sum is less we need to increment the front pointer as we need a greater value element wuth nums[back] to be made equal to target
                
                if (sum < target)
                    front++;
                
                // if the present sum is more we need to decrement the back pointer as we need a lesser value element wuth nums[front] to be made equal to target
                
                else if (sum > target)
                    back--;
                
                // when the target = nums[front] + nums[back], we have got one solution
                
                else {
                    
                    // triplet variable will store the elements of the current triplet whoose sum is 0  
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
            
                    // since we have found a solution, push the solution to the answer variable
                    
                    answer.push_back(triplet);
                
                    // processing duplicates of nums[front]
                    // incrementing the front pointer to the next different number forwards
                    
                    while (front < back && nums[front] == triplet[1]) 
                        front++;

                    // processing duplicates of nums[back]
                    // decrementing the back pointer to the next different number backwards
                    
                    while (front < back && nums[back] == triplet[2]) 
                        back--;
                }
            
            }

        // processing duplicates of nums[i] (since our solution needs only unique combinations)
            
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;

    }
    
    // returning the answer 
        
    return answer;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);

    vector<vector<int>> result = ThreeSum().threeSum(nums);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2]; 
        cout << endl; 
    }
    return 0;
}
