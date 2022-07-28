#ifndef _POINT
#define _POINT

#include <vector>
#include <sstream>

using namespace std;

class Point {

    protected:
    vector<double> fields;
    int size;

    public: 

    /**
     * Default constructor
     */
    Point();

    /**
     * Constructor.
     * @param data the string containing the data.
     */
    Point(string data); 

    /**
     * Get Euclidean distance between this point and other point.
     * @param other other point
     * @return Euclidean distance
     */
    double getEuclideanDistance(Point other) const;
    
    /**
     * Get Manhattan distance between this point and other point.
     * @param other other point
     * @return Manhattan distance
     */
    double getManhattanDistance(Point other) const;

    /**
     * Get Chebyshev distance between this point and other point.
     * @param other other point
     * @return Chebyshev distance
     */
    double getChebyshevDistance(Point other) const;

    enum DistanceMetric {
        EUCLIDEAN,
        MANHATTAN,
        CHEBYSHEV
    };

    /**
     * Get the k nearest neighbors of this point.
     * @param otherPoints vector of other points
     * @param distanceType distance metric
     * @param k number of neighbors
     * @return the k nearest neighbors
     */
    vector<Point> getKClosest(vector<Point> otherPoints, DistanceMetric distanceType, int k) const;

    /**
    * Get the string representation of this point.
    * @return string representation of this point
    */
    string toString() const;
};
#endif