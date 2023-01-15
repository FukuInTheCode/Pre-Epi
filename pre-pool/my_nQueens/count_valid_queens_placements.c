/*
** EPITECH PROJECT, 2023
** my_nQueens
** File description:
** count_queens
*/

int my_put_nbr(int nb);

int count_valid_queens_placements(int n);

int recursive_queens(int n);

int check_placement(int col, int n);

int row = 0;

int valid = 0;

int count = 0;

int queens[99][2];

int main(void)
{
    my_put_nbr(count_valid_queens_placements(5));
}

int count_valid_queens_placements(int n)
{
    for (int i = 0; i < n; i++)
    {

        queens[count][0] = row;
        queens[count][1] = i;
        count++;
        row++;
        recursive_queens(n);
    }
    return valid;
}

int recursive_queens(int n)
{

    if (count == n)
    {
        valid++;
        count--;
        row--;
        return 0;
    }
    else if (row == n)
    {
        if (count == n)
        {
            valid++;
        }
        count--;
        row--;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (check_placement(i, n) == 1)
        {

            queens[count][0] = row;
            queens[count][1] = i;
            count++;
            row++;
            recursive_queens(n);
        }
    }
    count--;
    row--;
}

int check_placement(int col, int n)
{

    for (int j = 0; j < count; j++)
    {
        if (queens[j][1] == col)
            return 0;
        if (queens[j][0] + queens[j][1] == row + col)
            return 0;
        if (queens[j][0] - queens[j][1] + n == row - col + n)
            return 0;
    };
    return 1;
}