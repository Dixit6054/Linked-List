#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

void print(node* head)
{
	if(!head)
	return;
	while(head)
	{
		cout << head->data <<" ";
		head= head->next;
	}
	cout <<endl;
}

void insert(node** head, node** last, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	
	if(!*head)
	*head = temp;
	if(*last)
	(*last)->next = temp;
	*last = temp;
}
void reverse(node** head, node* c, node* temp)
{
	if(*head==NULL)
	return;
	if(!c->next)
	{
		*head = c;
		return;
	}
	
	reverse( head, c->next, temp);
	
	c->next->next = c;
	if(c==temp)
	c->next = NULL;
}






bool ispalendrome(node* head)
{
	node *fast=head, *slow=head, *pre_mid=head, *half, *temp=head;
	bool result=1;
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		pre_mid = slow;
		slow = slow->next;
	}
	
//i am expecting middle element in slow;
	if(fast)		//odd length
	{
		half = slow->next;
		pre_mid = slow;
		slow = slow->next;
	}
	else
	half = slow;
	
	reverse(&half,half,half);
	
	slow = half;
	
	while(slow)
	{
		if(temp->data != slow->data)
		break;
		temp = temp->next;
		slow = slow->next;
	}
	if(!slow)
	result =  true;
	else
	result = false;
	reverse(&half,half,half);
	
	pre_mid->next = half;
	
	return result;
	
}
main()
{
	node* head = NULL;
	node* last = NULL;
	insert(&head, &last, 1);
	insert(&head, &last, 2);
	insert(&head, &last, 2);
	insert(&head, &last, 2);
	insert(&head, &last, 1);
	insert(&head, &last, 1);
//	insert(&head, &last, 1);
	print(head);
	cout << "\n" << ispalendrome(head)<<endl;
	print(head);
	
		
}










