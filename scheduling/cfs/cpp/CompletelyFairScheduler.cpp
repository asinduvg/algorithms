#include "CompletelyFairScheduler.h"
#include <iostream>

using namespace std;

CompletelyFairScheduler::CompletelyFairScheduler(int cpuPower) {
    this->cpuPower = cpuPower;
    this->rbTree = new RBTree();
}

void CompletelyFairScheduler::addProcess(int burstTime) {
    rbTree->insert(burstTime);
}

void CompletelyFairScheduler::start() {
    Node *pCount;
//    cout << "P count - " << pCount->getProcessCount() << endl;
    cout << "Time  " << "Process_id  " << "  Status  " << endl;

    while (rbTree->getRoot() != nullptr) {
        innerProcess();
    }

//    rbTree->traverse();
    cout << "Total time taken : " << timer << endl;
    delete rbTree;
}

void CompletelyFairScheduler::innerProcess() {

//    cout << rbTree->getLeftMost()->getData() << endl;
    Node *leftMost = rbTree->getLeftMost();
    int processID = leftMost->getProcessId();
    int burstTime = leftMost->getBurstTime();
    int virtualTime = leftMost->getVirtualTime();
    int processCount = leftMost->getProcessCount();

    timeSlice = cpuPower / processCount;


    if (virtualTime < burstTime) {
//        cout << "Process ID : " << processID << " has run only " << virtualTime << " time units" << endl;
        int remainTime = burstTime - virtualTime;
        if (remainTime <= timeSlice) {

            for (int i = 0; i < remainTime - 1; i++) {
                cout << timer << "   " << "Process_id :" << processID << " - running" << endl;
                timer++;
            }

            leftMost->setVirtualTime(remainTime);
            virtualTime = leftMost->getVirtualTime();
        } else {
            for (int i = 0; i < timeSlice - 1; i++) {
                cout << timer << "   " << "Process_id :" << processID << " - running" << endl;
                timer++;
            }
            cout << timer << "   " << "Process_id :" << processID << " - preempted" << endl;
            leftMost->setVirtualTime(timeSlice);
            virtualTime = leftMost->getVirtualTime();
//            cout << "Process ID : " << processID << " has to run " << remainTime - timeSlice << " time units" << endl;

            Node *process = new Node(*leftMost);
//            process->setRightChild(nullptr);
//            process->setLeftChild(nullptr);

            rbTree->deleteNode(leftMost);
            updateProcessTree(process);
        }

        if (burstTime == virtualTime) {
//            cout << "Process ID : " << processID << " completed with " << burstTime << " burst time" << endl;
            cout << timer << "   " << "Process_id :" << processID << " - completed" << endl;
            rbTree->deleteNode(leftMost);
        }
    }
    timer++;
}

void CompletelyFairScheduler::updateProcessTree(Node *node) {
    rbTree->insert(node);
}

