/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:44:44 by steh              #+#    #+#             */
/*   Updated: 2023/01/19 22:39:59 by steh             ###   ########.fr       */
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
			T				data;
			Color			color;
			Node			*left;
			Node			*right;
			Node			*parent;

			Node(const T& d) : data(d), color(red), left(nullptr), right(nullptr), parent(nullptr) {};

			Node(const Node& other) : data(other.data), color(other.color), left(other.left), right(other.right), parent(other.parent){};

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
	};
}

#endif
