#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <map>
#include <iterator>

template<typename T>
using map = std::map<std::array<int,2>, T>;

template<typename T>
class Matrix
{
//private:
    const int row, col;
    map<T> sparse;
    typename map<T>::iterator it_begin;
public:
    // Constructors
    Matrix(int r, int c) : row(r), col(c), it_begin(sparse.begin()) {}

    template<typename U=T>
    Matrix(const Matrix<U> other) : Matrix(other.row, other.col)
    {
        sparse = other.sparse;
        it_begin = other.it_begin;
    }

    template<typename U=T>
    Matrix(const Matrix<U>& other) : Matrix(other.row, other.col)
    {
        sparse = other.sparse;
        it_begin = other.it_begin;
    }

    // Operators
    template<typename U=T>
    U& operator[](std::array<int,2> p)
    {
        if( p[0] >= row || p[0] < 0 || p[1] >= col || p[1] < 0 ){
            throw "Position out of bounds\n";
        }

        sparse[p];
        it_begin = sparse.begin();
        return sparse[p];
    }
    // Methods
    std::array<int, 2> size() const
    {
        return {row, col};
    }

	template<typename U=T>
	typename map<T>::iterator iter() const
	{
		return it_begin;
	}

    template<typename U=T>
    bool end(typename map<T>::iterator it) const
    {
        return it == sparse.end();
    }
};

template<typename T>
inline Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
{
    Matrix<T> result(rhs.size[0], rhs.size[1]);

    for(auto it = rhs.iter(); !rhs.end(it); it++){
        result[it->first] = lhs*it->second;
    }

    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M)
{
    for(auto it = M.iter(); !M.end(it); it++)
    {
        os << "[" << it->first[0] << ", " << it->first[1] << "]: ";
        os << it->second << std::endl;
    }

    return os;
}



// Vector multiplication on the right
template<typename T>
inline Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
    Vector<T> result(lhs.size()[0]);
	if(lhs.size()[1] != rhs.size()) throw "Matrix and vector sizes don't match.";

	for(auto it = lhs.iter(); !lhs.end(it); it++){
		result[it->first[0]] += it->second*rhs[it->first[1]];
	}

    return result;
}

#endif // MATRIX_HPP
