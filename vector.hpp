#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <memory>
#include <cassert>
#include <iomanip>

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

    template<typename U=T>
    Vector(Vector<U>& orig) : Vector(orig.size())
    {
        for(int i = 0; i < length; ++i){
            data[i] = orig[i];
        }
    }

    ~Vector()
    {
        if(data != NULL) delete data;
    }

    // Operators

	template<typename U=T>
	U& operator[](const int i) const
	{
		return data[i];
	}

    template<typename U=T> // Copy assignment operator
    Vector<U>& operator=(const Vector<U>& orig)
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

    template<typename U=T> // Move assignment operator
    Vector<U>& operator=(Vector<U>&& other)
    {
        if(this != &other){
            length = std::move(other.length);
            data = std::move(other.data);

            other.length = 0;
            other.data = NULL;
        }

        return *this;
    }

    template<typename U>
    inline auto operator+(const Vector<U> other) const
    {
        if(length != other.size() || !length || !other.size()){
            throw "Vectors have different or null size, cannot perfom addition\n";
        }

        Vector<decltype(data[0]+other[0])> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] + other[i];
        }

        return new_v;
    }

    template<typename U>
    inline auto operator-(const Vector<U> other) const
    {
        if(length != other.size() || !length || !other.size()){
            throw "Vectors have different size, cannot perfom subtraction\n";
        }

        Vector<decltype(data[0]-other[0])> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] - other[i];
        }

        return new_v;
    }

    template<typename U>
    inline auto operator*(const U scalar) const
    {
        if(!length){
            throw "Vector is null, can't perform multiplication\n";
        }

        Vector<decltype(data[0]*scalar)> new_v(length);

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
};

template<typename T, typename U>
inline auto operator*(const U& scalar, const Vector<T> other)
{
    if(!other.size()){
        throw "Vector is null, can't perform multiplication\n";
    }

    Vector<decltype(other[0]*scalar)> new_v(other.size());

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

template<typename T, typename U>
inline auto dot(const Vector<T>& lhs, const Vector<U>& rhs)
{
    if(lhs.size() != rhs.size() || !lhs.size() || !rhs.size()){
        throw "Vectors have different size, cannot perfom dot product\n";
    }

    decltype(lhs[0]+rhs[0]) dot = lhs[0]*rhs[0];
    for(int i = 1; i < lhs.size(); ++i){
        dot += lhs[i]*rhs[i];
    }

    return dot;
}

#endif // VECTOR_HPP
