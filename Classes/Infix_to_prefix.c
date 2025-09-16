#include<stdio.h>
#include<stdlib.h>

struct stack{
    char* arr;
    int top,cap;
};

struct stack* initialize(int val){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->arr=(char*)malloc(sizeof(char));
    st->top=-1;
    st->cap=val;
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
    // st->size++;
}

void pop(struct stack* st){
    if(isEmpty(st)){
        return;
    }
    st->top--;
    // st->size--;
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

struct stack* reverse(struct stack* st){
    if(isEmpty(st)){
        return st;
    }
    struct stack* temp=initialize(100);
    // temp->top++;
    int i=st->top;
    while(i>=0){
        push(temp,st->arr[i]);
        i--;
        // pop(st);
    }
    return temp;
}

char* reverseString(char ch[]){
    int i=0,l=0;
    while(ch[l]!='\0'){
        l++;
    }
    while(i<l/2){
        char t=ch[i];
        ch[i]=ch[l-1-i];
        ch[l-1-i]=t;
    i++;
    }
    return ch;

}

void InfixToPrefix(char rch[50]){
    struct stack* st=initialize(100);
    char ans[50];int i=0,k=0;
    reverseString(rch);
    for(int j=0; rch[j]!='\0'; j++){
    if(rch[j]=='('){
        rch[j]=')';
    }
    else if(rch[j]==')'){ 
        rch[j]='(';
    }
}
    while(rch[i]!='\0'){
        //Check for operand.
            if(rch[i]>='a' && rch[i]<='z'){
                ans[k++]=rch[i];
            }
            else if(rch[i]=='('){
                push(st,rch[i]);
            }
            else if(rch[i]==')'){
                while(!isEmpty(st) && top(st)!='('){
                    ans[k++]=top(st);
                    pop(st);
                }
                pop(st);//popping '('
            }
            else{
                while(!isEmpty(st) && priority(rch[i])<=priority(top(st))){
                    ans[k++]=top(st);
                    pop(st);
                }
                push(st,rch[i]);
            }
            i++;
    }
    while(!isEmpty(st)){
        ans[k++]=top(st);
        pop(st);
    }
    ans[k]='\0';
    reverseString(ans);
    printf("%s",ans);
}

int main(){
    char ch[50];
    scanf("%s",ch);
    InfixToPrefix(ch);
}
