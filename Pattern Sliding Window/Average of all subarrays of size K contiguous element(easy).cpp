/*

#Problem statement
    Given an array,
    find the average of all subarrays of ‘K’ contiguous elements in it.

    Example :

    Input : [ 1, 3, 2, 6, -1, 4, 1, 8, 2 ],
    K = 5 Output : [ 2.2, 2.8, 2.4, 3.6, 2.8 ]

*/

// mycode

int avg_sub_array_size_k(int k, arr)
{   double result(arr.size() - k+1);
    double windowSum = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd]; // add the next element
        // slide the window, we don't need to slide if we've not hit the required window size of 'k'
        if (windowEnd >= K - 1)
        {
            result[windowStart] = windowSum / K; // calculate the average
            windowSum -= arr[windowStart];       // subtract the element going out
            windowStart++;                       // slide the window ahead
        }
    }

    return result;
}