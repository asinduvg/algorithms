#include <iostream>
#include "CompletelyFairScheduler.h"

int main() {

    std::cout << "Enter cpu power : ";
    int cpuPower;
    std::cin >> cpuPower;
    auto *cfs = new CompletelyFairScheduler(cpuPower);

    std::cout << "Enter number of processes : ";
    int numberOfProcesses;
    std::cin >> numberOfProcesses;
    for (int i = 0; i < numberOfProcesses; i++) {
        int burstTime;
        std::cout << "Enter burst time of process : " << i << " -> ";
        std::cin >> burstTime;
        cfs->addProcess(burstTime);
    }

//    cfs->addProcess(3);
//    cfs->addProcess(20);
//    cfs->addProcess(4);
//    cfs->addProcess(10);
//    cfs->addProcess(8);
//    cfs->addProcess(1);

//    cfs->addProcess(8);
//    cfs->addProcess(4);
//    cfs->addProcess(16);
//    cfs->addProcess(4);

    cfs->start();


//    delete rbTree;
    return 0;
}

