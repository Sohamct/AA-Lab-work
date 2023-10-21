#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int, int>, double>& a, 
        pair<pair<int, int>, double>& b) 
{ 
     if (a.second != b.second) {
        return a.second < b.second;
    }

    double dist_a = sqrt(pow(a.first.first, 2) + pow(a.first.second, 2));
    double dist_b = sqrt(pow(b.first.first, 2) + pow(b.first.second, 2));
    return dist_a > dist_b;
} 

vector<pair<pair<int, int>, double>> sort_map(map<pair<int, int>, double> &angles)
{
    vector<pair<pair<int, int>, double>> vect;

    for(auto it : angles)
    {
        vect.push_back(it);
    }

    sort(vect.begin(), vect.end(), cmp);

    return vect;
}

int Direction(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    //pi.first is the x coordinate of the ith point

    int d = (((p3.first - p1.first) * (p2.second - p1.second)) - ((p2.first - p1.first) * (p3.second - p1.second)));                                       
    return d;
}

int main()
{
    vector<pair<int, int>> vect = {{0, 0}, {3, 1}, {4, 4}, {1, 2}, {0, 5}, {2, 2}, {-1, 3}};
    pair<int, int> p0;
    int minimumY = INT_MAX;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].second < minimumY)
        {
            minimumY = vect[i].second;
            p0 = {vect[i].first, vect[i].second};
        }
    }
    // checking if two points are having y coordinates same then...
    vector<pair<int, int>> ySame;
    for (int i = 0; i < vect.size(); i++)
    {
        if (minimumY == vect[i].second)
        {
            ySame.push_back({vect[i].first, vect[i].second});
        }
    }

    // fetching minimum x coordinate from those points who are having Y coordinate same

    if (ySame.size() > 1)
    {
        int minimumX = INT_MAX;
        for (int i = 0; i < ySame.size(); i++)
        {
            if (ySame[i].first < minimumX)
            {
                minimumX = ySame[i].first;
                p0 = {ySame[i].first, ySame[i].second};
            }
        }
    }

    cout << p0.first << " " << p0.second << endl;

    map<pair<int, int>, double> angles;

    for(int i = 0; i < vect.size(); i++)
    {
        if(vect[i] != p0)
        {
            double y = vect[i].second - p0.second;
            double x = vect[i].first - p0.first;
            double m = y / x;
            double slope = atan(m);
            angles[{vect[i].first, vect[i].second}] = (slope * 180 / 3.1415 < 0) ? (180 + slope * 180 / 3.145) : (slope * 180 / 3.1415);
        }
    }   

    cout << "Angles with p0" << endl;

    for(auto it : angles)
    {
        cout << it.first.first << ", " << it.first.second << " = " << it.second << endl;
    }

    vector<pair<pair<int, int>, double>> sortedVal = sort_map(angles);

    cout << "Sorted angles : " << endl;

    for(int i = 0; i < sortedVal.size(); i++)
    {
        cout << sortedVal[i].first.first << " " << sortedVal[i].first.second << " " << sortedVal[i].second << endl;
    }
    
    stack<pair<int, int>> Convex_H_Points;

    Convex_H_Points.push(p0);
    Convex_H_Points.push({sortedVal[0].first.first, sortedVal[0].first.second});
    Convex_H_Points.push({sortedVal[1].first.first, sortedVal[1].first.second});


    for(int i = 2; i < sortedVal.size(); i++)
    {
        pair<int, int> top = Convex_H_Points.top();
        cout << "top : " << top.first << " " << top.second << endl;
        Convex_H_Points.pop();
        pair<int, int> next_to_top = Convex_H_Points.top();
        cout << "next to top : " << next_to_top.first << " " << next_to_top.second << endl;
        Convex_H_Points.push(top);
        cout << "point " << i << " " << sortedVal[i].first.first << " " << sortedVal[i].first.second << endl;

        while( Direction(next_to_top, top, {sortedVal[i].first.first, sortedVal[i].first.second}) > 0)
        {
            Convex_H_Points.pop();
            top = Convex_H_Points.top();
            cout << "top : " << top.first << " " << top.second << endl;
            Convex_H_Points.pop();
            next_to_top = Convex_H_Points.top();
            cout << "next to top : " << next_to_top.first << " " << next_to_top.second << endl;
            Convex_H_Points.push(top);
        }
            Convex_H_Points.push({sortedVal[i].first.first, sortedVal[i].first.second});
    }

    cout << "convex hull points" << endl;
    while(!Convex_H_Points.empty())
    {
        cout << Convex_H_Points.top().first << " " << Convex_H_Points.top().second << endl;
        Convex_H_Points.pop();
    }
    return 0;
}