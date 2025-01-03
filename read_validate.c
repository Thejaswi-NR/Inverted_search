#include "main.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define RED "\x1b[31m"
#define PINK "\x1b[35m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
int read_validate(int argc,char *argv[],file_t **head){
    for(int i=1;i<argc;i++){
        lable:
        if(strstr(argv[i],".")!=NULL && strcmp(strstr(argv[i],"."),".txt")==0){
            FILE *fptr=fopen(argv[i],"r");
            char ch;
            ch=fgetc(fptr);
            if(ch!=EOF){
                file_t *temp=*head;
                if(*head==NULL){
                   file_t *new=malloc(sizeof(file_t));
                   new -> filename = argv[i];
                   new -> link=NULL;
                   *head=new;
                   printf(GREEN "Successful : Creation of database for file "BLUE"%s\n"RESET"",new -> filename);
                }
                else if(*head!=NULL){
                  int flag=0;
                    while (temp->link!=NULL)
                    {
                        if(strcmp(temp->filename,argv[i])==0){ //if duplicate is present 
                         printf(RED"INFO : Duplicate filenames are found and remove.\n"RESET"");
                         i=i+1;
                         goto lable;
                        //return FAILURE;
                        }
                    temp=temp->link;
                    }
                    if(flag==0){
                    file_t *new=malloc(sizeof(file_t));
                    new -> filename = argv[i];
                    new -> link=NULL;
                    strcpy(new->filename,argv[i]);
                    new->link=NULL;
                    temp->link=new;
                    printf(GREEN "Successful : Creation of database for file "BLUE"%s\n"RESET"",new -> filename);
                    }
                    
                }
                else{
                    return FAILURE;
                }
                
            }
            else{
                printf(RED"INFO : List is empty\n"RESET"");
                return FAILURE;
            }
        }
        else {
           printf(RED"Not an valid file\n"RESET"");
            if(i==argc-1){
             return FAILURE;
            }
           i=i+1;
           goto lable;
        }
    }
    return SUCCESS;
}
void print_list(file_t *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head!=NULL)		
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}