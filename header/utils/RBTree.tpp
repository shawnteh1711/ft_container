/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:06:25 by steh              #+#    #+#             */
/*   Updated: 2023/02/07 20:24:07 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"
#include "algorithm.hpp"
#include <typeinfo>
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"


using namespace std;

template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>::RBTree(const value_compare& comp, const Alloc& alloc) :  _size(0), _comp(comp), _node_alloc(node_allocator()), _value_alloc(alloc)
{
	_TNULL = create_nil_node();
	_root = _TNULL;
	return ;
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::create_nil_node()
{
	Node*				new_node;
	// pointer				val_ptr;

	new_node = _node_alloc.allocate(1);
	// _node_alloc.construct(new_node, value_type());
	// val_ptr = _value_alloc.allocate(1);
	// new_node->data = *_value_alloc.allocate(1);
	_value_alloc.construct(&new_node->data,  value_type());
	// _value_alloc.construct(val_ptr,  value_type());
	// new_node->data = value_type();
	new_node->color = black;
	new_node->left = nullptr;
	new_node->right = nullptr;
	new_node->parent = _TNULL;
	new_node->is_nil = true;
	return (new_node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::create_node(const value_type &value)
{
	Node*				new_node;
	// pointer				val_ptr;

	new_node = _node_alloc.allocate(1);
	// _node_alloc.construct(new_node, value);
	// val_ptr = _value_alloc.allocate(1);
	// _value_alloc.construct(val_ptr,  value);
	// new_node->data = *_value_alloc.allocate(1);
	_value_alloc.construct(&new_node->data, value);
	// new_node->data = value;
	new_node->color = red;
	new_node->left = _TNULL;
	new_node->right = _TNULL;
	new_node->parent = nullptr;
	new_node->is_nil = false;
	return (new_node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>::RBTree(const RBTree& other)
{
	_root = other._root;
	_TNULL = other._TNULL;
	_size = other._size;
	_keyofvalue = other._keyofvalue;
	_comp = other._comp;
	_node_alloc = other._node_alloc;
	_value_alloc = other._value_alloc;
}

template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>& ft::RBTree<T, KeyofValue, Compare, Alloc>::operator=(const RBTree& other)
{
	if (this != &other)
	{
		RBTree	copy(other);
		this->swap(copy);
		return (*this);
	}
	return (*this);
}

template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>::~RBTree() 
{
	this->destroy(_root);
	return ;
}


template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::allocator_type ft::RBTree<T, KeyofValue, Compare, Alloc>::get_allocator() const
{
	return (_value_alloc);
}


template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::pre_order_helper(Node* node)
{
	if (node != _TNULL)
	{
		std::cout << node->data << " ";
		pre_order_helper(node->left);
		pre_order_helper(node->right);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::in_order_helper(Node* node)
{
	if (node != _TNULL)
	{
		in_order_helper(node->left);
		std::cout << node->data << " ";
		in_order_helper(node->right);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::post_order_helper(Node* node)
{
	if (node != _TNULL)
	{
		post_order_helper(node->left);
		post_order_helper(node->right);
		std::cout << node->data << " ";
	}
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::get_root()
{
	return (_root);
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::set_root(Node* new_root)
{
	_root = new_root;
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::insert_fix(Node* current_node)
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
		if (current_node == _root)
			break ;
	}
	_root->color = black;
}

template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree()
{
	if (_root)
	{
		// _myalgo.print_helper(this->_root, "", true);
		this->print_helper(this->_root, "", true);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc >
template <class P>
// void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree(typename ft::enable_if<std::is_same<P, ft::pair<typename P::first_type, typename P::second_type> >::value>)
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree(typename ft::enable_if<!ft::is_integral<P>::value, void>::type*)
{
	if (_root)
	{
		this->print_helper_pair(this->_root, "", true);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc>
void ft::RBTree<T, KeyofValue, Compare, Alloc>:: print_helper(Node* root, std::string indent, bool last)
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
		string sColor = root->color ? RED "red" RST : "black";
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


template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree_pair()
{
	if (_root)
	{
		print_helper_pair(this->_root, "", true);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc>
void ft::RBTree<T, KeyofValue, Compare, Alloc>:: print_helper_pair(Node* root, std::string indent, bool last)
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
		string sColor = root->color ? RED "red" RST : "black";
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


template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree(value_type value)
{
	return (search_tree_helper(_root, value));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree_const(const value_type &value) const
{
	return (search_tree_helper_const(_root, value));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree_helper(Node* node, value_type value)
{
	if (node == _TNULL || value == node->data)
		return (node);
	if (value < node->data)
		return (search_tree_helper(node->left, value));
	return (search_tree_helper(node->right, value));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree_helper_const(Node* node, const value_type& value) const
{
	if (node == _TNULL || value == node->data)
		return (node);
	if (value < node->data)
		return (search_tree_helper_const(node->left, value));
	return (search_tree_helper_const(node->right, value));
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::rb_transplant(Node* node_to_replace, Node* replacement_node)
{
	if (node_to_replace->parent == nullptr)
		_root = replacement_node;
	else if (node_to_replace == node_to_replace->parent->left)
		node_to_replace->parent->left = replacement_node;
	else
		node_to_replace->parent->right = replacement_node;
	replacement_node->parent = node_to_replace->parent;
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::delete_node_helper(Node* node, T value)
{
	Node*	node_to_delete;
	Node*	child_of_deleted_node;
	Node*	successor_of_deleted_node;
	Color	original_color_of_successor;

	node_to_delete = _TNULL;
	while (node != _TNULL)
	{
		if (_comp(node->data, value) == 0)
			node_to_delete = node;
		if (_comp(node->data, value))
			node = node->right;
		else
			node = node->left;
	}
	// while (node != _TNULL)
	// {
	// 	if (node->data == value)
	// 		node_to_delete = node;
	// 	if (node->data <= value)
	// 		node = node->right;
	// 	else
	// 		node = node->left;
	// }
	if (node_to_delete == _TNULL)
	{
		std::cout<<"Value not found in the tree" << std::endl;
		return ;
	}
	successor_of_deleted_node = node_to_delete;
	original_color_of_successor = successor_of_deleted_node->color;
	if (node_to_delete->left == _TNULL)
	{
		child_of_deleted_node = node_to_delete->right;
		rb_transplant(node_to_delete, node_to_delete->right);
	}
	else if (node_to_delete->right == _TNULL)
	{
		child_of_deleted_node = node_to_delete->left;
		rb_transplant(node_to_delete, node_to_delete->left);
	}
	else
	{
		successor_of_deleted_node = minimum(node_to_delete->right);
		original_color_of_successor = successor_of_deleted_node->color;
		child_of_deleted_node = successor_of_deleted_node->right;
		if (successor_of_deleted_node->parent == node_to_delete)
			child_of_deleted_node->parent = successor_of_deleted_node;
		else
		{
			rb_transplant(successor_of_deleted_node, successor_of_deleted_node->right);
			successor_of_deleted_node->right = node_to_delete->right;
			successor_of_deleted_node->right->parent = successor_of_deleted_node;
		}
		rb_transplant(node_to_delete, successor_of_deleted_node);
		successor_of_deleted_node->left = node_to_delete->left;
		successor_of_deleted_node->left->parent = successor_of_deleted_node;
		successor_of_deleted_node->color = node_to_delete->color;
	}
	if (original_color_of_successor == black)
		delete_fix(child_of_deleted_node);
}

// use sibling to fix violation
template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::delete_fix(Node* current_node)
{
	Node* sibling;
	while (current_node != _root && current_node->color == black)
	{
		if (current_node == current_node->parent->left)
		{
			sibling = current_node->parent->right;
			// case 1: sibling is red
			if (sibling->color == red)
			{
				sibling->color = black;
				sibling->parent->color = red;
				left_rotate(current_node->parent);
				sibling = current_node->parent->right;
			}

			// case 2: sibling is black and both children are black
			if (sibling->left->color == black && sibling->right->color == black)
			{
				sibling->color = red;
				current_node = current_node->parent;
			}
			else
			{
				// case 2: sibling is black and right children is black
				if (sibling->right->color == black)
				{
					sibling->left->color = black;
					sibling->color = red;
					right_rotate(sibling);
					sibling = current_node->parent->right;
				}
				sibling->color = current_node->parent->color;
				current_node->parent->color = black;
				sibling->right->color = black;
				left_rotate(current_node->parent);
				current_node = _root;
			}
		}
		else
		{
			sibling = current_node->parent->left;
			if (sibling->color == red)
			{
				sibling->color = black;
				sibling->parent->color = red;
				right_rotate(current_node->parent);
				sibling = current_node->parent->left;
			}

			if (current_node->right->color == black && sibling->right->color == black)
			{
				sibling->color = red;
				current_node = current_node->parent;
			}
			else
			{
				if (sibling->left->color == black)
				{
					sibling->right->color = black;
					sibling->color = red;
					left_rotate(sibling);
					sibling = current_node->parent->left;
				}
				sibling->color = current_node->parent->color;
				current_node->parent->color = black;
				sibling->left->color = black;
				right_rotate(current_node->parent);
				current_node = _root;
			}
		}
	}
	current_node->color = black;
}

template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::delete_node(value_type value)
{
	delete_node_helper(this->_root, value);
}


template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::minimum (Node* node) const
{
	while (node->left != _TNULL)
		node = node->left;
	return (node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::tree_minimum
() const
{
	return (minimum(_root));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::maximum(Node* node) const 
{
	while (node->right != _TNULL)
		node = node->right;
	return (node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::tree_maximum
() const
{
	return (maximum(_root));
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::left_rotate(Node* current_node)
{
	Node* right_child_of_current_node;
	
	right_child_of_current_node = current_node->right;
	current_node->right = right_child_of_current_node->left;
	if (right_child_of_current_node->left != _TNULL)
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

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::right_rotate(Node* current_node)
{
	Node* left_child_of_current_node;
	
	left_child_of_current_node = current_node->left;
	current_node->left = left_child_of_current_node->right;
	if (left_child_of_current_node->right != _TNULL)
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


template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::pre_order()
{
	this->pre_order_helper(_root);
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::in_order()
{
	this->in_order_helper(_root);
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::post_order()
{
	this->post_order_helper(_root);
}

// template <class T, class KeyofValue, class Compare, class Alloc >
// typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::successor(Node* current_node)
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


// template <class T, class KeyofValue, class Compare, class Alloc >
// typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::predecessor(Node* current_node)
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

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::get_tnull()
{
	return (_TNULL);
}

template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::destroy(Node* node)
{
	if (node == _TNULL)
		return ;
	// destroy(node->left);
	// destroy(node->right);
	if (node->left != _TNULL)
		destroy(node->left);
	if (node->right != _TNULL)
		destroy(node->right);
	_value_alloc.destroy(&node->data);
	// _node_alloc.deallocate(node, 1);
	// _value_alloc.deallocate(&node->data, 1); // here cause memory issue . maybe no need value_alloc
	_node_alloc.destroy(node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::begin()
{
	return (iterator(minimum(_root)));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::begin() const
{
	return (const_iterator(minimum(_root)));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::end()
{
	return (iterator(_TNULL));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::end() const
{
	return (const_iterator(_TNULL));
}


template <class T, class KeyofValue, class Compare, class Alloc >
bool		ft::RBTree<T, KeyofValue, Compare, Alloc>::empty() const
{
	return (this->size() == size_type(0));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::size_type	
ft::RBTree<T, KeyofValue, Compare, Alloc>::size() const
{
	return (size_helper(_root));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::size_type	
ft::RBTree<T, KeyofValue, Compare, Alloc>::size_helper(Node* node) const
{
	if (node == _TNULL)
		return (0);
	return (1 + size_helper(node->left) + size_helper(node->right));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::size_type	
ft::RBTree<T, KeyofValue, Compare, Alloc>::max_size() const
{
	size_type		max_alloc_size;
	difference_type	max_diff_type;

	max_alloc_size = _node_alloc.max_size();
	max_diff_type = std::numeric_limits<difference_type>::max();
	return (std::min(max_alloc_size, static_cast<size_type>(max_diff_type)));
}

template <class T, class KeyofValue, class Compare, class Alloc >
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::clear()
{
	this->destroy(this->_root);
	_root = _TNULL;
}


template <class T, class KeyofValue, class Compare, class Alloc>
ft::pair<typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator, bool>
ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const value_type& value)
{
	Node*				new_node;

	new_node = create_node(value);

	Node* current = _root;
	Node* parent = nullptr;
	while (current != _TNULL)
	{
		parent = current;
		if (_comp(value, current->data))
			current = current->left;
		else if (_comp(current->data, value))
			current = current->right;
		else
		{
			_value_alloc.destroy(&new_node->data);
			_node_alloc.deallocate(new_node, 1);
			_node_alloc.destroy(new_node);
			return (ft::make_pair(iterator(current), false)); /// so need pass, tnull
		}
	}
	new_node->parent = parent;
	if (parent == nullptr)
		_root = new_node;
	else if (_comp(value, parent->data))
		parent->left = new_node;
	else
		parent->right = new_node;
	if (new_node->parent == nullptr)
	{
		new_node->color = black;
		return (ft::make_pair(iterator(new_node), true));
	}
	if (new_node->parent->parent == nullptr || new_node->parent->parent == _TNULL)
		return (ft::make_pair(iterator(new_node), false));
	insert_fix(new_node);
	_TNULL->parent = _root;
	return (ft::make_pair(iterator(new_node), true));
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(iterator pos, const value_type& value)
{
	(void)pos;
	return (insert(value).first);
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class InputIt>
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(InputIt first, InputIt last, typename ft::enable_if<!std::is_integral<InputIt>::value, InputIt>::type*)
{
	for (InputIt tmp = first; tmp != last; tmp++)
	{
		insert((*tmp));
	}
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::erase(iterator pos)
{
	iterator ret;

	ret = pos;
	++ret;
	delete_node(*pos);
	return (ret);
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		first = erase(first);
	};
	return (first);
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::size_type	
ft::RBTree<T, KeyofValue, Compare, Alloc>::erase(const Key &key)
{
	iterator	it;

	it = search_node(key);
	if (it != this->end())
	{
		erase(it);
		return (1);
	}
	return (0);
}

template <class T, class KeyofValue, class Compare, class Alloc>
void	ft::RBTree<T, KeyofValue, Compare, Alloc>::swap(RBTree &other)
{
	ft::swap(_root, other._root);
	ft::swap(_TNULL, other._TNULL);
	ft::swap(_size, other._size);
	ft::swap(_keyofvalue, other._keyofvalue);
	ft::swap(_comp, other._comp);
	ft::swap(_node_alloc, other._node_alloc);
	ft::swap(_value_alloc, other._value_alloc);
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	
ft::RBTree<T, KeyofValue, Compare, Alloc>::search_node(const value_type& value) const
{
	Node*	node = _root;

	if (node == _TNULL)
		return (node);
	while (node != _TNULL)
	{
		if (_comp(value, node->data))
			node = node->left;
		else if (_comp(node->data, value))
			node = node->right;
		else
			return (node);
	}
	return (_TNULL);
}


template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::size_type	
ft::RBTree<T, KeyofValue, Compare, Alloc>::count(const Key& key) const
{
	return (this->search_node(key) == _TNULL ? 0 : 1);
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::find(const Key& key)
{
	iterator	ptr;

	ptr = this->search_node(key);
	return (ptr);
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::find(const Key& key) const
{
	const_iterator	ptr;

	ptr = this->search_node(key);
	return (ptr);
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::lower_bound( const Key& key )
{
	iterator	it;
	
	if (_root == _TNULL)
		return (this->end());
	for (it = tree_minimum(); it != _TNULL; it++)
	{
		if (!_comp(*it, key))
			break ;
	}
	return (iterator(it));
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::lower_bound( const Key& key ) const
{
	const_iterator	cit;
	
	if (_root == _TNULL)
		return (this->end());
	for (cit = tree_minimum(); cit != _TNULL; cit++)
	{
		if (!_comp(*cit, key))
			break ;
	}
	return (const_iterator(cit));
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::upper_bound( const Key& key )
{
	iterator	it;
	
	if (_root == _TNULL)
		return (this->end());
	for (it = tree_minimum(); it != _TNULL; it++)
	{
		if (!_comp(*it, key) && _comp(key, *it))
			break ;
	}
	return (iterator(it));
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator	
ft::RBTree<T, KeyofValue, Compare, Alloc>::upper_bound( const Key& key ) const
{
	const_iterator	cit;
	
	if (_root == _TNULL)
		return (this->end());
	for (cit = tree_minimum(); cit != _TNULL; cit++)
	{
		if (!_comp(*cit, key) && _comp(key, *cit))
			break ;
	}
	return (const_iterator(cit));
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
ft::pair<typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator, 
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator>	
ft::RBTree<T, KeyofValue, Compare, Alloc>::equal_range( const Key& key )
{
	return (ft::make_pair(lower_bound(key), upper_bound(key)));
}

template <class T, class KeyofValue, class Compare, class Alloc>
template <class Key>
ft::pair<typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator, 
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::const_iterator>	
ft::RBTree<T, KeyofValue, Compare, Alloc>::equal_range( const Key& key ) const
{
	return (ft::make_pair(lower_bound(key), upper_bound(key)));
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::key_of_value	
ft::RBTree<T, KeyofValue, Compare, Alloc>::key_comp() const
{
	return (_keyofvalue);
}

template <class T, class KeyofValue, class Compare, class Alloc>
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::value_compare	
ft::RBTree<T, KeyofValue, Compare, Alloc>::value_comp() const
{
	return (_comp);
}
