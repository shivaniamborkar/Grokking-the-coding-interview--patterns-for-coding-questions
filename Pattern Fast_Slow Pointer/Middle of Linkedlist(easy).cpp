/*
Problem Statement #
Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.

If the total number of nodes in the LinkedList is even, return the second middle node.

Example 1:

Input: 1 -> 2 -> 3 -> 4 -> 5 -> null
Output: 3

Example 2:

Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
Output: 4

Example 3:

Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null
Output: 4

We can use the Fast & Slow pointers method such that the fast pointer is always twice the nodes ahead of the slow pointer. This way, when the fast pointer reaches the end of the LinkedList, the slow pointer will be pointing at the middle node.


*/

//mycode

ListNode *find_Middle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
