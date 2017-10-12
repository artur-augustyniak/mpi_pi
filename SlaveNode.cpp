/* 
 * File:   SlaveNode.cpp
 * Author: artur
 * 
 * Created on 3 listopad 2012, 15:27
 */
#include <iostream>
#include <stdlib.h>
#include "SlaveNode.h"
#include <time.h>
#include <cmath>
using namespace std;

SlaveNode::SlaveNode(int pPerNode, int nodeId) {
    this->pointsToCalculate = pPerNode;
    this->selfId = nodeId;
    //cout << pPerNode << " node nb: " << nodeId << endl;
}

SlaveNode::SlaveNode(const SlaveNode& orig) {
}

SlaveNode::~SlaveNode() {
}

int SlaveNode::getOutcome() {
    int i;
    int nk = 0;
    float x, y;
    
    int seed = time(NULL) + this->selfId*100;
    srand(seed);
    for (i = 1; i <= this->pointsToCalculate; i++) {
        x = (float) rand() / ((float) RAND_MAX / 2.0);
        y = (float) rand() / ((float) RAND_MAX / 2.0);
        if (sqrt((x - 1)*(x - 1) + (y - 1)*(y - 1)) <= 1) nk++;
    }
    cout << "Partial - for " << this->pointsToCalculate << " points " << nk << " was inside circle," << endl;
    return nk;

}

