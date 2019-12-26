#include "vector.hpp"

int main()
{
    Vector<int> a = {1, 3, -2, 9};
    Vector<double> b {0.5, -0.2, 3.9, -11.37};
    //Vector<int> e = a-b;

    std::cout << a+b << std::endl;
    std::cout << b+a << std::endl;
    std::cout << -0.2*(b+(b+a)) << std::endl;
    std::cout << dot(a, b) << std::endl;
    return 0;
}
