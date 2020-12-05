// Created by Rahul Naik (rkn423)
// COE 322 Fall 2020
//


#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <ctime>
#include <cstdlib>
#include "disease.h"

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;



int main(){
    srand(time(NULL));
    Population austin(5,.5);
    austin.random_infection();
    while(austin.count_infected()>0){
        austin.status_string();
        austin.updatev1();
        if (austin.count_infected()==0){
            cout<<"Disease ran its course everyone is recovered"<<endl;
        }
    }
}
