/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:17:04 by steh              #+#    #+#             */
/*   Updated: 2023/02/03 16:35:14 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils/RBTree.tpp"
#include <iostream>
#include <map>



void	rbtree_test()
{
	{
		std::cout<<"rbtree"<<std::endl;

		ft::RBTree<int>										tree;
		ft::pair<ft::RBTree<int>::iterator, bool>			result;

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

		std::cout<<"begin: "<< (*tree.begin()).data <<std::endl;
		std::cout<<"end: "<< (*tree.end()).data <<std::endl;
		ft::RBTree<int>::iterator							it;
		for (it = tree.begin(); it != tree.end(); ++it)
		{
			std::cout << (*it).data << std::endl;
		}
		for (it = --tree.end(); it >= tree.begin(); --it)
		{
			std::cout << (*it).data << std::endl;
		}
		tree.pre_order();
		std::cout << std::endl;
		tree.in_order();
		std::cout << std::endl;
		tree.post_order();
		std::cout << std::endl;
		std::cout << "root: " << tree.get_root()->data << std::endl;
		std::cout << "max: " << tree.maximum(tree.get_root())->data << std::endl;
		std::cout << "min: " << tree.minimum(tree.get_root())->data << std::endl;
		std::cout << "value of 2 is : " << tree.search_tree(2)->data << std::endl;
		std::cout << "empty: "<< (tree.empty() ? "true" : "false") << std::endl;
		std::cout<<"size:" << tree.size() << std::endl;
		std::cout << "max_size: "<< tree.max_size() << std::endl;
		// tree.delete_node(1);
		tree.insert(tree.end(), 10);
		tree.insert(tree.begin(), 5);
		// tree.clear();
		std::cout << "empty: "<< (tree.empty() ? "true" : "false") << std::endl;
		tree.print_tree();

		ft::RBTree<int>										tree3;
		tree3.insert(tree.begin(), tree.end());
		tree3.print_tree();
	}
	// system("leaks ft_container");
}
