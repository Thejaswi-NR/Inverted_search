#include"main.h"
void display(main_t **arr){
    printf("%s\t%s\t  %s\t%s\t%s\n", "Index", "Word", "Filecount", "Files Name","Wordcount");
    for(int i=0;i<28;i++){
        if(arr[i]==NULL){
            continue;
        }
        else{
            main_t *temp=arr[i];
            while(temp!=NULL){
            printf("[%d]\t%s\t\t%d\t",i, temp->word, temp->f_count);
            sub_t *temp1=temp->s_link;
            int count=0;
            while(temp1!=NULL){
                if(count == 0)
                   printf("%s\t\t%d\n", temp1->f_name, temp1->w_count);
                else
                    printf("\t\t\t\t%s\t\t%d\n",temp1 -> f_name,temp1 -> w_count);
                count++;

               temp1=temp1->link;
            }
            temp=temp->m_link;
            printf("\n");
            }
        }
    }
}
