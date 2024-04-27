#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev,*next;
};
struct Node* createNode(int data) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertAtStart(struct Node** head,int data) {
    struct Node*newNode=createNode(data);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}
void insertAtEnd(struct Node**head,int data) {
    struct Node*newNode=createNode(data);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    struct Node*temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if (position<1) {
        printf("Invalid position\n");
        return;
    }
    if (position==1) {
        insertAtStart(head,data);
        return;
    }
    struct Node*newNode=createNode(data);
    struct Node*temp=*head;
    for (int i=1;i<position-1&&temp!=NULL;i++)
        temp=temp->next;
    if (temp==NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next=temp->next;
    if (temp->next!=NULL)
        temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void traverse(struct Node* head) {
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void deleteNode(struct Node** head,struct Node* nodeToDelete) {
    if (*head==NULL||nodeToDelete==NULL)
        return;
    if (*head==nodeToDelete)
        *head=(*head)->next;
    if (nodeToDelete->next!=NULL)
        nodeToDelete->next->prev=nodeToDelete->prev;
    if (nodeToDelete->prev!=NULL)
        nodeToDelete->prev->next=nodeToDelete->next;
    free(nodeToDelete);
}
void deleteList(struct Node** head) {
    struct Node* current=*head;
    struct Node* next;
    while (current!=NULL) {
        next=current->next;
        free(current);
        current=next;
    }
    *head=NULL;
}
int main() {
    struct Node* head=NULL;
    insertAtStart(&head, 3);
    insertAtStart(&head, 1);
    insertAtEnd(&head, 5);
    insertAtPosition(&head, 2, 2);
    printf("Original list: ");
    traverse(head);
    deleteNode(&head, head->next->next);
    printf("List after deletion: ");
    traverse(head);
    deleteList(&head);

    return 0;
}