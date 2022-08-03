/*
#Problem Statement
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

*/

//mycode
#include<String>
#include<unordered_map>

int longest_sub_string_with_K_distinct_char(str string, int k){
    int max_length = 0;
    int window_Start = 0;
    unordered_map<char, int> m;

    for(int window_End= 0; window_End < str.length(); window_End++){
        char right_char = str[window_End];
        m[right_char]++ ;

        while((int)m.size() > k){
            char left_char = str[window_Start];
            m[left_char]-- ;

            if(m[left_char] == 0){
                m.erade(left_char);
            }
            window_Start++ //shrink the window
        }
        max_length = max(max_length, window_End - window_Start + 1);
    }
    return max_length;
};

int main(){
    cout<< "Length of Longest Substring: "<< longest_sub_string_with_K_distinct_char("araaci", 2)<< endl;

}
