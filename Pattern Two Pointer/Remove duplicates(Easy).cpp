/*
Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
*/

int remove_duplictes(int arr){
    int next_non_duplicate = 1; //index of next non duplicate number
    for(int i=0; i< arr.size(); i++){
        if(arr[next_non_duplicate - 1] != arr[i]){  
            arr[next_non_duplicate] = arr[i];
            next_non_duplicate++;
        }
    }
    return next_non_duplicate;
}