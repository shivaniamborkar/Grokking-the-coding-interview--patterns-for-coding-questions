/*
Problem Statement #
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2
Example 2:

Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7
*/

//mycode

int find_missing_number(int nums){
    int i=0;
    while(i< nums.size()){
        if(nums[i] < nums.size() && nums[i] != nums[nums[i]]){
            swap(nums, i, nums[i]);
        }else{
            i++;
        }
    }

    //find the first number missing form its index, that will be our required number
    for(i=0; i<nums.size(); i++){
        if(nums[i] != i){
            return i;
        }    
    }
    return nums.size();
}

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}