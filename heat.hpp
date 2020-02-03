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
    double alpha;
    int m;
    double dt;
    Matrix<T> M;

public:
    //Constructors
    Heat(double a, int mm, double delta_t) : alpha(a), m(mm), dt(delta_t){
        M = createM();
    }

    //Methods
    //Creates an identity matrix dim x dim
    template<typename U=T>
    Matrix<U> identity(int dim){
        Matrix<U> I(dim,dim);
        for (auto i = 0; i < dim; ++i) {
            I[{i,i}]=1;
        }
        return I;
    }

    //Francisco, this is yours :)
    template<typename U=T>
    Matrix<U> sum(int i, int j){
        Matrix<U> S;
        return S;
    }

    //Create M
    template<typename U=T>
    Matrix<U> createM(){
        int const dimension=pow(m,n); //dimension of matrix
        double const dx=1/(m+1);
        double const coefficient = alpha*dt/pow(dx,2);

        M=identity(dimension);

        for (auto i = 0; i < dimension; ++i) {
            for (auto j = 0; j < dimension; ++j) {
                M[{i,j}]-=coefficient*sum(i,j);
            }
        }
    }

};

#endif // HEAT_HPP