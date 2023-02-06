/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:05:24 by steh              #+#    #+#             */
/*   Updated: 2023/02/06 22:02:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "RBTree.hpp"
# include "node.hpp"
# include "type_traits.hpp"
# include "RBTree.algorithms.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"

namespace ft
{
	template<typename T>
	class const_tree_iterator;
	template<typename T>
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef T												value_type; 
			typedef std::ptrdiff_t									difference_type;
			typedef value_type										node;
			typedef value_type*										pointer;
			typedef value_type&										reference;
			// typedef Node<value_type>								node;
			typedef Node<value_type>*								node_pointer;
			// typedef Node<value_type>*								tnull_pointer;
			// typedef Node<value_type>&								reference;
		
			// constructor

			tree_iterator() : _current_node(nullptr)
			{
				// std::cout<<"default tree iter constructor"<<std::endl;
			};

			tree_iterator(node_pointer node) : _current_node(node)
			{ 
				// std::cout<<"node constructro"<<std::endl;
			};

			// This is copy constructor
			template <class It> 
			tree_iterator(const tree_iterator<It>& iter) : _current_node(iter._current_node)
			{
				// std::cout<<"template constructor"<<std::endl;
			};


			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& other)
			{
				if (_current_node != other._current_node)
				{
					_current_node = other._current_node;
				}
				return (*this);
			};

			// tree_iterator(pointer ptr) : _current_node(static_cast<node_pointer>(ptr))
			// {
			// 	std::cout<<"pointer constructor"<<std::endl;
			// };

			const node_pointer& base() const
			{
				return (_current_node);
			};

			// dereference operator
			reference & operator*() const
			{
				return (_current_node->data);
			};

			// reference  operator->() const
			// {
			// 	return (&(operator*()));
			// };

			pointer operator->() const
			{
				return (&_current_node->data);
			}

			tree_iterator& operator++()
			{
				_current_node = _current_node->successor(_current_node);
				return (*this);
			};

			tree_iterator operator++(int)
			{
				tree_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			tree_iterator& operator--()
			{
				_current_node = _current_node->predecessor(_current_node);;
				return (*this);
			};

			tree_iterator operator--(int)
			{
				tree_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator==(const tree_iterator &other) const
			{
				return (_current_node == other._current_node);
			};

			bool operator!=(const tree_iterator &other) const
			{
				return (_current_node != other._current_node);
			};

			bool operator>=(const tree_iterator &other) const
			{
				if (!_current_node)
					return (false);
				return (_current_node >= other._current_node);
			};

			node_pointer get_node_pointer() const
			{
				return (_current_node);
			};

			// node_pointer in_order_successor(node_pointer node) 
			// {
			// 	node_pointer parent;

			// 	if (node == _TNULL)
			// 		return (_TNULL);
			// 	if (node->right != _TNULL)
			// 	{
			// 		node = node->right;
			// 		while (node->left != _TNULL)
			// 			node = node->left;
			// 		return (node);
			// 	}
			// 	parent = node->parent;
			// 	while (parent && parent->right == node)
			// 	{
			// 		node = parent;
			// 		parent = parent->parent;
			// 	}
			// 	if (!parent)
			// 		return (_TNULL);
			// 	return (parent);
			// }

			// node_pointer in_order_predecessor(node_pointer node) 
			// {
			// 	node_pointer parent;
			// 	// if (node == _TNULL)
			// 	// 	return (_TNULL);
			// 	std::cout<<"data:"<<node->data<<std::endl;
			// 	std::cout<<"left:"<<node->left<<std::endl;
			// 	std::cout<<"right:"<<node->right<<std::endl;
			// 	if (node->left != _TNULL)
			// 	{
			// 		node = node->left;
			// 		while (node->right != _TNULL)
			// 			node = node->right;
			// 		return (node);
			// 	}
			// 	parent = node->parent;
			// 	while (parent && parent->left == node)
			// 	{
			// 		node = parent;
			// 		parent = parent->parent;
			// 	}
			// 	if (!parent)
			// 		return (_TNULL);
			// 	return (parent);
			// }

		protected:
			node_pointer		_current_node;
	};

	template<typename T>
	class const_tree_iterator
	{
		public:
	
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef T												value_type; 
			typedef std::ptrdiff_t									difference_type;
			typedef const value_type								node;
			typedef const value_type*								pointer;
			typedef const value_type&								reference;
			typedef const Node<value_type>*							node_pointer;
		
			// constructor

			const_tree_iterator() : _current_node(nullptr)
			{
				// std::cout<<"default tree iter constructor"<<std::endl;
			};

			const_tree_iterator(const node_pointer node) : _current_node(node)
			{ 
				// std::cout<<"node constructro"<<std::endl;
			};

			// This is copy constructor
			template <class It> 
			const_tree_iterator(const const_tree_iterator<It>& iter) : _current_node(iter._current_node)
			{
				// std::cout<<"template constructor"<<std::endl;
			};


			~const_tree_iterator() {}

			const_tree_iterator& operator=(const const_tree_iterator& other)
			{
				if (_current_node != other._current_node)
				{
					_current_node = other._current_node;
				}
				return (*this);
			};

			// const_tree_iterator(pointer ptr) : _current_node(static_cast<node_pointer>(ptr))
			// {
			// 	std::cout<<"pointer constructor"<<std::endl;
			// };

			const node_pointer& base() const
			{
				return (_current_node);
			};

			// dereference operator
			reference & operator*() const
			{
				return (_current_node->data);
			};

			pointer operator->() const
			{
				return (&_current_node->data);
			}


			const_tree_iterator& operator++()
			{
				_current_node = _current_node->successor(_current_node);
				return (*this);
			};

			const_tree_iterator operator++(int)
			{
				const_tree_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			const_tree_iterator& operator--()
			{
				_current_node = _current_node->predecessor(_current_node);;
				return (*this);
			};

			const_tree_iterator operator--(int)
			{
				const_tree_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator==(const const_tree_iterator &other) const
			{
				return (_current_node == other._current_node);
			};

			bool operator!=(const const_tree_iterator &other) const
			{
				return (_current_node != other._current_node);
			};

			bool operator>=(const const_tree_iterator &other) const
			{
				if (!_current_node)
					return (false);
				return (_current_node >= other._current_node);
			};

			node_pointer get_node_pointer() const
			{
				return (_current_node);
			};

		protected:
			node_pointer		_current_node;


	};
}

#endif
