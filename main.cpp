/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on 30 październik 2012, 16:45
 */


//#include<mpi.h>

#include "Communicator.h"
#include "RootNode.h"
#include "SlaveNode.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {

    RootNode *srv;
    SlaveNode *cl;
    int pointsPerNodeCount = 0;
    int pointsInsideReduceSum = 0;
    int pointsInsideBuffer = 0;

    Communicator *c = new Communicator(&argc, argv, MPI_COMM_WORLD);
    //c->nodeSelfIdentify();
    if (c->getId() == 0) {
        srv = new RootNode();
        pointsPerNodeCount = srv->getPointsCount(c->getNodeCount());
    }

    c->bcastTasks(&pointsPerNodeCount);

    if (c->getId() != 0) {
        cl = new SlaveNode(pointsPerNodeCount, c->getId());
        pointsInsideBuffer = cl->getOutcome();
    };

    c->reduceTasks(&pointsInsideBuffer, &pointsInsideReduceSum);


    if (c->getId() == 0) {
        cout << srv->calculateOutcome(pointsInsideReduceSum) << endl;
    }
    
    delete c;
    return 0;
};

