#include<stdio.h>

// Setting global variables for the stock and price for each item
int stock_a, stock_b, stock_c;
float price_a = 2 , price_b = 1.5, price_c = 1;
char name_a = 'A', name_b = 'B', name_c = 'C';

// Setting the password as a constant so it cannot be changed further in the code
#define PASSWORD 123456

int main(void) {

    // Runs the loop until the user exits the program
    while (1) {

        // Displays the menu to the user
        printf("\nMenu:\n1. Customer\n2. Admin\n3. Exit\n");

        // Gets the preferred mode of the user
        int mode;
        printf("Enter mode (1/2/3): ");
        scanf("%d", &mode);

        // Mode: Customer
        if (mode == 1) {
            while (1) {

                // Displays the items along with the code, name and price
                printf("\nItems: {Code: Name - Price}\n1. %c - %.2f\n2. %c - %.2f\n3. %c - %.2f\n", name_a, name_b, name_c, price_a, price_b, price_c);
    
                // Asks the user to input the item code of the item they would like to purchase
                int item_code;
                printf("\nEnter item code to purchase (1/2/3)\nPress 0 to cancel purchase: ");
                scanf("%d", &item_code);
               
                // Breaks the loop if the user inputs 0
                if (item_code == 0) {
                    printf("\nPurchase Cancelled.\n");
                    break;
                }
                
                // Creates a variable to store the selected name and price of the item
                float item_price;
                char item_name;
                switch (item_code) {
                    case (1):
                        item_price = price_a;
                        item_name = name_a;
                        break;
                    case (2):
                        item_price = price_b;
                        item_name = name_b;
                        break;
                    case (3):
                        item_price = price_c;
                        item_name = name_c;
                        break;
                    default: // Informs the user if the item code is invalid
                        puts("Invalid Code\n");
                        continue;
                }
            
                /*TODO: Check if item is in stock*/
            
                // Prints the selected item name and price
                printf("\nItem Selected:\nName: %c  Price: %.2f\n", item_name, item_price);
            
                // Breaks the loop if user chooses to cancel the purchase
                int confirm_pur;
                printf("\nPress 0 to cancel purchase\nPress any key to continue purchase: ");
                scanf("%d", &confirm_pur);
                if (confirm_pur == 0) {
                   break;
                }
                
                // Prompts user to input coins till the item is paid
                float coin_insert;
                float payment;
                do {

                    printf("\nInsert Coin (Accepted Coins: 1, 0.5, 0.25)\nIf you would like to cancel your purchase, press 0: ");
                    scanf("%f", &coin_insert);

                    //
                    if (coin_insert == 1 || coin_insert == 0.5 || coin_insert == 0.25) {
                        payment += coin_insert;
                        printf("\nItem Price: %.2f  Paid: %.2f\n", item_price, payment);
                    }
                    else if (coin_insert == 0) {
                        printf("Purchase Cancelled\n");
                        break;
                    }
                    else {
                        printf("Coin Not Accepted.\n");
                    }

                } while (payment < item_price);

                printf("\nItem %c Purchased\n", item_name);

                /*TODO: Update the stock of item once it is purchased*/

            }
        }

        // Mode: Admin
        else if (mode == 2) {

            // Asks the user to enter the password
            int pwd;
            printf("\nEnter the password: ");
            scanf("%d", &pwd);

            // Checks if the password is correct
            if (pwd == PASSWORD) {

                while (1) {

                    // Displays the menu of operations
                    printf("\nMenu:\n1. Replenish Items\n2. Change Item Prices\n3. Display Total Sale\n4. Display Item Availability\n5. Exit Admin Mode\n");

                    // Gets the preferred mode of admin
                    int adm_mode;
                    printf("\nEnter the mode (1/2/3/4/5): ");
                    scanf("%d", &adm_mode);

                    /*TODO: Operations for other modes*/

                    if (adm_mode == 5) {
                        break;
                    }
                }
            } 
            
            else {

                // Notifies the user if the password is incorrect and exits the program
                printf("Invalid Password\n");
                break;
            } 
        }

        // Exits the program
        else if (mode == 3) {
            break;
        }

        // Informs the user if the input is invalid
        else {
            printf("\nInvalid Input\n");
        } 
    } 
}