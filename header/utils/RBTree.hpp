/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:59:48 by steh              #+#    #+#             */
/*   Updated: 2023/02/08 20:25:11 by steh             ###   ########.fr       */
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

// and actually if u did git push & save commit from time to time
// if u want to back to the pervious coding which work than now, can git reset to back the commit history, it is easier & quicker
// example when one time u managed to make insert work well, need to git commit it before move on work later.
// i mean i want to move the the insert fix to another class or file. because the rbtree too many function
// insert fix move to another class or file, u mean u want insert fix function to not a member of the rbtree class?
// u may need to pass the rbtree class into insertfix function or inheritance 
// like void insertfix(RBTree x) for example
#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include "pair.hpp"
# include "tree_iterator.hpp"
# include "node.hpp"
# include "RBTree.algorithms.hpp"
# include "iterator.hpp"
# include "algorithm.hpp"

namespace ft
{
	template <typename T, typename = void>
	struct KeyofValue
	{
		typedef T result_type;
		const result_type& operator()(const T& value) const
		{
			return (value);
		}
	};

	template <typename K, typename V>
	struct KeyofValue<ft::pair<K, V> >
	{
		typedef const typename ft::pair<K, V>::first_type result_type;
		const result_type& operator()(const ft::pair<K, V>& value) const
		{
			return (value.first);
		}
	};

	// template <class T, class KeyofValue, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	template <class T, class KeyofValue = ft::KeyofValue<T>, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class RBTree
	{
		public:
			typedef KeyofValue												key_of_value;
			typedef Compare													value_compare;
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::size_type						size_type;
			typedef typename allocator_type::difference_type				difference_type;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef Node<value_type>										Node;
			// typedef typename Node::node_type								node_type;
			typedef tree_iterator<value_type>								iterator;
			typedef const_tree_iterator<value_type>							const_iterator;
			typedef typename allocator_type::template rebind<Node>::other	node_allocator;
			// typedef typename allocator_type::template rebind<node_type>::other	node_allocator;


			// typedef typename rbt_node_types<value_type>::node_type				node_type;
			// typedef typename rbt_node_types<value_type>::leaf_node_type			leaf_node_type;
			// typedef typename rbt_node_types<value_type>::node_pointer			node_pointer;
			// typedef typename rbt_node_types<value_type>::leaf_node_pointer		leaf_node_pointer;
			// typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
			// typedef ft::reverse_iterator<iterator>							reverse_iterator;
			
		protected:
		
			// helper function
			void				pre_order_helper(Node* node);
			void				in_order_helper(Node* node);
			void				post_order_helper(Node* node);
			Node*				search_tree_helper(Node* node, T value);
			Node*				search_tree_helper_const(Node* node, const T& value) const;
			void				print_helper(Node* _root, std::string indent, bool last);
			void				print_helper_pair(Node* _root, std::string indent, bool last);
			void				delete_node_helper(Node* node, T value);
			void				delete_fix(Node* current_node);
			void				rb_transplant(Node* node_to_replace, Node* replacement_node);
			void				insert_fix(Node* current_node);
			Node*				successor(Node* current_node);
			Node*				predecessor(Node* current_node);
			void				left_rotate(Node* current_node);
			void				right_rotate(Node* current_node);
			Node*				search_node(const value_type& value) const;

			Node*				_root;
			Node*				_TNULL;
			size_type			_size;
			key_of_value		_keyofvalue;
			value_compare		_comp;
			node_allocator		_node_alloc;
			allocator_type		_value_alloc;

		public:

			// tree algorithms	
			RBTree(const value_compare& comp = value_compare(), const Alloc& alloc = allocator_type());
			RBTree(const RBTree& other);
			RBTree& operator=(const RBTree& other);
			~RBTree();
			void						destroy(Node* node);
			allocator_type				get_allocator() const;
			void						pre_order();
			void						in_order();
			void						post_order();
			void						delete_node(value_type value);
			Node* 						search_tree(value_type value);
			Node* 						search_tree_const(const value_type& value) const;
			void						print_tree();
			Node*						minimum(Node* node) const;
			Node*						tree_minimum() const;
			Node*						maximum(Node* node) const;
			Node*						tree_maximum() const;


			template <class P>
			void						print_tree(typename ft::enable_if<!ft::is_integral<P>::value, void>::type* = NULL);
			// void						print_tree(typename ft::enable_if<std::is_same<P, ft::pair<typename P::first_type, typename P::second_type> >::value>);
			void						print_tree_pair();
			Node*						get_root();
			void						set_root(Node* new_root);
			Node*						get_tnull();
			Node*						create_nil_node();
			Node*						create_node(const value_type &value);

			// member function
			iterator		begin();
			const_iterator	begin() const;
			iterator		end();
			const_iterator	end() const;
			bool			empty() const;
			size_type		size() const;
			size_type		size_helper(Node* node) const;
			size_type		max_size() const;

			// Modifiers
			void						clear();
			ft::pair<iterator, bool> 	insert(const value_type& value);
			iterator					insert(iterator pos, const value_type& value);
			template <class InputIt>
			void						insert(InputIt first, InputIt last, typename ft::enable_if<!std::is_integral<InputIt>::value, InputIt>::type* = NULL);
			iterator					erase(iterator pos);
			iterator					erase(iterator first, iterator last);
			template <class Key>
			size_type					erase(const Key &key);
			void						swap(RBTree &other);

			// Lookup
			template <class Key>
			size_type					count(const Key& key) const;
	
			template <class Key>
			iterator					find(const Key& key);

			template <class Key>
			const_iterator				find(const Key& key) const;

			template <class Key>
			iterator					lower_bound( const Key& key );

			template <class Key>
			const_iterator				lower_bound( const Key& key ) const;

			template <class Key>
			iterator					upper_bound( const Key& key );

			template <class Key>
			const_iterator				upper_bound( const Key& key ) const;

			template <class Key>
			ft::pair<iterator, iterator>				equal_range( const Key& key );

			template <class Key>
			ft::pair<const_iterator, const_iterator>	equal_range( const Key& key ) const;

			// Observer
			key_of_value	key_comp() const;
			value_compare	value_comp() const;
			

	};

	// template <typename K, typename V>
	// std::ostream & operator<<(std::ostream & os, const ft::pair<K, V>& p)
	// {
	// 	os << "(" << (*p.first).data << ", " << (*p.second).data << ")";
	// 	return os;
	// }
	#include "RBTree.tpp"
}

#endif
