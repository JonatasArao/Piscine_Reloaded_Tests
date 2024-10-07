/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex22.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:02:17 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 12:28:53 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "ft_abs.h"

MU_TEST(test_ft_abs_forty_two)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 42;
	actual_result = ABS(42);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_abs_minus_forty_two)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 42;
	actual_result = ABS(-42);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_abs_zero)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ABS(0);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_abs_test_suite)
{
	MU_RUN_TEST(test_ft_abs_forty_two);
	MU_RUN_TEST(test_ft_abs_minus_forty_two);
	MU_RUN_TEST(test_ft_abs_zero);
}

int	main(void) {
	MU_RUN_SUITE(ft_abs_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
