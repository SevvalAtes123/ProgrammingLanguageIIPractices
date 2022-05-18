#include <stdio.h>
#include <stdlib.h>
struct student
{
    int number;
    struct student *next;
};
typedef struct student std;
std *head, *new;
void add_beginning(std*);
void add_last(std*);
int main()
{
    
    while(1)
    {
        new=(std*)malloc(sizeof(std));
        printf("\n öğrenci no girin ");
        scanf("%d",&new->number);
        if(new->number==-1)
            break;
        if(new->number%2!=1)
            add_beginning(new);
        else
            add_last(new);
        new=new->next;
    }
    while(head!=NULL)
    {
        printf("%d ",head->number);
        head=head->next;
    }
    return 0;
}
void add_beginning(std *new)
{
    new->next=head;
    head=new;
}
void add_last(std *new)
{
    std *p=head;
    while(p->next!=NULL) p=p->next;
    p->next=new;
    new->next=NULL;
}
