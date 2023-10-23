#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"library.h"
int main()
{
	char str1[10000],str2[10000];
	char ans[20000];
		char x;
	printf("eneter the operation:");
	scanf("%c",&x);
	if(x!='/'&&x!='%'){
	printf("eneter the first no.:");
	scanf("%s",str1);
	printf("eneter the second no.:");
	scanf("%s",str2);
}
		switch(x)
		{
		case'+':	addition(str1,str2,ans);
			
				puts(ans);
				break;
		case'-':sub(str1,str2);
			break;
		case'/':printf("enter dividend:");
		scanf("%s",str1);
				printf("enter divisior:");
				int n;
				scanf("%d",&n);
		division(str1,n,ans);
		puts(ans);
			break;
		case'*':multiply(str1,str2);
			break;
		case'%':printf("enter dividend:");
		scanf("%s",str1);
				printf("enter divisior:");
				scanf("%d",&n);
		modules(str1,n,ans);
			break;
			default:printf("invalid operator!!!!!"); exit(1);
		}
}
