#include <stdio.h>
void customerInfo(char name[],int s,int cnic);
void displayInventory(int codes[], int quantity[], int price[], int size);
void updateInventory(int codes[],int quantity[], int price[], int s);
void addToCart(int codes[], int quantity[], int price[], int size,int cartCode[], int cartQty[], int cartCount);
float displayBill(int codes[], int price[], int size, int cartCode[], int cartQty[], int cartCount, float discountedTotal);
void showInvoice(char name[], int cnic, int cartCode[], int cartQty[], int cartCount, int codes[], int price[], float total, float discountedTotal);
int main()
{
    int codes[4] = {1, 2, 3, 4};
    int quantity[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};

    int cartCode[100], cartQty[100];
    int cartCount = 0;

    char name[50];
    int cnic;
    float total = 0, discountedTotal = 0;

    int choice;
    do
    {
        printf("\n--- Supermarket Menu ---");
        printf("\n\t 1. Customer Information");
        printf("\n\t 2. Display Inventory");
        printf("\n\t 3. Add Item to Cart");
        printf("\n\t 4. Display Total Bill");
        printf("\n\t 5. Show Invoice");
        printf("\n\t 6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                customerInfo(name,30,cnic);
                break;
            case 2:
                displayInventory(codes, quantity, price, 4);
                break;
            case 3:
                updateInventory(codes, quantity, price, 4);            
                break;
            case 4:
                addToCart(codes, quantity, price, 4, cartCode, cartQty, cartCount);
            	break;
            case 5:
                total = displayBill(codes, price, 4, cartCode, cartQty, cartCount, discountedTotal);
                break;
            case 6:
                showInvoice(name, cnic, cartCode, cartQty, cartCount, codes, price, total, discountedTotal);
                break;
            case 7:
                printf("\nExiting system... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    while(choice!=6);
    return 0;
}
void customerInfo(char name[],int s, int cnic)
{
   printf("\n write the name:");
   scanf("%s",name);
   printf("\n give your cnic:");
   scanf("%d",&cnic);
   printf("\n ----customer details---- \n\t name: %s \n\t cnic:%d",name,cnic);
}
void displayInventory(int codes[], int quantity[], int price[], int size)
{ 
    int i;
	printf("\n---------------------------------------------");
    printf("\n\t --Code--  --Quantity--  --Price-- ");
    printf("\n---------------------------------------------");
    for(i = 0; i < size; i++)
    {
        printf("\n%-10d %-15d %-10d", codes[i], quantity[i], price[i]);
    }
    printf("\n---------------------------------------------\n");
}
void updateInventory(int codes[], int quantity[], int price[], int s)
{
    int i,code, soldQty, found = 0;
    printf("\nEnter product code to update: ");
    scanf("%d", &code);
    printf("Enter quantity sold: ");
    scanf("%d", &soldQty);
    for(i = 0; i < s; i++)
    {
        if(codes[i] == code)   
        {
            found = 1;
            if(quantity[i] >= soldQty)
            {
                quantity[i] -= soldQty;   
                printf("\n Sale processed successfully!");
                printf("\n Updated stock for code %d: %d left\n", code, quantity[i]);
            }
            else
            {
                printf("\n Not enough stock available! Only %d left.\n", quantity[i]);
            }
            break;
        }
    }
    if(!found)
    {
        printf("\n Product code not found in inventory.\n");
    }
}
void addToCart(int codes[], int quantity[], int price[], int size, int cartCode[], int cartQty[], int cartCount)
{
	int code, qty, found, i;
    char choice;
    do
    {
        printf("\nEnter product code to add: ");
        scanf("%d", &code);
        found = 0;
        for (i = 0; i < size; i++)
        {
            if (codes[i] == code)
            {
                found = 1;
                printf("Enter quantity: ");
                scanf("%d", &qty);
                if (qty <= quantity[i])
                {
                    cartCode[cartCount] = code;
                    cartQty[cartCount] = qty;
                    cartCount++;
                    quantity[i] -= qty;

                    printf("Added %d of product %d to cart.\n", qty, code);
                }
                else
                {
                    printf("Not enough stock! Only %d left.\n", quantity[i]);
                }
                break;
            }
        }
        if (!found)
        {
            printf("Product code not found in inventory.\n");
        }
        printf("\nAdd another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}
float displayBill(int codes[], int price[], int size, int cartCode[], int cartQty[], int cartCount, float discountedTotal)
{
	float total = 0;       
    int i, j;
    char promo[20];
    int hasPromo;
    for (i = 0; i < cartCount; i++)
    {
        for (j = 0; j < 4; j++)  
        {
            if (cartCode[i] == codes[j])
            {
                total += price[j] * cartQty[i]; 
            }
        }
    }
    printf("\n-----------------------------------");
    printf("\n\t Total bill (without discount): %.2f", total);
    printf("\n-----------------------------------");
    printf("\nDo you have a promocode? (1 for Yes / 0 for No): ");
    scanf("%d", &hasPromo);
    if (hasPromo == 1)
    {
        printf("Enter promocode: ");
        scanf("%s", promo);
        if (promo[0] == 'E' && promo[1] == 'i' && promo[2] == 'd' &&
            promo[3] == '2' && promo[4] == '0' && promo[5] == '2' && promo[6] == '5' && promo[7] == '\0')
        {
            discountedTotal = total * 0.75; 
            printf("\nPromocode applied successfully! 25%% discount given.");
            printf("\nDiscounted bill: %.2f", discountedTotal);
        }
        else
        {
            discountedTotal = total;
            printf("\nInvalid promocode. No discount applied.");
        }
    }
    else
    {
        discountedTotal = total;
    }
    printf("\n-----------------------------------\n");
    return total;
}
void showInvoice(char name[], int cnic, int cartCode[], int cartQty[], int cartCount, int codes[], int price[], float total, float discountedTotal)
{
    printf("\n\n=============== INVOICE ================\n");
    printf("Customer Name: %s\n", name);
    printf("Customer CNIC: %d\n", cnic);
    printf("-----------------------------------------\n");
    printf("--Code--\t--Qty--\t--Price--\t--Subtotal--\n");
    printf("-----------------------------------------\n");
    int i,j;
    float subtotal, grandTotal = 0;
    for(i = 0; i < cartCount; i++)
    {
        int code = cartCode[i];
        int qty = cartQty[i];

        for(j = 0; j < 4; j++) 
        {
            if(codes[j] == code)
            {
                subtotal = qty * price[j];
                grandTotal += subtotal;
                printf("%d\t %d\t %d\t %.2f\n", code, qty, price[j], subtotal);
                break;
            }
        }
    }
    printf("-----------------------------------------\n");
    printf("Total Before Discount: %.2f\n", total);
    printf("Discounted Total: %.2f\n", discountedTotal);
    printf("=========================================\n");
    printf("Thank you for shopping with us!\n");
}

