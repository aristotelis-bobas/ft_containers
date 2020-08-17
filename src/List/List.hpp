/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:46:00 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 18:28:54 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "../includes/Iterator.hpp"
#include "../includes/Traits.hpp"
#include "../includes/Algorithms.hpp"
#include <climits>
#include <cstddef>

namespace ft
{

template <class T>
class list
{
public:
    typedef T value_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef node<T> element;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef bidirectional_iterator<value_type, element, reference> iterator;
    typedef bidirectional_iterator<value_type, element, const_reference> const_iterator;
    typedef reverse_bidirectional_iterator<value_type, element, reference> reverse_iterator;
    typedef reverse_bidirectional_iterator<value_type, element, const_reference> const_reverse_iterator;

    explicit list()
    {
        this->create_boundaries();
        this->total = 0;
    }

    explicit list(size_type n, const value_type &val = value_type())
    {
        this->create_boundaries();
        this->total = 0;
        this->assign(n, val);
    }

    template <class InputIterator>
    list(InputIterator first, InputIterator last,
         typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
    {
        this->create_boundaries();
        this->total = 0;
        this->assign(first, last);
    }

    list(const list &x)
    {
        this->create_boundaries();
        this->total = 0;
        this->assign(x.begin(), x.end());
    }

    ~list()
    {
        this->clear();
        this->delete_boundaries();
    }

    list &operator=(const list &x)
    {
        this->clear();
        this->reset_boundaries();
        this->assign(x.begin(), x.end());
        return (*this);
    }

    iterator begin()
    {
        return (iterator(*this->head->next));
    }

    iterator end()
    {
        return (iterator(*this->tail));
    }

    const_iterator begin() const
    {
        return (const_iterator(*this->head->next));
    }

    const_iterator end() const
    {
        return (const_iterator(*this->tail));
    }

    reverse_iterator rbegin()
    {
        return (reverse_iterator(*this->tail->previous));
    }

    reverse_iterator rend()
    {
        return (reverse_iterator(*this->head));
    }

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(*this->tail->previous));
    }

    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(*this->head));
    }

    bool empty() const
    {
        return (!this->size());
    }

    size_type size() const
    {
        return (this->total);
    }

    size_type max_size() const
    {
        return (SIZE_T_MAX / sizeof(element));
    }

    reference front()
    {
        return (this->head->next->data);
    }

    const_reference front() const
    {
        return (this->head->next->data);
    }

    reference back()
    {
        return (this->tail->previous->data);
    }

    const_reference back() const
    {
        return (this->tail->previous->data);
    }

    template <class InputIterator>
    void assign(InputIterator first, InputIterator last,
                typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
    {
        this->clear();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void assign(size_type n, const value_type &val)
    {
        this->clear();
        for (size_type i = 0; i < n; i++)
            this->push_back(val);
    }

    void push_front(const value_type &val)
    {
        element *insert = new element(val);
        insert->previous = this->head;
        insert->next = this->head->next;
        this->head->next->previous = insert;
        this->head->next = insert;
        this->total++;
    }

    void pop_front()
    {
        this->head->next = this->head->next->next;
        delete this->head->next->previous;
        this->head->next->previous = this->head;
        this->total--;
    }

    void push_back(const value_type &val)
    {
        element *insert = new element(val);
        insert->previous = this->tail->previous;
        insert->next = this->tail;
        this->tail->previous->next = insert;
        this->tail->previous = insert;
        this->total++;
    }

    void pop_back()
    {
        this->tail->previous = this->tail->previous->previous;
        delete this->tail->previous->next;
        this->tail->previous->next = this->tail;
        this->total--;
    }

    iterator insert(iterator position, const value_type &val)
    {
        this->insert(this->find(position), val);
        return (position);
    }

    void insert(iterator position, size_type n, const value_type &val)
    {
        element *pos = this->find(position);
        while (n > 0)
        {
            this->insert(pos, val);
            n--;
        }
    }

    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last,
                typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
    {
        element *pos = this->find(position);
        while (first != last)
        {
            this->insert(pos, *first);
            first++;
        }
    }

    iterator erase(iterator position)
    {
        element *pos = this->find(position);
        position++;
        this->erase(pos);
        return (position);
    }

    iterator erase(iterator first, iterator last)
    {
        element *pos = this->find(first);
        difference_type n = distance(first, last);
        while (n > 0)
        {
            pos = pos->next;
            this->erase(pos->previous);
            n--;
        }
        return (last);
    }

    void swap(list &x)
    {
        list tmp(x);
        x = *this;
        *this = tmp;
    }

    void resize(size_type n, value_type val = value_type())
    {
        if (n > this->size())
            while (this->size() < n)
                this->push_back(val);
        else
            while (this->size() > n)
                this->pop_back();
    }

    void clear()
    {
        while (this->size() > 0)
            this->pop_back();
    }

    void splice(iterator position, list &x)
    {
        this->insert(position, x.begin(), x.end());
        x.clear();
    }

    void splice(iterator position, list &x, iterator i)
    {
        this->insert(position, *i);
        x.erase(i);
    }

    void splice(iterator position, list &x, iterator first, iterator last)
    {
        this->insert(position, first, last);
        x.erase(first, last);
    }

    void remove(const value_type &val)
    {
        size_t n = this->size();
        element *traverser = this->head->next;
        while (n > 0)
        {
            traverser = traverser->next;
            if (traverser->previous->data == val)
                this->erase(traverser->previous);
            n--;
        }
    }

    template <class Predicate>
    void remove_if(Predicate pred)
    {
        iterator it = this->begin();
        element *traverser = this->head->next;
        size_t n = this->size();
        while (n > 0)
        {
            traverser = traverser->next;
            if (pred(*it))
                this->erase(traverser->previous);
            it++;
            n--;
        }
    }

    void unique()
    {
        element *traverser = this->head->next;
        size_t n = this->size();
        while (n > 0)
        {
            traverser = traverser->next;
            if (traverser->previous->data == traverser->data)
                this->erase(traverser->previous);
            n--;
        }
    }

    template <class BinaryPredicate>
    void unique(BinaryPredicate binary_pred)
    {
        iterator it = this->begin();
        it++;
        size_t n = this->size();
        while (n > 1)
        {
            iterator tmp = it;
            tmp--;
            if (binary_pred(*it, *tmp))
                this->erase(tmp);
            it++;
            n--;
        }
    }

    void merge(list &x)
    {
        element *traverser = this->head->next;
        element *x_traverser = x.head->next;
        size_t n = this->size();
        size_t m = x.size();
        while (n > 0 && m > 0)
        {
            if (traverser->data < x_traverser->data)
            {
                traverser = traverser->next;
                n--;
            }
            else
            {
                this->insert(traverser, x_traverser->data);
                x_traverser = x_traverser->next;
                x.pop_front();
                m--;
            }
        }
    }

    template <class Compare>
    void merge(list &x, Compare comp)
    {
        element *traverser = this->head->next;
        element *x_traverser = x.head->next;
        size_t n = this->size();
        size_t m = x.size();
        while (n > 0 && m > 0)
        {
            if (comp(traverser->data, x_traverser->data))
            {
                traverser = traverser->next;
                n--;
            }
            else
            {
                this->insert(traverser, x_traverser->data);
                x_traverser = x_traverser->next;
                x.pop_front();
                m--;
            }
        }
    }

    void sort()
    {
        element *traverser = this->head->next;
        size_t n = this->size() - 1;
        while (n > 0)
        {
            traverser = traverser->next;
            if (traverser->data < traverser->previous->data)
            {
                this->swap(traverser->previous, traverser);
                n = this->size() - 1;
                traverser = this->head->next;
                continue;
            }
            n--;
        }
    }

    template <class Compare>
    void sort(Compare comp)
    {
        element *traverser = this->head->next;
        size_t n = this->size() - 1;
        while (n > 0)
        {
            traverser = traverser->next;
            if (comp(traverser->data, traverser->previous->data))
            {
                this->swap(traverser->previous, traverser);
                n = this->size() - 1;
                traverser = this->head->next;
                continue;
            }
            n--;
        }
    }

    void reverse()
    {
        size_t n = this->size();
        size_t m = n;
        element *traverser = this->tail->previous;
        while (n > 0)
        {
            this->push_back(traverser->data);
            traverser = traverser->previous;
            n--;
        }
        while (m > 0)
        {
            this->pop_front();
            m--;
        }
    }

private:
    element *head;
    element *tail;
    size_type total;

    void create_boundaries()
    {
        this->head = new element;
        this->tail = new element;
        this->head->next = this->tail;
        this->tail->previous = this->head;
    }

    void delete_boundaries()
    {
        delete this->head;
        delete this->tail;
    }

    void reset_boundaries()
    {
        this->delete_boundaries();
        this->create_boundaries();
    }

    element *find(iterator position)
    {
        iterator it = this->begin();
        element *traverser = this->head->next;
        while (it != position)
        {
            it++;
            traverser = traverser->next;
        }
        return (traverser);
    }

    void insert(element *position, value_type val = value_type())
    {
        element *insert = new element(val);
        insert->previous = position->previous;
        insert->next = position;
        insert->previous->next = insert;
        position->previous = insert;
        this->total++;
    }

    void erase(element *position)
    {
        position->previous->next = position->next;
        position->next->previous = position->previous;
        delete position;
        this->total--;
    }

    void swap(element *first, element *second)
    {
        value_type tmp = first->data;
        first->data = second->data;
        second->data = tmp;
    }
};

template <class T>
void swap(list<T> &x, list<T> &y)
{
    list<T> tmp(y);
    y = x;
    x = tmp;
}

template <typename T>
bool operator==(const list<T> &lhs, const list<T> &rhs)
{
    typename list<T>::const_iterator rhs_it = rhs.begin();
    typename list<T>::const_iterator lhs_it = lhs.begin();

    if (lhs.size() != rhs.size())
        return (false);
    while (lhs_it != lhs.end())
    {
        if (*lhs_it != *rhs_it)
            return (false);
        lhs_it++;
        rhs_it++;
    }
    return (true);
}

template <typename T>
bool operator!=(const list<T> &lhs, const list<T> &rhs)
{
    return (!(lhs == rhs));
}

template <typename T>
bool operator<(const list<T> &lhs, const list<T> &rhs)
{
    typename list<T>::const_iterator rhs_it = rhs.begin();
    typename list<T>::const_iterator lhs_it = lhs.begin();

    if (lhs == rhs || lhs.size() > rhs.size())
        return (false);
    while (lhs_it != lhs.end() && rhs_it != rhs.end())
    {
        if (*lhs_it > *rhs_it)
            return (false);
        lhs_it++;
        rhs_it++;
    }
    return (true);
}

template <typename T>
bool operator<=(const list<T> &lhs, const list<T> &rhs)
{
    return (!(rhs < lhs));
}

template <typename T>
bool operator>(const list<T> &lhs, const list<T> &rhs)
{
    return (rhs < lhs);
}

template <typename T>
bool operator>=(const list<T> &lhs, const list<T> &rhs)
{
    return (!(lhs < rhs));
}

} // namespace ft

#endif
