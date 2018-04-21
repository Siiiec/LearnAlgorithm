#include <iostream>
#include <string>
#include <cmath>

double NormalizedAngle(double angle)
{
    while (angle < 0)
        angle += 360;
    
    return angle;
}

void solve()
{
    using namespace std;

    constexpr double oneHourAngle = 360.0 / 12.0;
    constexpr double oneMinAngle = 360.0 / 60.0;

    int h, m;
    string st;
    getline(cin, st, ':');
    h = stoi(st);
    getline(cin, st);
    m = stoi(st);

    auto angle1 = oneHourAngle * (h % 12 + m / 60.0);
    auto angle2 = oneMinAngle * m;

    cout << min(NormalizedAngle(angle1 - angle2), NormalizedAngle(angle2 - angle1)) << endl;
}