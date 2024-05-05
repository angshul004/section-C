#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//youtube link: https://youtu.be/RVpDvGGYaFM

#define MAX_ITEMS 50
#define GST_RATE 0.18

int main() {
    char item_names[MAX_ITEMS][100], name[30];
    int quantities[MAX_ITEMS], phone;
    float prices[MAX_ITEMS];
    int num_items = 0;
    
    printf("Enter customer name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter customer contact number: ");
    scanf("%d",&phone);
    char add_more;
    do {
        printf("Enter item name: ");
        scanf("%s", item_names[num_items]);
        printf("Enter quantity: ");
        scanf("%d", &quantities[num_items]);
        printf("Enter price (per unit): ");
        scanf("%f", &prices[num_items]);

        num_items++;

        printf("Add another item (y/n)? \n");
        scanf(" %c", &add_more);
    } while (add_more == 'y' || add_more == 'Y');

    float subtotal = 0;
    for (int i = 0; i < num_items; i++) {
        subtotal += quantities[i] * prices[i];
    }
    float gst = subtotal * GST_RATE;
    float total = subtotal + gst;
	
	
	
	system("cls");
    printf("===========================================\n");
    printf("                 INVOICE\n");
    printf("===========================================\n");
	printf("ABC STORES\nKolkata 7000001\nPhone: +91 90000000001\n\n");
	
	time_t t = time(NULL);
    struct tm *date = localtime(&t);  
    printf("Date: %02d/%02d/%d \tTime: %02d:%02d\n\n", date->tm_mday, date->tm_mon + 1, date->tm_year+1900, date->tm_hour, date->tm_min);   
	printf("BILL TO:\n%sPhone: %d\n\n",name,phone);
    printf("___________________________________________\n");
	printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-15s\t%-8d\tRS. %.2f\n", item_names[i], quantities[i], prices[i]);
    }

    printf("\nSubtotal:\tRS. %.2f\n", subtotal);
    printf("GST (%.2f%%):\tRS. %.2f\n", GST_RATE * 100, gst);
    printf("Total:\t\tRS. %.2f\n", total);

    printf("___________________________________________\n");
    printf("\nThank you for shopping!\n");

    return 0;
}
