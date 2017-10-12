/* 
 * File:   SlaveNode.h
 * Author: artur
 *
 * Created on 3 listopad 2012, 15:27
 */

#ifndef SLAVENODE_H
#define	SLAVENODE_H

class SlaveNode {
public:
    SlaveNode(int pPerNode, int nodeId);
    SlaveNode(const SlaveNode& orig);
    virtual ~SlaveNode();
    int getOutcome();
private:
    int pointsToCalculate;
    int selfId;

};

#endif	/* SLAVENODE_H */

