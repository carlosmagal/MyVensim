#include"unit_flow.hpp"


void unit_Flow_constructor(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    assert(f->getValue() == 0);
    assert(f->getTarget() == NULL);
    assert(f->getSource() == NULL);
}
void unit_Flow_destructor(){}

void unit_Flow_setValue(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    f->setValue(100);
    assert(f->getValue() == 100);
}

void unit_Flow_getValue(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    assert(f->getValue() == 0);
}

void unit_Flow_setSource(){
    System *m = System::createSystem();
    Stock *s = m->createStock(100);
    Flow *f = m->createFlow<FlowExp>();
    f->setSource(s);
    assert(f->getSource() == s);
}

void unit_Flow_getSource(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    assert(f->getSource() == NULL);
}

void unit_Flow_setTarget(){
    System *m = System::createSystem();
    Stock *s = m->createStock(100);
    Flow *f = m->createFlow<FlowExp>();
    f->setTarget(s);
    assert(f->getTarget() == s);
}
void unit_Flow_getTarget(){
    System *m = System::createSystem();
    Flow *f = m->createFlow<FlowExp>();
    assert(f->getTarget() == NULL);
}
void unit_Flow_connect(){
    System *m = System::createSystem();
    Stock *s1 = m->createStock(10);
    Stock *s2 = m->createStock(10);
    Flow *f = m->createFlow<FlowExp>();

    f->connect(s1,s2);

    assert(f->getSource() == s1);
    assert(f->getTarget() == s2);
}

void unit_Flow_isConnected(){
    System *m = System::createSystem();
    Stock *s1 = m->createStock(10);
    Stock *s2 = m->createStock(10);
    Flow *f = m->createFlow<FlowExp>();

    f->setSource(s1);
    f->setTarget(s2);
    assert(f->isConnected());
    
} 
void run_unit_tests_Flow(){

    unit_Flow_constructor();
    unit_Flow_setValue();
    unit_Flow_getValue();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_connect();
    unit_Flow_isConnected();
}
