#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include <map>
#include <iterator>

template<typename T>
using map = std::map<std::array<int, 2>, T>;



template<typename T>
class Matrix
{
//private:
    const int row, col;
    map<T> sparse;
public:
    // Constructors
    Matrix(int r, int c) : row(r), col(c) {}

    Matrix(const Matrix<T>&& other) : Matrix(other.row, other.col)
    {
        sparse = std::move(other.sparse);
    }

    template<typename U=T>
    Matrix(const Matrix<U>& other) : Matrix(other.row, other.col)
    {
        sparse = other.sparse;
    }

    // Operators
    template<typename U=T>
    U& operator[](std::array<int,2> p)
    {
        if( p[0] >= row || p[0] < 0 || p[1] >= col || p[1] < 0 ){
            throw "Position out of bounds\n";
        }

        return sparse[p];
    }
    // Methods
    std::array<int, 2> size() const
    {
        return {row, col};
    }

    template<typename U=T>
	typename map<T>::const_iterator begin() const
	{
		return sparse.begin();
	}

    template<typename U=T>
    typename map<U>::const_iterator end() const
    {
        return sparse.end();
    }
};

template<typename T>
inline Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
{
    Matrix<T> result(rhs.size[0], rhs.size[1]);

    for(auto it = rhs.begin(); it != rhs.end(); it++){
        result[it->first] = lhs*it->second;
    }

    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& M)
{
    for(auto it = M.begin(); it != M.end(); it++)
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
	if(lhs.size()[1] != rhs.size()) throw "Matrix and vector sizes don't match.";
    Vector<T> result(lhs.size()[0]);

	for(auto it = lhs.begin(); it != lhs.end(); it++){
		result[it->first[0]] += it->second*rhs[it->first[1]];
	}


    return result;
}

#endif // MATRIX_HPP
