#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void display(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
// Insertion methods
void insertAtFirst(node **head, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void insertAfterNode(node *given_node, int data)
{
    if (given_node == NULL)
        return;
    node *new_node = new node();
    new_node->data = data;
    new_node->next = given_node->next;
    given_node->next = new_node;
}
void insertAtLast(node **head_ref, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    node *traveler_node = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (traveler_node->next != NULL)
    {
        traveler_node = traveler_node->next;
    }
    traveler_node->next = new_node;
    return;
}

// Deletion methods
void deleteFromFirst(node **head_ref)
{
    node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    delete temp;
}
void deleteFromLast(node *head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    node *second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    delete second_last->next;
    second_last->next = NULL;
}
void deleteFromMiddle(node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    node *temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void deleteWithKey(node **head_ref, int key)
{
    node *temp = *head_ref;
    node *prev = NULL;
    if (*head_ref != NULL && (*head_ref)->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
}


int main()
{
    node *head = new node();
    head->data = 1;

    // Insertion methods:-
    // insertAtFirst(&head,12);
    // insertAfterNode(second,44);
    // insertAtLast(&head,44);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    // Deletion methods:-
    // deleteFromFirst(&head);
    // deleteFromLast(head);
    // deleteFromMiddle(&head,1);
    // deleteWithKey(&head,4);
    display(head);

    return 0;
}