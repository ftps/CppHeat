#ifndef CG_HPP
#define CG_HPP

#include "matrix.hpp"

template<typename T>
inline int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T& tol, int maxiter)
{
    Vector<T> p = b - A*x;
    Vector<T> r = p;
    T a, aux1 = dot(r, r), aux2;

    for(int i = 0; i < maxiter; ++i){
        a = aux1/dot(A*p, p);
        x = x + p*a;
        r = r - a*(A*p);

        aux2 = dot(r, r);
		if(aux2 < tol){
            return i;
        }
		p = r + (aux2/aux1)*p;
        aux1 = aux2;
    }

    return -1;
}

#endif
