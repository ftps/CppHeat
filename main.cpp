#include "heat.hpp"
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    // VERIFICATION #1: 1d problem

    // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=1
    // (numerical vs. exact solution comparison)
    
    Vector<double> aux1, aux2;
    Heat<1,double> Heat1d_test1(0.3125, 0.001, 99);

    aux1 = Heat1d_test1.exact(1.0);
    //std::cout << aux1 << std::endl;
    aux2 = Heat1d_test1.solve(1.0);
    //std::cout << aux2 << std::endl;

    // Test 2 -> alpha=0.3125, dt=0.1, m=3
    // (verify matrix M assembly)
    Heat<1,double> Heat1d_test2(0.3125, 0.1, 3);
    std::cout << Heat1d_test2.getMatrix() << std::endl;



    // VERIFICATION #2: 2d problem

    // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=0.5
    // (numerical vs. exact solution comparison)
    Vector<double> aux3, aux4;
    Heat<2,double> Heat2d_test1(0.3125, 0.001, 99);

    aux3 = Heat2d_test1.exact(0.5);
    //std::cout << aux3 << std::endl;
    aux4 = Heat2d_test1.solve(0.5);
    //std::cout << aux4 << std::endl;

    // Test 2 -> alpha=0.3125, dt=0.1, m=3
    // (verify matrix M assembly)
    Heat<2,double> Heat2d_test2(0.3125, 0.1, 3);
    std::cout << Heat2d_test2.getMatrix() << std::endl;
    
    return 0;
}