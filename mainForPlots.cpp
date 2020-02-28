#include "heat.hpp"
#include <iostream>
//#include <cmath>

int main(int argc, char* argv[])
{
    // VERIFICATION #1: 1d problem
    /*
    // Test 1 -> alpha=0.3125
    // (numerical vs. exact solution comparison)
    {
    int m_max = 100;
    double dt = 0.001; 
    double t = 1.0;
    Vector<double> mVec(m_max), errorVec(m_max);
    for(auto i = 1; i < m_max; ++i){
        mVec[i] = i;
        Heat<1,double> Heat1d_testLoop(0.3125, dt, i);
        Vector<double> auxLoop1 = Heat1d_testLoop.solve(t);
        Vector<double> auxLoop2 = Heat1d_testLoop.exact(t);
        Vector<double> auxtotal1dLoop = auxLoop2 - auxLoop1;

        for(auto j = 0; j < auxtotal1dLoop.size(); ++j){
        auxtotal1dLoop[j] = auxtotal1dLoop[j]/auxLoop1[j]; // Relative error
    }
        errorVec[i] = 100*auxtotal1dLoop.abs_max();
        //std::cout << i << " ";
        std::cout << errorVec[i] << " ";
    };
    }
    */

    // VERIFICATION #2: 2d problem

    // Test 1 -> alpha=0.3125, dt=0.001, m=99, t=0.5
    // (numerical vs. exact solution comparison)
    
    {
    int m_max = 61;
    double dt = 0.1; 
    double t = 0.5;
    Vector<double> mVec(m_max), errorVec(m_max);
    for(auto i = 1; i < m_max; i++){
        mVec[i] = i;
        Heat<2,double> Heat2d_testLoop(0.3125, dt, i);
        Vector<double> auxLoop1 = Heat2d_testLoop.solve(t);
        Vector<double> auxLoop2 = Heat2d_testLoop.exact(t);
        Vector<double> auxtotal2dLoop = auxLoop2 - auxLoop1;

        for(auto j = 0; j < auxtotal2dLoop.size(); ++j){
        auxtotal2dLoop[j] = auxtotal2dLoop[j]/auxLoop1[j]; // Relative error
    }
        errorVec[i] = 100*auxtotal2dLoop.abs_max();
        //std::cout << i << " ";
        std::cout << errorVec[i] << " ";
    };
    }
    

    return 0;
}
