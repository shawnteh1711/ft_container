/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:44:44 by steh              #+#    #+#             */
/*   Updated: 2023/03/07 18:22:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	enum Color { black, red };
	template <typename T>
	class Node
	{
		public:
			
			typedef	Node<T>			node_type;

			T				data;
			Color			color;
			Node			*left;
			Node			*right;
			Node			*parent;
			bool			is_nil;

			Node(const T& d) : data(d), color(red), left(nullptr), right(nullptr), parent(nullptr), is_nil(false) {
				std::cout<<"node constructor"<<std::endl;
			};

			Node(const Node& other) : data(other.data), color(other.color), left(other.left), right(other.right), parent(other.parent), is_nil(false) {};

			~Node(){};

			Node& operator=(const Node& other)
			{
				if (this != &other)
				{
					data = other.data;
					color = other.color;
					left = other.left;
					right = other.right;
					parent = other.parent;
				}
				return (*this);
			}
			
			bool	check_nil(const Node* node) const
			{
				if (node == nullptr)
					return (true);
				if (node->is_nil)
					return (true);
				return (false);
			}

			Node* successor(Node* node)
			{
				Node*	parent_node;

				if (node == nullptr)
					return (nullptr);
				if (!check_nil(node->right))
				{
					// return (minimum(node->right));
					node = node->right;
					while (!check_nil(node->left))
						node = node->left;
					return (node);
				}
				parent_node = node->parent;
				while (parent_node != nullptr && node == parent_node->right)
				{
					node = parent_node;
					parent_node = parent_node->parent;
				}
				if (!parent_node)
					return (this->right);
				return (parent_node);
			}

			const Node* successor(const Node* node) const
			{
				const Node*	parent_node;

				if (node == nullptr)
					return (nullptr);
				if (!check_nil(node->right))
				{
					// return (minimum(node->right));
					node = node->right;
					while (!check_nil(node->left))
						node = node->left;
					return (node);
				}
				parent_node = node->parent;
				while (parent_node != nullptr && node == parent_node->right)
				{
					node = parent_node;
					parent_node = parent_node->parent;
				}
				if (!parent_node)
					return (this->right);
				return (parent_node);
			}

			Node* predecessor(const Node* node) const
			{
				Node*	parent_node;
				Node*	predecessor_node;

				if (node == nullptr)
					return (nullptr);
				if (node->is_nil && node->parent)
				{
					parent_node = node->parent;
					while (parent_node->parent != nullptr)
						parent_node = parent_node->parent;
					while (!check_nil(parent_node->right))
						parent_node = parent_node->right;
					return (parent_node);
				}
				if (!check_nil(node->left))
				{
					predecessor_node  = node->left;
					while (!check_nil(predecessor_node ->right))
						predecessor_node  = predecessor_node ->right;
					return (predecessor_node );
				}
				// return (maximum(node->left));
				parent_node = node->parent;
				while (parent_node != nullptr && node == parent_node->left)
				{
					node = parent_node;
					parent_node = parent_node->parent;
				}
				if (!parent_node)
					return (nullptr);
				return (parent_node);
			}

			Node* predecessor(Node* node) 
			{
				Node*	parent_node;
				Node*	predecessor_node;

				if (node == nullptr)
					return (nullptr);
				if (node->is_nil && node->parent)
				{
					parent_node = node->parent;
					while (parent_node->parent != nullptr)
						parent_node = parent_node->parent;
					while (!check_nil(parent_node->right))
						parent_node = parent_node->right;
					return (parent_node);
				}
				if (!check_nil(node->left))
				{
					predecessor_node  = node->left;
					while (!check_nil(predecessor_node ->right))
						predecessor_node  = predecessor_node ->right;
					return (predecessor_node );
				}
				// return (maximum(node->left));
				parent_node = node->parent;
				while (parent_node != nullptr && node == parent_node->left)
				{
					node = parent_node;
					parent_node = parent_node->parent;
				}
				if (!parent_node)
					return (nullptr);
				return (parent_node);
			}

	};
}

#endif
