#include "diagram.h"

namespace Diagram
{
    /*
     * Vertex implementation
     */
    Vertex::Vertex()
    : _forward(nullptr),_backward(nullptr) {}

    Vertex::~Vertex() {}

    Vertex * Vertex::forward() const
    { return _forward; }

    Vertex * Vertex::backward() const
    { return _backward; }

    bool Vertex::isCrossing() const
    { return false; }
    
    bool Ending::isEnding() const
    { return false; }
    
    void Vertex::setForward(Vertex * v)
    { _forward = v; }
    
    void Vertex::setBackward(Vertex * v)
    { _backward = v; }
    
    /*
     * Crossing implementation
     */
    Crossing::Crossing(bool up,bool pos)
    : _up(up),_positive(pos),_otherStrand(nullptr) 
    {
        _otherStrand = new Crossing(!up,pos,this);
    }
    
    Crossing::Crossing(bool up,bool pos,Vertex * other)
    : _up(up),_positive(pos),_otherStrand(other) {}
    
    Crossing::~Crossing() 
    {
        if(_otherStrand != nullptr)
        {
            _otherStrand->setOtherStrand(nullptr);
            delete _otherStrand;
        }
    }
        
    bool isCrossing() const
    { return true; }
    
    bool isUpStrand() const
    { return _up; }
    
    bool isDownStrand() const
    { return !_up; }
    
    bool isPositive() const
    { return _positive; }
    
    bool isNegative() const
    { return !_positive; }
    
    Vertex * otherStrand() const
    { return _otherStrand; }
    
    Vertex * upStrand() const
    {
        if(_up)
            return this;
        else
            return _otherStrand;
    }
    
    Vertex * downStrand() const
    {
        if(_up)
            return _otherStrand;
        else
            return this;
    }
    
    Vertex * upForward() const
    { return upStrand()->forward(); }
    
    Vertex * upBackward() const
    { return upStrand()->backward(); }
    
    Vertex * downForward() const
    { return downStrand()->forward(); }
    
    Vertex * downBackward() const
    { return downStrand()->backward(); }
    
    Vertex * left() const
    {
        if(_positive == _up)
            return _otherStrand->forward();
        else
            return _otherStrand->backward();
    }
    
    Vertex * right() const
    {
        if(_positive == _up)
            return _otherStrand->backward();
        else
            return _otherStrand->forward();
    }
    
    void setOtherStrand(Vertex * v)
    { _otherStrand = v; }
    
    /*
     * Ending implementation
     */
    Ending::Ending() {}
    
    Ending::~Ending() {}
    
    bool Ending::isEnding() const
    { return true; }
    
    bool Ending::isEmpty() const
    { return (forward() == nullptr) && (backward() == nullptr); }
    
    bool Ending::isStart() const
    { return (forward() != nullptr); }
    
    bool Ending::isEnd() const
    { return (backward() != nullptr); }
    
    bool setForward(Vertex * v)
    {
        Vertex::setForward(v);
        if(isEnd())
        {
            Vertex::setBackward(nullptr);
            return true;
        }
        else
            return false;
    }
    
    bool setBackward(Vertex * v)
    {
        Vertex::setBackward(v);
        if(isStart())
        {
            Vertex::setForward(nullptr);
            return true;
        }
        else
            return false;
    }

    Diagram(const DiagramCode& code) {
        
    }

}
