#include "iris.hpp"
#include "point.hpp"
#include <sstream>
using namespace std;

Iris::Iris(double sepalLength, double sepalWidth, double petalLength, double petalWidth, string type) : Point(vector<double>{sepalLength, sepalWidth, petalLength, petalWidth}) {
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

string Iris::toString() {
    stringstream ss;
    ss << "Sepal length: " << getSepalLength() << endl;
    ss << "Sepal width: " << getSepalWidth() << endl;
    ss << "Petal length: " << getPetalLength() << endl;
    ss << "Petal width: " << getPetalWidth() << endl;
    ss << "Type: " << type << endl;
    return ss.str();
}