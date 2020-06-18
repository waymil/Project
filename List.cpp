#include "List.h"

List::List()
{
    head = 0;
    count = 0;
}

List::~List()
{
    clear();
}

void List::search(int num)
{
    Contractor *temp = head;
    int i = 0;
    string line;
    cout << "Search: ";
    getline(cin, line);
    while (temp != 0)
    {
        if (num == 1)
        {
            if (temp->month == atoi(line.c_str()))
            {
                cout << getDay(temp) << "." << getMonth(temp) << "." << getYear(temp) << " '" << getName(temp) << "' " << getMoney(temp) << endl;
                i++;
            }
        }
        if (num == 2)
        {
            if (temp->year == atoi(line.c_str()))
            {
                cout << getDay(temp) << "." << getMonth(temp) << "." << getYear(temp) << " '" << getName(temp) << "' " << getMoney(temp) << endl;
                i++;
            }
        }
        if (num == 3)
        {
            if (temp->name == line)
            {
                cout << getDay(temp) << "." << getMonth(temp) << "." << getYear(temp) << " '" << getName(temp) << "' " << getMoney(temp) << endl;
                i++;
            }
        }
        if (num == 3)
        {
            if (temp->money == atoi(line.c_str()))
            {
                cout << getDay(temp) << "." << getMonth(temp) << "." << getYear(temp) << " '" << getName(temp) << "' " << getMoney(temp) << endl;
                i++;
            }
        }
        temp = temp->next;
    }
    if (i > 0)
    {
        cout << "Total found: " << i << endl;
    }
    else cout << "<No such parameter found>" << endl;
}

void List::clear()
{
    if (empty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    Contractor *temp = head;
    Contractor *p = 0;
    while (temp != 0)
    {
        p = temp;
        temp = temp->next;
        delete p;
    }
    count = 0;
    head = 0;
}

void List::show()
{
    if (empty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    Contractor *temp = head;
    cout << "<LIST>" << endl;
    while (temp != 0)
    {
        cout << getDay(temp) << "." << getMonth(temp) << "." << getYear(temp) << " '" << getName(temp) << "' " << getMoney(temp) << endl;
        temp = temp->next;
    }
    cout << "Total items: " << count << endl;
    cout << endl;
}

void List::savefile()
{
    fstream file;
    file.open("file.txt", ios_base::out);
    if (!file.is_open())
    {
        cout << "ERROR: file is not open" << endl;
        return;
    }
    Contractor *temp = head;
    while (temp != 0)
    {
        file << getName(temp) << "\t" << getDay(temp) << "\t" << getMonth(temp) << "\t" << getYear(temp) << "\t"  << getMoney(temp) << endl;
        temp = temp->next;
    }
    cout << "<File saved>" << endl;
    file.close();
}

void List::uploadfile()
{
    ifstream file;
    file.open("f.txt");
    if (!file.is_open())
    {
        cout << "ERROR: file is not open" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        string n, token;
        int d, m ,y, s, i = 0;
        istringstream flow(line);
        while (getline(flow, token, '\t'))
        {
            if (i == 0) n = token;
            if (i == 1) d = atoi(token.c_str());
            if (i == 2) m = atoi(token.c_str());
            if (i == 3) y = atoi(token.c_str());
            if (i == 4) s = atoi(token.c_str());
            i++;
        }
        add(n, d, m, y, s);
    }
}

Contractor* List::add(string n, int d, int m, int y, int s)
{
    Contractor *temp = new Contractor;
    temp->name = n;
    temp->day = d;
    temp->month = m;
    temp->year = y;
    temp->money = s;
    if (empty())
    {
        temp->next = 0;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    count++;
    return temp;
}

bool List::empty()
{
    return head == 0;
}

string List::getName(Contractor *temp) const
{
    return temp->name;
}

int List::getDay(Contractor *temp) const
{
    return temp->day;
}

int List::getMonth(Contractor *temp) const
{
    return temp->month;
}

int List::getYear(Contractor *temp) const
{
    return temp->year;
}

int List::getMoney(Contractor *temp) const
{
    return temp->money;
}
