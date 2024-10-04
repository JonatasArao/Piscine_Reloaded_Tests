/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:37:12 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 15:30:56 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_iterative_factorial(int nb);

MU_TEST(test_ft_iterative_zero_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_iterative_factorial(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_one_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_iterative_factorial(1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_minus_one_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_iterative_factorial(-1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_five_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 120;
	actual_result = ft_iterative_factorial(5);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_minus_five_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_iterative_factorial(-5);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_twelve_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 479001600;
	actual_result = ft_iterative_factorial(12);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_thirteen_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_iterative_factorial(13);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_min_int_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_iterative_factorial(-2147483648);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_iterative_max_int_factorial)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_iterative_factorial(2147483647);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_iterative_factorial_test_suite)
{
	MU_RUN_TEST(test_ft_iterative_zero_factorial);
	MU_RUN_TEST(test_ft_iterative_one_factorial);
	MU_RUN_TEST(test_ft_iterative_minus_one_factorial);
	MU_RUN_TEST(test_ft_iterative_five_factorial);
	MU_RUN_TEST(test_ft_iterative_minus_five_factorial);
	MU_RUN_TEST(test_ft_iterative_twelve_factorial);
	MU_RUN_TEST(test_ft_iterative_thirteen_factorial);
	MU_RUN_TEST(test_ft_iterative_min_int_factorial);
	MU_RUN_TEST(test_ft_iterative_max_int_factorial);
}

int	main(void) {
	MU_RUN_SUITE(ft_iterative_factorial_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
