//
// Created by User on 03/02/2020.
//

#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include <cmath>

// power function introduced for natural values
int power(int a, int n)
{
    if(n <= 0) return 1;
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
    Heat(double a, double delta_t, int mm) : alpha(a), m(mm), dt(delta_t), M(dim, dim), dim(pow(m,n))
    {
        int kk, kk1;
        const double coeff = alpha*dt*pow(m+1, 2);

        for(int i = 0; i < dim; ++i){
            M[{i,i}] = 1 + n*2*coeff;   // The diagonal of the M matrix is filled with the idendity plus the sum in k of D_kii
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
    void calc_initial_it(Vector<int>& x, Vector<U>& u, int& counter, int dim) const
    { //dim has to be passed by value because in calc_initial it is the attribute n and we don't want to change it
        if(dim==1){
            const double dx=1/((double)m+1);
            for(x[0]=1; x[0]<=m; x[0]++){
                for (auto i = 0; i < n ; ++i){ //product of sin(pi*x_i) , 0<i<n-1
                    u[counter]*=sin(M_PI*(x[i]*dx));
                }
                counter++;
            }
            return;
        }else //this is the last iteration
            for(x[dim-1]=1; x[dim-1]<=m; x[dim-1]++){
                calc_initial_it<U>(x, u, counter, dim-1);
            }
        return;
    }

    template<typename U=T>
    void calc_initial(Vector<U>& u) const
    {
        Vector<int> x(n); //vector that holds the current position
        int counter=0;

        for(auto i = 0; i < dim; ++i){
            u[i] = 1;
        }

        calc_initial_it(x,u,counter,n);
    }

    template<typename U=T>
    Vector<U> exact(double t) const
    {
        Vector<U> u(dim); //vector with the result

        calc_initial(u);
        u=u*exp(-n*pow(M_PI,2)*alpha*t);
        return u;
    }

    template <typename U=T>
    Vector<U> solve(double t) const
    {
        int l = (int) (t/dt);   //t = l * dt;
        Vector<U> u(dim);
        Vector<U> u_next(dim); //vector with the result

        calc_initial(u_next);
        for (auto i = 0; i < l; ++i) {
            u = u_next;
            cg(M, u, u_next, 0.001, 1e6); //tolerance and number of max iterations can be changed
        }
        return u_next;
    }

};
#endif // HEAT_HPP
