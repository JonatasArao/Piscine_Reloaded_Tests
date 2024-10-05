/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex19.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:40:32 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/05 18:30:28 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

int	program_main(int argc, char **argv);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void capture_ft_sort_params_output(int (*func)(int, char**), int argc, char **argv, char* buffer, size_t size) {
	int pipefd[2];
	ssize_t count;

	// Cria um pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Salva o descritor de arquivo original da saída padrão
	int stdout_backup = dup(STDOUT_FILENO);

	// Redireciona a saída padrão para o pipe
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	// Chama a função cuja saída queremos capturar
	func(argc, argv);

	// Restaura a saída padrão
	fflush(stdout);
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);

	// Lê o conteúdo do pipe
	count = read(pipefd[0], buffer, size - 1);
	if (count == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[count] = '\0';
}

MU_TEST(test_ft_sort_params_empty_params)
{
	// ARRANGE
	char	expected_result[18];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 1;
	argv = (char *[]){"./a.out"};
	strcpy(expected_result, "");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_one_params)
{
	// ARRANGE
	char	expected_result[7];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 2;
	argv = (char *[]){"./a.out", "test1"};
	strcpy(expected_result, "test1\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_two_in_order_params)
{
	// ARRANGE
	char	expected_result[13];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "test1", "test2"};
	strcpy(expected_result, "test1\ntest2\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_two_out_order_params)
{
	// ARRANGE
	char	expected_result[13];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "test2", "test1"};
	strcpy(expected_result, "test1\ntest2\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_three_in_order_params)
{
	// ARRANGE
	char	expected_result[19];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 4;
	argv = (char *[]){"./a.out", "test1", "test2", "test3"};
	strcpy(expected_result, "test1\ntest2\ntest3\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_three_out_order_params)
{
	// ARRANGE
	char	expected_result[19];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 4;
	argv = (char *[]){"./a.out", "test2", "test3", "test1"};
	strcpy(expected_result, "test1\ntest2\ntest3\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_undercase_uppercase_params)
{
	// ARRANGE
	char	expected_result[11];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "test", "TEST"};
	strcpy(expected_result, "TEST\ntest\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_uppercase_undercase_params)
{
	// ARRANGE
	char	expected_result[11];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "test", "TEST"};
	strcpy(expected_result, "TEST\ntest\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}
MU_TEST(test_ft_sort_params_mixed_case_params)
{
	// ARRANGE
	char	expected_result[19];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 4;
	argv = (char *[]){"./a.out", "Test", "test", "TEST"};
	strcpy(expected_result, "TEST\nTest\ntest\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_numeric_params)
{
	// ARRANGE
	char	expected_result[13];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "123", "45"};
	strcpy(expected_result, "123\n45\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_special_characters)
{
	// ARRANGE
	char	expected_result[19];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 4;
	argv = (char *[]){"./a.out", "!test", "@test", "#test"};
	strcpy(expected_result, "!test\n#test\n@test\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_mixed_alphanumeric)
{
	// ARRANGE
	char	expected_result[19];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 4;
	argv = (char *[]){"./a.out", "test1", "test2", "test10"};
	strcpy(expected_result, "test1\ntest10\ntest2\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_long_strings)
{
	// ARRANGE
	char	expected_result[37];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "thisisaverylongstring", "anotherlongstring"};
	strcpy(expected_result, "anotherlongstring\nthisisaverylongstring\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_empty_string)
{
	// ARRANGE
	char	expected_result[37];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "", "nonempty"};
	strcpy(expected_result, "\nnonempty\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_duplicate_strings)
{
	// ARRANGE
	char	expected_result[37];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "duplicate", "duplicate"};
	strcpy(expected_result, "duplicate\nduplicate\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_sort_params_varied_lengths)
{
	// ARRANGE
	char	expected_result[37];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "short", "averyverylongstring"};
	strcpy(expected_result, "averyverylongstring\nshort\n");
	capture_ft_sort_params_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_sort_params_test_suite)
{
	MU_RUN_TEST(test_ft_sort_params_empty_params);
	MU_RUN_TEST(test_ft_sort_params_one_params);
	MU_RUN_TEST(test_ft_sort_params_two_in_order_params);
	MU_RUN_TEST(test_ft_sort_params_two_out_order_params);
	MU_RUN_TEST(test_ft_sort_params_three_in_order_params);
	MU_RUN_TEST(test_ft_sort_params_three_out_order_params);
	MU_RUN_TEST(test_ft_sort_params_undercase_uppercase_params);
	MU_RUN_TEST(test_ft_sort_params_uppercase_undercase_params);
	MU_RUN_TEST(test_ft_sort_params_mixed_case_params);
	MU_RUN_TEST(test_ft_sort_params_numeric_params);
	MU_RUN_TEST(test_ft_sort_params_special_characters);
	MU_RUN_TEST(test_ft_sort_params_mixed_alphanumeric);
	MU_RUN_TEST(test_ft_sort_params_long_strings);
	MU_RUN_TEST(test_ft_sort_params_empty_string);
	MU_RUN_TEST(test_ft_sort_params_duplicate_strings);
	MU_RUN_TEST(test_ft_sort_params_varied_lengths);
}

int	main(void) {
    MU_RUN_SUITE(ft_sort_params_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
