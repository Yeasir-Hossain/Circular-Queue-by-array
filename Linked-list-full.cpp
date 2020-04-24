#include<iostream>
#include<stdlib.h>
#include<strings.h>
using namespace std;
struct node
{
    int roll;
    char name[100];
    node *next;
};
class link
{
    node *head;
public:
    link();
    void insert1st();
    void insertlast();
    void insertbefore();
    void deletelist();
    void deletefirst();
    void deletelast();
    void deleteinfo();
    void traverse();
    int findinfo();

};
link :: link()
{
    head=NULL;
}

void link::insert1st()
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    cout<<"Enter name:";
    cin>>newnode->name;
    cout<<"Enter roll:";
    cin>>newnode->roll;
    newnode->next=head;
    head=newnode;

}
void link::insertlast()
{
    node *newnode,*i;
    newnode=(node *)malloc(sizeof(node));
    cout<<"Enter name:";
    cin>>newnode->name;
    cout<<"Enter roll:";
    cin>>newnode->roll;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        return;
    }
    for(i=head; i->next!=NULL;i=i->next);
    i->next=newnode;
}
void link::insertbefore()
{
    node *i;
    i=head;
    char n[100];
    cout<<"Enter name before which you want to insert the data:";
    cin>>n;
    if(i==NULL)
        cout<<"No record"<<endl;
    if((strcmp(head->name,n)==0))
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        newnode->next=head;
        head=newnode;
    }
    else
    {
        int nodenumber=0,k;
        for(i=head; i!=NULL; i=i->next)
        {
            nodenumber++;
            if(strcmp(i->next->name,n)==0)
                break;
        }
        if(i==NULL)
        {
            cout<<"Not found";
            return;
        }
        for(k=1,i=head; k<nodenumber; i=i->next,k++);
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        cout<<"Enter name:";
        cin>>newnode->name;
        cout<<"\nEnter roll:";
        cin>>newnode->roll;
        newnode->next=i->next;
        i->next=newnode;
    }

}
void link::deletelist()
{
    node *i,*temp;
    for(i=head; i!=NULL; )
    {
        temp=i->next;
        free(i);
        i=temp;
    }
    head=NULL;

}
void link::deletefirst()
{
    if(head==NULL)
        return;
    node *temp= head;
    head=head->next;
    free(temp);
}
void link::deletelast()
{
    node *temp;
    if(head==NULL)//No node
    {
        cout<<"Nothing to delete"<<endl;;
        return;
    }
    else if(head->next==NULL)//Only one node
    {
        free(head);
        head=NULL;
        return;
    }
    for(temp=head; temp->next->next!=NULL; temp=temp->next);
    free(temp->next);
    temp->next=NULL;
}
void link::deleteinfo()
{
    node *temp,*i;
    char n[100];
    cout<<"Enter name you want to delete:";
    cin>>n;

    if(head==NULL)
    {
        cout<<"Nothing to delete"<<endl;;
        return;
    }
    //If name matches with first node
    else if(strcmp(head->name,n)==0)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    //check other nodes
    int k=0;
    for(i=head; i!=NULL; i=i->next)
    {
        k++;
        if(strcmp(i->name,n)==0)
            break;
    }
    if(i==NULL)
    {
        cout<<"Not found";
        return;
    }
    int j;
    for(j=1,i=head;j<k-1;i=i->next,j++);
    temp=i->next;
    i->next=i->next->next;
    free(temp);

}
int link::findinfo()
{
    char n[100];
    int k=0;
    node *i;
    cout<<"Enter name you want to search:";
    cin>>n;
    for(i=head; i!=NULL; i=i->next)
    {
        k++;
        if(strcmp(i->name,n)==0)
        {
            cout<<"Found at node:"<<k<<endl;
            return k;
        }
    }
    if(i==NULL)
    {
        cout<<"Not found"<<endl;
        return 0;
    }
    system("PAUSE");
}
void link::traverse()
{
    node *i;
    int k=0;
    for(i=head; i!=NULL; i=i->next)
    {
        k++;
        cout<<k<<": "<<i->roll<<"\t"<<i->name<<endl;
    }
    system("PAUSE");
}
int main()
{
    int ch=0,j,n;
    link obj;
    while(ch!=11)
    {
        cout<<"<<==MENU==>>"<<endl;
        cout<<"1.Insert data"<<endl;
        cout<<"2.Insert in first position"<<endl;
        cout<<"3.Insert in last position"<<endl;
        cout<<"4.Insert before a record"<<endl;
        cout<<"5.Delete full list"<<endl;
        cout<<"6.Delete first record"<<endl;
        cout<<"7.Delete last record"<<endl;
        cout<<"8.Delete a record"<<endl;
        cout<<"9.Find position of a record"<<endl;
        cout<<"10.Show full list"<<endl;
        cout<<"11.Quit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter how many records you want to enter:";
            cin>>n;
            for(j=0; j<n; j++)
                obj.insertlast();
                system("CLS");
            break;
        case 2:
            obj.insert1st();
            system("CLS");
            break;
        case 3:
            obj.insertlast();
            system("CLS");
            break;
        case 4:
            obj.insertbefore();
            system("CLS");
            break;
        case 5:
            obj.deletelist();
            system("CLS");
            break;
        case 6:
            obj.deletefirst();
            system("CLS");
            break;
        case 7:
            obj.deletelast();
            system("CLS");
            break;
        case 8:
            obj.deleteinfo();
            system("CLS");
            break;
        case 9:
            obj.findinfo();
            system("CLS");
            break;
        case 10:
            obj.traverse();
            system("CLS");
            break;
        case 11:
            break;
        default:
            cout<<"Outside 1-11. Try again.\n";
        }//End of switch
    }//End of while
}
