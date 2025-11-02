#include<stdio.h>
int push(int stack[], int top, int maxSize);
int pop(int stack[], int top);
void peek(int stack[], int top);
void display(int stack[], int top);
#define max 5
int main()
{
	int stack[max];
	int top=-1;
	int choice=0;
	while(choice!=5)
	{
		printf("\n--- STACK MENU ---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        	case 1:
        		top = push(stack, top, max);
        		break;
        	case 2:
        		top = pop(stack, top);
        		break;
        	case 3:
        		peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("\nExiting program... Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
		}
	}
return 0;
}
int push(int stack[], int top, int maxSize)
{
	int value;
    if (top == maxSize - 1)
    {
        printf("\nStack Overflow! Cannot push more elements.\n");
    }
    else
    {
        printf("\nEnter value to push: ");
        scanf("%d", &value);
        top++;               
        stack[top] = value;  
        printf("Pushed %d into stack.\n", value);
    }
    return top;
}
int pop(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("\nPopped element: %d\n", stack[top]);
        top--; 
    }
    return top;
}
void peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nTop element is: %d\n", stack[top]);
    }
}
void display(int stack[], int top)
{
	int i;
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
