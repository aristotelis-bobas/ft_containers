/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 21:13:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/11 21:25:44 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

namespace ft
{
    template <typename T>
    class List
    {
        private:
            template <typename T>
            typedef struct s_list
            {
                T data;
                struct s_list *previous;
                struct s_list *next;
            }               t_list;
            t_list *head;
            uint32_t size;
        public:
            List()
            List(List<T> const &other);
            List& operator=(List<T> const &other);
            ~List();
            /*
                begin()
                end()
                rbegin()
                rend()
            */
            bool empty() const;
            uint32_t size() const;
            uint32_t max_size() const;
            T& front(uint32_t n);
            const T& front(uint32_t n);
            T& back(uint32_t n);
            const T& back(uint32_t n);
            void push_front(const T &val);
            void pop_front();
            void push_back(const T &val);
            void pop_back();
            /*
                assign()
                insert()
                erase()
            */
            void swap(List<T> &x);
            void resize(uint32_t n, T val);
            void clear();
            void remove(T const &val);
            void unique();
            void merge(List<T> &x);
            void sort();
            void reverse();
            /*
                splice()
                remove_if()
                unique(Predicate);
                merge(Compare);
                sort(Compare);
            */
    };

    template <typename T>
    void swap(List<T> &x, List<T> &y);

    template <typename T>
    bool operator==(List<T> const &lhs, List<T> const &rhs);

    template <typename T>
    bool operator!=(List<T> const &lhs, List<T> const &rhs);

    template <typename T>
    bool operator<(List<T> const &lhs, List<T> const &rhs);

    template <typename T>
    bool operator<=(List<T> const &lhs, List<T> const &rhs);

    template <typename T>
    bool operator>(List<T> const &lhs, List<T> const &rhs);

    template <typename T>
    bool operator>=(List<T> const &lhs, List<T> const &rhs);
}

#endif