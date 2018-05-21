// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <array>
#include <iostream>

void stl_sort(List &l, bool numeric) {
  Node** d = new Node*[l.size];
  auto compare = (numeric ? void_number_compare : void_string_compare);
  size_t i = 0;

  // Store nodes in array
  for (auto curr = l.head; curr != nullptr; curr = curr->next) {
    d[i++] = curr;
  }

  // Sort array
  sort(d, l.size, sizeof(Node *), compare);

  // Relink nodes
  for (size_t i = 0; i < l.size; i++) {
      d[i]->next = (i + 1 < l.size ? d[i + 1] : nullptr);
  }
  l.head = d[0];

  delete [] d;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
