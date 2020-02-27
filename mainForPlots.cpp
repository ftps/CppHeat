#include "heat.hpp"
#include <iostream>
//#include <cmath>

int main(int argc, char* argv[])
{
    // VERIFICATION #1: 1d problem

    // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=1
    // (numerical vs. exact solution comparison)

    Vector<double> aux1, aux2, auxtotal1d;
    Heat<1,double> Heat1d_test1(0.3125, 0.001, 4);

    aux1 = Heat1d_test1.exact(1.0); // Exact solution (1 sec)
    aux2 = Heat1d_test1.solve(1.0); // Numerical solution (1 sec)

    auxtotal1d = aux2-aux1;         // Difference vector

    for(auto i = 0; i < auxtotal1d.size(); ++i){
        auxtotal1d[i] = auxtotal1d[i]/aux1[i]; // Relative error
    }

    FILE *text;
    text=fopen("output.txt","w");
    fprintf(text,"Nodes: error:\n");

    int m_max = 100;
    double dt = 0.001;
    double t = 1.0;
    Vector<double> mVec(m_max), errorVec(m_max);
    for(auto i = 1; i < m_max; ++i){
        mVec[i] = i;
        Heat<1,double> Heat1d_test1dLoop(0.3125, dt, i);
        Vector<double> auxLoop1 = Heat1d_test1dLoop.solve(t);
        Vector<double> auxLoop2 = Heat1d_test1dLoop.exact(t);
        Vector<double> auxtotal1dLoop = auxLoop2 - auxLoop1;

        for(auto j = 0; j < auxtotal1dLoop.size(); ++j){
            auxtotal1dLoop[j] = auxtotal1dLoop[j]/auxLoop1[j]; // Relative error
        }
        errorVec[i] = 100*auxtotal1dLoop.abs_max();
        //std::cout << i << " ";
        std::cout << errorVec[i] << " ";

        fprintf(text,"%d , %f ;\n",i,errorVec[i]);
    };

    fclose(text);

/*
    // Test 2 -> alpha=0.3125, dt=0.1, m=3
    // (verify matrix M assembly)
    Heat<1,double> Heat1d_test2(0.3125, 0.1, 3);
    std::cout << Heat1d_test2.getMatrix() << std::endl;

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

    // Test 2 -> alpha=0.3125, dt=0.1, m=3
    // (verify matrix M assembly)
    Heat<2,double> Heat2d_test2(0.3125, 0.1, 3);
    std::cout << Heat2d_test2.getMatrix() << std::endl;
*/
    return 0;
}
