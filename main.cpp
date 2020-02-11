#include "heat.hpp"

int main(int argc, char* argv[])
{
    // Verification of 1d system matrix
    Heat<1,double> Heat1d(0.3125, 0.1, 3);
    std::cout << Heat1d.getMatrix() << std::endl;

    // Verification of 2d system matrix
    Heat<2,double> Heat2d(0.3125, 0.1, 3);
    std::cout << Heat2d.getMatrix() << std::endl;

    return 0;
}
