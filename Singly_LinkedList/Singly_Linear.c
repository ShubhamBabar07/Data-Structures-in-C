#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First, int NO)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = NO;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }

}

void InsertLast(PPNODE First, int NO)
{
    PNODE newn = NULL;
    PNODE temp = *First;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = NO;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp ->next = newn;
    }
    
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("|%d|->",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}


void DeleteFirst(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Unable to delete\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First == NULL;
    }
    else
    {
        temp = *First;
        *First = (*First)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Unable to delete\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First == NULL;
    }
    else
    {
        temp = *First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First, int No, int iPos)
{
    PNODE newn = NULL;
    int iLength = 0;
    PNODE temp = NULL;
    int i = 0;

    iLength = Count(*First);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First, No);
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

void DeleteAtPos(PPNODE First, int iPos)
{
    int iLength = 0;

    iLength = Count(*First);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iLength)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE temp1 = *First;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }

        PNODE temp2 = temp1->next;

        temp1->next = temp1->next->next;    // temp1->next = temp2->next;
        free(temp2);
    }

}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    InsertLast(&Head, 101);
    InsertLast(&Head, 111);
    InsertLast(&Head, 121);
    InsertLast(&Head, 151);

    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    InsertAtPos(&Head, 105, 5);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head, 5);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements are : %d\n",iRet);

    return 0;
}