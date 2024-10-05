/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex17.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:39:01 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/05 16:34:13 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int	ft_strcmp(char *s1, char *s2);

MU_TEST(test_ft_strcmp_s1_a_s2_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strcmp("a", "a");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_A_s2_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'A' - 'a';
	actual_result = ft_strcmp("A", "a");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_empty_s2_a)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - 'a';
	actual_result = ft_strcmp("", "a");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_a_s2_empty)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a' - '\0';
	actual_result = ft_strcmp("a", "");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 0;
	actual_result = ft_strcmp("abc", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abcdef_s2_abcDEF)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'd' - 'D';
	actual_result = ft_strcmp("abcdef", "abcDEF");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abcDEF_s2_abcdef)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'D' - 'd';
	actual_result = ft_strcmp("abcDEF", "abcdef");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abcdef)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - 'd';
	actual_result = ft_strcmp("abc", "abcdef");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abcdef_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'd' - '\0';
	actual_result = ft_strcmp("abcdef", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_newline_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\n' - '\0';
	actual_result = ft_strcmp("abc\n", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abc_newline)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - '\n';
	actual_result = ft_strcmp("abc", "abc\n");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_tab_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\t' - '\0';
	actual_result = ft_strcmp("abc\t", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abc_tab)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - '\t';
	actual_result = ft_strcmp("abc", "abc\t");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_space_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = ' ' - '\0';
	actual_result = ft_strcmp("abc ", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abc_space)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - ' ';
	actual_result = ft_strcmp("abc", "abc ");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_space_abc_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = ' ' - 'a';
	actual_result = ft_strcmp(" abc", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_space_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = 'a' - ' ';
	actual_result = ft_strcmp("abc", " abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_nonprintable_s2_abc)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\x01' - '\0';
	actual_result = ft_strcmp("abc\x01", "abc");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_strcmp_s1_abc_s2_abc_nonprintable)
{
	// ARRANGE
	int	expected_result;
	int	actual_result;

	// ACT
	expected_result = '\0' - '\x01';
	actual_result = ft_strcmp("abc", "abc\x01");

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strcmp_test_suite)
{
	MU_RUN_TEST(test_ft_strcmp_s1_a_s2_a);
	MU_RUN_TEST(test_ft_strcmp_s1_A_s2_a);
	MU_RUN_TEST(test_ft_strcmp_s1_empty_s2_a);
	MU_RUN_TEST(test_ft_strcmp_s1_a_s2_empty);
	MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abc);
	MU_RUN_TEST(test_ft_strcmp_s1_abcdef_s2_abcDEF);
	MU_RUN_TEST(test_ft_strcmp_s1_abcDEF_s2_abcdef);
	MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abcdef);
	MU_RUN_TEST(test_ft_strcmp_s1_abcdef_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_newline_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abc_newline);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_tab_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abc_tab);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_space_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abc_space);
    MU_RUN_TEST(test_ft_strcmp_s1_space_abc_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_space_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_nonprintable_s2_abc);
    MU_RUN_TEST(test_ft_strcmp_s1_abc_s2_abc_nonprintable);
}

int	main(void) {
	MU_RUN_SUITE(ft_strcmp_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
