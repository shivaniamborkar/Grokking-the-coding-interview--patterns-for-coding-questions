/*
Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]
*/

int squaring_sorted_arr(int arr){
    int n = arr.size();
    vector<int> squares(n);
    int left = 0;
    int right = n-1;
    int highest_square_index = n-1;

    while(left <= right){
        int left_square = arr[left] * arr[left];
        int right_square = arr[right] * arr[right];

        if(left_square > right_square){
            squares[highest_square_index--] = left_square;
            left++;
        }
        else{
            squares[highest_square_index--] = right_square;
            right--;
        }
    } 
    return squares;
}