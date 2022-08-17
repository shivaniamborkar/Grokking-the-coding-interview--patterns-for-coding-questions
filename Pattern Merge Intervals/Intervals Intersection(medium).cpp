/*
Problem Statement #
Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.

Example 1:

Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.
Example 2:

Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists.
*/

//mycode

vector<Interval> merge(vector<Interval> &arr1, vector<Interval> &arr2){
    vector<Interval> result;

    int i=0, j = 0;
    while(i < arr1.size() && jj < arr2.size()){
        //checkk if the interval arr1[i] intersects with arr2[j]
        //check if the one of the interval's start time  lies within the other interval
        if((arr1[i].start >= arr2[j].start && arr1[i].start <= arr2[j].end) || (arr2[j].start >= arr1[i].start && arr2[j].start <= arr1[i].end)){
            //store the intersection part
            result.push_back({max(arr1[i].start, arr2[j].start), min(arr1[i].end, arr2[j].end)});
        }
        //move next from the interval which is finishing first
        if(arr1[i].end < arr2[j].end){
            i++;
        }else{
            j++;
        }

    }
    return result;
}