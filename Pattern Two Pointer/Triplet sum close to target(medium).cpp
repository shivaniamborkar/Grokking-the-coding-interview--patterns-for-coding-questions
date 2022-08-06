/*
Problem Statement #
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
*/

//mycode
#include <limits>

int triplet_sum_close_to_target(int arr, int target_sum){
    sort(arr.begin(), arr.end());
    int smallest_difference = numeric_limits;

    for(int i=0;i<arr.size() - 2; i++){
        int left = i+1, right = arr.size() - 1;

        while(left < right){
            //comparing the sum of three numbers to the target_sum can cause overflow
            // so we will try to find target differnce
            int target_diff = target_sum - arr[i] - arr[left] - arr[right];

            if(target_diff == 0){ //we have found the triplet with exact sum
                return target_sum - target_diff; //return sum of all numbers
            }

            if(abs(target_diff) < abs(smallest_difference)){
                smallest_difference = target_diff; //save the closest difference
            }

            if(target_diff > 0){
                left++; //we need a triplet with a bigger sum
            }
            else{
                right--; //we need a triplet with a smaller sum
            }
        }
    }
    return target_sum - smallest_difference;
}