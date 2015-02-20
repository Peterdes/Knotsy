#ifndef DIAGRAMCODE_H
#define DIAGRAMCODE_H
#include <bitset>

class DiagramCode {
public:
    // Constructors, destructors, operators
    DiagramCode(int);
    DiagramCode(const DiagramCode&);
    ~DiagramCode();
    const bool operator==(const DiagramCode&);
    
    // Sets bits
    void setBits(int n,int len,int mask);
    void setBit(int n,int bit);
    void setBit(int n,bool bit);
    
    // Reads bits
    bool readBit(int n);
    int readBits(int n,int len);
    
private:
    // Need to have length
    DiagramCode();
    DiagramCode& operator=(const DiagramCode&);
}

#endif
