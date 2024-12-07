#include "NearestNeighbor.h"

int nearest_neighbor(std::vector<long double> p, std::vector<std::vector<long double>> t) {
    long double minDis = 0.0;
    int classification = p.at(0);
    for (unsigned int i = 0; i < t.at(0).size(); i++) {
        long double dis = 0.0;
        for (unsigned int j = 1; j < t.size(); j++) {
            dis += pow(t.at(j).at(i) - p.at(j), 2);
        }
        if (i == 0) {
            minDis = dis;
        } else if (dis < minDis) {
            minDis = dis;
            classification = (int)t.at(0).at(i);
        }
    }
    return classification;
}
