#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lexer.h"


const char PIPE[] = "|";
const char GREAT[] = ">";
const char LESS[] = "<";
const char AMPERSAND[] = "&";


token_arr_type token_array[100];
int COUNT;

void lexer(char* command){
    char* token = strtok(command," \t\n");
    int index = 0;


    while (token != NULL){
        
        strcpy(token_array[index].name, token);

        if(strlen(token) > 2 ){

            token_array[index].token_id = token_WORD;
           
        }
        else if(strlen(token) == 2){


            if(strcmp(">>",token) == 0){
                token_array[index].token_id = token_GREATGREAT;
            }
            else{
                token_array[index].token_id = token_WORD;
            }


        }
    

        else{
            
            if (strcmp(PIPE,token) == 0){
                token_array[index].token_id = token_PIPE;
           
               
            }

            else if ((strcmp(GREAT,token) == 0)){
                token_array[index].token_id = token_GREAT;
           
            }

            else if ((strcmp(LESS,token) == 0)){
                token_array[index].token_id = token_LESS;
           

            }

            else if ((strcmp(AMPERSAND,token) == 0)){
                token_array[index].token_id = token_AMPERSAND;
           

              
                
            }
            else{
                token_array[index].token_id = token_SYMBOL;
          
            }


        }
        index++;
        token = strtok(NULL, " \t\n");
          


   }
    COUNT = index;
}
