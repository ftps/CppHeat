#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <map>
#include <iterator>

template<typename T>
class Matrix
{
public:
    const int row, col;
    std::map<std::array<int,2>, T> sparse;
    // Constructors
    Matrix(int r, int c) : row(r), col(c){}

    // Operators
    template<typename U=T>
    U& operator[](std::array<int,2> p)
    {
        if( p[0] >= row || p[0] < 0 || p[1] >= col || p[1] < 0 ){
            std::cout << "Position out of bounds" << std::endl;
            exit(-2);
        }
        return sparse[p];
    }
    // Methods
    template<typename U=T>
    void print_map()
    {
        typename std::map<std::array<int,2>, U>::iterator it = sparse.begin();
        while(it !=sparse.end()){
            std::cout << "Pos: " << it->first[0] << " " << it->first[1] << ", Val: " << it->second << std::endl;
            it++;
        }
    }
};

template<typename T>
inline Vector<T> operator*(Matrix<T>& lhs, Vector<T>& rhs)
{
    Vector<T> result(lhs.col);

    if(lhs.row != rhs.size()) throw "Matrix and vector sizes don't match.";

    typename std::map<std::array<int, 2>, T>::iterator it = lhs.sparse.begin();
    while(it != lhs.sparse.end()){
        result[it->first[0]] += it->second*rhs[it->first[1]];
        it++;
    }

    return result;
}

#endif // MATRIX_HPP
