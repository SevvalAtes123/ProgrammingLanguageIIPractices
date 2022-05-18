#include <stdio.h>
#include <stdlib.h>
struct node
{
    int number;
    struct node *next;
};
struct node* cutlastaddhead(struct node *head);
int main()
{
    struct node  *head, *p;
    int n;
    head=(struct node*)malloc(sizeof(struct node));
    p=head;
    printf("\n liste elemanlarını girin durdurmak için -1 girin ");
    while(1)
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            p->next=(struct node*)malloc(sizeof(struct node));
            p=p->next;
            p->number=n;
        }
        else break;
    }
    head=cutlastaddhead(head->next);
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->number);
        p=p->next;
    }
    return 0;
}
struct node* cutlastaddhead(struct node *head)
{
    struct node *p, *q, *k;
    p=head;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    k=p;
    q->next=NULL;
    free(p);
    k->next=head;
    head=k;
    return head;
}
