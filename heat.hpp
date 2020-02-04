//
// Created by User on 03/02/2020.
//

#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include <cmath>

template <int n, typename T>
class Heat{
//private:
    const double alpha;
    const int m;
    const double dt;
    const int dim;
    Matrix<T> M;

public:
    //Constructors
    Heat(double a, int mm, double delta_t) : alpha(a), m(mm), dt(delta_t), dim(pow(m,n)){
        M = createM();
    }

    //Methods
    //Creates an identity matrix dim x dim
    template<typename U=T>
    Matrix<U> identity(){
        Matrix<U> I(dim,dim);
        for (auto i = 0; i < dim; ++i) {
            I[{i,i}] = 1;
        }
        return I;
    }

    //Francisco, this is yours :)
    template<typename U=T>
    Matrix<U> createD()
    {
        Matrix<U> D = (n*-2)*identity();

        for(int i = 0; i < dim; ++i){
            for(int j = i+1; j < dim; ++j){
                for(int k = 0; k < n; ++k){
                    if((i+pow(m,k))%pow(m,k+1) == (i%pow(m,k+1))){
                        D[{i, i+pow(m,k)}] += 1;
                    }
                }
            }
        }

        return D;
    }

    //Create M
    template<typename U=T>
    Matrix<U> createM(){
        double const dx=1/(m+1);
        double const coefficient = alpha*dt/pow(dx,2);
        Matrix<U> D = createD();

        M = identity();

        for (typename map<T>::iterator it = D.iter(); !D.end(it); it++) {
            M[it->first] -= coefficient*it->second;
        }
    }

};

#endif // HEAT_HPP
