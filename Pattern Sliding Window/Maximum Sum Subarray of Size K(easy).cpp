/*
#Problem Statement
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:

Input: [2, 3, 4, 1, 5], k=2
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
*/

int max_sum_sub_array_size_k(int k, int arr)
{
    int max_Sum = 0;
    int window_Sum = 0;
    int window_Start = 0;

    for (int window_End = 0; window_End < arr.size(); window_End++)
    {
        window_Sum += arr[window_End]; // add the next element, until it hit the below condition

        if (window_End > k - 1)
        {                                       // slide the window, we don't need to slide if we've not hit the required window size of 'k'
            max_Sum = max(max_Sum, window_Sum); // Calculate maximum sum and store inside maxSum
            window_Sum -= arr[window_Start];    // Subtract the element which is going out
            window_Start++;                     // slide the window ahead
        }
    }
    return max_Sum;
}

int main()
{
    cout << "Maximum Sum of Subarray of Size K: " << max_sum_sub_array_size_k(3, [ 2, 1, 5, 1, 3, 2 ]) << endl;
    cout << "Maximum Sum of Subarray of Size K: " << max_sum_sub_array_size_k(2, [ 2, 3, 4, 1, 5 ]) << endl;
}