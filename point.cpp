#include <math.h>
class Point {
    private:
    double* fields;
    int fieldsLength;
    public:
    double getEuclideanDistance(Point other) {
        double distance = 0;
        for (int i = 0; i < fieldsLength; i++)
        {
            distance += pow(fields[i] - other.fields[i], 2);
        }
        return sqrt(distance);
    }
    double getManhattanDistance(Point other) {
        double distance = 0;
        for (int i = 0; i < fieldsLength; i++)
        {
            distance += abs(fields[i] - other.fields[i]);
        }
        return distance;
    }
    double getChebyshevDistance(Point other) {
        double max = 0;
        for (int i = 0; i < fieldsLength; i++)
        {
            if (abs(fields[i] - other.fields[i]) > max) {
                max =  abs(fields[i] - other.fields[i]);
            }
        }
        return max;
    }
};