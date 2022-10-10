#include <stdio.h>

char exp[100];
int flag = 0;
//this flag will ensure that after bracket there are more then 1 operators

int strlen(char *str){
    int l;
    for (l = 0; *str!='\0'; str++){
        l++;
    }
    return l;
}

char* push(char * ptr, char ele){   
    ptr++;
    *ptr = ele;
    printf("Pushed %c element at %p Address\n",*ptr,ptr);
    return ptr;
}

char* pop(char * ptr){
    printf("Poped %c element at %p Address\n",*ptr,ptr);
    *ptr = ' ';
    ptr--;
    return ptr;
}

void sorter(char* ptr){
    int index = 0;
    char seq[] = {'/','*','+','-'};
    char corrected[flag];

    for (int i = 0; i < 4 ; i++){
        for (;flag > 0 ; flag--){
            if (*ptr == seq[i]){
                corrected[index] = seq[i];
                index++;
                ptr = pop(ptr);
            }
        }
    }
    //inserting it in stack
    //swaping to get index as 0 and flag as the orignal value
    flag = flag ^ index;
    index = flag ^ index;
    flag = flag ^ index;

    for (; index < flag; index++){
        ptr = push(ptr, corrected[index]);
    }
}

void postfix(char *ptr){
    for (int i = 0; i < strlen(exp); i++ ){
        switch (exp[i]){
        case '(':
            //condition to check if flag is more then 1 then it 
            if (flag > 1){
                sorter(ptr);
            }

            flag=0;
            ptr = push(ptr, '(');
            break;

        case '+':
            flag++;
            ptr = push(ptr, '+');
            /* code */
            break;

        case '-':
            flag++;
            ptr = push(ptr, '-');
            /* code */
            break;

        case '*':
            flag++;
            ptr = push(ptr, '*');
            /* code */
            break;

        case '/':
            flag++;
            ptr = push(ptr, '/');
            /* code */
            break;

        case ')':
            /* code */
            break;
        
        default:
            //when things like ABCD is going to be out
            break;

        
        }
    }
}

void main(){
    printf("Enter the expression : ");
    scanf("%s",&exp);
    printf(" %d \n", strlen(exp));
    char stack[strlen(exp)];
    char *ptr = stack;
    ptr--;
    postfix(ptr);

}