/*
#Problem Statement

Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both the baskets.

Example 1:

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

Example 2:

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
*/

// mycode

#include <unordered_map>

int fruits_into_baskets(char arr)
{
    int window_Start = 0;
    int max_length = 0;
    unordered_map<char, int> f;

    //try to extend the range [window_start, window_end]
    for (int window_End = 0; window_End < arr.size(); window_End++)
    {
        f[arr[window_End]]++;

        //shrink the sliding window, until we are left with '2' fruits in the fruit frequency map 
        while ((int)f.size() > 2)
        {
            f[arr[window_Start]]--;

            if (f[arr[window_Start]] == 0)
            {
                f.erase(arr[window_Start]);
            }
            window_Start++; // shrink the window
        }
        max_length = max(max_length, window_End - window_Start + 1);
    }
    return max_length;
}

int main()
{
    cout << "Maximum number of fruits: " << fruits_into_baskets([ 'A', 'B', 'C', 'A', 'C' ]);
}