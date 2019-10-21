#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

#include "../../src/system.hpp"
#include "../../src/flowImpl.hpp"
//#include "../../src/systemImpl.hpp"

#include <assert.h>

using namespace std;

void unit_System_constructor();
void unit_System_destructor();
void unit_System_addSystem();
void unit_System_addFlow();
void run_unit_tests_System();

#endif