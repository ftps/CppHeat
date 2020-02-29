#ifndef HEAT_HPP
#define HEAT_HPP

#include "cg.hpp"
#include "matrix.hpp"
#include "vector.hpp"

template <int n, typename T>
class Heat{
//private:
    const double alpha;
    const int m;
    const double dt;
    const int dim;
    const Vector<T> u_initial;
    const Matrix<T> M;

    template<typename U=T>
    const Matrix<U> createM() const
    {
        Matrix<U> M_aux(dim, dim);
        int kk, kk1;
        const double coeff = alpha*dt*pow(m+1, 2); // alpha*dt/dx^2

        for(int i = 0; i < dim; ++i){
            M_aux[{i,i}] = 1 + n*2*coeff;   // The diagonal of the M matrix is filled with the idendity plus the sum in k of D_kii
            kk = 1;
            kk1 = m;
            for(int k = 0; k < n; ++k){     // the loop will go through the forward neighbours of point i
                if(k){                      // those being the ones such that j > i
                    kk *= m;                // which will be located right next to i (j = i + 1),
                    kk1 *= m;               // on the next line (j = i + m), plane (j = i + m^2) or
                }                           // in general (j = i + m^k)
                if((i+kk)/kk1 == (i/kk1) && i+kk < dim){  // this if verifies if j is the same hyperplane as i
                    M_aux[{i, i+kk}] -= coeff;  // and adds the value to such point accordingly
                    M_aux[{i+kk, i}] -= coeff;
                }
            }
        }

        return M_aux;
    }

    template<typename U=T>
    const Vector<U> createI() const
    {
        Vector<U> u(dim);
        Vector<int> x(n); //vector that holds the current position
        int counter=0;

        for(auto i = 0; i < dim; ++i){
            u[i] = 1;
        }

        calc_initial_it(x,u,counter,n);
        return u;
    }

    template<typename U=T>
    void calc_initial_it(Vector<int>& x, Vector<U>& u, int& counter, int dim) const
    {
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


public:
    //Constructor
    Heat(double alpha, double delta_t, int mm) : alpha(alpha), m(mm), dt(delta_t), dim(pow(m,n)),
                                                 u_initial(createI()), M(createM()) {}

    //Methods
    template<typename U=T>
    const Matrix<U>& getMatrix() const
    {
        return M;
    }

    template<typename U=T>
    const Vector<U>& getInitial() const
    {
        return u_initial;
    }

    template<typename U=T>
    Vector<U> exact(U t) const
    {
        return u_initial*(U)exp(-n*pow(M_PI,2)*alpha*t);
    }

    template <typename U=T>
    Vector<U> solve(U t) const
    {
        int l = (int) (t/dt);   //t = l * dt;
        Vector<U> u(u_initial); // vector with the result
        Vector<U> u_aux(dim);

        for (auto i = 0; i < l; ++i) {
            u_aux = u;
            cg(M, u_aux, u, 0.001, 1e6); //tolerance and number of max iterations can be changed
        }
        return u;
    }

};
#endif // HEAT_HPP
