//
// Created by User on 03/02/2020.
//

#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include <cmath>

int power(int a, int n)
{
    if(!n) return 1;
    else return a*power(a, n-1);
}

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
    Heat(double a, double delta_t, int mm) : alpha(a), m(mm), dt(delta_t), dim(pow(m,n)), M(dim, dim)
    {
        int kk, kk1;
        const double coeff = alpha*dt*pow(m+1, 2);

        for(int i = 0; i < dim; ++i){
            M[{i,i}] = 1 + n*2*coeff;
            for(int k = 0; k < n; ++k){
                kk = power(m, k);
                kk1 = power(m, k+1);
                if((i+kk)/kk1 == (i/kk1)){
                    M[{i, i+kk}] -= coeff;
                    M[{i+kk, i}] -= coeff;
                }
            }
        }
    }

    //Methods

    template<typename U=T>
    Matrix<U>& getMatrix()
    {
        return M;
    }



    //Recursive process to obtain the initial conditions
    // *** there's another version using the template specialization but
    // I was not able to find a viable option to implement it because it requires
    //partial template specializataion with a non-variable which is not supported by
    //the compiler for same reason
    //the specialized version was already shared so it anyone wants to take a look at it
    //and try to find a solution feel welcome to
    //For now, this is a way to implement that actually works
    template<typename U=T>
    void calc_initial_it(Vector<U>& x, Vector<U>& u, int& counter, int dim){ //dim has to be passed by value because in calc_initial it is the attribute n and we don't want to change it
        if(dim==1){
            double const dx=1/(m+1);
            for(x[1]=1; x[1]<=m; x[1]++){
                for (auto i = 0; i < n ; ++i){ //product of sin(pi*x_i) , 0<i<n-1
                    u[counter]*=sin(M_PI*x[i]*dx);
                    counter++;
                }
                counter++;
            }
            return;
        }else //this is the last iteration
            for(x[dim]=1; x[dim]<=m; x[dim]++){
                calc_initial_it<U,dim-1>(x, u, counter, dim-1);
            }
        return;
    }

    template<typename U=T>
    void calc_initial(Vector<U>& u){
        Vector<int> x(n); //vector that holds the current position
        int counter=0;
        calc_initial_it<U,n>(x,u,counter,n);
        return;
    }

    template<typename U=T>
    Vector<U> exact(U t) const{
        Vector<U> u(pow(m,n)); //vector with the result

        calc_initial(u);
        u=u*exp(-n*M_PI^2*alpha*t);
        return u;
    }

    template <typename U=T>
    Vector<U> solve(U t) const{
        int l = (int) t / dt;   //t = l * dt;
        Vector<U> u(pow(m,n));  //vector with the result
        Vector<U> u_next(pow(m,n));

        calc_initial(u);
        for (auto i = 0; i < l; ++i) {
            cg(M, u, u_next, 0.01, 10^6); //tolerance and number of max iterations can be changed
            u=u_next;
        }
        return u;
    }

};
#endif // HEAT_HPP
