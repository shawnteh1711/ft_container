/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:17:04 by steh              #+#    #+#             */
/*   Updated: 2023/01/20 14:45:07 by steh             ###   ########.fr       */
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
	std::cout<<"result: "<<result.second<<std::endl;
	// tree.print_tree();
	// ft::RBTree<ft::pair<int, std::string> >				tree2;
	// ft::pair<int, std::string> data(2, "a");
	// tree2.insert(data);
	// tree2.print_tree();
	// tree.insert(2, "b");
	// tree.insert(3, "c");
	// tree.insert(4, "d");
	// tree.insert(5, "e");
	// tree.insert(6, "f");
	// tree.insert(7, "g");
	// ft::pair<int, std::string> data1(8, "h");
	// tree.insert(9);
	// tree.insert(data1.first, data1.second);
	// tree.insert(ft::pair<int, std::string>(10, "i"));

	// for (it = tree.begin(); it != tree.end(); it++)
	// {
	// 	std::cout << (*it).key << ": " << (*it).value << std::endl;
	// }
	// tree.print_tree();
	// tree.pre_order();
	// std::cout << std::endl;
	// tree.in_order();
	// std::cout << std::endl;
	// tree.post_order();
	// std::cout << std::endl;
	// std::cout<<"root: " << tree.get_root()->data << std::endl;
	// std::cout<<"max: " << tree.maximum(tree.get_root())->data << std::endl;
	// std::cout<<"min: " << tree.minimum(tree.get_root())->data << std::endl;
	// std::cout<<"value of 2 is : " << tree.search_tree(2)->value << std::endl;
	// std::cout << "successor of 3 is " << tree.successor(tree.search_tree(3))->key <<std::endl;
	// std::cout << "predecessor of 3 is " << tree.predecessor(tree.search_tree(3))->key <<std::endl;
	// tree.delete_node(1);
	// system("leaks ft_container");
}
