#include "heat.hpp"
//#include "gnuplot-iostream.h"
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    /*std::vector<std::pair<double, double>> result;
    Vector<double> aux;
    Gnuplot gp;
    gp << "set xrange [0:1]\nset yrange [0:1]\n";

    gp << "plot '-' with lines title 'hh'";
    for(int m = 20; m < 80; m += 10){
        gp << ", '-' with lines title 'hh'";
    }
    gp << "\n";

    for(int m = 10; m < 80; m += 10){
        Heat<1,double> Heat1d(0.3125, 0.001, m);
        aux = Heat1d.solve(0.1*(m/10.0));
        double dx = 1/(double)(1+m);
        std::cout << "m = " << m << std::endl;
        for(auto i = 0; i < aux.size(); ++i){
            result.push_back(std::make_pair(dx*(i+1), aux[i]));
        }

        gp.send1d(result);
        result.clear();
    }*/

    Heat<1, double> Heat1d(0.3125, 0.001, 99);
    Vector<double> aux;

    std::cout << (aux = Heat1d.solve(2.0)) << std::endl;

    return 0;
}
