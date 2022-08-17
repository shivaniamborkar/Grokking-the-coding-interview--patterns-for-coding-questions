/*
Problem Statement #
Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
one [1,5].

Example 2:

Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].
 
Example 3:

Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.
*/

//mycode

vector<Interval> merge(vector<Interval> &intervals){
    if(intervals.size()< 2)
        return intervals;

    //sort intervals by start time
    sort(intervals.begin(), intervals.end())

    vector<Interval> merged_intervals;

    vector<Interval>::const_iterator it = intervals.begin();
    Interval interval = *it++ ;
    int start = interval.start;
    int end = interval.end;

    while(it != intervals.end){
        interval = *it++ ;
        if(interval.start <= end){ //overlapping the intervals, adjust the end
            end = max(interval.end, end);
        }else{ //non-overlapping intervals, add the previous intervals and reset
            merged_intervals.push_back({start,end});
            start = interval.start;
            end = interval.end;
        }
    }
    //add the last interval
    merged_intervals.push_back({start, end});
    return merged_intervals;

}