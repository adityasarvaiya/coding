#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// Two - pointer solution
// TC : O( n )
// SC : O( 1 )
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class ContainerWithMostWater {
  public:
    int maxArea(vector<int>& height) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        
        // finding the size of the vector
        long long int n = height.size();
        
        // one pointer points to the element at the last of the vector or the back of the vector
        long long int back = n-1;

        // another pointer points to the front of the vector or the first element of the vector
        long long int front = 0;

        // answer variable will return the final answer
        long long int answer = 0;
        
        // iterating till the front pointer is less than the back pointer
        while(front < back){

            // minimum container size at this point
            long long int minimum_container_size_now = min(height[ front ], height[ back ]);

            // the present distance between the front and the back containers
            long long int distance_between_containers_now = back - front;

            // update the answer by comapring answer with the present area which the containers can hold
            answer = max(answer, distance_between_containers_now * minimum_container_size_now);
            
            // if the front container is smaller then shift to the next container 
            // else if the back container is smaller then shift to the previous container
            if(height[ front ] <= height[ back ])
                front++;
            else
                back--;
        }
        
        // finally return the answer
        return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> height;
    ReadMatrix<int>().OneDMatrix(n, height);
    int result = ContainerWithMostWater().maxArea(height);
    cout << result;
    return 0;
}
