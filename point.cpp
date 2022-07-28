#include <math.h>
#include <vector>
#include "point.hpp"

using namespace std;

Point::Point(vector<double> fields) {
    this->fields = fields;
    size = fields.size();
}

double Point::getEuclideanDistance(Point other) {
    double distance = 0;
    for (int i = 0; i < size; i++) {
        distance += pow(fields[i] - other.fields[i], 2);
    }
    return sqrt(distance);
}

double Point::getManhattanDistance(Point other) {
    double distance = 0;
    for (int i = 0; i < size; i++) {
        distance += abs(fields[i] - other.fields[i]);
    }
    return distance;
}

double Point::getChebyshevDistance(Point other) {
    double max = 0;
    for (int i = 0; i < size; i++) {
        if (abs(fields[i] - other.fields[i]) > max) {
            max =  abs(fields[i] - other.fields[i]);
        }
    }
    return max;
}
