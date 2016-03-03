#ifndef NODE_H
#define NODE_H

#include <iostream>

typedef int EType;

struct Node {
	Node(const EType &data, Node *next=0, Node *prev=0) : data(data), next(next), prev(prev) {}
	EType data;
	Node *next;
	Node *prev;
};

#endif // NODE_H


