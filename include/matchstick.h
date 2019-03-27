/*
** EPITECH PROJECT, 2017
** file.h
** File description:
** Main header
*/

#ifndef  READ_SIZE
#define  READ_SIZE (1080)
#endif  /* READ_SIZE  */

#ifndef STICK_H_
#define STICK_H_

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

struct request {
    char **content;
    int limit;
    int size;
    int exit;
};

int check(int ac, char **as);
void play_bot(struct request *req);
void print_status(int nbr, int i);
void remove_random_match(struct request *req);
void remove_silent_match(struct request *req, int line, int match);
void process(struct request *req);
int input(struct request *req, int line);
int remove_match(struct request *req, int line, int match);
void my_remove(struct request *req, int match, int line);
void display(struct request *req);
int handle_match_error(struct request *req, int match);
int handle_line_error(int line);
struct request *get_request(char **str);
int my_getnbr(char const *str);
int input_matches(struct request *req, int line);
void fill_alums(struct request *req);
void my_put_char(char c, int output);
void my_put_str(const char *str);
int my_put_nbr(int nb, int output);
char *get_next_line(int fd);
int my_strlen(const char *str);
int entities_number(struct request *req);
int entities_number_line(struct request *req, int line);
int crand(int a, int b);

#endif /* STICK_H_ */
