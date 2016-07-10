//
//  LinkedList.hpp
//
//  Header file for a doubly linked list class
//
//  Algorithms
//
//  Created by Tyler Scott on 7/10/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>

//Structure for the elements in the linked list
struct ElementType {
    int key;
    ElementType *next;
    ElementType *prev;
};

typedef ElementType * ElementTypePtr;

//Linked list class
class LinkedList {
public:
    ElementTypePtr head;
    LinkedList();   //Constructor
    ElementTypePtr ListSearch(int);    //Search the linked list
    void ListInsert(ElementTypePtr); //Insert into the linked list
    void ListDelete(ElementTypePtr); //Delete from the linked list
    void Print();    //Print the linked list
};

#endif /* LinkedList_hpp */
