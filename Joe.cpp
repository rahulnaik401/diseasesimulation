//Created by Rahul Naik(rkn423)
//COE 322 Fall 2020

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "disease.h"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ofstream;


int main(){
    Person joe;
    int day = 1;
    for (;; day++) {
        joe.update();
        float sickchance = (float) rand() / (float) RAND_MAX;
        if (sickchance > .50) {
            joe.infect(5);
        }
        cout << "On day " << day << ", Joe is " << joe.status_string() << endl;
        if (joe.is_stable()) {
            break;
        }
        if (joe.is_stable()) {
            break;
        }
    }
}