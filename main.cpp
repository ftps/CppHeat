#include "cg.hpp"

int main()
{
    Matrix<int> A(3, 3);
    Vector<int> x = {2, -1, 5};
    Vector<int> b = {0, -1, 2};

    A[{1, 0}] = 1;
    A[{0, 2}] = 1;
    A[{2, 1}] = 1;

    cg<int>(A, b, x, 1, 100);

    return 0;
}
