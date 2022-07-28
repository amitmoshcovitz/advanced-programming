#include <vector>

using namespace std;

class Point {

    protected:
    vector<double> fields;
    int fieldsLength;

    public:

    /**
     * Constructor.
     * @param fields vector of fields
     */

    Point(vector<double> fields); 

    /**
     * Get Euclidean distance between this point and other point.
     * @param other other point
     * @return Euclidean distance
     */
    double getEuclideanDistance(Point other);
    
    /**
     * Get Manhattan distance between this point and other point.
     * @param other other point
     * @return Manhattan distance
     */
    double getManhattanDistance(Point other);

    /**
     * Get Chebyshev distance between this point and other point.
     * @param other other point
     * @return Chebyshev distance
     */
    double getChebyshevDistance(Point other);
};
