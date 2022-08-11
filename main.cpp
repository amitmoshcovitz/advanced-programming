#include "fileHandler.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "algorithms.h"

using namespace std;

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
