#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    if( top==-1)
    return -1;
    else 
        return stack[top--];

}

int precedence(char x){
    if(x=='(')
    return 0;
    if(x=='+' || x=='-')
    return 1;
    if(x=='*' || x=='/')
    return 2;
    return 0;
}

int main(){
    char infix[100];
    char i,x;
    printf("Enter the expression:");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++){
        if (isalnum(infix[i])){
            printf("%c",infix[i]);
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }

        }
        else{
            while(precedence(stack[top])>=precedence(infix[i])){
                printf("%c",pop());
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        
        printf("%c",pop());
    }
}