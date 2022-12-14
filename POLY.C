#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int coeff, powr;
	struct node *link;
};
typedef struct node * N;

N pol1 = NULL, pol2 = NULL, ans = NULL;
N add_node(N pol, int coeff, int powr)
{
	N cur = pol;
	N newnode = (N)malloc(sizeof(struct node));
	newnode->coeff = coeff;
	newnode->powr = powr;
	newnode->link = NULL;
	if(pol == NULL)
		return newnode;
	while(cur->link!=NULL)
		cur = cur->link;
	cur->link = newnode;
	return pol;
}

void display(N poly)
{
	N cur = poly;
	while(cur!=NULL)
	{
		printf("%dx^%d ", cur->coeff, cur->powr);
		if(cur->link!=NULL)
			printf("+ ");
		cur = cur->link;
	}
}

N sum(N pol1, N pol2, N ans)
{
	N ptr1 = pol1, ptr2 = pol2, ptr3 = ans;
	int coeff;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->powr == ptr2->powr)
		{
			coeff = ptr1->coeff + ptr2->coeff;
			ptr3 = add_node(ptr3, coeff, ptr1->powr);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1->powr > ptr2->powr)
		{
			ptr3 = add_node(ptr3, ptr1->coeff, ptr1->powr);
			ptr1 = ptr1->link;
		}
		else if(ptr2->powr > ptr1 -> powr)
		{
			ptr3 = add_node(ptr3, ptr2->coeff, ptr2->powr);
			ptr2 = ptr2->link;
		}
	}
	while(ptr1!=NULL)
	{
		ptr3 = add_node(ptr3, ptr1->coeff, ptr1->powr);
		ptr1 = ptr1->link;
	}
	while(ptr2!=NULL)
	{
		ptr3 = add_node(ptr3, ptr2->coeff, ptr2->powr);
		ptr2 = ptr2->link;
	}
	return ptr3;
}

void display_ans()
{
	N ptr1 = pol1, ptr2 = pol2;
	//sum(pol1, pol2, ans);
	printf("\nAddition successful....\n");
	display(ptr1);
	printf("+ ");
	display(ptr2);
	printf("= ");

	display(ans);
	printf("\n");
}

int main()
{
	int coeff, powr=1;
	//N ptr1 = pol1, ptr2 = pol2;
	clrscr();
	printf("\t--Polynomial Addition--\nPolynomial 1\n");
	while(powr!=0)
	{
		printf("Enter the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the power (Enter 0 to exit): ");
		scanf("%d", &powr);
		pol1 = add_node(pol1, coeff, powr);
	}
	powr = 1;
	printf("\nPolynomial 2\n");
	while(powr!=0)
	{
		printf("Enter the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the power (Enter 0 to exit): ");
		scanf("%d", &powr);
		pol2 = add_node(pol2, coeff, powr);
	}
	ans = sum(pol1, pol2, ans);
	display_ans();
	getch();
	return 0;
}