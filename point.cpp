#include <math.h>
#include <vector>
#include "point.h"
#include <random>
#include "fileHandler.h"
#include <sstream>

using namespace std;

Point::Point(string data) {
    vector<string> unhandleFields = split(data, ',');
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

vector<Point> Point::getKClosest(const vector<Point> otherPoints, DistanceMetric distanceType, int k) const {

    int size = otherPoints.size();
    vector<Point> copyPoints = vector<Point>(size);
    for (int i = 0; i < size; i++) {
        copyPoints[i] = otherPoints[i];
    }
    
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
    
    vector<double> otherDistance = vector<double>(size);
    for (int i = 0; i < size; i++) {
        otherDistance[i] = ((this->*distance)(copyPoints[i]));
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, size);

    int minIndex = 0, maxIndex = size - 1;
    while (minIndex != maxIndex) {
        
        int divideIndex = distr(gen);
        double pivot = otherDistance[divideIndex];

        int left = minIndex, right = maxIndex;
        while (left < right) {
            while (otherDistance[left++] <= pivot);
            while (otherDistance[right--] >= pivot);
            if (left >= right) {
                break;
            }
            left--; right++;
            if (divideIndex == left) {
                divideIndex = right;
            } else if (divideIndex == right) {
                divideIndex = left;
            }
            swap(otherDistance[left], otherDistance[right]);
            swap(copyPoints[left], copyPoints[right]);
        }
        if (divideIndex > k) {
            maxIndex = divideIndex - 1;
        } else {
            minIndex = divideIndex;
        }
    }

    vector<Point> kClosest;
    for (int i = 0; i < k; i++) {
        kClosest.push_back(copyPoints[i]);
    }

    return kClosest;
}


string Point::toString() const {
    stringstream ss;
    for (int i = 0; i < size; i++) {
        ss << fields[i] << ",";
    }
    return ss.str();
}

