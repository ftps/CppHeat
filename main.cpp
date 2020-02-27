#include "heat.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    {
        Heat<1,double> Heat1d_test1(0.3125, 0.1, 3);
        std::cout << Heat1d_test1.getMatrix() << std::endl;
    }
    {
        // VERIFICATION #1: 1d problem

        // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=1
        // (numerical vs. exact solution comparison)
        Vector<double> aux1, aux2, auxtotal1d;
        Heat<1,double> Heat1d_test2(0.3125, 0.001, 99);

        aux1 = Heat1d_test2.exact(1.0); // Exact solution (1 sec)
        aux2 = Heat1d_test2.solve(1.0); // Numerical solution (1 sec)

        auxtotal1d = aux2-aux1;         // Difference vector

        for(auto i = 0; i < auxtotal1d.size(); ++i){
            auxtotal1d[i] = auxtotal1d[i]/aux1[i]; // Relative error
        }

        std::cout << "The max difference in relative value is " << 100*auxtotal1d.abs_max() << "%\n";
    }
    {
        Heat<2,double> Heat2d_test1(0.3125, 0.1, 3);
        std::cout << Heat2d_test1.getMatrix() << std::endl;
    }
    {
        // VERIFICATION #2: 2d problem

        // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=0.5
        // (numerical vs. exact solution comparison)
        Vector<double> aux3, aux4, auxtotal2d;
        Heat<2,double> Heat2d_test2(0.3125, 0.05, 99);

        aux3 = Heat2d_test2.exact(0.5); // Exact solution (0.5 sec)
        aux4 = Heat2d_test2.solve(0.5); // Numerical solution (0.5 sec)

        auxtotal2d = aux3 - aux4;


        for(auto i = 0; i < auxtotal2d.size(); ++i){
            auxtotal2d[i] = auxtotal2d[i]/aux3[i];
        }

        std::cout << "The max difference in relative value is " << auxtotal2d.abs_max() << "%\n";
    }
    return 0;
}
