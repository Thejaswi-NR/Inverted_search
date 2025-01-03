#include "main.h"
#include<string.h>
int search_database(main_t **arr , char *str){
    int index;
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
    main_t *temp=arr[index];
    int flag=0;
    while(temp!=NULL){
        if(strcmp(temp->word,str)==0){
            flag=1;
            // printf("[%d]\t%s\t",index, temp->word);
            printf("%s is present at index %d\n",temp -> word , index);
            printf("%s is present in %d files\n",temp -> word, temp->f_count);
            
        sub_t *temp1=temp->s_link;
        while(temp1!=NULL){
            printf("%s is  present in %s : %d times\n",temp -> word,temp1 -> f_name,temp1 ->w_count);
            temp1=temp1->link;
        }
        }
        temp=temp->m_link;
    }
    if(flag==0){
       printf("data not found\n");
       return FAILURE;
    }
    return SUCCESS;
}