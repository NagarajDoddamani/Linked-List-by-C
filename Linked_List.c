#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node *link;
};

typedef struct node* NODE;

NODE getnode()
{
    NODE new;
    new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("The NODE is not created\n");
    }
    return new;
}

NODE fnInsertfront(NODE first)
{
    int num;
    NODE temp;
    printf("The Number : ");
    scanf("%d",&num);

    temp=getnode();
    temp->info=num;
    temp->link=first;
    return temp;
}

NODE fnDeletefront(NODE first)
{
    NODE temp;

    if(first==NULL)
    {
        printf("THe list is empty\n");
        return NULL;
    }
    temp=first;
    temp=temp->link;
    printf("%d is Deleted\n",first->info);
    free(first);
    return temp;
}

NODE fnInsertRear(NODE first)
{
    NODE temp,curr;
    int num;

    printf("Enter the number : ");
    scanf("%d",&num);

    temp=getnode();
    temp->info=num;
    temp->link=NULL;

    if(first==NULL)
    {
        return temp;
    }
    curr=first;
    while (curr->link!=NULL)
    {
        curr=curr->link;
    }
    curr->link=temp;
    return first;
}

NODE fnDeletNodeByPos(NODE first)
{
    NODE curr,prev;
    int pos=0, num;

    if(first==NULL)
    {
        printf("The List is empty\n");
        return NULL;
    }

    printf("Enter the Postion : ");
    scanf("%d",&num);

    if(num==1)
    {
        printf("%d is Deleted\n\n",first->info);
        curr=first->link;
        free(first);
        return curr;
    }

    prev=NULL;
    curr = first;
    while(curr!=NULL)
    {
        pos++;
        if(pos==num)
        {
            break;
        }
        prev=curr;
        curr=curr->link;
    }
    if(curr!=NULL)
    {
        printf("%d is Deleted\n\n",curr->info);
        prev->link=curr->link;
        free(curr);
    }
    
    return first;
}

NODE fnDeleteRear(NODE first)
{
    NODE curr,prev;

    if(first==NULL)
    {
        printf("THe list empty\n");
        return NULL;
    }
    if(first->link==NULL)
    {
        printf("%d is Deleted\n",first->info);
        free(first);
        return NULL;
    }

    prev=NULL;
    curr=first;
    while (curr!=NULL && curr->link!=NULL)
    {
        prev=curr;
        curr=curr->link;
    }
    printf("%d is Deleted\n",curr->info);
    free(curr);
    prev->link=NULL;
    return first;
}

NODE fnPriorityDisending(NODE first)
{
    int num;
    NODE temp, curr, prev;
    printf("Enter the number : ");
    scanf("%d",&num);

    temp=getnode();
    temp->info=num;
    temp->link=NULL;

    if(first==NULL)
    {
        return temp;
    }
    if(first->info<num)
    {
        temp->link=first;
        return temp;
    }
    prev=NULL;
    curr=first;
    while(curr!=NULL && curr->info>num)
    {
        prev=curr;
        curr=curr->link;
    }
    prev->link=temp;
    temp->link=curr;
    return first;
}

NODE fnPriorityAssending(NODE first)
{
    int num;
    NODE temp, curr, prev;
    printf("Enter the number : ");
    scanf("%d",&num);

    temp=getnode();
    temp->info=num;
    temp->link=NULL;

    if(first==NULL)
    {
        return temp;
    }
    if(first->info>num)
    {
        temp->link=first;
        return temp;
    }
    prev=NULL;
    curr=first;
    while(curr!=NULL && curr->info<num)
    {
        prev=curr;
        curr=curr->link;
    }
    prev->link=temp;
    temp->link=curr;
    return first;
}

void fnDisplay(NODE first)
{
    NODE curr;

    if(first==NULL)
    {
        printf("the List is empty\n");
        return;
    }

    curr = first;
    printf("The DItails :  ");
    while(curr->link!=NULL)
    {
        printf("%d  ",curr->info);
        curr=curr->link;
    }
    printf("%d  \n", curr->info);
    return;
}

void wait(int n)
{
    for(int i=1; i<n; i++);
}

void fnFreeAll(NODE first)
{
    NODE temp;
    printf("Deleteing.....\n");
    while (temp->link!=NULL)
    {
        wait(1000);
        temp=first;
        printf("%d ",temp->info);
        first=first->link;
        free(temp);
    }

    printf("\nComplited.....\n\n\n");
    return;
}

int main()
{   
    NODE first;
    first=NULL;
    int choice;

    while(1)
    {
        printf("\n\n1 ==> Insertfront\n2 ==> Deletefront\n3 ==> Insert Rear\n4 ==> Delete Rear\n5 ==> Display\n6 ==> Priority Disending\n7 ==> priority Asending\n8 ==> Delete Node By It's Position\n9 ==> EXIT\n");
        printf("\nEnter the Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            first=fnInsertfront(first);
            break;
        case 2:
            first=fnDeletefront(first);
            break;
        case 3: 
            first=fnInsertRear(first);
            break;
        case 4:
            first=fnDeleteRear(first);
            break;
        case 5:
            fnDisplay(first);
            break;
        case 6:
            first=fnPriorityAssending(first);
            break;
        case 7:
            first=fnPriorityDisending(first);
            break;
        case 8:
            first=fnDeletNodeByPos(first);
            break;
        case 9:
            fnFreeAll(first);
            printf("\n\nThanks for using\n\n");
            return 0;
        default:
            printf("Enter the correct choice\n");
            break;
        }
    }
}