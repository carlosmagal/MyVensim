#include"unit_system.hpp"

void unit_System_constructor( void){}

void unit_System_destructor( void){}

void unit_System_addSystem(){
    System *m = System::createSystem();
    Stock *s = m->createStock(10);
    
    m->add(s);
    assert(m->getVecStock(0)->getEnergy() == s->getEnergy());
}

void unit_System_addFlow(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    
    m->add(f);

    assert(m->getVecFlow(0)->getTarget() == f->getTarget());
}

void run_unit_tests_System(){
    unit_System_constructor();
    unit_System_destructor();
    unit_System_addSystem();
    unit_System_addFlow();
}