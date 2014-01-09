
#ifndef DD2387_lab1_vector_h
#define DD2387_lab1_vector_h

#include <cstdlib>      // size_t
#include <iostream>     // std::initializer_list
#include <stdexcept>    // std::out_of_range
#include <algorithm>    // std::sort, std::unique
#include <iterator>     // std::reverse_iterator

template <class T>
class Vector
{
public:
    /*
     * Default vector. Create a 0-sized vector.
     */
    Vector<T>();
	/*
	 * Create a vector of given size and initialize all elements to
	 * default for type T
	 */
    explicit Vector<T>(size_t size=0);
    /*
     * Create a vector of given size and initialize all elements to value.
     */
    Vector<T>(size_t size, T value);
    
    
    /*
     * Copy constructor
     */
    Vector<T>(const Vector<T> & source);
    /*
     * Assignment operator
     */
    Vector<T> & operator=(Vector<T> source);
    /*
     * Destructor
     */
    ~Vector<T>();
    
    
    /*
     * Move constructor
     */
    Vector<T>(Vector<T> && source);
    
    
    /*
     * Constructor using std::initializer_list as parameter.
     */
    Vector<T>(std::initializer_list<T> list);
    
    
    /*
     * Swap content with another vector. Using std::swap
     */
    void swap(Vector & other);
    
    
    /*
     * Overloading the subscript operator.
     */
    T & operator[](size_t index);
    /*
     * Overloading the subscript operator, used for constant vectors.
     */
    const T & operator[](size_t index) const;
    
    
    /********************************************************
     * additional funtionality
     *******************************************************/
    /*
     * Add element to the end of the vector.
     */
    void push_back(T obj);
    /*
     * Add element at specified index in vector.
     */
    void insert(size_t index, T obj);
    /*
     * Remove element at given index.
     */
    void erase(size_t index);
    /*
     * Remove all elements.
     */
    void clear();
    /*
     * Return size of vector.
     */
    const size_t size() const;
    /*
     * Sort the vector in the given direction.
     */
    void sort(bool ascending=true);
    /*
     * Sort the vector in the given direction and remove all duplicates.
     */
    void unique_sort(bool ascending=true);
    /*
     * Check if element is in vector.
     */
    bool exists(const T & obj);
    
    
    /********************************************************
     * Usefull functions
     *******************************************************/
    /*
     * Return iterator to beginning of vector.
     */
    T * begin();
    /*
     * Return iterator after the end of the vector.
     */
    T * end();
    /*
     * Return iterator to reverse beginning of vector.
     */
    std::reverse_iterator<T*> rbegin();
    /*
     * Return iterator to reverse end of vector.
     */
    std::reverse_iterator<T*> rend();
private:
	/*
	 * Allocate new memory to fit the new larger vector.
	 */
    void reserve();
    
    
private:
	/*
	 * Size of vector.
	 */
    size_t vec_size;
    /*
     * Capacity of vector. Should be the same as the size of the buffer.
     */
    size_t vec_capacity;
    /*
     * Pointer to a allocated memory space to store the vector.
     */
    T * buffer;
};


/*************************************************************
 *************************************************************
 * IMPLEMENTATION
 *************************************************************
 ************************************************************/

/*
 * Default vector. Create a 0-sized vector.
 */
template <class T>
Vector<T>::Vector() :
vec_size(0),
vec_capacity(10),
buffer(new T[10])
{}

/*
 * Create a vector of given size and initialize all elements to
 * default for type T
 */
template <class T>
Vector<T>::Vector(size_t size) :
vec_size(size),
vec_capacity(10+size),
buffer(new T[10+size])
{
    for (size_t i=0; i<size; ++i)
        buffer[i] = T();
}

/*
 * Create a vector of given size and initialize all elements to value.
 */
template <class T>
Vector<T>::Vector(size_t size, T value) :
vec_size(size),
vec_capacity(10+size),
buffer(new T[10+size])
{
    for (size_t i=0; i<size; ++i)
        buffer[i] = value;
}


/********************************************************
 * rule of three
 *******************************************************/

/*
 * Copy constructor.
 */
template <class T>
Vector<T>::Vector(const Vector<T> & source) :
vec_size(source.vec_size),
vec_capacity(source.vec_capacity),
buffer(new T[source.vec_capacity])
{
    for (size_t i=0; i<vec_size; ++i)
        buffer[i] = source.buffer[i];
}

/*
 * Assignment operator.
 */
template <class T>
Vector<T> & Vector<T>::operator=(Vector<T> source)
{
    swap(source);
    return *this;
}

/*
 * Destructor
 */
template <class T>
Vector<T>::~Vector()
{
    if (buffer != NULL)
        delete[] buffer;
}


/*
 * Move constructor
 */
template <class T>
Vector<T>::Vector(Vector<T> && source) :
buffer(NULL)
{
    swap(source);
}


/*
 * Constructor using std::initializer_list as parameter.
 */
template <class T>
Vector<T>::Vector(std::initializer_list<T> list) :
vec_size(list.size()),
vec_capacity(10+list.size()),
buffer(new T[10+list.size()])
{
    T * ptr = buffer;
    for (T i : list)
        *ptr++ = i;
}


/*
 * Swap content with another vector. Using std::swap
 */
template <class T>
void Vector<T>::swap(Vector<T> & other)
{
    using std::swap;
    swap(vec_size, other.vec_size);
    swap(vec_capacity, other.vec_capacity);
    swap(buffer, other.buffer);
}

/********************************************************
 * subscript operator
 *******************************************************/

/*
 * Overloading the subscript operator.
 */
template <class T>
T & Vector<T>::operator[](size_t index)
{
    if (index >= vec_size)
        throw std::out_of_range("Index out of range");
    return buffer[index];
}

/*
 * Overloading the subscript operator, used for constant vectors.
 */
template <class T>
const T & Vector<T>::operator[](size_t index) const
{
    if (index >= vec_size)
        throw std::out_of_range("Index out of range");
    return buffer[index];
}


/********************************************************
 * additional funtionality
 *******************************************************/

/*
 * Add element to the end of the vector.
 */
template <class T>
void Vector<T>::push_back(T obj)
{
    vec_size++;
    reserve();
    buffer[vec_size-1] = obj;
}

/*
 * Add element at specified index in vector.
 */
template <class T>
void Vector<T>::insert(size_t index, T obj)
{
    if (index > vec_size)
        throw std::out_of_range("Index out of range");
    
    if (index == vec_size) {
        push_back(obj);
        return;
    }
    
    vec_size++;
    reserve();
    for (size_t i=vec_size-1; i>index; --i)
        buffer[i] = buffer[i-1];
    buffer[index] = obj;
}

/*
 * Remove element at given index.
 */
template <class T>
void Vector<T>::erase(size_t index)
{
    if (index >= vec_size)
        throw std::out_of_range("Index out of range");
    
    for (size_t i=index; i < vec_size-1; ++i)
        buffer[i] = buffer[i+1];
    vec_size--;
}

/*
 * Remove all elements.
 */
template <class T>
void Vector<T>::clear()
{
    vec_size = 0;
}

/*
 * Return the size of the vector.
 */
template <class T>
const size_t Vector<T>::size() const
{
    return vec_size;
}

/*
 * Sort the vector in the given direction.
 */
template <class T>
void Vector<T>::sort(bool ascending)
{
    if (ascending)
        std::sort(begin(), end());
    else
        std::sort(rbegin(), rend());
}

/*
 * Sort the vector in the given direction and remove all duplicates.
 */
template <class T>
void Vector<T>::unique_sort(bool ascending)
{
    // sort the vector
    sort(ascending);
    // remove all duplicates
    T * ptr = std::unique(begin(), end());
    // adjust size of vector accordingly
    vec_size = ptr-begin();
}

/*
 * Check if element is in vector.
 */
template <class T>
bool Vector<T>::exists(const T & obj)
{
    T * ptr = std::find(begin(), end(), obj);
    
    if (ptr == end())
        return false;
    return true;
}

/********************************************************
 * Usefull functions?
 *******************************************************/

/*
 * Return iterator to beginning of vector.
 */
template <class T>
T * Vector<T>::begin()
{
    return buffer;
}

/*
 * Return iterator after the end of the vector.
 */
template <class T>
T * Vector<T>::end()
{
    return buffer + size();
}

/*
 * Return iterator to reverse beginning of vector.
 */
template <class T>
std::reverse_iterator<T*> Vector<T>::rbegin()
{
    return std::reverse_iterator<T*>(buffer + size());
}

/*
 * Return iterator to reverse end of vector.
 */
template <class T>
std::reverse_iterator<T*> Vector<T>::rend()
{
    return std::reverse_iterator<T*>(buffer);
}

/*
 * Allocate new memory to fit the new larger vector.
 */
template <class T>
void Vector<T>::reserve()
{
    // If allocated memory is not large enough
    if (vec_capacity < vec_size){
        // double the capacity
        vec_capacity *= 2;
        T * tmpBuffer = new T[vec_capacity];
        // copy everything from old buffer to new
        for (int i=0; i<vec_size-1; ++i)
            tmpBuffer[i] = buffer[i];
        
        // delete old buffer and point to new one instead.
        delete[] buffer;
        buffer = tmpBuffer;
    }
}

#endif
