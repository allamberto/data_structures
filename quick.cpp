// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
  if(numeric) { //compare by number
    qsort(l.head, node_number_compare);
  }
  else { //compare by string
    qsort(l.head, node_string_compare);
  }
}

Node *qsort(Node *head, CompareFunction compare) {
  Node *left = nullptr;
  Node *right = nullptr;
  if(head == nullptr){
    return head;
  }
  partition(head->next, head, left, right, void_string_compare);
  left = qsort(left, compare);
  right = qsort(right, compare);
  head->next = right;
  head = concatenate(left, right);
  return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
  Node *post = head;
  while(post != nullptr){
    if(compare(post, pivot)){
      left->next = post;
    else{
      right->next = post;
    }
    post = post->next;
    }
  }
}

Node *concatenate(Node *left, Node *right) {
  Node *join = left;
  while(left->next != nullptr){
    join = join->next;
  }
  join->next = right;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
