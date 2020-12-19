#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "TreeInterface.h"
#include "Node.h"

class RBTree : public TreeInterface {
private:
    Node *root;

    Node *insertIntoTree(Node *travelNode, Node *newNode);

    void inOrderTraverse(Node *travelNode);

    void rightRotate(Node *baseNode);

    void leftRotate(Node *baseNode);

    void fixViolation(Node *node);

    Node *inOrderSuccessor(Node *node);

    Node *selectNodeToDelete(Node *node);

    void deleteFixUp(Node *node, bool isLeft);

    Node *leftMostNode(Node *node);

public:
    Node *getRoot() const;
//    RBTree(int timeSlice);

    void insert(int data) override;

    void traverse() override;

    Node *findNode(Node *temp, int data) override;

//    void deleteNode(int data) override;

    void deleteNode(Node *node);

    Node *getLeftMost();

    void insert(Node *node);

};

#endif
