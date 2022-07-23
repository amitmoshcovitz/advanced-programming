#include "point.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Iris : Point {

    public:
    enum IrisType {
        SETOSA,
        VIRGINICA,
        VERSICOLOR
    };

    static IrisType getIrisType(string type) {
       return type == "Iris-setosa" ? SETOSA : type == "Iris-virginica" ? VIRGINICA : VERSICOLOR;
    }
    
    private:
    IrisType type;

    public:
    Iris(double sepalLength, double sepalWidth, double petalLength, double petalWidth, IrisType type)
            : Point(vector<double>({sepalLength, sepalWidth, petalLength, petalWidth})) {
        this->type = type;
    }

    double getSepalLength() {
        return fields[0];
    }

    double getSepalWidth() {
        return fields[1];
    }

    double getPetalLength() {
        return fields[2];
    }

    double getPetalWidth() {
        return fields[3];
    }

    IrisType getType() {
        return type;
    }
};

