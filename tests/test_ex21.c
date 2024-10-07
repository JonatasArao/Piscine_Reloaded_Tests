/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex21.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:50:06 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 11:26:28 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minunit.h"

int	*ft_range(int min, int max);

MU_TEST(test_ft_range_zero_to_three)
{
	// ARRANGE
	int	expected_result[3];
	int	*actual_result;
	int i;

	// ACT
	i = 0;
	while (i < 3)
	{
		expected_result[i] = i;
		i++;
	}
	actual_result = ft_range(0, 3);

	// ASSERT
	i = 0;
	while (i < 3)
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
		i++;
	}

	// CLEANUP
	free(actual_result);
}


MU_TEST(test_ft_range_minus_three_to_three)
{
	// ARRANGE
	int	expected_result[6];
	int	*actual_result;
	int i;

	// ACT
	i = 0;
	while (i < 6)
	{
		expected_result[i] = -3 + i;
		i++;
	}
	actual_result = ft_range(-3, 3);

	// ASSERT
	i = 0;
	while (i < 6)
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
		i++;
	}

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_range_one_to_five)
{
	// ARRANGE
	int	expected_result[4] = {1, 2, 3, 4};
	int	*actual_result;
	int i;

	// ACT
	actual_result = ft_range(1, 5);

	// ASSERT
	for (i = 0; i < 4; i++)
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_range__minus_five_to_minus_one)
{
	// ARRANGE
	int	expected_result[4] = {-5, -4, -3, -2};
	int	*actual_result;
	int i;

	// ACT
	actual_result = ft_range(-5, -1);

	// ASSERT
	for (i = 0; i < 4; i++)
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_range_two_to_two)
{
	// ARRANGE
	int	*actual_result;

	// ACT
	actual_result = ft_range(2, 2);

	// ASSERT
	mu_assert(actual_result == NULL, "Expected NULL for empty range");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_range_five_to_one)
{
	// ARRANGE
	int	*actual_result;

	// ACT
	actual_result = ft_range(5, 1);

	// ASSERT
	mu_assert(actual_result == NULL, "Expected NULL for reverse range");

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_range_one_to_one_thousand)
{
	// ARRANGE
	int	expected_result[1000];
	int	*actual_result;
	int i;

	// ACT
	for (i = 0; i < 1000; i++)
	{
		expected_result[i] = i;
	}
	actual_result = ft_range(0, 1000);

	// ASSERT
	for (i = 0; i < 1000; i++)
	{
		mu_assert_int_eq(expected_result[i], actual_result[i]);
	}

	// CLEANUP
	free(actual_result);
}

MU_TEST_SUITE(ft_range_test_suite)
{
	MU_RUN_TEST(test_ft_range_zero_to_three);
	MU_RUN_TEST(test_ft_range_minus_three_to_three);
	MU_RUN_TEST(test_ft_range_one_to_five);
	MU_RUN_TEST(test_ft_range__minus_five_to_minus_one);
	MU_RUN_TEST(test_ft_range_two_to_two);
	MU_RUN_TEST(test_ft_range_five_to_one);
	MU_RUN_TEST(test_ft_range_one_to_one_thousand);
}

int	main(void) {
	MU_RUN_SUITE(ft_range_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
