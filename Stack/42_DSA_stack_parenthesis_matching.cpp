#include <iostream>
using namespace std;

struct sNode
{
    char data;
    sNode *next;
};

void push(sNode **top_ref, int data)
{
    sNode *new_node = new sNode;
    if (new_node == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        new_node->data = data;
        new_node->next = *top_ref;
        *top_ref = new_node;
    }
}

int pop(sNode **top_ref)
{
    char c;
    sNode *top;
    if (*top_ref == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        top = *top_ref;
        c = top->data;
        *top_ref = top->next;
        free(top);
        return c;
    }
}

int isMatchingPair(char c1, char c2)
{
    if (c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']')
        return 1;
    return 0;
}

int isBalanced(string exp)
{
    int i = 0;
    sNode *stack = NULL;
    while (exp[i])
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&stack, exp[i]);
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (stack == NULL)
                return 0;
            else if (!isMatchingPair(pop(&stack), exp[i]))
                return 0;
        }
        i++;
    }
    if (stack == NULL)
        return 1;
    return 0;
}
int main()
{
    string s = "fksdldsjfkdsfj(((())))";
    if (isBalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;
    return 0;
}