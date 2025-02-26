#include "iostream"
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_ROUTES = 10;
const int MAX_BUSES = 10;
const int MAX_STOPS = 20;

class Transportation;
class Bus;

class Student
{
private:
    string studentID;
    string name;
    bool semesterFeePaid;
    bool cardActive;
    string assignedStop;

public:
    Student() : studentID(""), name(""), semesterFeePaid(false), cardActive(false), assignedStop(""){}

    void initialize(string id, string n) 
	{
        studentID = id;
        name = n;
        semesterFeePaid = false;
        cardActive = false;
        assignedStop = "";
    }

    string getStudentID()const{return studentID;}
    string getName()const{return name;}
    bool isSemesterFeePaid()const{return semesterFeePaid;}
    bool isCardActive()const{return cardActive;}
    string getAssignedStop()const{return assignedStop;}

    void setAssignedStop(string stop){assignedStop = stop;}
    void activateCard(){cardActive = true;}

    void registerForTransportation() 
	{
        cout << name << " (ID: " << studentID << ") has registered for the transportation service." << endl;
    }

    void paySemesterFee() 
	{
        semesterFeePaid = true;
        activateCard();
        cout << name << " (ID: " << studentID << ") has paid the semester fee. Card is now active." << endl;
    }

    void tapCard(Bus& bus);
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

    void initialize(string id, string name) 
	{
        routeID = id;
        routeName = name;
        stopCount = 0;
    }

    string getRouteID()const{return routeID;}
    string getRouteName()const{return routeName;}

    void addStop(string stop){
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

    void recordAttendance(Student& student) 
	{
        if(student.isCardActive() && !student.getAssignedStop().empty()) 
		{
            cout << "Attendance recorded for " << student.getName() << " (ID: " << student.getStudentID() << ") at stop '" << student.getAssignedStop() << "'." << endl;
        } 
		else 
		{
            cout << "Cannot record attendance. Card inactive or stop not assigned for " << student.getName() << " (ID: " << student.getStudentID() << ")." << endl;
        }
    }
};

void Student::tapCard(Bus& bus) 
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
    Student students[MAX_STUDENTS];
    Transportation routes[MAX_ROUTES];
    Bus buses[MAX_BUSES];

    int studentCount = 0, routeCount = 0, busCount = 0;

    while(true)
	{
        cout << "\n-----FAST Transportation System-----\n";
        cout << "1. Register Student\n2. Pay Semester Fee\n3. Create Route\n4. Add Stop to Route\n5. Create Bus\n6. Assign Route to Bus\n7. Assign Stop to Student\n8. Tap Card\n9. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if(choice == 1 && studentCount < MAX_STUDENTS) 
		{
            string id, name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;
            students[studentCount].initialize(id, name);
            students[studentCount].registerForTransportation();
            studentCount++;
        } 
		else if(choice == 2) 
		{
            string id;
            cout << "Enter student ID to pay fee: ";
            cin >> id;
            for(int i=0; i<studentCount; i++) 
			{
                if(students[i].getStudentID() == id) 
				{
                    students[i].paySemesterFee();
                }
            }
        } 
		else if(choice == 3 && routeCount < MAX_ROUTES) 
		{
            string id, name;
            cout << "Enter route ID: ";
            cin >> id;
            cout << "Enter route name: ";
            cin >> name;
            routes[routeCount].initialize(id, name);
            routeCount++;
        } 
		else if(choice == 4) 
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
        else if(choice == 5 && busCount<MAX_BUSES) 
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
    
        
        else if(choice == 7) 
        {
            string id, stop;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter stop name: ";
            cin >> stop;

            bool found = false;
            for(int i=0; i<studentCount; i++) 
            {
                if(students[i].getStudentID() == id) 
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
        }
        
        else if(choice == 6) 
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
        
        else if(choice == 8) 
        {
            string studentID, busID;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Bus ID: ";
            cin >> busID;

            Student *selectedStudent = nullptr;
            Bus *selectedBus = nullptr;

            for(int i = 0; i < studentCount; i++) 
            {
                if(students[i].getStudentID() == studentID) 
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
        }
        
		else if(choice == 9) 
		{
		    cout << "Exiting the system....";
            break;
        }
    }
}