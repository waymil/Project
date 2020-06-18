#include "Order.h"
#include "InOrder.h"
#include "OutOrder.h"
#include "List.h"

void menu();
int getNumber(int total);

int main()
{
    List list;
    int num;
    string n, b, i;
    int d, m, y, dc, s;
    float v;
    //Information about the organization
    string organization = "OOO Dallas";
    int balance = 500000;
    do{
        menu();
        num = getNumber(6);
        switch(num)
        {
            case 1:
                do{
                    cout << "1. INCOMING CASH WARRANT" << endl;
                    cout << "2. OUTCOMING CASH WARRANT" << endl;
                    num = getNumber(2);
                    switch(num)
                    {
                        case 1:{
                            cout << "<Fill in the following fields>" << endl;
                            cout << "Name: ";
                            getline(cin, n);
                            cout << "Base: ";
                            getline(cin, b);
                            cout << "Sum: ";
                            cin >> s;
                            cout << "Date(enter a space between day, month, year): ";
                            cin >> d >> m >> y;
                            cout << "Document Number: ";
                            cin >> dc;
                            cout << "VAT (if not, enter 0): ";
                            cin >> v;
                            InOrder cell(n, b, d, m, y, dc, s, v);
                            cell.print(organization);
                            list.add(n, d, m, y, s);
                            balance = balance + s;
                            break;
                        }
                        case 2:
                            cout << "<Fill in the following fields>" << endl;
                            cout << "Name: ";
                            getline(cin, n);
                            cout << "Base: ";
                            getline(cin, b);
                            cout << "Sum: ";
                            cin >> s;
                            cout << "Date(enter a space between day, month, year): ";
                            cin >> d >> m >> y;
                            cout << "Document Number: ";
                            cin >> dc;
                            cout << "Passport details: ";
                            cin >> i;
                            OutOrder cell(n, b, d, m, y, dc, s, i);
                            cell.print(organization);
                            list.add(n, d, m, y, s);
                            balance = balance - s;
                            break;
                    }
                    cout << "1. Create another cash order" << endl;
                    cout << "2. Return to the menu" << endl;
                    num = getNumber(2);
                } while(num != 2);
                break;
            case 2:
                list.show();
                if (list.empty() == 0)
                {
                    cout << "<Do you want to save the operation history to a file?>" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No, return to the menu" << endl;
                    num = getNumber(2);
                    if (num == 1)
                    {
                        list.savefile();
                    }
                }
                break;
            case 3:
                cout << "Balance on today: " << balance << endl;
                break;
            case 4:
                cout << "<Search by>" << endl;
                cout << "1. month" << endl;
                cout << "2. year" << endl;
                cout << "3. name" << endl;
                cout << "4. amount of money" << endl;
                num = getNumber(4);
                list.search(num);
                break;
            case 5:
                list.uploadfile();
                break;
        }
    } while (num != 6);
    return 0;
}

void menu()
{
    cout << endl;
    cout << "<ACCOUNTING>" << endl;
    cout << "1. Create cash order" << endl;
    cout << "2. View all operations history" << endl;
    cout << "3. View balance" << endl;
    cout << "4. Search operations by parameters" << endl;
    cout << "5. Download history from file" << endl;
    cout << "6. Exit" << endl;
}

int getNumber(int total)
{
    int number;
    string str;
    cout << ">> ";
    getline(cin, str);
    while ((sscanf(str.c_str(),"%i",&number) != 1)||(number < 1)||(number > total))
    {
        cout << "ERROR, try again >> ";
        getline(cin, str);
    }
    cout << endl;
    return number;
}
