// lsort.h

#pragma once

#include <string>

// Structures ------------------------------------------------------------------

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(Node*, size_t); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s);	//define in list.cpp
};

// Type definitions ------------------------------------------------------------

typedef enum {	// this is only used in main.cpp
    MODE_STL,
    MODE_QSORT,
    MODE_MERGE,
    MODE_QUICK
} Mode;

typedef bool(*CompareFunction)(const Node *, const Node*); // notice the typedef

// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b); 	//define in node.cpp, used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b);		//define in node.cpp, used by quick, merge and stl
int  void_number_compare(const void *a, const void *b);		//define in node.cpp, used by qsort
int  void_string_compare(const void *a, const void *b);		//define in node.cpp, used by qsort
void dump_node(Node *n);					//define in node.cpp, also useful for debugging

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
