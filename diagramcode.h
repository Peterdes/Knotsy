#ifndef DIAGRAMCODE_H
#define DIAGRAMCODE_H
#include <vector>
#include <tuple>

template<int A, int B>
class DiagramCode {
public:
    DiagramCode();
    DiagramCode(const DiagramCode&);
    ~DiagramCode();
    DiagramCode& operator=(const DiagramCode&);
    const bool operator==(const DiagramCode&);
    
    // Number of crossings
    int crossings();
    // Number of ends
    int ends();
    
    // Descriptions of strands
    std::vector< std::tuple<int,
        std::vector<int>.std::vector<bool>,std::vector<bool>,int> >
            strands();
    
private:
    
    // Sets bits
    void setBits(int n,int len,unsigned int mask);
    
    // Reads bits
    unsigned int readBits(int n,int len);    
    
    // Real data
    std::vector<bool> _code;
}

#endif
