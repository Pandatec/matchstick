/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main file
*/

#include "matchstick.h"

int main(int ac, char **as)
{
    int exit_error = 84;
    struct request *req;

    srand(time(NULL));
    if (check(ac, as) == 0)
        return (exit_error);
    req = get_request(as);
    if (req == NULL)
        return (exit_error);
    process(req);
    return (req->exit);
}

int check(int ac, char **as)
{
    int size;
    int limit;

    if (ac != 3)
        return (0);
    size = my_getnbr(as[1]);
    limit = my_getnbr(as[2]);
    if (size < 1 || size > 100 || limit <= 0)
        return (0);
    return (1);
}
