#include <stdio.h>
#include <stdlib.h> // Function used from the library: rand()

// Setting global variables for the stock, price and name for each item
int stock_a, stock_b, stock_c;
float price_a, price_b, price_c;
char name_a = 'A', name_b = 'B', name_c = 'C';

// Setting a global variable to store the total sales
float total_amount;

// Setting the password as a constant so it cannot be changed further in the code
#define PASSWORD 123456

// Defining a constant 'Min' that notifies the admin if the stock of an item is less than or equal to Min
#define Min 4

// Creating functions to return the name, stock and price of an item based on the item code
char getName(int itemCode);
float getPrice(int itemCode);
int getStock(int itemCode);

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

                // Displays the avaiable items along with the code, name and price
                if (stock_a > 0 || stock_b > 0 || stock_c > 0) {

                    printf("\nItems {Code: Name - Price}\n");

                    // Iterates through a loop of all items where i is the item code
                    for (int i = 1; i < 4; i++) {

                        int item_stock = getStock(i);

                        // Prints the items that are available
                        if (item_stock > 0) {
                            printf("%d: %c - %.2f\n", i, getName(i), getPrice(i));
                        }
                    }
                }

                // Exits from the loop if there are no available items
                else {
                    printf("\nSorry! No available items\n");
                    break;
                }

                // Asks the user to input the item code of the item they would like to purchase
                int item_code;
                printf("\nEnter item code to purchase (1/2/3)\nPress 0 to cancel purchase: ");
                scanf("%d", &item_code);
               
                // Breaks the loop if the user inputs 0
                if (item_code == 0) {
                    printf("\nPurchase Cancelled.\n");
                    break;
                }
                
                // Creates a variable to store the selected name, price and stock of the item
                float item_price = getPrice(item_code);
                char item_name = getName(item_code);
                int item_stock = getStock(item_code);
                
                // Notifies the user if the code is invalid and returns to the beginning of the loop
                if (item_price == -1 || item_name == -1 || item_stock == -1) {
                    printf("Invalid Code\n");
                    continue;
                }
            
                // Checks if the item is in stock. Returns to the loop if the item is unavailable
                if (item_stock == 0) {
                    printf("\nItem Unavailable.\nPlease select another item.\n");
                    continue;
                }
            
                // Prints the selected item name and price
                printf("\nItem Selected:\nName: %c  Price: %.2f\n", item_name, item_price);
            
                // Breaks the loop if user chooses to cancel the purchase
                int confirm_pur;
                printf("\nPress 0 to cancel purchase\nPress any number to continue purchase: ");
                scanf("%d", &confirm_pur);
                if (confirm_pur == 0) {
                   break;
                }
                
                // Prompts user to input coins till the item is paid
                float coin_insert;
                float payment = 0;
                do {

                    printf("\nInsert Coin (Accepted Coins: 1, 0.5, 0.25)\nIf you would like to cancel your purchase, press 0: ");
                    scanf("%f", &coin_insert);

                    // Tracks the total amount inserted by the customer and notifies them
                    if (coin_insert == 1 || coin_insert == 0.5 || coin_insert == 0.25) {
                        payment += coin_insert;
                        printf("\nItem Price: %.2f  Paid: %.2f\n", item_price, payment);
                    }

                    else if (coin_insert == 0) {
                        printf("Purchase Cancelled\n");

                        // Returns the coins to customer inserted if the purchase is cancelled
                        if (payment > 0) {
                            printf("%.2f Returned\n", item_price-payment);
                        }
                        break;
                    }
                    else {
                        printf("Coin Not Accepted.\n");
                    }

                } while (payment < item_price);

                // Skips the operations if customer cancels purchase
                if (coin_insert != 0) {

                    // Displays the name and price of item purchased
                    printf("\nItem Purchased:\nName: %c  Price: %.2f", item_name, item_price);
                    // Displays the amount paid by customer and change returned
                    printf("\nPaid: %.2f  Change: %.2f\n", payment, payment-item_price);

                    // Updates the total amount of sales
                    total_amount += item_price;

                    // Updates the stock of the purchased item
                    switch (item_code) {
                        case (1):
                            stock_a--;
                            break;
                        case (2):
                            stock_b--;
                            break;
                        case (3):
                            stock_c--;
                            break;
                    }
                }
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

                    // Alerts the admin if the stock of items are less than or equal to Min
                    if (stock_a <= Min || stock_b <= Min || stock_c <= Min) {

                        printf("\nItems that are low on stock: {Name - Available Stock}\n");

                        // Iterates through a loop of all items where i is the item code
                        for (int i = 1; i < 4; i++) {

                            int item_stock = getStock(i);

                            // Prints the items that are less than or equal to Min
                            if (item_stock <= Min) {
                                printf("%c - %d\n", getName(i), getStock(i));
                            }
                        }
                    }

                    // Displays the menu of operations
                    printf("\nMenu:\n1. Replenish Items\n2. Change Item Prices\n3. Display Total Sale\n4. Display Item Availability\n0. Exit Admin Mode\n");

                    // Gets the preferred mode of admin
                    int adm_mode;
                    printf("\nEnter the mode (1/2/3/4/0): ");
                    scanf("%d", &adm_mode);

                    // Gives the admin the option to re-stock an item
                    if (adm_mode == 1) {

                        // Displays the items and its stock
                        printf("\nItems: {Code: Name - Stock}\n1: %c - %d\n2: %c - %d\n3. %c - %d\n", name_a, stock_a, name_b, stock_b, name_c, stock_c);

                        // Asks the admin to input the code of the they would like to replenish
                        int item_code;
                        printf("\nEnter code of the item you would like to re-stock: ");
                        scanf("%d", &item_code);

                        // Checks if the code is invalid
                        if (item_code < 1 || item_code > 3) {
                            printf("Invalid Code\n");
                            continue;
                        }
                        
                        // Generates a random number from 1 to 20
                        int new_stock = (rand() % 20) + 1;

                        // Replenishes the stock of the selected item by the random number
                        switch(item_code) {
                            case (1):
                                stock_a = new_stock;
                                break;
                            case (2):
                                stock_b = new_stock;
                                break;
                            case (3):
                                stock_c = new_stock;
                                break;
                        }

                        // Displays the item with the new stock
                        printf("\nItem Replenished\nName: %c  Stock:%d\n", getName(item_code), getStock(item_code));
                    }

                    // Gives the admin the option to change the price of an item
                    else if (adm_mode == 2) {
                        
                        // Displays the items and its price
                        printf("\nItems: {Code: Name - Price}\n1: %c - %.2f\n2: %c - %.2f\n3: %c - %.2f\n", name_a, price_a, name_b, price_b, name_c, price_c);
                        
                        // Asks the admin to input the code of the item
                        int item_code;
                        printf("\nEnter code of the item you would like to change its price: ");
                        scanf("%d", &item_code);

                        // Returns to the beginning of the loop if the code is invalid
                        if (getPrice(item_code) == -1) {
                            printf("Invalid Code\n");
                            continue;
                        }

                        // Displays the item selected
                        printf("\nItem Selected:\nName: %c Price: %.2f\n", getName(item_code), getPrice(item_code));

                        // Asks the user to input the new price for the item selected
                        float new_amount;
                        printf("\nEnter the new price for the item: ");
                        scanf("%f", &new_amount);

                        // Updates the price of the selected item
                        switch (item_code) {
                            case (1):
                                price_a = new_amount;
                                break;
                            case (2):
                                price_b = new_amount;
                                break;
                            case (3):
                                price_c = new_amount;
                                break;
                        }

                        // Prints the name and new price of the item selected
                        printf("\nPrice Changed.\nName: %c  Price: %.2f\n", getName(item_code), getPrice(item_code));
                    }

                    // Displays the total sales amount and resets to zero if the admin chooses to
                    else if (adm_mode == 3) {
                        // Prints the total sales amount
                        printf("\nTotal Sales Amount: %.2f", total_amount);

                        // Reminds the admin to collect money from the machine if sales are above zero
                        if (total_amount > 0) {
                            printf("\nPlease collect the money from the machine!\n");
                        }

                        // Asks if the user chooses to reset the total sales amount to zero
                        int choice_a3;
                        printf("\nWould you like to reset the total sales amount to zero?\nPress 0 to confirm. Press any number to skip ");
                        scanf("%d", &choice_a3);

                        if (choice_a3 == 0) {
                            total_amount = 0;
                            printf("Total sales amount is reset to 0.\n");
                        }

                    }

                    // Displays information on the stock of available items
                    else if (adm_mode == 4) {
                        printf("\nAvailable Items: {Name - Stock}\n%c - %d\n%c - %d\n%c - %d\n", name_a, stock_a, name_b, stock_b, name_c, stock_c);
                    }

                    // Breaks the loop and returns to the main menu
                    else if (adm_mode == 0) {
                        break;
                    }

                    else {
                        printf("Invalid Input.\n");
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

// Returns the name of the item based on the item code. Returns -1 if the code is invalid
char getName(int itemCode) {
    switch (itemCode) {
        case (1):
            return name_a;
            break;
        case (2):
            return name_b;
            break;
        case (3):
            return name_c;
            break;
        default:
            return -1;
    }
}

// Returns the price of the item based on the item code. Returns -1 if the code is invalid
float getPrice(int itemCode) {
    switch (itemCode) {
        case (1):
            return price_a;
            break;
        case (2):
            return price_b;
            break;
        case (3):
            return price_c;
            break;
        default:
            return -1;
    }
}

// Returns the stock of the item based on the item code. Returns -1 if the code is invalid.
int getStock(int itemCode) {
    switch (itemCode) {
        case (1):
            return stock_a;
            break;
        case (2):
            return stock_b;
            break;
        case (3):
            return stock_c;
            break;
        default:
            return -1;
    }
}