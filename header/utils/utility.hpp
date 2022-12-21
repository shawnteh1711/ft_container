/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 07:34:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>

namespace ft
{
    class pair
    {
        public:
        /*Constructor*/
            pair()
            {
                std::cout << "pair construct" << std::endl;
            }

        private:
    };
}

#endif