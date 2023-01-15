/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** my_putnbr
*/

char neg = '-', zero = '0';

int my_put_nbr(int nb)
{
    int n = nb;
    int q = 1;
    int tenth = 0;
    while (n / q / 10 != 0)
    {
        q = q * 10;
        tenth++;
    }
    for (int i = 0; i <= tenth; i++)
    {
        int tmp = 48 + (n - n % q) / q;
        write(1, &tmp, 1);
        n = n % q;
        q = q / 10;
    };
};