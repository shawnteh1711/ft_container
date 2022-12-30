/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:38:54 by steh              #+#    #+#             */
/*   Updated: 2022/12/30 17:50:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils/pair.hpp"
#include <iostream>

void	pair_test()
{
	ft::pair<int,char> foo (10,'a');
	ft::pair<int,char> bar (90,'z');
	foo.swap(bar);
	std::cout << "foo contains: " << foo.first;
	std::cout << " and " << foo.second << '\n';

	ft::pair <std::string,int> planet, homeplanet;
	planet = ft::make_pair("Earth",6371);
	homeplanet = planet;
	std::cout << "Home planet: " << homeplanet.first << '\n';
	std::cout << "Planet size: " << homeplanet.second << '\n';
}
