#ifndef CG_HPP
#define CG_HPP

#include "matrix.hpp"

template<typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

template<typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
    Vector<T> p = b - A*x;
    Vector<T> r = p;
    T a;

    for(int i = 0; i < maxiter; ++i){
        a = dot(r, r)/dot(p, p);  
        x = x + p*a;
		r = r - a*(A*p);

		if(dot(r, r) < tol*tol) return i;

		p = r + dot(r, r)/(a*dot(p, p))*p;
    }

    return -1;
}

#endif
