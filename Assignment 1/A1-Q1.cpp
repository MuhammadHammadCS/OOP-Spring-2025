#include "iostream"
using namespace std;

class Mentor;  
class Sports;
class Skill;

class Student 
{
public:
    string StudentID;
    string name;
    int age;
    string* sportsInterest;
    string MentorAssigned;
    int n;

    Student() 
    {
        cout << "Enter Student name: ";
        cin >> name;
        cout << "Enter Student ID: ";
        cin >> StudentID;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter the number of sports interested in: ";
        cin >> n;

        sportsInterest = new string[n];

        cin.ignore();
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter Sports Interest " << i + 1 << ": ";
            getline(cin, sportsInterest[i]);
        }
    }

    ~Student() 
    {
        delete[] sportsInterest;
    }

    void registerForMentorship(Mentor& m);
    void viewMentorDetails();
};

class Mentor 
{
public:
    int MentorID;
    int n;
    string name;
    string* sportsExpertise;
    int maxLearners;
    string* assignedLearner;

    Mentor() 
    {
        cout << "Enter the Mentor ID: ";
        cin >> MentorID;
        cout << "Enter Mentor name: ";
        cin.ignore();
        getline(cin , name);
        cout << "Enter number of Sport expertise: ";
        cin >> n;

        sportsExpertise = new string[n];

        for (int i = 0; i < n; i++) 
        {
            cout << "Enter Sport Expertise " << i + 1 << " : ";
            cin >> sportsExpertise[i];
        }

        cout << "Enter fixed number of learners: ";
        cin >> maxLearners;
        assignedLearner = new string[maxLearners];
    }

    ~Mentor() 
    {
        delete[] sportsExpertise;
        delete[] assignedLearner;
    }

    void assignLearner(Student& s);
    void removeLearner();
    void viewLearners();
    void provideGuidance();
};

void Student::registerForMentorship(Mentor& m) 
{
    cout << "Enter the Mentor name you want to register with: ";
    cin >> m.name;
    MentorAssigned = m.name;
}

void Student::viewMentorDetails() 
{
    cout << "Mentor details for Student ID: " << StudentID << endl;
    cout << "Mentor name: " << MentorAssigned << endl;
}

void Mentor::assignLearner(Student& s) 
{
    cout << "Enter the number of students to assign: ";
    int numStudents;
    cin >> numStudents;

    if (numStudents <= maxLearners) 
    {
        cin.ignore();
        for (int i = 0; i < numStudents; i++) {
            cout << "---Learner " << i + 1 << "----" << endl;
            cout << "Enter Student Name: ";
            getline(cin, assignedLearner[i]);
        }
    } else {
        cout << "Not enough capacity for learners." << endl;
    }
}

void Mentor::removeLearner() 
{
    string rev;
    cout << "Enter the learner's name to remove: ";
    cin.ignore();
    getline(cin, rev);
    bool found = false;

    for (int i = 0; i < maxLearners; i++) 
    {
        if (assignedLearner[i] == rev) 
        {
            found = true;
            assignedLearner[i] = "";
            cout << "Learner removed successfully.\n";
            break;
        }
    }

    if (!found) 
    {
        cout << "Learner not found.\n";
    }
}

void Mentor::viewLearners() 
{
    cout << "Assigned Learners:\n";
    for (int i = 0; i < maxLearners; i++) 
    {
        if (!assignedLearner[i].empty()) 
        {
            cout << i + 1 << ": " << assignedLearner[i] << endl;
        }
    }
}

void Mentor::provideGuidance() 
{
    cout << "Guidance provided!\n";
}

class Sports 
{
public:
    int sportID;
    string name;
    string description;
    string* requiredSkill;
    int skillCount;

    Sports() 
    {
        skillCount = 0;
        requiredSkill = new string[10];
    }

    ~Sports() 
    {
        delete[] requiredSkill;
    }

    void addSkill(Skill& s);
    void removeSkill(Skill& s);
};

void Sports::addSkill(Skill& s) 
{
    cout << "Enter the number of new Skills required for " << name << " : ";
    int n;
    cin >> n;
    cin.ignore();
    string sn;
    for (int i = 0; i < n; i++) 
    {
        cout << "Skill " << i + 1 << ": ";
        getline(cin, sn);
        requiredSkill[skillCount++] = sn;
    }
}

void Sports::removeSkill(Skill& s) 
{
    string find;
    cout << "Enter the skill to be removed: ";
    cin.ignore();
    getline(cin, find);
    bool found = false;

    for (int i = 0; i < skillCount; i++) 
    {
        if (requiredSkill[i] == find) 
        {
            found = true;
            requiredSkill[i] = "";
            cout << "Skill removed successfully.\n";
            break;
        }
    }

    if (!found) 
    {
        cout << "Skill not found.\n";
    }
}

class Skill 
{
public:
    int skillID;
    string skillName;
    string description;

    void showSkillDetails() 
    {
        cout << "Skill ID: " << skillID << endl;
        cout << "Skill Name: " << skillName << endl;
        cout << "Skill Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) 
    {
        description = newDescription;
        cout << "Description updated successfully.\n";
    }
};

int main()
{
    int a,b,c,d;
    cout << "Enter Student Details: " << endl;
    Student su;
    cout << "Enter Mentor Details: " << endl;
    Mentor mt;
    su.registerForMentorship(mt);
    cout << "assigning learner...." << endl;
    mt.assignLearner(su);
    cout << "Do you want to remove learners(1 for Yes || 0 for No): ";
    cin >> a;
    if(a == 1)
    {
        mt.removeLearner();
    }
    else
    {
        cout << "None of the were learner removed!!" << endl;
    }
    cout << "Do you want to View learners(1 for Yes || 0 for No): ";
    cin >> b;
    if (b == 1)
    {
        mt.viewLearners();
    }
    
    Sports st;
    Skill sk;
    cout << "Do you want to add skills (1 for Yes || 0 for No): ";
    cin >> c;
    if (c == 1)
    {
        st.addSkill(sk);
    }
    else
    {
        cout << "None of the Skills were added !!" << endl;
    }
    cout << "Do you want to remove skills (1 for Yes || 0 for No): ";
    cin >> d;
    if (d == 1)
    {
        st.removeSkill(sk);
    }
    else
    {
        cout << "None of the Skills were removed !!" << endl;
    }

    return 0;
}
