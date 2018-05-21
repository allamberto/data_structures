// node.cpp

#include "lsort.h"

#include <iostream>
using namespace std;

bool node_number_compare(const Node *a, const Node *b) {
    return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
  return a->string.compare(b->string);
}

int void_number_compare(const void *a, const void *b) {
  Node *na = *(Node **)a;
  Node *nb = *(Node **)b;
  return na->number < nb->number;
}

int void_string_compare(const void *a, const void *b) {
    Node *na = *(Node **)a;
    Node *nb = *(Node **)b;
    return na->string.compare(nb->string);
}

void dump_node(Node *n) {
  Node *track = n;
  while(track != nullptr) {
    cout << "s: " << track->string << " n: " << track->number << endl;
    track = track->next;
  }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
