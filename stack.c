#include<stdio.h>
 int top=-1;
 int size=5;
    int st[5];
void push(){
    int x;
    if(top==size-1){
        printf("Stack is Full");
        return;
    }
    else{
        printf("Enter element to enter: ");
        scanf("%d",&x);
        top=top+1;
        st[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack is Empty");
        return;
    }
    else{
        top--;
    }
}
void dis(){
    int y=top;
    if(y==-1){
        printf("Stack is empty");
        return;
    }
    while(y!=-1){
        printf("%d",st[y]);
        y--;
    }
}
int main(){
   int c;
   push();
    printf("Enter an operation");
    scanf("%d",&c);
    switch(c){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        dis();
        break;
        default:
        printf("Not valid operation.");
        break;
    }
   
}