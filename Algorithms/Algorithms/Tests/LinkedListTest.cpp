//
//  LinkedListTest.cpp
//  Algorithms
//
//  Created by Tyler Scott on 7/10/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    LinkedList list;
    
    ElementTypePtr e;
    for(int i = 1; i <= 5; i++) {
        e = new ElementType;
        e->key = i;
        list.ListInsert(e);
        list.Print();
    }
    
    e = new ElementType;
    e = list.ListSearch(3);
    list.ListDelete(e);
    
    e = list.ListSearch(1);
    list.ListDelete(e);
    
    list.Print();
    
    return 0;
}
