/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:10:18 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/05 15:25:07 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_strlen(char *str);

MU_TEST(test_ft_strlen_empty_str)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strlen("");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_undercase_alphabet)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 26;
	actual_result = ft_strlen("abcdefghijklmnopqrstuvwxyz");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_uppercase_alphabet)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 26;
	actual_result = ft_strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_numbers)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 10;
	actual_result = ft_strlen("0123456789");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_special)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 33;
	actual_result = ft_strlen(" !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_unprintable)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 7;
	actual_result = ft_strlen("\a\b\f\n\r\t\v");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_spaces)
{
    // ARRANGE
    int expected_result;
    int actual_result;

    // ACT
    expected_result = 3;
    actual_result = ft_strlen("   ");

    // ASSERT
    mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_multibyte)
{
    // ARRANGE
    int expected_result;
    int actual_result;

    // ACT
	expected_result = 18;
	actual_result = ft_strlen("仮面ライダー");

    // ASSERT
    mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strlen_long_str)
{
    // ARRANGE
    int expected_result;
    int actual_result;

    // ACT
    expected_result = 63;
    actual_result = ft_strlen("a very very very very very very very very very very long string");

    // ASSERT
    mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strlen_test_suite)
{
	MU_RUN_TEST(test_ft_strlen_empty_str);
	MU_RUN_TEST(test_ft_strlen_undercase_alphabet);
	MU_RUN_TEST(test_ft_strlen_uppercase_alphabet);
	MU_RUN_TEST(test_ft_strlen_numbers);
	MU_RUN_TEST(test_ft_strlen_special);
	MU_RUN_TEST(test_ft_strlen_unprintable);
    MU_RUN_TEST(test_ft_strlen_spaces);
    MU_RUN_TEST(test_ft_strlen_multibyte);
    MU_RUN_TEST(test_ft_strlen_long_str);
}

int	main(void) {
	MU_RUN_SUITE(ft_strlen_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
