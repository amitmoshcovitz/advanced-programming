class Point {
    private:
    double* fields;
    int fieldsLength;
    public:
    double getPowerDistance(Point other) {
        double distance = 0;
        for (int i = 0; i < fieldsLength; i++)
        {
            distance += fields[i] * fields[i];
        }
        
    }
};