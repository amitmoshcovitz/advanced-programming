#ifndef _IRIS
#define _IRIS

#include "point.hpp"

#include <string>
#include <vector>
using namespace std;

class Iris : Point {

    private:
    string type;

    public:
    /**
     * Constructor.
     * @param sepalLength sepal length
     * @param sepalWidth sepal width
     * @param petalLength petal length
     * @param petalWidth petal width
     * @param type type
     */
    Iris(double sepalLength, double sepalWidth, double petalLength, double petalWidth, string type);

    /**
     * Get sepal length.
     * @return sepal length
     */
    double getSepalLength();

    /**
     * Get sepal width.
     * @return sepal width
     */
    double getSepalWidth();

    /**
     * Get petal length.
     * @return petal length
     */
    double getPetalLength();

    /**
     * Get petal width.
     * @return petal width
     */
    double getPetalWidth();

    /**
     * Get type string.
     * @return type string
     */
    string getType();

    /**
     * Get the string representation of the iris.
     * @return string representation of the iris
     */
    string toString();
};
#endif