#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "Iterator.hpp"
#include "Traits.hpp"
#include <stdexcept>
#include <climits>

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
    typedef node<T> *element_pointer;
    typedef const node<T> *const_element_pointer;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef random_access_iterator<value_type, element_pointer, reference> iterator;
    typedef random_access_iterator<value_type, const_element_pointer, const_reference> const_iterator;
    typedef reverse_random_access_iterator<value_type, pointer, reference> reverse_iterator;
    typedef reverse_random_access_iterator<value_type, const_pointer, const_reference> const_reverse_iterator;

    explicit list()
    {
        this->head = nullptr;
        this->total = 0;
    }

    explicit list(size_type n, const value_type &val = value_type())
    {
        this->head = nullptr;
        this->total = 0;
        for (size_type i = 0; i < n; i++)
            this->push_back(val);
    }

    ~list()
    {
    }

    iterator begin()
	{
		return (iterator(this->head->next));
	}

	iterator end()
	{
		return (iterator(nullptr));
	}

    size_type size() const
	{
		return (this->total);
	}

	size_type max_size() const
	{
		return (SIZE_T_MAX / sizeof(value_type));
	}

    bool empty() const
	{
		if (this->total == 0)
			return (true);
		else
			return (false);
	}

    void push_back(const value_type &val)
    {
        if (this->empty())
        {
            this->create_head(val);
            return ;
        }
        element *traverser = this->head;
        while (traverser->next != nullptr)
            traverser = traverser->next;
        traverser->next = new element;
        traverser->next->data = val;
        traverser->next->next = nullptr;
        traverser->next->previous = traverser;
        this->total++;
    }

private:
    element *head;
    element *tail;
    size_type total;

    void create_head(const value_type &val = value_type())
    {
        this->head = new element;
        this->head->next = nullptr;
        this->head->previous = nullptr;
        this->head->data = val;
        this->total++;
    }
};

} // namespace ft

#endif
