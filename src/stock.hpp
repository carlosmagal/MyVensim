#ifndef STOCK_HPP
#define STOCK_HPP

#include"model.hpp"

using namespace std;

/*! Stock: a Stock that contains energy in it */
class Stock : public Model{
public:
//! <b>Energy setter</b>
    /*!
      Sets the value of the variable energy
    */
    virtual void setEnergy(float ) = 0;
//! <b>Energy getter</b>
    /*!
      Returns the value of the energy
    */
    virtual float getEnergy() = 0;

    virtual void run(int , int){}
};

#endif