/*
#Problem Statement 
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

Example 3:

Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].

*/

//mycode
#include<limits>
int smallest_sub_array_with_given_sum(int S, int arr){
    int window_Sum = 0;
    int min_length = numeric_limits; //min_length= infinity
    int window_Start = 0;

    for(int window_End = 0; window_End < arr.size(); window_End++){
        window_Sum += arr[window_End]; //add the next element

        // shrink the window as small as possible until the 'window_sum' is smaller than 'S'
        while(window_Sum >= S){  // while loop
            min_length = min(min_length, window_End - window_Start + 1)
            window_Sum -= arr[window_Start]; //substract the element going out
            window_Start++; // slide the window ahead
        }
    }

    if(min_length == numeric_limits){ //if such sub array doesn't exists then return 0
        return 0;
    }
    else{
        return min_length;
    }
}

int main(
    cout<<"Smallest subarray length: "<<smallest_sub_array_with_given_sum(7, [2, 1, 5, 2, 3, 2])<< endl;
    cout<<"Smallest subarray length: "<<smallest_sub_array_with_given_sum(7, [2, 1, 5, 2, 8])<< endl;

)