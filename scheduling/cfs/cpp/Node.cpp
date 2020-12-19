#include "Node.h"

int Node::processCount = 0;

Node::Node(int burstTime) {
    this->burstTime = burstTime;
    this->color = RED;
    virtualTime = 0;
    processID = processCount;
    processCount++;

    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}

Node::Node(const Node &source) {
    this->processID = source.processID;
    this->color = source.color;
    this->virtualTime = source.virtualTime;
    this->burstTime = source.burstTime;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    processCount++;
}


Node::~Node() {
    processCount--;
}

//int Node::getData() const {
//    return data;
//}
//
//void Node::setData(int data) {
//    Node::data = data;
//}

NodeColor Node::getColor() const {
    return color;
}

void Node::setColor(NodeColor color) {
    Node::color = color;
}

Node *Node::getLeftChild() const {
    return leftChild;
}

void Node::setLeftChild(Node *leftChild) {
    Node::leftChild = leftChild;
}

Node *Node::getRightChild() const {
    return rightChild;
}

void Node::setRightChild(Node *rightChild) {
    Node::rightChild = rightChild;
}

Node *Node::getParent() const {
    return parent;
}

void Node::setParent(Node *parent) {
    Node::parent = parent;
}

int Node::getBurstTime() const {
    return burstTime;
}

void Node::setBurstTime(int burstTime) {
    Node::burstTime = burstTime;
}

int Node::getProcessId() const {
    return processID;
}

void Node::setProcessId(int processId) {
    processID = processId;
}

int Node::getVirtualTime() const {
    return virtualTime;
}

void Node::setVirtualTime(int virtualTime) {
    Node::virtualTime += virtualTime;
}

int Node::getProcessCount() {
    return processCount;
}



