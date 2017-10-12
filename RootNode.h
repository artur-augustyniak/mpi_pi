/* 
 * File:   RootNode.h
 * Author: artur
 *
 * Created on 3 listopad 2012, 15:27
 */

#ifndef ROOTNODE_H
#define	ROOTNODE_H

class RootNode {
public:
    RootNode();
    RootNode(const RootNode& orig);
    virtual ~RootNode();
    int getPointsCount(int nodeCount);
    double calculateOutcome(int insidePointsCount);
private:
    int pointsCount;

};

#endif	/* ROOTNODE_H */

