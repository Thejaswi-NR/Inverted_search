#include<stdio.h>
#include "main.h"
#define RED "\x1b[31m"
#define PINK "\x1b[35m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RESET  "\x1b[0m"
int main(int argc, char *argv[]){
    file_t *head=NULL;
    main_t *arr[28]={NULL};
    char ch='y';
    int op;
    while(ch=='y' || ch=='Y'){
    printf("Enter your choice\n1: Read and varidate\n2: Create database\n3: Search database\n4: Save database\n5: update database\n6: Display database\n");
    scanf("%d",&op);
    static int flag=0;
    static int create=0;
    static int update=0;
    switch(op){
        case 1:
            if(read_validate(argc,argv,&head)==SUCCESS){
                //print_list(head);
                printf("read and validate successful\n");
            }
            break;
  
        case 2:
            flag=1;
            if(create==0){
                create=1;
                if(create_database(&head,arr) == SUCCESS){
                   printf("creat database successful\n");
                }
                else{
                   printf("Failed\n");
                }
            }
            else{
                printf(RED"database is already created\n"RESET"");
            }
            break;
        case 3:
            char word[20];
            printf("Enter the string to search\n");
            scanf("%s",word);
            if(search_database(arr,word)==SUCCESS){
               printf("search database successful\n");
            }
            else{
                printf("Failed\n");
            }
            break;
        case 4:
            // if(flag==1 || update==1){
                char str[50];
                printf("Enter the txt file you want to save the data\n");
                scanf("%s",str);
                if(save_database(arr,str)==SUCCESS){
                    printf("data saved  successful\n");
                }
                else{
                    printf("Failed\n");
                }
            //  }
            // else{
            //     printf(RED"without creating the database you can't save it\n"RESET"");
            // }
            break;
        case 5:
            if(flag==0 && update==0){
                update=1;
                char str1[50];
                printf("Enter the txt file\n");
                scanf("%s",str1);
                if(update_database(arr,str1)==SUCCESS){
                    printf("Update database successful\n");
                }
                else{
                   printf("Failed\n");
                }
            }
            else{
                printf(RED"Update database is not possible\n"RESET"");
            }
            break;
        case 6:
            display(arr);
            break;  
        }
        printf("do you wnant to continue(y/n)\n");
        scanf(" %c",&ch);
    }    
    }

