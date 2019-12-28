#include "matrix.hpp"

int main()
{
    Matrix<int> A(3, 3);
    Vector<int> x = {2, -1, 5};

    A[{1, 0}] = 1;
    A[{0, 2}] = 1;
    A[{2, 1}] = 1;

    Vector<int> y = A*x;

    std::cout << y << std::endl;

    return 0;
}
