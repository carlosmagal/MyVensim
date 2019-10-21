#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "system.hpp"
#include"handlebody.hpp"
#include"stockImpl.hpp"
#include"flowImpl.hpp"
//#include "StockImpl.hpp"
//#include "flowImpl.hpp"
class FlowExp;
using namespace std;

class SystemBody : public Body{
public:
    SystemBody():Body(){}
    virtual ~SystemBody(){}

    void add(Flow* f);
    void add(Stock* s);
    void run(int, int);
    Stock* getVecStock(int position);
    Flow* getVecFlow(int position);

    //Factories
    static System* createSystem();
    Stock* createStock(float energy);
    //Flow* createFlowExp();
    //Flow* createFlowLog();
    void remove(Flow*);
    void remove(Stock *);

    void addSystemToSystem(System *s);
    void execute();
protected:
    vector<Stock*> vecStock;/**< container which acumulates the Stocks of the System  */
    vector<Flow*> vecFlow;/**< container which acumulates the flows of the System  */

    vector<System*> systemContainer;
private:
    SystemBody* operator=(SystemBody *m);

};

class SystemHandle : public System, public Handle<SystemBody>{
public:
    SystemHandle(){
        pImpl_ = new SystemBody();
        pImpl_->attach();
    }

    virtual ~SystemHandle(){
        pImpl_->detach();
    }

    void add(Flow* f){pImpl_->add(f);}
    void add(Stock* s){pImpl_->add(s);}
    void run(int a, int b){pImpl_->run(a,b);}
    Stock* getVecStock(int position){return pImpl_->getVecStock(position);}
    Flow* getVecFlow(int position){return pImpl_->getVecFlow(position);}

    //Factories
    static System* createSystem(){return SystemBody::createSystem();}
    Stock* createStock(float energy){return pImpl_->createStock(energy);}
    //Flow* createFlowExp(){return pImpl_->createFlowExp();}
    //Flow* createFlowLog(){return pImpl_->createFlowLog();}
    void remove(Flow* f){pImpl_->remove(f);}
    void remove(Stock *s){pImpl_->remove(s);}

    void execute(){pImpl_->execute();}

    void addSystemToSystem(System *s){pImpl_->addSystemToSystem(s);}
};

#endif