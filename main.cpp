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
string classify(std::unique_ptr<Point> unclassified, map<std::unique_ptr<Point>, string> points, Point::DistanceMetric distanceType, int k) {
    int size = points.size();
    vector<std::unique_ptr<Point>> pointsVector = vector<std::unique_ptr<Point>>(size);
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
    map<std::unique_ptr<Point>, string> points = decryptClassifiedFile("input/classified.csv");
    vector<std::unique_ptr<Point>> unclassified = decryptUnclassifiedFile("input/unclassified.csv");
    for (int i = 0; i < 3; i++) {
        string outputFile = "out/" + Point::toString((Point::DistanceMetric)i) + "_output.csv";
        ofstream file(outputFile);

        int tempSize = unclassified.size();
        for (size_t i = 0; i < tempSize; i++) {
            string type = classify(std::move(unclassified[i]), points, (Point::DistanceMetric)i, k);
            file << type << endl;
        } //need to return because of the vector of destructer pointers.
    }
    return 0;
}
