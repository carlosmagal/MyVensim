#include "unit_stock.hpp"

void unit_Stock_constructor( void){
    System *m = System::createSystem();
    Stock *s1 = m->createStock(0);
    assert( s1->getEnergy() == 0 );
    Stock *s2 = m->createStock(10);
    assert( s2->getEnergy() == 10 );
}

void unit_Stock_destructor( void){};

void unit_Stock_getEnergy( void){
    System *m = System::createSystem();
    Stock *s = m->createStock(10);
    assert( s->getEnergy() == 10 );
}

void unit_Stock_setEnergy( void ) {
    System *m = System::createSystem();
    Stock *s = m->createStock(0);
    s->setEnergy(100);
    assert( s->getEnergy() == 100 );
}

void unit_Stock_opertorequals(){
    System *m = System::createSystem();
    Stock *s1 = m->createStock(10);
    Stock *s2 = m->createStock(0);
    s1=s2;
    assert( s1->getEnergy() == s2->getEnergy() );
}




void unit_Stock_constructor2(){
    System *m = System::createSystem();
    Stock *s = m->createStock(100);
    //assert(numBodyCreated == 1);
}

void run_unit_tests_Stock( void ){
    unit_Stock_constructor();
    unit_Stock_destructor();
    unit_Stock_getEnergy();
    unit_Stock_setEnergy();
    unit_Stock_opertorequals();
    //unit_System_constructor2();
}
