//
//  main.cpp
//  iterlinked
//
//  Created by Piankhy Salomon on 3/1/16.
//  Copyright © 2016 Piankhy Salomon. All rights reserved.
//

#include <iostream>
#include "linked_list.h"
#include <cstdlib>


using namespace std;

int main()
{
    LinkedList *li = new LinkedList();
    cout<<boolalpha;
    
    cout << "Empty: " << li->empty() << endl;
    li->firstInsert(53);
    cout << *li << endl;
    cout << "Size: " << li->size() << endl;
    cout << "Empty: " << li->empty() << endl;
    cout<<li->front()<<" Front"<<endl;
    cout<<li->back()<<" Back"<<endl;
    
    li->insertFront(18);
    cout << *li << endl;
    cout << "Size: " << li->size() << endl;
    cout << "Empty: " << li->empty() << endl;
    cout<<li->front()<<" Front"<<endl;
    cout<<li->back()<<" Back"<<endl;
    
    li->insertFront(50);
    cout << *li << endl;
    cout << "Size: " << li->size() << endl;
    cout << "Empty: " << li->empty() << endl;
    cout<<li->front()<<" Front"<<endl;
    cout<<li->back()<<" Back"<<endl;
    
    Node *p = li->find(10);
    li->insert(p,3);
    cout << *li << endl;
    cout << "Size: " << li->size() << endl;
    cout << "Empty: " << li->empty() << endl;
    cout<<"Front:"<<li->front()<<endl;
    cout<<"Back:"<<li->back()<<endl;
    
    Node *pp = li->find(3);
    int x = li->removeNode(pp);
    bool y = li->removeNode(9);
    cout<<"Removed:(9)?"<<(y == false ? " Element not part of the list": " true")<<endl;
    cout<<"Removed:"<<"("<<x<<")?"<<" true"<<endl;
    cout << *li << endl;
    cout << "Size: " << li->size() << endl;
    cout << "Empty: " << li->empty() << endl;
    cout<<"Front:"<<li->front()<<endl;
    cout<<"Back:"<<li->back()<<endl;
    
    cout<<"---------------------Iteration--------------------"<<endl;
    iter itForward(*li,li->frontP());
    cout<<"{ ";
    for(itForward.curr = itForward.iterBegin(); itForward.curr->next!= itForward.iterEnd(); itForward.curr = itForward.curr->next)
        cout<<itForward.curr->data<<" ";
    cout<<"}"<<endl<<endl;
    cout<<*li<<endl;
    cout<<"{ ";
   
    iter itBackwards(*li,li->backP());
    for(itBackwards.curr = itBackwards.iterBegin(); itBackwards.curr->prev!= itBackwards.iterEnd(); itBackwards.curr = itBackwards.curr->prev)
        cout<<itBackwards.curr->data<<" ";
    cout<<"}"<<endl<<endl;
    cout<<*li<<endl;
    
    
    delete li;
    return 0;
}

