#include "iostream"
using namespace std;

class Planner
{
    public:
    string task[12][30];
    void add()
    {
        int n1,n2;
        cout << "1.Jan\n2.Feb\n3.Mar\n4.Apr\n5.May\n6.Jun\n7.Jul\n8.Aug\n9.Sep\n10.Oct\n11.Nov\n12.Dec\n";
        cout << "Enter the Month number to add tasks for: ";
        cin >> n1;
        while(n1 > 12)
        {
            cout << "Invalid number of Month! Re-Enter: ";
            cin >> n1;
        }
        cout << "Enter the Day number(1-30): ";
        cin >> n2;
        while(n2 > 30)
        {
            cout << "Invalid number of Day! Re-Enter: ";
            cin >> n2;
        }
        if(task[n1][n2] == "")
        {
            cout << "Enter Task " << "for day " << n2 << " of month " << n1 << ": ";
            cin.ignore();
            getline(cin , task[n1][n2]);   
        }
        else
        {
            cout << "One task per day select another day!!! task already assigned\n" << endl;
        }
    }
    void remove()
    {
        int n1,n2;
        cout << "1.Jan\n2.Feb\n3.Mar\n4.Apr\n5.May\n6.Jun\n7.Jul\n8.Aug\n9.Sep\n10.Oct\n11.Nov\n12.Dec\n";
        cout << "Enter the Month number to remove task for: ";
        cin >> n1;
        while(n1 > 12)
        {
            cout << "Invalid number of Month! Re-Enter: ";
            cin >> n1;
        }
        cout << "Enter the Day number to remove task for (1-30): ";
        cin >> n2;
        while(n2 > 30)
        {
            cout << "Invalid number of Day! Re-Enter: ";
            cin >> n2;
        }
        if(task[n1][n2] == " ")
        {
            cout << "No Task to be removed\n" << endl;
        }
        else
        {
            task[n1][n2] = "";
            cout << "Task removed Successflly\n" << endl;
        }
    }
    void display()
    {
        int n1;
        cout << "1.Jan\n2.Feb\n3.Mar\n4.Apr\n5.May\n6.Jun\n7.Jul\n8.Aug\n9.Sep\n10.Oct\n11.Nov\n12.Dec\n";
        cout << "Enter the Month number to Display tasks for: ";
        cin >> n1;
        while(n1 > 12)
        {
            cout << "Invalid number of Month! Re-Enter: ";
            cin >> n1;
        }
        cout << "Displaying for " << n1 << "th Month " << endl;
        for (int i = 1; i <= 30; i++)
        {
            cout << "Day " << i  << ": " << task[n1][i] << endl;
        }
        
    }
};

int main()
{
    Planner pr;
    int choice;
    cout << "Event Manager" << endl;
    while(choice != 4)
    {
        cout << "1.Add Task\n2.Remove Task\n3.Display Tasks\n4.Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pr.add();
            break;
        case 2:
            pr.remove();
            break;
        case 3:
            pr.display();
            break;
        case 4:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid Choice Entered!" << endl;
            break;
        }
    }
}
