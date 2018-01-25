//
//  main.c
//  String Line
//
//  Created by Jukkrit Buangarm on 9/1/2561 BE.
//  Copyright © 2561 Jukkrit Buangarm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    char * pch;
    int i,temp= 0;
    long len;
    int flag = 0;
    char master_Keyword[32][20] = {
        "auto",    "double",    "int",    "struct",
        "break",    "else",    "long",    "switch",
        "case",    "enum",    "register",     "typedef",
        "char",    "extern",    "return",    "union",
        "continue",    "for",    "signed",    "void",
        "do",    "if",    "static",     "while",
        "default",    "goto",    "sizeof",    "volatile",
        "const",    "float",    "short",    "unsigned"
    };
    char master_symbol[32][5] = {
        "++", "--", "=",
        ",",    "<",    ">",    ".",    "_",
        "(",    ")",    ";",    "$",    ":",
        "%",    "[",    "]",    "#",    "?",
        "'",    "&",    "{",    "}",    "\"",
        "^",    "!",    "*",    "/",    "|",
        "-",    "\\",    "~",    "+"
    };
    char str[100]; //= "case for i = 690 ++ else ; 000 * i if < 6 i ++ if ) -- ) test01";
    char keystr[100];
    char symstr[100];
    char numstr[100];
    char varstr[100];
    char otstr[100] = " Not working";
    int countkey=0,countsym=0,countnum=0,countvar=0,countot=0;
    printf("----------------------------------------------------------------------------\n");
    printf("EX String : case for i = 690 ++ else ; 000 * i if < 6 i ++ if ) -- ) test01\n");
    printf("----------------------------------------------------------------------------\n");
    printf("Enter input: ");
    scanf("%[^\n]s",str);
    printf("----------------------------------------------------------------------------\n");
    printf ("Input is : %s\n",str);
    printf("----------------------------------------------------------------------------\n");
    pch = strtok (str," ");
    while (pch != NULL)
    {   temp = 0;
        for (i=0; i<32; i++) {
            if (strcmp(pch, master_Keyword[i])==0) {
                strcat(keystr, " ");
                strcat(keystr, pch);
                countkey++;
                temp = 1;
            }
        }
        for (i=0; i<32; i++) {
            if(strcmp(pch, master_symbol[i])==0){
                strcat(symstr, " ");
                strcat(symstr, pch);
                countsym++;
                temp = 1;
            }
        }
        len = strlen(pch);
        for(i=0;i<len;i++)
        {
            if(pch[i] >= 48 && pch[i] <= 57  && flag == 0)
            {
                flag = 1 ;
            }else{
                flag = 0;
            }
        }
        if (flag == 1) {
            strcat(numstr, " ");
            strcat(numstr, pch);
            countnum++;
            temp = 1;
        }
        if (temp == 0) {
            strcat(varstr, " ");
            strcat(varstr, pch);
            countvar++;
        }
        pch = strtok (NULL, " ");
    }
    
    printf("Output of Keyword [%d] :%s\n",countkey,keystr);
    printf("Output of Symbols [%d] :%s\n",countsym,symstr);
    printf("Output of Numbers [%d] :%s\n",countnum,numstr);
    printf("Output of Identifier [%d] :%s\n",countvar,varstr);
    printf("Output of Other [%d] :%s\n",countot,otstr);
    printf("----------------------------------------------------------------------------\n");
    return 0;
    
}

