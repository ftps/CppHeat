#include "heat.hpp"

int main(int argc, char* argv[])
{
    // Verification of 1d system matrix
    Vector<double> aux1, aux2;
    Heat<1,double> Heat1d(0.3125, 0.01, 3);

    std::cout << Heat1d.getMatrix() << std::endl;
    aux1 = Heat1d.exact(0.05);
    std::cout << aux1 << std::endl;
    aux2 = Heat1d.solve(0.05);
    std::cout << aux2 << std::endl;

    // Verification of 2d system matrix
    Heat<2,double> Heat2d(0.3125, 0.0001, 5);

    std::cout << Heat2d.getMatrix() << std::endl;
    aux1 = Heat2d.exact(0.05);
    std::cout << aux1 << std::endl;
    aux2 = Heat2d.solve(0.05);
    std::cout << aux2 << std::endl;

    return 0;
}
