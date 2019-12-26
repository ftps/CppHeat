#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <initializer_list>
#include <cassert>
#include <memory>
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
    Vector(int n) : length(n), data(new T[n]) {}

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
    U& operator[](const int i){
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
    Vector<U>& operator=(Vector<U>&& orig)
    {
        length=std::move(orig.length);
        data = std::move(orig.data);

        orig.length = 0;
        orig.data = NULL;

        return *this;
    }

    template<typename U>
    inline auto operator+(Vector<U> other) const
    {
        if(length != other.size() || !length || !other.size()) throw "Vectors have different or null size, cannot perfom addition\n";

        Vector<decltype(data[0]+other[0])> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] + other[i];
        }

        return new_v;
    }

    template<typename U>
    inline auto operator-(Vector<U> other) const
    {
        if(length != other.size() || !length || !other.size()) throw "Vectors have different size, cannot perfom subtraction\n";

        Vector<decltype(data[0]-other[0])> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = data[i] - other[i];
        }

        return new_v;
    }

    template<typename U>
    inline auto operator*(const U& scalar)
    {
        if(!length) throw "Vector is null, can't perform multiplication\n";

        Vector<decltype(data[0]*scalar)> new_v(length);

        for(int i = 0; i < length; ++i){
            new_v[i] = scalar*data[i];
        }

        return new_v;
    }

    // Methods
    int size()
    {
        return length;
    }
};

template<typename T, typename U>
inline auto operator*(const U& scalar, Vector<T> other)
{
    if(!other.size()) throw "Vector is null, can't perform multiplication\n";

    Vector<decltype(other[0]*scalar)> new_v(other.size());

    for(int i = 0; i < other.size(); ++i){
        new_v[i] = scalar*other[i];
    }

    return new_v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Vector<T> v)
{
    os << "Vector sz " << v.size() << " :";
    for(int i = 0; i < v.size(); ++i){
        os << " " << v[i];
    }
    return os;
}

template<typename T, typename U>
inline auto dot(Vector<T> lhs, Vector<U> rhs)
{
<<<<<<< HEAD
    T d = 0;


=======
    if(lhs.size() != rhs.size() || !lhs.size() || !rhs.size()) throw "Vectors have different size, cannot perfom dot product\n";

    decltype(lhs[0]+rhs[0]) dot = lhs[0]*rhs[0];
    for(int i = 1; i < lhs.size(); ++i){
        dot += lhs[i]*rhs[i];
    }

    return dot;
>>>>>>> b3b80f831bac93f3388e3563358a55ec96fb527e
}

#endif // VECTOR_HPP
