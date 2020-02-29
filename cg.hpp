#ifndef CG_HPP
#define CG_HPP

#include "matrix.hpp"

template<typename T>
inline int cg(const Matrix<T> &A, Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
    Vector<T> p = b - A*x;
    Vector<T> r = b - A*x;
    T a;

    for(int i = 0; i < maxiter; ++i){
        a = dot(r, r)/dot(A*p, p);
        x = x + p*a;
        r = r - a*(A*p);

		if(dot(r, r) < tol*tol){
            return i;
        }
		p = r + dot(r, r)/(a*dot(A*p, p))*p;
    }

    return -1;
}

#endif
