#include "fileHandler.h"
#include "point.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int k = stoi(argv[1]);
    map<Point, string> points = decryptFile("classified.csv");
    int size = points.size();
    vector<Point> pointsVector = vector<Point>(size);
    int i = 0;
    for (auto &point : points) {
        pointsVector[i] = point.first;
        i++;
    }
    Point reference = Point("0,0,0,0");
    vector<Point> kNearest = reference.getKClosest(pointsVector, Point::DistanceMetric::EUCLIDEAN, k);
    for (auto &point : kNearest) {
        cout << points[point] << endl;
    }
    return 0;
}
