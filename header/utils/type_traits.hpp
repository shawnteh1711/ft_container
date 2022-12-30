/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:45:52 by steh              #+#    #+#             */
/*   Updated: 2022/12/30 17:57:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

#include <cstdint> // char16_t, char32_t

//https://www.youtube.com/watch?v=H-m23Vvzcug

namespace ft
{
	// integral constant
	// T - Type of integral_constant
	// v - Value of integral_constant
	template <class T, T v>
	struct integral_constant
	{
		static const T						value = v;
		typedef T							value_type;
		typedef integral_constant<T, v>		type;
	};

	// enable-if
	// The EnableIf template is a type trait that enables or
	// disables a template or function depending on a compile-time
	// Boolean value. It is often used to enable or disable a template
	// or function only if a certain type or value meets certain conditions.

	// B - compile-time Boolean value, if B is true, enable-if template
	// define a type member typedef. if B is false, then enable-if template
	// does not define a type member typedef
	template<bool B, class T = void> struct enable_if {};

	// T(optional) - the type to be used as the type member typedef
	// if B is true. If T is not provided, the enable-if template defaults
	// to void
	template<class T> struct enable_if<true, T> { typedef T type; };

	// false and true value used as type during compile-time

	// template<bool> struct check_bool : public integral_constant <bool> {};
	typedef integral_constant<bool, false> false_type;
	typedef integral_constant<bool, true> true_type;

	template <class> struct is_integral_type						: public false_type {};
	template <> struct is_integral_type<bool>						: public true_type {};
	template <> struct is_integral_type<char>						: public true_type {};
	template <> struct is_integral_type<char16_t>					: public true_type {};
	template <> struct is_integral_type<char32_t>					: public true_type {};
	template <> struct is_integral_type<wchar_t>					: public true_type {};
	template <> struct is_integral_type<signed char>				: public true_type {};
	template <> struct is_integral_type<short int>					: public true_type {};
	template <> struct is_integral_type<int>						: public true_type {};
	template <> struct is_integral_type<long int>					: public true_type {};
	template <> struct is_integral_type<unsigned char>				: public true_type {};
	template <> struct is_integral_type<unsigned short int>			: public true_type {};
	template <> struct is_integral_type<unsigned int>				: public true_type {};
	template <> struct is_integral_type<unsigned long int>			: public true_type {};
	// 'long long' is a C++11 extension
	// template <> struct is_integral_type<long long int>				: public true_type {};
	// template <> struct is_integral_type<unsigned long long int>		: public true_type {};
	
	template <class T> struct is_integral : public is_integral_type<T>::type {};
}

#endif
