#include<iostream>
#include<time.h>
#include<string>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
    void Print()
    {
        cout << "Day:" << day << endl;
        cout << "Month:" << month << endl;
        cout << "Year:" << year << endl;
    }
    void Fill()
    {
        cout << "Day:";
        cin >> day;
        cout << endl << "Month:";
        cin >> month;
        cout << endl << "Year:";
        cin >> year;
    }
    void FillRandom(int min, int max)
    {
        day = 1 + rand() % 31;
        month = 1 + rand() % 12;
        year = min + (rand() % (max - min));
    }
};
struct Students
{
    string FirstName;
    string LastName;
    int age;
    Date date;
    int marks[10];
    bool vidminnyk;
    string status = "Vidminnyk";
    void Fill()
    {
        string sn[5] = { "Bondarenko", "Melnik", "Shevchenko", "Tkachenko", "Kovalenko" };
        string n[5] = { "Olexiy", "Alexandr", "Maxim", "Boris", "Yriy" };
        int a, b;
        a = rand() % 4;
        b = rand() % 4;
        FirstName = n[a];
        LastName = sn[b];
        age = 22 + rand() % 39;
        date.FillRandom(2000, 2004);

        int qwe = rand() % 10;

      
 
        bool privilegia = true;
        for (int i = 0; i < 10; i++)
        {
            if (marks[i] < 10)
            {
                privilegia = false;
            }
        }
        if (qwe == 0)
        {
            FillRandomTrueMarks();
            vidminnyk = true;
        }
        else
        {
            vidminnyk = false;

            FillRandomMarks();
        }
    }
    void FillRandomTrueMarks()
    {
        for (int i = 0; i < 10; i++)
        {
            marks[i] = 10 + rand() % 12-10;
        }
    }
    void Print()
    {
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day<<"."<<date.month<<"."<<date.year<< endl;
        date.Print();
    }
    void FillRandomMarks()
    {
       
        for (int i = 0; i < 10; i++)
        {
            marks[i] =1+rand() % 12;
        }
    }
   
};
struct Teachers 
{
    string FirstName;
    string LastName;
    int age;
    Date date;


    void Fill() 
    {
        string sn[5] = { "Ivanchuk", "Melnychuk", "Tkach", "Zelenskiy", "Stolyar" };
        string n[5] = { "Dmitro", "Vadim", "Maxim", "Nazar", "Stanislav" };
        int a, b;
        a = rand() % 4;
        b = rand() % 4;
        FirstName = n[a];
        LastName = sn[b];
        age = 22 + rand() % 39;
        date.FillRandom(1965, 1990);
    }
    void Print()
    {
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
        date.Print();
    }
};
struct Group
{
    Teachers teacher;
    Students* students = new Students[5];
    string Name;
    void Fill(string name)
    {
        Name = name;
        teacher.Fill();
        for (int i = 0; i < 5; i++)
        {
            students[i].Fill();
        }
    }
    void Print()
    {
        cout << "----------------------"<<Name<<"--------------";
        cout << "----------------------------------------------" << endl;
        cout << "Teacher of "  << endl;

        teacher.Print();
        
        for (int i = 0; i < 5; i++)
        {
            cout << "------------------------------------" << endl;
            cout << "Student" << endl;
            students[i].Print();
        }
    }
};
void PrintVidminnyk(Group* groups, bool vidminnyk)
{
    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (vidminnyk == true)
            {
               groups[i].students[j].status;
               groups[i].students[j].Print();
            }
        }
    }
}
void main()
{
    srand(time(0));
    Group groups[3];
    string names[3] = { "Group 1","Group 2","Group 3" };
    for (int i = 0; i < 3; i++)
    {
        groups[i].Fill(names[i]);
        groups[i].Print();
    }
    PrintVidminnyk(groups, true);
}