#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;

void create()
{
    int n, i = 0;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    
    while (i < n)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d\t\n", temp->data);
        temp = temp->next;
    }
}

void beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);

    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = 0;
}

void pos()
{
    int pos, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);

    printf("\nEnter position : ");
    scanf("%d", &pos);

    temp = head;

    for (i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void del_beg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode=head;
    head=newnode->next;
    free(newnode);
}

void del_end(){
    temp = head;   
        while(temp->next != NULL)  
        {  
            newnode = temp;  
            temp = temp ->next;  
        }  
        newnode->next = NULL;  
        free(temp);  
        printf("\nDeleted Node from the last ...\n");
}

void del_pos(){
    
    int pos,i;
    printf("Enter position : ");
    scanf("%d",&pos);
    
    temp = head;   
        for(i=0; i<pos; i++)
        {  
            newnode = temp;  
            temp = temp ->next;  
        }  
        newnode->next=temp->next;
        free(temp);
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n-----------------------\nEnter choice : \n1.Create  \n2.Display  \n3.Insert at beg  \n4.Insert at end  \n5.Insert at pos \n6.Delete at beg  \n7.Delete at end  \n8.Delete at pos  \n9.Exit \n---------------------");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            beg();
            break;
        case 4:
            end();
            break;
        case 5:
            pos();
            break;
        case 6:
            del_beg();
            break;
         case 7:
             del_end();
             break;
         case 8:
            del_pos();
            break;
         case 9:
             exit(0);
        }
    }
    return 0;
}