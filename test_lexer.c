#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "lexer.h"




void test(int expected_count,char expected_names[][20],int expected_id[20]){
    printf("Tokens: \n");
    for (int i = 0; i < COUNT; i++) {
        printf("Token %d: Name = %s, token_id = %d\n", i, token_array[i].name, token_array[i].token_id);
        if (strcmp(token_array[i].name, expected_names[i]) != 0 || token_array[i].token_id !=  expected_id[i])  {
            printf("***********************Test Failed at token %d\n", i);

            return;


        }

    }

    assert(COUNT == expected_count && 
               "Count not equal to expected count");
    printf("Test passed..............\n");
    printf("\n");
    

}



int main(){


    
    char command1[] = "cd hannan < >";
    lexer(command1);
    char expected_names1[][20] = {"cd","hannan","<",">"};
    int expected_id1[20] = {-5,-5,-3,-2};
    test(4, expected_names1, expected_id1);



    
    char command2[] = "   < >";
    lexer(command2);
    char expected_names2[][20] = {"<",">"};
    int expected_id2[20] = {-3,-2};
    test(2, expected_names2, expected_id2);




    char command3[] = "| < > >>";
    lexer(command3);
    char expected_names3[][20] = {"|","<",">",">>"};
    int expected_id3[20] = {-1,-3,-2,-6};
    test(4, expected_names3, expected_id3);

    

    char command4[] = "cat < file.txt &";
    lexer(command4);
    char expected_names4[][20] = {"cat","<","file.txt","&"};
    int expected_id4[20] = {-5,-3,-5,-4};
    test(4,expected_names4,expected_id4);


    
    char command5[] = "echo   hello   world";
    lexer(command5);
    char expected_names5[][20] = {"echo","hello","world"};
    int expected_id5[20] = {-5,-5,-5};
    test(3, expected_names5, expected_id5);

  






}















































