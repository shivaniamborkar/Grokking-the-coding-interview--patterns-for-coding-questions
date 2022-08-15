/*
Problem Statement #
Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.

 head 
  1  
  2  
  3  
  4  
  5  
  6  
 Cycle start 

 Examples: 
 Cycle start 
  1  
  2  
  3  
  4  
  5  
  6  
 
  1  
  2  
  3  
  4  
  5  
  6  
 head 
 head 
 Cycle start 
*/

ListNode *find_cycle_start(ListNode *head){
    int cycleLength = 0;
    //find the cycle
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){ //found the cycle
            cycleLength = calculate_cycle_length(slow);
            break;
        }
    }
    return find_Start(head, cycleLength);

}

int calculate_cycle_length(ListNode *slow){
    Listnode *current = slow;
    int cycleLength = 0;
    do{
        current = current->next;
        cycleLength++;
    }while(current != slow){
        return cycleLength;
    }
}

ListNode *find_Start(ListNode *head, int cycleLength){
    ListNode *pointer1 = head, *pointer2 = head;
    //move pointer2 ahead of cycleLength nodes
    while(cycleLength > 0){
        pointer2 = pointer2->next;
        cycleLength--;
    }

    //increament both pointers until they meet at the start of the cycle
    while(pointer1 != pointer2){
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    return pointer1;
}