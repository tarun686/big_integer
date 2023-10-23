#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void display(struct node *head){
	
while(head!=NULL)
{
	printf("%d",head->data);
	head=head->next;
}
printf("\n");
}
struct node* newnode(struct node*head,int data){
	struct node *temp=(struct node*)malloc(sizeof (struct node));
	temp->data=data;
	 temp->next=head;
	 head=temp;
	 return head;
}
void reversestring(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void addition( char str1[],char str2[],char ans[])
{
	reversestring(str1);
	reversestring(str2);
	int i=0,carry=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		int digit1=str1[i]-'0';
		int digit2=str2[i]-'0';
		int add=digit1+digit2+carry;
		carry=add/10;
		ans[i]=(add%10)+'0';
		i++;
	}
	if(str2[i]=='\0')
	{
			while(str1[i]!='\0' )
			{
			int digit1=str1[i]-'0';
			int add=digit1+carry;
			carry=add/10;
			ans[i]=(add%10)+'0';
				i++;
			}
			if(carry){
			ans[i]='1';
		i++;
		}
	}
	if(str1[i]=='\0')
	{
			while(str2[i]!='\0' )
			{
			int digit1=str2[i]-'0';
			int add=digit1+carry;
			carry=add/10;
			ans[i]=(add%10)+'0';
				i++;
			}
			if(carry){
			ans[i]='1';
		i++;
		}
	}
	ans[i]='\0';
	reversestring(ans);
}

void sub(char str1[],char str2[])
{
	struct node *node1=NULL;
	struct node *node2=NULL;
	struct node *result=NULL;
	int l1=strlen(str1);
	int l2=strlen(str2);
	if (l1 < l2 || (l1 == l2 && strcmp(str1, str2) < 0))
	{
		char *temp=str1;
		str1=str2;
		str2=temp;
		int swap=l1;
		l1=l2;
		l2=swap;
	}

	
	for(int i=0;i<l1;i++)
	{
		 int digit=str1[i]-'0';
		node1=newnode(node1,digit);
	}
	for(int i=0;i<l2;i++)
	{
		int digit=str2[i]-'0';
		node2=newnode(node2,digit);
	}
	
	int borrow=0,digit1=0,digit2=0,diff=0;
	while(node1!=NULL || node2!= NULL)
	{
		if(node1!=NULL)
		{
			digit1=node1->data;
		}
		else
		{
			digit1=0;
		}
		if(node2!=NULL)
		{
			digit2=node2->data;
		}
		else
		{
			digit2=0;
		}
		diff=digit1-digit2-borrow;
		if (digit1<digit2) {
            diff=diff+10;
            borrow=1;
        } else {
            borrow=0;
        }
		
		
        result=newnode(result,diff);
		if(node1!=NULL)
		{
			node1=node1->next;
		}
		if(node2!=NULL)
		{
			node2=node2->next;
		}
	
	}
		if (l2 < l1 || (l2 == l1 && strcmp(str2, str1) < 0))
		{
			result->data=-(result->data);
		}
	display(result);
}


void displayarr(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
{
	printf("%d",arr[i]);
	}	
	printf("\n");
}



void multiply(char str1[],char str2[])
{
	int l1=strlen(str1); 
	int l2=strlen(str2);
	int arr1[1000],arr2[1000];
	int ans[20000];
	int i=0;
	while(str1[i]!='\0')
	{
		arr1[i]=str1[i]-'0';
		i++;
	}

	i=0;
		while(str2[i]!='\0')
	{
		arr2[i]=str2[i]-'0';
		i++;	
	}
	
	for(int i=l2;i>=0;i--)
	{
		for(int j=l1;j>=0;j--)
		{
			ans[i+j]=ans[i+j]+arr1[i]*arr2[j];
		}
	int carry =0;
for(int i=l1+l2;i>=0;i--)
{
	if(i==0)
	break;
	carry=ans[i]/10;
	ans[i]=ans[i]%10;
	ans[i-1]=carry+ans[i-1];
	}
	printf("product :");
	displayarr(ans,l1+l2);
}
	}
	void division(char dividend[], int divisor, char result[]) {
    int len=strlen(dividend);
    int carry=0;
    int temp;

    int index=0;

    for (int i=0;i<len;i++)
	 {
        temp=carry*10+(dividend[i]-'0');
        result[index++] = temp/divisor+'0';
        carry=temp%divisor;
    }
    result[index]='\0';

    while (result[0]=='0'&&result[1]!='\0')
	{
        for (int i=0;i<index;i++)
		 {
            result[i]=result[i+1];
        }
        index--;
    }
}
void modules(char dividend[], int divisor, char result[]) {
    int len=strlen(dividend);
    int carry=0;
    int temp;

    int index=0;

    for (int i=0;i<len;i++)
	 {
        temp=carry*10+(dividend[i]-'0');
        result[index++] = temp/divisor+'0';
        carry=temp%divisor;
    }
    printf("%d\n",carry);
}


