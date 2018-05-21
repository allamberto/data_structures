// list.cpp

#include "lsort.h"
using namespace std;

#include <memory>

List::List(Node *h, size_t s) { //constructor
  head = h;
  size = s;
}

List::~List() { //deconstructor
  Node *n = head;
  if(head != nullptr){
    delete head;
    head = n->next;
  }
}

void List::push_front(const std::string &s) {
  Node *n;
  n->string = s;
  n->number = stoi(s);
  n->next = head;
  head = n;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
