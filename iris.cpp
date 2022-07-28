#include "iris.hpp"
#include "point.hpp"
#include <sstream>
using namespace std;

Iris::Iris(double sepalLength, double sepalWidth, double petalLength, double petalWidth, IrisType type) : Point(vector<double>{sepalLength, sepalWidth, petalLength, petalWidth}) {
    this->type = type;
}

double Iris::getSepalLength() {
    return fields[0];
}

double Iris::getPetalLength() {
    return fields[2];
}

double Iris::getSepalWidth() {
    return fields[1];
}

double Iris::getPetalWidth() {
    return fields[3];
}

Iris::IrisType Iris::getIrisType(string type) {
    if (type == "Iris-setosa") {
        return Iris::IrisType::SETOSA;
    } else if (type == "Iris-virginica") {
        return Iris::IrisType::VIRGINICA;
    } else {
        return Iris::IrisType::VERSICOLOR;
    }
}