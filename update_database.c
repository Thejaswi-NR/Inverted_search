#include"main.h"
#include<string.h>
#include<stdlib.h>
int update_database(main_t **arr,char *ptr){
    if(strstr(ptr,".")!=NULL && strcmp(strstr(ptr,"."),".txt")==0){
    FILE *fp = fopen(ptr,"r");                       //opening the data file in read mode
    static char *token;                             // variable declaration 
    char str[200];
    int value = fscanf(fp,"%s",str);
    int index , node = 0;
    printf("%s\n", str);
    if(str[0]=='#'){
    while ( value != EOF )                          //reading  upto EOF
    {
        if( str[0] == '#' )                         //to get the index number
        {
            node = 0;
            token = strtok(str,"#;");          // geting first token
            printf("%s\t",token);

            index = atoi(token);                // converting the token into integer using atoi and storing it in the index
            printf("index = %d\t",index);       //printing the index
           // token = strtok(NULL,";");           // Get the next token after the first one, using ';' as the delimiter.
      
            main_t *new = malloc(sizeof(main_t));
            main_t *temp;
            sub_t *temp1;

            token = strtok(NULL,";");               //using delimiter strtok data is store in database
            printf("word = %s\t",token);
            strcpy(new -> word,token);
            token = strtok(NULL,";");

            int count = atoi(token);

            printf("filecount = %d\t",count);
            new -> f_count = count;

            int sub = 0;
            for ( int i = 0 ; i < count; i++ )      //loop to store data in database
            {
                token = strtok(NULL,";");            //using delimiter and compare the value
                sub_t *new1 = malloc(sizeof(sub_t));

                printf("filename = %s\t",token);
                
                new1 -> f_name = malloc(strlen(token)+1);
                strcpy(new1 -> f_name,token);
                token = strtok(NULL,";");

                int count = atoi(token);
                
                printf("wordcount = %d\t",count);
                new1 -> w_count = count;
                new1 -> link = NULL;
                if ( !sub )                            //sub is 0
                {
                    new -> s_link = new1;
                    sub++;
                }
                else
                    temp1 -> link = new1;
                temp1 = new1;
            }
            if ( token != NULL ) 
                token = strtok(NULL,";");
            if ( !node  )
            {
                arr[index] = new;
                node++;
            }
            else
                temp -> m_link = new;
            new -> m_link = NULL;

            temp = new;
            printf("\n");
            token = strtok(NULL,";");
        }
        if ( token == NULL )
            value = fscanf(fp,"%s",str);

       }
     return SUCCESS;
    }
    else{
        printf("Not an valid file\n");
        return FAILURE;
     }
    }
    else{
        return FAILURE;
    }
}