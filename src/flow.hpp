#ifndef FLOW_HPP
#define FLOW_HPP

#include <iostream>
//#include"model.hpp"
using namespace std;
//class Stock;
#include"stock.hpp"
/*! Flow: What connects the Stocks. Is controlled by a equation */
class Flow : public Model{
public:
//! <b>Checking function</b>
    /*!
      Returns \c true if the flow is connected to something
    */
    virtual bool isConnected() = 0;
//! <b>Source setter</b>
    /*!
      Sets the source of the flow
      Receives a Stock as a parameter
    */
    virtual void setSource(Stock* s) = 0;
//! <b>Source getter</b>
    /*!
      Returns the source of the flow
    */
    virtual Stock* getSource() = 0;
//! <b>Target setter</b>
    /*!
      Sets the target of the Stock
    */
    virtual void setTarget(Stock* s1) = 0;
//! <b>Target getter</b>
    /*!
      Returns the target of the Stock
    */
    virtual Stock* getTarget() = 0;
//! <b>Connecting funcion</b>
    /*!
      Connects the source and the target to a flow,
      \c s1 is gonna be the \c source and \c s2 the \c target
    */
    virtual void connect(Stock *s1, Stock *s2) = 0;
//! <b>Equation</b>
    /*!
      The equation responsible of creating the flow between the Stocks
    */
    virtual float equation() = 0;

//! <b>Value getter</b>
    /*!
      Returns the content of the variable value
    */
    virtual double getValue() = 0;

//! <b>Value setter</b>
    /*!
      Sets the variable value
    */
    virtual void setValue(double) = 0;

    virtual void run(int, int){}
};

#endif