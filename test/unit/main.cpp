#include"unit_stock.hpp"
#include"unit_system.hpp"
#include"unit_flow.hpp"

using namespace std;
int main(){

    run_unit_tests_System();
    run_unit_tests_Stock();
    run_unit_tests_Flow();

    return 0;
}