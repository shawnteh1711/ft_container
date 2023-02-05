/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:50:14 by steh              #+#    #+#             */
/*   Updated: 2023/02/05 23:54:57 by steh             ###   ########.fr       */
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

		ft::map<std::string, int > map;
		std::map<std::string, int > std_map;
	}

	{
		ft::print_headers("Range Constructor");

		ft::map<std::string, int > map;
		std::map<std::string, int > std_map;
	}
	// system("leaks ft_container");

	return (0);
}
