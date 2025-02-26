#include <iostream>
using namespace std;

class Ball
{
public:
    int ballX;
    int ballY;

    Ball() : ballX(0), ballY(0) {}

    int getX()
    {
        return ballX;
    }
    int getY()
    {
        return ballY;
    }

    void move(int dx, int dy)
    {
        ballX += dx;
        ballY += dy;
    }

    void getPosition()
    {
        cout << "Ball Position: (" << ballX << ", " << ballY << ")" << endl;
    }
};

class Robot
{
public:
    string name;
    int hits;

    Robot() : hits(0) {}

    void hitBall(Ball &ball, const string &direction)
    {
        if (direction == "up")
        {
            ball.move(0, 1);
        }
        else if (direction == "down")
        {
            ball.move(0, -1);
        }
        else if (direction == "left")
        {
            ball.move(-1, 0);
        }
        else if (direction == "right")
        {
            ball.move(1, 0);
        }
        hits++;
    }
};

class Goal
{
public:
    bool isGoalReached(const Ball &ball)
    {
        if (ball.ballX == 3 && ball.ballY == 3)
        {
            cout << "Goal Reached!" << endl;
            return true;
        }
        return false;
    }
};

class Team
{
public:
    static int count;
    string teamName;
    Robot *robot;
    Ball ball;

    Team() : robot(nullptr) {}

    void createTeam()
    {
        cout << "Team no. " << count << endl;
        robot = new Robot();
        cout << "Enter Team Name: ";
        getline(cin, teamName);
        cout << "Enter Robot Name: ";
        cin.ignore();
        getline(cin, robot->name);
    }

    ~Team()
    {
        delete robot;
    }
};
class Game
{
private:
    Team teamOne;
    Team teamTwo;
    Ball ball;
    Goal goal;

public:
    Game()
    {
        teamOne.createTeam();
        teamOne.count++;
        teamTwo.createTeam();
        teamTwo.count++;
    }

    void play(Team &team)
    {
        string direction;
        cout << "Playing for team: " << team.teamName << endl;
        cout << "Enter direction (up/down/left/right): ";
        cin >> direction;
        team.robot->hitBall(team.ball, direction);
        team.ball.getPosition();
    }

    void declareWinner()
    {
        if (teamOne.robot->hits < teamTwo.robot->hits)
        {
            cout << "Team " << teamOne.teamName << " is the Winner!!" << endl;
        }
        else
        {
            cout << "Team " << teamTwo.teamName << " is the Winner!!" << endl;
        }
    }

    void startGame()
    {
        int choice;
        while (!goal.isGoalReached(teamOne.ball) && !goal.isGoalReached(teamTwo.ball))
        {
            cout << "Which team starts? (1 or 2): ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                play(teamOne);
                break;
            case 2:
                play(teamTwo);
                break;

            default:
                cout << "exit" << endl;
                break;
            }
        }
        declareWinner();
    }
};
int Team :: count = 1;
int main()
{
    Game game;
    game.startGame();
    return 0;
}
