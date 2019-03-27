/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "matchstick.h"

static char *my_strdup(char *src)
{
    int nb = 0;
    char *new_str;

    while (src && src[nb])
        nb += 1;
    if (!(new_str = malloc(sizeof(char) * nb + 1)))
        return (NULL);
    nb = 0;
    while (src[nb] != '\0') {
        new_str[nb] = src[nb];
        nb += 1;
    }
    new_str[nb] = '\0';
    return (new_str);
}

static char *str_cpy(char *dest, char *src, int nbr, int concatenate)
{
    int nb = 0;
    int nb_src;

    if (concatenate == true) {
        while (dest != NULL && dest[nb])
            nb += 1;
        nb_src = 0;
        while (src[nb_src] && nb_src < nbr) {
            dest[nb] = src[nb_src];
            nb += 1;
            nb_src += 1;
        }
        dest[nb] = '\0';
        return (dest);
    }
    while (src[nb] && nb < nbr) {
        dest[nb] = src[nb];
        nb += 1;
    }
    dest[nb] = '\0';
    return (dest);
}

static char *auto_alloc(char *ptr, size_t mem)
{
    char *new_ptr;
    int ptr_len = 0;

    while (ptr && ptr[ptr_len])
        ptr_len += 1;
    if (!ptr) {
        if (!(new_ptr = malloc(sizeof(char) * mem)))
            return (NULL);
        else if (mem > 0)
            new_ptr[0] = '\0';
        return (new_ptr);
    }
    if (!(new_ptr = malloc(sizeof(char) * (ptr_len + 1 + mem))))
        return (NULL);
    new_ptr = str_cpy(new_ptr, ptr, ptr_len, false);
    free(ptr);
    return (new_ptr);
}

static char *get_new_buffer(char *buf, char *buf_full, int fd, int count)
{
    int tmp;

    while (true) {
        count = 0;
        tmp = 0;
        while (buf_full && buf_full[tmp]) {
            if (buf_full[tmp++] == '\n')
                count += 1;
        }
        if (count != 0)
            return (buf_full);
        else if ((tmp = read(fd, buf, READ_SIZE)) <= 0 || (buf[tmp] = '\0') ||
            !(buf_full = auto_alloc(buf_full, READ_SIZE + 1))) {
            if (buf_full != NULL && buf_full[0] != '\0')
                return (buf_full);
            free(buf);
            free(buf_full);
            return (NULL);
        }
        buf_full = str_cpy(buf_full, buf, READ_SIZE, true);
    }
}

char *get_next_line(int fd)
{
    char *buf;
    static char *buffer;
    int nb_buf = 0;
    int nb = 0;
    char *line;

    if (READ_SIZE <= 0 || !(buf = malloc(sizeof(char) * (READ_SIZE + 1))) ||
        !(buffer = get_new_buffer(buf, buffer, fd, 0)))
        return (NULL);
    for (; buffer[nb_buf + nb] && buffer[nb_buf + nb] != '\n'; nb += 1);
    for (; buffer[nb_buf + nb] && buffer[nb_buf + nb] != '\n'; nb += 1);
    buf = buffer;
    if (!(line = auto_alloc((line = NULL), nb + 2)) ||
        !(buffer = buf[nb_buf + nb] == '\0' ? my_strdup("\0") :
          my_strdup(buf + nb_buf + nb + 1)))
        return (NULL);
    line = str_cpy(line, buf + nb_buf, nb + 1, false);
    line[nb] = '\0';
    free(buf);
    return (line);
}
