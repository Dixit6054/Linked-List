//this will find you the middle element of a linked list
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* link;
};

void insert(int data , node** head , node** last, int key)
{
	if(key==1)
	{
		node* temp = new node;
		(*temp).data = data;
		node* c;
		c = *head;
		*head = temp;
		temp->link = c;
		if(*last == NULL)
		*last = temp;
		
	}
	else
	{
		node* temp = new node;
		temp->data = data;
		temp->link= NULL;
		
		if(*last == NULL)
		*last = temp;//(*last)->link = temp;
		else
		{
			(*last)->link = temp;
			*last = temp;	
		}
		
		if(*head==NULL)
		*head=temp;
	}
}
void print (node* head)
{
	while(head != NULL)
	{
		cout << head->data <<" ";
		head = head->link;
	}
	cout<<endl;
}
void middle(node* head)
{
	node *slow=head,*fast=head,*back_mid;
	
	while(fast && fast->link)
	{
		fast = fast->link->link;
		back_mid = slow;
		slow = slow->link;
	}
	if(fast==NULL)	//for even list
	{
		cout << "I have got a even sting. thus two middles are: " << back_mid->data <<" and "<<slow->data;
	}
	else
	cout << "your middle element is: " << slow->data;
	
	
}
 
main()
{
	node* head = NULL;
	node* last = NULL;
	insert(1,&head,&last,0);
	insert(2,&head,&last,0);
	insert(3,&head,&last,0);
	insert(4,&head,&last,0);
	insert(3,&head,&last,0);
	insert(2,&head,&last,0);//2 0 5 7 12 21 
	insert(1,&head,&last,0);
	print(head);
	middle(head);	
}
