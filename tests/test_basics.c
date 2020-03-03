/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_strlen, counting_str_length)
{
    char test[] = "Hello";

    cr_assert_eq(my_strlen(test), 5);
}

Test(my_strlen, checking_null_str)
{
    char *test = NULL;

    cr_assert_eq(my_strlen(test), 0);
}

Test(my_putchar, testing_output_of_putchar)
{
    cr_redirect_stdout();
    my_putchar('c');
    cr_expect_stdout_eq_str("c");
}

Test(my_putstr, testing_output_of_putstr)
{
    cr_redirect_stdout();
    my_putstr("testing");
    cr_expect_stdout_eq_str("testing");
}

Test(my_putstr, testing_error)
{
    char *test = NULL;

    cr_assert_eq(my_putstr(test), 84);
}

Test(my_putstr, testing_no_error)
{
    cr_redirect_stdout();
    cr_assert_eq(my_putstr("BONJOUR"), 0);
}

Test(my_atoi, testing_null_pointer)
{
    char *test = NULL;

    cr_assert_eq(my_atoi(test), -1);
}

Test(my_atoi, testing_lettre_in_num)
{
    cr_assert_eq(my_atoi("12E"), -1);
}

Test(my_atoi, test_correct)
{
    cr_assert_eq(my_atoi("12"), 12);
}

Test(concat, testing_normal_concat)
{
    char test[] = "Hello";
    char test2[] = "World";

    cr_assert_str_eq(concat(test, test2), "Hello/World");
}

Test(concat, testing_null_fststr_concat)
{
    char *test = NULL;
    char test2[] = "World";

    cr_assert_eq(concat(test, test2), NULL);
}

Test(concat, testing_NULL_scdstr_concat)
{
    char test[] = "Hello";
    char *test2 = NULL;

    cr_assert_eq(concat(test, test2), NULL);
}

Test(convert_to_string, testing_easy_convertion)
{
    cr_assert_str_eq(convert_to_string(230), "230");
}

Test(convert_to_string, testing_zero_convertion)
{
    cr_assert_str_eq(convert_to_string(0), "0");
}

Test(my_revstr, testing_null_str)
{
    char *test = NULL;

    cr_assert_eq(my_revstr(test), NULL);
}

Test(my_strdup, testing_normal_output)
{
    char test[] = "Hello";

    cr_assert_str_eq(my_strdup(test), "Hello");
}

Test(my_strdup, testing_wrong_input)
{
    char *test = NULL;

    cr_assert_eq(my_strdup(test), NULL);
}