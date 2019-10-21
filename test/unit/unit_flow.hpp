#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP
#include"../../src/flowImpl.hpp"
//#include"../../src/systemImpl.hpp"
#include"../../src/system.hpp"
#include<assert.h>

void unit_Flow_constructor();
void unit_Flow_destructor();
void unit_Flow_setValue();
void unit_Flow_getValue();
void unit_Flow_setSource();
void unit_Flow_getSource();
void unit_Flow_setTarget();
void unit_Flow_getTarget();
void unit_Flow_connect();
void unit_Flow_isConnected();
void run_unit_tests_Flow();


#endif