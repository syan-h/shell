#include <stdio.h>
#include <unistd.h>
#include "lexer.h"



int main(){
    while(1){
        char prompt[]  = ">>> ";
        ssize_t writtenSize;
        writtenSize = write(1,prompt,4);
        int MAX_LEN = 1024;
        char command[MAX_LEN];
        
        fgets(command,MAX_LEN,stdin);

        lexer(command);
        int i;
        for(i=0;i<COUNT;i++){
            printf("%s  %d\n",token_array[i].name,token_array[i].token_id);
            
        }        
        


    }
    return 0;
}
