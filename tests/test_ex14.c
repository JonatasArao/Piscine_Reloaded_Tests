/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:25:01 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:14 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_sqrt(int nb);

MU_TEST(test_zero_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_one_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 1;
	actual_result = ft_sqrt(1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_minus_one_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(-1);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_nine_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 3;
	actual_result = ft_sqrt(9);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_minus_nine_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(-3);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_max_possible_int_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 46340;
	actual_result = ft_sqrt(2147395600);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_fifty_thousand_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(50000);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_min_int_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(-2147483648);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_max_int_sqrt)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_sqrt(2147483647);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_sqrt_test_suite)
{
	MU_RUN_TEST(test_zero_sqrt);
	MU_RUN_TEST(test_one_sqrt);
	MU_RUN_TEST(test_minus_one_sqrt);
	MU_RUN_TEST(test_nine_sqrt);
	MU_RUN_TEST(test_minus_nine_sqrt);
	MU_RUN_TEST(test_max_possible_int_sqrt);
	MU_RUN_TEST(test_fifty_thousand_sqrt);
	MU_RUN_TEST(test_min_int_sqrt);
	MU_RUN_TEST(test_max_int_sqrt);
}

int	main(void) {
	MU_RUN_SUITE(ft_sqrt_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
