#include "iostream"
using namespace std;

class Visitor;
class ghost;

class HauntedHouse 
{
private:
    string name;
    ghost** ghosts; 
    int ghostCount;
    const static int MAX_GHOSTS = 10; 

public:
    HauntedHouse(string n) : name(n), ghostCount(0) {
        ghosts = new ghost*[MAX_GHOSTS];
    }

    void addGhost(ghost* g) 
    {
        if (ghostCount < MAX_GHOSTS) 
        {
            ghosts[ghostCount++] = g;
        }
    }

    ghost* getGhost(int index) 
    {
        if (index < ghostCount) {
            return ghosts[index];
        }
        return nullptr;
    }

    int getGhostCount() 
    {
        return ghostCount;
    }

    friend void visit(HauntedHouse& H, Visitor V[], int n);

    ~HauntedHouse() 
    {
        delete[] ghosts;
    }
};

class ghost 
{
protected:
    string name;
    int RNG;

public:
    ghost(string n, int level) : name(n), RNG(level) {}

    virtual void haunt() {
        cout << "Haunting!!!!" << endl;
    }

    ghost operator+(ghost& g) {
        return ghost(name + g.name, RNG + g.RNG);
    }

    friend ostream& operator<<(ostream& os, const ghost& G);

    int getRNG() 
    {
        return RNG;
    }
};

ostream& operator<<(ostream& os, const ghost& G) 
{
    os << G.name << " (Scare level: " << G.RNG << ")";
    return os;
}

class Poltergeists :virtual public ghost 
{
public:
    Poltergeists(string n, int lvl) : ghost(n, lvl) {}
    void haunt()  
    {
        cout << "Object moved by Poltergeist Ghost... " << name << endl;
    }
};

class Banshees : public ghost 
{
public:
    Banshees(string n, int lvl) : ghost(n, lvl) {}
    void haunt() 
    {
        cout << "Loud SCREAM! by Banshee... " << name << endl;
    }
};

class ShadowGhosts :virtual public ghost 
{
public:
    ShadowGhosts(string n, int lvl) : ghost(n, lvl) {}
    void haunt() 
    {
        cout << "Whispers creepily by ShadowGhost... " << name << endl;
    }
};

class ShadowPoltergeist : public ShadowGhosts, public Poltergeists 
{
private:
string name;
int level;
public:
    ShadowPoltergeist(string n, int lvl) : ghost(n,lvl),ShadowGhosts(n,lvl) , Poltergeists(n,lvl) {}
    void haunt() 
    {
        ShadowGhosts::haunt();
        Poltergeists::haunt();
    }
};

class Visitor 
{
private:
    string name;
    int Bravery;

public:
    Visitor() 
    {
        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your bravery (1-4: Cowardly, 5-7: Average, 8-10: Fearless): ";
        cin >> Bravery;
        while (Bravery < 1 || Bravery > 10) 
        {
            cout << "Invalid bravery level. Please enter between 1-10: ";
            cin >> Bravery;
        }
    }

    string getName()  
    {
        return name;
    }
    int getBravery() 
    {
        return Bravery;
    }

    void reactToGhost(int ghostRNG) 
    {
        if (ghostRNG < Bravery) 
        {
            cout << name << " laughs at the ghost!" << endl;
        } 
        else if (ghostRNG > Bravery + 3) 
        {
            cout << name << " screams and runs away!" << endl;
        } 
        else 
        {
            cout << name << " gets scared but stands their ground!" << endl;
        }
    }
};

void visit(HauntedHouse& H, Visitor V[], int n) 
{
    cout << "\nVisiting " << H.name << " with " << n << " visitors..." << endl;
    
    for (int i = 0; i < H.getGhostCount(); i++) {
        ghost* Ghost = H.getGhost(i);
        cout << "\nGhost " << i+1 << ": " << *Ghost << endl;
        Ghost->haunt();
        
        for (int j = 0; j < n; j++) 
        {
            cout << "  ";
            V[j].reactToGhost(Ghost->getRNG());
        }
    }
}

int main() 
{
    cout << "-----------------------------------" << endl;
    cout << "Muhammad Hammad-24K-0544" << endl;
	cout << "-----------------------------------\n" << endl;
    Poltergeists poltergeist1("Poltergeist1", 4);
    Banshees banshee1("Banshees1", 7);
    ShadowGhosts shadow1("Shadow1", 5);
    ShadowPoltergeist shadowPoltergeist1("shadowPoltergeist1", 8);
    Banshees banshee2("Banshee2", 9);
    Poltergeists poltergeist2("Poltergeist2", 3);
    ShadowGhosts shadow2("Shadow2", 6);
    Banshees banshee3("Banshee3", 7);
    ShadowPoltergeist shadowPoltergeist2("shadowPoltergeist2", 10);

    HauntedHouse house1("Spooky Mansion");
    HauntedHouse house2("Creepy Castle");
    HauntedHouse house3("Haunted Hotel");

    house1.addGhost(&poltergeist1);
    house1.addGhost(&banshee1);
    house1.addGhost(&shadow1);

    house2.addGhost(&shadowPoltergeist1);
    house2.addGhost(&banshee2);

    house3.addGhost(&poltergeist2);
    house3.addGhost(&shadow2);
    house3.addGhost(&banshee3);
    house3.addGhost(&shadowPoltergeist2);

    const int visitorCount = 2;
    Visitor visitors[visitorCount];

    cout << "----------------------------------------------------------" << endl;
    visit(house1, visitors, visitorCount);
    cout << "----------------------------------------------------------" << endl;
    visit(house2, visitors, visitorCount);
    cout << "----------------------------------------------------------" << endl;
    visit(house3, visitors, visitorCount);
    cout << "----------------------------------------------------------" << endl;
}



