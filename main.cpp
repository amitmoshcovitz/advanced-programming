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
std::string classify(Point* unclassified, map<Point*, std::string>* points, Point::DistanceMetric distanceType, int k) {
    int size = points->size();
    vector<Point*>* pointsVector = new vector<Point*>(size);
    int i = 0;
    for (auto &point : *points) {
        (*pointsVector)[i] = point.first;
        i++;
    }
    vector<Point*> kNearest = unclassified->getKClosest(pointsVector, distanceType, k);
    map<std::string, int> amountOfType = map<std::string, int>();
    for (auto &point : kNearest) {
        amountOfType[(*points)[point]]++;
    }
    pair<std::string, int> correctType = pair<std::string, int>("", -1);
    for (auto &type : amountOfType) {
        if (type.second > correctType.second) {
            correctType = type;
        }
    }
    delete pointsVector;
    return correctType.first;
}

int main(int argc, char const *argv[]) {
    int k = stoi(argv[1]);
    map<Point*, string>* points = decryptClassifiedFile("input/classified.csv");
    vector<Point*>* unclassified = decryptUnclassifiedFile("input/unclassified.csv");
    for (int i = 0; i < 3; i++) {
        string outputFile = "out/" + Point::toString((Point::DistanceMetric)i) + "_output.csv";
        ofstream file(outputFile);

        int tempSize = unclassified->size();
        for (size_t i = 0; i < tempSize; i++) {
            string type = classify((*unclassified)[i], points, (Point::DistanceMetric)i, k);
            file << type << endl;
        }
    }
    
    delete points;
    delete unclassified;

    return 0;
}



