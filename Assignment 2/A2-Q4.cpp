#include "iostream"
using namespace std;

class User;
int calc_hash(string password)
{
    int len = password.length();
    int hash = 5381;
    for (int i = 0; i < len; i++)
    {
        hash = hash * 33 + password[i];
    }
    return hash;
}
void authenticateAndPerformAction(User* user, string action);
class User{
    protected:
    string name;
    int ID;
    string permission[2];
    string email;
    int hashed_password;
    
    public:
    User(string n,int id, string email,string password,string list[]) : name(n) , ID(id) , email(email){
        hashed_password = calc_hash(password);
        permission[0] = list[0];
        permission[1] = list[1];
    }

    int autheincate(string password)
    {
        int found = 0;
        if(hashed_password == calc_hash(password))
        {
            found = 1;
            cout << "Password Authenticated" << endl;
        }
        else
        {
            found = 0;
            cout << "Incorrect Password" << endl;
        }
        return found;
    }
    
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Email: " << email << endl;
        cout << "Permissions: " << permission[0] << " " << permission[1] << endl;

    }

    int accesslab(string action)
    {
        int find =0;
        if(permission[0] == action && permission[1] == action)
        {
            find = 1;
        }
        else
        {
            find = 0;
        }
        return find;
    }
};
class Student : public User{
    private:
    int assignment[3] = {0};
    public:
    Student(string n,int id, string email,string password) : User(n,id,email,password,new string[2]{"Assignment submission",""}) {
    }
    void display()
    {
        User::display();
        cout << "Assignments Status: " << endl;
        for (int i = 0; i < 3; i++) 
        {
            if (assignment[i] == 1)
            {
                cout << "[" << i + 1 << ": Submitted" << " " << endl;
            }
            else
            {
                cout << "[" << i + 1 << ": Not Submitted" << " " << endl;
            }
        }
    }

    void assignmentsubmission()
    {
        char choice;
        int index;
        cout << "Do you want to submit any assignment(Y|y: Yes, N|n: No): ";
        cin >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            cout << "Enter the assignment number: ";
            cin >> index;
            if(index > 3 && index < 1)
            {
                cout << "Invalid assignment index" << endl;
            }
            else
            {
                index = index - 1;
                if(assignment[index] == 0)
                {
                    assignment[index] = 1;
                    cout << "Assignment " << index + 1 << " submitted" << endl;
                }
                else
                {
                    cout << "Assignment " << index + 1 << " already submitted" << endl;
                }
            }
        }
        else
        {
            cout << "No assignment submitted" << endl;
        }
            
    }
    

};
class TA : public Student{
    private:
    Student* student[10];
    string projects[2];
    int studentCount = 0;
    int projectCount = 0;

    public:
    TA(string name, int id, string email, string password) 
        : Student(name, id, email, password) 
    {
        permission[0] = "view_projects";
        permission[1] = "manage_students";
    }

    bool assignStudent(Student* student) 
    {
        if (studentCount < 10) 
        {
            student[studentCount++] = *student;
            return true;
        }
        return false;
    }

    bool addProject(string project) 
    {
        if (projectCount < 2) 
        {
            projects[projectCount++] = project;
            return true;
        }
        return false;
    }

    void display()
    {
        User::display();
        cout << "Managing Students: " << studentCount << " / 10" << endl;
        cout << "Projects: " << endl;
        for (int i = 0; i < projectCount; i++) 
        {
            cout << projects[i] << endl;
        }
    }


};
class Professor : public User 
{
    public:
    Professor(string name, int id, string email, string password) 
        : User(name, id, email, password, new string[2]{"assign_projects", "full_lab_access"}) 
    {}

    void display() override 
    {
        User::display();
        cout << "Professor privileges enabled." << endl;
    }
};

void authenticateAndPerformAction(User* user, string action) 
{
    if (user->accesslab(action)) 
    {
        cout << "Access granted for action: " << action << endl;
    } 
    else 
    {
        cout << "Access denied for action: " << action << endl;
    }
}


int main()
{
    cout << "-----------------------------------" << endl;
    cout << "Muhammad Hammad-24K-0544" << endl;
	cout << "-----------------------------------\n" << endl;


    Student s1("Imaad", 171, "Imaad@gmail.com", "password123");
    TA t1("Muhib", 251, "Muhib@gmail.com", "password123");
    Professor p1("Dr. Atif", 361, "Atif@nu.edu.pk", "securePass");

    s1.assignmentsubmission();
    t1.addProject("Data Science Research");
    authenticateAndPerformAction(&p1, "full_lab_access");

    s1.display();
    cout << "-----------------------------------" << endl;
    t1.display();
    cout << "-----------------------------------" << endl;
    p1.display();
    cout << "-----------------------------------" << endl;

}






