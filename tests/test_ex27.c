/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex27.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:00:29 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/08 16:13:18 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

int	program_main(int argc, char **argv);

void capture_ft_display_file_output(int (*func)(int, char**), int argc, char **argv, char* buffer, size_t size) {
	int pipefd[2];
	ssize_t count;

	// Cria um pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Salva os descritores de arquivo originais da saída padrão e erro padrão
	int stdout_backup = dup(STDOUT_FILENO);
	int stderr_backup = dup(STDERR_FILENO);

	// Redireciona a saída padrão e erro padrão para o pipe
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(pipefd[1], STDERR_FILENO);
	close(pipefd[1]);

	// Chama a função cuja saída queremos capturar
	func(argc, argv);

	// Restaura a saída padrão e erro padrão
	fflush(stdout);
	fflush(stderr);
	dup2(stdout_backup, STDOUT_FILENO);
	dup2(stderr_backup, STDERR_FILENO);
	close(stdout_backup);
	close(stderr_backup);

	// Lê o conteúdo do pipe
	count = read(pipefd[0], buffer, size - 1);
	if (count == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[count] = '\0';

	// Fecha o descritor de leitura do pipe
	close(pipefd[0]);
}

MU_TEST(test_ft_display_file_empty_params)
{
	// ARRANGE
	char	expected_result[20];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 1;
	argv = (char *[]){"./a.out"};
	strcpy(expected_result, "File name missing.\n");
	capture_ft_display_file_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_display_file_more_than_one_params)
{
	// ARRANGE
	char	expected_result[21];
	char	actual_result[256];
	int		argc;
	char	**argv;

	// ACT
	argc = 3;
	argv = (char *[]){"./a.out", "test1", "test2"};
	strcpy(expected_result, "Too many arguments.\n");
	capture_ft_display_file_output(program_main, argc, argv, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_display_file_short_file)
{
	// ARRANGE
	char	expected_result[128];
	char	actual_result[128];
	int		argc;
	char	**argv;
	char	*full_path;
	FILE	*file;

	file = fopen("test_ft_display_file_short_file.txt", "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 128 / 2; i++) {
		fprintf(file, "42");
	}
	fclose(file);

	file = fopen("test_ft_display_file_short_file.txt", "r");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fread(expected_result, sizeof(char), sizeof(expected_result) - 1, file);
	fclose(file);

	// ACT
	argc = 2;
	full_path = realpath("test_ft_display_file_short_file.txt", NULL);
	if (full_path == NULL) {
		perror("realpath");
		exit(EXIT_FAILURE);
	}
	argv = (char *[]){"./a.out", full_path};
	capture_ft_display_file_output(program_main, argc, argv, actual_result, sizeof(actual_result));
	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(full_path);

	// Remove o arquivo após o teste
	if (remove("test_ft_display_file_short_file.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
}

MU_TEST(test_ft_display_file_regular_file)
{
	// ARRANGE
	char	expected_result[8192];
	char	actual_result[8192];
	int		argc;
	char	**argv;
	char	*full_path;
	FILE	*file;

	file = fopen("test_ft_display_file_regular_file.txt", "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 8192 / 2; i++) {
		fprintf(file, "42");
	}
	fclose(file);

	file = fopen("test_ft_display_file_regular_file.txt", "r");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fread(expected_result, sizeof(char), sizeof(expected_result) - 1, file);
	fclose(file);

	// ACT
	argc = 2;
	full_path = realpath("test_ft_display_file_regular_file.txt", NULL);
	if (full_path == NULL) {
		perror("realpath");
		exit(EXIT_FAILURE);
	}
	argv = (char *[]){"./a.out", full_path};
	capture_ft_display_file_output(program_main, argc, argv, actual_result, sizeof(actual_result));
	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(full_path);

	// Remove o arquivo após o teste
	if (remove("test_ft_display_file_regular_file.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
}

MU_TEST(test_ft_display_file_large_file)
{
	// ARRANGE
	char	expected_result[32768];
	char	actual_result[32768];
	int		argc;
	char	**argv;
	char	*full_path;
	FILE	*file;

	file = fopen("test_ft_display_file_large_file.txt", "w");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 32768 / 2; i++) {
		fprintf(file, "42");
	}
	fclose(file);

	file = fopen("test_ft_display_file_large_file.txt", "r");
	if (file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fread(expected_result, sizeof(char), sizeof(expected_result) - 1, file);
	fclose(file);

	// ACT
	argc = 2;
	full_path = realpath("test_ft_display_file_large_file.txt", NULL);
	if (full_path == NULL) {
		perror("realpath");
		exit(EXIT_FAILURE);
	}
	argv = (char *[]){"./a.out", full_path};
	capture_ft_display_file_output(program_main, argc, argv, actual_result, sizeof(actual_result));
	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(full_path);

	// // Remove o arquivo após o teste
	if (remove("test_ft_display_file_large_file.txt") != 0) {
		perror("remove");
		exit(EXIT_FAILURE);
	}
}

MU_TEST_SUITE(ft_display_file_test_suite)
{
	MU_RUN_TEST(test_ft_display_file_empty_params);
	MU_RUN_TEST(test_ft_display_file_more_than_one_params);
	MU_RUN_TEST(test_ft_display_file_short_file);
	MU_RUN_TEST(test_ft_display_file_regular_file);
	MU_RUN_TEST(test_ft_display_file_large_file);
}

int	main(void) {
	MU_RUN_SUITE(ft_display_file_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
