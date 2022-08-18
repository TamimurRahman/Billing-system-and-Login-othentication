#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void insert_item();
void display();
void inputItems(int i);
void delete_item();
void generateId(int);
void search_item();
void bill_footer();
void bill_body();
void generate_bill_header();
void createBill();
void operationExitFunction();

struct items
{
    char item[20];
    float price, pricePerItem;
    int qty;
    int id;
};
struct orders
{
    char customer[50];
    char date[50];
    int numberofitems;
    int cell_number;
    float vat;
    float total;
    float total_vat;
    struct items itm[50];
};
struct orders ord;

int main()
{
    int i, invoice_input, n, total = 0, choise_operation;
    cout << "\n\t============== Restaurent Billing System ==============";
    cout << "\n\nPlease slect your prefered operation";
    cout << "\n1.Generate Invoice";
    cout << "\n2.Exit";
    cout << "\n\nYour choice:\t";
    cin >> invoice_input;
    fgetc(stdin);
    switch (invoice_input)
    {
    case 1:
        system("cls");
        strcpy(ord.date, __DATE__);
        cout << "Input customer name : ";
        fgets(ord.customer, 50, stdin);

        cout << "Phone number : ";
        cin >> ord.cell_number;
        cout << "Enter number of ITEMS : ";
        cin >> n;
        ord.numberofitems = n;
        cout << "\nInput VAT Govt. specified categories: ";
        cin >> ord.vat;
        for (i = 1; i <= n; i++)
        {

            fgetc(stdin);
            inputItems(i);
        }
        do
        {
            cout << "\n1.Item Insert";
            cout << "\n2.Item delete";
            cout << "\n3.Item search ( Linear searching operation )";
            cout << "\n4.Items Display ( Only for operation shows )";
            cout << "\n5.Create Bill";
            cout << "\n\n### without (1,2,3,4,5) keys Press any key to Exit ###";
            cout << "\n\nInput your choise : ";
            cin >> choise_operation;
            switch (choise_operation)
            {
            case 1:
                system("cls");
                insert_item();
                break;

            case 2:
                system("cls");
                delete_item();
                break;
            case 3:
                system("cls");
                search_item();
                break;
            case 4:
                system("cls");
                display();
                break;
            case 5:
                system("cls");
                createBill();
                break;
            default:
                operationExitFunction();

                break;
            }
        } while (exit);

        break;
    default:
        operationExitFunction();
        break;
    }
}
void operationExitFunction()
{
    system("cls");
    cout << "\n\nGood Bye\n";
    cout << "       Have a Good Day :)\n\n";
    exit(0);
}
void createBill()
{
    if (ord.numberofitems == 0)
    {
        cout << "\nThere has no item in the list please Insert item !!\n";
    }
    else
    {
        generate_bill_header();
        bill_body();
        bill_footer();
        exit(0);
    }
}
void generateId(int i)
{

    srand(time(NULL));
    ord.itm[i].id = rand() % 1000;
}

void insert_item()
{

    display();
    int i, position;
    cout << "\nInsert item position : ";
    cin >> position;
    for (i = ord.numberofitems; i >= position; i--)
    {
        strcpy(ord.itm[i + 1].item, ord.itm[i].item);
        ord.itm[i + 1].qty = ord.itm[i].qty;
        ord.itm[i + 1].price = ord.itm[i].price;
        ord.itm[i + 1].id = ord.itm[i].id;
    }

    fgetc(stdin);
    ord.numberofitems = ord.numberofitems + 1;
    generateId(position);
    inputItems(position);
}
void delete_item()
{

    if (ord.numberofitems == 0)
    {
        cout << "\nThere has no item in the list please Insert item !!\n";
    }
    else
    {
        display();
        int i, position;
        cout << "\nRemove Item from the list";
        cout << "\nInput item positin to the list : ";
        cin >> position;
        for (i = position; i < ord.numberofitems; i++)
        {
            strcpy(ord.itm[i].item, ord.itm[i + 1].item);
            ord.itm[i].price = ord.itm[i + 1].price;
            ord.itm[i].qty = ord.itm[i + 1].qty;
        }
        ord.numberofitems = ord.numberofitems - 1;
    }
}

void display()
{
    cout << "\n-----------------------------------------------------------\n";
    cout << "Items\t\t";
    cout << "Id\t\t";
    cout << "Qty\t\t";
    cout << "Total\t\t";
    cout << "\n-----------------------------------------------------------";
    cout << "\n\n";
    bill_body();
}
void inputItems(int i)
{
    cout << "\nEnter the item " << i << " : ";
    fgets(ord.itm[i].item, 20, stdin);
    ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
    cout << "Enter the quantity : ";
    cin >> ord.itm[i].qty;
    cout << "Enter the price : ";
    cin >> ord.itm[i].price;
    generateId(i);
}
void bill_body()
{
    int i;
    ord.total = 0;
    for (i = 1; i <= ord.numberofitems; i++)
    {
        ord.itm[i].pricePerItem = ord.itm[i].qty * ord.itm[i].price;
        ord.total = ord.total + ord.itm[i].pricePerItem;
        cout << ord.itm[i].item << "\t\t";
        cout << ord.itm[i].id << "\t\t";
        cout << ord.itm[i].qty << "\t\t";
        cout << ord.itm[i].pricePerItem << "\n";
    }
}
void search_item()
{
    display();
    int i, itemId, count = 0, foundItem;
    if (ord.numberofitems == 0)
    {
        cout << "Your list is empty !! Please insert items \n";
    }
    else
    {
        cout << "\nInput Item id : ";
        cin >> itemId;
        for (i = 1; i <= ord.numberofitems; i++)
        {
            if (itemId != ord.itm[i].id)
            {
                count++;
            }
            else
            {
                foundItem = i;
            }
        }
        if (count < ord.numberofitems && ord.numberofitems != 0)
        {
            cout << "\nItem is found " << foundItem << " position in the list\n";
        }

        else
        {
            cout << "\nItem is not found in the list !! Please trye again\n";
        }
    }
}
void generate_bill_header()
{
    system("cls");
    cout << "\n\n"
         << "============= Generate Customer Invoice ==============\n";
    cout << "\nDate: " << ord.date;
    cout << "\nInvoice To: " << ord.customer;
    cout << "Cell Number : " << ord.cell_number << "\n\n";
    cout << "------------------------------------------------------\n";
    cout << "Items\t\t";
    cout << "Id\t\t";
    cout << "Qty\t\t";
    cout << "Total\t\t";
    cout << "\n------------------------------------------------------";
    cout << "\n\n";
}
void bill_footer()
{
    ord.total_vat = ord.total * (ord.vat / 100);
    cout << "\n";
    cout << "------------------------------------------------------";
    cout << "\nTotal(Without VAT)";
    cout << "\t\t\t\t" << ord.total;
    cout << "\nVAT\t\t\t\t\t\t" << ord.vat << "\n";
    cout << "-------------------------------------------------------";
    cout << "\nTotal(With VAT)\t\t\t\t\t" << ord.total + ord.total_vat << "\n\n\n";
}
