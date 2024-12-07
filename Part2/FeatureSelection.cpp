#include "FeatureSelection.h"

void forward_Selection(std::vector<std::vector<long double>> training_set, unsigned int numFeatures) {
    std::vector<unsigned int> bestFeatures;
    std::vector<unsigned int> localBest;
    float accuracy, max = 0.0;

    for (unsigned int i = 1; i <= numFeatures; i++) {
        float localmax = 0.0;
        std::vector<unsigned int> tmpMax;
        for (unsigned int j = 1; j <= numFeatures; j++) {
            std::vector<std::vector<long double>> tmp;
            std::vector<unsigned int> tmpLocal;
            tmp.push_back(training_set.at(0));
            tmpLocal = localBest;

            for (unsigned int x = 0; x < tmpLocal.size(); x++) {
                tmp.push_back(training_set.at(tmpLocal.at(x)));
            }

            if (std::find(tmpLocal.begin(), tmpLocal.end(), j) == tmpLocal.end()) {
                tmp.push_back(training_set.at(j));
                tmpLocal.push_back(j);
                std::cout << "Testing ";
                for (unsigned int i = 0; i < tmpLocal.size(); i++) {
                    std::cout << tmpLocal.at(i) << " ";
                }
                accuracy = validator(tmp);
                std::cout << "Accuracy: " << accuracy << std::endl;
                if (accuracy > localmax) {
                    localmax = accuracy;
                    tmpMax = tmpLocal;
                }
            }
        }
        localBest = tmpMax;
        std::cout << "The best feature set is: ";
        for (unsigned int i = 0; i < localBest.size(); i++) {
            std::cout << localBest.at(i) << " ";
        }
        std::cout << "with an accuracy of " << localmax << "%" << std::endl << std::endl;

        if (localmax > max) {
            bestFeatures = localBest;
            max = localmax;
            localBest = bestFeatures;
        } else if (localmax < max) {
            std::cout << "Warning! Accuracy is decreasing. Continuing check in case of local maxima." << std::endl;
        }
    }

    std::cout << std::endl << "Search finished." << std::endl;
    std::cout << "The final best feature set is: ";
    for (unsigned int i = 0; i < bestFeatures.size(); i++) {
        std::cout << bestFeatures.at(i) << " ";
    }
    std::cout << "with an accuracy of " << max << "%" << std::endl;
}

void backward_Selection(std::vector<std::vector<long double>> training_set, unsigned int numFeatures) {
    std::vector<unsigned int> bestFeatures(numFeatures);
    std::iota(bestFeatures.begin(), bestFeatures.end(), 1);
    std::vector<unsigned int> localBest = bestFeatures;
    float accuracy, max = 0.0;

    for (unsigned int i = 1; i < numFeatures; i++) {
        float localmax = 0.0;
        std::vector<unsigned int> tmpMax;
        for (unsigned int j = 0; j <= numFeatures; j++) {
            std::vector<std::vector<long double>> tmp;
            std::vector<unsigned int> tmpLocal;
            tmp.push_back(training_set.at(0));
            tmpLocal = localBest;

            for (unsigned int x = 0; x < localBest.size(); x++) {
                tmp.push_back(training_set.at(localBest.at(x)));
            }
            auto it = std::find(tmpLocal.begin(), tmpLocal.end(), j);
            if (it != tmpLocal.end()) {
                unsigned int index = it - tmpLocal.begin() + 1;
                tmpLocal.erase(it);
                tmp.erase(tmp.begin() + index);
                std::cout << "Testing ";
                for (unsigned int i = 0; i < tmpLocal.size(); i++) {
                    std::cout << tmpLocal.at(i) << " ";
                }
                accuracy = validator(tmp);
                std::cout << "Accuracy: " << accuracy << std::endl;
                if (accuracy >= localmax) {
                    localmax = accuracy;
                    tmpMax = tmpLocal;
                }
            }
        }
        localBest = tmpMax;
        std::cout << "The best feature set is: ";
        for (unsigned int i = 0; i < localBest.size(); i++) {
            std::cout << localBest.at(i) << " ";
        }
        std::cout << "with an accuracy of " << localmax << "%" << std::endl << std::endl;

        if (localmax > max) {
            bestFeatures = localBest;
            max = localmax;
        } else if (localmax < max) {
            std::cout << "Warning! Accuracy is decreasing. Continuing check in case of local maxima." << std::endl;
        }
    }

    std::cout << std::endl << "Search finished." << std::endl;
    std::cout << "The final best feature set is: ";
    for (unsigned int i = 0; i < bestFeatures.size(); i++) {
        std::cout << bestFeatures.at(i) << " ";
    }
    std::cout << "with an accuracy of " << max << "%" << std::endl;
}
