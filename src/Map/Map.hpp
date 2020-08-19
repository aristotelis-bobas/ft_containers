/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:40:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 18:06:07 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapNode.hpp"
#include "Pair.hpp"
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

	/*
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	
	*/

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

	/* 
			10
		4
	*/


	bool insert (const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (true);
		}
		element *traverser = this->root;
		while (traverser->left_child || traverser->right_child)
		{
			if (traverser.first == val.first)
				return (false);
			if (value_comp()(traverser, val))
			{
				if (traverser->left_child)
					traverser = traverser->left_child;
				else
					break ;
			}
			else
			{
				if (traverser->right_child)
					traverser = traverser->right_child;
				else
					break ;				
			}
		}
		if (value_comp()(traverser, val))
			this->insert_left_child(traverser, val);
		else
			this->insert_right_child(traverser, val);
		return (true);
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
	
	void create_root(value_type val = value_type());
	{
		this->root = new element(val);
		this->total++;
	}

	void insert_left_child(element *position, value_type val = value_type())
	{
		element *insert = new element(val);
		insert->parent = position;
		position->left_child = insert;
		this->total++;
	}

	void insert_right_child(element *position, value_type val = value_type())
	{
		element *insert = new element(val);
		insert->parent = position;
		position->right_child = insert;
		this->total++;
	}

};

} // namespace ft

#endif
