// merge.cpp

#include "lsort.h"
#include <vector>

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

void merge_sort(List &l, bool numeric) { //check whether to use numeric or string comparisons based on bool
    (numeric ? l.head = msort(l.head, node_number_compare) : l.head = msort(l.head, node_string_compare));
}

Node *msort(Node *head, CompareFunction compare) {
    Node *left = nullptr;
    Node *right = nullptr;
    if(head == nullptr || head->next == nullptr){ // handle base case
        return head;
    }
    split(head, left, right); //divide into two lists
    left = msort(left, compare); //sort
    right = msort(right, compare); //sort
    return merge(left, right, compare); //conquer
}


void split(Node *head, Node *&left, Node *&right) { // DIVIDE into left and right sublists
    Node *fast = head;
    Node *slow = head;
    if (head == nullptr || head->next == nullptr){ //base case
      left = head;
      right = nullptr;
    }
    else{
      while(fast->next != nullptr) {
        fast = fast->next; //fast checks two heads
        if(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;  // moves one node ahead at a time to reach half list
        }
      }
      left = head; //head of left list
      right = slow->next; //head of right list
      slow->next = nullptr; //disconnect the two lists
    }
}


// COMBINE left and right sublists, return new head of list
Node *merge(Node *left, Node *right, CompareFunction compare) {
    Node *hL = left;
    Node *hR = right;
    Node *head = nullptr;
    Node *curr = nullptr;

    if(compare(hL, hR)) { //initial compare to check which list has the head
      head = hL;
      hL = hL->next;
    }
    else {
      head = hR;
      hR = hR->next;
    }

    curr = head; //set head of new list

    while(hL && hR) { //continue looping until both lists reach an end
      if(compare(hL, hR)) { //if left is smaller add left
        curr->next = hL;
        hL = hL->next;
        curr = curr->next;
      }
      else { //if right is smaller add right
        curr->next = hR;
        hR = hR->next;
        curr = curr->next;
      }
    }
    if(hL != nullptr) { //check if hL didn't reach end of list in loop
      curr->next = hL;
    }
    else if(hR != nullptr) { //check if hR didn't reach end of list in loop
      curr->next = hR;
    }

    return head;
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
