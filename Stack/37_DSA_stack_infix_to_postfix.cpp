#include<iostream>
using namespace std;

class stack{
    public:
    int size;
    int top;
    char *arr;
};
int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
char stackTop(stack*sp){
    return sp->arr[sp->top];
}
int prec(char s){
    if(s=='*'||s=='/')return 3;
    else if(s=='+'||s=='-')return 2;
    return 0;
}
int isOp(char s){
    if(s=='*'||s=='/'||s=='+'||s=='-')return 1;
    return 0;
}
string infixToPostfix(string st){
    stack *infix = new stack[1];
    infix->size = 100;
    infix->top = -1;
    infix->arr = new char[infix->size];
    string postFix;
    // char *postFix;
    int i=0;
    int j = 0;
    while(st[i]){
        if(!isOp(st[i])){
            postFix[j]=st[i];
            j++;i++;
        }
        else{
            // if(prec(st[i])>prec(stackTop(infix))){
            if(prec(stackTop(infix))<prec(st[i])){
                push(infix,st[i]);
                i++;
            }
            else{
            }
                postFix[j]=st[i];
                j++;

        }
    }
    // while(infix->top!=-1){
    while(!isEmpty(infix)){
        postFix[j] = pop(infix);
        j++;
    }
    // postFix[j] = '\0';
    return postFix;
}
int main(){
    string infix = "a+b";
    // string postF = postFix(infix);
    // cout<<postF<<endl;

    cout<<infixToPostfix(infix)<<endl;
    return 0;
}