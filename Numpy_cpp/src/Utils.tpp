// Utils.tpp
#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <unordered_set>
#include <fstream>
#include <chrono>
#include <random>
#include "../include/Utils.hpp"
#include "../include/Array.hpp"

namespace np
{
    template <typename T, typename... Args>
    Array<T> ones(Args... args)
    {
        Array<T> arr(args...);
        arr.fill(1);
        return arr;
    }

    template <typename T , typename... Args>
    Array<T> zeros(Args... args)
    {
        Array<T> arr(args...);
        arr.fill(0);
        return arr;
    }

    template <typename T>
    ostream& operator<<(ostream& os, const Array<T>& p)
    {
        p.display(os); 
        return (os);
    }

    template <typename T>
    Array<T> sum(const Array<T>& arr, vector<int> axes) 
    {
        if (axes.empty()) 
        {
            axes.push_back(-1);
        }
    
        // Normalise axes : -1 veut dire "tous les axes"
        if (axes[0] == -1) {
            T result = 0;
            for (size_t i = 0; i < arr.size(); ++i) {
                result += arr[i];
            }
            Array<T> out(1);
            out[0] = result;
            return out;
        }
    
        // Tri et suppression des doublons (au cas où)
        std::sort(axes.begin(), axes.end());
        axes.erase(std::unique(axes.begin(), axes.end()), axes.end());
    
        // Vérifie que les axes sont valides
        auto shape = arr.shape();
        for (int axis : axes) {
            if (axis < 0 || static_cast<size_t>(axis) >= shape.size()) {
                throw std::invalid_argument("Invalid axis in sum()");
            }
        }
    
        // Axe le plus à gauche → plus simple à traiter d’abord
        int axis = axes[0];
    
        std::vector<size_t> new_shape = shape;
        new_shape.erase(new_shape.begin() + axis);
    
        Array<T> result(new_shape);
    
        // Indices de parcours
        std::vector<size_t> index(shape.size(), 0);
        std::vector<size_t> res_index = index;
        res_index.erase(res_index.begin() + axis);
    
        do {
            T acc = 0;
            for (index[axis] = 0; index[axis] < shape[axis]; ++index[axis]) {
                acc += arr[index];
            }
            result[res_index] = acc;
    
            // Incrémente tous les index sauf celui qu'on a réduit
            size_t dim = shape.size();
            bool carry = true;
            for (int i = dim - 1; i >= 0; --i) {
                if (i == axis) continue;
                index[i]++;
                res_index[i < axis ? i : i - 1]++;
                if (index[i] < shape[i]) {
                    carry = false;
                    break;
                } else {
                    index[i] = 0;
                    res_index[i < axis ? i : i - 1] = 0;
                }
            }
            if (carry) break;
    
        } while (true);
    
        // Appel récursif si plusieurs axes
        if (axes.size() > 1) 
        {
            std::vector<int> remaining_axes(axes.begin() + 1, axes.end());
            // Les axes restants sont à ajuster (décrémentés de 1 si > axis)
            for (int& a : remaining_axes) 
            {
                if (a > axis) --a;
            }
            return sum(result, remaining_axes);
        }
    
        return result;
    }

    template <typename T>
    T sum(const Array<T>& arr)
    {
        T result = 0;
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result += arr[i];
        }
        return result;
    }
    template <typename T>
    Array<T> unique(const Array<T>& arr) 
    {
        std::unordered_set<T> seen;
        std::vector<T> uniques;
        for (size_t i = 0; i < arr.size(); ++i) {
            if (seen.insert(arr[i]).second) 
            {
                uniques.push_back(arr[i]);
            }
        }
        Array<T> result(std::vector<size_t>{uniques.size()});

        for (size_t i = 0; i < uniques.size(); ++i) {
            result[i] = uniques[i];
        }
        return result;
    }

    template <typename T>
    T mean(const Array<T>& arr) 
    {
        T sum = std::accumulate(arr.begin(), arr.end(), static_cast<T>(0));
        return sum / arr.size();
    }

    template <typename T>
    T min(const Array<T>& arr) 
    {
        return *std::min_element(arr.begin(), arr.end());
    }

    template <typename T>
    T max(const Array<T>& arr) 
    {
        return *std::max_element(arr.begin(), arr.end());
    }

    template <typename T>
    Array<T> cos(const Array<T>& arr) 
    {
        Array<T> result(arr.shape());
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result[i] = std::cos(arr[i]);
        }
        return result;
    }

    template <typename T>
    Array<T> sin(const Array<T>& arr) {
        Array<T> result(arr.shape());
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result[i] = std::sin(arr[i]);
        }
        return result;
    }

    template <typename T>
    Array<T> sqrt(const Array<T>& arr) {
        Array<T> result(arr.shape());
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result[i] = std::sqrt(arr[i]);
        }
        return result;
    }

    template <typename T>
    Array<T> log(const Array<T>& arr) 
    {
        Array<T> result(arr.shape());
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result[i] = std::log(arr[i]);
        }
        return result;
    }

    template <typename T>
    Array<T> exp(const Array<T>& arr) {
        Array<T> result(arr.shape());
        for (size_t i = 0; i < arr.size(); ++i) 
        {
            result[i] = std::exp(arr[i]);
        }
        return(result);
    }

    template <typename T>
    void save_csv(const std::string& filename, const np::Array<T>& arr) 
    {
        std::ofstream out(filename);
        if (!out) throw std::runtime_error("Can't open file to write.");

        // Écrire le shape
        const auto& shape = arr.shape();
        for (size_t i = 0; i < shape.size(); ++i) {
            out << shape[i];
            if (i < shape.size() - 1) out << ",";
        }
        out << "\n";

        for (size_t i = 0; i < arr.size(); ++i) {
            out << arr[i];
            if (i < arr.size() - 1) out << ",";
        }
        out << "\n";
        out.close();
    }


    template <typename T>
    np::Array<T> load_csv(const std::string& filename) 
    {
        std::ifstream in(filename);
        if (!in) throw std::runtime_error("Can't open file to read.");

        std::string shape_line, data_line;

        // Lire shape
        std::getline(in, shape_line);
        std::stringstream shape_ss(shape_line);
        std::vector<size_t> shape;
        std::string s;
        while (std::getline(shape_ss, s, ',')) 
        {
            shape.push_back(std::stoul(s));
        }

        // Lire data
        std::getline(in, data_line);
        std::stringstream data_ss(data_line);
        std::vector<T> data;
        while (std::getline(data_ss, s, ',')) {
            if constexpr (std::is_same<T, int>::value)
                data.push_back(std::stoi(s));
            else if constexpr (std::is_same<T, float>::value || std::is_same<T, double>::value)
                data.push_back(std::stod(s));
        }

        // Vérif taille
        size_t total_size = 1;
        for (size_t dim : shape) total_size *= dim;
        if (data.size() != total_size) 
        {
            throw std::runtime_error("Data size does not match shape.");
        }

        // Remplir tableau
        np::Array<T> arr(shape);
        for (size_t i = 0; i < data.size(); ++i) {
            arr[i] = data[i];
        }
        return arr;
    }
    template <typename T>
    np::Array<T> arange(const T start, const T end, const T pas) {   
        if (end < start) 
        {
            throw std::invalid_argument("argument invalid, end < start");
        } else if (end - start == 0) 
        {
            Array<T> r(1);
            r[0] = start;
            return r;
        } else 
        {
            std::vector<T> tmp;
            T value = start;  
            while (value < end) {
                tmp.push_back(value);
                value += pas;
            }
            
            Array<T> result(tmp.size());
            for (size_t i = 0; i < tmp.size(); i++) {
                result[i] = tmp[i];
            }
            return (result);
        }
    }


    template <typename T>
    Array<T> eye(const size_t m, const size_t n, const int k) {
        size_t _n = n;
        if (_n == 0) _n = m;
    
        Array<T> result(std::vector<size_t>{m, _n});
    
        for (size_t i = 0; i < m; i++) {
            int j = static_cast<int>(i) + k;
            if (j >= 0 && static_cast<size_t>(j) < _n) {
                result[std::vector<size_t>{i, static_cast<size_t>(j)}] = static_cast<T>(1);
            }
        }
    
        return result;
    }

    template<typename T>
    Array<T> rand(const std::vector<size_t>& shape) 
    {
        size_t total_size = 1;
        for (auto dim : shape)
            total_size *= dim;

        Array<T> result(shape);
        std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<T> dist(0.0, 1.0);

        for (size_t i = 0; i < total_size; ++i)
            result[i] = dist(gen);

        return result;
    }
    
    
    template<typename T = float>
    Array<T> randn(const std::vector<size_t>& shape) 
    {
        size_t total_size = 1;
        for (auto dim : shape)
            total_size *= dim;

        Array<T> result(shape);
        std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
        std::normal_distribution<T> dist(0.0, 1.0);

        for (size_t i = 0; i < total_size; ++i)
            result[i] = dist(gen);

        return(result);

        
    }
    template <typename T>
    Array<T> linspace(T start, T stop, size_t num) 
    {
        if (num == 0) {
            throw std::invalid_argument("np::linspace: num must be >= 1");
        }
    
        Array<T> result(vector<size_t>{num});
    
        if (num == 1) 
        {
            result[0] = start;
            return result;
        }
    
        T step = (stop - start) / static_cast<T>(num - 1);
        for (size_t i = 0; i < num; ++i) {
            result[i] = start + step * static_cast<T>(i);
        }
    
        return(result);
    }


    bool advance_index(std::vector<size_t>& index, const std::vector<size_t>& shape)
    {
        for (int i = shape.size() - 1; i >= 0; --i)
        {
            index[i]++;
            if (index[i] < shape[i])
                return true;
            index[i] = 0;
        }
        return false;
    }

    template <typename T>
    Array<T> concat(const Array<T>& a, const Array<T>& b, size_t axis)
    {
        if (a.shape().size() != b.shape().size())
                throw std::invalid_argument("Arrays must have the same number of dimensions");

        std::vector<size_t> result_shape = a.shape();
        result_shape[axis] += b.shape()[axis];

        for (size_t i = 0; i < a.shape().size(); ++i)
        {
            if (i != axis && a.shape()[i] != b.shape()[i])
                throw std::invalid_argument("Shapes must match on non-concatenation axes");
        }

        Array<T> result(result_shape);

        // Copie des éléments de `a`
        std::vector<size_t> indices(a.shape().size(), 0);
        do 
        {
            result[indices] = a[indices];
        } while (advance_index(indices, a.shape()));

        indices.assign(b.shape().size(), 0);
        do 
        {
            std::vector<size_t> target = indices;
            target[axis] += a.shape()[axis];
            result[target] = b[indices];
        } while (advance_index(indices, b.shape()));

        return (result);
    } 


    template <typename T >
    Array<T> abs(Array<T> arr)
    {   
        size_t i;
        for ( i = 0; i < arr.size(); i++)
        {
            arr[i] = arr[i] >= 0 ? arr[i] : -arr[i];
        }

        return(arr);
    }


    template <typename T>
    Array<T> dot(const Array<T>& a, const Array<T>& b) 
    {
        if (a.shape().size() != 2 || b.shape().size() != 2 || 
            a.shape()[1] != b.shape()[0]) {
            throw std::invalid_argument("Incompatible dimensions for dot product");
        }
    
        size_t m = a.shape()[0];
        size_t n = b.shape()[1];
        size_t p = a.shape()[1];
    
        Array<T> result(m, n);
        size_t i,k,j;
        for (i = 0; i < m; ++i) {
            for ( j = 0; j < n; ++j) {
                T sum = 0;
                for (k = 0; k < p; ++k) 
                {
                    sum += a[{i, k}] * b[{k, j}];
                }
                result[{i, j}] = sum;
            }
        }
    
        return result;
    }

    template <typename T>
    Array<T> transpose(const Array<T>& arr) 
    {
        if (arr.shape().size() != 2) {
            throw std::invalid_argument("Transpose only implemented for 2D arrays");
        }

        size_t rows = arr.shape()[0];
        size_t cols = arr.shape()[1];
        Array<T> result(cols,rows);
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {   
                result[{j, i}] = arr[{i, j}];
            }
        }
        
        return result;
    }
    template <typename T>
    Array<bool> operator==(const Array<T>& lhs, const Array<T>& rhs) {
        // Vérifiez que les shapes sont compatibles (broadcasting!)
        Array<bool> result(lhs.shape());
        std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(),
                    [](T a, T b) { return a == b; });
        return result;
    }
    #define IMPLEMENT_FREE_OP(OP) \
    template <typename U, typename V> \
    Array<bool> operator OP(const U& scalar, const Array<V>& arr) { \
        static_assert(is_comparable_v<V,U>, "Incomparable types"); \
        return arr OP scalar; \
    }

    IMPLEMENT_FREE_OP(==)
    IMPLEMENT_FREE_OP(!=)
    IMPLEMENT_FREE_OP(<)
    IMPLEMENT_FREE_OP(<=)
    IMPLEMENT_FREE_OP(>)
    IMPLEMENT_FREE_OP(>=)

    #undef IMPLEMENT_FREE_OP
}
 