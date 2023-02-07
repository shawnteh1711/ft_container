/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:00:33 by steh              #+#    #+#             */
/*   Updated: 2023/02/07 22:52:49 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/set.hpp"
#include "../header/set.tpp"
#include "../header/utils/RBTree.tpp"
#include <set>

int main(void)
{
	{
		ft::print_headers("Set Constructor");

		ft::set<int> set;
		std::set<int> std_set;

		set.insert(1);
		set.insert(1);
		std_set.insert(1);
		std_set.insert(1);

		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Range Constructor");

		ft::set<int> set;
		std::set<int> std_set;
		set.insert(1);
		set.insert(1);
		std_set.insert(1);
		std_set.insert(1);

		ft::set<int>	set2(set.begin(), set.end());
		std::set<int>	std_set2(std_set.begin(), std_set.end());
		ft::set_check(set2, std_set2);
	}

	{
		ft::print_headers("Template Constructor");

		ft::set<int, std::less<int> > 					set;
		ft::set<int, std::less<int> >::key_compare		set_key_compare;
		ft::set<int, std::less<int> >::iterator			it;
		std::set<int, std::less<int> > 					std_set;
		std::set<int, std::less<int> >::key_compare		std_set_key_compare;
		std::set<int, std::less<int> >::iterator			sit;
		
		set_key_compare = set.key_comp();
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set_key_compare = std_set.key_comp();
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		it = set.begin();
		for (sit = std_set.begin(); sit != std_set.end(); sit++, it++)
		{
			assert(*it == *sit);
		}
		assert(set_key_compare(1, 2) == std_set_key_compare(1, 2));
		assert(set_key_compare(2, 1) == std_set_key_compare(2, 1));
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Copy Constructor");

		ft::set<int> set;
		std::set<int> std_set;

		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);

		ft::set<int> 					set2(set);
		std::set<int> 					std_set2(std_set);
		ft::set_check(set2, std_set2);
	}
	// system("leaks ft_container");

	return (0);
}
