/*
Problem Statement #
Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Example 1:

Input: 23   
Output: true (23 is a happy number)  
Explanations: Here are the steps to find out that 23 is a happy number:
2^2 + 3 ^22
​2
​​ +3
​2
​​  = 4 + 9 = 13
1^2 + 3^21
​2
​​ +3
​2
​​  = 1 + 9 = 10
1^2 + 0^21
​2
​​ +0
​2
​​  = 1 + 0 = 1
*/

//mycode

bool find(int num){
    int slow = num, fast = num;
    do{
        slow = find_sum_square(slow); //move one step
        fast = find_sum_square(find_sum_square(fast)); //move two steps
    }while(slow != fast); //found the cycle

    return slow == 1; //see if the cycle stuck on number 1
}

int find_sum_square(int num){
    int sum = 0, digit;
    while(num > 0){
        digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}