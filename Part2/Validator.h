#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>

float validator(std::vector<std::vector<long double>> features);
void PrintInstances(std::vector<std::vector<long double>> features);
void track_time_validator(std::vector<std::vector<long double>> features);
#endif
