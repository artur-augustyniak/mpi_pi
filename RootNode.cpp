/* 
 * File:   RootNode.cpp
 * Author: artur
 * 
 * Created on 3 listopad 2012, 15:27
 */
#include <iostream>
#include "RootNode.h"
using namespace std;

RootNode::RootNode() {
    cout << "Points to check [int]: ";
    cin >> this->pointsCount;
}

RootNode::RootNode(const RootNode& orig) {
}

RootNode::~RootNode() {
}

int RootNode::getPointsCount(int nodeCount) {

    int effectiveNodes = nodeCount - 1;
    int pointsPerNode;
    if (this->pointsCount > nodeCount) {
        pointsPerNode = this->pointsCount / effectiveNodes;
    } else {
        pointsPerNode = 1;
    }
    return pointsPerNode;

}

double RootNode::calculateOutcome(int insidePointsCount){
        
    return 4.0 * (float)insidePointsCount / (float)this->pointsCount;
}

