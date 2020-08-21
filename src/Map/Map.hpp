/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:40:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 20:30:15 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "MapNode.hpp"
#include "../includes/BidirectionalIterator.hpp"
#include "../includes/Algorithms.hpp"
#include "../includes/Traits.hpp"
#include <climits>
#include <cstddef>
#include <utility>

// TESTING
#include <iostream>

namespace ft
{

template <class Key, class T, class Compare = less<Key> >
class map
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef node<value_type, key_compare> node;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator<value_type, node> iterator;
    typedef bidirectional_iterator<value_type, node> const_iterator;
    typedef reverse_bidirectional_iterator<value_type, node> reverse_iterator;
    typedef reverse_bidirectional_iterator<value_type, node> const_reverse_iterator;
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
		typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		this->comp = comp;
		this->total = 0;
		this->insert(first, last);
	}

	map(const map &x)
	{
		this->comp = x.comp;
		this->total = 0;
		this->insert(x.begin(), x.end());
	}

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
        return (SIZE_T_MAX / sizeof(node));
    }

	mapped_type &operator[](const key_type &k);

	std::pair<iterator, bool> insert(const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (std::make_pair(iterator(*this->root), true));
		}
		node *traverser = this->root;
		while (traverser->left || traverser->right)
		{
			if (traverser->data.first == val.first)
				return (std::make_pair(iterator(*traverser), false));
			if (value_comp()(val, traverser->data))
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
		if (value_comp()(val, traverser->data))
			return (std::make_pair(iterator(*(this->insert_left(traverser, val))), true));
		else
			return (std::make_pair(iterator(*(this->insert_right(traverser, val))), true));
	}
 
	iterator insert(iterator position, const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (iterator(*this->root));
		}
		if (position->first == val.first)
			return (position);
		return (this->insert(val).first);
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		while (first != last)
		{
			this->insert(*first);
			first++;
		}
	}
	
	/*
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

	void clear()
	{
		this->total = 0;
		this->clear(this->root);
	}

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

	size_type count(const key_type &k) const;

	iterator lower_bound(const key_type &k);

	const_iterator lower_bound(const key_type &k) const;

	iterator upper_bound(const key_type &k);

	const_iterator upper_bound(const key_type &k) const;

	std::pair<const_iterator,const_iterator> equal_range (const key_type &k) const;
	
	std::pair<iterator,iterator> equal_range (const key_type &k);
	
	*/

private:
	key_compare comp;
	size_type total;
	node *root;
	node *lower;
	node *upper;
	
	void create_root(value_type val = value_type())
	{
		this->root = new node(val);
		this->create_boundaries();
		this->total++;
	}

	void create_boundaries()
	{
		this->lower = new node;
		this->upper = new node;
		this->set_boundaries();
	}

	void unset_boundaries()
	{
		this->lower->parent->left = nullptr;
		this->upper->parent->right = nullptr;
	}

	void set_boundaries()
	{
		node *traverser = this->root;
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

	void clear(node *position)
	{
		if (!position)
			return ;
		this->clear(position->left);
		this->clear(position->right);
		delete position;
	}

	node *insert_left(node *position, value_type val = value_type())
	{
		this->unset_boundaries();
		node *insert = new node(val);
		insert->parent = position;
		position->left = insert;
		this->total++;
		this->set_boundaries();
		return (insert);
	}

	node *insert_right(node *position, value_type val = value_type())
	{
		this->unset_boundaries();
		node *insert = new node(val);
		insert->parent = position;
		position->right = insert;
		this->total++;
		this->set_boundaries();
		return (insert);
	}
};

} // namespace ft

#endif
