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
    Matrix(int r, int c) : row(r), col(c), it_begin(sparse.begin()){}

    // Operators
    template<typename U=T>
    U& operator[](std::array<int,2> p)
    {
        if( p[0] >= row || p[0] < 0 || p[1] >= col || p[1] < 0 ){
            std::cout << "Position out of bounds" << std::endl;
            exit(-2);
        }
		sparse[p]; // generates mapping of key p if it doesn't exist
		it_begin = sparse.begin(); // updates the iterator to take into account the new value
        return sparse[p];
    }
    // Methods
    std::array<int, 2> size() const
    {
        return {row, col};
    }

	template<typename U=T>
	typename map<U>::iterator iter() const
	{
		return it_begin;
	}

	template<typename U=T>
	bool end(typename map<U>::iterator curr) const
	{
		return curr == sparse.end();
	}
};

template<typename T>
inline Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
    Vector<T> result(lhs.size()[1]);
	if(lhs.size()[0] != rhs.size()) throw "Matrix and vector sizes don't match.";

	for(typename map<T>::iterator it = lhs.iter(); !lhs.end(it); it++){
		result[it->first[0]] += it->second*rhs[it->first[1]];
	}

    return result;
}

#endif // MATRIX_HPP
