#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision
#include "feature_search.h"


int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    std::cout << "Welcome to Arun Chacko's Feature Selection Algorithm.\n\n";

    int numFeatures;
    std::cout << "Please enter total number of features: ";
    std::cin >> numFeatures;

    std::cout << "\nType the number of the algorithm you want to run.\n";
    std::cout << "1) Forward Selection\n";
    std::cout << "2) Backward Elimination\n";
    std::cout << "3) Arun\'s Special Algorithm.\n\n";

    int choice;
    std::cin >> choice;

    // Create feature set
    std::vector<int> features;
    for (int i = 1; i <= numFeatures; ++i) {
        features.push_back(i);
    }

    if (choice == 1) {
        // Forward Selection
        std::cout << "\nUsing no features and “random” evaluation, I get an accuracy of "
                  << std::fixed << std::setprecision(1) << evaluate({}) * 100 << "%\n";
        std::cout << "Beginning search.\n";

        auto [bestFeatureSet, bestAccuracy] = forwardSelection(features);

        std::cout << "Finished search!! The best feature subset is ";
        printFeatureSet(bestFeatureSet);
        std::cout << ", which has an accuracy of " << std::fixed << std::setprecision(1) << bestAccuracy * 100 << "%\n";

    } else if (choice == 2) {
        // Backward Elimination
        std::cout << "\nUsing all features and \"random\" evaluation, I get an initial accuracy of "
                  << std::fixed << std::setprecision(1) << evaluate(features) * 100 << "%\n";
        std::cout << "Beginning search.\n";

        auto [bestFeatureSet, bestAccuracy] = backwardElimination(features);

        std::cout << "Finished search!! The best feature subset is ";
        printFeatureSet(bestFeatureSet);
        std::cout << ", which has an accuracy of " << std::fixed << std::setprecision(1) << bestAccuracy * 100 << "%\n";

    } else if (choice == 3) {
        // Placeholder for Bertie's Special Algorithm
        std::cout << "Arun\'s Special Algorithm is not implemented in this example.\n";
    } else {
        std::cout << "Invalid choice. Please select 1, 2, or 3.\n";
    }

    return 0;
}
