#include<stdio.h>
#ifndef MAIN_H
#define MAIN_H

#define SUCCESS 1
#define FAILURE 0

typedef struct file_name
{
    char *filename;
    struct file_name *link;
}file_t;
typedef struct subnode{
    int  w_count;
    char *f_name;
    struct subnode *link;
}sub_t;
typedef struct mainnode
{   
    char word[50];
    int  f_count;
    struct mainnode *m_link;
    sub_t *s_link;
}main_t;

int read_validate(int , char *argv[],file_t **head);
void print_list(file_t *head);
int create_database(file_t **head,main_t **arr);
void display(main_t **arr);
int search_database(main_t **arr , char *word);
int save_database(main_t **arr , char *str);
int update_database(main_t **arr,char *str);
#endif