/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

void split(Node*& in, Node*& odds, Node*& evens)
{
  // Base case
  if(in == nullptr){
    return;
  }
  else{
    // If value is even, we change the evens pointer to the 
    // in pointer, thus taking on the address of the first value
    // of the current iteration of the input list. The list is then 
    // iterated to the next value, while changing even's next pointer to null
    // in order to ensure no extra values from the original input list are 
    // left on the even's list at the end. 
    if(in -> value % 2 == 0){
      evens = in;
      in = in->next;
      evens-> next = nullptr;
      split(in, odds, evens->next);
    }
    // The same algorithm as explained above is used for the odd's list,
    // with the obvious change of checking if the current input "value" is odd.
    else{
      odds = in;
      in = in->next;
      odds->next = nullptr;
      split(in, odds->next, evens);
    } 
  }
}


