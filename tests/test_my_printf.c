/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf
*/

# include <criterion/criterion.h>
# include <criterion/redirect.h>
#include<stdio.h>

void redirect_all_std ( void )
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int my_printf ( const char * format , ...);

Test (my_printf , simple_string , .init = redirect_all_std )
{
    my_printf("hello world");
    cr_assert_stdout_eq_str ("hello world");
}

Test (my_printf , int_string , .init = redirect_all_std )
{
    int n = 256;
    my_printf("hello world %%d bonsoir", n);
    cr_assert_stdout_eq_str ("hello world %d bonsoir");
}

Test (my_printf , int_string2 , .init = redirect_all_std )
{
    int n = 256;
    my_printf("hello world %i bonsoir", n);
    cr_assert_stdout_eq_str ("hello world 256 bonsoir");
}

Test (my_printf , percent_string , .init = redirect_all_std )
{
    my_printf("hello world %% bonsoir");
    cr_assert_stdout_eq_str ("hello world % bonsoir");
}

Test (my_printf , char_string , .init = redirect_all_std )
{
    char n = 't';
    my_printf("hello world %c bonsoir", n);
    cr_assert_stdout_eq_str ("hello world t bonsoir");
}

Test (my_printf , str_string , .init = redirect_all_std )
{
    char * n = "bon";
    my_printf("hello world %s %c %d %c bonsoir", n, 't', 23, 'B');
    cr_assert_stdout_eq_str ("hello world bon t 23 B bonsoir");
}

Test (my_printf , error_string)
{
    char * n = "bonsoir";
     int r = my_printf("hello world %QA bonsoir", n);
     cr_assert_eq(r, 84);
}

Test (my_printf , return_str_string, .init = redirect_all_std )
{
    char * n = "bonsoir";
    int r;
    r = my_printf("hello world %s bonsoir", n);
    cr_assert_eq(r, 27);
}

Test (my_printf , return_nb_string , .init = redirect_all_std )
{
    int d = -267;
    int r;
    r = my_printf("hello world %d bonsoir", d);
    cr_assert_eq(r, 24);
}

Test (my_printf , return_float , .init = redirect_all_std )
{
    float d = 267.0;
    my_printf("hello world %f bonsoir", d);
    cr_assert_stdout_eq_str("hello world 267.000000 bonsoir");
}

Test (my_printf , print_Noprintable , .init = redirect_all_std )
{
    char* c = "Bonjour \n ceci \n semble \n fonctionner\n";
    my_printf("%S", c);
    cr_assert_stdout_eq_str("Bonjour \\012 ceci \\012 semble \\012 fonctionner\\012");
}

Test (my_printf , return_nb_noprintable, .init = redirect_all_std )
{
    char str[] = "Bonjour   test";
    str[8] = 10;
    int res;
    res = my_printf("%S", str);
    cr_assert_eq(res, 17);
}

Test (my_printf , print_hexa_maj , .init = redirect_all_std )
{
    unsigned int i = 123;
    my_printf("%X", i);
    cr_assert_stdout_eq_str("7B");
}

Test (my_printf , return_nb_hexa_maj, .init = redirect_all_std )
{
    unsigned int i = 123;
    int res;
    res = my_printf("%X", i);
    cr_assert_eq(res, 2);
}

Test (my_printf , print_hexa_min , .init = redirect_all_std )
{
    unsigned int i = 123;
    my_printf("%x", i);
    cr_assert_stdout_eq_str("7b");
}

Test (my_printf , return_nb_hexa_min, .init = redirect_all_std )
{
    unsigned int i = 123;
    int res;
    res = my_printf("%x", i);
    cr_assert_eq(res, 2);
}

Test (my_printf , return_binary , .init = redirect_all_std )
{
    int i = 267;
    my_printf("hello world %b bonsoir", i);
    cr_assert_stdout_eq_str("hello world 100001011 bonsoir");
}

Test (my_printf , return_binari , .init = redirect_all_std )
{
    int i = 1084;
    my_printf("hello world %b bonsoir", i);
    cr_assert_stdout_eq_str("hello world 10000111100 bonsoir");
}

Test (my_printf , print_unsided_int , .init = redirect_all_std )
{
    unsigned int i = 123;
    my_printf("%u", i);
    cr_assert_stdout_eq_str("123");
}

Test (my_printf , return_nb_unsigned_int, .init = redirect_all_std)
{
    unsigned int i = 123;
    int res;
    res = my_printf("%u", i);
    cr_assert_eq(res, 3);
}

Test (my_printf , int_string_long_long , .init = redirect_all_std )
{
    long long int n = 12000000000000000;
    my_printf("hello world %lli bonsoir", n);
    cr_assert_stdout_eq_str ("hello world 12000000000000000 bonsoir");
}

Test (my_printf , int_string_long_long_with_d , .init = redirect_all_std )
{
long long int n = 12000000000000000;
my_printf("hello world %lld bonsoir", n);
cr_assert_stdout_eq_str ("hello world 12000000000000000 bonsoir");
}

Test (my_printf , int_string_long_long_neg , .init = redirect_all_std )
{
long long int n = -12000000000000000;
my_printf("hello world %lli bonsoir", n);
cr_assert_stdout_eq_str ("hello world -12000000000000000 bonsoir");
}

Test (my_printf , int_string_long_long_dot , .init = redirect_all_std )
{
long long int n = 12000000000000000;
my_printf("hello world %.30lli bonsoir", n);
cr_assert_stdout_eq_str ("hello world 00000000000012000000000000000 bonsoir");
}

Test (my_printf , int_string_long , .init = redirect_all_std )
{
long long int n = 12000000000;
my_printf("hello world %li bonsoir", n);
cr_assert_stdout_eq_str ("hello world 12000000000 bonsoir");
}

Test (my_printf , int_string_long_with_d , .init = redirect_all_std )
{
long long int n = 1200000000;
my_printf("hello world %ld bonsoir", n);
cr_assert_stdout_eq_str ("hello world 1200000000 bonsoir");
}

Test (my_printf , print_count_in_string , .init = redirect_all_std )
{
int n[1];
my_printf("hello world %n bonsoir", n);
cr_assert_stdout_eq_str ("hello world  bonsoir");
}

Test (my_printf , print_count_verif_return , .init = redirect_all_std )
{
int n[1];
my_printf("hello world %n bonsoir", n);
cr_assert_eq (n[0], 12);
}

Test (my_printf , return_pointer , .init = redirect_all_std )
{
char * str = "bonsoir";
int count = my_printf("hello world %p bonsoir", str);
cr_assert_eq (count, 34);
}

Test (my_printf , str_string_mult , .init = redirect_all_std )
{
    char * n = "bon";
    my_printf("hello world %s %c %d %c bonsoir", n, 't', 23, 'B');
    cr_assert_stdout_eq_str ("hello world bon t 23 B bonsoir");
}

Test (my_printf , exposant_pos , .init = redirect_all_std )
{
    double x = 123.123;
    my_printf("Le resultat est : %e", x);
    cr_assert_stdout_eq_str ("Le resultat est : 1.231230e+02");
}

Test (my_printf , exposant_neg , .init = redirect_all_std )
{
    double x = -123.123;
    my_printf("Le resultat est : %e", x);
    cr_assert_stdout_eq_str ("Le resultat est : -1.231230e+02");
}

Test (my_printf , exposant_null , .init = redirect_all_std )
{
    double x = 0.00012;
    my_printf("Le resultat est : %e", x);
    cr_assert_stdout_eq_str ("Le resultat est : 1.200000e-04");
}

Test (my_printf , i_with_zero , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %05i", i);
cr_assert_stdout_eq_str ("Le resultat est : 00023");
}

Test (my_printf , i_with_point , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %.5i", i);
cr_assert_stdout_eq_str ("Le resultat est : 00023");
}

Test (my_printf , x_min_hashtag , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %#x", i);
cr_assert_stdout_eq_str ("Le resultat est : 0x17");
}

Test (my_printf , x_maj_hashtag , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %#X", i);
cr_assert_stdout_eq_str ("Le resultat est : 0X17");
}

Test (my_printf , x_min_hashtag_null , .init = redirect_all_std )
{
int i = 0;
my_printf("Le resultat est : %#x", i);
cr_assert_stdout_eq_str ("Le resultat est : 0");
}

Test (my_printf , x_maj_hashtag_null , .init = redirect_all_std )
{
int i = 0;
my_printf("Le resultat est : %#X", i);
cr_assert_stdout_eq_str ("Le resultat est : 0");
}

Test (my_printf, print_octa , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %o", i);
cr_assert_stdout_eq_str ("Le resultat est : 27");
}

Test (my_printf, print_octa_with_hashtag , .init = redirect_all_std )
{
int i = 23;
my_printf("Le resultat est : %#o", i);
cr_assert_stdout_eq_str ("Le resultat est : 027");
}

Test (my_printf, print_float_precision, .init = redirect_all_std )
{
    float f= 23.3434;
    my_printf("Le resultat est : %.3f", f);
    cr_assert_stdout_eq_str("Le resultat est : 23.343");
}

Test (my_printf, print_float_g, .init = redirect_all_std )
{
float g= 23.3434;
my_printf("Le resultat est : %g", g);
cr_assert_stdout_eq_str("Le resultat est : 23");
}

Test (my_printf, print_float_g_sup5, .init = redirect_all_std)
{
float g = 234567.3434;
my_printf("Le resultat est : %g", g);
cr_assert_stdout_eq_str("Le resultat est : 234567");
}

Test (my_printf, print_float_g_inf5, .init = redirect_all_std)
{
float g= 123.243243;
my_printf("Le resultat est : %g", g);
cr_assert_stdout_eq_str("Le resultat est : 1234.243");
}

Test (my_printf, print_float_pos_multi_sign, .init = redirect_all_std)
{
float g= 1234.243243;
my_printf("Le resultat est : %.a-2147483647f", g);
cr_assert_stdout_eq_str("Le resultat est : %.a-2147483647f");
}

Test (my_printf, print_g_int_equal_zero, .init = redirect_all_std)
{
float g= 0.012344654;
my_printf("Le resultat est : %g", g);
cr_assert_stdout_eq_str("Le resultat est : 0.012344");
}

Test (my_printf, print_g_int_result_more_6, .init = redirect_all_std)
{
float g= 1234567.012344654;
my_printf("Le resultat est : %g", g);
cr_assert_stdout_eq_str("Le resultat est : 1.234568e+06");
}

