#include "Validator.h"
#include "NearestNeighbor.h"
#include <iostream>
#include <chrono>

using namespace std;

float validator(std::vector<std::vector<long double>> features) {
    std::vector<std::vector<long double>> instance_subset;
    std::vector<long double> instanceCheck;
    int numCorrect = 0;

    for (unsigned int i = 0; i < features.at(0).size(); i++) {
        for (unsigned int j = 0; j < features.size(); j++) {
            std::vector<long double> tmp = features.at(j);
            instanceCheck.push_back(tmp.at(i));
            tmp.erase(tmp.begin() + i);
            instance_subset.push_back(tmp);
        }
        int predicted = nearest_neighbor(instanceCheck, instance_subset);
        int actual = (int)instanceCheck.at(0);
        if(predicted == actual) { 
            numCorrect++; 
        }
        instance_subset.clear();
        instanceCheck.clear();
    }

    return ((float)numCorrect / (float)features.at(0).size()) * 100;
}

void PrintInstances(std::vector<std::vector<long double>> features) {
    std::vector<std::vector<long double>> instance_subset;
    std::vector<long double> instanceCheck;
    int numCorrect = 0;

    for (unsigned int i = 0; i < features.at(0).size(); i++) {
        for (unsigned int j = 0; j < features.size(); j++) {
            std::vector<long double> tmp = features.at(j);
            instanceCheck.push_back(tmp.at(i));
            tmp.erase(tmp.begin() + i);
            instance_subset.push_back(tmp);
        }
        int predicted = nearest_neighbor(instanceCheck, instance_subset);
        int actual = (int)instanceCheck.at(0);

        // Trace output for each iteration
        cout << "Instance " << i + 1 << ": Predicted = " << predicted << ", Actual = " << actual << endl;

        if(predicted == actual) { 
            numCorrect++; 
        }
        instance_subset.clear();
        instanceCheck.clear();
}
}

void track_time_validator(std::vector<std::vector<long double>> features) {
    // Start time tracking
    auto start = std::chrono::high_resolution_clock::now();

    // Run the validator and capture the result
    float accuracy = validator(features);

    // End time tracking
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Validator execution time: " << duration.count() << " milliseconds" << endl;
}