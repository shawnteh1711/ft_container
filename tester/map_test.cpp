/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:50:14 by steh              #+#    #+#             */
/*   Updated: 2023/02/06 22:00:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/map.hpp"
#include "../header/map.tpp"
#include "../header/utils/RBTree.tpp"
#include <map>

int main(void)
{
	{
		ft::print_headers("Map Constructor");

		ft::map<int, std::string > map;
		std::map<int, std::string > std_map;

		map.insert(ft::make_pair(1, "a"));
		map.insert(ft::make_pair(2, "b"));
		std_map.insert(std::make_pair(1, "a"));
		std_map.insert(std::make_pair(2, "b"));

		ft::print_map(map);
		ft::print_map(std_map);
		ft::map_check(map, std_map);
	}

	{
		ft::print_headers("Range Constructor");

		ft::map<int, std::string > map;
		// map.insert(ft::make_pair(1, "a"));
		// map.insert(ft::make_pair(2, "b"));
		std::map<int, std::string > std_map;
		// std_map.insert(std::make_pair(1, "a"));
		// std_map.insert(std::make_pair(2, "b"));

		// std::map<int, std::string> std_map2(std_map.begin(), std_map.end());
		// for (std::map<int, std::string>::iterator it = std_map2.begin();
		// 	it != std_map2.end(); ++it)
		// {
		// 	std::cout << " " << it->first << ":" << it->second;
		// }
		// std::cout << std::endl;
		// ft::map<int, std::string> map2(map.begin(), map.end());
		// for (ft::map<int, std::string>::iterator it = map2.begin();
		// 	it != map2.end(); ++it)
		// {
		// 	std::cout << " " << it->first << ":" << it->second;
		// }
		// std::cout << std::endl;


	}
	// system("leaks ft_container");

	return (0);
}
