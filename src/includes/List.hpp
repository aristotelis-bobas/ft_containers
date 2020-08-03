#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "Iterator.hpp"
#include "Traits.hpp"
#include "Algorithms.hpp"
#include <climits>
#include <cstddef>

// TESTING
#include <iostream>

namespace ft
{

template <typename T>
class list
{
public:
    typedef T value_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef node<T> element;
    typedef const element const_element;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    // BIDIRECTIONAL ITERATOR
    typedef random_access_iterator<value_type, element, reference> iterator;
    typedef random_access_iterator<value_type, const_element, const_reference> const_iterator;
    typedef reverse_random_access_iterator<value_type, element, reference> reverse_iterator;
    typedef reverse_random_access_iterator<value_type, const_element, const_reference> const_reverse_iterator;

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

    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;

    bool empty() const
    {
        if (this->total == 0)
            return (true);
        else
            return (false);
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
        iterator it = this->begin();
        element *insert = new element(val);
        element *traverser = this->head->next;
        while (it != position)
        {
            it++;
            traverser = traverser->next;
        }
        insert->previous = traverser->previous;
        insert->next = traverser;
        insert->previous->next = insert;
        traverser->previous = insert;
        this->total++;
        return (position);
    }

    void insert(iterator position, size_type n, const value_type &val);

    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last,
                typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr);

    iterator erase(iterator position);

    iterator erase(iterator first, iterator last);

    void swap(list &x)
    {
        list temp(x);
        x = *this;
        *this = temp;
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
};

} // namespace ft

#endif
