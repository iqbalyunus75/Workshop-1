#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include<sys/stat.h>
#include<thread>
#include<chrono>
#include <iomanip>
using namespace std;

int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            system("cls");

        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "dbmusic", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            system("cls");

        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

void Prompt();
void StaffLogin();
void ManagerLogin();
void AdminLogin();
void regS();
void regM();
void Exit();
void MenuStaff();
void displayItemS();
void orderItemS();
void SoldItems();
void MenuManager();
void addItemM();
void deleteItemM();
void editItemM();
void displayItemM();
void MenuAdmin();
void deleteStaff();
void changeManager();

int main()
{
    system("cls");
    system("title DoReMi Music Store Management System");
    system("color 0f");

    db_response::ConnectionFunction();

    Prompt();


}

void Prompt()
{
    system("cls");
    int choose;

    cout << "\n                    ************************************************************************* ";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |         .: WELCOME TO DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.     |";
    cout << "\n                   |         ===========================================================     |";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |                      PLEASE CHOOSE YOUR ACCOUNT TYPE:                   |";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |               (1. STAFF | 2. MANAGER | 3. ADMIN | 4. EXIT)              |";
    cout << "\n                   |                                                                         |";
    cout << "\n                    ************************************************************************* ";
    cout << "\n                                                 CHOOSE --> ";
    cin >> choose;
    system("cls");

    switch (choose)
    {
    case 1:
        StaffLogin();
        break;
    case 2:
        ManagerLogin();
        break;
    case 3:
        AdminLogin();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << " ================================================== ";
        cout << "\n ERROR!! PLEASE CHOOSE FROM 1 - 4. ";
        cout << "\n ================================================== ";
        std::this_thread::sleep_for(3s);
        Prompt();
        break;
    }
}

void StaffLogin()
{
    system("cls");
    string staffid, staffpass = "";
    char c;
    cout << "\n                    ****************************************************************** ";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |    .: WELCOME TO DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.   |";
    cout << "\n                   |    ===========================================================   |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |                PLEASE LOGIN TO ENTER THE SYSTEM                  |";
    cout << "\n                   |                                                                  |";
    cout << "\n                    ****************************************************************** ";
    cout << "\n                                                                  ";
    cout << "\n                                              STAFF ID :  ";
    cin >> staffid;
    cout << "                                              PASSWORD : ";

p:
    c = _getch();
    cout << "*";
    if (c != 13)
    {
        staffpass = staffpass + c;
        goto p;
    }

    qstate = mysql_query(conn, "select staff_id, staff_password, staff_fname, staff_lname from staff_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {

            if (staffid == row[0] && staffpass == row[1])
            {
                system("cls");
                cout << " ================================================== ";
                cout << " \n ACCESS GRANTED!!! WELCOME " << row[2] << " " << row[3];
                cout << "\n ================================================== ";
                std::this_thread::sleep_for(3s);
                MenuStaff();

            }
        }

        char ka;
        system("cls");
        cout << "\n ======================================================================================== ";
        cout << "\n ACCESS DENIED!!! USERNAME AND PASSWORD NOT FOUND IN DATABASE!!!";
        cout << "\n ======================================================================================== ";
        cout << "\n PRESS m TO GO BACK OR r TO LOGIN AGAIN. \n";
        cin >> ka;
        switch (ka)
        {
        case 'm':
        case 'M':
            system("cls");
            Prompt();
            break;
        case 'r':
        case 'R':
            system("cls");
            StaffLogin();
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuStaff();
        }
    }
    else
    {
        cout << "\n\n Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

void ManagerLogin()
{
    system("cls"); 
    string managerid, managerpass = "";
    char c;


    cout << "\n                    ****************************************************************** ";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |    .: WELCOME TO DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.   |";
    cout << "\n                   |    ===========================================================   |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |                PLEASE LOGIN TO ENTER THE SYSTEM                  |";
    cout << "\n                   |                                                                  |";
    cout << "\n                    ****************************************************************** ";
    cout << "\n                                                                  ";
    cout << "\n                                              MANAGER ID :  ";
    cin >> managerid;
    cout << "                                              PASSWORD   : ";

p:
    c = _getch();
    cout << "*";
    if (c != 13)
    {
        managerpass = managerpass + c;
        goto p;
    }

    qstate = mysql_query(conn, "select manager_id, manager_password, manager_fname, manager_lname from manager_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {

            if (managerid == row[0] && managerpass == row[1])
            {
                system("cls");
                cout << " ================================================== ";
                cout << " \n ACCESS GRANTED!!! WELCOME " << row[2] << " " << row[3];
                cout << "\n ================================================== ";
                std::this_thread::sleep_for(3s);
                MenuManager();

            }
        }

        char ka;
        system("cls");
        cout << "\n ======================================================================================== ";
        cout << "\n ACCESS DENIED!!! USERNAME AND PASSWORD NOT FOUND IN DATABASE!!!";
        cout << "\n ======================================================================================== ";
        cout << "\n PRESS m TO GO BACK OR r TO LOGIN AGAIN. \n";
        cin >> ka;
        switch (ka)
        {
        case 'm':
        case 'M':
            system("cls");
            Prompt();
            break;
        case 'r':
        case 'R':
            system("cls");
            ManagerLogin();
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuManager();
        }
    }
    else
    {
        cout << "\n\n Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}

void AdminLogin()
{
    system("cls");
    string adminid, adminpass = "";
    char c;
    cout << "\n                    ****************************************************************** ";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |    .: WELCOME TO DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.   |";
    cout << "\n                   |    ===========================================================   |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |                PLEASE LOGIN TO ENTER THE SYSTEM                  |";
    cout << "\n                   |                                                                  |";
    cout << "\n                    ****************************************************************** ";
    cout << "\n                                                                  ";
    cout << "\n                                              ADMIN ID :  ";
    cin >> adminid;
    cout << "                                              PASSWORD : ";

p:
    c = _getch();
    cout << "*";
    if (c != 13)
    {
        adminpass = adminpass + c;
        goto p;
    }

    qstate = mysql_query(conn, "select admin_id, admin_password, admin_fname, admin_lname from admin_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {

            if (adminid == row[0] && adminpass == row[1])
            {
                system("cls");
                cout << " ================================================== ";
                cout << " \n ACCESS GRANTED!!! WELCOME " << row[2] << " " << row[3];
                cout << "\n ================================================== ";
                std::this_thread::sleep_for(3s);
                MenuAdmin();

            }
        }

        char ka;
        system("cls");
        cout << "\n ======================================================================================== ";
        cout << "\n ACCESS DENIED!!! USERNAME AND PASSWORD NOT FOUND IN DATABASE!!!";
        cout << "\n ======================================================================================== ";
        cout << "\n PRESS m TO GO BACK OR r TO LOGIN AGAIN. \n";
        cin >> ka;
        switch (ka)
        {
        case 'm':
        case 'M':
            system("cls");
            Prompt();
            break;
        case 'r':
        case 'R':
            system("cls");
            AdminLogin();
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuAdmin();
        }
    }
    else
    {
        cout << "\n\n Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

void regS()
{
    system("cls");

    string id = "";
    string pass = "";
    string fname = "";
    string lname = "";
    char choose;

    cout << "Welcome To Music Store" << endl << endl;
    cout << "Add Your Detail Here" << endl << endl;

    cin.ignore(1, '\n');
    cout << "Enter ID: ";
    getline(cin, id);
    cout << "Enter Password: ";
    getline(cin, pass);
    cout << "Enter First Name: ";
    getline(cin, fname);
    cout << "Enter Last Name: ";
    getline(cin, lname);


    string insert_query = "insert into staff_table (staff_id, staff_password, staff_fname, staff_lname) values ('" + id + "','" + pass + "','" + fname + "','" + lname + "')";

    const char* q = insert_query.c_str();

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully Registered." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << "Press 'm' to go to Menu: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuAdmin();
    }
    else
    {
        exit(0);
    }
}

void regM()
{
    system("cls");

    string id = "";
    string password = "";
    string fname = "";
    string lname = "";
    string items[50];
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    string storeid = "";
    string storepassword = "";
    string storefname = "";
    string storelname = "";

    cout << "Welcome To Music Store" << endl << endl;
    cout << "Edit Item Menu" << endl << endl;

    qstate = mysql_query(conn, "select manager_id, manager_password from manager_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "ID\tPassword\n" << endl;
        while ((row = mysql_fetch_row(res)))
        {
            cout << row[0] << "\t" << row[1] << endl;
            items[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Manager ID: ";
        cin >> id;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << id;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from manager_table where manager_id = '" + strid + "'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "================================================\n" << "Manager ID: " << "\t\t" << row[0] << "\nManager Password: " << "\t" << row[1] << "\nManager First Name: " << "\t\t" << row[2] << "\nManager Last Name: " << "\t\t" << row[3] << "\n================================================\n" << endl << endl;
                    storeid = row[0];
                    storepassword = row[1];
                    storefname = row[2];
                    storelname = row[3];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter New Manager ID (xN to not change): ";
            getline(cin, id);
            if (id == "xN")
            {
                id = storeid;
            }
            cout << "Enter New Manager Password (xN to not change): ";
            getline(cin, password);
            if (password == "xN")
            {
                password = storepassword;
            }
            cout << "Enter Manager First Name (xN to not change): ";
            getline(cin, fname);
            if (fname == "xN")
            {
                fname = storefname;
            }
            cout << "Enter Manager Last Name (xN to not change): ";
            getline(cin, lname);
            if (lname == "xN")
            {
                lname = storelname;
            }

            string update_query = "update manager_table set manager_id = '" + id + "', manager_password = '" + password + "', manager_fname = '" + fname + "', manager_lname = '" + lname + "'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuAdmin();
    }
    else if (choose == 'e' || choose == 'E')
    {
        regM();
    }
    else
    {
        exit(0);
    }
}

void Exit()
{
    system("cls"); 
    string answer;
    string y, n;
    cout << "ARE YOU SURE YOU WANT TO EXIT ?? [Y = YES / N = NO]";
    cout << "\n Answer: ";
    cin >> answer;

    if (answer == y)
    {
        exit(0);
    }
    else
    {
        Prompt();
    }
}

void MenuStaff()
{
    system("cls");
    int opt = 0;
    char exit;
    cout << "\n  ************************************************** ";
    cout << "\n |                --------------                    |";
    cout << "\n |                  STAFF MENU                      |";
    cout << "\n |                --------------                    |";
    cout << "\n |                                                  |";
    cout << "\n | 1. CHECK STOCK                                   |";
    cout << "\n | 2. CREATE ORDERS                                 |";
    cout << "\n | 3. CHECK ALBUM SALES                             |";
    cout << "\n | 4. EXIT                                          |";
    cout << "\n |                                                  |";
    cout << "\n  ************************************************** \n";

    cout << " \n\n PLEASE CHOOSE : ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        displayItemS();
        break;

    case 2:
        orderItemS();
        break;

    case 3:
        SoldItems();

    case 4:
    ExitProgram:
        cout << "\n ARE YOU SURE YOU WANT TO EXIT ?? [Y = YES // N = NO]";
        cout << "\n ===>> ";
        cin >> exit;
        if (exit == 'y' || exit == 'Y') {
            Prompt();
        }
        else if (exit == 'n' || exit == 'N') {
            system("cls");
            MenuStaff();
        }
        else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "ERROR !! PLEASE TRY AGAIN. ";
        break;
    }
}

void displayItemS()
{
    system("cls");
    char choose;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                    ALL ALBUM LIST                   " << endl << endl;

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", "ALBUM ID", "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << endl << endl;
    cout << "PRESS <M> TO GO BACK TO MENU // PRESS ANY BUTTON TO EXIT\n";
    cout << "===>> ";
    cin >> choose;

    if (choose == 'm' || choose == 'M')
    {
        MenuStaff();
    }
    else
    {
        exit(0);
    }
}

void orderItemS()
{
    system("cls");
    char choose;
    string getId = "";
    string itemId[50];
    string itemName[50];
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    bool purchase{}, itemFalse = false;

    string storeid[50];
    string storetitle[50];
    string storeartist[50];
    string storegenre[50];
    string storeprice[50];
    string storequantity[50];
    int storeIndex = 0, storeIndexN = 0;

    cout << "Welcome To DoReMi Music Store Management System" << endl << endl;
    cout << "Menu" << endl;

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        cout << "---------------------------------------------------------------------------------------------------------\n";
        printf("| %-10s | %-20s | %-15s | %-15s | %-15s | %-5s |\n", "Album Id", "Album Title", "Album Artist", "Album Genre", "Album Price", "Quantity");
        cout << "---------------------------------------------------------------------------------------------------------\n";
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[5]) > 0)
            {
                printf("| %-10s | %-20s | %-15s | %-15s | %-15s | %-7s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
                cout << endl;

                storeid[storeIndex] = row[0];
                storetitle[storeIndex] = row[1];
                storeartist[storeIndex] = row[2];
                storegenre[storeIndex] = row[3];
                storeprice[storeIndex] = row[4];
                storequantity[storeIndex] = row[5];
                storeIndex++;
            }
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    for (itemIndex = 0;; itemIndex++)
    {
        cout << "Enter an Album ID's (q to exit): ";
        cin >> getId;
        if (getId == "q")
        {
            break;
        }
        else
        {
            for (int i = 0; i < storeIndex; i++)
            {
                if (getId == storeid[i])
                {
                    itemId[itemIndex] = getId;
                    itemFalse = false;
                    break;
                }
                else
                {
                    itemFalse = true;
                }
            }
            if (itemFalse == true)
            {
                cout << "Enter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        }
    }

    cout << "You choose this song id's: ";
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << " ";
    }

CHOOSEEDITORBUY:
    cout << endl << "Do you want to edit items(e) or buy this items(b): ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == 'e')
    {
        for (int i = 0;; i++)
        {
            cout << "Remove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }
            else
            {
                for (int j = 0; j < itemIndex; j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k + 1];
                        }
                        itemId[itemIndex--] = "\0";
                    }
                }
            }
        }

        cout << "You choose this song id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << itemId[i] << " ";
        }

        goto CHOOSEEDITORBUY;
    }
    else if (chooseEditOrBuy == 'b')
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0; j < storeIndex; j++)
            {
                if (itemId[i] == storeid[j])
                {
                    qstate = mysql_query(conn, "select album_quantity from album_table");
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)))
                        {
                            if (atoi(row[0]) > 0)
                            {
                                storequantity[storeIndexN] = row[0];
                                storeIndexN++;
                            }
                        }
                        storeIndexN = 0;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }

                    totalPrice += strtof((storeprice[j]).c_str(), 0);

                    float quan1 = strtof((storequantity[j]).c_str(), 0);
                    quan1 -= 1;
                    float quan2 = strtof((storequantity[j]).c_str(), 0);
                    float quan = quan2 - quan1;
                    string getResult;
                    stringstream strquan;
                    strquan << quan;
                    strquan >> getResult;

                    string getQuan1;
                    stringstream strquan1;
                    strquan1 << quan1;
                    strquan1 >> getQuan1;

                    string insert_query = "insert into soldalbum_table (album_title, album_artist, album_genre, album_price, album_quantity) values ('" + storetitle[j] + "','" + storeartist[j] + "','" + storegenre[j] + "','" + storeprice[j] + "','" + getResult + "')";
                    purchase = true;

                    //cout << insert_query << endl;


                    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

                    qstate = mysql_query(conn, q);

                    if (!qstate)
                    {
                        purchase = true;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }


                    string update_query = "update album_table set album_quantity = '" + getQuan1 + "' where album_id = '" + storeid[j] + "'";
                    const char* qu = update_query.c_str();
                    //cout << update_query << endl;

                    qstate = mysql_query(conn, qu);

                    if (qstate)
                    {
                        cout << "Failed To Update!" << mysql_errno(conn) << endl;
                    }
                }
            }
        }

        if (purchase == true)
        {
            cout << endl << "Purchase Successfully Done." << endl;
            cout << endl << "Total Price: " << totalPrice << endl;
        }
    }

    // Exit Code
    cout << endl << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuStaff();
    }
    else
    {
        exit(0);
    }
}

void SoldItems()
{
    system("cls");

    char choose;
    string input;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                   SOLD ALBUM LIST                   " << endl << endl;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-30s | %-30s | %-30s | %-30s | %-30s | %-30s |\n",  "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY SOLD", "DATE");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select album_title, album_artist, album_genre, album_price, sum(album_quantity), album_solddate from soldalbum_table group by album_solddate, album_title");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-30s | %-30s | %-30s | %-30s | %-30s | %-30s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << endl << endl;
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuStaff();
    }
    else
    {
        exit(0);
    }
}

void MenuManager()
{
    system("cls");
    int opt = 0;
    char exit;
    cout << "\n  ************************************************** ";
    cout << "\n |                --------------                    |";
    cout << "\n |                 MANAGER MENU                     |";
    cout << "\n |                --------------                    |";
    cout << "\n |                                                  |";
    cout << "\n | 1. ADD STOCK                                     |";
    cout << "\n | 2. DELETE STOCK                                  |";
    cout << "\n | 3. EDIT STOCK INFORMATION                        |";
    cout << "\n | 4. DISPLAY ITEM                                  |";
    cout << "\n | 5. EXIT                                          |";
    cout << "\n |                                                  |";
    cout << "\n |                                                  |";
    cout << "\n  ************************************************** \n";

    cout << " \n\n PLEASE CHOOSE : ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        addItemM();
        break;
    case 2:
        deleteItemM();
        break;
    case 3:
        editItemM();
        break;
    case 4:
        displayItemM();
        break;
    case 5:
    ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exit;
        if (exit == 'y' || exit == 'Y') {
            Prompt();
        }
        else if (exit == 'n' || exit == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "ERROR !! PLEASE TRY AGAIN. ";
        break;
    }

}

void addItemM()
{
    system("cls");

    string title = "";
    string genre = "";
    string artist = "";
    float price = 0.0;
    int quantity = 0;
    char choose;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     ADD NEW ALBUM                     " << endl << endl;

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", "ALBUM ID", "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    cout << endl << endl;
    cin.ignore(1, '\n');
    cout << "Enter Album Title: ";
    getline(cin, title);
    cout << "Enter Album Artist: ";
    getline(cin, artist);
    cout << "Enter Album Genre: ";
    getline(cin, genre);
    cout << "Enter Album Price: ";
    cin >> price;
    cout << "Enter Album Quantity: ";
    cin >> quantity;

    stringstream streamPrice, streamQuan;
    string sprice, squan;
    streamPrice << price;
    streamPrice >> sprice;
    streamQuan << quantity;
    streamQuan >> squan;


    string insert_query = "insert into album_table (album_title, album_artist, album_genre, album_price, album_quantity) values ('" + 
        title + "','" + artist + "','" + genre + "','" + sprice + "','" + squan + "')";

    const char* q = insert_query.c_str();

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        addItemM();
    }
    else
    {
        exit(0);
    }
}

void deleteItemM()
{
    system("cls");
    
    char choose;
    int itemId;
    string items[50];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     DELETE ALBUM                     " << endl << endl;

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", "ALBUM ID", "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from album_table where album_id = '" + strid + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'd' || choose == 'D')
    {
        deleteItemM();
    }
    else
    {
        exit(0);
    }
}

void editItemM()
{
    system("cls");

    string id = "";
    string title = "";
    string genre = "";
    string artist = "";
    string items[50];
    string price = "";
    string quantity = "";
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    string storeid = "";
    string storetitle = "";
    string storegenre = "";
    string storeartist = "";
    string storeprice = "";
    string storequantity = "";

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                EDIT ALBUM INFORMATION                " << endl << endl;

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", "ALBUM ID", "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from album_table where album_id = '" + strid + "'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                cout << endl;
                while ((row = mysql_fetch_row(res)))
                {
                    cout << "================================================\n" << "ALBUM ID\t: " << "\t" << row[0] << "\nALBUM TITLE\t: " << "\t" << row[1] << "\nALBUM ARTIST\t: " << "\t" << row[2] << "\nALBUM GENRE\t: " << "\t" << row[3] << "\nALBUM PRICE\t: " << "\t" << row[4] << "\nQUANTITY\t: " << "\t" << row[5] << "\n================================================\n" << endl << endl;
                    storeid = row[0];
                    storetitle = row[1];
                    storeartist = row[2];
                    storegenre = row[3];
                    storeprice = row[4];
                    storequantity = row[5];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            cout << "Enter New Album Title (Type [-] to not change): ";
            getline(cin, title);
            if (title == "-")
            {
                title = storetitle;
            }
            cout << "Enter New Album Artist (Type [-] to not change): ";
            getline(cin, artist);
            if (artist == "-")
            {
                artist = storeartist;
            }
            cout << "Enter New Album Genre (Type [-] to not change): ";
            getline(cin, genre);
            if (genre == "-")
            {
                genre = storegenre;
            }
            cout << "Enter New Album Price (Type [-] to not change): ";
            cin >> price;
            if (price == "-")
            {
                price = storeprice;
            }
            cout << "Enter New Album Quantity (Type [-] to not change): ";
            cin >> quantity;
            if (quantity == "-")
            {
                quantity = storequantity;
            }

            string update_query = "update album_table set album_title = '" + title + "', album_artist = '" + artist + "', album_genre = '" + 
                genre + "', album_price = '" + price + "', album_quantity = '" + quantity + "' where album_id = '" + strid + "'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'e' || choose == 'E')
    {
        editItemM();
    }
    else
    {
        exit(0);
    }
}

void displayItemM()
{
    system("cls");
    char choose;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     ALL ALBUM LIST                   " << endl << endl;

    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", "ALBUM ID", "ALBUM TITLE", "ALBUM ARTIST", "ALBUM GENRE", "PRICE", "QUANTITY");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select * from album_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << endl << endl;
    cout << "PRESS <M> TO GO BACK TO MENU // PRESS ANY BUTTON TO EXIT\n";
    cout << "===>> ";
    cin >> choose;

    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else
    {
        exit(0);
    }
}

void MenuAdmin()
{
    system("cls");
    int opt = 0;
    char exit;
    cout << "\n  ************************************************** ";
    cout << "\n |                --------------                    |";
    cout << "\n |                  ADMIN MENU                      |";
    cout << "\n |                --------------                    |";
    cout << "\n |                                                  |";
    cout << "\n | 1. NEW STAFF REGISTRATION                        |";
    cout << "\n | 2. CHANGE NEW MANAGER                            |";
    cout << "\n | 3. DELETE STAFF INFORMATION                      |";
    cout << "\n | 4. EXIT                                          |";
    cout << "\n |                                                  |";
    cout << "\n |                                                  |";
    cout << "\n  ************************************************** \n";

    cout << " \n\n PLEASE CHOOSE : ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        regS();
        break;

    case 2:
        changeManager();
        break;

    case 3:
        deleteStaff();
        break;

    case 4:
    ExitProgram:
        cout << "\n ARE YOU SURE YOU WANT TO EXIT ?? [Y = YES // N = NO]";
        cout << "\n ===>> ";
        cin >> exit;
        if (exit == 'y' || exit == 'Y') {
            Prompt();
        }
        else if (exit == 'n' || exit == 'N') {
            system("cls");
            MenuStaff();
        }
        else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "ERROR !! PLEASE TRY AGAIN. ";
        break;
    }
}

void deleteStaff()
{
    system("cls");

    char choose;
    string staffId;
    string staff[50];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |  .: DoReMi MUSIC STORE SALES MANAGEMENT SYSTEM :.  |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                DELETE STAFF INFORMATION              " << endl << endl;

    printf("------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-30s | %-30s |\n", "STAFF ID", "STAFF FIRST NAME", "STAFF LAST NAME");
    printf("------------------------------------------------------------------------------------\n");

    qstate = mysql_query(conn, "select staff_id, staff_fname, staff_lname from staff_table");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-30s | %-30s |\n", row[0], row[1], row[2]);
            staff[indexForId] = row[0];
            indexForId++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Staff ID: ";
        cin >> staffId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << staffId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != staff[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from staff_table where staff_id = '" + strid + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuAdmin();
    }
    else if (choose == 'd' || choose == 'D')
    {
        deleteStaff();
    }
    else
    {
        exit(0);
    }
}

void changeManager()
{
    system("cls");

    string id = "";
    string pass = "";
    string fname = "";
    string lname = "";
    string items[500];
    char choose;
    string itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storefname = "";
    string storelname = "";
    string storepass = "";
    char c;
    // Variables End


    cout << "\n                                                     CHANGE NEW MANAGER                   \n\n";

    qstate = mysql_query(conn, "select * from manager_table");
    if (!qstate)
    {
        string a;
        int c;

        res = mysql_store_result(conn);
        printf("-----------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-20s | %-30s | %-30s |\n", "MANAGER ID", "MANAGER PASSWORD", "MANAGER FIRST NAME", "MANAGER LAST NAME");
        printf("-----------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            string str = row[1];
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-15s | %-20s | %-30s | %-30s |\n", row[0], a, row[2], row[3]);
        }
        printf("-----------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;

        cout << "Enter Manager ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false) {


        string findbyid_query = "select * from manager_table where manager_id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID\t\t: " << row[0]
                    << "\nPassword\t: " << row[1]
                    << "\nFirst Name\t: " << row[2]
                    << "\nLast Name\t: " << row[3]
                    << endl << endl;

                storeid = row[0];
                storepass = row[1];
                storefname = row[2];
                storelname = row[3];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        cin.ignore(1, '\n');
        string defaultString = "-";
        cout << "Enter ID (" << defaultString << "Type [-] to not change): ";
        getline(cin, id);
        if (id == defaultString)
        {
            id = storeid;
        }
        cout << endl;
        cout << "Enter Password (" << defaultString << "Type [-] to not change): ";
    p:
        c = _getch();
        cout << "*";   //for printing * instead for password
        if (c != 13)
        {
            pass = pass + c;  //for concatenating the string
            goto p;
        }
        if (pass == defaultString)
        {
            pass = storepass;
        }
        cout << endl;
        cout << endl;
        cout << "Enter First Name (" << defaultString << "Type [-] to not change): ";
        getline(cin, fname);
        if (fname == defaultString)
        {
            fname = storefname;
        }

        cout << endl;
        cout << endl;
        cout << "Enter Last Name (" << defaultString << "Type [-] to not change): ";
        getline(cin, lname);
        if (lname == defaultString)
        {
            lname = storelname;
        }

        string update_query = "update manager_table set manager_id = '" + id + "', manager_password = '" + pass + "', manager_fname = '" + fname + "', manager_lname = '" + lname + "' where manager_id = '" + itemId + "'";
        const char* qu = update_query.c_str();
        qstate = mysql_query(conn, qu);

        if (!qstate)
        {
            cout << endl << "Successfully Updated." << endl;
        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }


    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuAdmin();
    }
    else if (choose == 'e' || choose == 'E')
    {
        changeManager();
    }
    else
    {
        exit(0);
    }
}