#include "main.h"
#include<stdlib.h>
#include<string.h>
int create_database(file_t **head,main_t **arr){
    file_t *temp=*head;
    int index ;
    while(temp!=NULL){
        FILE *fptr=fopen(temp->filename,"r");
        rewind(fptr);
        char str[100];
        label:
         while(fscanf(fptr,"%s ",str) != EOF){
           
            if(str[0]>='A' && str[0]<='Z'){
               index=str[0]-'A';
            }
            else if(str[0]>='a' && str[0]<='z'){
                index=str[0]-'a';
            }
            else if(str[0]>=0 && str[0]<=9){
                index=str[0]-'0';
            }
            else{
                index=27;
            }
            if(arr[index]==NULL){
                main_t *new=malloc(sizeof(main_t));
                sub_t *new1=malloc(sizeof(sub_t));
                if(new==NULL || new1==NULL){
                   return FAILURE;
                }
               
                strcpy(new->word,str);
                new->f_count=1;
                new->m_link=NULL;
                new->s_link=new1;

                new1->f_name=temp->filename;
                new1->link=NULL;
                new1->w_count=1;
                arr[index]=new;
            }
            else{

                main_t *t=arr[index];
                main_t *prev=NULL;
                while(t)
                {
                    if(strcmp(str,t->word)==0){
                        
                        sub_t *t1=t->s_link;
                        sub_t *prev1=NULL;
                        while(t1){
                            if(strcmp(t1->f_name,temp->filename)==0){
                               (t1->w_count)++;
                               goto label;
    
                            }
                            
                                prev1=t1;
                                t1=t1->link;
                            
                        }
                        sub_t *new1=malloc(sizeof(sub_t));
                        if(new1==NULL){
                            return FAILURE;
                        }
                        new1->f_name=temp->filename;
                        new1->w_count=1;
                        
                        new1->link=NULL;
                        prev1->link=new1;
                        (t->f_count)++;
                        goto label;
                    }
                prev=t;
                t=t->m_link;
                }
                main_t *new=malloc(sizeof(main_t));
                sub_t *new1=malloc(sizeof(sub_t));
                if(new==NULL || new1==NULL){
                   return FAILURE;
                }
                
                strcpy(new->word,str);
                new->f_count=1;
                new->s_link=new1;
                new->m_link=NULL;

                new1->f_name=temp->filename;
                new1->w_count=1;
                new1->link=NULL;


                prev->m_link=new;  
            }
        }
         temp=temp->link;
    }
    return SUCCESS;
}