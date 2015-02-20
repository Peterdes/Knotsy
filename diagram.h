#ifndef DIAGRAM_H
#define DIAGRAM_H
#include <vector>
#include <list>
#include "diagramcode.h"
#include "diagrammove.h"

class Diagram 
{
public:
    // Constructors, destructors, operators
    Diagram(const DiagramCode&);
    ~Diagram();
    Diagram& operator=(const Diagram&);
    const bool operator==(const Diagram&);
    
    // Gives diagram code
    const DiagramCode getCode();
    
    // Lists possible moves
    const std::array<DiagramMove> getMoves();
    
    // Returns a copy of diagram after a move
    const Diagram makeMove(const DiagramMove&);
    
private:
    class Vertex 
    {
    public:
        Vertex();
        ~Vertex();
        
        Vertex * forward() const;
        Vertex * backward() const;
        virtual void setForward(Vertex*);
        virtual void setBackward(Vertex*);
        virtual bool isCrossing() const;
        virtual bool isEnding() const;
        
    private:
        Vertex(const Vertex&);
        Vertex& operator=(const Vertex&);
        
        Vertex * _forward;
        Vertex * _backward;
    };
    class Crossing : public Vertex 
    {
    public:
        // construct THIS and OTHER strand
        Crossing(bool upper,bool positive);
        ~Crossing();
        
        Vertex * left() const;
        Vertex * right() const;
        Vertex * upForward() const;
        Vertex * upBackward() const;
        Vertex * downForward() const;
        Vertex * downBackward() const;
        Vertex * upStrand() const;
        Vertex * downStrand() const;
        Vertex * otherStrand() const;
        
        bool isUpStrand() const;
        bool isDownStrand() const;
        bool isPositive() const;
        bool isNegative() const;
        bool isCrossing() const;
        
    private:
        Crossing(const Crossing&);
        Crossing& operator=(const Crossing&);
        
        // ALLOW
        Crossing(bool,bool,Vertex *);
        
        void setOtherStrand(Vertex *) const;
        
        Vertex * _otherStrand;
        bool _positive;
        bool _up;
    };
    class Ending : public Vertex 
    {
    public:
        Ending();
        ~Ending();
        
        bool isEmpty() const;
        bool isStart() const;
        bool isEnd() const;
        bool setForward(Vertex *);
        bool setBackward(Vertex *);
        bool isEnding() const;
        
    private:
        Ending(const Ending&);
        Ending& operator=(const Ending&);
    };
    // No empty diagram allowed
    Diagram();
    
    // Diagram vertices
    std::list<Vertex *> _vertices;
};

#endif

