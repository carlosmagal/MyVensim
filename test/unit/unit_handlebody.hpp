#ifndef UNIT_HANDLEBODY_HPP
#define UNIT_HANDLEBODY_HPP

#include"../../src/handlebody.hpp"
#include"../../src/stockImpl.hpp"

void unit_handlebody_detach(){
    Stock *h = new StockHandle;
    Stock *h1 = new StockHandle;

    *h=*h1;
}

#endif