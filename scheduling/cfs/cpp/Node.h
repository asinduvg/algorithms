#ifndef NODE_H
#define NODE_H

#include "NodeColor.h"
using namespace std;

class Node {
private:

    // RedBlack Tree Properties :

    NodeColor color;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
//    int data;

    // RedBlack Tree Properties //

    // Scheduler Properties :

    int virtualTime; // virtual_time
    int burstTime;
    int processID;
    static int processCount;

    // Scheduler Properties //

public:

    Node(int burstTime);

    ~Node();

    Node(const Node &source);

    int getData() const;

    void setData(int data);

    NodeColor getColor() const;

    void setColor(NodeColor color);

    Node *getLeftChild() const;

    void setLeftChild(Node *leftChild);

    Node *getRightChild() const;

    void setRightChild(Node *rightChild);

    Node *getParent() const;

    void setParent(Node *parent);

    int getBurstTime() const;

    void setBurstTime(int burstTime);

    int getProcessId() const;

    void setProcessId(int processId);

    int getVirtualTime() const;

    void setVirtualTime(int virtualTime);

    static int getProcessCount();
};


#endif
