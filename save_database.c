#include "main.h"
#include<string.h>
int save_database(main_t **arr , char *str){
    if(strcmp(strstr(str,"."),".txt")==0){
     FILE *fp=fopen(str,"w");
    if(fp==NULL){
        return FAILURE;
    }
    for(int i=0;i<28;i++){
        if(arr[i]==NULL){
            continue;
        }
        else{
            main_t *temp=arr[i];
            while(temp!=NULL){
            
            fprintf(fp,"#%d;%s;%d",i, temp->word, temp->f_count);
            sub_t *temp1=temp->s_link;
            int count=0;
            while(temp1!=NULL){
                if(count == 0)
                   fprintf(fp,";%s;%d", temp1->f_name, temp1->w_count);
                else
                    fprintf(fp,";%s;%d",temp1 -> f_name,temp1 -> w_count);
                count++;

               temp1=temp1->link;
            }
            putc('#',fp);
            putc('\n',fp);
            temp=temp->m_link;
            printf("\n");
            }
        }
        
       }
       fclose(fp);
     return SUCCESS;
    }
    else{
        printf("wrong file name\n");
        return FAILURE;
    }
}