#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <memory>
#include <cassert>
#include <iomanip>
#include <cmath>
/*#include <iostream> // for debug

#define LOG std::cout << "IN FILE " << __FILE__ << " IN LINE " << __LINE__ << std::endl;
*/
template <typename T>
class Vector
{
//private:
    int length;
    T *data;
public:
    // Constructors
    Vector() : length(0), data(NULL) {}
    Vector(const int n) : length(n), data(new T[n]()) {}

    template<typename U=T>
    Vector(std::initializer_list<U> list) : Vector((int)list.size())
    {
        std::uninitialized_copy(list.begin(), list.end(), data);
    }

    Vector(const Vector<T>& orig) : Vector(orig.size())
    {
        for(int i = 0; i < length; ++i){
            data[i] = orig[i];
        }
    }

    Vector(Vector<T>&& orig) : Vector(orig.size())
    {
        data = std::move(orig.data);
    }

    ~Vector()
    {
        if(data != NULL){
            delete data;
        }
    }

    // Operators

	template<typename U=T>
	U& operator[](const int i) const
	{
		return data[i];
	}

    // Copy assignment operator
    Vector<T>& operator=(const Vector<T>& orig)
    {
        if(length != orig.size()){
            if(data != NULL) delete data;
            data = new T[orig.size()];
            length = orig.size();
        }
        for(int i = 0; i < length; ++i){
            data[i] = orig[i];
        }
        return *this;
    }

    // Move assignment operator
    Vector<T>& operator=(Vector<T>&& other)
    {
        if(this != &other){
            length = std::move(other.length);
            if(data != NULL){
                delete data;
            }
            data = std::move(other.data);
            other.length = 0;
            other.data = NULL;
        }
        return *this;
    }

    template<typename U=T>
    inline Vector<U> operator+(const Vector<U>& other) const
    {
        if(length != other.size() || !length || !other.size()){
            throw "Vectors have different or null size, cannot perfom addition\n";
        }

        Vector<U> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] + other[i];
        }

        return new_v;
    }

    template<typename U=T>
    inline Vector<U> operator-(const Vector<U>& other) const
    {
        if(length != other.size() || !length || !other.size()){
            throw "Vectors have different size, cannot perfom subtraction\n";
        }

        Vector<U> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] - other[i];
        }

        return new_v;
    }

    template<typename U=T>
    inline Vector<U> operator*(const U& scalar) const
    {
        if(!length){
            throw "Vector is null, can't perform multiplication\n";
        }

        Vector<U> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = scalar*data[i];
        }

        return new_v;
    }

    // Methods
    int size() const
    {
        return length;
    }

    template<typename U=T>
    U abs_max()
    {
        U max = 0;
        for (auto i=0; i<length; i++)
        {
            if (fabs(data[i]) > max) {
                max = fabs(data[i]);
            }
        }

        return max;
    }
};

template<typename T>
inline Vector<T> operator*(const T& scalar, const Vector<T>& other)
{
    if(!other.size()){
        throw "Vector is null, can't perform multiplication\n";
    }

    Vector<T> new_v(other.size());

    for(int i = 0; i < other.size(); ++i){
        new_v[i] = scalar*other[i];
    }
    return new_v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
    os << "Vector sz " << v.size() << " :";
    for(int i = 0; i < v.size(); ++i){
        os << " " << v[i];
    }
    return os;
}

template<typename T>
inline T dot(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if(lhs.size() != rhs.size() || !lhs.size() || !rhs.size()){
        throw "Vectors have different size, cannot perfom dot product\n";
    }
    T dot = lhs[0]*rhs[0];
    for(int i = 1; i < lhs.size(); ++i){
        dot += lhs[i]*rhs[i];
    }
    return dot;
}

#endif // VECTOR_HPP
