#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE First, PNODE Last)
{
    if((First == NULL) && (Last == NULL))
    {
        printf("Linked list is Empty\n");
        return;
    }

    printf("\n<=>");
    do
    {
        printf("| %d |<=>",First->data);
        First = First->next;
    }while(Last->next != First);

    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;

    if((First == NULL) && (Last == NULL))
    {
        return -1;
    }

    do
    {
        iCnt++;
        First = First->next;
    }while(Last->next != First);

    return iCnt;
}

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        (*First) ->prev = newn;
        *First = newn;
    }

    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
    }

    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void InsertAtPos(PPNODE First, PPNODE Last, int No, int iPos)
{
    int iLength = 0;
    iLength = Count(*First, *Last);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, Last, No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First,Last, No);
    }
    else
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL; 

        PNODE temp = *First;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("Unable to delete as LL empty");
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
        free((*First)->prev);
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("Unable to delete as LL empty");
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
       *Last = (*Last)->prev;
       free((*First)->prev);
       (*Last)->next = *First;
       (*First)->prev = *Last;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    int iLength = 0;
    iLength = Count(*First, *Last);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
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
        PNODE temp = *First;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp ->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;

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
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    InsertLast(&Head, &Tail, 151);

    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of elements are : %d\n",iRet);

    InsertAtPos(&Head, &Tail, 105, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head, &Tail, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of elements are : %d\n",iRet);

    return 0;
}