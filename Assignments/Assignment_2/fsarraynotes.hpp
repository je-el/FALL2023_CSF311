// Guard to prevent the header file from being included more than once
#ifndef FSARRAYNOTES_HPP 
#define FSARRAYNOTES_HPP

#include <algorithm>  // For std::copy, std::equal
#include <cstddef>    // For std::size_t

// Template definition for FSArray class, allowing for any data type T
template<typename T>
class FSArray {
public:
    using value_type = T;  // Typedef to represent the data type of elements
    using size_type = std::size_t;  // Typedef for unsigned int to represent sizes

    // Default constructor, initializes an array of size 8
    FSArray() : m_data(new T[8]()), m_size(8) {}

    // Parameterized constructor to specify size, initializes each element to default value
    explicit FSArray(size_type n) : m_data(new T[n]()), m_size(n) {}

    // Parameterized constructor to specify size and initial value for all elements
    FSArray(size_type n, const T& val) : m_data(new T[n]), m_size(n) {
        std::fill(m_data, m_data + m_size, val);
    }

    // Destructor to clean up dynamically allocated memory
    ~FSArray() { delete[] m_data; }

    // Copy constructor to allow deep copying of the array
    FSArray(const FSArray& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }

    // Move constructor for efficient transfer of ownership of the array
    FSArray(FSArray&& other) noexcept : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // Copy assignment operator for deep copying
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

    // Move assignment operator for efficient transfer of ownership
    FSArray& operator=(FSArray&& other) noexcept {
        if (this != &other) {
            std::swap(m_data, other.m_data);
            std::swap(m_size, other.m_size);
        }
        return *this;
    }

    // Overloading the [] operator for element access
    T& operator[](size_type idx) { return m_data[idx]; }
    const T& operator[](size_type idx) const { return m_data[idx]; }  // Const version

    // Function to return the size of the array
    size_type size() const { return m_size; }

    // Begin and end functions to support iteration over the array
    T* begin() { return m_data; }
    const T* begin() const { return m_data; }  // Const version
    T* end() { return m_data + m_size; }
    const T* end() const { return m_data + m_size; }  // Const version

    // Comparison operators for comparing two FSArray objects
    friend bool operator==(const FSArray& lval, const FSArray& rval) {
        return lval.m_size == rval.m_size && std::equal(lval.m_data, lval.m_data + lval.m_size, rval.m_data);
    }

    // Other comparison operators, utilizing the == and < operators
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
    T* m_data;  // Pointer to the first element of the dynamic array
    size_type m_size;  // The size of the dynamic array
};

#endif  // FSARRAYNOTES_HPP
