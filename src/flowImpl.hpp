#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include"flow.hpp"
#include"handlebody.hpp"
using namespace std;

class FlowBody : public Body{
public:
    FlowBody();
    ~FlowBody();
    bool isConnected();
    void setSource(Stock* s);
    Stock* getSource();
    void setTarget(Stock* s1);
    Stock* getTarget();
    void connect(Stock *s1, Stock *s2);
    virtual float equation(){ return 0;}
    double getValue();
    void setValue(double);

    void run(int a, int b){}

protected:
    Stock *target;/**< Where the energy goes to*/
    Stock *source;/**< Where the energy comes from*/
    double value;
private:
    FlowBody* operator=(FlowBody* s);
};

class FlowHandle : public Flow, public Handle<FlowBody>{
public:
    FlowHandle(){
        setTarget(NULL);
        setSource(NULL);
        setValue(0);
    }
    virtual ~FlowHandle(){}

    bool isConnected(){return pImpl_->isConnected();}
    void setSource(Stock* s){pImpl_->setSource(s);}
    Stock* getSource(){return pImpl_->getSource();}
    void setTarget(Stock* s1){ pImpl_->setTarget(s1);}
    Stock* getTarget(){return pImpl_->getTarget();}
    void connect(Stock *s1, Stock *s2){pImpl_->connect(s1,s2);}
    virtual float equation(){ return 0;}
    double getValue(){return pImpl_->getValue();}
    void setValue(double value){pImpl_->setValue(value);}

    void run(int a, int b){pImpl_->run(a,b);}
};


class FlowLog : public FlowHandle{
    float equation();
};
class FlowExp : public FlowHandle{
    float equation();
};

#endif