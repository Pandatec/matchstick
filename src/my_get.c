/*
** EPITECH PROJECT, 2019
** my_get.c
** File description:
** Get file
*/

#include "matchstick.h"

struct request *get_request(char **str)
{
    struct request *req = malloc(sizeof(struct request));

    if (req == NULL)
        return NULL;
    req->size = my_getnbr(str[1]);
    req->limit = my_getnbr(str[2]);
    req->content = malloc(sizeof(char *) * req->size);
    req->exit = 0;
    if (req->content == NULL)
        return NULL;
    for (int i = 0; i < req->size; i += 1) {
        req->content[i] = malloc(sizeof(char) *
        (1 + (2 * (req->size))));
        if (req->content[i] == NULL)
            return NULL;
    }
    return req;
}
int my_getnbr(char const *str)
{
    int var1 = 0;
    int var2 = 0;

    for (int i = 0; str[i] != '\0' && (str[i] < '0' || str[i] > '9'); i += 1) {
        if (str[i] != '+' && str[i] != '-')
            return (var1);
        else if (str[i] == '-' && var2 == 0)
            var2 = 1;
        else
            var2 = 0;
    }
    for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i += 1)
        var1 = (var1 * 10) + (str[i] - 48);
    if (var2 == 1)
        var1 = var1 * (-1);
    return (var1);
}

int input_matches(struct request *req, int line)
{
    char *str;
    int match;

    my_put_str("Matches: ");
    str = get_next_line(0);
    if (str == NULL) {
        req->exit = 0;
        return 84;
    }
    match = my_getnbr(str);
    if (handle_match_error(req, match) == 0)
        return (input(req, 1));
    return (remove_match(req, line, match));
}
