#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include"flow.hpp"
using namespace std;
/*! System: abstract class about to be implemented */
class System : public Model{
public:   
//! <b>Flow adding</b>
    /*!
      Adds a flow to the System
    */
    virtual void add(Flow* f) = 0;
//! <b>Stock adding</b>
    /*!
      Adds a Stock to the System
    */
    virtual void add(Stock* s) = 0;
//! <b>Running the System</b>
    /*!
      The function that contains the main algorithm of the simulation
    */
    virtual void run(int, int){}
//! <b>Stock container getter</b>
    /*!
     Receives a position of the vector as a parameter, and returns the Stock placed in that position
    */
    virtual Stock* getVecStock(int position) = 0;

//! <b>Flow container getter</b>
    /*!
        Receives a position of the vector as a parameter, and returns the flow placed in that position
    */
    virtual Flow* getVecFlow(int position) = 0;

    virtual Stock* createStock(float energy) = 0;

    template <typename TypeFlow>
    Flow* createFlow(){
      Flow *flow = new TypeFlow;
      add(flow);
      return flow;    
    }
    //virtual Flow* createFlowLog() = 0;
    //virtual Flow* createFlowExp() = 0; 
    static System* createSystem();
    virtual void remove(Stock*) = 0;
    virtual void remove(Flow*) = 0;

    virtual void execute()=0;
//! <b>sub-System adding</b>
    /*!
      Adds a sub-System to the System
    */
    virtual void addSystemToSystem(System *s) = 0;
};

#endif