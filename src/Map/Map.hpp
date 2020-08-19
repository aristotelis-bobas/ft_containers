/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:40:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 22:28:40 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapNode.hpp"
#include "Pair.hpp"
#include "../includes/Iterator.hpp"
#include "../includes/Algorithms.hpp"
#include "../includes/Traits.hpp"
#include <climits>
#include <cstddef>

namespace ft
{

template <class Key, class T, class Compare = less<Key> >
class map
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef node<key_type, mapped_type, key_compare> element;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	 typedef bidirectional_iterator<value_type, element, reference> iterator;
    typedef bidirectional_iterator<value_type, element, const_reference> const_iterator;
    typedef reverse_bidirectional_iterator<value_type, element, reference> reverse_iterator;
    typedef reverse_bidirectional_iterator<value_type, element, const_reference> const_reverse_iterator;
	class value_compare : binary_function<value_type, value_type, bool>
	{
	public:
		bool operator()(const value_type &x, const value_type &y) const
		{
			return comp(x.first, y.first);
		}

	private:
		Compare comp;
		value_compare(Compare c)
		{
			this->comp = c;
		}
		friend class map;
	};

	explicit map(const key_compare &comp = key_compare())
	{
		this->comp = comp;
		this->total = 0;
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr);

	map(const map &x);

	~map()
	{
	}

	map &operator=(const map &x);

	
	iterator begin()
	{
		return (iterator(*this->lower->parent));
	}
	
	const_iterator begin() const
	{
		return (const_iterator(*this->lower->parent));
	}

	iterator end()
	{
		return (iterator(*this->upper));
	}
	
	const_iterator end() const
	{
		return (const_iterator(*this->upper));
	}
	
	reverse_iterator rbegin()
	{
		return (reverse_iterator(*this->upper->parent));
	}
	
	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(*this->upper->parent));
	}
	
	reverse_iterator rend()
	{
		return (reverse_iterator(*this->lower));	
	}

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(*this->lower));	
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

	mapped_type &operator[](const key_type &k);

	pair<iterator, bool> insert(const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (pair<iterator, bool>(iterator(*this->root), true));
		}
		element *traverser = this->root;
		while (traverser->left || traverser->right)
		{
			if (traverser->data.first == val.first)
				return (pair<iterator, bool>(iterator(*traverser), false));
			if (value_comp()(traverser->data, val))
			{
				if (traverser->left && traverser->left != this->lower)
					traverser = traverser->left;
				else
					break ;
			}
			else
			{
				if (traverser->right && traverser->right != this->upper)
					traverser = traverser->right;
				else
					break ;				
			}
		}
		if (value_comp()(traverser->data, val))
			return (pair<iterator, bool>(iterator(*(this->insert_left(traverser, val))), true));
		else
			return (pair<iterator, bool>(iterator(*(this->insert_right(traverser, val))), true));
	}

	/* 
	iterator insert(iterator position, const value_type &val);

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	
	void erase(iterator position);

	size_type erase(const key_type &k);

	void erase(iterator first, iterator last);

	*/

	void swap(map &x)
	{
		map tmp(x);
		x = *this;
		*this = tmp;
	}

	void clear();

	key_compare key_comp() const
	{
		return (key_compare());
	}

	value_compare value_comp() const
	{
		return (value_compare(this->comp));
	}

	/*
	
	iterator find(const key_type &k);

	const_iterator find(const key_type &k) const;

	*/

	size_type count(const key_type &k) const;

	/*

	iterator lower_bound(const key_type &k);

	const_iterator lower_bound(const key_type &k) const;

	iterator upper_bound(const key_type &k);

	const_iterator upper_bound(const key_type &k) const;

	pair<const_iterator,const_iterator> equal_range (const key_type &k) const;
	
	pair<iterator,iterator> equal_range (const key_type &k);
	
	*/

private:
	key_compare comp;
	size_type total;
	element *root;
	element *lower;
	element *upper;
	
	void create_root(value_type val = value_type())
	{
		this->root = new element(val);
		this->create_boundaries();
		this->total++;
	}

	void create_boundaries()
	{
		this->lower = new element;
		this->upper = new element;
		this->set_boundaries();
	}

	void unset_boundaries()
	{
		this->lower->parent->left = nullptr;
		this->upper->parent->right = nullptr;
	}

	void set_boundaries()
	{
		element *traverser = this->root;
		while (traverser->left)
			traverser = traverser->left;
		traverser->left = this->lower;
		this->lower->parent = traverser;
		traverser = this->root;
		while (traverser->right)
			traverser = traverser->right;
		traverser->right = this->upper;
		this->upper->parent = traverser;
	}

	element *insert_left(element *position, value_type val = value_type())
	{
		this->unset_boundaries();
		element *insert = new element(val);
		insert->parent = position;
		position->left = insert;
		this->total++;
		this->set_boundaries();
		return (insert);
	}

	element *insert_right(element *position, value_type val = value_type())
	{
		this->unset_boundaries();
		element *insert = new element(val);
		insert->parent = position;
		position->right = insert;
		this->total++;
		this->set_boundaries();
		return (insert);
	}
};

} // namespace ft

#endif
