/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/11 20:45:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
            T *array;
            uint32_t size;
            uint32_t capacity;
        public:
            Vector()
            Vector(Vector<T> const &other);
            Vector& operator=(Vector<T> const &other);
            ~Vector();
            /*
                begin()
                end()
                rbegin()
                rend()
            */
            uint32_t size() const;
            uint32_t max_size() const;
            void resize(uint32_t n, T val);
            uint32_t capacity() const;
            bool empty() const;
            void reserve(uint32_t n);
            T& operator[](uint32_t n);
            const T& operator[](uint32_t n) const;
            T& at(uint32_t n);
            const T& at(uint32_t n);
            T& front(uint32_t n);
            const T& front(uint32_t n);
            T& back(uint32_t n);
            const T& back(uint32_t n);
            void push_back(const T &val);
            void pop_back();
            void swap(Vector<T> &x);
            void clear();
            /*
                assign()
                insert()
                erase()
            */
    };

    template <typename T>
    void swap(Vector<T> &x, Vector<T> &y);

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
