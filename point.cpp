#include "algorithms.h"
#include <math.h>
#include <vector>
#include "point.h"
#include <random>
#include "fileHandler.h"
#include <sstream>
#include <iostream>

using namespace std;

Point::Point(std::string data) {
    vector<std::string> unhandleFields = split(data, ',');
    int size = unhandleFields.size();
    vector<double> fields = vector<double>(size);
    for (int i = 0; i < size; i++) {
        fields[i] = stod(unhandleFields[i]);
    }
    this->fields = fields;
    this->size = size;
}

Point::Point() {
    this->fields = vector<double>();
    this->size = 0;
}

double Point::getEuclideanDistance(Point other) const {
    double distance = 0;
    for (int i = 0; i < size; i++) {
        distance += pow(fields[i] - other.fields[i], 2);
    }
    return sqrt(distance);
}

double Point::getManhattanDistance(Point other) const {
    double distance = 0;
    for (int i = 0; i < size; i++) {
        distance += abs(fields[i] - other.fields[i]);
    }
    return distance;
}

double Point::getChebyshevDistance(Point other) const {
    double max = 0;
    for (int i = 0; i < size; i++) {
        if (abs(fields[i] - other.fields[i]) > max) {
            max = abs(fields[i] - other.fields[i]);
        }
    }
    return max;
}

vector<Point*> Point::getKClosest(const vector<Point*>* otherPoints, DistanceMetric distanceType, int k) const {

    int size = otherPoints->size();
    if (size == 0) return vector<Point*>();
    
    double (Point::*distance)(Point) const;
    switch (distanceType) {
        case EUCLIDEAN:
            distance = &Point::getEuclideanDistance;
            break;
        case MANHATTAN:
            distance = &Point::getManhattanDistance;
            break;
        case CHEBYSHEV:
            distance = &Point::getChebyshevDistance;
            break;
    }
    
    vector<pair<Point*, double>>* distances = new vector<pair<Point*, double>>(size);
    for (int i = 0; i < size; i++) {
        (*distances)[i].first = (*otherPoints)[i];
        (*distances)[i].second = (this->*distance)(*(*otherPoints)[i]);
    }

    kthSmallest<pair<Point*, double>>(distances, k, [](pair<Point*, double> a, pair<Point*, double> b) {
        return a.second < b.second;
    });

    vector<Point*> kClosest = vector<Point*>(k);
    for (int i = 0; i < k; i++) {
        kClosest[i] = (*distances)[i].first;
    }

    for (int i = 0; i < size; i++) {
        (*distances)[i].first = nullptr;
    }

    delete distances;
    

    return kClosest;
}


std::string Point::toString() const {
    stringstream ss;
    for (int i = 0; i < size; i++) {
        ss << fields[i] << ",";
    }
    std::string str = ss.str();
    return str.substr(0, str.size() - 1);
}

bool Point::operator<(const Point &other) const {
    return this->fields < other.fields;
}

std::string Point::toString(DistanceMetric distanceType) {
    switch (distanceType) {
        case EUCLIDEAN:
            return "euclidean";
        case MANHATTAN:
            return "manhattan";
        default:
            return "chebyshev";
    }
}