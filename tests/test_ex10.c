/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:29:44 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 12:07:34 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

void	ft_swap(int *a, int *b);

MU_TEST(test_ft_swap_a_to_b)
{
	// ARRANGE
	int	expected_result_a;
	int	actual_result_a;
	int	actual_result_b;

	// ACT
	actual_result_a = 24;
	actual_result_b = 42;
	expected_result_a = 42;
	ft_swap(&actual_result_a, &actual_result_b);

	// ASSERT
	mu_assert_int_eq(expected_result_a, actual_result_a);
}

MU_TEST(test_ft_swap_b_to_a)
{
	// ARRANGE
	int	expected_result_b;
	int	actual_result_a;
	int	actual_result_b;

	// ACT
	actual_result_a = 24;
	actual_result_b = 42;
	expected_result_b = 24;
	ft_swap(&actual_result_a, &actual_result_b);

	// ASSERT
	mu_assert_int_eq(expected_result_b, actual_result_b);
}

MU_TEST_SUITE(ft_swap_test_suite)
{
	MU_RUN_TEST(test_ft_swap_a_to_b);
	MU_RUN_TEST(test_ft_swap_b_to_a);
}

int	main(void) {
	MU_RUN_SUITE(ft_swap_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
