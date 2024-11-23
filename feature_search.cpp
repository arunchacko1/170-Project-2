#include "feature_search.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip> 

// Stub evaluation function
double evaluate(const std::vector<int>& features) {
    return static_cast<double>(rand()) / RAND_MAX;
}

// Function to print the feature set in the desired format
void printFeatureSet(const std::vector<int>& features) {
    std::cout << "{";
    for (size_t i = 0; i < features.size(); ++i) {
        std::cout << features[i];
        if (i < features.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "}";
}

// Function to evaluate and print feature subsets
std::pair<std::vector<int>, double> forwardSelection(const std::vector<int>& features) {
    std::vector<int> currentBestSet;
    double currentBestAccuracy = 0.0;

    std::vector<int> selectedFeatures; // Features already selected

    for (size_t i = 0; i < features.size(); ++i) {
        std::vector<int> candidateSet;
        double bestLocalAccuracy = 0.0;
        int bestFeature = -1;

        // Try adding each feature not already in selectedFeatures
        for (int feature : features) {
            if (std::find(selectedFeatures.begin(), selectedFeatures.end(), feature) == selectedFeatures.end()) {
                candidateSet = selectedFeatures;
                candidateSet.push_back(feature);

                // Evaluate the candidate set
                double accuracy = evaluate(candidateSet);

                // Print current evaluation result
                std::cout << "Using feature(s) ";
                printFeatureSet(candidateSet); // Helper function to print feature set
                std::cout << " accuracy is " << std::fixed << std::setprecision(1) << accuracy * 100 << "%\n";

                if (accuracy > bestLocalAccuracy) {
                    bestLocalAccuracy = accuracy;
                    bestFeature = feature;
                }
            }
        }

        // Update selected features with the best feature of this iteration
        if (bestFeature != -1) {
            selectedFeatures.push_back(bestFeature);
            currentBestAccuracy = bestLocalAccuracy;
            currentBestSet = selectedFeatures;

            // Print the best feature set for this iteration
            std::cout << "Feature set ";
            printFeatureSet(selectedFeatures);
            std::cout << " was best, accuracy is " << std::fixed << std::setprecision(1) << currentBestAccuracy * 100 << "%\n";
        }
    }

    return {currentBestSet, currentBestAccuracy};
}

// Backward Elimination implementation
// Function for backward elimination
std::pair<std::vector<int>, double> backwardElimination(const std::vector<int>& features) {
    std::vector<int> currentBestSet = features; // Start with all features
    double currentBestAccuracy = evaluate(features);

    std::cout << "Using all features and \"random\" evaluation, I get an accuracy of "
              << std::fixed << std::setprecision(1) << currentBestAccuracy * 100 << "%\n";

    while (currentBestSet.size() > 1) {
        std::vector<int> candidateSet;
        double bestLocalAccuracy = 0.0;
        int featureToRemove = -1;

        // Try removing each feature in the current set
        for (int feature : currentBestSet) {
            candidateSet = currentBestSet;
            candidateSet.erase(std::remove(candidateSet.begin(), candidateSet.end(), feature), candidateSet.end());

            // Evaluate the candidate set
            double accuracy = evaluate(candidateSet);

            // Print current evaluation result
            std::cout << "Using feature(s) ";
            printFeatureSet(candidateSet); // Helper function to print feature set
            std::cout << " accuracy is " << std::fixed << std::setprecision(1) << accuracy * 100 << "%\n";

            if (accuracy > bestLocalAccuracy) {
                bestLocalAccuracy = accuracy;
                featureToRemove = feature;
            }
        }

        // Update the current best set by removing the feature with the lowest impact on accuracy
        if (featureToRemove != -1) {
            currentBestSet.erase(std::remove(currentBestSet.begin(), currentBestSet.end(), featureToRemove), currentBestSet.end());
            currentBestAccuracy = bestLocalAccuracy;

            // Print the best feature set for this iteration
            std::cout << "Feature set ";
            printFeatureSet(currentBestSet);
            std::cout << " was best, accuracy is " << std::fixed << std::setprecision(1) << currentBestAccuracy * 100 << "%\n";
        }

        // Check if accuracy decreased
        if (bestLocalAccuracy < currentBestAccuracy) {
            std::cout << "(Warning, Accuracy has decreased!)\n";
        }
    }

    return {currentBestSet, currentBestAccuracy};
}