#include <bits/stdc++.h>
using namespace std;

int Direction(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    //pi.first is the x coordinate of the ith point

    int d = (((p3.first - p1.first) * (p2.second - p1.second)) - ((p2.first - p1.first) * (p3.second - p1.second)));                                       
    return d;
}

bool onSegment(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    if((min(p1.first, p2.first) <= p3.first <= max(p1.first, p2.first)) && (min(p1.second, p2.second) <= p3.second <= max(p1.second, p2.second)))
    {
        return true;
    }
    return false;
}
int main()
{
    pair<int, int> p1 = {1, 1}, p2 = {4, 8}, p3 = {2, 6}, p4 = {6, 3};
    
    int d1 = Direction(p3, p4, p1);
    int d2 = Direction(p3, p4, p2);
    int d3 = Direction(p1, p2, p3);
    int d4 = Direction(p1, p2, p4);

    //printing true if they are intersecting
    if(d1 * d2 < 0 && d3 * d4 < 0)
    {
        cout << true << endl;
    }
    else if(d1 == 0)
    {
        cout << onSegment(p3, p4, p1) << endl;
    }
    else if(d2 == 0)
    {
        cout << onSegment(p3, p4, p1) << endl;
    }
    else if(d3 == 0)
    {
        cout << onSegment(p3, p4, p1) << endl;
    }
    else if(d4 == 0)
    {
        cout << onSegment(p3, p4, p1) << endl;
    }
    else
    {
        cout << false << endl;
    }
    return 0;
}
