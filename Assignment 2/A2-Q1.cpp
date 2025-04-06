#include "iostream"
#include <string>
using namespace std;

const int MAX_USER = 100;
const int MAX_TEACHER = 10;
const int MAX_STAFF = 10;
const int MAX_ROUTES = 10;
const int MAX_BUSES = 10;
const int MAX_STOPS = 20;

class Transportation;
class Bus;
class Teacher;
class Staff;
class User
{
protected:
    string ID;
    string name;
    bool FeePaid;
    bool cardActive;
    string assignedStop;

public:
    User():ID(""), name(""), FeePaid(false), cardActive(false), assignedStop(""){}
    User(string ID, string name, bool FeePaid ,bool cardActive, string assignedStop) : ID(""), name(""), FeePaid(false), cardActive(false), assignedStop(""){}

    void initialize(string id, string n) 
	{
        ID = id;
        name = n;
        FeePaid = false;
        cardActive = false;
        assignedStop = "";
    }
    string getID()const{return ID;}
    string getName()const{return name;}
    bool isSemesterFeePaid()const{return FeePaid;}
    bool isCardActive()const{return cardActive;}
    string getAssignedStop()const{return assignedStop;}

    void setAssignedStop(string stop){assignedStop = stop;}
    void activateCard(){cardActive = true;}

    void registerForTransportation() 
	{
        cout << name << " (ID: " << ID << ") has registered for the transportation service." << endl;
    }

    virtual void payFee() 
	{
        FeePaid = true;
        activateCard();
        cout << name << " (ID: " << ID << ") has paid the semester fee. Card is now active." << endl;
    }

    void tapCard(Bus& bus);
};
class Teacher : public User{
    private:
    string months[12] = {"Unpaid"};
    int monthcount;
    public:
    Teacher() : User("","",false,false,""){}
    Teacher(string ID , string name , bool FeePaid ,bool cardActive, string assignedStop) : User("","",false,false,"") {}
    void payFee()
    {
        FeePaid = true;
        activateCard();
        months[monthcount] = "Paid";
        cout << name << " Teacher ID: " << ID << " has paid the monthly fees for month: " << monthcount + 1 << " Card is now active" << endl; 
        monthcount++;
    }
};
class Staff : public User{
    private:
    string months[12] = {"Unpaid"};
    int monthcount;
    public:
    Staff() : User("","",false,false,""){}
    Staff(string ID , string name , bool FeePaid ,bool cardActive, string assignedStop) : User("","",false,false,"") {}
    void payFee()
    {
        FeePaid = true;
        activateCard();
        months[monthcount] = "Paid";
        cout << name << " Staff ID: " << ID << " has paid the monthly fees for month: " << monthcount + 1 << " Card is now active" << endl; 
        monthcount++;
    }
};
class Transportation 
{
private:
    string routeID;
    string routeName;
    string stops[MAX_STOPS];
    int stopCount;

public:
    Transportation():routeID(""), routeName(""), stopCount(0) {}
    
    bool operator==(const Transportation& t1) 
    {
        return routeID == t1.routeID && routeName == t1.routeName;
    }

    void initialize(string id, string name) 
	{
        routeID = id;
        routeName = name;
        stopCount = 0;
    }

    string getRouteID()const{return routeID;}
    string getRouteName()const{return routeName;}

    void addStop(string stop)
    {
        if(stopCount < MAX_STOPS) 
		{
            stops[stopCount++] = stop;
            cout << "Stop '" << stop << "' added to route " << routeName << " (ID: " << routeID << ")." << endl;
        } 
		else 
		{
            cout << "Stop limit reached for route " << routeName << "." << endl;
        }
    }

    void getRouteDetails()const 
	{
        cout << "Route ID: " << routeID << ", Name: " << routeName << endl;
        cout << "Stops: ";
        for (int i = 0; i < stopCount; ++i) 
		{
            cout << stops[i] << " ";
        }
        cout << endl;
    }
};

class Bus 
{
private:
    string busID;
    string busNumber;
    Transportation* assignedRoute;

public:
    Bus() : busID(""), busNumber(""), assignedRoute(nullptr){}

    void initialize(string id, string number) 
	{
        busID = id;
        busNumber = number;
    }

    string getBusID() const{return busID;}

    void assignRoute(Transportation& route)
	{
        assignedRoute = &route;
        cout << "Bus " << busNumber << " (ID: " << busID << ") assigned to route " << route.getRouteName() << " (ID: " << route.getRouteID() << ")." << endl;
    }

    void recordAttendance(User& student) 
	{
        if(student.isCardActive() && !student.getAssignedStop().empty()) 
		{
            cout << "Attendance recorded for " << student.getName() << " (ID: " << student.getID() << ") at stop '" << student.getAssignedStop() << "'." << endl;
        } 
		else 
		{
            cout << "Cannot record attendance. Card inactive or stop not assigned for " << student.getName() << " (ID: " << student.getID() << ")." << endl;
        }
    }
};

void User::tapCard(Bus& bus) 
{
    if(cardActive) 
	{
        bus.recordAttendance(*this);
    } 
	else 
	{
        cout << "Card is inactive. Please pay the semester fee to activate the card." << endl;
    }
}

int main() 
{
    cout << "-----------------------------------" << endl;
    cout << "Muhammad Hammad-24K-0544" << endl;
	cout << "-----------------------------------\n" << endl;
    User students[MAX_USER];
    Teacher teacher[MAX_TEACHER];
    Staff staff[MAX_STAFF];
    Transportation routes[MAX_ROUTES];
    Bus buses[MAX_BUSES];

    int userCount = 0,teachercount = 0, staffcount = 0, routeCount = 0, busCount = 0;

    while(true)
	{
        cout << "\n-----FAST Transportation System-----\n";
        cout << "1. Register Student\n2. Register Teacher\n3. Register Staff\n4. Pay Fees\n5. Create Route\n6. Add Stop to Route\n7. Create Bus\n8. Assign Route to Bus\n9. Assign Stop to Student\n10. Tap Card\n11. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if(choice == 1 && userCount < MAX_USER) 
		{
            string id, name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;
            students[userCount].initialize(id, name);
            students[userCount].registerForTransportation();
            userCount++;
        }
        else if(choice == 2 && userCount < MAX_TEACHER) 
		{
            string id, name;
            cout << "Enter Teacher ID: ";
            cin >> id;
            cout << "Enter Teacher Name: ";
            cin >> name;
            teacher[teachercount].initialize(id, name);
            teacher[teachercount].registerForTransportation();
            teachercount++;
        }
        if(choice == 3 && userCount < MAX_STAFF) 
		{
            string id, name;
            cout << "Enter Staff ID: ";
            cin >> id;
            cout << "Enter Staff Name: ";
            cin >> name;
            staff[staffcount].initialize(id, name);
            staff[staffcount].registerForTransportation();
            staffcount++;
        } 
		else if(choice == 4) 
		{
            int call;
            while(call != 4)
            {
                cout << "\n1.Pay Student Fee\n2.Pay Teacher Fee\n3.Pay Staff Fee\n4.Exit\nEnter your choice: ";
                cin >> call;
                string id;
                
                switch(call)
                {
                case 1:
                    cout << "Enter student ID to pay fee: ";
                    cin >> id;
                    for(int i=0; i < userCount; i++) 
                    {
                        if(students[i].getID() == id) 
                        {
                            students[i].payFee();
                        }
                    }
                    break;
                case 2:
                    cout << "Enter teacher ID to pay fee: ";
                    cin >> id;
                    for(int i=0; i < teachercount; i++) 
                    {
                        if(teacher[i].getID() == id) 
                        {
                            teacher[i].payFee();
                        }
                    }
                    break;
                case 3:
                    cout << "Enter Staff ID to pay fee: ";
                    cin >> id;
                    for(int i=0; i < staffcount; i++) 
                    {
                        if(staff[i].getID() == id) 
                        {
                            staff[i].payFee();
                        }
                    }
                    break;
                case 4:
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Exiting" << endl;
                    break;
                }
            }
            
        } 
		else if(choice == 5 && routeCount < MAX_ROUTES) 
		{
            string id, name;
            cout << "Enter route ID: ";
            cin >> id;
            cout << "Enter route name: ";
            cin >> name;
            routes[routeCount].initialize(id, name);
            routeCount++;
        } 
		else if(choice == 6) 
		{
            string id, stop;
            cout << "Enter route ID: ";
            cin >> id;
            for(int i=0; i < routeCount; i++) 
			{
                if (routes[i].getRouteID() == id) 
				{
                    cout << "Enter stop name: ";
                    cin >> stop;
                    routes[i].addStop(stop);
                }
            }
        }
        else if(choice == 7 && busCount<MAX_BUSES) 
        {
            string id, number;
            cout << "Enter Bus ID: ";
            cin >> id;
            cout << "Enter Bus Number: ";
            cin >> number;
            buses[busCount].initialize(id, number);
            cout << "Bus created successfully." << endl;
            busCount++;
        }
    
        
        else if(choice == 8) 
        {
            int call;
                cout << "\n1.for Student\n2.forTeacher\n3.for Staff\n4.Exit\nEnter your choice: ";
                cin >> call;
                string id,stop;
                bool found;
                switch(call)
                {
                case 1:
                    cout << "Enter student ID: ";
                    cin >> id;
                    cout << "Enter stop name: ";
                    cin >> stop;

                    found = false;
                    for(int i=0; i < userCount; i++) 
                    {
                        if(students[i].getID() == id) 
                        {
                            students[i].setAssignedStop(stop);
                            cout << "Stop '" << stop << "' assigned to student " << students[i].getName() << "." << endl;
                            found = true;
                            break;
                        }
                    }

                    if(!found) 
                    {
                        cout << "Student not found." << endl;
                    }
                    break;
                case 2:
                    cout << "Enter teacher ID: ";
                    cin >> id;
                    cout << "Enter stop name: ";
                    cin >> stop;
        
                    found = false;
                    for(int i=0; i < teachercount; i++) 
                    {
                        if(teacher[i].getID() == id) 
                        {
                            teacher[i].setAssignedStop(stop);
                            cout << "Stop '" << stop << "' assigned to teacher " << teacher[i].getName() << "." << endl;
                            found = true;
                            break;
                        }
                    }
        
                    if(!found) 
                    {
                        cout << "Teacher not found." << endl;
                    }
                    break;
                case 3:
                    cout << "Enter Staff ID: ";
                    cin >> id;
                    cout << "Enter stop name: ";
                    cin >> stop;
        
                    found = false;
                    for(int i=0; i < staffcount; i++) 
                    {
                        if(staff[i].getID() == id) 
                        {
                            staff[i].setAssignedStop(stop);
                            cout << "Stop '" << stop << "' assigned to staff " << staff[i].getName() << "." << endl;
                            found = true;
                            break;
                        }
                    }
        
                    if(!found) 
                    {
                        cout << "Staff not found." << endl;
                    }
                    break;
                case 4:
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Exiting" << endl;
                    break;
                }
            }
        
        else if(choice == 9) 
        {
            string busID, routeID;
            cout << "Enter Bus ID: ";
            cin >> busID;
            cout << "Enter Route ID: ";
            cin >> routeID;
    
            Bus *selectedBus = nullptr;
            Transportation *selectedRoute = nullptr;
    
            for(int i=0; i<busCount; i++) 
            {
                if(buses[i].getBusID() == busID) 
                {
                    selectedBus = &buses[i];
                    break;
                }
            }

            for(int j = 0; j < routeCount; j++) 
            {
                if(routes[j].getRouteID() == routeID) 
                {
                    selectedRoute = &routes[j];
                    break;
                }
            }

            if(selectedBus && selectedRoute) 
            {
                selectedBus->assignRoute(*selectedRoute);
            } 
            else 
            {
                cout << "Invalid Bus ID or Route ID." << endl;
            }
        }
        
        else if(choice == 10) 
        {
            int call;
            cout << "\n1.for Student\n2.forTeacher\n3.for Staff\n4.Exit\nEnter your choice: ";
            cin >> call;
            string studentID, teacherID, staffID, busID;
            Bus *selectedBus = nullptr;
            User *selectedStudent = nullptr;
            Teacher *selectedTeacher = nullptr;
            Staff *selectedStaff = nullptr;
            switch (call)
            {
            case 1:
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Bus ID: ";
                cin >> busID;

                

                for(int i = 0; i < userCount; i++) 
                {
                    if(students[i].getID() == studentID) 
                    {
                        selectedStudent = &students[i];
                        break;
                    }
                }

                for(int j=0; j<busCount; j++) 
                {
                    if(buses[j].getBusID() == busID) 
                    {
                        selectedBus = &buses[j];
                        break;
                    }
                }

                if(selectedStudent && selectedBus) 
                {
                    selectedStudent->tapCard(*selectedBus);
                } 
                else 
                {
                    cout << "Invalid Student ID or Bus ID." << endl;
                }
                break;
            case 2:
                cout << "Enter Teacher ID: ";
                cin >> teacherID;
                cout << "Enter Bus ID: ";
                cin >> busID;

                

                for(int i = 0; i < teachercount; i++) 
                {
                    if(teacher[i].getID() == teacherID) 
                    {
                        selectedTeacher = &teacher[i];
                        break;
                    }
                }

                for(int j=0; j<busCount; j++) 
                {
                    if(buses[j].getBusID() == busID) 
                    {
                        selectedBus = &buses[j];
                        break;
                    }
                }

                if(selectedTeacher && selectedBus) 
                {
                    selectedTeacher->tapCard(*selectedBus);
                } 
                else 
                {
                    cout << "Invalid Teacher ID or Bus ID." << endl;
                }
                break;
            case 3:
                cout << "Enter Staff ID: ";
                cin >> staffID;
                cout << "Enter Bus ID: ";
                cin >> busID;

                for(int i = 0; i < staffcount; i++) 
                {
                    if(staff[i].getID() == staffID) 
                    {
                        selectedStaff = &staff[i];
                        break;
                    }
                }

                for(int j=0; j<busCount; j++) 
                {
                    if(buses[j].getBusID() == busID) 
                    {
                        selectedBus = &buses[j];
                        break;
                    }
                }

                if(selectedStaff && selectedBus) 
                {
                    selectedStaff->tapCard(*selectedBus);
                } 
                else 
                {
                    cout << "Invalid Staff ID or Bus ID." << endl;
                }
                break;
            
            default:
                cout << "Invalid" << endl;
                break;
            }
        }
		else if(choice == 11) 
		{
		    cout << "Exiting the system....";
            break;
        }
    }
}