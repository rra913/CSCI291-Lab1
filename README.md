# CSCI291-Lab1
CSCI291 - Lab Task-1 :  Vending Machine Simulator.

This is a simulation of a Vending Machine made for the CSCI291 Lab Task-1, made as per the requirements of the course. The code should simulate the behaviours of a vending machine, from a customer purchasing and paying for an item, to an operator controlling the stock and setting the prices for an item. 

The code should consist of user-defined functions and should not make use of arrays, pointers or C-structs. The program should consist of three variables:
- password: an integer admin password variable.
- Min: a constant value, when the quantity of any product in the machine becomes less or equal
to Min, an alert should be sent to the vending machine operator.
- total_amount: a real-value variable which gives the total amount of sale since last reset.

Taking these requirements into account, I have designed the code to simulate the actions of a functioning vending machine.

Menu:
The user is given three options to choose from:
- Customer Mode: The user can purchase an item in this mode
- Admin Mode: The user can modify and view the stock and price of an item. The access to this mode is restricted with a password.
- Exit: The program is closed.

1. Customer Mode:
- Items in stock are displayed to the customer with it's code, name and price.
- Customer is given the option to select the item or cancel the purchase.
- In order to purchase an item, the user must pay according to the price of the item selected, change is returned if the customer pays than the item price.
- Total sales and the stock of the item is updated once the purchase is completed.

2. Admin Mode:
- User must type the correct password in order to access this mode.
- Stock of items that are lower than Min are displayed to the operator, notifying them to restock those items
- Operator is given the option to choose one of the five modes:
  - 1. Replenish Items:
    The operator can re-stock an item of their choice. The stock of the item is changed to a random number from 1-20.
  - 2. Change Item Price:
    The operator can modify the price of an item of their choice.
  - 3. Display Total Sale:
    The operator can view the total sale of the vending machine. The operator can reset the total sale to zero if they wish to do so.
  - 4. Display Item Availability:
    Display the name and stock of all the items.
  - 0. Exit Admin Mode.

The program uses three user-built functions. These functions were created to return the name, price or stock an item based on the item code. They are:
- getName(): Returns the name of an item with the item code as a parameter.
- getPrice(): Returns the price of an item with the item code as a parameter.
- getStock(): Returns the stock of an item with the item code as a parameter.