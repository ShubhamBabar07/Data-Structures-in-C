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


void Display(PNODE First)
{
    printf("Elements of Queue are : \n");

    while(First != NULL)
    {
        printf("%d\t",First->data);
        First = First->next;
    }
    printf("\n");
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


void EnQueue(PPNODE First, int NO)      // InsertLast
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


int DeQueue(PPNODE First)      // DeleteFirst
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Unable to remove the element as Queue is empty\n");
        return -1;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First == NULL;
    }
    else
    {
        temp = *First;

        iValue = (*First)->data;
        *First = (*First)->next;
        free(temp);
    }

    return iValue;
}


int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    EnQueue(&Head, 10);
    EnQueue(&Head, 20);
    EnQueue(&Head, 30);
    EnQueue(&Head, 40);

    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in the Queue are : %d\n",iRet);

    iRet = DeQueue(&Head);
    printf("Removed element is : %d\n",iRet);

    iRet = DeQueue(&Head);
    printf("Removed element is : %d\n",iRet);

    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in the Queue are : %d\n",iRet);

    EnQueue(&Head, 50);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in the Queue are : %d\n",iRet);

    return 0;
}