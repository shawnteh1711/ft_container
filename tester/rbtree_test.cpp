/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:17:04 by steh              #+#    #+#             */
/*   Updated: 2023/01/28 21:34:06 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils/RBTree.tpp"
#include <iostream>



void	rbtree_test()
{
	std::cout<<"rbtree"<<std::endl;

	ft::RBTree<int>				tree;
	ft::pair<ft::RBTree<int>::iterator, bool>			result;
	ft::RBTree<int>::iterator	it;

	result = tree.insert(1);
	result = tree.insert(2);
	result = tree.insert(3);
	tree.print_tree();

	ft::RBTree<ft::pair<int, std::string> >				tree2;
	tree2.insert(ft::make_pair(2, "a"));
	tree2.insert(ft::make_pair(3, "b"));
	tree2.insert(ft::make_pair(4, "d"));
	tree2.print_tree_pair();
	// tree2.print_tree();
	std::cout<<"end: "<< (*tree.end()).data <<std::endl;
	for (it = tree.begin(); it != tree.end(); it++)
	{
		std::cout << (*it).data << std::endl;
	}
	// tree.pre_order();
	// std::cout << std::endl;
	// tree.in_order();
	// std::cout << std::endl;
	// tree.post_order();
	// std::cout << std::endl;
	// std::cout << "root: " << tree.get_root()->data << std::endl;
	// std::cout << "max: " << tree.maximum(tree.get_root())->data << std::endl;
	// std::cout << "min: " << tree.minimum(tree.get_root())->data << std::endl;
	// std::cout << "value of 2 is : " << tree.search_tree(2)->data << std::endl;
	// std::cout << "successor of 1 is " << tree.successor(tree.search_tree(1))->data <<std::endl;
	// if (tree.successor(tree.search_tree(3)) == nullptr)
	// 	std::cout << "successot of 3 is null" << std::endl;
	// std::cout << "predecessor of 3 is " << tree.predecessor(tree.search_tree(3))->data <<std::endl;
	// tree.delete_node(1);
	// tree.print_tree();
	// system("leaks ft_container");
}
