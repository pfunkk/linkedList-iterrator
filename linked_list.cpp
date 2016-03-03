#include <iostream>
#include "linked_list.h"


using namespace std;

class LinkedList;

ostream &operator <<(ostream &os, const LinkedList &linkedList) {
	Node *p = linkedList.head->next;
	os << "{";
	while(p){
		os << "...["<<"p#:"<<p->prev<<" | "<<p->data << " | n#:" << p->next << "]...";
		p = p->next;
		if(p==linkedList.tail)
            break;
	}
	os << "}";
	return os;
}
LinkedList::LinkedList(){
    head->next = tail;
    head->prev = tail;
    tail->prev = head;
    tail->next = head;
}
void LinkedList::insert(Node *curr,const EType &val){
	Node *newNode = new Node(val, curr, curr->prev);
	Node *prev = curr->prev;
	curr->prev = newNode;
	prev->next = newNode;
}
void LinkedList::insertFront(const EType &val) {
    Node *nodeP = new Node(val,head->next,head);
    head->next = nodeP;
    Node *nextNode = nodeP->next;
    nextNode->prev = nodeP;
}
void LinkedList::firstInsert(const EType &val){
    Node *nodeP = new Node(val,tail,head);
    head->next = nodeP;
    tail->prev = nodeP;
}
EType LinkedList::removeNode(Node *p){
    EType removedVal = p->data;
    Node *nextNode = p->next;
    Node *prevNode = p->prev;
    nextNode->prev = p->prev;
    prevNode->next = p->next;
    return removedVal;

}
bool LinkedList::removeNode(const EType &val){
    Node *p = head->next;
    while(p){
        if(p->data == val){
            removeNode(p);
            return true;
        }
        p = p->next;
        if(p == tail)
            return false;
    }
    return false;
}

Node *LinkedList::find(const EType &val) {
    Node *p = new Node (0,head,0);
    while(p){
        if (p->data == val)
            return p;
        else if(p->next == tail)
                break;
            p = p->next;
    }
    if(p->next == tail)
        insert(p,val);
    Node *pp = find(val);
    return pp;
}
int LinkedList::getSize()  {
    Node *p = head;
    int counter = 0;
    while(p){
        if((p ->next)== tail)
            return counter;
        p = p->next;
        counter++;
    }
    return counter;
}
bool LinkedList::empty(){
    if(size() == 0)return true;
    return false;
}
iter::iter(LinkedList &linkedList, Node *p){
    try{
        if(p != linkedList.head->next && p != linkedList.tail->prev ) throw "Exception: You can only pass the head or tail pointer";
        else {
            curr = p;
            if(linkedList.head->next == p){
                pp = linkedList.tail->next;
            }
            else if(linkedList.tail->prev == p){
                pp = linkedList.head->prev;
            }
        }
    }catch(const char* e){std::cout<<e<<endl;}
}

