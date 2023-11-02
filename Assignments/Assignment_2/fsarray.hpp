//Jewel Maldonado
//CS311
//2023-09-20
//fsarray.hpp

#ifndef FSARRAY_HPP
#define FSARRAY_HPP

#include <algorithm>  // For std::copy, std::equal
#include <cstddef>    // For std::size_t

template<typename T>
class FSArray {
public:
    using value_type = T;
    using size_type = std::size_t;

    // Constructors
    FSArray() : m_data(new T[8]()), m_size(8) {}

    explicit FSArray(size_type n) : m_data(new T[n]()), m_size(n) {}

    FSArray(size_type n, const T& val) : m_data(new T[n]), m_size(n) {
        std::fill(m_data, m_data + m_size, val);
    }

    // Destructor
    ~FSArray() { delete[] m_data; }

    // Copy constructor
    FSArray(const FSArray& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }

    // Move constructor
    FSArray(FSArray&& other) noexcept : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // Copy assignment
    FSArray& operator=(const FSArray& other) {
        if (this != &other) {
            T* newData = new T[other.m_size];
            std::copy(other.m_data, other.m_data + other.m_size, newData);
            delete[] m_data;

            m_data = newData;
            m_size = other.m_size;
        }
        return *this;
    }

    // Move assignment
    FSArray& operator=(FSArray&& other) noexcept {
        if (this != &other) {
            std::swap(m_data, other.m_data);
            std::swap(m_size, other.m_size);
        }
        return *this;
    }

    // Bracket operator
    T& operator[](size_type idx) { return m_data[idx]; }
    const T& operator[](size_type idx) const { return m_data[idx]; }

    // Size function
    size_type size() const { return m_size; }

    // Begin and End for iterator support
    T* begin() { return m_data; }
    const T* begin() const { return m_data; }
    T* end() { return m_data + m_size; }
    const T* end() const { return m_data + m_size; }

    // Comparison operators
    friend bool operator==(const FSArray& lval, const FSArray& rval) {
        return lval.m_size == rval.m_size && std::equal(lval.m_data, lval.m_data + lval.m_size, rval.m_data);
    }

    friend bool operator!=(const FSArray& lval, const FSArray& rval) {
        return !(lval == rval);
    }

    friend bool operator<(const FSArray& lval, const FSArray& rval) {
        return std::lexicographical_compare(lval.begin(), lval.end(), rval.begin(), rval.end());
    }

    friend bool operator<=(const FSArray& lval, const FSArray& rval) {
        return !(rval < lval);
    }

    friend bool operator>(const FSArray& lval, const FSArray& rval) {
        return rval < lval;
    }

    friend bool operator>=(const FSArray& lval, const FSArray& rval) {
        return !(lval < rval);
    }

private:
    T* m_data;
    size_type m_size;
};

#endif  // FSARRAY_HPP
