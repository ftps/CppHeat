#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <map>
#include <iterator>

template<typename T>
class Matrix
{
//private:
    const int row, col;
    std::map<std::array<int,2>, T> sparse;
    typename std::map<std::array<int,2>, T>::iterator iter;
public:
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

    void begin_iter()
    {
        iter = sparse.begin();
    }

    bool iter_end()
    {
        return iter == sparse.end();
    }

    std::array<int, 2> get_pos()
    {
        return iter->first;
    }

    template<typename U=T>
    U get_val()
    {
        return iter->second;
    }

    void next()
    {
        iter++;
    }

    std::array<int, 2> size()
    {
        return {row, col};
    }
};

template<typename T>
inline Vector<T> operator*(Matrix<T>& lhs, Vector<T>& rhs)
{
    Vector<T> result(lhs.size()[1]);

    if(lhs.size()[0] != rhs.size()) throw "Matrix and vector sizes don't match.";

    lhs.begin_iter();
    while(!lhs.iter_end()){
        result[lhs.get_pos()[0]] += lhs.get_val()*rhs[lhs.get_pos()[1]];
        lhs.next();
    }

    return result;
}

#endif // MATRIX_HPP
