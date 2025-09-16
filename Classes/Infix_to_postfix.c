#include<stdio.h>
#include<stdlib.h>

struct stack{
    char*arr;
    int top,size,cap;
};

struct stack* initialize(int size){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->arr=(char*)malloc(sizeof(char)*size);
    st->top=-1;
    st->size=0;
    st->cap=size;
    return st;
}

int isEmpty(struct stack* st){
    if(st->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* st){
    if(st->top==(st->cap)-1){
        return 1;
    }
    return 0;
}

void push(struct stack* st,int val){
    if(isFull(st)){
        return;
    }
    st->top++;
    st->arr[st->top]=val;
    st->size++;
}

void pop(struct stack* st){
    if(isEmpty(st)){
        return;
    }
    st->top--;
    st->size--;
}

char top(struct stack* st){
    if(isEmpty(st)){
        return ' ';
    }
    return st->arr[st->top];
}

int priority(char ch){
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}

void InfixToPostfix(char ch[50]){
    struct stack* st=initialize(100);
    int i=0,k=0;
    char ans[50];
    while(ch[i]!='\0'){
        //Checking for operands.
        if((ch[i]>='a' && ch[i]<='z')){
            ans[k++]=ch[i];
        }else if(ch[i]=='('){
            push(st,ch[i]);
        }
        else if(ch[i]==')'){ //Checking for closing bracket.
            while(!isEmpty(st) && top(st)!='('){
                ans[k++]=top(st);
                pop(st);
            }
            pop(st);//pop '(' bracket.
        }
        else{ //For operators.
            while(!isEmpty(st) && priority(top(st))>=priority(ch[i])){
                ans[k++]=top(st);
                pop(st);
            }
            push(st,ch[i]);
        }
        i++;
    }
    while(!isEmpty(st)){
        ans[k++]=top(st);
        pop(st);
    }
    ans[k]='\0';
    printf("%s",ans);
}

int main(){
    char ch[50];
    scanf("%s",ch);
    InfixToPostfix(ch);
}