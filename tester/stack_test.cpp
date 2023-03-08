/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:08 by steh              #+#    #+#             */
/*   Updated: 2023/03/08 19:05:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <cassert>
#include <iomanip> 
// #include "../header/stack.hpp"
// #include "../header/stack.tpp"
// #include "../header/vector.tpp"
#include "../header/utils/test.hpp"
#include <ctime> // for clock
#include <deque>
#include <list>


int	main()
{
	{
		ft::print_headers("Constructor");
		ft::stack<int> s;
		std::stack<int> ss;
		ft::stack_check(s, ss);
	}

	{
		ft::print_headers("Copy Constructor");
		ft::stack<int> s;
		s.push(1);
		s.push(12);
		s.push(42);
		ft::stack<int> s2(s);

		std::stack<int> ss;
		ss.push(1);
		ss.push(12);
		ss.push(42);
		std::stack<int> ss2(ss);
		ft::stack_check(s2, ss2);
	}

	{
		ft::print_headers("Operator=");
		ft::stack<int> s;
		s.push(1);
		s.push(12);
		s.push(42);
		ft::stack<int> s2;
		s2 = s;
		ft::print_stack(s2);

		std::stack<int> ss;
		ss.push(1);
		ss.push(12);
		ss.push(42);
		std::stack<int> ss2;
		ss2 = ss;
		ft::print_stack(ss2);
		ft::stack_check(s2, ss2);
	}

	{
		ft::print_headers("Top");

		// Test non_const top()
		ft::stack<int> s;
		std::stack<int> ss;
		int	my_top, std_top;
		s.push(1);
		s.push(12);
		s.push(42);
		ss.push(1);
		ss.push(12);
		ss.push(42);
		my_top = s.top();
		std_top = ss.top();
		ft::test_assert(my_top, std_top, "Top incorrect", "Top Passed");

		// Test const top()
		const ft::stack<int> ft_s = s;
		const std::stack<int> std_s = ss;
		ft::test_assert(ft_s.top(), std_s.top(), "Const Top incorrect", "Const Top Passed");
	}

	{
		ft::print_headers("Empty");

		// Test empty stack()
		ft::stack<int> s;
		std::stack<int> ss;
		ft::test_assert(s.empty(), bool(1), "Empty incorrect", "Empty Passed");
		ft::test_assert(ss.empty(), bool(1), "Empty incorrect", "Empty Passed");

		// Test non-empty stack()
		s.push(1);
		ss.push(1);
		std::cout<<"empty"<<ss.empty()<<std::endl;
		ft::test_assert(s.empty(), bool(0), "Empty incorrect", "Empty Passed");
		ft::test_assert(ss.empty(), bool(0), "Empty incorrect", "Empty Passed");
	}

	{
		ft::print_headers("Size");

		// Test empty stack()
		ft::stack<int> s;
		std::stack<int> ss;
		ft::test_assert(s.size(), ss.size(), "Size incorrect", "Empty Passed");

		s.push(1);
		ss.push(1);
		ft::test_assert(s.size(), ss.size(), "Size incorrect", "Empty Passed");

		s.pop();
		ss.pop();
		ft::test_assert(s.size(), ss.size(), "Size incorrect", "Empty Passed");
	}

	{
		ft::print_headers("Push");

		// Test int stack
		ft::stack<int> s;
		std::stack<int> ss;

		s.push(1);
		ss.push(1);
		s.push(-11);
		ss.push(-11);
		s.push(0);
		ss.push(0);
		ft::stack_check(s, ss);

		// Test char stack
		ft::stack<char> s2;
		std::stack<char> ss2;

		s2.push('c');
		ss2.push('c');
		s2.push('b');
		ss2.push('b');
		s2.push('a');
		ss2.push('a');
		ft::stack_check(s2, ss2);
	}

	{
		ft::print_headers("Pop");

		// Test int stack
		ft::stack<int> s;
		std::stack<int> ss;

		s.push(1);
		s.push(-11);
		s.pop();
		ss.push(1);
		ss.push(-11);
		ss.pop();
		ft::stack_check(s, ss);

		// Test char stack
		ft::stack<char> s2;
		std::stack<char> ss2;
		s2.push('c');
		s2.push('b');
		s2.push('a');
		s2.pop();
		ss2.push('c');
		ss2.push('b');
		ss2.push('a');
		ss2.pop();
		ft::stack_check(s2, ss2);
	}

	{
		ft::print_headers("non-member function");

		int	my_val, std_val;

		ft::stack<int> s;
		ft::stack<int> s2;

		std::stack<int> ss;
		std::stack<int> ss2;

		s.push(1);
		s2.push(1);
		s2.push(2);

		ss.push(1);
		ss2.push(2);
		ss2.push(2);

		my_val = (s == s2);
		std_val = (ss == ss2);
		ft::test_assert(my_val, std_val, "Equal incorrect", "Equal Passed");
		my_val = (s != s2);
		std_val = (ss != ss2);
		ft::test_assert(my_val, std_val, "Not Equal incorrect", "Not Equal Passed");
		my_val = (s < s2);
		std_val = (ss < ss2);
		ft::test_assert(my_val, std_val, "Less than incorrect", "Less than Passed");
		my_val = (s <= s2);
		std_val = (ss <= ss2);
		ft::test_assert(my_val, std_val, "Less than equal incorrect", "Less than equal Passed");
		my_val = (s > s2);
		std_val = (ss > ss2);
		ft::test_assert(my_val, std_val, "More than incorrect", "More than Passed");
		my_val = (s >= s2);
		std_val = (ss >= ss2);
		ft::test_assert(my_val, std_val, "More than equal incorrect", "More than equal Passed");
	}

	{
		ft::print_headers("Testing");

		ft::stack<int, std::deque<int> > s;
		ft::stack<int, std::list<int> > s2;
		std::stack<int, std::deque<int> > ss;
		std::stack<int, std::list<int> > ss2;
		
		s.push(1);
		ss.push(1);
		s2.push(2);
		ss2.push(2);
		assert(s.top() == ss.top());
		assert(s2.top() == ss2.top());

	}

	{
		ft::print_headers("Check Time Performance");

		clock_t	start_time, end_time;
		double	ft_vec_time, std_vec_time;
		bool	rv;

		start_time = clock();

		ft::stack<int>						s;
		ft::stack<int>						s2(s);
		ft::stack<int>						s3 = s2;
		ft::stack<int, ft::vector<int> >	s4;

		s.push(42);
		s.top();
		s.empty();
		s.size();
		s.pop();
		rv = (s == s2);
		rv = (s != s2);
		rv = (s < s2);
		rv = (s <= s2);
		rv = (s > s2);
		rv = (s >= s2);
		ft::swap(s, s2);

		end_time = clock();
		ft_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "ft_vec_time: " << ft_vec_time << std::endl;

		start_time = clock();

		std::stack<int>						ss;
		std::stack<int>						ss2(ss);
		std::stack<int>						ss3 = ss2;
		std::stack<int, std::vector<int> >	ss4;

		ss.push(42);
		ss.top();
		ss.empty();
		ss.size();
		ss.pop();
		rv = (ss == ss2);
		rv = (ss != ss2);
		rv = (ss < ss2);
		rv = (ss <= ss2);
		rv = (ss > ss2);
		rv = (ss >= ss2);
		std::swap(ss, ss2);

		end_time = clock();
		std_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "std_vec_time: " << std_vec_time << std::endl;
		std::cout << "Performance ratio of ft container compared to std container is: " << ft_vec_time / std_vec_time << " times\n" << std::endl;
	}
	// system("leaks ft_container");

	return (0);
}
