/*
write a program to implement the following operations on strings
1. read a string
2. replace a string
3. perform patern matching, find and replace anyh occurance of the patern

*/

#include <stdio.h>
/*
Name : Saksham Jain
UID : 21BCS3508
*/ 

char str[100], pat[50], rep[50], new[100];

int strlen(char *str){
    int l;
    for (l = 0; *str!='\0'; str++){
        l++;
    }
    return l;
}

void input(){
    printf("Enter main string : ");
    scanf("%[^\n]%*c", str);
    printf("Enter Pattern : ");
    scanf("%[^\n]%*c", pat);
    printf("Enter replacement : ");
    scanf("%[^\n]%*c", rep);
}

int check(){
    for (int i = 0; i < strlen(str) ; i++){
        if (str[i] == pat[0]){
            int j;
            for (j = 0; j < strlen(pat); j++){
                if (str[i+j] != pat[j]){
                    printf("string dont have the pattern\n");
                    return strlen(str)+5; 
                }
            }
            if (j == strlen(pat)){
                printf("string has the patern starting at index %d\n", i);
                return i;
            }
        }
    }
}

void replace(int start){
    if (start == strlen(str)+5){
        printf("Terminating the Program...\n");
    }
    else { 
        //removing patern
        for (int s = 0; s < strlen(pat); s++){
            for (int i = start ; i < start +strlen(pat)+1; i++){
                str[i] = str[i+1];
            }
            str[start + strlen(pat)+1] = ' '; 
        } 
        //inserting replacement text
        for (int j = 0; j < strlen(rep); j++){
            for (int i = strlen(str); i >= start+j ; i--){
                if (i == start+j){
                    str[start+j] = rep[j];
                }
                else{
                    str[i] = str[i-1];
                }
            }
        }
        printf("Result : %s\n", str);
    }
}


void main(){   
    input();
    replace(check());    
}