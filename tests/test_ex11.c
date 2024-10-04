/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:18:25 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 14:28:08 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

void	ft_div_mod(int a, int b, int *div, int *mod);

MU_TEST(test_ft_div_mod_ten_divided_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = 10 / 3;
	ft_div_mod(10, 3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_ten_module_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	div;

	// ACT
	expected_result = 10 % 3;
	ft_div_mod(10, 3, &div, &actual_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_ten_divided_minus_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = 10 / 3;
	ft_div_mod(10, 3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_ten_module_minus_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	div;

	// ACT
	expected_result = 10 % 3;
	ft_div_mod(10, 3, &div, &actual_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_minus_ten_divided_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = -10 / 3;
	ft_div_mod(-10, 3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_minus_ten_module_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	div;

	// ACT
	expected_result = -10 % 3;
	ft_div_mod(-10, 3, &div, &actual_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_minus_ten_divided_minus_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = -10 / 3;
	ft_div_mod(-10, 3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_minus_ten_module_minus_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	div;

	// ACT
	expected_result = -10 % 3;
	ft_div_mod(-10, 3, &div, &actual_result);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_zero_divided_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = 0 / 3;
	ft_div_mod(0, 3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_div_mod_zero_divided_minus_three)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;
	int	mod;

	// ACT
	expected_result = 0 / -3;
	ft_div_mod(0, -3, &actual_result, &mod);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_div_mod_test_suite)
{
	MU_RUN_TEST(test_ft_div_mod_ten_divided_three);
	MU_RUN_TEST(test_ft_div_mod_ten_module_three);
	MU_RUN_TEST(test_ft_div_mod_ten_divided_minus_three);
	MU_RUN_TEST(test_ft_div_mod_ten_module_minus_three);
	MU_RUN_TEST(test_ft_div_mod_minus_ten_divided_three);
	MU_RUN_TEST(test_ft_div_mod_minus_ten_module_three);
	MU_RUN_TEST(test_ft_div_mod_minus_ten_divided_minus_three);
	MU_RUN_TEST(test_ft_div_mod_minus_ten_module_minus_three);
	MU_RUN_TEST(test_ft_div_mod_zero_divided_three);
	MU_RUN_TEST(test_ft_div_mod_zero_divided_minus_three);
}

int	main(void) {
	MU_RUN_SUITE(ft_div_mod_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
