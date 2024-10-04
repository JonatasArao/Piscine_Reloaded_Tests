/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex09.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:15:38 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 11:30:33 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

void	ft_ft(int *nbr);

MU_TEST(test_ft_ft_42)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 42;
	ft_ft(&actual_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_ft_test_suite)
{
	MU_RUN_TEST(test_ft_ft_42);
}

int	main(void) {
	MU_RUN_SUITE(ft_ft_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
