#include <stdio.h>
#include <stdlib.h>
struct person
{
    int age;
    struct person *next;
};
typedef struct person prs;
prs* changeFirstAndLast(prs *head);
prs* find_last(prs *head);
int main()
{
    prs *head, *p;
    int n;
    head=(prs*)malloc(sizeof(prs));
    p=head;
    printf("listenin elemanlarını giriniz\ndurdurmak icin -1 giriniz ");
    while(1)
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            p->next=(prs*)malloc(sizeof(prs));
            p=p->next;
            p->age=n;
        }
        else  break;
    }
    head=changeFirstAndLast(head->next);
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->age);
        p=p->next;
    }
    return 0;
}
prs* changeFirstAndLast(prs *head)
{
    prs *last, *p, *q;
    last=find_last(head);
    p=head;
    q=head->next;
    head=last->next;
    last->next->next=q;
    last->next=p;
    p->next=NULL;
    return head;
}
prs* find_last(prs *head)
{
    prs *p;
    p=head;
    while(p->next->next!=NULL)
        p=p->next;
    return p;
}
