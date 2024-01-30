#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <conio.h>
using namespace std;

class BookShop
{

protected:
    string book_id;
    string book_name;
    string author_name;
    int book_price;
    int book_quantity;

public:
    void main_menu();
    void administrator();
    void buyer();
    void add_file();
    void edit_file();
    void remove_file();
    void receipt();
    void file_list();
};

void BookShop::main_menu()
{
m:
    string username;
    int password;
    char choice;

    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|                    BookShop Main Menu                   |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "\tPress 1) for Administrator menu " << endl;
    cout << "\tPress 2) for Buyer menu " << endl;
    cout << "\tPress 3) for Exit program " << endl;

    choice = getch();
    switch (choice)
    {
    case 49:
        cout << "\tPlease login as administrator \n"
             << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if ((username == "waqas") && (password == 123))
        {
            administrator();
        }
        else
        {
            cout << "Invalid username/Password" << endl;
        }
        break;
    case 50:
        buyer();
        break;
    case 51:
        exit(0);
    default:
        cout << "Please select from given options" << endl;
    }

    goto m;
}

void BookShop::administrator()
{

m:
    char choice;
    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|                   Administrator Menu                    |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "\tPress 1) to Add a new book " << endl;
    cout << "\tPress 2) to Modify an excisting book" << endl;
    cout << "\tPress 3) to Remove an excisting book" << endl;
    cout << "\tPress 4) for Back to main menu" << endl;
    cout << "\tPress 5) to look at excisting books" << endl;
    choice = getch();
    switch (choice)
    {
    case 49:
        add_file();
        break;
    case 50:
        edit_file();
        break;
    case 51:
        remove_file();
        break;
    case 52:
        main_menu();
        break;
    case 53:
        file_list();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
    goto m;
}
void BookShop::buyer()
{
m:
    char choice;
    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|                        Buyer Menu                       |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "Press 1) to Buy a book " << endl;
    cout << "Press 2) for back to main menu " << endl;
    choice = getch();
    switch (choice)
    {
    case 49:
        receipt();
        break;
    case 50:
        main_menu();
    default:
        cout << "Invalid choice!" << endl;
    }
    goto m;
}

void BookShop::add_file()
{
m:
    fstream myfile;
    string id;
    string name;
    string author;
    int price;
    int quantity;
    int token = 0;

    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|                  Menu to Add new Book                   |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "Enter book id: ";
    cin >> book_id;
    cout << "Enter book name: ";
    cin >> book_name;
    cout << "Enter author name: ";
    cin >> author_name;
    cout << "Enter book price: ";
    cin >> book_price;
    cout << "Enter book quantity: ";
    cin >> book_quantity;

    myfile.open("Database.txt", ios::in);

    if (!myfile)
    {
        myfile.open("Database.txt", ios::app | ios::out);
        myfile << " " << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << "\n";
        myfile.close();
    }
    else
    {
        myfile >> id >> name >> author >> price >> quantity;
        while (!myfile.eof())
        {
            if (id == book_id)
            {
                token++;
            }
            myfile >> id >> name >> author >> price >> quantity;
        }
        myfile.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            myfile.open("Database.txt", ios::app | ios::out);
            myfile << " " << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << "\n";
            myfile.close();
        }
    }
    cout << "Record of Books is Inserted!!" << endl;
}

void BookShop::edit_file()
{

    fstream myfile, myfile1;
    string new_id;
    string id;
    string name;
    string author;
    int price;
    int quantity;
    int token = 0;

    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|               Menu to Add in Existing Book              |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "Enter book id: ";
    cin >> new_id;
    myfile.open("Database.txt", ios::in);
    if (!myfile)
    {
        cout << "Files not found " << endl;
    }
    else
    {
        myfile1.open("Database1.txt", ios::app | ios::out);
        myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
        while (!myfile.eof())
        {
            if (new_id == book_id)
            {
                cout << "Enter book New id: ";
                cin >> id;
                cout << "Enter new name of book: ";
                cin >> name;
                cout << "Enter new author name of book: ";
                cin >> author;
                cout << "Enter new price of book: ";
                cin >> price;
                cout << "Enter new quantity of book: ";
                cin >> quantity;
                myfile1 << " " << id << " " << name << " " << author << " " << price << " " << quantity << "\n";
                cout << "File Edited !!" << endl
                     << endl;
                token++;
            }
            else
            {
                myfile1 << " " << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << "\n";
            }
            myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
        }
        myfile.close();
        myfile1.close();
        remove("Database.txt");
        rename("Database1.txt", "Database.txt");
        if (token == 0)
        {
            cout << "Record not found!!" << endl
                 << endl;
        }
    }
}

void BookShop::remove_file()
{
    fstream myfile, myfile1;
    string new_id;
    int token = 0;
    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|              Menu to Remove Existing Book               |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << "Enter book id: ";
    cin >> new_id;
    myfile.open("Database.txt", ios::in);
    if (!myfile)
    {
        cout << "Files not found " << endl;
    }
    else
    {
        myfile1.open("Database1.txt", ios::app | ios::out);
        myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
        while (!myfile.eof())
        {
            if (new_id == book_id)
            {
                cout << "File deleted successfully" << endl;
                token++;
            }
            else
            {
                myfile1 << " " << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << "\n";
            }
            myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
        }
        myfile.close();
        myfile1.close();
        remove("Database.txt");
        rename("Database1.txt", "Database.txt");
        if (token == 0)
        {
            cout << "Record not found!!" << endl;
        }
    }
}

void BookShop::file_list()
{
    fstream myfile;
    myfile.open("Database.txt", ios::in);
    cout << "---------------------------------------------------------------------------------------------------\n";
    cout << "Book_ID"
         << setw(20)
         << "Book Name"
         << setw(20)
         << "Book Author"
         << setw(20)
         << "Book price"
         << setw(20)
         << "Book quantity"
         << endl;
    cout << "---------------------------------------------------------------------------------------------------\n";
    myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
    while (!myfile.eof())
    {
        cout << book_id << setw(20) << book_name << setw(20) << author_name << setw(20) << book_price << setw(20) << book_quantity << "\n";
        myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
    }
    myfile.close();
}

void BookShop::receipt()
{
    fstream myfile;
    string id_array[100];
    int quantity_array[100];
    char cardtype;
    int card_dis;
    char choice;
    int c = 0;
    float amount = 0;
    int new_dis;
    float dis;
    float total;
    float grandtotal = 0;
    cout << endl
         << endl;
    cout << "|---------------------------------------------------------|\n";
    cout << "|                                                         |\n";
    cout << "|            Receipt Generator Menu for buyer             |\n";
    cout << "|                                                         |\n";
    cout << "|---------------------------------------------------------|\n";
    cout << endl;
    myfile.open("Database.txt", ios::in);
    if (!myfile)
    {
        cout << "Empty Database of Books" << endl;
    }
    else
    {
        myfile.close();
        file_list();
        cout << endl
             << endl;
        cout << "|---------------------------------------------------------|\n";
        cout << "|                                                         |\n";
        cout << "|             Please Place your order                     |\n";
        cout << "|                                                         |\n";
        cout << "|---------------------------------------------------------|\n";

        cout << "Enter your card Type:";
        cout << "[ Press: (P for Platimum) | (G for Gold) | (S for silver) ] " << endl
             << endl;
        cardtype = getch();
        if (cardtype == 112 || cardtype == 80)
        {
            dis = 15;
            card_dis = 15;
        }
        else if (cardtype == 103 || cardtype == 71)
        {
            dis = 10;
            card_dis = 10;
        }
        else if (cardtype == 115 || cardtype == 83)
        {
            dis = 5;
            card_dis = 5;
        }

        do
        {
        m:
            cout << "\nEnter ID of Book to order: " << endl;
            cin >> id_array[c];
            cout << "\nEnter Quantity of Book: " << endl;
            cin >> quantity_array[c];
            for (int i = 0; i < c; i++)
            {
                if (id_array[i] == id_array[c])
                {
                    cout << "\nBook already ordered";
                    goto m;
                }
            }
            c++;
            cout << "If you want to Continue puchasing the books?( If yes,then enter \"y\"),(Else no, then enter\"n\")  ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
        cout << "\n\t\t---------------------------------------------------------\n";

        cout << "\n\t\t                   Buyer Receipt                         \n";

        cout << "\n\t\t---------------------------------------------------------\n"
             << endl;
        cout << "Book_id" << setw(20) << "Book name" << setw(20) << "Book quantity" << setw(20) << "Book price" << setw(20) << "toatl amount" << setw(18) << "  toatl amount with discount \n";
        new_dis = dis;
        for (int i = 0; i < c; i++)
        {
            dis = new_dis;
            myfile.open("Database.txt", ios::in);
            fstream tempFile("temp.txt", ios::out);

            myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
            while (!myfile.eof())
            {
                if (book_id == id_array[i])
                {
                    new_dis = 0;
                    amount = book_price * quantity_array[i];
                    dis = amount - (amount * (dis / 100));

                    book_quantity -= quantity_array[i];

                    tempFile << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << endl;

                    total = total + dis;
                    grandtotal = grandtotal + amount;
                    cout << book_id << setw(25) << book_name << setw(15) << quantity_array[i] << setw(20) << book_price << setw(20) << amount << setw(20) << total << endl;
                }
                else
                {

                    tempFile << book_id << " " << book_name << " " << author_name << " " << book_price << " " << book_quantity << endl;
                }

                myfile >> book_id >> book_name >> author_name >> book_price >> book_quantity;
            }

            myfile.close();
            tempFile.close();

            remove("Database.txt");
            rename("temp.txt", "Database.txt");
        }
    }

    cout << "\n Discoutn offered: " << card_dis << "%\n";
    cout << "\n|--------------------------------|\n"
         << endl;
    cout << "|         Total price: " << grandtotal << " Rs/-   " << endl;
    cout << "\n|--------------------------------|" << endl
         << endl;
}

int main()
{
    BookShop b;
    b.main_menu();
    return 0;
}