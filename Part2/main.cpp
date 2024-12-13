#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string> 
#include <cmath> 
#include <list> 
#include <algorithm>
#include <numeric>
#include <chrono>
#include "FeatureSelection.h"
#include "Validator.h"


using namespace std; 



int main() {
    auto start = std::chrono::high_resolution_clock::now();
    string filename, algorithm;
    cout << "Welcome to Arun Chacko's Feature Selection Algorithm." << endl;
    cout << "Type in the name of the file to test: " << endl;
    cin >> filename;

    vector<vector<long double>> training_set;
    vector<long double> features;
    string line;

    // Read the file
    ifstream fin;
    fin.open(filename.c_str());
    if (!fin.is_open()) {
        cout << "Error opening file." << endl;
        return -1;
    }

    getline(fin, line);
    std::stringstream sstream(line);
    string feature;
    while (sstream >> feature) {
        features.push_back(stold(feature));
        training_set.push_back(features);
        features.clear();
    }

    while (getline(fin, line)) {
        std::stringstream sstream(line);
        string feature;
        for (unsigned int i = 0; i < training_set.size(); i++) {
            if (sstream >> feature) {
                training_set.at(i).push_back(stold(feature));
            }
        }
    }

    fin.close();

    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // // Handle "small-test-dataset.txt"
    // if (filename == "small-test-dataset.txt") {
    //     int choice;
    //     cout << "For small-test-dataset.txt, do you want to:\n";
    //     cout << "1) Use all features\n";
    //     cout << "2) Use only features {3,5,7}\n";
    //     cin >> choice;

    //     if (choice == 2) {
    //         vector<vector<long double>> filtered_set;
    //         filtered_set.push_back(training_set.at(0)); // Include class labels
    //         filtered_set.push_back(training_set.at(3)); // Feature 3
    //         filtered_set.push_back(training_set.at(5)); // Feature 5
    //         filtered_set.push_back(training_set.at(7)); // Feature 7
    //         training_set = filtered_set;               // Replace with filtered set
    //     }
    // }

    // // Handle "large-test-dataset.txt"
    // if (filename == "large-test-dataset.txt") {
    //     int choice;
    //     cout << "For large-test-dataset.txt, do you want to:\n";
    //     cout << "1) Use all features\n";
    //     cout << "2) Use only features {1,15,27}\n";
    //     cin >> choice;

    //     if (choice == 2) {
    //         vector<vector<long double>> filtered_set;
    //         filtered_set.push_back(training_set.at(0)); // Include class labels
    //         filtered_set.push_back(training_set.at(1)); // Feature 1
    //         filtered_set.push_back(training_set.at(15)); // Feature 15
    //         filtered_set.push_back(training_set.at(27)); // Feature 27
    //         training_set = filtered_set;                // Replace with filtered set
    //     }
    // }

    unsigned int numFeatures = training_set.size() - 1;
    // cout << "Number of instances: " << training_set.at(0).size() << endl;
    // cout << "Number of features: " << numFeatures << endl;
    // // PrintInstances(training_set);
    // cout << "Running nearest neighbor with all " << numFeatures << " features, using \"leaving-one-out\" evaluation, I get an accuracy of ";
    // cout << validator(training_set) << "%" << endl << endl;
    
    // cout << "Dataset Parsing Time: " << duration.count() << " milliseconds" << endl;
    // track_time_validator(training_set);

    //Algorithm selection
    cout << "Type the number of the algorithm you want to run.\n";
    cout << "1) Forward Selection\n2) Backward Elimination\n";
    cin >> algorithm;
    


    if (algorithm == "1") {
        forward_Selection(training_set, numFeatures);
    } else {
        backward_Selection(training_set, numFeatures);
    }

    return 0;
}


