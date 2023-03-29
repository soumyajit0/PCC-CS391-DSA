#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node * push(struct node *top,int value){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=top;
    return temp;
}

struct node * pop(struct node *top){
    if (top==NULL){
        printf("Underflow\n");
        return top;
    }
    struct node *temp=top->next;
    free(top);
    return temp;
}

int main(){
    char postfix[100];
    int n1,n2,s;
    printf("Enter the Postfix Expression : ");
    scanf("%s",&postfix);
    struct node *top=NULL;
    char *c=postfix;
    while(*c!='\0'){
        if (isdigit(*c)==true)
            top=push(top,*c-48);
        else{
            n1=top->data;
            top=pop(top);
            n2=top->data;
            top=pop(top);
            switch(*c){
                case '+':
                    s=n1+n2;
                    break;
                case '-':
                    s=n2-n1;
                    break;
                case '*':
                    s=n1*n2;
                    break;
                case '/':
                    s=n2/n1;
                    break;
            }
            top=push(top,s);
        }
        c++;
    }

    printf("The Result : %d\n",top->data);

    return 0; 
}