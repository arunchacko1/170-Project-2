#ifndef FEATURE_SEARCH_H
#define FEATURE_SEARCH_H

#include <vector>
#include <utility>  // For std::pair

// Evaluate function declaration
double evaluate(const std::vector<int>& features);

// Forward Selection function declaration
std::pair<std::vector<int>, double> forwardSelection(const std::vector<int>& features);

// Backward Elimination function declaration
std::pair<std::vector<int>, double> backwardElimination(const std::vector<int>& features);

void printFeatureSet(const std::vector<int>& features);
#endif // FEATURE_SEARCH_H
