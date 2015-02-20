#ifndef DIAGRAMMOVE_H
#define DIAGRAMMOVE_H

class DiagramMove {
public:
    // Constructors, destructors, operators
    DiagramMove(?);
    DiagramMove(const DiagramMove&);
    ~DiagramMove();
    DiagramMove& operator=(const Diagram&);
    
    // Parent
    const * Diagram getParent();
private:
    
};

#endif

