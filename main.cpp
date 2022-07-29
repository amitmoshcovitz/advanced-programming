#include "fileHandler.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

/**
 * Classifies a point.
 * @param unclassified point to classify
 * @param points the map of points to their classifications
 * @param distanceType the distance metric to use
 * @param k the number of neighbors to use
 * @return the classification of the point
 */
string classify(Point unclassified, map<Point, string> points, Point::DistanceMetric distanceType, int k) {
    int size = points.size();
    vector<Point> pointsVector = vector<Point>(size);
    int i = 0;
    for (auto &point : points) {
        pointsVector[i] = point.first;
        i++;
    }
    vector<Point> kNearest = unclassified.getKClosest(pointsVector, distanceType, k);
    map<string, int> amountOfType = map<string, int>();
    for (auto &point : kNearest) {
        amountOfType[points[point]]++;
    }
    pair<string, int> correctType = pair<string, int>("", -1);
    for (auto &type : amountOfType) {
        if (type.second > correctType.second) {
            correctType = type;
        }
    }
    return correctType.first;
}

int main(int argc, char const *argv[]) {
    int k = stoi(argv[1]);
    map<Point, string> points = decryptClassifiedFile("input/classified.csv");
    int size = points.size();
    vector<Point> pointsVector = vector<Point>(size);
    int i = 0;
    for (auto &point : points) {
        pointsVector[i] = point.first;
        i++;
    }
    vector<Point> unclassified = decryptUnclassifiedFile("input/unclassified.csv");
    for (int i = 0; i < 3; i++) {
        string outputFile = "out/" + Point::toString((Point::DistanceMetric)i) + "_output.csv";
        ofstream file(outputFile);
        for (Point unclassifiedPoint : unclassified) {
            string type = classify(unclassifiedPoint, points, (Point::DistanceMetric)i, k);
            file << type << endl;
        }
    }
    return 0;
}
