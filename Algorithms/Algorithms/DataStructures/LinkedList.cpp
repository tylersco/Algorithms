//
//  LinkedList.cpp
//
//  Implementation of a doubly linked list class
//
//  Algorithms
//
//  Created by Tyler Scott on 7/10/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() {
    head = NULL;
}

//Search for an element in a linked list
ElementTypePtr LinkedList::ListSearch(int k) {
    ElementTypePtr temp = head;
    while(temp != NULL && temp->key != k)
        temp = temp->next;
    return temp;
}

//Insert an ElementTypePtr into the linked list at the head position
void LinkedList::ListInsert(ElementTypePtr x) {
    x->next = head;
    if(head != NULL)
        head->prev = x;
    head = x;
    x->prev = NULL;
}

//Delete an ElementTypePtr from the linked list
void LinkedList::ListDelete(ElementTypePtr x) {
    if(x->prev != NULL)
        x->prev->next = x->next;
    else
        head = x->next;
    if(x->next != NULL)
        x->next->prev = x->prev;
}

//Print the linked list
void LinkedList::Print() {
    ElementTypePtr temp = head;
    while(temp != NULL) {
        std::cout << temp->key << "->";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}


