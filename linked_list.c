#include <stdio.h>
#include <stdlib.h>
#include "Sll.h"
#include "Dll.h"
#include "Cll.h"

int main()
{
    int choice1, choice2, choice3, pos_ele, ins_ele, ins_pos, del_pos;
    printf("\nLet's Get Started with the Journey...!! \n");
    do
    {
        printf("Which list are you working on ? \n");
        printf("#1 Singly linked list . \n");
        printf("#2 Doubly linked list . \n");
        printf("#3 Circular Singly linked list . \n");
        printf("#4 Circular Doubly linked list . \n");
        printf("#5 Queue implemenetation from Singly Linked Lists . \n");
        printf("#6 Stack implemenetation from Singly Linked Lists . \n");
        printf("#7 Sum of two polynomials from Singly Linked List Representation . \n");
        printf("#8 Concatenation of two lists using Singly Linked List . \n");
        printf("#9 Enough of this stuff . \n");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
        {
            printf("What do you want to do in Singly Linked List ? \n");
            do
            {
                printf("#1 Insertion... \n");
                printf("#2 Deletion ... \n");
                printf("#3 Reverse and print ... \n");
                printf("#4 Give the sum of the nodes ... \n");
                printf("#5 Count the number of nodes present ...\n");
                printf("#6 Search a given element in the list and return the node position ... \n");
                printf("#7 Display the elements of the linked list ... \n");
                printf("#8 Exit from Singly Linked list ... \n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                {
                    do
                    {
                        printf("#1 Insert at front ? \n");
                        printf("#2 Insert at end ? \n");
                        printf("#3 Insert at a position ? \n");
                        printf("#4 Enough of Insertion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            SL_head = SL_insertfront(SL_head, ins_ele);
                            printf("Element %d inserted at the beginning.", ins_ele);
                            break;
                        }
                        case 2:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            SL_head = SL_insertend(SL_head, ins_ele);
                            printf("Element %d inserted at the end.", ins_ele);
                            break;
                        }
                        case 3:
                        {
                            printf("Enter element to be inserted : \n");
                            scanf("%d", &ins_ele);
                            printf("Enter position to be inserted : \n");
                            scanf("%d", &ins_pos);
                            SL_head = SL_insertpos(SL_head, ins_ele, ins_pos);
                            printf("Element %d inserted at the position %d.", ins_ele, ins_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 2:
                {
                    do
                    {
                        printf("#1 Delete at front ? \n");
                        printf("#2 Delete at end ? \n");
                        printf("#3 Delete at a position ? \n");
                        printf("#4 Enough of Deletion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            SL_head = SL_deletefront(SL_head);
                            printf("First element deleted ...");
                            break;
                        }
                        case 2:
                        {
                            SL_head = SL_deleteEnd(SL_head);
                            printf("Last element deleted ...");
                            break;
                        }
                        case 3:
                        {
                            printf("Enter the position for element to be deleted : \n");
                            scanf("%d", &del_pos);
                            SL_head = SL_Delete(SL_head, del_pos);
                            printf("Element at position %d deleted ...", del_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 3:
                {
                    printf("Given list is : \n");
                    SL_display(SL_head);
                    printf("After Reversing : \n");
                    SL_Reverse_print(SL_head);
                    break;
                }
                case 4:
                {
                    printf("The sum of all nodes : %d \n", SL_sumofnodes(SL_head));
                    break;
                }
                case 5:
                {
                    printf("Count of nodes : %d \n", SL_count(SL_head));
                    break;
                }
                case 6:
                {
                    printf("Enter the element to be searched : \n");
                    scanf("%d", &pos_ele);
                    printf("The position in which element is found is : %d \n", SL_search_for_pos(SL_head, pos_ele));
                    break;
                }
                case 7:
                {
                    printf("Elements of Singly Linked List : \n");
                    SL_display(SL_head);
                    break;
                }
                } // switch case choice2; SINGLy linked list
            } while (choice2 != 8);
            break;
        }
        case 2:
        {
            printf("What do you want to do in Doubly Linked List ? \n");
            do
            {
                printf("#1 Insertion... \n");
                printf("#2 Deletion ... \n");
                printf("#3 Reverse and print ... \n");
                printf("#4 Give the sum of the nodes ... \n");
                printf("#5 Search a given element in the list and return the node position ... \n");
                printf("#6 Count the number of nodes ... \n");
                printf("#7 Display the elements of the linked list ... \n");
                printf("#8 Exit from Doubly Linked list ... \n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                {
                    do
                    {
                        printf("#1 Insert at front ? \n");
                        printf("#2 Insert at end ? \n");
                        printf("#3 Insert at a position ? \n");
                        printf("#4 Enough of Insertion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            DL_head = DL_insertfront(DL_head, ins_ele);
                            printf("Element %d inserted at the beginning.", ins_ele);
                            break;
                        }
                        case 2:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            DL_head = DL_insertend(DL_head, ins_ele);
                            printf("Element %d inserted at the end.", ins_ele);
                            break;
                        }
                        case 3:
                        {
                            printf("Enter element to be inserted : \n");
                            scanf("%d", &ins_ele);
                            printf("Enter position to be inserted : \n");
                            scanf("%d", &ins_pos);
                            DL_head = DL_insertpos(DL_head, ins_ele, ins_pos);
                            printf("Element %d inserted at the position %d.", ins_ele, ins_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 2:
                {
                    do
                    {
                        printf("#1 Delete at front ? \n");
                        printf("#2 Delete at end ? \n");
                        printf("#3 Delete at a position ? \n");
                        printf("#4 Enough of Deletion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            DL_head = DL_deletefront(DL_head);
                            printf("First element deleted ...");
                            break;
                        }
                        case 2:
                        {
                            DL_head = DL_deleteend(DL_head);
                            printf("Last element deleted ...");
                            break;
                        }
                        case 3:
                        {
                            printf("Enter the position for element to be deleted : \n");
                            scanf("%d", &del_pos);
                            DL_head = DL_deletepos(DL_head, del_pos);
                            printf("Element at position %d deleted ...", del_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 3:
                {
                    printf("Given list is : \n");
                    DL_display(DL_head);
                    printf("After Reversing : \n");
                    DL_Reverse_print(DL_head);
                    break;
                }
                case 4:
                {
                    printf("The sum of all nodes : %d \n", DL_sumofnodes(DL_head));
                    break;
                }
                case 5:
                {
                    printf("Count of nodes : %d \n", DL_count(DL_head));
                    break;
                }
                case 6:
                {
                    printf("Enter the element to be searched : \n");
                    scanf("%d", &pos_ele);
                    printf("The position in which element is found is : %d \n", DL_search(DL_head, pos_ele));
                    break;
                }
                case 7:
                {
                    printf("Elements of Doubly Linked List : \n");
                    DL_display(DL_head);
                    break;
                }
                }
            } while (choice2 != 8);
            break;
        }
        case 3:
        {
            printf("What do you want to do in Circular Singly Linked List ? \n");
            do
            {
                printf("#1 Insertion... \n");
                printf("#2 Deletion ... \n");
                printf("#3 Give the sum of the nodes ... \n");
                printf("#4 Search a given element in the list and return the node position ... \n");
                printf("#5 Count the number of nodes ... \n");
                printf("#6 Display the elements of the linked list ... \n");
                printf("#7 Exit from Circular Singly Linked list ... \n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                {
                    do
                    {
                        printf("#1 Insert at front ? \n");
                        printf("#2 Insert at end ? \n");
                        printf("#3 Insert at a position ? \n");
                        printf("#4 Enough of Insertion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            CSL_head = CSL_insertfront(CSL_head, ins_ele);
                            printf("Element %d inserted at the beginning.", ins_ele);
                            break;
                        }
                        case 2:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            CSL_head = CSL_insertend(CSL_head, ins_ele);
                            printf("Element %d inserted at the end.", ins_ele);
                            break;
                        }
                        case 3:
                        {
                            printf("Enter element to be inserted : \n");
                            scanf("%d", &ins_ele);
                            printf("Enter position to be inserted : \n");
                            scanf("%d", &ins_pos);
                            CSL_head = CSL_insertpos(CSL_head, ins_ele, ins_pos);
                            printf("Element %d inserted at the position %d.", ins_ele, ins_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 2:
                {
                    do
                    {
                        printf("#1 Delete at front ? \n");
                        printf("#2 Delete at end ? \n");
                        printf("#3 Delete at a position ? \n");
                        printf("#4 Enough of Deletion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            CSL_head = CSL_deletefront(CSL_head);
                            printf("First element deleted ...");
                            break;
                        }
                        case 2:
                        {
                            CSL_head = CSL_deleteend(CSL_head);
                            printf("Last element deleted ...");
                            break;
                        }
                        case 3:
                        {
                            printf("Enter the position for element to be deleted : \n");
                            scanf("%d", &del_pos);
                            CSL_head = CSL_deletepos(CSL_head, del_pos);
                            printf("Element at position %d deleted ...", del_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 3:
                {
                    printf("The sum of nodes : %d \n", CSL_sumofnodes(CSL_head));
                    break;
                }
                case 4:
                {
                    printf("Enter the element to be searched : \n");
                    scanf("%d", &pos_ele);
                    printf("The position in which element is found is : %d \n", CSL_search(CSL_head, pos_ele));
                    break;
                }
                case 5:
                {
                    printf("Count of nodes : %d \n", CSL_count(CSL_head));
                    break;
                }
                case 6:
                {
                    printf("Elements of Circular Singly Linked List : \n");
                    CSL_display(CSL_head);
                    break;
                }
                } // switch(choice2) CSL
            } while (choice2 != 7);
            break;
        }
        case 4:
        {
            printf("What do you want to do in Circular Doubly Linked List ? \n");
            do
            {
                printf("#1 Insertion... \n");
                printf("#2 Deletion ... \n");
                printf("#3 Reverse and print ... \n");
                printf("#4 Display the elements of the linked list ... \n");
                printf("#5 Exit from Circular Doubly Linked list ... \n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                {
                    do
                    {
                        printf("#1 Insert at front ? \n");
                        printf("#2 Insert at end ? \n");
                        printf("#3 Insert at a position ? \n");
                        printf("#4 Enough of Insertion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            CDL_head = CDL_insertfront(CDL_head, ins_ele);
                            printf("Element %d inserted at the beginning.", ins_ele);
                            break;
                        }
                        case 2:
                        {
                            printf("Enter element to insert : \n");
                            scanf("%d", &ins_ele);
                            CDL_head = CDL_insertend(CDL_head, ins_ele);
                            printf("Element %d inserted at the end.", ins_ele);
                            break;
                        }
                        case 3:
                        {
                            printf("Enter element to be inserted : \n");
                            scanf("%d", &ins_ele);
                            printf("Enter position to be inserted : \n");
                            scanf("%d", &ins_pos);
                            CDL_head = CDL_insertatpos(CDL_head, ins_ele, ins_pos);
                            printf("Element %d inserted at the position %d.", ins_ele, ins_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                }
                case 2:
                {
                    do
                    {
                        printf("#1 Delete at front ? \n");
                        printf("#2 Delete at end ? \n");
                        printf("#3 Delete at a position ? \n");
                        printf("#4 Enough of Deletion. \n");
                        scanf("%d", &choice3);
                        switch (choice3)
                        {
                        case 1:
                        {
                            CDL_head = CDL_deletefront(CDL_head);
                            printf("First element deleted ...");
                            break;
                        }
                        case 2:
                        {
                            CDL_head = CDL_deleteend(CDL_head);
                            printf("Last element deleted ...");
                            break;
                        }
                        case 3:
                        {
                            printf("Enter the position for element to be deleted : \n");
                            scanf("%d", &del_pos);
                            CDL_head = CDL_deletepos(CDL_head, del_pos);
                            printf("Element at position %d deleted ...", del_pos);
                            break;
                        }
                        }
                    } while (choice3 != 4);
                    break;
                } // case2 cdl
                case 3:
                {
                    printf("Given list is : \n");
                    CDL_displayList(CDL_head);
                    printf("After Reversing : \n");
                    CDL_head = CDL_reverseList(CDL_head);
                    CDL_displayList(CDL_head);
                    break;
                }
                case 4:
                {
                    printf("Elements of Circular Doubly Linked List : \n");
                    CDL_displayList(CDL_head);
                }
                }
            } while (choice2 != 5);
            break;
        }
        case 5:
        {
            // Queue Implementation
            int choice, ele;
            SL_NODE *SL_queuehead = NULL;
            printf("Queue implementation using singly linked list\n");
            do
            {
                printf("1.InsertFront \n2.Display \n3.DeleteRare \n4.Exit\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter an integer : ");
                    scanf("%d", &ele);
                    SL_queuehead = SL_insertfront(SL_queuehead, ele);
                    break;
                case 2:
                    SL_display(SL_queuehead);
                    printf("\n");
                    break;
                case 3:
                    if (SL_queuehead != NULL)
                    {
                        SL_queuehead = SL_deleteEnd(SL_queuehead);
                        printf("Element deleted... \n");
                    }
                    else
                    {
                        printf("Stack is empty\n");
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
            } while (choice != 4);
            break;
        }
        case 6:
        {
            // Stack Implementation
            int choice_s,ele_s;
            SL_NODE *SL_stackhead = NULL;
            do
            {
                printf("1.InsertFront \n2.Display \n3.DeleteFront \n4.Exit\n");
                scanf("%d", &choice_s); 
                switch (choice_s)
                {
                case 1:
                    printf("Enter an integer : ");
                    scanf("%d", &ele_s); 
                    SL_stackhead = SL_insertfront(SL_stackhead, ele_s);
                    break;
                case 2:
                    SL_display(SL_stackhead);
                    break;
                case 3:
                    if (SL_stackhead != NULL)
                    {
                        SL_stackhead = SL_deletefront(SL_stackhead);
                        printf("Deleted element is %d\n", ele_s);
                    }
                    else
                    {
                        printf("Stack is empty\n");
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
            } while (choice_s != 4);
            break;
        }
        case 7:
        {
            // Sum of two polynomials
            break;
        }
        case 8:
        {
            // Concatenation using singly linked lists
            break;
        }
        case 9:
        {
            printf("Thank you for using this mini(mini-project)\n");
            printf("Done by Rakesh R K");
            break;
        }
        } // switch choice1
    } while (choice1 != 9); // dowhile
} // main