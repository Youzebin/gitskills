#include <stdio.h>
#include <stdlib.h>

struct Student{
    char cName[20];
    int iNumber;
    struct Student* pNext;
};

int iCount;

struct Student* Create()
{
    struct Student* pHead = NULL;
    struct Student* pEnd,*pNew;
    iCount = 0;
    pEnd = pNew = (struct Student*)malloc(sizeof(struct Student));
    printf("please first enter Name,then Number\n");
    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);
    while(pNew->iNumber!=0)
    {
        iCount++;
        if(iCount==1)
        {
            pNew->pNext = pHead;
            pEnd = pNew;
            pHead = pNew;
        }
        else{
            pNew->pNext = NULL;
            pEnd->pNext = pNew;
            pEnd = pNew;
        }
        pNew = (struct Student*)malloc(sizeof(struct Student));
        scanf("%s",pNew->cName);
        scanf("%d",&pNew->iNumber);
    }
    free(pNew);
    return pHead;
}

void Print(struct Student* pHead)
{
    struct Student *pTemp;
    int ilndex = 1;

    printf("----the List has %d menbers:--\n",iCount);
    printf("\n");
    pTemp = pHead;

    while(pTemp!=NULL)
    {
        printf("the No%d member is:\n",ilndex);
        printf("the name is:%s\n",pTemp->cName);
        printf("the number is: %d\n",pTemp->iNumber);
        printf("\n");
        pTemp = pTemp->pNext;
        ilndex++;
    }
}

struct Student* Insert(struct Student* pHead)
{
    struct Student* pNew;
    printf("----Insert member at first----\n");
    pNew = (struct Student*)malloc(sizeof(struct Student));

    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);

    pNew->pNext = pHead;
    pHead = pNew;
    iCount++;
    return pHead;
}

void Delete(struct Student* pHead,int ilndex)
{
    int i;
    struct Student* pTemp;
    struct Student* pPre;
    pTemp = pHead;
    pPre = pTemp;

    printf("---delete No %d member ----\n",ilndex);
    for(i=1;i<ilndex;i++)
    {
        pPre = pTemp;
        pTemp = pTemp->pNext;
    }
    pPre->pNext = pTemp->pNext;
    free(pTemp);
    iCount--;
}

int main()
{
    struct Student* pHead;
    pHead = Create();
    pHead = Insert(pHead);
    Delete(pHead,2);
    Print(pHead);
    return 0;
}