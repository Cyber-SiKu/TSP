#include <iostream>

#include "City.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "greedy.h"
#include "BBM.h"


int main(int argc,char *argv[]) {
    // get data
    std::vector<City> citys;

    get_data(argv[2], citys);

    if (!strcmp(argv[1], "greedy")){
        std::vector<City> route = greedy(citys);

        for (auto i = route.begin(); route.end() != i; ++i){
            std::cout << *i << std::endl;
        }
        std::cout << "distance in all : " << distance_all(route) << std::endl;

    } else if(!strcmp(argv[1], "BBM")){
        std::vector<City> route = brach_bound_methound(citys);

        for (auto i = route.begin(); route.end() != i; ++i){
            std::cout << *i << std::endl;
        }
        std::cout << "distance in all : " << distance_all(route) << std::endl;
    } else {
        std::cout<<"no this solution!" << std::endl;
    }
    return 0;
}
