/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:26:10 by hyap              #+#    #+#             */
/*   Updated: 2023/03/08 16:57:21 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template < typename T, typename U >
void	pre_test_int(T& x, U& y)
{
	print_content_header("Pre test: ", "push_back({0, 1, 2, 3, 4})");
	for (size_t i = 0; i < 5; i++)
		x.push_back(i);
	for (size_t i = 0; i < 5; i++)
		y.push_back(i);
}

template < typename T, typename U >
void	pre_test_string(T& x, U& y)
{
	print_content_header("Pre test: ", "push_back({\"One\", \"Two\", \"Three\"}})");
	x.push_back("One");
	x.push_back("Two");
	x.push_back("Three");
	y.push_back("One");
	y.push_back("Two");
	y.push_back("Three");
}

template < typename T, typename U >
void	test_constructor(T x, U y)
{
	std::stringstream	s;
	s << "Capacity [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Constructor: ", s.str());
	{
		T	a(5, 10);
		U	b(5, 10);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << a;
		ss << b;
		print_subsubcontent_compare("Constructor(5, 10)", "", myss.str(), ss.str());
	}
	{
		T	a(x.begin(), x.end());
		U	b(y.begin(), y.end());
		std::stringstream	myss;
		std::stringstream	ss;
		myss << a;
		ss << b;
		print_subsubcontent_compare("Constructor(begin(), end())", "", myss.str(), ss.str());
	}
	{
		T	a(x);
		U	b(y);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << a;
		ss << b;
		print_subsubcontent_compare("Constructor(vector)", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_capacity(T x, U y)
{
	std::stringstream	s;
	s << "Capacity [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member Functions: ", s.str());
	print_subsubcontent_compare("empty()", "", x.empty(), y.empty());
	print_subsubcontent_compare("size()", "", x.size(), y.size());
	print_subsubcontent_compare("max_size()", "", x.max_size(), y.max_size());
	print_subsubcontent_compare("capacity()", "", x.capacity(), y.capacity());
	x.reserve(10);
	y.reserve(10);
	std::stringstream	myss;
	std::stringstream	ss;
	myss << x;
	ss << y;
	print_subsubcontent_compare("reserve(10): ", "Check capacity", myss.str(), ss.str());
	std::cout << std::endl;
}

template < typename T, typename U >
void	test_element_access(T x, U y)
{
	std::stringstream	s;
	s << "Element access [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	print_subsubcontent_compare("operator[2]", "", x[2], y[2]);
	print_subsubcontent_compare("at(2)", "", x.at(2), y.at(2));
	print_subcontent_header("at(6) ", "Exception");
	try { x.at(6); } catch (const std::out_of_range& e) { print_subsubcontent(MY, e.what()); }
	try { y.at(6); } catch (const std::out_of_range& e) { print_subsubcontent(EXPECTED, e.what()); }
	print_subsubcontent_compare("front()", "", x.front(), y.front());
	print_subsubcontent_compare("back()", "", x.back(), y.back());
	print_subsubcontent_compare("data()", "", x.data(), y.data());
	print_subsubcontent_compare("data() ", "dereference", *(x.data()), *(y.data()));
	std::cout << std::endl;
}

template < typename T, typename U >
void	test_iterator(T x, U y)
{
	typename T::iterator			myit;
	typename U::iterator			it;
	typename T::const_iterator	cmyit;
	typename U::const_iterator	cit;

	std::stringstream	s;
	s << "Iterators [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	myit = x.begin();
	it = y.begin();
	print_subcontent("it = begin()", "");
	print_subsubcontent_compare("begin()", "", *myit, *it);
	print_subsubcontent_compare("it[2]", "", myit[2], it[2]);
	print_subsubcontent_compare("++it", "", *(++myit), *(++it));
	print_subsubcontent_compare("it++", "", *(myit++), *(it++));
	print_subsubcontent_compare("--it", "", *(--myit), *(--it));
	print_subsubcontent_compare("it--", "", *(myit--), *(it--));
	print_subsubcontent_compare("it += 2", "", *(myit += 2), *(it += 2));
	print_subsubcontent_compare("it -= 2", "", *(myit -= 2), *(it -= 2));
	print_subsubcontent_compare("it + 2", "", *(myit = myit + 2), *(it = it + 2));
	print_subsubcontent_compare("it - 2", "", *(myit = myit - 2), *(it = it - 2));
	print_subsubcontent_compare("end() - begin()", "", x.end() - x.begin(), y.end() - y.begin());
	print_subsubcontent_compare("*(begin())", "", *(x.begin()), *(y.begin()));
	print_subsubcontent_compare("end() == begin()", "", x.end() == x.begin(), y.end() == y.begin());
	print_subsubcontent_compare("end() != begin()", "", x.end() != x.begin(), y.end() != y.begin());
	print_subsubcontent_compare("begin() > end()", "", x.begin() > x.end(), y.begin() > y.end());
	print_subsubcontent_compare("begin() < end()", "", x.begin() < x.end(), y.begin() < y.end());
	print_subsubcontent_compare("begin() <= begin()", "", x.begin() <= x.begin(), y.begin() <= y.begin());
	print_subsubcontent_compare("end() >= end()", "", x.end() >= x.end(), y.end() >= y.end());

	s.str(std::string());
	s << "Modify Iterators [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	{
		myit = x.begin();
		it = y.begin();
		*myit = 99;
		*it = 99;
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("it = begin() ", "*it = 99", myss.str(), ss.str());
	}
	{
		myit = x.begin() + 3;
		it = y.begin() + 3;
		*myit = -3;
		*it = -3;
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("it = begin() + 3 ", "*it = -3", myss.str(), ss.str());
	}
	{
		myit = x.end() - 1;
		it = y.end() - 1;
		*myit = 0;
		*it = 0;
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("it = end() - 1 ", "*it = 0", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_clear(T x, U y)
{
	x.clear();
	y.clear();
	std::stringstream	myss;
	std::stringstream	ss;
	myss << x;
	ss << y;
	print_subsubcontent_compare("clear() ", "", myss.str(), ss.str());
}

template < typename T, typename U >
void	test_insert(T x, U y)
{
	std::stringstream	s;
	s << "Modifiers (Insert) [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	T	a(x);
	U	b(y);

	typename T::iterator	myit;
	typename U::iterator	it;
	typename T::iterator	myit2;
	typename U::iterator	it2;

	{
		myit = x.insert(x.end(), 5);
		it = y.insert(y.end(), 5);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(end(), 5)", "", myss.str(), ss.str());
	}
	{
		myit = x.insert(x.begin(), -1);
		it = y.insert(y.begin(), -1);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(begin(), -1)", "", myss.str(), ss.str());
	}
	{
		myit = x.insert(x.begin() + 1, 2, 0);
		it = y.insert(y.begin() + 1, 2, 0);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(begin(), 2, 0)", "", myss.str(), ss.str());
	}
	{
		myit = x.insert(x.end(), 2, 5);
		it = y.insert(y.end() , 2, 5);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(end(), 2, 5)", "", myss.str(), ss.str());
	}
	{
		myit = x.insert(x.begin(), a.begin(), a.begin() + 4);
		it = y.insert(y.begin(), b.begin(), b.begin() + 4);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(begin(), a.begin(), a.begin() + 4)", "", myss.str(), ss.str());
	}
	{
		myit = x.insert(x.end(), a.begin(), a.begin() + 4);
		it = y.insert(y.end(), b.begin(), b.begin() + 4);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("insert(end(), a.begin(), a.begin() + 4)", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_erase(T x, U y)
{
	std::stringstream	s;
	s << "Modifiers (Erase) [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	typename T::iterator	myit;
	typename U::iterator	it;

	{
		myit = x.erase(x.begin());
		it = y.erase(y.begin());
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("erase(begin())", "", myss.str(), ss.str());
	}
	{
		myit = x.erase(x.begin(), x.begin() + 2);
		it = y.erase(y.begin(), y.begin() + 2);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ft::distance(x.begin(), myit) << " | " << x;
		ss << ft::distance(y.begin(), it) << " | " << y;
		print_subsubcontent_compare("erase(begin(), x.begin() + 2)", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_push_back(T x, U y)
{
	std::stringstream	s;
	s << "Modifiers (push_back) [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	{
		x.push_back(5);
		y.push_back(5);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("push_back(5)", "", myss.str(), ss.str());
	}
	{
		x.push_back(6);
		y.push_back(6);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("push_back(6)", "", myss.str(), ss.str());
	}
	{
		T	w(x);
		U	z(y);
		w.clear();
		z.clear();
		w.push_back(0);
		z.push_back(0);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << w;
		ss << z;
		print_subsubcontent_compare("push_back(0) ", "empty vector", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_pop_back(T x, U y)
{
	std::stringstream	s;
	s << "Modifiers (pop_back) [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	{
		x.pop_back();
		y.pop_back();
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("pop_back()", "", myss.str(), ss.str());
	}
	{
		x.pop_back();
		y.pop_back();
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("pop_back()", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_resize(T x, U y)
{
	std::stringstream	s;
	s << "Modifiers (resize) [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	{
		x.resize(3, 99);
		y.resize(3, 99);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("resize(3, 99)", "", myss.str(), ss.str());
	}
	{
		x.resize(10, 99);
		y.resize(10, 99);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("resize(10, 99)", "", myss.str(), ss.str());
	}
	{
		T	w(x);
		U	z(y);
		w.clear();
		z.clear();
		w.resize(5, 99);
		z.resize(5, 99);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << w;
		ss << z;
		print_subsubcontent_compare("resize(5, 99) ", "empty vector", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_swap(T x, U y)
{
	print_content_header("Member functions: ", "swap");
	T	w;
	w.push_back(8);
	w.push_back(9);
	U	z;
	z.push_back(8);
	z.push_back(9);
	{
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "[" << x << "]  [" << w << "]";
		ss << "[" << y << "]  [" << z << "]";
		print_subsubcontent_compare("swap() ", "Before", myss.str(), ss.str());
	}
	x.swap(w);
	z.swap(y);
	{
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "[" << x << "]  [" << w << "]";
		ss << "[" << y << "]  [" << z << "]";
		print_subsubcontent_compare("swap() ", "After", myss.str(), ss.str());
	}
	print_content_header("Non-Member functions: ", "swap");
	ft::swap(x, w);
	std::swap(y, z);
	{
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "[" << x << "]  [" << w << "]";
		ss << "[" << y << "]  [" << z << "]";
		print_subsubcontent_compare("ft::swap() ", "After", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_operators_n_lexicographical(T x, U y)
{
	T	w;
	w.push_back(0); w.push_back(2); w.push_back(3); w.push_back(4); w.push_back(5);
	U	z;
	z.push_back(0); z.push_back(2); z.push_back(3); z.push_back(4); z.push_back(5);
	{
		std::stringstream	s;
		s << "[" << x << "] < [" << w << "]";
		print_subsubcontent_compare(s.str(), "", x < w, y < z);
	}
	{
		std::stringstream	s;
		s << "[" << x << "] > [" << w << "]";
		print_subsubcontent_compare(s.str(), "", x > w, y > z);
	}
	{

		std::stringstream	s;
		s << "[" << x << "] <= [" << w << "]";
		print_subsubcontent_compare(s.str(), "", x <= w, y <= z);
	}
	{
		std::stringstream	s;
		s << "[" << x << "] >= [" << w << "]";
		print_subsubcontent_compare(s.str(), "", x >= w, y >= z);
	}
	T	a(x);
	U	b(y);
	{

		std::stringstream	s;
		s << "[" << x << "] <= [" << a << "]";
		print_subsubcontent_compare(s.str(), "", x <= a, y <= b);
	}
	{
		std::stringstream	s;
		s << "[" << x << "] >= [" << a << "]";
		print_subsubcontent_compare(s.str(), "", x >= a, y >= b);
	}
}

template < typename T, typename U >
void	test_reverse_iterator(T x, U y)
{
	typename T::reverse_iterator	rmyit(x.rbegin());
	typename T::reverse_iterator	rbmyit(x.rend());
	typename U::reverse_iterator	rit(y.rbegin());
	typename U::reverse_iterator	rbit(y.rend());

	std::stringstream	s;
	s << "Reverse Iterators [";
	for (size_t i = 0; i < x.size(); i++)
		s << x[i] << (i == x.size() - 1 ? "" : ", ");
	s << "]";
	print_content_header("Member functions: ", s.str());
	print_subcontent("it(end())", "");
	print_subsubcontent_compare("*it", "", *rmyit, *rit);
	print_subsubcontent_compare("it[4]", "", rmyit[4], rit[4]);
	print_subsubcontent_compare("++it", "", *(++rmyit), *(++rit));
	print_subsubcontent_compare("it++", "", *(rmyit++), *(rit++));
	print_subsubcontent_compare("--it", "", *(--rmyit), *(--rit));
	print_subsubcontent_compare("it--", "", *(rmyit--), *(rit--));
	print_subsubcontent_compare("it += 2", "", *(rmyit += 2), *(rit += 2));
	print_subsubcontent_compare("it -= 2", "", *(rmyit -= 2), *(rit -= 2));
	print_subsubcontent_compare("it + 2", "", *(rmyit = rmyit + 2), *(rit = rit + 2));
	print_subsubcontent_compare("it - 2", "", *(rmyit = rmyit - 2), *(rit = rit - 2));
	// print_subsubcontent_compare("end() - begin()", "", x.end() - x.begin(), y.end() - y.begin());
	print_subsubcontent_compare("end() == begin()", "", rmyit == rbmyit, rit == rbit);
	print_subsubcontent_compare("end() != begin()", "", rmyit != rbmyit, rit != rbit);
	print_subsubcontent_compare("begin() > end()", "", rbmyit > rmyit, rbit > rit);
	print_subsubcontent_compare("begin() < end()", "", rbmyit < rmyit, rbit < rit);
	print_subsubcontent_compare("begin() <= begin()", "", rbmyit <= rbmyit, rbit <= rbit);
	print_subsubcontent_compare("end() >= end()", "", rmyit >= rmyit, rit >= rit);

	print_subsubcontent_compare("3 + end()", "", *(3 + rmyit), *(3 + rit));
	print_subsubcontent_compare("end() - (begin() - 3)", "", (rmyit - (rbmyit - 3)), (rit - (rbit - 3)));
	// print_subsubcontent_compare("->at(1)", "", rmyit->at(1), rit->at(1));
}

template < typename T, typename U >
void	pre_test_stack(T& x, U& y)
{
	for (int i = 0; i < 5; i++)
		x.push(i);
	for (int i = 0; i < 5; i++)
		y.push(i);
}

template < typename T, typename U >
void	test_stack(T x, U y)
{
	print_content_header("Stack: ", "[0, 1, 2, 3, 4]");
	print_subsubcontent_compare("top()", "", x.top(), y.top());
	print_subsubcontent_compare("empty()", "", x.empty(), y.empty());
	print_subsubcontent_compare("size()", "", x.size(), y.size());
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.push(5);
		y.push(5);
		myss << x;
		ss << y;
		print_subsubcontent_compare("push(5)", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.push(6);
		y.push(6);
		myss << x;
		ss << y;
		print_subsubcontent_compare("push(6)", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.pop();
		y.pop();
		myss << x;
		ss << y;
		print_subsubcontent_compare("pop()", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.pop();
		y.pop();
		myss << x;
		ss << y;
		print_subsubcontent_compare("pop()", "", myss.str(), ss.str());
	}
	T	a;
	U	b;
	a.push(2);
	a.push(3);
	a.push(4);
	b.push(2);
	b.push(3);
	b.push(4);
	{
		std::stringstream	ss;
		ss << x << " == " << a;
		print_subsubcontent_compare(ss.str(), "", x == a, y == b);
	}
	{
		std::stringstream	ss;
		ss << x << " != " << a;
		print_subsubcontent_compare(ss.str(), "", x != a, y != b);
	}
	{
		std::stringstream	ss;
		ss << x << " < " << a;
		print_subsubcontent_compare(ss.str(), "", x < a, y < b);
	}
	{
		std::stringstream	ss;
		ss << x << " <= " << a;
		print_subsubcontent_compare(ss.str(), "", x <= a, y <= b);
	}
	{
		std::stringstream	ss;
		ss << x << " > " << a;
		print_subsubcontent_compare(ss.str(), "", x > a, y > b);
	}
	{
		std::stringstream	ss;
		ss << x << " >= " << a;
		print_subsubcontent_compare(ss.str(), "", x >= a, y >= b);
	}
}

template < typename T, typename U >
void	test_pair(T x, U y)
{
	T	mypair("Hi there", 20);
	U	pair("Hi there", 20);

	print_content_header("pair<std::string, int>: ", "( Hello world, 10 ) ( Hi there, 20 )");
	print_subsubcontent_compare("( Hello world, 10 ) < ( Hi there, 20 )", "", x < mypair, y < pair);
	print_subsubcontent_compare("( Hello world, 10 ) <= ( Hi there, 20 )", "", x <= mypair, y <= pair);
	print_subsubcontent_compare("( Hello world, 10 ) > ( Hi there, 20 )", "", x > mypair, y > pair);
	print_subsubcontent_compare("( Hello world, 10 ) >= ( Hi there, 20 )", "", x >= mypair, y >= pair);
	print_subsubcontent_compare("( Hello world, 10 ) == ( Hi there, 20 )", "", x == mypair, y == pair);
	print_subsubcontent_compare("( Hello world, 10 ) != ( Hi there, 20 )", "", x != mypair, y != pair);
}

template < typename T, typename U >
void	pre_test_map(T& x, U& y)
{
	print_content_header("Pre test: ", "insert( {0, AAAAAA}, {1, BBBBB}, {2, CCCC}, {3, DDD}, {4, EE}, {5, F} )");
	std::string	s[6] = {"AAAAAA", "BBBBB", "CCCC", "DDD", "EE", "F"};

	for (int i = 0; i < 6; i++)
		x.insert(FT_MAKE_PAIR(i, s[i]));
	for (int i = 0; i < 6; i++)
		y.insert(std::make_pair(i, s[i]));
}

template < typename T, typename U >
void	test_map_constructor(T x, U y)
{
	{
		T	a(x.begin(), x.end());
		U	b(y.begin(), y.end());
		std::stringstream	myss;
		std::stringstream	ss;
		myss << a;
		ss << b;
		print_subsubcontent_compare("constructor(begin(), end())", "", myss.str(), ss.str());
	}
	{
		T	a(x);
		U	b(y);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << a;
		ss << b;
		print_subsubcontent_compare("constructor(map)", "", myss.str(), ss.str());
	}

}

template < typename T, typename U >
void	test_map_capacity(T x, U y)
{
	std::stringstream	s;
	s << "Capacity ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	print_subsubcontent_compare("empty()", "", x.empty(), y.empty());
	print_subsubcontent_compare("size()", "", x.size(), y.size());
	print_subsubcontent_compare("max_size()", "", x.max_size(), y.max_size());
	std::cout << std::endl;
}

template < typename T, typename U >
void	test_map_lookup(T x, U y)
{
	std::stringstream	s;
	s << "Look up ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	print_subsubcontent_compare("count(1)", "", x.count(1), y.count(1));
	print_subsubcontent_compare("count(99)", "", x.count(99), y.count(99));
	{
		typename T::iterator			myit = x.find(3);
		typename U::iterator			it = y.find(3);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("find(3)", "", myss.str(), ss.str());
	}
	{
		FT_PAIR<typename T::iterator, typename T::iterator>			myitpair = x.equal_range(2);
		std::pair<typename U::iterator, typename U::iterator>			itpair = y.equal_range(2);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myitpair.first->first << ", " << myitpair.first->second << "} {" << myitpair.second->first << ", " << myitpair.second->second << "} | " << x;
		ss << "{" << itpair.first->first << ", " << itpair.first->second << "} {" << itpair.second->first << ", " << itpair.second->second << "} | " << y;
		print_subsubcontent_compare("equal_range(2)", "", myss.str(), ss.str());
	}
	{
		FT_PAIR<typename T::iterator, typename T::iterator>			myitpair = x.equal_range(3);
		std::pair<typename U::iterator, typename U::iterator>			itpair = y.equal_range(3);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myitpair.first->first << ", " << myitpair.first->second << "} {" << myitpair.second->first << ", " << myitpair.second->second << "} | " << x;
		ss << "{" << itpair.first->first << ", " << itpair.first->second << "} {" << itpair.second->first << ", " << itpair.second->second << "} | " << y;
		print_subsubcontent_compare("equal_range(3)", "", myss.str(), ss.str());
	}
	{
		typename T::iterator			myit = x.lower_bound(5);
		typename U::iterator			it = y.lower_bound(5);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("lower_bound(5)", "", myss.str(), ss.str());
	}
	{
		typename T::iterator			myit = x.lower_bound(-2);
		typename U::iterator			it = y.lower_bound(-2);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("lower_bound(-2)", "", myss.str(), ss.str());
	}
	{
		typename T::iterator			myit = x.upper_bound(3);
		typename U::iterator			it = y.upper_bound(3);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("upper_bound(3)", "", myss.str(), ss.str());
	}
	{
		typename T::iterator			myit = x.upper_bound(20);
		typename U::iterator			it = y.upper_bound(20);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << ( myit == x.end() ? "same" : "not same" ) << " | " << x;
		ss << ( it == y.end() ? "same" : "not same" ) << " | " << y;
		print_subsubcontent_compare("upper_bound(20)", " returns end() ", myss.str(), ss.str());
	}
	std::cout << std::endl;
}

template < typename T, typename U >
void	test_map_insert(T x, U y)
{
	std::stringstream	s;
	s << "insert ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	{
		FT_PAIR<typename T::iterator, bool>	mypair = x.insert(FT_MAKE_PAIR(10, std::string("ten")));
		std::pair<typename U::iterator, bool>	pair = y.insert(std::make_pair(10, std::string("ten")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << mypair.first->first << ", " << mypair.first->second << "}, " << mypair.second << " | " << x;
		ss << "{" << pair.first->first << ", " << pair.first->second << "}, " << pair.second << " | " << y;
		print_subsubcontent_compare("insert( {10, ten} )", "", myss.str(), ss.str());
	}
	{
		FT_PAIR<typename T::iterator, bool>	mypair = x.insert(FT_MAKE_PAIR(6, std::string("six")));
		std::pair<typename U::iterator, bool>	pair = y.insert(std::make_pair(6, std::string("six")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << mypair.first->first << ", " << mypair.first->second << "}, " << mypair.second << " | " << x;
		ss << "{" << pair.first->first << ", " << pair.first->second << "}, " << pair.second << " | " << y;
		print_subsubcontent_compare("insert( {6, six} )", "", myss.str(), ss.str());
	}
	{
		FT_PAIR<typename T::iterator, bool>	mypair = x.insert(FT_MAKE_PAIR(-2, std::string("-two")));
		std::pair<typename U::iterator, bool>	pair = y.insert(std::make_pair(-2, std::string("-two")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << mypair.first->first << ", " << mypair.first->second << "}, " << mypair.second << " | " << x;
		ss << "{" << pair.first->first << ", " << pair.first->second << "}, " << pair.second << " | " << y;
		print_subsubcontent_compare("insert( {-2, -two} )", "", myss.str(), ss.str());
	}
	{
		FT_PAIR<typename T::iterator, bool>	mypair = x.insert(FT_MAKE_PAIR(-2, std::string("-two")));
		std::pair<typename U::iterator, bool>	pair = y.insert(std::make_pair(-2, std::string("-two")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << mypair.first->first << ", " << mypair.first->second << "}, " << mypair.second << " | " << x;
		ss << "{" << pair.first->first << ", " << pair.first->second << "}, " << pair.second << " | " << y;
		print_subsubcontent_compare("insert( {-2, -two} ) ", "Duplicates", myss.str(), ss.str());
	}
	{
		typename T::iterator	myit = x.insert(x.lower_bound(9), FT_MAKE_PAIR(15, std::string("fifteen")));
		typename U::iterator	it = y.insert(y.lower_bound(9), std::make_pair(15, std::string("fifteen")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("insert( lower_bound(9), {15, fifteen} )", "", myss.str(), ss.str());
	}
	{
		typename T::iterator	myit = x.insert(x.upper_bound(20), FT_MAKE_PAIR(17, std::string("seventeen")));
		typename U::iterator	it = y.insert(y.upper_bound(20), std::make_pair(17, std::string("seventeen")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("insert( upper_bound(20), {17, seventeen} )", "", myss.str(), ss.str());
	}
	{
		typename T::iterator	myit = x.insert(x.upper_bound(20), FT_MAKE_PAIR(17, std::string("seventeen")));
		typename U::iterator	it = y.insert(y.upper_bound(20), std::make_pair(17, std::string("seventeen")));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << "{" << myit->first << ", " << myit->second << "} | " << x;
		ss << "{" << it->first << ", " << it->second << "} | " << y;
		print_subsubcontent_compare("insert( upper_bound(20), {17, seventeen} ) ", "Duplicates", myss.str(), ss.str());
	}
	T	a;
	U	b;
	a.insert(FT_MAKE_PAIR(-1, std::string("-one")));
	a.insert(FT_MAKE_PAIR(-3, std::string("-three")));
	a.insert(FT_MAKE_PAIR(-5, std::string("-five")));
	b.insert(std::make_pair(-1, std::string("-one")));
	b.insert(std::make_pair(-3, std::string("-three")));
	b.insert(std::make_pair(-5, std::string("-five")));
	{
		x.insert(a.begin(), a.find(-3));
		y.insert(b.begin(), b.find(-3));
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("insert( begin(), find(-5) ) ", "{-5, -five}, {-3, -three}, {-1, -one}", myss.str(), ss.str());
	}
	{
		x.insert(a.find(-3), a.end());
		y.insert(b.find(-3), b.end());
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("insert( find(-3), end()) ", "{-5, -five}, {-3, -three}, {-1, -one}", myss.str(), ss.str());
	}
	std::cout << std::endl;
}

template < typename T, typename U >
void	test_map_erase(T x, U y)
{
	std::stringstream	s;
	s << "erase ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.erase(2);
		y.erase(2);
		myss << x;
		ss << y;
		print_subsubcontent_compare("erase(2)", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.erase(3);
		y.erase(3);
		myss << x;
		ss << y;
		print_subsubcontent_compare("erase(3)", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.erase(x.begin()->first);
		y.erase(y.begin()->first);
		myss << x;
		ss << y;
		print_subsubcontent_compare("erase(begin()->first)", "", myss.str(), ss.str());
	}
	{
		std::stringstream	myss;
		std::stringstream	ss;
		x.erase((--x.end())->first);
		y.erase((--y.end())->first);
		myss << x;
		ss << y;
		print_subsubcontent_compare("erase((--end())->first)", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_map_swap(T x, U y)
{
	std::stringstream	s;
	s << "swap ";
	s << x;
	print_content_header("Member Functions: ", s.str());

	T	a;
	U	b;
	a.insert(FT_MAKE_PAIR(-1, std::string("-one")));
	a.insert(FT_MAKE_PAIR(-3, std::string("-three")));
	a.insert(FT_MAKE_PAIR(-5, std::string("-five")));
	b.insert(std::make_pair(-1, std::string("-one")));
	b.insert(std::make_pair(-3, std::string("-three")));
	b.insert(std::make_pair(-5, std::string("-five")));
	{
		{
			std::stringstream	myss;
			std::stringstream	ss;
			myss << x << " | " << a;
			ss << y << " | " << b;
			print_subsubcontent_compare("swap() ", "before", myss.str(), ss.str());
		}
		x.swap(a);
		y.swap(b);
		{
			std::stringstream	myss;
			std::stringstream	ss;
			myss << x << " | " << a;
			ss << y << " | " << b;
			print_subsubcontent_compare("swap() ", "after", myss.str(), ss.str());
		}
	}
	{
		{
			std::stringstream	myss;
			std::stringstream	ss;
			myss << x << " | " << a;
			ss << y << " | " << b;
			print_subsubcontent_compare("swap() ", "before", myss.str(), ss.str());
		}
		x.swap(a);
		y.swap(b);
		{
			std::stringstream	myss;
			std::stringstream	ss;
			myss << x << " | " << a;
			ss << y << " | " << b;
			print_subsubcontent_compare("swap() ", "after", myss.str(), ss.str());
		}
	}
}

template < typename T, typename U >
void	test_map_element_access(T x, U y)
{
	std::stringstream	s;
	s << "at ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	print_subsubcontent_compare("at(1)", "", x.at(1), y.at(1));
	try { x.at(6); } catch (const std::out_of_range& e) { print_subsubcontent(MY, e.what()); }
	try { y.at(6); } catch (const std::out_of_range& e) { print_subsubcontent(EXPECTED, e.what()); }
	print_subsubcontent_compare("operator[3]", "", x[3], y[3]);
	print_subsubcontent_compare("operator[8]", "", x[8], y[8]);
	{
		x[11] = "eleven";
		y[11] = "eleven";
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("operator[11] = eleven", "", myss.str(), ss.str());
	}
	{
		x[7] = "sevenseven";
		y[7] = "sevenseven";
		std::stringstream	myss;
		std::stringstream	ss;
		myss << x;
		ss << y;
		print_subsubcontent_compare("operator[7] = sevenseven", "", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_map_lexicographical(T x, U y)
{
	T	a;
	U	b;
	a.insert(FT_MAKE_PAIR(-1, std::string("-one")));
	a.insert(FT_MAKE_PAIR(-3, std::string("-three")));
	a.insert(FT_MAKE_PAIR(-5, std::string("-five")));
	b.insert(std::make_pair(-1, std::string("-one")));
	b.insert(std::make_pair(-3, std::string("-three")));
	b.insert(std::make_pair(-5, std::string("-five")));
	{
		std::stringstream	myss;
		myss <<  x << " == " << a;
		print_subsubcontent_compare(myss.str(), "", x == a, y == b);
	}
	{
		std::stringstream	myss;
		myss <<  x << " != " << a;
		print_subsubcontent_compare(myss.str(), "", x != a, y != b);
	}
	{
		std::stringstream	myss;
		myss <<  x << " < " << a;
		print_subsubcontent_compare(myss.str(), "", x < a, y < b);
	}
	{
		std::stringstream	myss;
		myss <<  x << " <= " << a;
		print_subsubcontent_compare(myss.str(), "", x <= a, y <= b);
	}
	{
		std::stringstream	myss;
		myss <<  x << " > " << a;
		print_subsubcontent_compare(myss.str(), "", x > a, y > b);
	}
	{
		std::stringstream	myss;
		myss <<  x << " == " << a;
		print_subsubcontent_compare(myss.str(), "", x >= a, y >= b);
	}
}

template < typename T, typename U >
void	test_map_iterator(T x, U y)
{
	typename T::iterator			myit;
	typename T::iterator			myit2;
	typename U::iterator			it;
	typename U::iterator			it2;

	std::stringstream	s;
	s << "iterator ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	myit = x.begin();
	it = y.begin();
	myit2 = ++myit;
	it2 = ++it;
	print_subsubcontent_compare("++begin() == ++begin()", "", myit == myit2, it == it2);
	{
		myit = x.begin();
		it = y.begin();
		std::stringstream	myss;
		std::stringstream	ss;
		myss << *myit;
		ss << *it;
		print_subsubcontent_compare("begin()", "", myss.str(), ss.str());
	}
	{
		myit = x.begin();
		it = y.begin();
		std::stringstream	myss;
		std::stringstream	ss;
		for (size_t i = 0; myit != x.end(); i++, myit++)
			myss << " {" << myit->first << ", " << myit->second << (i + 1 == x.size() ? "} " : "}, ");
		for (size_t i = 0; it != y.end(); i++, it++)
			ss << " {" << it->first << ", " << it->second << (i + 1 == y.size() ? "} " : "}, ");
		print_subsubcontent_compare("begin()++ to end()", "", myss.str(), ss.str());
	}
	{
		myit = x.find(4);
		it = y.find(4);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << (*myit).first << ", " << (*myit).second;
		ss << (*it).first << ", " << (*it).second;
		print_subsubcontent_compare("operator*", " *(find(4)).first, *(find(4)).second", myss.str(), ss.str());
	}
	{
		myit = x.find(3);
		it = y.find(3);
		std::stringstream	myss;
		std::stringstream	ss;
		myss << myit->first << ", " << myit->second;
		ss << it->first << ", " << it->second;
		print_subsubcontent_compare("operator->", " find(3)->first, find(3)->second", myss.str(), ss.str());
	}
	{
		myit = x.find(9);
		it = y.find(9);
		std::stringstream	myss;
		std::stringstream	ss;
		--myit;
		--it;
		myss << myit->first << ", " << myit->second;
		ss << it->first << ", " << it->second;
		print_subsubcontent_compare("--operator", " (--find(9))->first, (--find(9))->second", myss.str(), ss.str());
	}
}

template < typename T, typename U >
void	test_map_reverse_iterator(T x, U y)
{
	typename T::reverse_iterator	myrit;
	typename T::reverse_iterator	myrit2;
	typename U::reverse_iterator	rit;
	typename U::reverse_iterator	rit2;

	std::stringstream	s;
	s << "reverse iterator ";
	s << x;
	print_content_header("Member Functions: ", s.str());
	myrit = x.rbegin();
	rit = y.rbegin();
	myrit2 = ++myrit;
	rit2 = ++rit;
	print_subsubcontent_compare("++rbegin() == ++rbegin()", "", myrit == myrit2, rit == rit2);
	{
		myrit = x.rbegin();
		rit = y.rbegin();
		std::stringstream	myss;
		std::stringstream	ss;
		myss << *myrit;
		ss << *rit;
		print_subsubcontent_compare("rbegin()", "", myss.str(), ss.str());
	}
	{
		myrit = x.rbegin();
		rit = y.rbegin();
		std::stringstream	myss;
		std::stringstream	ss;
		for (size_t i = 0; myrit != x.rend(); i++, myrit++)
			myss << " {" << myrit->first << ", " << myrit->second << (i + 1 == x.size() ? "} " : "}, ");
		for (size_t i = 0; rit != y.rend(); i++, rit++)
			ss << " {" << rit->first << ", " << rit->second << (i + 1 == y.size() ? "} " : "}, ");
		print_subsubcontent_compare("rbegin()++ to rend()", "", myss.str(), ss.str());
	}
	{
		myrit = x.rend();
		rit = y.rend();
		myrit--;
		rit--;
		std::stringstream	myss;
		std::stringstream	ss;
		myss << *myrit;
		ss << *rit;
		print_subsubcontent_compare("rend()--", "", myss.str(), ss.str());
	}
	{
		myrit = x.rend();
		rit = y.rend();
		myrit--;
		rit--;
		std::stringstream	myss;
		std::stringstream	ss;
		for (size_t i = 0; myrit != x.rbegin(); i++, myrit--)
			myss << " {" << myrit->first << ", " << myrit->second << (i + 1 == x.size() ? "} " : "}, ");
		for (size_t i = 0; rit != y.rbegin(); i++, rit--)
			ss << " {" << rit->first << ", " << rit->second << (i + 1 == y.size() ? "} " : "}, ");
		print_subsubcontent_compare("rend()--; -- to rbegin()", "", myss.str(), ss.str());
	}
}
