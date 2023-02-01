/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.algorithms.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:48:49 by steh              #+#    #+#             */
/*   Updated: 2023/02/01 22:52:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ALGO_HPP
# define RBTREE_ALGO_HPP

#include <iostream>
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"

namespace ft
{
	template <class Node, class T, class KeyofValue, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	struct algo : public RBTree<T, KeyofValue, Compare, Alloc>
	{
			// void		print_helper(Node* _root, std::string indent, bool last);
		// void		print_helper_pair(Node* _root, std::string indent, bool last);
		// Node*	search_tree_helper(Node* node, T value);
		// void		rb_transplant(Node* node_to_replace, Node* replacement_node);
		// void		delete_node_helper(Node* node, T value);
		// void		delete_fix(Node* current_node);
		// void		insert_fix(Node* current_node);
		// Node*	minimum(Node* node);
		// Node*	maximum(Node* node);
		// void		left_rotate(Node* current_node);
		// void		right_rotate(Node* current_node);
		// Node*	successor(Node* current_node);
		// Node*	predecessor(Node* current_node);
		// void		pre_order_helper(Node* node);
		// void		in_order_helper(Node* node);
		// void		post_order_helper(Node* node);

		// https://www.programiz.com/dsa/red-black-tree

		// template <class T, class KeyofValue, class Compare, class Alloc, class Node >
		// Node* _root = RBTree<T, KeyofValue, Compare, Alloc>::get_root();
		
		// template <class T, class KeyofValue, class Compare, class Alloc, class Node >
		// Node* _TNULL = RBTree<T, KeyofValue, Compare, Alloc>::get_tnull();

		// template <class T, class KeyofValue, class Compare, class Alloc, class Node >
		// Node*	get_tree_tnull()
		// {
		// 	RBTree<T, KeyofValue, Compare, Alloc>	tree;
		// 	Node*	_TNULL = tree.get_tnull();
		// 	return (_TNULL);
		// }

		static void print_helper(Node* root, std::string indent, bool last)
		{
			if (root != nullptr)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? RED "red" RST : "black";
				try
				{
					std::cout << root->data <<  "(" << sColor << ")" << std::endl;
				}
				catch (...)
				{
					std::cout << "An error occured while trying to access root->data." << std::endl;
				}
				print_helper(root->left, indent, false);
				print_helper(root->right, indent, true);
			}
		}

		void print_helper_pair(Node* root, std::string indent, bool last)
		{
			if (root != nullptr)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? RED "red" RST : "black";
				try
				{
					std::cout << root->data.first << ":" << root->data.second << " (" << sColor << ")" << std::endl;
				}
				catch (...)
				{
					std::cout << "An error occured while trying to access root->data.first and second." << std::endl;
				}
				print_helper_pair(root->left, indent, false);
				print_helper_pair(root->right, indent, true);
			}
		}

		Node*	search_tree_helper(Node* node, T value)
		{
			if (node == this->_TNULL || value == node->data)
				return (node);
			if (value < node->data)
				return search_tree_helper(node->left, value);
			return (search_tree_helper(node->right, value));
		}

		
		// void	rb_transplant(Node* node_to_replace, Node* replacement_node)
		// {
		// 	if (node_to_replace->parent == nullptr)
		// 		_root = replacement_node;
		// 	else if (node_to_replace == node_to_replace->parent->left)
		// 		node_to_replace->parent->left = replacement_node;
		// 	else
		// 		node_to_replace->parent->right = replacement_node;
		// 	replacement_node->parent = node_to_replace->parent;
		// }

		// template <class T, class Node>
		// void	delete_node_helper(Node* node, T value)
		// {
		// 	Node*	node_to_delete;
		// 	Node*	child_of_deleted_node;
		// 	Node*	successor_of_deleted_node;
		// 	Color	original_color_of_successor;

		// 	node_to_delete = _TNULL;
		// 	while (node != _TNULL)
		// 	{
		// 		if (node->data == value)
		// 			node_to_delete = node;
		// 		if (node->data <= value)
		// 			node = node->right;
		// 		else
		// 			node = node->left;
		// 	}
		// 	if (node_to_delete == _TNULL)
		// 	{
		// 		std::cout<<"Value not found in the tree" << std::endl;
		// 		return ;
		// 	}
		// 	successor_of_deleted_node = node_to_delete;
		// 	original_color_of_successor = successor_of_deleted_node->color;
		// 	if (node_to_delete->left == _TNULL)
		// 	{
		// 		child_of_deleted_node = node_to_delete->right;
		// 		rb_transplant(node_to_delete, node_to_delete->right);
		// 	}
		// 	else if (node_to_delete->right == _TNULL)
		// 	{
		// 		child_of_deleted_node = node_to_delete->left;
		// 		rb_transplant(node_to_delete, node_to_delete->left);
		// 	}
		// 	else
		// 	{
		// 		successor_of_deleted_node = minimum(node_to_delete->right);
		// 		original_color_of_successor = successor_of_deleted_node->color;
		// 		child_of_deleted_node = successor_of_deleted_node->right;
		// 		if (successor_of_deleted_node->parent == node_to_delete)
		// 			child_of_deleted_node->parent = successor_of_deleted_node;
		// 		else
		// 		{
		// 			rb_transplant(successor_of_deleted_node, successor_of_deleted_node->right);
		// 			successor_of_deleted_node->right = node_to_delete->right;
		// 			successor_of_deleted_node->right->parent = successor_of_deleted_node;
		// 		}
		// 		rb_transplant(node_to_delete, successor_of_deleted_node);
		// 		successor_of_deleted_node->left = node_to_delete->left;
		// 		successor_of_deleted_node->left->parent = successor_of_deleted_node;
		// 		successor_of_deleted_node->color = node_to_delete->color;
		// 	}
		// 	if (original_color_of_successor == black)
		// 		delete_fix(child_of_deleted_node);
		// }

		// // use sibling to fix violation
		
		// void	delete_fix(Node* current_node)
		// {
		// 	Node* sibling;
		// 	while (current_node != _root && current_node->color == black)
		// 	{
		// 		if (current_node == current_node->parent->left)
		// 		{
		// 			sibling = current_node->parent->right;
		// 			// case 1: sibling is red
		// 			if (sibling->color == red)
		// 			{
		// 				sibling->color = black;
		// 				sibling->parent->color = red;
		// 				left_rotate(current_node->parent);
		// 				sibling = current_node->parent->right;
		// 			}

		// 			// case 2: sibling is black and both children are black
		// 			if (sibling->left->color == black && sibling->right->color == black)
		// 			{
		// 				sibling->color = red;
		// 				current_node = current_node->parent;
		// 			}
		// 			else
		// 			{
		// 				// case 2: sibling is black and right children is black
		// 				if (sibling->right->color == black)
		// 				{
		// 					sibling->left->color = black;
		// 					sibling->color = red;
		// 					right_rotate(sibling);
		// 					sibling = current_node->parent->right;
		// 				}
		// 				sibling->color = current_node->parent->color;
		// 				current_node->parent->color = black;
		// 				sibling->right->color = black;
		// 				left_rotate(current_node->parent);
		// 				current_node = _root;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			sibling = current_node->parent->left;
		// 			if (sibling->color == red)
		// 			{
		// 				sibling->color = black;
		// 				sibling->parent->color = red;
		// 				right_rotate(current_node->parent);
		// 				sibling = current_node->parent->left;
		// 			}

		// 			if (current_node->right->color == black && sibling->right->color == black)
		// 			{
		// 				sibling->color = red;
		// 				current_node = current_node->parent;
		// 			}
		// 			else
		// 			{
		// 				if (sibling->left->color == black)
		// 				{
		// 					sibling->right->color = black;
		// 					sibling->color = red;
		// 					left_rotate(sibling);
		// 					sibling = current_node->parent->left;
		// 				}
		// 				sibling->color = current_node->parent->color;
		// 				current_node->parent->color = black;
		// 				sibling->left->color = black;
		// 				right_rotate(current_node->parent);
		// 				current_node = _root;
		// 			}
		// 		}
		// 	}
		// 	current_node->color = black;
		// }

		
		// Node*	minimum(Node* node)
		// {
		// 	while (node->left != _TNULL)
		// 		node = node->left;
		// 	return (node);
		// }

		
		// Node*	maximum(Node* node)
		// {
		// 	while (node->right != _TNULL)
		// 		node = node->right;
		// 	return (node);
		// }

		void	left_rotate(Node* current_node)
		{
			Node* right_child_of_current_node;
			
			right_child_of_current_node = current_node->right;
			current_node->right = right_child_of_current_node->left;
			if (right_child_of_current_node->left != this->_TNULL)
				right_child_of_current_node->left->parent = current_node;
			right_child_of_current_node->parent = current_node->parent;
			if (current_node->parent == nullptr)
				this->_root = right_child_of_current_node;
			else if (current_node == current_node->parent->left)
				current_node->parent->left = right_child_of_current_node;
			else
				current_node->parent->right = right_child_of_current_node;
			right_child_of_current_node->left = current_node;
			current_node->parent = right_child_of_current_node;
		}

		void	right_rotate(Node* current_node)
		{
			Node* left_child_of_current_node;
			
			left_child_of_current_node = current_node->left;
			current_node->left = left_child_of_current_node->right;
			if (left_child_of_current_node->right != this->_TNULL)
				left_child_of_current_node->right->parent = current_node;
			left_child_of_current_node->parent = current_node->parent;
			if (current_node->parent == nullptr)
				this->_root = left_child_of_current_node;
			else if (current_node == current_node->parent->right)
				current_node->parent->right = left_child_of_current_node;
			else
				current_node->parent->left = left_child_of_current_node;
			left_child_of_current_node->right = current_node;
			current_node->parent = left_child_of_current_node;
		}

		// Node*	successor(Node* current_node)
		// {
		// 	Node*	parent_node;
		// 	if (current_node == nullptr)
		// 		return (nullptr);
		// 	if (current_node->right != _TNULL)
		// 		return (minimum(current_node->right));
		// 	parent_node = current_node->parent;
		// 	while (parent_node != nullptr && current_node == parent_node->right)
		// 	{
		// 		current_node = parent_node;
		// 		parent_node = parent_node->parent;
		// 	}
		// 	return (parent_node);
		// }
		
		// Node* predecessor(Node* current_node)
		// {
		// 	Node*	parent_node;

		// 	if (current_node == nullptr)
		// 		return (nullptr);
		// 	if (current_node->left != _TNULL)
		// 		return (maximum(current_node->left));
		// 	parent_node = current_node->parent;
		// 	while (parent_node != nullptr && current_node == parent_node->left)
		// 	{
		// 		current_node = parent_node;
		// 		parent_node = parent_node->parent;
		// 	}
		// 	return (parent_node);
		// }

		// void	pre_order_helper(Node* node)
		// {
		// 	if (node != _TNULL)
		// 	{
		// 		std::cout << node->data << " ";
		// 		pre_order_helper(node->left);
		// 		pre_order_helper(node->right);
		// 	}
		// }

		// void	in_order_helper(Node* node)
		// {
		// 	if (node != _TNULL)
		// 	{
		// 		in_order_helper(node->left);
		// 		std::cout << node->data << " ";
		// 		in_order_helper(node->right);
		// 	}
		// }
		
		// void	post_order_helper(Node* node)
		// {
		// 	if (node != _TNULL)
		// 	{
		// 		post_order_helper(node->left);
		// 		post_order_helper(node->right);
		// 		std::cout << node->data << " ";
		// 	}
		// }

		static void	insert_fix(Node* current_node)
		{
			Node*	uncle_node;
			while (current_node->parent->color == red)
			{
				// check if new node parent os right or left child of its grandparent.
				// it sets the uncle node to be left or right child of grandparent
				if (current_node->parent == current_node->parent->parent->right)
				{
					uncle_node = current_node->parent->parent->left;
					// case 1: uncle node is red
					if (uncle_node->color == red)
					{
						uncle_node->color = black;
						current_node->parent->color = black;
						current_node->parent->parent->color = red;
						current_node = current_node->parent->parent;
					}
					else
					{
						// case 2: uncle node is black and new node is left child
						if (current_node == current_node->parent->left)
						{
							current_node = current_node->parent;
							right_rotate(current_node);
						}
						// case 3: uncle node is black and new node is right child
						current_node->parent->color = black;
						current_node->parent->parent->color = red;
						left_rotate(current_node->parent->parent);
					}
				}
				else
				{
					uncle_node = current_node->parent->parent->right;
					// case 1: uncle node is red
					if (uncle_node->color == red)
					{
						uncle_node->color = black;
						current_node->parent->color = black;
						current_node->parent->parent->color = red;
						current_node = current_node->parent->parent;
					}
					else
					{
						// case 2: uncle node is black and new node is right child
						if (current_node == current_node->parent->right)
						{
							current_node = current_node->parent;
							left_rotate(current_node);
						}
						// case 3: uncle node is black and new node is left child
						current_node->parent->color = black;
						current_node->parent->parent->color = red;
						right_rotate(current_node->parent->parent);
					}
				}
				if (current_node == this->_root)
					break ;
			}
			this->_root->color = black;
		}
	};
}


# endif
