#pragma once
#include "../include/Array.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
namespace np
{   


    template <typename T>
    void Array<T>::compute_strides(bool row_major) 
    {
       strides_.resize(shape_.size());
       
       if (row_major) 
       { 
           strides_.back() = 1; 
           for (int i = shape_.size() - 2; i >= 0; --i) 
           {
               strides_[i] = strides_[i + 1] * shape_[i + 1];
           }
       } 
       else 
       { // Ordre Fortran (column-major)
           strides_[0] = 1; 
           for (size_t i = 1; i < shape_.size(); ++i) {
               strides_[i] = strides_[i - 1] * shape_[i - 1];
           }
       }
   }
    template <typename T>
    template <typename... Args>
    Array<T>::Array(Args... args) 
    {
        shape_ = {static_cast<size_t>(args)...}; 
        size_t totalSize = 1;
        for (size_t dim : shape_) {
            totalSize *= dim;
        }
        compute_strides();
        data_ = std::vector<T>(totalSize, 0);
    }

    template <typename T>
    Array<T>::Array(const std::vector<size_t>& shape) : shape_(shape) {
        size_t totalSize = 1;
        for (size_t dim : shape_) 
        {
            totalSize *= dim;
        }
        compute_strides();
        data_ = std::vector<T>(totalSize, 0);
    }

    template <typename T>
    size_t Array<T>::compute_index(const vector<size_t>& indices) const
    {
        size_t index = 0;
        for (size_t i = 0; i < indices.size(); ++i) 
        {
            index += indices[i] * strides_[i];
        }
        return index;
    }

    template <typename T>
    T& Array<T>::operator[](vector<size_t> indices)
    {
        return (data_[compute_index(indices)]);
    }
    
    template <typename T>
    const T& Array<T>::operator[](vector<size_t> indices) const
    {
        return (data_[compute_index(indices)]);
    }

    template <typename T>
    const T& Array<T>::operator()(vector<size_t> indices) const
    {
        return (data_[compute_index(indices)]);
    }
    template <typename T>
    vector<size_t> Array<T>::shape() const
    {
        return (shape_);
    }
    template <typename T>
    size_t Array<T>::size() const
    {
        return (data_.size());
    }
    template <typename T>
    Array<T> Array<T>::operator+(const Array<T>& other)
    {
        if (shape_ != other.shape_)
        {
            cerr << "Impossible to add arrays: shape_="; 
            this->displayShape();
            cerr << "\nother.shape_=";
            other.displayShape(); 
            cerr<< endl;
            exit(3);
        }
        Array<T> result(shape_);
        for (size_t i = 0; i < data_.size(); i++)
        {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return (result);
    }

    template <typename T>
    Array<T> Array<T>::operator-(const Array<T>& other)
    {
        if (shape_ != other.shape_)
        {
            cerr << "Impossible to minus arrays: shape_="; 
            this->displayShape();
            cerr << "\nother.shape_=";
            other.displayShape(); 
            cerr<< endl;
            exit(4);
        }
        Array<T> result(shape_);
        for (size_t i = 0; i < data_.size(); i++)
        {
            result.data_[i] = data_[i] - other.data_[i];
        }
        return (result);
    }

    template <typename T>
    Array<T> Array<T>::operator*(const Array<T>& other)
    {
        if (shape_ != other.shape_)
        {
            cerr << "Impossible to multiply arrays: shape_="; 
            this->displayShape();
            cerr << "\nother.shape_=";
            other.displayShape(); 
            cerr<< endl;
            exit(5);
        }
        Array<T> result(shape_);
        for (size_t i = 0; i < data_.size(); i++)
        {
            result.data_[i] = data_[i] * other.data_[i];
        }
        return (result);
    }
    template <typename T>   
    Array<T> Array<T>::operator/(const Array<T>& other)
    {
        if (shape_ != other.shape_)
        {
            cerr << "Impossible to divide arrays: shape_="; 
            this->displayShape();
            cerr << "\nother.shape_=";
            other.displayShape(); 
            cerr<< endl;
            exit(6);
        }
        Array<T> result(shape_);
        for (size_t i = 0; i < data_.size(); i++)
        {   
            if (other.data_[i] == 0)
            {
                cerr << "Impossible to divide arrays: other.data_[" << i << "]=" << other.data_[i] << std::endl;
                exit(7);
            }
            result.data_[i] = data_[i] / other.data_[i];
        }
        return (result);
    }

    template <typename T>
    void Array<T>::display(ostream& os, size_t depth, size_t index) const
    {
        if (depth == shape_.size() - 1) // Dernière dimension (affichage direct)
        {
            os << "[";
            for (size_t i = 0; i < shape_[depth]; i++)
            {
                os << std::setw(3) << data_[index + i]; // Alignement pour la lisibilité
                if (i + 1 < shape_[depth])
                    os << ", ";
            }
            os << "]";
        }
        else // Dimensions supérieures (récursivité)
        {
            os << "[\n";
            size_t stride = 1;
            for (size_t i = depth + 1; i < shape_.size(); i++)
                stride *= shape_[i];

            for (size_t i = 0; i < shape_[depth]; i++)
            {
                os << std::string((depth + 1) * 2, ' '); // Indentation
                display(os, depth + 1, index + i * stride);
                if (i + 1 < shape_[depth])
                    os << ",\n";
            }
            os << "\n" << std::string(depth * 2, ' ') << "]";
        }
    }

    template <typename T>
    void Array<T>::display(ostream& os) const
    {
        if (shape_.empty())
        {
            os << "[]";
            return;
        }
        display(os, 0, 0);
        os << "\n";
    }

    template <typename T>
    void Array<T>::displayShape() const
    {
        cout << "Shape(";
        for (size_t i = 0; i < shape_.size(); i++)
        {
            cout << shape_[i];  
            if (i + 1 < shape_.size())
            {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    template <typename T>
    T& Array<T>::operator[](size_t index)
    {
        return(data_[index]);
    }
    template <typename T>
    Array<T> Array<T>::slice(size_t begin, size_t end, size_t pas)
    {
    
        if (begin >= end || begin >= shape_[0] || end > shape_[0])
        {
            throw std::out_of_range("Slice indices out of range");
        }
        if (pas == 0 || pas > (end - begin))
        {
            throw std::out_of_range("Step (pas) is invalid");
        }
     
        size_t i, j;
        size_t original_index;
        size_t total_elements = 1; 

        for (size_t k = 1; k < shape_.size(); ++k)
        {
            total_elements *= shape_[k];
        }
    
        vector<size_t> new_shape = shape_;
        new_shape[0] = (end - begin + pas - 1) / pas; 
  
        Array<T> result(new_shape);
    
        for (i = 0; i < new_shape[0]; i++)  
        {
            for (j = 0; j < total_elements; ++j) 
            {
                original_index = (begin + i * pas) * total_elements + j;
                result.data_[i * total_elements + j] = data_[original_index];
            }
        }
    
        return result;
    }
    
    
    template <typename T>
    template <typename... Args>
    void Array<T>::reshape(Args... args)
    {
        vector<size_t> new_shape= {static_cast<size_t>(args)...};
        size_t s=1;
        for (auto i:new_shape)
        {
            s*=i;
        }
        if (s!=this->size())
        {
            throw(std::invalid_argument("Reshape not allowed")); 
        }
        shape_= move(new_shape);
        compute_strides();
    }
    template <typename T>
    void Array<T>::fill(T value)
    {
        size_t i;
        std::fill(data_.begin(),data_.end(),value);
    }
    
    template <typename T>
    bool Array<T>::contains(T var)
    {
        for (auto t : data_)
        {
            if (var == t)
            {
                return(true);
            }
        }
        return(false);
    }
    template <typename T>
    Array<T> Array<T>::slice(vector<size_t> partial_indices)
    {
        if (partial_indices.size() > shape_.size()) 
        {
            throw std::invalid_argument("Too many indices for slicing.");
        }
    
        size_t base_index = 0;
        size_t j = 1;
        for (size_t i = partial_indices.size(); i-- > 0;)
        {
            if (partial_indices[i] >= shape_[i])
            {
                cerr << "Impossible to compute index: indices.size()=" << partial_indices.size() << " shape[" << i << "]=" << shape_[i] << " indices[" << i << "]=" << partial_indices[i] << std::endl;
                exit(2);
            }
            base_index += partial_indices[i] * j;
            j *= shape_[i];
        }
        vector<size_t> new_shape(shape_.begin() + partial_indices.size(), shape_.end());
        size_t subarray_size = 1;
        for (auto s : new_shape) subarray_size *= s;
    
        vector<T> sub_data(data_.begin() + base_index,
                           data_.begin() + base_index + subarray_size);
    
        Array<T> result;
        result.shape_ = new_shape;
        result.data_ = std::move(sub_data);
        return (result);
    }

    template <typename T>
    Array<T> Array<T>::slice(const std::vector<std::tuple<long, long, long>>& slices) const {
        if (slices.size() != shape_.size()) 
        {
            throw std::invalid_argument("Number of slices must match array dimensions");
        }

        // Calculer la nouvelle shape et les nouveaux strides
        std::vector<size_t> new_shape;
        std::vector<size_t> new_strides;
        std::vector<size_t> offsets;

        for (size_t dim = 0; dim < shape_.size(); ++dim) {
            auto [start, stop, step] = slices[dim];
            
            // Gérer les valeurs négatives et les valeurs par défaut
            if (start < 0) start += shape_[dim];
            if (stop < 0) stop += shape_[dim];
            start = std::clamp<long>(start, 0, shape_[dim]);
            stop = std::clamp<long>(stop, 0, shape_[dim]);
            if (step == 0) step = 1;

            // Calculer la taille de la nouvelle dimension
            size_t dim_size = (stop - start + step - 1) / step;
            if (step < 0) {
                dim_size = (start - stop - step - 1) / (-step);
            }

            new_shape.push_back(dim_size);
            new_strides.push_back(strides_[dim] * step);
            offsets.push_back(start * strides_[dim]);
        }

        // Créer le nouveau tableau
        Array<T> result;
        result.shape_ = new_shape;
        result.strides_ = new_strides;

        // Copier les données avec le bon pas
        std::vector<size_t> indices(new_shape.size(), 0);
        while (true) 
        {
            // Calculer l'offset total
            size_t offset = 0;
            for (size_t dim = 0; dim < new_shape.size(); ++dim) 
            {
                offset += offsets[dim] + indices[dim] * new_strides[dim];
            }
            result.data_.push_back(data_[offset]);

            // Incrémenter les indices
            size_t dim = new_shape.size() - 1;
            while (true) {
                indices[dim]++;
                if (indices[dim] < new_shape[dim]) break;
                if (dim == 0) goto end_loop;
                indices[dim] = 0;
                dim--;
            }
        }
        end_loop:

        return result;
    }
    template <typename T>
    template <typename U>
    void Array<T>::parse(const std::initializer_list<U>& list, 
                     std::vector<size_t>& current_shape,
                     std::vector<T>& flat_data,
                     size_t depth) 
    {
              if (depth >= current_shape.size()) {
                  current_shape.push_back(list.size());
              } else if (current_shape[depth] != list.size()) {
                  throw std::invalid_argument("Inconsistent dimensions");
              }
      
              for (const auto& item : list) {
                  if constexpr (std::is_convertible_v<U, T>) {
                      flat_data.push_back(static_cast<T>(item));
                  } else {
                      parse(item, current_shape, flat_data, depth + 1);
                  }
              }
          }
    template<typename T>
    template <typename U>
    Array<T>::Array(const std::initializer_list<U>& list) 
    {
              std::vector<size_t> shape;
              std::vector<T> flat_data;
              parse(list, shape, flat_data);
              shape_ = shape;
              data_ = flat_data;
              compute_strides(); 
    }    
    template <typename T>
    const T& Array<T>::operator[](size_t index) const {
        if (index >= data_.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index]; 
    }


    template <typename T, typename U>
    constexpr bool is_comparable_v = std::is_convertible_v<U,T> || std::is_convertible_v<T,U>;

    // Implémentation des opérateurs membres -------------------------------------

    #define IMPLEMENT_SCALAR_OP(OP) \
    template <typename T> \
    template <typename U> \
    Array<bool> Array<T>::operator OP(const U& scalar) const { \
        static_assert(is_comparable_v<T,U>, "Incomparable types"); \
        Array<bool> result(shape_); \
        std::transform(data_.begin(), data_.end(), result.begin(), \
            [scalar](T val) { return val OP static_cast<T>(scalar); }); \
        return result; \
    }

    IMPLEMENT_SCALAR_OP(==)
    IMPLEMENT_SCALAR_OP(!=)
    IMPLEMENT_SCALAR_OP(<)
    IMPLEMENT_SCALAR_OP(<=)
    IMPLEMENT_SCALAR_OP(>)
    IMPLEMENT_SCALAR_OP(>=)

    #undef IMPLEMENT_SCALAR_OP

    #define IMPLEMENT_ARRAY_OP(OP) \
    template <typename T> \
    template <typename U> \
    Array<bool> Array<T>::operator OP(const Array<U>& other) const { \
        static_assert(is_comparable_v<T,U>, "Incomparable types"); \
        if (shape_ != other.shape()) { \
            throw std::invalid_argument("Shape mismatch in array comparison"); \
        } \
        Array<bool> result(shape_); \
        std::transform(data_.begin(), data_.end(), other.begin(), result.begin(), \
            [](T a, U b) { return a OP static_cast<T>(b); }); \
        return result; \
    }

    IMPLEMENT_ARRAY_OP(==)
    IMPLEMENT_ARRAY_OP(!=)
    IMPLEMENT_ARRAY_OP(<)
    IMPLEMENT_ARRAY_OP(<=)
    IMPLEMENT_ARRAY_OP(>)
    IMPLEMENT_ARRAY_OP(>=)

    #undef IMPLEMENT_ARRAY_OP

} // namespace np
