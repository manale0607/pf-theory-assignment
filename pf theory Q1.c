#include<stdio.h>
void addbook(int isbns[100],char titles[100][50],float prices[100],int quantities[100]);
void sale(int isbns[100],int quantities[100]);
void report(int isbns[100],char titles[100][50],float prices[100],int quantities[100]);
void display(int isbns[100], char titles[100][50], float prices[100], int quantities[100],int count);
int count =3;
int main ()
{
  int isbns[100] = {101, 102, 103};
char titles[100][50] = {"programming","algorithm","code"};
float prices[100] = {500.0, 750.0, 900.0};
int quantities[100] = {10, 3, 2};
int c;
	printf("\t\tLiberty Books");
	do {

	printf("\nMain Menu:\n1)Add New Book\n2)Process a Sale\n3)Generate Low-Stock Report\n4)display available\n0)exit\nyour choice is : ");
	scanf("%d",&c);
	switch(c){
	case 1:
		{
		 addbook(isbns,titles,prices,quantities);
		 break;
		}
	case 2 :
		{
	     sale( isbns, quantities);
	     break ;
		}
	case 3:
		{
		 report( isbns,titles,prices,quantities);
		 break;
		}
	case 4:{
		 display( isbns,titles,prices, quantities,count);
		break;
	}
	case 0:
		{
			printf("program exited ");
			break;
		}
	
	}
	} while(c!=0);
}


void addbook(int isbns[100],char titles[100][50],float prices[100],int quantities[100])
{
	int i,n;
	printf("\n-----add new book-----\n");
    printf("enter number of books to add : ");
    scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter International Standard Book Number of book %d: ",i+4);
		scanf("%d",&isbns[i+3]);
		printf("enter starting alpha of title of book %d: ",i+4);
		scanf(" %[^\n]",&titles[i+3]);
		printf("enter price of book %d: ",i+4);
		scanf("%f",&prices[i+3]);
		printf("enter quantity of book %d: ",i+4);
		scanf("%d",&quantities[i+3]);
		count++;
	}
}

void sale(int isbns[100],int quantities[100])
{
    	int i,isbn, sold, found = 0;
    	printf("\n------sale process------\n");
		printf("enter International Standard Book Number of the book  ");
		scanf("%d",&isbn);
		
		for(i=0;i<100;i++)
		{
			if (isbns[i] == isbn)       
        {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);
            if (quantities[i] >= sold)
            {
                quantities[i] -= sold;
                printf("Sale processed successfully!\n");
                printf("Remaining stock: %d\n", quantities[i]);
            }
            else
            {
                printf("Not enough stock! Only %d available.\n", quantities[i]);
            }
            break;
		}}
		
    if (!found)
    {
        printf("Book not found.\n");
        
    }
	
}
void report(int isbns[100],char titles[100][50],float prices[100],int quantities[100])
{
	
    int i,found = 0;

    printf("\n--- Low Stock Report ---\n");

    for (i = 0; i < 100; i++)
    {
        if (quantities[i] < 5 && quantities[i] > 0) 
        {
            found = 1;
            printf("\nISBN: %d", isbns[i]);
            printf("\nTitle: %s", titles[i]);
            printf("\nPrice: %.2f", prices[i]);
            printf("\nQuantity: %d", quantities[i]);
            printf("\n-----------------------------------");
        }
    }

    if (!found)
    {
        printf("\nNo low-stock books found!\n");
    }
}



void display(int isbns[100], char titles[100][50], float prices[100], int quantities[100],int count)
{
    printf("\n--- All Books in Inventory ---\n");
    int i;
    for (i = 0; i < count; i++)
    {
        printf("\nBook %d", i + 1);
        printf("\nISBN: %d", isbns[i]);
        printf("\nTitle: %s", titles[i]);
        printf("\nPrice: %.2f", prices[i]);
        printf("\nQuantity: %d", quantities[i]);  
    }
    printf("\n----------------------\n");
}
