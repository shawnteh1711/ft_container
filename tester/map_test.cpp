/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:50:14 by steh              #+#    #+#             */
/*   Updated: 2023/03/06 17:16:35 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../header/map.hpp"
// #include "../header/map.tpp"
// #include "../header/utils/RBTree.tpp"
#include "../header/utils/test.hpp"
#include <map>
#include <list>



// --- Class foo
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}

#define T1 float
#define T2 foo<int>

int main(void)
{
	{
		ft::print_headers("Map Constructor");

		ft::map<int, std::string > map;
		std::map<int, std::string > std_map;

		map.insert(ft::make_pair(1, "a"));
		map.insert(ft::make_pair(1, "a"));
		map.insert(ft::make_pair(2, "b"));
		std_map.insert(std::make_pair(1, "a"));
		std_map.insert(std::make_pair(1, "a"));
		std_map.insert(std::make_pair(2, "b"));

		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Range Constructor");

		ft::map<int, std::string > map;
		map.insert(ft::make_pair(1, "a"));
		map.insert(ft::make_pair(2, "b"));
		std::map<int, std::string > std_map;
		std_map.insert(std::make_pair(1, "a"));
		std_map.insert(std::make_pair(2, "b"));

		ft::map<int, std::string>	map2(map.begin(), map.end());
		std::map<int, std::string>	std_map2(std_map.begin(), std_map.end());
		ft::map_check(map2, std_map2);
	}

	{
		ft::print_headers("Template Constructor");

		ft::map<int, int, std::greater<int> > 					map;
		ft::map<int, int, std::greater<int> >::key_compare		map_key_compare;
		ft::map<int, int, std::greater<int> >::iterator			it;
		std::map<int, int, std::greater<int> > 					std_map;
		std::map<int, int, std::greater<int> >::key_compare		std_map_key_compare;
		std::map<int, int, std::greater<int> >::iterator		sit;
		
		map_key_compare = map.key_comp();
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map_key_compare = std_map.key_comp();
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		
		it = map.begin();
		for (sit = std_map.begin(); sit != std_map.end(); sit++, it++)
		{
			assert(it->first == sit->first);
			assert(it->second == sit->second);
		}
		assert(map_key_compare(1, 2) == std_map_key_compare(1, 2));
	}

	{
		ft::print_headers("Copy Constructor");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		
		ft::map<int, int> 					map2(map);
		std::map<int, int> 					std_map2(std_map);
		map.clear();
		std_map.clear();
		ft::map_check(map2, std_map2);
	}

	{
		ft::print_headers("Assignment operator");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		
		ft::map<int, int> 					map2;
		map2 = map;
		map.clear();
		std::map<int, int> 					std_map2;
		std_map2 = std_map;
		std_map.clear();
		ft::map_check(map2, std_map2);
	}

	{
		ft::print_headers("get_allocator");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		
		assert(map.get_allocator() == std_map.get_allocator());
	}

	{
		ft::print_headers("at");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));

		try
		{
			assert(map.at(1) == std_map.at(1));
			map.at(4);
			std_map.at(4);
		}
		catch(const std::out_of_range& e)
		{
			std::cerr << e.what() << '\n';
		}
	}


	{
		ft::print_headers("operator[]");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		ft::map_check(map, std_map);
	}


	{
		ft::print_headers("Begin");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert(map.begin()->first == std_map.begin()->first);
		assert(map.begin()->second == std_map.begin()->second);
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("End");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert((--map.end())->first == 3);
		assert((--std_map.end())->first == 3);
		assert((--map.end())->second == 30);
		assert((--std_map.end())->second == 30);
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Rbegin");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert((map.rbegin())->first == 3);
		assert((std_map.rbegin())->first == 3);
		assert((map.rbegin())->second == 30);
		assert((std_map.rbegin())->second == 30);
		ft::map_check(map, std_map);
	}


	{
		ft::print_headers("Rend");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert((--map.rend())->first == 1);
		assert((--std_map.rend())->first == 1);
		assert((--map.rend())->second == 10);
		assert((--std_map.rend())->second == 10);
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Empty");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		assert(map.empty() == std_map.empty());
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		ft::map_check(map, std_map);
	}


	{
		ft::print_headers("Size");

		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;
		
		assert(map.size() == std_map.size());
		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert(map.size() == std_map.size());
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Max_size");

		// ft::map<int, int> 					map;
		// std::map<int, int> 					std_map;
		
		// assert(map.max_size() == std_map.max_size());
		// map.insert(ft::make_pair(1, 10));
		// map.insert(ft::make_pair(2, 20));
		// map.insert(ft::make_pair(3, 30));
		// std_map.insert(std::make_pair(1, 10));
		// std_map.insert(std::make_pair(2, 20));
		// std_map.insert(std::make_pair(3, 30));
		// assert(map.size() == std_map.size());
		// assert(map.size() == std_map.max_size());
		// ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Clear");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		map.clear();
		std_map.clear();
		assert(map.size() == std_map.size());
	}

	{
		ft::print_headers("Insert");
		ft::map<int, int> 					map;
		ft::map<int, int> 					map2;
		std::map<int, int> 					std_map;
		std::map<int, int> 					std_map2;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));

		map.insert(map.begin(), ft::make_pair(0, 0));
		std_map.insert(std_map.begin(), std::make_pair(0, 0));
		map.insert(--map.end(), ft::make_pair(4, 40));
		std_map.insert(--std_map.end(), std::make_pair(4, 40));
		ft::map_check(map, std_map);

		map2.insert(map.begin(), map.end());
		std_map2.insert(std_map.begin(), std_map.end());
		ft::map_check(map2, std_map2);
	}

	{
		ft::print_headers("Erase");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		map.erase(map.begin());
		std_map.erase(std_map.begin());
		assert(map.erase(2) == std_map.erase(2));
		ft::map_check(map, std_map);
		map.erase(map.begin(), map.end());
		std_map.erase(std_map.begin(), std_map.end());
		assert(map.empty() == std_map.empty());
	}

	{
		ft::print_headers("Swap");
		ft::map<int, int> 					map;
		ft::map<int, int> 					map2;
		std::map<int, int> 					std_map;
		std::map<int, int> 					std_map2;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		map2.swap(map);
		std_map2.swap(std_map);

		ft::map_check(map2, std_map2);
	}

	{
		ft::print_headers("Count");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert(map.count(3) == std_map.count(3));
		assert(map.count(4) == std_map.count(4));
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Find");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		assert(map.find(3)->first == std_map.find(3)->first);
		assert(map.find(3)->second == std_map.find(3)->second);
		// no key 4 , return end()
		assert(map.find(4) == map.end());
		assert(std_map.find(4) == std_map.end());
		ft::map_check(map, std_map);
	}


	{
		ft::print_headers("Equal Range");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>	range;
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>	std_range;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));
		

		range = map.equal_range(1);
		std_range = std_map.equal_range(1);
		assert(range.first == map.begin());
		assert(range.second  == std::next(range.first));
		assert(range.first->first == std_range.first->first);
		assert(range.first->second == std_range.first->second);
		assert(range.second->first == std_range.second->first);
		assert(range.second->second == std_range.second->second);

		range = map.equal_range(2);
		std_range = std_map.equal_range(2);
		assert(range.second  == std::next(range.first));
		assert(range.first->first == std_range.first->first);
		assert(range.first->second == std_range.first->second);
		assert(range.second->first == std_range.second->first);
		assert(range.second->second == std_range.second->second);
		ft::map_check(map, std_map);

		// check no key , return first and second equat set end
		range = map.equal_range(4);
		std_range = std_map.equal_range(4);
		assert(range.first == map.end());
		assert(range.second ==  map.end());
		assert(std_range.first == std_map.end());
		assert(std_range.second ==  std_map.end());
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Lower_bound");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		ft::map<int, int>::iterator			range;
		std::map<int, int>::iterator		std_range;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));

		range = map.lower_bound(1);
		std_range = std_map.lower_bound(1);
		assert(range->first == std_range->first);
		assert(range->second == std_range->second);
		assert(range == map.begin());
		assert(std_range == std_map.begin());

		// key not found, return end;
		range = map.lower_bound(4);
		std_range = std_map.lower_bound(4);
		assert(range == map.end());
		assert(std_range == std_map.end());
		
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Upper_bound");
		ft::map<int, int> 					map;
		std::map<int, int> 					std_map;

		ft::map<int, int>::iterator			range;
		std::map<int, int>::iterator		std_range;

		map.insert(ft::make_pair(1, 10));
		map.insert(ft::make_pair(2, 20));
		map.insert(ft::make_pair(3, 30));
		std_map.insert(std::make_pair(1, 10));
		std_map.insert(std::make_pair(2, 20));
		std_map.insert(std::make_pair(3, 30));

		// return 2
		range = map.upper_bound(1);
		std_range = std_map.upper_bound(1);
		assert(range->first == std_range->first);
		assert(range->second == std_range->second);
		assert(range != map.begin());
		assert(std_range != std_map.begin());

		// key not found, return end;
		range = map.upper_bound(4);
		std_range = std_map.upper_bound(4);
		// assert(range->first == std_range->first);
		// assert(range->second == std_range->second);
		assert(range == map.end());
		assert(std_range == std_map.end());
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Key_comp");
		ft::map<int, int, std::greater<int> > 					map;
		std::map<int, int, std::greater<int> > 					std_map;
		ft::map<int, int, std::greater<int> >::key_compare		map_key_compare;
		std::map<int, int, std::greater<int> >::key_compare		std_map_key_compare;

		map_key_compare = map.key_comp();
		std_map_key_compare = std_map.key_comp();
		assert(map_key_compare(1, 0) == std_map_key_compare(1, 0));
		assert(map_key_compare(0, 1) == std_map_key_compare(0, 1));
	}

	{
		ft::print_headers("Value_comp");
		ft::map<int, int, std::greater<int> > 						map;
		ft::map<int, int, std::greater<int> >::value_compare		map_value_compare;
		std::map<int, int, std::greater<int> > 						std_map;
		std::map<int, int, std::greater<int> >::value_compare		std_map_value_compare(std_map.value_comp());

		std_map_value_compare = std_map.value_comp();
		map_value_compare = map.value_comp();
		assert(map_value_compare(ft::make_pair(1, 10), ft::make_pair(2, 20)) == std_map_value_compare(std::make_pair(1, 10), std::make_pair(2, 20)));
		assert(map_value_compare(ft::make_pair(2, 20), ft::make_pair(1, 10)) == std_map_value_compare(std::make_pair(2, 20), std::make_pair(1, 10)));
	}

	{
		ft::print_headers("Non-member function Operators");

		ft::map<int, char> map;
		ft::map<int, char> map2;
		ft::map<int, char> map3;

		map.insert(ft::make_pair(1, 'a'));
	
		map2.insert(ft::make_pair(1, 'a'));
		map2.insert(ft::make_pair(2, 'b'));

		map3.insert(ft::make_pair(1, 'a'));
		map3.insert(ft::make_pair(2, 'b'));
		map3.insert(ft::make_pair(3, 'c'));

		assert(!(map == map2));
		assert(!(map2 == map3));
		assert(map != map2);
		assert(map2 != map3);
		assert(map < map2);
		assert(map2 < map3);
		assert(map <= map2);
		assert(map2 <= map3);
		assert(map3 > map2);
		assert(map2 > map);
		assert(map3 >= map2);
		assert(map2 >= map);
		std::cout << "All Non-member functions pass" << std::endl;
	}


	{
		ft::print_headers("Check Time Performance");

		clock_t	start_time;
		clock_t	end_time;
		double	ft_vec_time;
		double	std_vec_time;
		bool	rv;

		start_time = clock();

		ft::map<int, int>		map;
		ft::map<int, int>		map2;

		map2.insert(ft::make_pair(42, 42));
		map.insert(ft::make_pair(1, 1));
		map.insert(ft::make_pair(2, 2));
		map.insert(ft::make_pair(3, 3));
		map.get_allocator();
		map.at(1);
		map[1];
		map.begin();
		map.end();
		map.rbegin();
		map.rend();
		map.empty();
		map.size();
		map.max_size();
		map.clear();
		map.insert(map2.begin(), map2.end());
		map.insert(map.begin(), ft::make_pair(4, 4));
		map.count(1);
		map.find(1);
		map.equal_range(1);
		map.lower_bound(1);
		map.upper_bound(1);
		map.key_comp();
		map.value_comp();
		map.erase(map.begin());
		map.erase(map.begin(), map.end());
		map.insert(ft::make_pair(42, 42));
		map.swap(map2);
		rv = (map == map2);
		rv = (map != map2);
		rv = (map < map2);
		rv = (map <= map2);
		rv = (map > map2);
		rv = (map >= map2);
		
		end_time = clock();
		ft_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "ft_vec_time: " << ft_vec_time << std::endl;

		start_time = clock();

		std::map<int, int>		s_map;
		std::map<int, int>		s_map2;

		s_map2.insert(std::make_pair(42, 42));
		s_map.insert(std::make_pair(1, 1));
		s_map.insert(std::make_pair(2, 2));
		s_map.insert(std::make_pair(3, 3));
		s_map.get_allocator();
		s_map.at(1);
		s_map[1];
		s_map.begin();
		s_map.end();
		s_map.rbegin();
		s_map.rend();
		s_map.empty();
		s_map.size();
		s_map.max_size();
		s_map.clear();
		s_map.insert(s_map2.begin(), s_map2.end());
		s_map.insert(s_map.begin(), std::make_pair(4, 4));
		s_map.count(1);
		s_map.find(1);
		s_map.equal_range(1);
		s_map.lower_bound(1);
		s_map.upper_bound(1);
		s_map.key_comp();
		s_map.value_comp();
		s_map.erase(s_map.begin());
		s_map.erase(s_map.begin(), s_map.end());
		s_map.insert(std::make_pair(42, 42));
		s_map.swap(s_map2);
		rv = (s_map == s_map2);
		rv = (s_map != s_map2);
		rv = (s_map < s_map2);
		rv = (s_map <= s_map2);
		rv = (s_map > s_map2);
		rv = (s_map >= s_map2);
		
		end_time = clock();
		std_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "std vec time: " << std_vec_time << std::endl;
		std::cout << "Performance ratio of ft container compared to std container is: " << ft_vec_time / std_vec_time << " times\n" << std::endl;
	}

	{
		ft::print_headers("const_iterator");

		ft::map<int, int>			map;
		std::map<int, int>			smap;
		// map.insert(ft::make_pair(1, 10));
		// smap.insert(std::make_pair(1, 10));

		ft::map<int, int>::const_iterator cit = map.begin(), cite = map.end();
		std::map<int, int>::const_iterator scit = smap.begin(), scite = smap.end();

		if (cit == cite)
			std::cout << "map is empty" << std::endl;
		else
			std::cout << "map is not empty" << std::endl;

		if (scit == scite)
			std::cout << "map is empty" << std::endl;
		else
			std::cout << "map is not empty" << std::endl;

		for (; cit != cite; ++cit)
			std::cout << "data: " << cit->first  << std::endl;
		for (; scit != scite; ++cit)
			std::cout << "data: " << scit->first  << std::endl;
	}


{
		ft::print_headers("ite_arrow");

		ft::list<ft::pair<T1, T2> > lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
        	lst.push_back(ft::make_pair(2.5 + i, i + 1));

		for (ft::list<ft::pair<T1, T2> >::const_iterator it = lst.begin(); it != lst.end(); ++it)
  	    	ft::cout << (*it).first << ", " << (*it).second << std::endl;

		std::list<std::pair<T1, T2> > slst;
		unsigned int slst_size = 5;
		for (unsigned int i = 0; i < slst_size; ++i)
        	slst.push_back(std::make_pair(2.5 + i, i + 1));

		for (std::list<std::pair<T1, T2> >::const_iterator sit = slst.begin(); sit != slst.end(); ++sit)
  	    	std::cout << (*sit).first << ", " << (*sit).second << std::endl;
		
		ft::map<T1, T2>			map(lst.begin(), lst.end());
		std::map<T1, T2>			smap(slst.begin(), slst.end());

		ft::map<T1, T2>::iterator it(map.begin());
		std::map<T1, T2>::iterator sit(smap.begin());
		ft::map<T1, T2>::const_iterator cit(map.begin());
		std::map<T1, T2>::const_iterator scit(smap.begin());

		++it;
		++sit;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;
	
		++cit;
		++scit;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;
	
		it->second.m();
		cit->second.m();
		cit++;
		scit++;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;

		cit++;
		scit++;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;

		++cit;
		++scit;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;
		
		--cit;
		--scit;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;
	}

	{
		ft::print_headers("rite_arrow");

		ft::list<ft::pair<T1, T2> > lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
        	lst.push_back(ft::make_pair(2.5 + i, i + 1));

		for (ft::list<ft::pair<T1, T2> >::const_iterator it = lst.begin(); it != lst.end(); ++it)
  	    	ft::cout << (*it).first << ", " << (*it).second << std::endl;

		std::list<std::pair<T1, T2> > slst;
		unsigned int slst_size = 5;
		for (unsigned int i = 0; i < slst_size; ++i)
        	slst.push_back(std::make_pair(2.5 + i, i + 1));

		for (std::list<std::pair<T1, T2> >::const_iterator sit = slst.begin(); sit != slst.end(); ++sit)
  	    	std::cout << (*sit).first << ", " << (*sit).second << std::endl;
		
		ft::map<T1, T2>			map(lst.begin(), lst.end());
		std::map<T1, T2>			smap(slst.begin(), slst.end());

		ft::map<T1, T2>::reverse_iterator it(map.rbegin());
		std::map<T1, T2>::reverse_iterator sit(smap.rbegin());
		ft::map<T1, T2>::const_reverse_iterator cit(map.rbegin());
		std::map<T1, T2>::const_reverse_iterator scit(smap.rbegin());

		++cit;
		++scit;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;
	
		cit++;
		scit++;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;

		cit++;
		scit++;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;
	
		++cit;
		++scit;
		std::cout << "key: " << cit->first << "| value: " << cit->second << std::endl;
		std::cout << "std key: " << scit->first << "| value: " << scit->second << std::endl;

		it->second.m();
		sit->second.m();
		cit->second.m();
		scit->second.m();

		++it;
		++sit;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;

		it++;
		sit++;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;
		
		it++;
		sit++;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;
		
		++it;
		++sit;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;

		(*it).second.m();
		(*sit).second.m();
		(*cit).second.m();
		(*scit).second.m();
	
		--it;
		--sit;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;

		it--;
		sit--;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;
		
		it--;
		sit--;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;
		
		--it;
		--sit;
		std::cout << "key: " << it->first << "| value: " << it->second << std::endl;
		std::cout << "std key: " << sit->first << "| value: " << sit->second << std::endl;

	}


	// system("leaks ft_container");

	return (0);
}
