// Stephanie Sarambo
// CSCI 1010 Section 002
// Project 2
// Grocery product management system

#include<iostream>

#include<string>

using namespace std;

const int MAX = 100;
int products[MAX], amount[MAX], id = 0;
string brands[MAX], names[MAX];
double wholesale[MAX], sale[MAX];

void initial();
void productNew(int a[], int);
void productCost(int a[], int);
void productSale(int a[], int);
void productCount(int a[], int);
void profit(int a[], int);
void lowStock(int a[], int);
void remove(int a[], int);
void display(int a[], int);

int main()
{
    initial();

    for(int i = 0; i < MAX; i++)
    {
        int choice;
        cout << "*** Menu *** \n";
        cout << "1. Add a new product \n";
        cout << "2. Update product cost \n";
        cout << "3. Update product sale price \n";
        cout << "4. Update product count \n";
        cout << "5. Calculate total profit \n";
        cout << "6. Check low in stock (<10) \n";
        cout << "7. Remove product \n";
        cout << "8. Display all products \n";
        cout << "9. Quit \n";

        cout << "Choose from the menu: ";
        cin >> choice;

        if(choice == 9)
        {
            break;
        }
        else
        {
            switch(choice)
            {
                case 1:
                productNew(products, id);
                break;
                case 2:
                productCost(products, id);
                break;
                case 3:
                productSale(products, id);
                break;
                case 4:
                productCount(products, id);
                break;
                case 5:
                profit(products, id);
                break;
                case 6:
                lowStock(products, id);
                break;
                case 7:
                remove(products, id);
                break;
                case 8:
                display(products, id);
                break;
                default:
                cout << "Invalid entry. Try again!\n";
                break;
            }
        }
    }
}

void initial()
{
    products[0] = 1;
    brands[0] = "Kraft";
    names[0] = "Mac&Cheese";
    wholesale[0] = 9.89;
    sale[0] = 13.99;
    amount[0] = 8;

    products[1] = 2;
    brands[1] = "Nescafe";
    names[1] = "Coffee";
    wholesale[1] = 3.49;
    sale[1] = 5.59;
    amount[1] = 9;

    products[2] = 3;
    brands[2] = "Cheerios";
    names[2] = "Cereal";
    wholesale[2] = 2.12;
    sale[2] = 4.99;
    amount[2] = 3;

    products[3] = 4;
    brands[3] = "Oreo";
    names[3] = "Cookies";
    wholesale[3] = 4.89;
    sale[3] = 6.99;
    amount[3] = 160;

    products[4] = 5;
    brands[4] = "Dole";
    names[4] = "CannedFruit";
    wholesale[4] = 6.89;
    sale[4] = 13.99;
    amount[4] = 20;

    id = 5;
}

void productNew(int a[], int size)
{
    if(id > 100)
    {
        cout << "Product limit reached!\n";
    }
    else
    {
        products[id] = id + 1;

        cout << "Enter the brand name: ";
        cin >> brands[id];

        cout << "Enter the product name: ";
        cin >> names[id];

        cout << "Enter the wholesale price: ";
        cin >> wholesale[id];

        cout << "Enter the sale price: ";
        cin >> sale[id];

        cout << "Enter the product count: ";
        cin >> amount[id];

        id++;
    }
}

void productCost(int a[], int size)
{
    int idNum;
    
    cout << "Enter an ID: ";
    cin >> idNum;

    if(idNum > size)
    {
        cout << "Invalid ID. Try again.\n";
    }
    else
    {
        cout << "The brand is " << brands[idNum - 1] << endl;
        cout << "The product is " << names[idNum - 1] << endl;
        cout << "The current wholesale price is " << wholesale[idNum - 1] << endl;
        cout << "Enter a new price: ";
        cin >> wholesale[idNum - 1];
    }
}

void productSale(int a[], int size)
{
    int idNum;

    cout << "Enter an ID: ";
    cin >> idNum;
    
    if(idNum > size)
    {
        cout << "Invalid ID. Try again.\n";
    }
    else
    {
        cout << "The brand is " << brands[idNum - 1] << endl;
        cout << "The product is " << names[idNum - 1] << endl;
        cout << "The current sale price is " << sale[idNum - 1] << endl;
        cout << "Enter a new price: ";
        cin >> sale[idNum - 1];
    }
}

void productCount(int a[], int size)
{
    int idNum;

    cout << "Enter an ID: ";
    cin >> idNum;

    if(idNum > size)
    {
        cout << "Invalid ID. Try again.\n";
    }
    else
    {
        cout << "The brand is " << brands[idNum - 1] << endl;
        cout << "The product is " << names[idNum - 1] << endl;
        cout << "The current count is " << amount[idNum - 1] << endl;
        cout << "Enter a new count: ";
        cin >> amount[idNum - 1];
    }
}

void profit(int a[], int size)
{
    double total = 0;

    for(int i = 0; i < size; i++)
    {
        total += amount[i] * (sale[i] - wholesale[i]);
    }

    cout << "The total profit is: " << total << endl;
}

void lowStock(int a[], int size)
{
    cout << "The following products are low in stock: \n";
    cout << "ID\tBrand\t\tProduct\t\tCount\n";

    for(int i = 0; i < size; i++)
    {
        if(amount[i] < 10)
        {
            cout << products[i] << "\t" << brands[i] << "\t\t" << names[i] << "\t\t" << amount[i] << endl;
        }
    }
}

void remove(int a[], int size)
{
    int idNum;

    cout << "Enter an ID: ";
    cin >> idNum;

    cout << "The brand is " << brands[idNum - 1] << endl;
    cout << "The product is " << names[idNum - 1] << endl;

    for(int i = idNum - 1; i < size; i++)
    {
        products[i] = products[i + 1];
        brands[i] = brands[i + 1];
        names[i] = names[i + 1];
        wholesale[i] = wholesale[i + 1];
        sale[i] = sale[i + 1];
        amount[i] = amount[i + 1];
    }

    cout << "Remove success!" << endl;

    id--;
}

void display(int a[], int size)
{
    cout << "ID\tBrand\t\tProduct\t\tWholesale\t\tPrice\tCount\n";

    for(int i = 0; i < size; i++)
    {
        cout << products[i] << "\t" << brands[i] << "\t\t" << names[i] << "\t\t" << wholesale[i] << "\t\t" << sale[i] << "\t" << amount[i] << endl;
    }
}