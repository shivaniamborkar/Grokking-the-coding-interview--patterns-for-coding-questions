/*
Problem Statement #
Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.

 Example: 
 
 Following LinkedList has a cycle: head   1  
  2  
  3  
  4  
  5  
  6  
 Following LinkedList doesn't have a cycle: 
  2  
  4  
  6  
  8  
  10  
 */


class ListNode{
    int value = 0;
    ListNode *next;
    ListNode(){
        this->value = value;
        next = nullptr;
    }
}

bool has_cycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true; //found the cycle
        }
    }
    return false;
}