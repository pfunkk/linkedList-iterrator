#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"

class LinkedList {
	friend std::ostream &operator <<(std::ostream &os, const LinkedList &linkedList);
    friend class iter;
private:
	int getSize() ;
      Node *head = new Node(999);
      Node *tail = new Node(888);
public:
    LinkedList();
	void insertFront(const EType &val);
    void insert(Node *curr, const EType &val);
	void firstInsert(const EType &val);
    EType removeNode(Node *p);
    bool removeNode(const EType &val);
	Node *find(const EType &val);
	bool empty();
	EType &front() const {return (head->next)->data;}
	EType &back() const {return (tail->prev)->data;}
	Node *frontP() const {return head->next;}
	Node *backP() const {return tail->prev;}
	int size (){return getSize();}
};
class iter{
public:
    iter(LinkedList &linkedList, Node *p);
    Node *iterBegin(){return curr;}
    Node *iterEnd(){return pp;}
    Node *curr;
    Node *pp;
};

#endif

