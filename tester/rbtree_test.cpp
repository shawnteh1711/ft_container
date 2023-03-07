/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:17:04 by steh              #+#    #+#             */
/*   Updated: 2023/03/07 16:37:42 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils/RBTree.hpp"
#include <iostream>
#include <map>
#include <iterator>



void	rbtree_test()
{
	{
		std::cout<<"rbtree"<<std::endl;

		ft::RBTree<int>										tree;
		ft::pair<ft::RBTree<int>::iterator, bool>			result;

		result = tree.insert(1);
		result = tree.insert(2);
		result = tree.insert(3);
		result = tree.insert(1);
		
		tree.print_tree();

		ft::RBTree<ft::pair<int, std::string> >				tree2;
		tree2.insert(ft::make_pair(2, "a"));
		tree2.insert(ft::make_pair(3, "b"));
		tree2.insert(ft::make_pair(4, "d"));
		tree2.print_tree_pair();
		std::cout<<"tree 2 first: "<<tree2.begin()->first<<std::endl;
		std::cout<<"tree 2 first: "<<tree2.begin()->second<<std::endl;
		// tree2.print_tree();

	
		ft::RBTree<int>::iterator							it;
		for (it = tree.begin(); it != tree.end(); ++it)
		{
			std::cout << (*it) << std::endl;
		}
		for (it = --tree.end(); it >= tree.begin(); --it)
		{
			std::cout << (*it) << std::endl;
		}
		tree.pre_order();
		std::cout << std::endl;
		tree.in_order();
		std::cout << std::endl;
		tree.post_order();
		std::cout << std::endl;
		std::cout << "begin: " << *(tree.begin())<<std::endl;
		std::cout << "end: "   << *(tree.end()) <<std::endl;
		std::cout << "root: "  << tree.get_root()->data << std::endl;
		std::cout << "max: "   << tree.maximum(tree.get_root())->data << std::endl;
		std::cout << "min: "   << tree.minimum(tree.get_root())->data << std::endl;
		std::cout << "value of 2 is : " << (tree.search_tree(2))->data << std::endl;
		std::cout << "empty: " << (tree.empty() ? "true" : "false") << std::endl;
		std::cout<< "size:"    << tree.size() << std::endl;
		std::cout << "max_size: "<< tree.max_size() << std::endl;

		// // insert iterator and value
		tree.insert(tree.end(), 10);
		tree.insert(tree.begin(), 5);
		std::cout << "empty: "<< (tree.empty() ? "true" : "false") << std::endl;

		// // insert 2 iterator
		ft::RBTree<int>										tree3;
		tree3.insert(tree.begin(), tree.end());
		it = tree3.begin();

		// erase
		tree3.erase(it);
		tree3.erase(tree3.begin(), tree3.end());
		std::cout << "size: " << tree3.size() << std::endl;
		std::cout << "empty: "<< (tree3.empty() ? "true" : "false") << std::endl;

		tree3 = tree;
		tree3.print_tree();
		tree3.erase(3);
		tree3.print_tree();
		std::cout << "count: "<< (tree3.count(3) ? "1" : "0") << std::endl;
		std::cout << "count: "<< (tree3.count(1) ? "1" : "0") << std::endl;
		std::cout << "find: "<< *(tree3.find(3)) << std::endl;
		std::cout << "find: "<< *(tree3.find(1)) << std::endl;
		std::cout << "lower bound: "<< *(tree3.lower_bound(5)) << std::endl;
		std::cout << "lower bound: "<< *(tree3.lower_bound(6)) << std::endl;
		
		// try change return value of lower_bound
		it = tree3.lower_bound(5);
		if (it != tree3.end())
			(*it) = 6;
		std::cout << "lower bound: " << *(tree3.lower_bound(5)) << std::endl;
		
		// const lower_bound cannot change value
		ft::RBTree<int>::const_iterator cit;
		const ft::RBTree<int> &tree3_const = tree3;
		cit = tree3_const.lower_bound(5);
		std::cout << "const lower bound: " << (*cit) << std::endl;

		// upper bound
		ft::RBTree<int>		tree4;
		tree4.insert(1);
		tree4.insert(2);
		tree4.insert(6);
		tree4.insert(10);

		const ft::RBTree<int> &tree4_const = tree4;
		std::cout<<"lower bound of 2: "<<*(tree4.lower_bound(2))<<std::endl;
		std::cout<<"upper bound of 2: "<<*(tree4.upper_bound(2))<<std::endl;
		std::cout<<"cosnt upper bound of 2: "<<*(tree4_const.upper_bound(2))<<std::endl;


		ft::pair<ft::RBTree<int>::iterator, ft::RBTree<int>::iterator>						p;
		ft::pair<ft::RBTree<int>::const_iterator, ft::RBTree<int>::const_iterator>			cp;
		p = tree4.equal_range(2);
		cp = tree4_const.equal_range(2);
		// std::cout<<"equal range first of 2: " << (*p).first << std::endl;
		// std::cout<<"equal range second of 2: " << p.second << std::endl;
		// std::cout<<"const range first of 2: " << cp.first << std::endl;
		// std::cout<<"const range second of 2: " << cp.second << std::endl;
		// std::cout<<"range of 2: " << p << std::endl;
		// std::cout<<"const range of 2: " << cp << std::endl;

		// Observer
		ft::RBTree<int>::key_of_value	key_comp_func;

		key_comp_func = tree4.key_comp();
		int ret = key_comp_func(1);
		std::cout<<"key_comp return: " << ret << std::endl;
		ret = key_comp_func(8);
		std::cout<<"key_comp return: " << ret << std::endl;

		ft::RBTree<int>::value_compare	value_comp_func;
		bool ret_b = value_comp_func(1, 2);
		std::cout<<"1 is less than 2: " << (ret_b ? "yes" : "no" ) << std::endl;
		ret_b = value_comp_func(5, 1);
		std::cout<<"5 is less than 1: " << (ret_b ? "yes" : "no" ) << std::endl;
	}
	// system("leaks ft_container");
}
