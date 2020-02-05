#include "heat.hpp"

int main()
{
    Matrix<double> A(3, 3);
    Vector<double> x = {2, -1, 5};
    Vector<double> b = {0, -1, 2};

    A[{1, 0}] = 1;
    A[{0, 2}] = 1;
    A[{2, 1}] = 1;

    std::cout << cg<double>(A, b, x, 2, 100) << std::endl;
    

    return 0;
}
