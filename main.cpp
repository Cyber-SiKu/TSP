#include <iostream>

#include "City.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "greedy.h"

int main(int argc,char *argv[]) {

    std::cout << argv[1];
    if (!strcmp(argv[1], "greedy")){
        std::vector<City> citys;

        get_data("/home/siku/Documents/code/C_C++/TSP/data/TSP10cities.tsp", citys);

        std::vector<City> route = greedy(citys);

        for (auto i = route.begin(); route.end() != i; ++i){
            std::cout << *i << std::endl;
        }

    } else {
        std::cout<<"open file failed";
    }
    return 0;
}