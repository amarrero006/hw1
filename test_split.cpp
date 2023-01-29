/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
    Node one(1, nullptr);
    Node two(2, nullptr);
    Node three(3, nullptr);
    Node four(4, nullptr);

    Node* in;

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = nullptr;

    Node* evens = nullptr;
    Node* odds = nullptr;
    in = &one;


    Node* head1;
    Node* head2;
    Node* head3;

    head1 = odds;
    head2 = evens;
    head3 = in;

    cout << "In list: ";
    while(head3 != nullptr){
        cout << head3->value;
        head3 = head3-> next;
    }
    cout << endl;

    cout << "Splitting..." << endl; 
    split(in, odds, evens);

    head1 = odds;
    head2 = evens;
    head3 = in;


    cout << "Odds list: ";
    while(head1 != nullptr){
        cout << head1->value;
        head1 = head1-> next;
    }
    cout << endl << "Evens list: ";
    while(head2 != nullptr){
        cout << head2->value;
        head2 = head2-> next;
    }
    cout<< endl; 

    cout << "Updated list (should be empty): ";
    while(head3 != nullptr){
        cout << head3->value;
        head3 = head3-> next;
    }
    cout << endl;
   
return 0;
}
