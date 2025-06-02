
#pragma once
#include <iostream>  
#include "Array.hpp"  

namespace np
{
    template <typename T>
    ostream& operator<<(ostream& os, const Array<T>& p);

    template <typename T>
    Array<bool> operator==(const Array<T>& lhs, const Array<T>& rhs);

    template <typename T, typename... Args>
    Array<T> ones(Args... args);

    template <typename T = int , typename... Args>
    Array<T> zeros(Args... args);

    template <typename T>
    Array<T> sum(const Array<T>& arr,vector<int> axis);

    template <typename T>
    T sum(const Array<T>& arr);

    template <typename T>
    Array<T> unique(const Array<T>& arr);

    template <typename T>
    T mean(const Array<T>& arr);

    template <typename T>
    T min(const Array<T> & arr);

    template <typename T>
    T max(const Array<T> &arr);

    template <typename T>
    Array<T> cos(const Array<T>& arr);

    template <typename T>
    Array<T> sin(const Array<T>& arr);

    template <typename T>
    Array<T> sqrt(const Array<T>& arr);

    template <typename T>
    Array<T> log(const Array<T>& arr);

    template <typename T>
    Array<T> exp(const Array<T>& arr);

    template <typename T>
    void save_csv(const std::string& filename, const np::Array<T>& arr);
    
    template <typename T>
    np::Array<T> load_csv(const std::string& filename); 

    template <typename T = int >
    Array<T> arange(const T start,const T end,const T pas=1);

    template <typename T = int >
    Array<T> eye(const size_t m, const size_t n = 0, const int k = 0);

    template <typename T = float >
    Array<T> rand(const vector<size_t>& dimension);

    template <typename T>
    Array<T> randn(const std::vector<size_t>& shape);

    template <typename T = float >
    Array<T> linspace(T start,T stop,size_t num);

    template <typename T>
    Array<T> concat(const Array<T>& a, const Array<T>& b, size_t axis=0);

    template <typename T >
    Array<T> abs( Array<T> arr);

    template <typename T>
    Array<T> dot(const Array<T>& arr1,const Array<T>& arr2);

    template <typename T>
    Array<T> transpose(const Array<T>& arr);

    // Opérateurs libres pour comparaisons scalaire-Array
    template <typename U, typename V> Array<bool> operator==(const U& scalar, const Array<V>& arr);
    template <typename U, typename V> Array<bool> operator!=(const U& scalar, const Array<V>& arr);
    template <typename U, typename V> Array<bool> operator<(const U& scalar, const Array<V>& arr);
    template <typename U, typename V> Array<bool> operator<=(const U& scalar, const Array<V>& arr);
    template <typename U, typename V> Array<bool> operator>(const U& scalar, const Array<V>& arr);
    template <typename U, typename V> Array<bool> operator>=(const U& scalar, const Array<V>& arr);

    template <typename Condition, typename U, typename V>
    auto where(const Condition& cond, const U& x, const V& y);
}

#include "../src/Utils.tpp"  
