#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <ctype.h>

using namespace std;

void Works(float &, float &);
inline void cls();

int main()
{
    const char exit_character = 'N';
    ios::sync_with_stdio(false);

    vector <float> time, money, velocity;

    //time, money and velocity of the three works
    time.resize(3);
    money.resize(3);
    velocity.resize(3);

    char option;    //'N' for end the program

    do
    {
        for(int i = 0; i < 3; i++)
            Works(time[i], money[i]);

        for(int i = 0; i < 3; i++)
        {
            velocity[i] = money[i] / time[i];
            cout << i+1 << ": " << velocity[i] << " Millions per hour" << endl;
        }

        float maximum = max(max(velocity[0], velocity[1]), velocity[2]);

        for(int i = 0; i < 3; i++)
            if(maximum == velocity[i])
            {
                cout << "The biggest is: " << i+1 << endl;
                break;
            }

        cout << "\nPress 'N' for exit or any key to continue" << endl;
        cin >> option;

    } while( (option != exit_character) and (option != tolower(exit_character) ));    //option different of N and n

    return 0;
}

void Works(float &time, float &money)
{
    const char available_time_unit[2] =     {'H','M'};
    const char available_money_unit[3] =    {'T', 'M', 'B'};

    cls();

    float time_1, time_2;
    char time_unit, money_unit;

    do
    {
        cout << "Money unit: "; cin >> money_unit;
    } while( (money_unit != available_money_unit[0]) and (money_unit != tolower(available_money_unit[0])) and
             (money_unit != available_money_unit[1]) and (money_unit != tolower(available_money_unit[1])) and
             (money_unit != available_money_unit[2]) and (money_unit != tolower(available_money_unit[2])) );
              //money unit different of T, M, B, t, m and b

    cout << "Money: "; cin >> money;

    do
    {
        cout << "Time unit: "; cin >> time_unit;
    } while( (time_unit != available_time_unit[0]) and (time_unit != tolower(available_time_unit[0])) and
             (time_unit != available_time_unit[1]) and (time_unit != tolower(available_time_unit[1])) );
              //money unit different of H, M, h and m

    cout << "Time 1: "; cin >> time_1;
    cout << "Time 2: "; cin >> time_2;

    if( (money_unit != available_money_unit[1]) and (money_unit != tolower(available_money_unit[1])) )
        money /= 1000000;    //one million (7 digits)

    if( (time_unit == available_time_unit[0]) or (time_unit == tolower(available_time_unit[0])) )
    {
        time_2 /= 60;   //minutes to hours
    } else
    {
        time_1 /= 60;
        time_2 /= 3600; //seconds to hours
    }

    time = time_1 + time_2;
}

inline void cls()
{
    if (system("cls")) system("clear");     //this is for linux and windows compatibility
}
