#include <math.h>
#include <vector>

using namespace std;

class Point {

    protected:
    vector<double> fields;
    int size;

    public:

    Point(vector<double> fields) {
        this->fields = fields;
        size = fields.size();
    }
    
    double getEuclideanDistance(Point other) {
        double distance = 0;
        for (int i = 0; i < size; i++) {
            distance += pow(fields[i] - other.fields[i], 2);
        }
        return sqrt(distance);
    }

    double getManhattanDistance(Point other) {
        double distance = 0;
        for (int i = 0; i < size; i++) {
            distance += abs(fields[i] - other.fields[i]);
        }
        return distance;
    }

    double getChebyshevDistance(Point other) {
        double max = 0;
        for (int i = 0; i < size; i++) {
            if (abs(fields[i] - other.fields[i]) > max) {
                max =  abs(fields[i] - other.fields[i]);
            }
        }
        return max;
    }
};