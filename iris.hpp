#include "point.hpp"

class Iris : Point {

    public:
    enum IrisType {
        SETOSA,
        VIRGINICA,
        VERSICOLOR
    };

    /**
    * Gets the type of the iris from the string.
    * @param line string to get the type from
    * @return type of the iris
    */
    static IrisType getIrisType(string type);

    private:
    IrisType type;

    public:
    /**
     * Constructor.
     * @param sepalLength sepal length
     * @param sepalWidth sepal width
     * @param petalLength petal length
     * @param petalWidth petal width
     * @param type type
     */
    Iris(double sepalLength, double sepalWidth, double petalLength, double petalWidth, IrisType type);

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
     * Get type.
     * @return type
     */
    IrisType getType();
};
