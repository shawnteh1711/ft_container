/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:00:33 by steh              #+#    #+#             */
/*   Updated: 2023/02/08 18:42:53 by steh             ###   ########.fr       */
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

	{
		ft::print_headers("Assignment operator");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		ft::set<int> 					set2 = set;
		std::set<int> 					std_set2 = std_set;
		ft::set_check(set2, std_set2);
	}

	{
		ft::print_headers("Assignment operator");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(set.get_allocator() == std_set.get_allocator());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Begin");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(*set.begin() == *std_set.begin());
		assert(*set.begin() == 1);
		assert(*std_set.begin() == 1);
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("End");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert((*--set.end()) == (*--std_set.end()));
		assert(*--set.end() == 3);
		assert((*--std_set.end()) == 3);
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Rbegin");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert((*set.rbegin()) == (*std_set.rbegin()));
		assert(*set.rbegin() == 3);
		assert((*std_set.rbegin()) == 3);
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Rend");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert((*--set.rend()) == (*--std_set.rend()));
		assert(*--set.rend() == 1);
		assert((*--std_set.rend()) == 1);
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Rend");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert((*--set.rend()) == (*--std_set.rend()));
		assert(*--set.rend() == 1);
		assert((*--std_set.rend()) == 1);
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Empty");

		ft::set<int> set;
		std::set<int> std_set;
		
		assert(set.empty() == std_set.empty());
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(set.empty() == std_set.empty());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Size");

		ft::set<int> set;
		std::set<int> std_set;
		
		assert(set.size() == std_set.size());
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(set.size() == std_set.size());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Max_size");

		size_t		my_max_alloc_size;
		size_t		std_max_alloc_size;

		ft::set<int> set;
		std::set<int> std_set;

		my_max_alloc_size = set.max_size();
		std_max_alloc_size = std_set.max_size();
		// assert(my_max_alloc_size == std_max_alloc_size);
	}

	{
		ft::print_headers("Clear");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		set.clear();
		std_set.clear();
		assert(set.size() == std_set.size());
	}

	{
		ft::print_headers("Insert");

		ft::set<int> set;
		std::set<int> std_set;
		ft::set<int> set2;
		std::set<int> std_set2;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		set.insert(set.begin(), 0);
		std_set.insert(std_set.begin(), 0);
		set.insert(--set.end(), 4);
		std_set.insert(--std_set.end(), 4);
		ft::set_check(set, std_set);

		set2.insert(set.begin(), set.end());
		std_set2.insert(std_set.begin(), std_set.end());
		ft::set_check(set2, std_set2);
	}

	{
		ft::print_headers("Erase");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		set.erase(set.begin());
		std_set.erase(std_set.begin());
		assert(set.erase(2) == std_set.erase(2));
		ft::set_check(set, std_set);
		set.erase(set.begin(), set.end());
		std_set.erase(std_set.begin(), std_set.end());
		assert(set.empty() == std_set.empty());
	}

	{
		ft::print_headers("Swap");

		ft::set<int> set;
		std::set<int> std_set;
		ft::set<int> set2;
		std::set<int> std_set2;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		set2.swap(set);
		std_set2.swap(std_set);
		ft::set_check(set2, std_set2);
	}

	{
		ft::print_headers("Count");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(set.count(3) == std_set.count(3));
		assert(set.count(4) == std_set.count(4));
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Find");

		ft::set<int> set;
		std::set<int> std_set;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		
		assert(*set.find(3) == *std_set.find(3));
		assert(set.find(4) == set.end());
		assert(std_set.find(4) == std_set.end());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Equal Range");

		ft::set<int>												set;
		ft::pair<ft::set<int>::iterator, ft::set<int>::iterator>	range;
		std::set<int> std_set;
		std::pair<std::set<int>::iterator, std::set<int>::iterator>	std_range;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);

		range = set.equal_range(1);
		std_range = std_set.equal_range(1);
		assert(range.first == set.begin());
		assert(std_range.first == std_set.begin());
		assert(range.second == std::next(range.first));
		assert(std_range.second == std::next(std_range.first));
		assert(*range.first == *std_range.first);
		assert(*range.second == *std_range.second);

		range = set.equal_range(3);
		std_range = std_set.equal_range(3);
		assert(range.second == std::next(range.first));
		assert(std_range.second == std::next(std_range.first));
		assert(*range.first == *std_range.first);
		assert(range.second == set.end());
		assert(std_range.second == std_set.end());

		// check no key , return first and second equat set end
		range = set.equal_range(4);
		std_range = std_set.equal_range(4);
		assert(range.first == set.end());
		assert(range.second == set.end());
		assert(std_range.first == std_set.end());
		assert(std_range.first == std_set.end());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Lower_bound");

		ft::set<int>				set;
		ft::set<int>::iterator		range;
		std::set<int>				std_set;
		std::set<int>::iterator		std_range;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		range = set.lower_bound(1);
		std_range = std_set.lower_bound(1);
		
		assert(range == set.begin());
		assert(std_range == std_set.begin());
		assert(*range == *std_range);
		assert(*range == 1);
		assert(*std_range == 1);

		range = set.lower_bound(3);
		std_range = std_set.lower_bound(3);
		assert(*range == *std_range);
		assert(*range == 3);
		assert(*std_range == 3);

		// check no key , return set end
		range = set.lower_bound(4);
		std_range = std_set.lower_bound(4);
		assert(range == set.end());
		assert(std_range == std_set.end());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Upper_bound");

		ft::set<int>				set;
		ft::set<int>::iterator		range;
		std::set<int>				std_set;
		std::set<int>::iterator		std_range;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		range = set.upper_bound(1);
		std_range = std_set.upper_bound(1);
		
		assert(*range == *std_range);
		assert(*range == 2);
		assert(*std_range == 2);

		// no key greater than will return end
		range = set.upper_bound(3);
		std_range = std_set.upper_bound(3);
		assert(range == set.end());
		assert(std_range == std_set.end());

		// check no key , return set end
		range = set.upper_bound(4);
		std_range = std_set.upper_bound(4);
		assert(range == set.end());
		assert(std_range == std_set.end());
		ft::set_check(set, std_set);
	}

	{
		ft::print_headers("Key_comp");

		ft::set<int, std::greater<int> >						set;
		ft::set<int, std::greater<int> >::key_compare		set_key_comp;
		std::set<int, std::greater<int> >					std_set;
		std::set<int, std::greater<int> >::key_compare		std_set_key_comp;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		set_key_comp = set.key_comp();
		std_set_key_comp = std_set.key_comp();
		
		assert(set_key_comp(1, 0) == std_set_key_comp(1, 0));
		assert(set_key_comp(0, 1) == std_set_key_comp(0, 1));
	}

	{
		ft::print_headers("Value_comp");

		ft::set<int, std::greater<int> >					set;
		ft::set<int, std::greater<int> >::value_compare		set_value_comp;
		std::set<int, std::greater<int> >					std_set;
		std::set<int, std::greater<int> >::value_compare	std_set_value_comp;
		
		set.insert(1);
		set.insert(2);
		set.insert(3);
		std_set.insert(1);
		std_set.insert(2);
		std_set.insert(3);
		set_value_comp = set.value_comp();
		std_set_value_comp = std_set.value_comp();
		
		assert(set_value_comp(1, 0) == std_set_value_comp(1, 0));
		assert(set_value_comp(0, 1) == std_set_value_comp(0, 1));
	}

	{
		ft::print_headers("Non-member function Operators");

		ft::set<int> set;
		ft::set<int> set2;
		ft::set<int> set3;

		set.insert(1);
	
		set2.insert(1);
		set2.insert(2);

		set3.insert(1);
		set3.insert(2);
		set3.insert(3);

		assert(!(set == set2));
		assert(!(set2 == set3));
		assert(set != set2);
		assert(set2 != set3);
		assert(set < set2);
		assert(set2 < set3);
		assert(set <= set2);
		assert(set2 <= set3);
		assert(set3 > set2);
		assert(set2 > set);
		assert(set3 >= set2);
		assert(set2 >= set);
		std::cout << "All Non-member functions pass" << std::endl;
		ft::print_set(set);
		ft::print_set(set2);
		ft::print_set(set3);
	}

	{
		ft::print_headers("Check Time Performance");

		clock_t	start_time;
		clock_t	end_time;
		double	ft_vec_time;
		double	std_vec_time;
		bool	rv;

		start_time = clock();

		ft::set<int>		set;
		ft::set<int>		set2;

		set2.insert(42);
		set.insert(1);
		set.insert(2);
		set.insert(3);
		set.get_allocator();
		set.begin();
		set.end();
		set.rbegin();
		set.rend();
		set.empty();
		set.size();
		set.max_size();
		set.clear();
		set.insert(set2.begin(), set2.end());
		set.insert(set.begin(), 4);
		set.count(1);
		set.find(1);
		set.equal_range(1);
		set.lower_bound(1);
		set.upper_bound(1);
		set.key_comp();
		set.value_comp();
		set.erase(set.begin());
		set.erase(set.begin(), set.end());
		set.insert(42);
		set.swap(set2);
		rv = (set == set2);
		rv = (set != set2);
		rv = (set < set2);
		rv = (set <= set2);
		rv = (set > set2);
		rv = (set >= set2);
		
		end_time = clock();
		ft_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "ft_vec_time: " << ft_vec_time << std::endl;

		start_time = clock();

		std::set<int>		s_set;
		std::set<int>		s_set2;

		s_set2.insert(42);
		s_set.insert(1);
		s_set.insert(2);
		s_set.insert(3);
		s_set.get_allocator();
		s_set.begin();
		s_set.end();
		s_set.rbegin();
		s_set.rend();
		s_set.empty();
		s_set.size();
		s_set.max_size();
		s_set.clear();
		s_set.insert(s_set2.begin(), s_set2.end());
		s_set.insert(s_set.begin(), 4);
		s_set.count(1);
		s_set.find(1);
		s_set.equal_range(1);
		s_set.lower_bound(1);
		s_set.upper_bound(1);
		s_set.key_comp();
		s_set.value_comp();
		s_set.erase(s_set.begin());
		s_set.erase(s_set.begin(), s_set.end());
		s_set.insert(42);
		s_set.swap(s_set2);
		rv = (s_set == s_set2);
		rv = (s_set != s_set2);
		rv = (s_set < s_set2);
		rv = (s_set <= s_set2);
		rv = (s_set > s_set2);
		rv = (s_set >= s_set2);
		
		end_time = clock();
		std_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "std vec time: " << std_vec_time << std::endl;
		std::cout << "Performance ratio of ft container compared to std container is: " << ft_vec_time / std_vec_time << " times\n" << std::endl;
	}
	system("leaks ft_container");

	return (0);
}
