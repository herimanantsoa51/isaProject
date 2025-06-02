#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>
using namespace std;

namespace np
{
    template <typename T = double > 
    class Array
    {
    private:
        vector<T> data_;
        vector<size_t> shape_;
        vector<size_t> strides_;
        size_t compute_index(const vector<size_t>& indices) const;
          // Fonction récursive pour déterminer la shape
        template <typename U>
        void parse(const std::initializer_list<U>& list, 
                     std::vector<size_t>& current_shape,
                     std::vector<T>& flat_data,
                     size_t depth = 0);
        void compute_strides(bool row_major = true); 
          

    public:
        template <typename... Args>
        Array(Args... args);
        Array(const std::vector<size_t>& shape);
        Array() = default;

        T& operator[](vector<size_t> indices);
        T& operator[](size_t index);
        const T& operator[](vector<size_t> indices) const; 
        const T& operator[](size_t index) const;
        
        Array<T> slice(size_t begin,size_t end,size_t pas=1);
        Array<T> slice(vector<size_t> dimension);
        Array<T> slice(const std::vector<std::tuple<long, long, long>>& slices) const;

        const T& operator()(vector<size_t> indices) const;
       
        vector<size_t> shape() const;
        size_t size() const;

        template <typename... Args>
        void reshape(Args... args);
        
        Array<T> operator+(const Array<T>& other);
        Array<T> operator-(const Array<T>& other);
        Array<T> operator*(const Array<T>& other);
        Array<T> operator/(const Array<T>& other);

        void fill(T value);

        bool contains(T var);
        void display(ostream& os) const;
        void display(ostream& os, size_t depth, size_t index) const;
        void displayShape() const;
        ~Array() = default;
        template <typename U>
        friend ostream& operator<<(ostream& os, const Array<U>& p);
        auto begin() { return data_.begin(); }
        auto end() { return data_.end(); }
        auto begin() const { return data_.begin(); }
        auto end() const { return data_.end(); }
        template <typename U>
        Array(const std::initializer_list<U>& list);
        
        template <typename U> Array<bool> operator==(const U& scalar) const;
        template <typename U> Array<bool> operator!=(const U& scalar) const;
        template <typename U> Array<bool> operator<(const U& scalar) const;
        template <typename U> Array<bool> operator<=(const U& scalar) const;
        template <typename U> Array<bool> operator>(const U& scalar) const;
        template <typename U> Array<bool> operator>=(const U& scalar) const;

        template <typename U> Array<bool> operator==(const Array<U>& other) const;
        template <typename U> Array<bool> operator!=(const Array<U>& other) const;
        template <typename U> Array<bool> operator<(const Array<U>& other) const;
        template <typename U> Array<bool> operator<=(const Array<U>& other) const;
        template <typename U> Array<bool> operator>(const Array<U>& other) const;
        template <typename U> Array<bool> operator>=(const Array<U>& other) const;
    };
}

#include "../src/Array.tpp"


