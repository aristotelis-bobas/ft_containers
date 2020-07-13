/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/13 17:37:35 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdint>
#include <stdexcept>

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
            T *_array;
            uint32_t _size;
            uint32_t _capacity;
        public:
            Vector()
            {
                _array = new T[128];
                _size = 0;
                _capacity = 128;
            }
            Vector(uint32_t n, const T &val)
            {
                _array = new T[n];
                _capacity = n;
                _size = 0;
                for (uint32_t i = 0; i < n; i++)
                    this->push_back(val);
            }
            // Vector(IteratorFirst, IteratorLast)
            Vector(Vector<T> const &other)
            {
                _array = new T[other.capacity];
                _size = 0;
                _capacity = other.capacity;
                for (uint32_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
            }
            Vector& operator=(Vector<T> const &other)
            {
                delete[] _array;
                _array = new T[other.capacity];
                _capacity = other.capacity;
                _size = 0;
                for (uint32_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
                return (*this);
            }
            ~Vector()
            {
                delete[] _array;
                _size = 0;
                _capacity = 0;
            }
            /*
                begin()
                end()
                rbegin()
                rend()
            */
            uint32_t size() const
            {
                return (this->size);
            }
            //  uint32_t max_size() const;
            void resize(uint32_t n)
            {
                T *temp = T[n];
                uint32_t temp_size = 0;
                for (uint32_t i = 0; i < this->size() && i < n; i++)
                {
                    temp[i] = _array[i];
                    temp_size++;
                }
                delete[] _array;
                _array = temp;
                _size = temp_size;
                _capacity = n;
            }
            uint32_t capacity() const
            {
                return (this->capacity);
            }
            bool empty() const
            {
                if (_size == 0)
                    return (true);
                else
                    return (false);
            }
            void reserve(uint32_t n)
            {
                while (_capacity < n)
                    this->resize(_capacity * 2);
            }
            T& operator[](uint32_t n)
            {
                return (_array[n]);
            }
            const T& operator[](uint32_t n) const
            {
                return (_array[n]);
            }
            T& at(uint32_t n)
            {
                if (n >= this->size)
                    throw std::out_of_range("Out of range");
                else
                    return (_array[n]);
            }
            const T& at(uint32_t n) const
            {
                if (n >= this->size)
                    throw std::out_of_range("Out of range");
                else
                    return (_array[n]);
            }
            T& front()
            {
                return (_array[0]);
            }
            const T& front() const
            {
                return (_array[0]);
            }
            T& back()
            {
                return (_array[_size - 1]);
            }
            const T& back() const
            {
                return (_array[_size - 1]);
            }
            void push_back(const T &val)
            {
                if (_size == this->capacity)
                    this->resize(_capacity * 2);
                _array[this->size] = val;
                this->size++;
            }
            void pop_back()
            {
                _array[_size - 1] = 0;
                this->size--;
            }
            void swap(Vector<T> &other)
            {
                T temp[] = T[other.capacity()];
                uint32_t temp_size = 0;
                uint32_t temp_capacity = other.capacity();
                for (uint32_t i = 0; i < other.size(); i++)
                {
                    temp[i] = other._array[i];
                    temp_size++;
                }
                delete[] other._array;
                other._array = T[this->capacity()];
                other._capacity = this->capacity();
                other._size = 0;
                for (uint32_t i = 0; i < this->size(); i++)
                    other.push_back(_array[i]);
                delete[] _array;
                _array = T[temp_capacity];
                _capacity = temp_capacity;
                _size = 0;
                for (uint32_t i = 0; i < temp_size; i++)
                    this->push_back(temp[i]);
            }
            void clear()
            {
                for (uint32_t i = this->size() - 1; i >= 0; i--)
                    _array[i] = 0;
                _size = 0;
            }
            /*
                assign()
                insert()
                erase()
            */
    };

    template <typename T>
    void swap(Vector<T> &first, Vector<T> &second)
    {
        T temp[] = T[second.capacity()];
        uint32_t temp_size = 0;
        uint32_t temp_capacity = second.capacity();
        for (uint32_t i = 0; i < second.size(); i++)
        {
            temp[i] = second._array[i];
            temp_size++;
        }
        delete[] second._array;
        second._array = T[first.capacity()];
        second._capacity = first.capacity();
        second._size = 0;
        for (uint32_t i = 0; i < first.size(); i++)
            second.push_back(first.array[i]);
        delete[] first.array;
        first._array = T[temp_capacity];
        first._capacity = temp_capacity;
        first._size = 0;
        for (uint32_t i = 0; i < temp_size; i++)
            first.push_back(temp[i]);
    }

    template <typename T>
    bool operator==(Vector<T> const &lhs, Vector<T> const &rhs);

    template <typename T>
    bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs);

    template <typename T>
    bool operator<(Vector<T> const &lhs, Vector<T> const &rhs);

    template <typename T>
    bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs);

    template <typename T>
    bool operator>(Vector<T> const &lhs, Vector<T> const &rhs);

    template <typename T>
    bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs);
}

#endif
