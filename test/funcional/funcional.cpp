#include "funcional.hpp"

float FlowLog::equation(){//t3 equation
    float a = 0.01 * this->getTarget()->getEnergy();
    float a1 = 1 - ( this->getTarget()->getEnergy() / 70 );
    float a2 = a * a1;
    return a2;
}

float FlowExp::equation(){//t1-t2 equation
    float aux = (0.01 * this->getSource()->getEnergy());
    return aux;
}

void t3(){

    System *m = System::createSystem();
    System *m1 = System::createSystem();
	Flow *logistic = m->createFlow<FlowLog>();
	Stock *s1 = m->createStock(100); 
    Stock *s2 = m->createStock(10);

    logistic->connect(s1, s2);

    m1->addSystemToSystem(m);
    
	m1->execute();

	assert(fabs(s1->getEnergy() - 88.2167) < 0.0001);
	assert(fabs(s2->getEnergy() - 21.7833) < 0.0001);
    
    m->remove(logistic);
    m->remove(s1);
    m->remove(s2);
    delete m;
}

void t1(){

    System *m = System::createSystem();
    System *m1 = System::createSystem();
    Stock *s1 = m->createStock(100);
    Stock *s2 = m->createStock(0);
    Flow *f = m->createFlow<FlowExp>();

    f->connect(s1,s2);

    m1->addSystemToSystem(m);
    m1->execute();

    float test1 = fabs(36.6032 - s1->getEnergy());
    float test2 = fabs(63.3968 - s2->getEnergy());
    
    assert(test1 < 0.0001);
    assert(test2 < 0.0001);

    m->remove(s1);
    m->remove(s2);
    m->remove(f);
    delete m;
}


void t2(){

    System *m = System::createSystem();
    System *m1 = System::createSystem();

    Stock *s1 = m->createStock(100);
    Stock *s2 = m->createStock(0);
    Stock *s3 = m->createStock(100);
    Stock *s4 = m->createStock(0);
    Stock *s5 = m->createStock(0);

    Flow *u = m->createFlow<FlowExp>();
    Flow *g = m->createFlow<FlowExp>();
    Flow *f = m->createFlow<FlowExp>();
    Flow *t = m->createFlow<FlowExp>();
    Flow *r = m->createFlow<FlowExp>();
    Flow *v = m->createFlow<FlowExp>();

    v->connect(s4, s1);
    r->connect(s1,s2);
    t->connect(s3,s4);
    f->connect(s2,s3);
    g->connect(s2,s5);
    u->connect(s1,s3);
    
    m1->addSystemToSystem(m);
    m1->execute();

    float test1 = fabs(31.8513 - s1->getEnergy());
    float test2 = fabs(18.4003 - s2->getEnergy());
    float test3 = fabs(77.1143 - s3->getEnergy());
    float test4 = fabs(56.1728 - s4->getEnergy());
    float test5 = fabs(16.4612 - s5->getEnergy());

    assert(test1 < 0.0001);
    assert(test2 < 0.0001);
    assert(test3 < 0.0001);
    assert(test4 < 0.0001);
    assert(test5 < 0.0001);

    m->remove(s1);
    m->remove(s2);
    m->remove(s3);
    m->remove(s4);
    m->remove(s5);

    m->remove(u);
    m->remove(g);
    m->remove(f);
    m->remove(t);
    m->remove(r);
    m->remove(v);

    delete m;
}