#include<stdio.h>
#include<stdlib.h>

struct SLL_NODE {
    int data;
    struct SLL_NODE *link;
};

typedef struct SLL_NODE SL_NODE;

// SL_NODE *SL_head = (SL_NODE*)malloc(sizeof(struct SLL_NODE));
SL_NODE *SL_head = NULL;

SL_NODE *SL_getnode(int ele){
    SL_NODE *newnode = (SL_NODE*)malloc(sizeof(struct SLL_NODE));
    if(newnode == NULL){
        printf("Memory Not Allocated.");
    }
    newnode->data=ele;
    newnode->link=NULL;
    return newnode;
}

SL_NODE *SL_insertfront(SL_NODE *SL_head,int ele){
    SL_NODE *newnode = SL_getnode(ele);
    newnode->link = SL_head;
    SL_head = newnode;
    return SL_head;
}

SL_NODE *SL_insertend(SL_NODE *SL_head,int ele){
    SL_NODE *current,*newnode = SL_getnode(ele);
    current = SL_head;
    if(SL_head==NULL){
        return newnode;
    }
    while(current->link!=NULL){
        current = current->link;
    }
    current->link = newnode;
    return SL_head;
}

SL_NODE *SL_insertpos(SL_NODE *SL_head, int ele , int pos){
    SL_NODE *newnode = SL_getnode(ele);
    if(pos == 1){
        newnode->link = SL_head;
        return newnode;
    }
    SL_NODE *current = SL_head;
    int i = 1;
    while(current != NULL && i< pos){
        current = current -> link;
        i++;
    }
    if(current == NULL){
        printf("No position.");
        return SL_head;
    }
    newnode->link=current->link;
    current->link=newnode;
    return SL_head;
}

SL_NODE *SL_deletefront(SL_NODE *SL_head){
    if(SL_head->link==NULL){
        printf("List is empty.");
        return NULL;
    }
    SL_NODE *current = SL_head->link;
    free(SL_head);
    SL_head=current;
    return SL_head;
}

SL_NODE *SL_deleteEnd(SL_NODE *SL_head){
    if(SL_head->link==NULL){
        printf("List is empty.");
        return NULL;
    }
    SL_NODE *current,*prev;
    current = SL_head;
    prev = NULL;
    while(current->link!=NULL){
        prev=current;
        current=current->link;
    }
    free(current);
    prev->link=NULL;
    return SL_head;
}

SL_NODE *SL_Delete(SL_NODE *SL_head,int pos){
    if(SL_head==NULL){
        printf("List is empty.");
        return NULL;
    }
    if(pos==0){
        SL_NODE *temp = SL_head;
        SL_head = SL_head->link;
        free(temp);
        return SL_head;
    }
    SL_NODE *prev = NULL , *cur = SL_head;
    int i = 0;
    while(i<pos && cur!=NULL){
        prev = cur;
        cur = cur -> link;
        i++;
    }
    if(cur == NULL){
        return SL_head;
    }
    prev -> link = cur -> link;
    free(cur);
    return SL_head;
}

void SL_Reverse_print(SL_NODE *SL_head){
    SL_NODE *current=SL_head,*next=NULL,*prev=NULL;
    if(SL_head==NULL){
        printf("List is empty. \n");
    }
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    current = prev;
    while(current!=NULL){
        printf("%d",current->data);
        current = current->link;
    }
    printf("\n");
}

int SL_sumofnodes(SL_NODE *SL_head){
    int sum = 0 ;
    SL_NODE *current = SL_head;
    while(current!=NULL){
        sum += current->data;
        current=current->link;
    }
    return sum;
}

int SL_count(SL_NODE *SL_head){
    int count = 0;
    SL_NODE *current = SL_head;
    while(current!=NULL){
        count++;
        current=current->link;
    }
    return count;
}

int SL_search_for_pos(SL_NODE *SL_head,int ele){
    int pos = 1;
    SL_NODE *current = SL_head;
    while(current!=NULL){
        if(current->data==ele){
            return pos;
        }
        current = current->link;
        pos++;
    }
    return -1;
}

void SL_display(SL_NODE *SL_head){
    SL_NODE *current = SL_head;
    while(current!=NULL){
        printf("%d ",current->data);
        current = current->link;
    }
    printf("\n");
}