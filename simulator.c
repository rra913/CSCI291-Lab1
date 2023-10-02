#include<stdio.h>

// Setting global variables for the stock and price for each item
int stock_a, stock_b, stock_c;
int price_a, price_b, price_c;

// Setting the password as a constant so it cannot be changed further in the code
#define PASSWORD 123456

int main(void) {
    // Runs the loop until the user exits the program
    while (1) {
        // Displays the menu to the user
        printf("Menu:\n1. Customer\n2. Admin\n3. Exit\n");

        // Gets the preferred mode of the user
        int mode;
        printf("Enter mode (1/2/3): ");
        scanf("%d", &mode);

        // Mode: Customer
        if (mode == 1) {

            // Displays the items along with the code, name and price
            printf("Items: {Code: Name - Price}\n1. A -%d\n2. B - %d\n3. C - %d\n",price_a, price_b, price_c);

            /*TODO: Other sequence of operations such as purchasing an item, payment*/
        }

         // Mode: Admin
        else if (mode == 2) {
            
            // Asks the user to enter the password
            int pwd;
            printf("Enter the password: ");
            scanf("%d", &pwd);

            // Checks if the password is correct
            if (pwd == PASSWORD) {

                while (1) {

                    // Displays the menu of operations
                    printf("Menu:\n1. Replenish Items\n2. Change Item Prices\n3. Display Total Sale\n4. Display Item Availability\n5. Exit Admin Mode\n");

                    // Gets the preferred mode of admin
                    int adm_mode;
                    printf("Enter the mode (1/2/3/4/5): ");
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
            printf("Invalid Input\n");
        } 
    } 
}