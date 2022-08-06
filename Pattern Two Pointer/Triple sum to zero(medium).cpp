/*
Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.

Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
*/

vector<vector<int>> search_triplets(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        if (i > 0; arr[i] == arr[i - 1])
        { // skip same elements to avoid duplicate triple
            continue;
        }
        search_pair(arr, -arr[i], i + 1, triplets);
    }
    return triplets;
}

search_pair(int arr, int target_sum, int left, vector<vector<int>> triplets)
{
    int right = arr.size() - 1;
    while (left < right)
    {
        int current_sum = arr[left] + arr[right];
        if (current_same == target_sum)
        { // found the pair
            triplets.push_back({-target_sum, arr[left], arr[right]})
                left++;
            right--;

            while (left < right && arr[left] == arr[left - 1])
            {
                left++; // skip same elements to avoid duplicates
            }
            while (left < right && arr[right] == arr[right - 1])
            {
                right--; // skip same elements to avoid duplicates
            }
        }
        else if (target_sum > current_sum)
        {
            left++; // we need a pair with bigger sum
        }
        else
        {
            right--; // we need a pair with smaller sum
        }
    }
}
