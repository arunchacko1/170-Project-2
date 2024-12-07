#ifndef FEATURE_SELECTION_H
#define FEATURE_SELECTION_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "Validator.h"

void forward_Selection(std::vector<std::vector<long double>> training_set, unsigned int numFeatures);
void backward_Selection(std::vector<std::vector<long double>> training_set, unsigned int numFeatures);

#endif
