/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:05:24 by steh              #+#    #+#             */
/*   Updated: 2023/01/30 16:43:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "RBTree.hpp"
# include "node.hpp"
# include "type_traits.hpp"

namespace ft
{
	template<typename T> // here accept t Oonly
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag				iterator_category;
			typedef T											value_type; 
			typedef std::ptrdiff_t								difference_type;
			typedef Node<value_type>							node;
			typedef Node<value_type>*							node_pointer;
			typedef Node<value_type>*							tnull_pointer;
			typedef Node<value_type>&							reference;
			// typedef ft::RBTree<T, KeyofValue>					tree;
			// typedef value_type*										pointer;
			// what is T? value of key, where is template parameter for the node?
			//	typedef value_type*										pointer;
		
			// constructor

			tree_iterator() : _current_node(nullptr) , _TNULL(nullptr)
			{
				// std::cout<<"default tree iter constructor"<<std::endl;
			};

			tree_iterator(node_pointer node, tnull_pointer tnull) : _current_node(node), _TNULL(tnull) // this constructor takes two parameter inputs
			{ 
				// std::cout<<"node constructro"<<std::endl;
			};

			// This is copy constructor
			template <class It> 
			tree_iterator(const tree_iterator<It>& iter) : _current_node(iter._current_node), _TNULL(iter._TNULL)
			{
				// std::cout<<"template constructor"<<std::endl;
			};


			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& other)
			{
				if (_current_node != other._current_node)
				{
					_current_node = other._current_node;
					_TNULL = other._TNULL;
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
				return (*_current_node);
			};

			node_pointer operator->() const
			{
				return (_current_node);
			};

			tree_iterator& operator++()
			{
				_current_node = in_order_successor(_current_node);
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
				_current_node = in_order_predecessor(_current_node);
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

			node_pointer get_node_pointer() const
			{
				return (_current_node);
			};

		private:

			node_pointer in_order_successor(node_pointer node) 
			{
				node_pointer parent;
				if (node->right != _TNULL)
				{
					node = node->right;
					while (node->left != _TNULL)
						node = node->left;
					return (node);
				}
				parent = node->parent;
				while (parent && parent->right == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			node_pointer in_order_predecessor(node_pointer node) 
			{
				node_pointer parent;
				if (node->left != _TNULL)
				{
					node = node->left;
					while (node->right != _TNULL)
						node = node->right;
					return (node);
				}
				parent = node->parent;
				while (parent && parent->left == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

		protected:
			node_pointer		_current_node;
			tnull_pointer		_TNULL;


	};
}

#endif
