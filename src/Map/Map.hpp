/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:40:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/24 19:00:09 by abobas        ########   odam.nl         */
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
	typedef value_type *pointer;
	typedef const value_type *const_pointer;
	typedef node<value_type, key_compare> node;
	typedef node *node_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator<value_type, reference, pointer, node_pointer> iterator;
	typedef bidirectional_iterator<value_type, const_reference, const_pointer, node_pointer> const_iterator;
	typedef reverse_bidirectional_iterator<value_type, reference, pointer, node_pointer> reverse_iterator;
	typedef reverse_bidirectional_iterator<value_type, const_reference, const_pointer, node_pointer> const_reverse_iterator;
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
		this->root = nullptr;
		this->create_boundaries();
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		this->comp = comp;
		this->total = 0;
		this->root = nullptr;
		this->create_boundaries();
		this->insert(first, last);
	}

	map(const map &x)
	{
		this->comp = x.comp;
		this->total = 0;
		this->root = nullptr;
		this->create_boundaries();
		this->insert(x.begin(), x.end());
	}

	~map()
	{
		this->clear();
		this->delete_boundaries();
	}

	map &operator=(const map &x)
	{
		this->clear();
		this->comp = x.comp;
		this->total = 0;
		this->insert(x.begin(), x.end());
		return (*this);
	}

	iterator begin()
	{
		return (iterator(this->lower->parent));
	}

	const_iterator begin() const
	{
		return (const_iterator(this->lower->parent));
	}

	iterator end()
	{
		return (iterator(this->upper));
	}

	const_iterator end() const
	{
		return (const_iterator(this->upper));
	}

	reverse_iterator rbegin()
	{
		return (reverse_iterator(this->upper->parent));
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(this->upper->parent));
	}

	reverse_iterator rend()
	{
		return (reverse_iterator(this->lower));
	}

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(this->lower));
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

	mapped_type &operator[](const key_type &k)
	{
		return ((*((this->insert(std::make_pair(k, mapped_type()))).first)).second);
	}

	std::pair<iterator, bool> insert(const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (std::make_pair(iterator(this->root), true));
		}
		node *traverser = this->root;
		while (traverser->left || traverser->right)
		{
			if (traverser->data.first == val.first)
				return (std::make_pair(iterator(traverser), false));
			if (this->value_comp()(val, traverser->data))
			{
				if (traverser->left && traverser->left != this->lower)
					traverser = traverser->left;
				else
					break;
			}
			else
			{
				if (traverser->right && traverser->right != this->upper)
					traverser = traverser->right;
				else
					break;
			}
		}
		if (this->value_comp()(val, traverser->data))
			return (std::make_pair(iterator(this->insert_left(traverser, val)), true));
		else
			return (std::make_pair(iterator(this->insert_right(traverser, val)), true));
	}

	iterator insert(iterator position, const value_type &val)
	{
		if (this->total == 0)
		{
			this->create_root(val);
			return (iterator(this->root));
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

	void erase(iterator position)
	{
		node *erase = find(position);
		if (!erase)
			return;
		this->erase(erase);
	}

	size_type
	erase(const key_type &k)
	{
		size_type ret = this->count(k);
		if (ret == 1)
			this->erase(this->find(k));
		return (ret);
	}

	void erase(iterator first, iterator last)
	{
		while (first != last)
		{
			iterator tmp(first);
			tmp++;
			this->erase(first);
			first = tmp;
		}
	}

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
		this->reset_boundaries();
		this->root = nullptr;
	}

	key_compare key_comp() const
	{
		return (key_compare());
	}

	value_compare value_comp() const
	{
		return (value_compare(this->comp));
	}

	iterator find(const key_type &k)
	{
		iterator it = this->begin();
		while (it != this->end())
		{
			if (this->equal(it->first, k))
				return (it);
			it++;
		}
		return (it);
	}

	const_iterator find(const key_type &k) const
	{
		const_iterator it = this->begin();
		while (it != this->end())
		{
			if (this->equal(it->first, k))
				return (it);
			it++;
		}
		return (it);
	}

	size_type count(const key_type &k) const
	{
		const_iterator it = this->begin();
		while (it != this->end())
		{
			if (this->equal(it->first, k))
				return (1);
			it++;
		}
		return (0);
	}

	iterator lower_bound(const key_type &k)
	{
		for (iterator it = this->begin(); it != this->end(); it++)
		{
			if (!this->key_comp()(it->first, k))
				return (it);
		}
		return (this->end());
	}

	const_iterator lower_bound(const key_type &k) const
	{
		for (const_iterator it = this->begin(); it != this->end(); it++)
		{
			if (!this->key_comp()(it->first, k))
				return (it);
		}
		return (this->end());
	}

	iterator upper_bound(const key_type &k)
	{
		for (iterator it = this->begin(); it != this->end(); it++)
		{
			if (this->key_comp()(k, it->first))
				return (it);
		}
		return (this->end());
	}

	const_iterator upper_bound(const key_type &k) const
	{
		for (const_iterator it = this->begin(); it != this->end(); it++)
		{
			if (this->key_comp()(k, it->first))
				return (it);
		}
		return (this->end());
	}

	std::pair<iterator, iterator> equal_range(const key_type &k)
	{
		return (std::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

	std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
	{
		return (std::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

private:
	key_compare comp;
	size_type total;
	node *root;
	node *top;
	node *lower;
	node *upper;

	void create_root(value_type val = value_type())
	{
		this->root = new node(val);
		this->top->left = this->root;
		this->top->right = this->root;
		this->root->parent = this->top;
		this->set_boundaries();
		this->total++;
	}

	void reset_boundaries()
	{
		this->delete_boundaries();
		this->create_boundaries();
	}

	void create_boundaries()
	{
		this->top = new node;
		this->lower = new node;
		this->upper = new node;
		this->set_boundaries();
	}

	void set_boundaries()
	{
		node *traverser = this->top;
		while (traverser->left)
			traverser = traverser->left;
		traverser->left = this->lower;
		this->lower->parent = traverser;
		traverser = this->top;
		while (traverser->right)
			traverser = traverser->right;
		traverser->right = this->upper;
		this->upper->parent = traverser;
	}

	void delete_boundaries()
	{
		delete this->top;
		delete this->upper;
		delete this->lower;
	}

	void unset_boundaries()
	{
		this->lower->parent->left = nullptr;
		this->upper->parent->right = nullptr;
	}

	void clear(node *position)
	{
		if (!position)
			return;
		this->clear(position->left);
		this->clear(position->right);
		if (position != this->lower && position != this->upper)
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

	bool equal(key_type first, key_type second) const
	{
		return (!this->key_comp()(first, second) && !this->key_comp()(second, first));
	}

	node *find(iterator position)
	{
		key_type k = position->first;
		if (this->equal(this->root->data.first, k))
			return (this->root);
		node *traverser = this->root;
		while (traverser->left || traverser->right)
		{
			if (this->equal(traverser->data.first, k))
				return (traverser);
			if (this->key_comp()(k, traverser->data.first))
			{
				if (traverser->left && traverser->left != this->lower)
					traverser = traverser->left;
				else
					break;
			}
			else
			{
				if (traverser->right && traverser->right != this->upper)
					traverser = traverser->right;
				else
					break;
			}
		}
		return (nullptr);
	}

	void erase(node *position)
	{
		this->unset_boundaries();
		if (!position->left && !position->right)
			this->erase_leaf(position);
		else if (position->left && position->right)
			this->erase_double(position);
		else
			this->erase_single(position);
	}

	void erase_leaf(node *position)
	{
		if (position->parent == this->top)
		{
			position->parent->left = nullptr;
			position->parent->right = nullptr;
			this->root = nullptr;
		}
		else if (position->parent->left == position)
			position->parent->left = nullptr;
		else
			position->parent->right = nullptr;
		delete position;
		position = nullptr;
		this->total--;
		this->set_boundaries();
	}

	void erase_single(node *position)
	{
		if (position->left)
		{
			position->left->parent = position->parent;
			if (position->parent == this->top)
			{
				position->parent->left = position->left;
				position->parent->right = position->left;
				this->root = position->left;
			}
			else if (position->parent->left == position)
				position->parent->left = position->left;
			else
				position->parent->right = position->left;
		}
		else if (position->right)
		{
			position->right->parent = position->parent;
			if (position->parent == this->top)
			{
				position->parent->left = position->right;
				position->parent->right = position->right;
				this->root = position->right;
			}
			else if (position->parent->left == position)
				position->parent->left = position->right;
			else
				position->parent->right = position->right;
		}
		delete position;
		this->total--;
		this->set_boundaries();
		return;
	}

	void erase_double(node *position)
	{
		node *tmp = position->right;
		while (tmp->left)
			tmp = tmp->left;
		position->data = tmp->data;
		this->set_boundaries();
		this->erase(tmp);
	}
};

template <class Key, class T, class Compare>
void swap(map<Key, T, Compare> &x, map<Key, T, Compare> &y)
{
	map<Key, T, Compare> tmp(y);
	y = x;
	x = tmp;
}

template <class Key, class T, class Compare>
bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	typename map<Key, T, Compare>::const_iterator rhs_it = rhs.begin();
	typename map<Key, T, Compare>::const_iterator lhs_it = lhs.begin();

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

template <class Key, class T, class Compare>
bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare>
bool operator<(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	typename map<Key, T, Compare>::const_iterator rhs_it = rhs.begin();
	typename map<Key, T, Compare>::const_iterator lhs_it = lhs.begin();

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

template <class Key, class T, class Compare>
bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare>
bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare>
bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace ft

#endif
