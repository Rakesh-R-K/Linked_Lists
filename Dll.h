#include <stdio.h>
#include <stdlib.h>

struct DLL_NODE{
    int data;
    struct DLL_NODE *rlink, *llink;
};

typedef struct DLL_NODE DL_NODE;

// DL_NODE *DL_head = (DL_NODE *)malloc(sizeof(struct DLL_NODE));
DL_NODE *DL_head = NULL;

DL_NODE *getnode(int ele)
{
    DL_NODE *newnode = (DL_NODE *)malloc(sizeof(struct DLL_NODE));
    if (newnode == NULL)
    {
        printf("Memory Not Allocated");
    }
    newnode->data = ele;
    newnode->llink = newnode->rlink = NULL;
    return newnode;
}

DL_NODE *DL_insertfront(DL_NODE *DL_head, int ele)
{
    DL_NODE *temp = getnode(ele);
    if (DL_head == NULL)
    {
        temp->rlink = temp->llink = NULL;
        DL_head = temp;
    }
    DL_NODE *current = DL_head;
    temp->llink = NULL;
    temp->rlink = current;
    current->llink = temp;
    DL_head = temp;
    return DL_head;
}

DL_NODE *DL_insertend(DL_NODE *DL_head, int ele)
{
    DL_NODE *temp = getnode(ele);
    if (DL_head == NULL)
    {
        temp->rlink = temp->llink = NULL;
        DL_head = temp;
    }
    DL_NODE *current = DL_head;
    while (current->rlink != NULL)
    {
        current = current->rlink;
    }
    current->rlink = temp;
    temp->llink = current;
    temp->rlink = NULL;
    return DL_head;
}

DL_NODE *DL_insertpos(DL_NODE *DL_head, int ele, int pos)
{
    DL_NODE *temp = getnode(ele);
    if (DL_head == NULL)
    {
        temp->rlink = temp->llink = NULL;
        DL_head = temp;
    }
    if (pos == 1)
    {
        DL_head = DL_insertfront(DL_head, ele);
    }
    int count = 1;
    DL_NODE *previous = NULL, *current = DL_head;
    while (current != NULL && count != pos)
    {
        previous = current;
        current = current->rlink;
        count++;
    }
    if (count == pos)
    {
        previous->rlink = temp;
        temp->llink = previous;
        temp->rlink = current;
        current->llink = temp;
    }
    else
    {
        printf("Sorry, Can't Fool Me With Invalid Position.");
    }
    return DL_head;
}

DL_NODE *DL_deletefront(DL_NODE *DL_head)
{
    DL_NODE *current;
    if (DL_head == NULL)
    {
        printf("List is empty.");
        return NULL;
    }
    else if (DL_head->rlink == NULL)
    {
        current = DL_head;
        free(DL_head);
        return NULL;
    }
    else
    {
        current = DL_head;
        current = current->rlink;
        current->llink = NULL;
        free(DL_head);
        DL_head = current;
    }
    return DL_head;
}

DL_NODE *DL_deleteend(DL_NODE *DL_head){
    DL_NODE *current = DL_head , *previous = NULL;
    if(DL_head == NULL){
        printf("List is empty. \n");
        return NULL;
    }
    else if(DL_head->rlink == NULL){
        current = DL_head;
        free(DL_head);
        return NULL;
    }
    else { 
        while(current -> rlink != NULL){
            previous = current;
            current = current -> rlink;
        }
        previous -> rlink = NULL;
        current -> llink = NULL;
        free(current);
    }
    return DL_head;
}

DL_NODE *DL_deletepos(DL_NODE *DL_head , int pos){
    if(DL_head == NULL){
        printf("Empty List.\n");
        return DL_head;
    }
    DL_NODE *current = DL_head , *previous = NULL , *next = NULL;
    if(DL_head -> rlink == NULL && pos == 1){
        free(DL_head);
        return NULL;
    }
    int count = 1;
    while(current!=NULL && count < pos){
        previous = current;
        current = current -> rlink;
        count++;
    }
    if(current != NULL && count==pos){
        next = current -> rlink;
        previous -> rlink = next;
        next -> llink = previous;
        free(current);
    }
    else{
        printf("Sorry, Can't Fool Me With Invalid Position.");
    }
    return DL_head;
}

void DL_Reverse_print(DL_NODE *DL_head){
    if(DL_head == NULL){
        printf("List is empty. \n");
        return;
    }
    DL_NODE *current = DL_head;
    while(current->rlink!=NULL){
        current = current -> rlink;
    }
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->llink;
    }
    printf("\n");
}

int DL_sumofnodes(DL_NODE *DL_head){
    int sum=0;
    DL_NODE *current = DL_head;
    while(current!=NULL){
        sum += current->data;
        current = current ->rlink;
    }
    return sum;
}

int DL_count(DL_NODE *DL_head){
    int count = 0;
    DL_NODE *current = DL_head;
    while(current!=NULL){
        count++;
        current=current->rlink;
    }
    return count;
}

int DL_search(DL_NODE *DL_head, int ele){
    int pos = 1;
    DL_NODE *current = DL_head;
    while(current!=NULL){
        if(current->data==ele){
            return pos;
        }
        current = current->rlink;
        pos++;
    }
    return -1;
}

void DL_display(DL_NODE *DL_head){
    DL_NODE *current = DL_head;
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->rlink;
    }
}