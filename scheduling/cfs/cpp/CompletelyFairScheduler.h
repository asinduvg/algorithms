#ifndef COMPLETELYFAIRSCHEDULER_H
#define COMPLETELYFAIRSCHEDULER_H

#include "RedBlackTree.h"

class CompletelyFairScheduler {

private:
    int timeSlice;
    int cpuPower;
    int timer = 0;
    RBTree *rbTree = nullptr;

    void innerProcess();

    void updateProcessTree(Node *node);

public:
    CompletelyFairScheduler(int cpuPower);

    void addProcess(int burstTime);

    void start();

};

#endif
