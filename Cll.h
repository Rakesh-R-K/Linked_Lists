#include<stdio.h>
#include<stdlib.h>

struct CSL_NODE{
    int data;
    struct CSL_NODE *link;
};

struct CDL_NODE{
    int data;
    struct CDL_NODE *prev , *next;
};

typedef struct CDL_NODE CDL_NODE;
typedef struct CSL_NODE CSL_NODE;

CDL_NODE *CDL_head = NULL;
CSL_NODE *CSL_head = NULL;


CSL_NODE* CSL_getnode(int ele){
    CSL_NODE *newnode = (CSL_NODE*)malloc(sizeof(CSL_NODE));
    if (newnode == NULL) {
        printf("Memory Not Allocated.\n");
        exit(0);
    }
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

CSL_NODE* CSL_insertfront(CSL_NODE *CSL_head, int ele) {
    CSL_NODE *newnode = CSL_getnode(ele);
    if (CSL_head == NULL) {
        newnode->link = newnode;  // Single node points to itself
        return newnode;
    }
    CSL_NODE *current = CSL_head;
    while (current->link != CSL_head) {
        current = current->link;
    }
    newnode->link = CSL_head;
    current->link = newnode;
    return newnode;  // New node becomes the new CSL_head
}

CSL_NODE* CSL_insertend(CSL_NODE *CSL_head, int ele) {
    CSL_NODE *newnode = CSL_getnode(ele);
    if (CSL_head == NULL) {
        newnode->link = newnode;
        return newnode;
    }
    CSL_NODE *current = CSL_head;
    while (current->link != CSL_head) {
        current = current->link;
    }
    current->link = newnode;
    newnode->link = CSL_head;
    return CSL_head;
}

CSL_NODE* CSL_insertpos(CSL_NODE *CSL_head, int ele, int pos) {
    CSL_NODE *newnode = CSL_getnode(ele);
    if (pos == 1) {
        return CSL_insertfront(CSL_head, ele);  // Insert at the front
    }
    CSL_NODE *current = CSL_head;
    int i = 1;
    while (current->link != CSL_head && i < pos - 1) {
        current = current->link;
        i++;
    }
    if (i == pos - 1) {
        newnode->link = current->link;
        current->link = newnode;
    } else {
        printf("Invalid position.\n");
    }
    return CSL_head;
}

CSL_NODE* CSL_deletefront(CSL_NODE *CSL_head) {
    if (CSL_head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    CSL_NODE *current = CSL_head;
    if (CSL_head->link == CSL_head) {  // Only one node in the list
        free(CSL_head);
        return NULL;
    }
    while (current->link != CSL_head) {
        current = current->link;
    }
    CSL_NODE *temp = CSL_head;
    current->link = CSL_head->link;
    CSL_head = CSL_head->link;
    free(temp);
    return CSL_head;
}

CSL_NODE* CSL_deleteend(CSL_NODE *CSL_head) {
    if (CSL_head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    CSL_NODE *current = CSL_head, *prev = NULL;
    if (CSL_head->link == CSL_head) {  // Only one node in the list
        free(CSL_head);
        return NULL;
    }
    while (current->link != CSL_head) {
        prev = current;
        current = current->link;
    }
    prev->link = CSL_head;
    free(current);
    return CSL_head;
}

CSL_NODE* CSL_deletepos(CSL_NODE *CSL_head, int pos) {
    if (CSL_head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (pos == 1) {
        return CSL_deletefront(CSL_head);  // Special case for first position
    }
    CSL_NODE *current = CSL_head, *prev = NULL;
    int i = 1;
    while (current->link != CSL_head && i < pos) {
        prev = current;
        current = current->link;
        i++;
    }
    if (i == pos) {
        prev->link = current->link;
        free(current);
    } else {
        printf("Invalid position.\n");
    }
    return CSL_head;
}

int CSL_sumofnodes(CSL_NODE *CSL_head){
    if(CSL_head == NULL){
        return 0;
    }
    int sum = 0;
    CSL_NODE *current = CSL_head;
    while(current->link!=CSL_head){
        sum+=current->data;
        current=current->link;
    }
    sum+=current->data;
    return sum;
}

int CSL_search(CSL_NODE *CSL_head, int ele){
    if(CSL_head==NULL){
        return -1;
    }
    CSL_NODE *current = CSL_head;
    int pos = 1;
    while(current->link != CSL_head){
        if(current->data==ele){
            return pos;
        }
        current = current -> link;
        pos++;
    }
    if(current->data==ele){
        return pos;
    }
    return -1;
}

int CSL_count(CSL_NODE *CSL_head){
    if(CSL_head==NULL){
        return 0;
    }
    CSL_NODE *current = CSL_head;
    int count = 1;
    while(current->link!=CSL_head){
        current = current->link;
        count++;
    }
    return count;
}

void CSL_display(CSL_NODE *CSL_head) {
    if (CSL_head == NULL) {
        printf("List is empty.\n");
        return;
    }
    CSL_NODE *current = CSL_head;
    do {
        printf("%d ", current->data);
        current = current->link;
    } while (current != CSL_head);
    printf("\n");
}

CDL_NODE* CDL_getnode(int ele){
    CDL_NODE* newnode = (CDL_NODE*)malloc(sizeof(CDL_NODE));
    newnode->data = ele;
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

CDL_NODE* CDL_insertfront(CDL_NODE *CDL_head, int ele){
    CDL_NODE* newnode = CDL_getnode(ele);
    if(CDL_head == NULL){
        return newnode;
    }
    else{
        CDL_NODE* last = CDL_head -> prev;
        newnode -> next = CDL_head;
        newnode -> prev = last;
        last -> next = newnode;
        CDL_head -> prev = newnode;
        return newnode;
    }
}

CDL_NODE* CDL_insertend(CDL_NODE *CDL_head, int ele){
    CDL_NODE* newnode = CDL_getnode(ele);
    if(CDL_head == NULL){
        return newnode;
    }
    else{
        CDL_NODE* last = CDL_head -> prev;
        newnode -> next = CDL_head;
        newnode -> prev = last;
        last -> next = newnode;
        CDL_head -> prev = newnode;
        return newnode;
    }
}

CDL_NODE* CDL_insertatpos(CDL_NODE *CDL_head,int ele, int pos){
    if(pos == 1){
        return CDL_insertfront(CDL_head,ele);
    }
    CDL_NODE* newnode = CDL_getnode(ele);
    CDL_NODE* temp = CDL_head;
    for(int i = 1 ; i < pos - 1 ; i++){
        temp = temp -> next;
        if(temp == CDL_head){
            printf("Invalid Position.\n");
            free(newnode);
            return CDL_head;
        }
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    return CDL_head;
}

CDL_NODE* CDL_deletefront(CDL_NODE *CDL_head){
    if (CDL_head == NULL) return NULL;
    CDL_NODE* temp = CDL_head;
    if (temp->next == temp) { // Only one node
        free(temp);
        return NULL;
    } else {
        CDL_NODE* last = temp->prev;
        CDL_head = temp->next;
        CDL_head->prev = last;
        last->next = CDL_head;
        free(temp);
        return CDL_head;
    }
}

CDL_NODE* CDL_deleteend(CDL_NODE* CDL_head) {
    if (CDL_head == NULL) return NULL;
    CDL_NODE* temp = CDL_head->prev;
    if (temp == CDL_head) { // Only one node
        free(temp);
        return NULL;
    } else {
        CDL_NODE* newLast = temp->prev;
        newLast->next = CDL_head;
        CDL_head->prev = newLast;
        free(temp);
        return CDL_head;
    }
}

CDL_NODE* CDL_deletepos(CDL_NODE* CDL_head, int position) {
    if (CDL_head == NULL) return NULL;
    if (position == 1) {
        return CDL_deletefront(CDL_head);
    }
    CDL_NODE* temp = CDL_head;
    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == CDL_head) {
            printf("Position out of bounds\n");
            return CDL_head;
        }
    }
    if (temp->next == temp) { // Only one node
        free(temp);
        return NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == CDL_head) CDL_head = temp->next;
        free(temp);
        return CDL_head;
    }
}

CDL_NODE* CDL_reverseList(CDL_NODE* CDL_head) {
    if (CDL_head == NULL) return NULL;
    CDL_NODE *temp = CDL_head, *prev = NULL, *next = NULL;
    do {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    } while (temp != CDL_head);
    CDL_head = prev;
    CDL_head->prev->next = CDL_head; 
    CDL_head->prev = prev->prev;
    return CDL_head;
}

void CDL_displayList(CDL_NODE* CDL_head) {
    if (CDL_head == NULL) return;
    CDL_NODE* temp = CDL_head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != CDL_head);
    printf("\n");
}