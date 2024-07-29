#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE First, PNODE Last)
{
    if((First == NULL) && (Last == NULL))
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        printf("| %d |->",First->data);
        First = First->next;
    }while(First != Last->next);

    printf("\n"); 
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;

    if((First == NULL) && (Last == NULL))
    {
        printf("List is Empty\n");
        return -1;
    }

    do
    {
        iCnt++;
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
    (*Last)->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
}

void InsertAtPos(PPNODE First, PPNODE Last, int No, int iPos)
{
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;

    iLength = Count(*First, *Last);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, Last, No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First, Last, No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        temp = *First;

        for(i = 1; i < iPos-1; i++)
        {
	        temp = temp->next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("LL is Empty");
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*Last)->next);
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("LL is Empty");
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *First;

        while(temp->next != *Last)
        {
            temp = temp->next;
        }

        free(*Last);
        *Last = temp;
        (*Last)->next = *First;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    int iLength = 0;
    int i = 0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    iLength = Count(*First, *Last);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if(iPos == iLength)
    {
        DeleteLast(First, Last);
    }
    else
    {
        temp1 = *First;

        for(i = 1; i < iPos -1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next;

        temp1->next = temp2 -> next;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);

    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail,111);
    InsertLast(&Head, &Tail, 121);

    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of Nodes are : %d\n",iRet);

    InsertAtPos(&Head, &Tail, 105, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of Nodes are : %d\n",iRet);

    DeleteAtPos(&Head, &Tail, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of Nodes are : %d\n",iRet);
}