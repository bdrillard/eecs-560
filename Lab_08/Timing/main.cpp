#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "LeftistTree.h"
#include "SkewTree.h"
#include "Timer.h"

int main() {
    int nValues[4] = {50000, 100000, 200000, 400000};
    double leftistTreeInsertionTimes[5];
    double leftistTreeOperationTimes[5];
    double skewTreeInsertionTimes[5];
    double skewTreeOperationTimes[5];
    int insertion;
    Timer timer;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            LeftistTree<int>* leftistTree = new LeftistTree<int>;
            SkewTree<int>* skewTree = new SkewTree<int>;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                leftistTree -> insert(entry);
            }
            leftistTreeInsertionTimes[j] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", data size " << nValues[i] << ", time " << leftistTreeInsertionTimes[j] << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 2;
                switch (choice) {
                    case 0:
                        leftistTree -> deleteMin();
                        break;
                    case 1:
                        insertion = rand() % (nValues[i] * 4);
                        leftistTree -> insert(insertion);
                        break;
                }
            }
            leftistTreeOperationTimes[j] = timer.stop();
            std::cout << "Leftist Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << leftistTreeOperationTimes[j] << std::endl;
            delete leftistTree;

            srand(j);
            timer.start();
            for (int k = 0; k < nValues[i]; k++) {
                int entry = rand() % (nValues[i] * 4);
                skewTree -> insert(entry);
            }
            skewTreeInsertionTimes[j] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", data size " << nValues[i] << ", time " << skewTreeInsertionTimes[j] << std::endl;

            timer.start();
            for (int k = 0; k < (int) nValues[i] * 0.1; k++) {
                int choice = rand() % 4;
                switch (choice) {
                    case 0:
                        skewTree -> deleteMin();
                        break;
                    case 1:
                        insertion = rand() % (nValues[i] * 4);
                        skewTree -> insert(insertion);
                        break;
                }
            }
            skewTreeOperationTimes[j] = timer.stop();
            std::cout << "Skew Tree: seed " << j << ", operations " << nValues[i] * 0.1 << ", time " << skewTreeOperationTimes[j] << std::endl;
            delete skewTree;
            
            std::cout << std::endl;

        }

        double leftistTreeInsertionSum = 0;
        double leftistTreeOperationSum = 0;
        double skewTreeInsertionSum = 0;
        double skewTreeOperationSum = 0;
        for (int i = 0; i < 5; i++) {
            leftistTreeInsertionSum += leftistTreeInsertionTimes[i];
            leftistTreeOperationSum += leftistTreeOperationTimes[i];
            skewTreeInsertionSum += skewTreeInsertionTimes[i];
            skewTreeOperationSum += skewTreeOperationTimes[i];
        }

        std::cout << "Leftist Tree average insertion time: " << leftistTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Leftist Tree average operation time: " << leftistTreeOperationSum / 5.0 << std::endl;
        std::cout << "Skew Tree average insertion time: " << skewTreeInsertionSum / 5.0 << std::endl;
        std::cout << "Skew Tree average operation time: " << skewTreeOperationSum / 5.0 << std::endl;

        std::cout << std::endl;

    }

    return 0;
}
