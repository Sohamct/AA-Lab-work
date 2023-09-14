#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x;
    int y;
};

double euclideanDistance(const Point& p1, const Point& p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

 pair<Point, Point> findClosestPoints(const vector<Point>& points) {
    int n = points.size();
    if (n < 2) {
        // Not enough points to find the closest pair
        return make_pair(Point{0, 0}, Point{0, 0});
    }

    double minDistance =  numeric_limits<double>::max();
    Point closestPoint1, closestPoint2;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distance = euclideanDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPoint1 = points[i];
                closestPoint2 = points[j];
            }
        }
    }

    return make_pair(closestPoint1, closestPoint2);
}

int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};

    auto result = findClosestPoints(points);
    Point point1 = result.first;
    Point point2 = result.second;

     cout << "The two points with the shortest distance are (" << point1.x << ", " << point1.y << ") and (" << point2.x << ", " << point2.y << ") with a distance of " << euclideanDistance(point1, point2) <<  endl;

    return 0;
}
