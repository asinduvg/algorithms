#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include "Node.h"

class TreeInterface {
public:
    TreeInterface(){};
    virtual void traverse() = 0;
    virtual void insert(int data) = 0;
    virtual Node *findNode(Node *temp, int data) = 0;
//    virtual void deleteNode(int data) = 0;
};

#endif
