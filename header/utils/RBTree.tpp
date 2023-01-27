/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:06:25 by steh              #+#    #+#             */
/*   Updated: 2023/01/27 22:25:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"
#include <typeinfo>
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"


using namespace std;

// template <typename T>
// struct is_pair : std::false_type {};

// template <typename T1, typename T2>
// struct is_pair<std::pair<T1, T2> > : std::true_type {};

template <typename T>
bool is_pair(const T& x) {
	(void)x;
    return false;
}

// template <typename T, typename U>
template <typename K, typename V >
bool is_pair(const ft::pair<K, V>& x) {
	(void)x;
    return true;
}


template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>::RBTree(const value_compare& comp, const Alloc& alloc) : _keyofvalue(), _comp(comp), _alloc(alloc)
{
	_TNULL = new Node(T());
	_TNULL->color = black;
	_TNULL->left = nullptr;
	_TNULL->right = nullptr;
	_root = _TNULL;
	return ;
}

template <class T, class KeyofValue, class Compare, class Alloc >
ft::RBTree<T, KeyofValue, Compare, Alloc>::~RBTree() 
{
	return ;
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
void ft::RBTree<T, KeyofValue, Compare, Alloc>::post_order_traversal(Node *_root)
{
	if (_root == nullptr)
		return;
	post_order_traversal(_root->left);
	post_order_traversal(_root->right);
	std::cout << _root->value << " ";
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

// template <class T, class KeyofValue, class Compare, class Alloc >
// void	ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const K&  key, const V& value)
// {
// 	Node* new_node = new Node(key, value);
// 	// new_node->data = ft::pair<K, V>(key, value);f
// 	new_node->parent = nullptr;
// 	new_node->key = key;
// 	new_node->left = _TNULL;
// 	new_node->right = _TNULL;
// 	new_node->color = red;

// 	Node* parent_node = nullptr;
// 	Node* curren_node = this->_root;

// 	while (curren_node != _TNULL)
// 	{
// 		parent_node = curren_node;
// 		if (new_node->key < curren_node->key)
// 			curren_node = curren_node->left;
// 		else
// 			curren_node = curren_node->right;
// 	}
// 	new_node->parent = parent_node;
// 	if (parent_node == nullptr)
// 		_root = new_node;
// 	else if (new_node->key < parent_node->key)
// 		parent_node->left = new_node;
// 	else
// 		parent_node->right = new_node;

// 	if (new_node->parent == nullptr)
// 	{
// 		new_node->color = black;
// 		return ;
// 	}
// 	if (new_node->parent->parent == nullptr)
// 		return ;
// 	insert_fix(new_node);
// }

// template <class K, class V, class KeyofValue, class Compare, class Alloc>
// void ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const ft::pair<K, V>& key_value)
// {
// 	Node* new_node = new Node(key_value.first, key_value.second);
// 	new_node->left = _TNULL;
// 	new_node->right = _TNULL;

// 	// find the appropriate place to insert the new node
// 	Node* current_node = _root;
// 	Node* parent_node = nullptr;
// 	while (current_node != _TNULL)
// 	{
// 		parent_node = current_node;
// 		if (_comp(new_node->key, current_node->key))
// 			current_node = current_node->left;
// 		else
// 			current_node = current_node->right;
// 	}
// 	new_node->parent = parent_node;
// 	if (parent_node == nullptr)
// 		_root = new_node;
// 	else if (_comp(new_node->key, parent_node->key))
// 		parent_node->left = new_node;
// 	else
// 		parent_node->right = new_node;

// 	if (new_node->parent == nullptr)
// 	{
// 		new_node->color = black;
// 		return ;
// 	}
// 	if (new_node->parent->parent == nullptr)
// 		return ;
// 	// fix any violations of the red-black tree properties
// 	insert_fix(new_node);
// }


// template <class T, class KeyofValue, class Compare, class Alloc >
// void	ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const T&  value)
// {
// 	Node* new_node = new Node(value);
// 	new_node->parent = nullptr;
// 	new_node->data = value;
// 	new_node->left = _TNULL;
// 	new_node->right = _TNULL;
// 	new_node->color = red;

// 	Node* parent_node = _TNULL;
// 	Node* curren_node = this->_root;

// 	while (curren_node != _TNULL)
// 	{
// 		parent_node = curren_node;
// 		if (new_node->data < curren_node->data)
// 			curren_node = curren_node->left;
// 		else
// 			curren_node = curren_node->right;
// 	}
// 	new_node->parent = parent_node;
// 	if (parent_node == nullptr)
// 		_root = new_node;
// 	else if (new_node->data < parent_node->data)
// 		parent_node->left = new_node;
// 	else
// 		parent_node->right = new_node;

// 	if (new_node->parent == nullptr)
// 	{
// 		new_node->color = black;
// 		return ;
// 	}
// 	if (new_node->parent->parent == nullptr)
// 		return ;
// 	insert_fix(new_node);
// }

template <class T, class KeyofValue, class Compare, class Alloc>
ft::pair<typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator, bool>
ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const T& value)
{
	Node* new_node;

	const T& key = _keyofvalue(value);;
	new_node = new Node(value);
	new_node->left = _TNULL;
	new_node->right = _TNULL;

	Node* current = _root;
	Node* parent = nullptr;
	while (current != _TNULL)
	{
		parent = current;
		if (_comp(key, _keyofvalue(current->data)))
			current = current->left;
		else if (_comp(_keyofvalue(current->data), key))
			current = current->right;
		else
			return (ft::pair<iterator, bool>(iterator(current), false));
	}
	new_node->parent = parent;
	if (parent == nullptr)
		_root = new_node;
	else if (_comp(key, _keyofvalue(parent->data)))
		parent->left = new_node;
	else
		parent->right = new_node;
	if (new_node->parent == nullptr)
	{
		new_node->color = black;
		return (ft::pair<iterator, bool>(iterator(new_node), true));
	}
	if (new_node->parent->parent == nullptr || new_node->parent->parent == _TNULL)
		return (ft::pair<iterator, bool>(iterator(new_node), false));
	insert_fix(new_node);
	return (ft::pair<iterator, bool>(iterator(new_node), true));
}


// template <class K, class V, class KeyofValue, class Compare, class Alloc>
// void ft::RBTree<T, KeyofValue, Compare, Alloc>::insert(const ft::pair<K, V>& key_value)
// {
// 	Node* new_node = new Node(key_value.first, key_value.second);
// 	new_node->left = _TNULL;
// 	new_node->right = _TNULL;

// 	// find the appropriate place to insert the new node
// 	Node* current_node = _root;
// 	Node* parent_node = nullptr;
// 	while (current_node != _TNULL)
// 	{
// 		parent_node = current_node;
// 		if (_comp(new_node->key, current_node->key))
// 			current_node = current_node->left;
// 		else
// 			current_node = current_node->right;
// 	}
// 	new_node->parent = parent_node;
// 	if (parent_node == nullptr)
// 		_root = new_node;
// 	else if (_comp(new_node->key, parent_node->key))
// 		parent_node->left = new_node;
// 	else
// 		parent_node->right = new_node;

// 	if (new_node->parent == nullptr)
// 	{
// 		new_node->color = black;
// 		return ;
// 	}
// 	if (new_node->parent->parent == nullptr)
// 		return ;
// 	// fix any violations of the red-black tree properties
// 	insert_fix(new_node);
// }

template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree_by_level()
{
	std::queue<Node*> q;
	int level = 0;
	q.push(_root);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node* current = q.front();
			q.pop();
			if (current->left != nullptr)
				q.push(current->left);
			if (current->right != nullptr)
				q.push(current->right);
			// Print the node, you can format it as you wish
			if (current->color == red)
				std::cout << RED << current->data << ")" << "[R]" << RST;
			else
				std::cout << GRN << current->data << ")" << "[B]" << RST;
		}
		std::cout << std::endl;
		level++;
	}
}


// https://www.programiz.com/dsa/red-black-tree
template <class T, class KeyofValue, class Compare, class Alloc >
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_tree()
{
	if (_root)
	{
		print_helper(this->_root, "", true);
	}
}

template <class T, class KeyofValue, class Compare, class Alloc>
void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_helper(Node* root, std::string indent, bool last)
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
		// // if (is_pair<T>::value)
		// if (std::is_same<T, ft::pair<typename T::first_type, typename T::second_type> >::value)
		// {
		// 	std::cout<<"1"<<std::endl;
		// 	std::cout << root->data.first << ":" << root->data.second << " (" << sColor << ")" << std::endl;
		// }
		// else
		// {
		// 	std::cout<<"2"<<std::endl;
		// 	std::cout << root->data <<":" << " (" << sColor << ")" << std::endl;
		// }
		// std::cout << root->data <<  "(" << sColor << ")" << std::endl;
		// std::cout << root->data.first << ":" << root->data.second << " (" << sColor << ")" << std::endl;
		// if (std::is_base_of<std::pair<typename T::first_type, typename T::second_type>, T>::value)
		if(is_pair(root->data))
        {
			// std::cout<<"1"<<std::endl;
			// std::cout<<"is pair: "<<is_pair(root->data)<<std::endl;
			std::cout << root->data.first << ":" << root->data.second << " (" << sColor << ")" << std::endl;
        }
        else
        {
			// std::cout<<"2"<<std::endl;
			// std::cout<<"is pair: "<<is_pair(root->data)<<std::endl;

            std::cout << root->data;
        }
		// std::cout<<"3"<<std::endl;
		print_helper(root->left, indent, false);
		print_helper(root->right, indent, true);
	}
}

// template <class T, class KeyofValue, class Compare, class Alloc>
// template <class U>
// void ft::RBTree<T, KeyofValue, Compare, Alloc>::print_helper(Node* root, std::string indent, bool last, typename ft::enable_if<std::is_same<U, ft::pair<typename U::first_type, typename U::second_type> >::value, U>::type*)
// {
// 	if (root != nullptr)
// 	{
// 		std::cout << indent;
// 		if (last)
// 		{
// 			std::cout << "R----";
// 			indent += "   ";
// 		}
// 		else
// 		{
// 			std:: cout << "L----";
// 			indent += "|  ";
// 		}
// 		string sColor = root->color ? RED "red" RST : "black";
// 		std::cout << root->data.first << ":" << root->data.second << " (" << sColor << ")" << std::endl;
// 		print_helper(root->left, indent, false);
// 		print_helper(root->right, indent, true);
// 	}
// }

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree(T value)
{
	return (search_tree_helper(_root, value));
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::search_tree_helper(Node* node, T value)
{
	if (node == _TNULL || value == node->data)
		return (node);
	if (value < node->data)
		return search_tree_helper(node->left, value);
	return (search_tree_helper(node->right, value));
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
		if (node->data == value)
			node_to_delete = node;
		if (node->data <= value)
			node = node->right;
		else
			node = node->left;
	}
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
	delete node_to_delete;
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
void ft::RBTree<T, KeyofValue, Compare, Alloc>::delete_node(T value)
{
	delete_node_helper(this->_root, value);
}


template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::minimum(Node* node)
{
	while (node->left != _TNULL)
		node = node->left;
	return (node);
}

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node*	ft::RBTree<T, KeyofValue, Compare, Alloc>::maximum(Node* node)
{
	while (node->right != _TNULL)
		node = node->right;
	return (node);
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

template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::successor(Node* current_node)
{
	Node*	parent_node;
	if (current_node == nullptr)
		return (nullptr);
	if (current_node->right != _TNULL)
		return (minimum(current_node->right));
	parent_node = current_node->parent;
	while (parent_node != _TNULL && current_node == parent_node->right)
	{
		current_node = parent_node;
		parent_node = parent_node->parent;
	}
	return (parent_node);
}

// template <class T, class KeyofValue, class Compare, class Alloc >
// typename ft::RBTree<T, KeyofValue, Compare, Alloc>::iterator ft::RBTree<T, KeyofValue, Compare, Alloc>::successor(Node* current_node)
// {
// 	// check if input node is null or largest value in tree
// 	if (current_node == nullptr || current_node->right == _TNULL)
// 		return (this->end());

// 	Node* parent_node = current_node->parent;
// 	while (parent_node != _TNULL && current_node == parent_node->right)
// 	{
// 		current_node = parent_node;
// 		parent_node = parent_node->parent;
// 	}
// 	return (iterator(parent_node));
// }


template <class T, class KeyofValue, class Compare, class Alloc >
typename ft::RBTree<T, KeyofValue, Compare, Alloc>::Node* ft::RBTree<T, KeyofValue, Compare, Alloc>::predecessor(Node* current_node)
{
	Node*	parent_node;

	if (current_node == nullptr)
		return (nullptr);
	if (current_node->left != _TNULL)
		return (maximum(current_node->left));
	parent_node = current_node->parent;
	while (parent_node != _TNULL && current_node == parent_node->left)
	{
		current_node = parent_node;
		parent_node = parent_node->parent;
	}
	return (parent_node);
}
