/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:59:48 by steh              #+#    #+#             */
/*   Updated: 2023/01/27 22:25:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.programiz.com/dsa/red-black-tree
// https://github.com/anandarao/Red-Black-Tree/blob/master/RBTree.cpp

// Create a red-black tree class that implements the basic functionality of a binary search tree. This class should include methods for insertion, deletion, and search.

// Implement the basic properties of a red-black tree, such as the color of each node, whether it is a leaf, and whether it has a parent.

// Implement the rules for maintaining the balance of the tree, such as the rule that no red node can have a red parent, and that the number of black nodes on any path from the _root to a leaf is the same.

// Implement rotation methods, such as left-rotate and right-rotate, to maintain the balance of the tree when inserting or deleting a node.

// Create a map class that uses your red-black tree class as its underlying data structure.

// Implement the map class's methods such as insert, erase, find, operator[] and clear, using the methods and properties of the red-black tree class.

// Test your implementation by creating sample map objects and performing different map operations. You should make sure that the map behaves correctly and that the red-black tree is properly balanced.

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include <queue>
#include "pair.hpp"
#include "tree_iterator.hpp"
#include "node.hpp"

namespace ft
{
	template <typename T>
	struct KeyofValue 
	{
		typedef T result_type;
		const T& operator()(const T& value) const
		{
			return (value);
		}
	};

	template <typename T>
	struct Compare
	{
		bool operator()(const T& x, const T& y) const
		{
			if (x < y)
				return true;
			else if (y < x)
				return false;
			else
				return false;
		}
	};

	template <class T, class KeyofValue = ft::KeyofValue<T>, class Compare = ft::Compare<T>, class Alloc = std::allocator<T> >
	class RBTree
	{
		public:
			typedef KeyofValue									key_of_value;
			typedef Compare										value_compare;
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef Node<T>										Node;
			typedef tree_iterator<value_type>					iterator;
			typedef tree_iterator<const value_type>				const_iterator;
			typedef typename allocator_type::template rebind<Node>::other	node_allocator;
			//typedef typename tree_iterator<key_type, mapped_type>::node_pointer						iterator;
			// typedef typename tree_iterator<const key_type, const mapped_type>::node_pointer			const_iterator;
			
		private:
			void	pre_order_helper(Node* node);
			void	in_order_helper(Node* node);
			void	post_order_helper(Node* node);
			Node*	search_tree_helper(Node* node, T value);

			void	print_helper(Node* _root, std::string indent, bool last);
			// template <class U>
			// void	print_helper(Node* _root, std::string indent, bool last, typename ft::enable_if<std::is_same<U, ft::pair<typename U::first_type, typename U::second_type> >::value, U>::type* = nullptr);
		
			void	delete_node_helper(Node* node, T value);
			void	delete_fix(Node* current_node);
			void	rb_transplant(Node* node_to_replace, Node* replacement_node);
			void	insert_fix(Node* current_node);

			// your map's iterator need to point to this root
			Node				*_root;
			Node				*_TNULL;
			key_of_value		_keyofvalue;
			value_compare		_comp;
			Alloc				_alloc;

		public:
			RBTree(const value_compare& comp = value_compare(), const Alloc& alloc = allocator_type());
			~RBTree();
			void	pre_order();
			void	in_order();
			void	post_order();
			// void	insert(const T& value);
			// void	insert(const K& key, const V& value);
			// void	insert(const ft::pair<K, V>& key_value);
			ft::pair<iterator, bool> insert(const T& value);
			void	delete_node(T value);
			Node* 	search_tree(T value);
			Node*	get_root();
			Node*	minimum(Node* node);
			Node*	maximum(Node* node);
			Node*	successor(Node* current_node);
			// iterator	successor(Node* current_node);
			Node*	predecessor(Node* current_node);
			void	post_order_traversal(Node *_root);
			void	print_tree_by_level();

			void	print_tree();
			Node*	search_tree(Node* node, T value);
			void	left_rotate(Node* current_node);
			void	right_rotate(Node* current_node);

			iterator	begin()
			{
				return (iterator(minimum(_root)));
			}

			iterator	end()
			{
				return (iterator(_TNULL));
			}
	};
}

#endif
