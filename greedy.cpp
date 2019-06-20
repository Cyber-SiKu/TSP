//
// Created by siku on 19-6-18.
//

#include "greedy.h"

#include <iostream>

std::vector<City> greedy(const std::vector<City> &citys) {
    std::vector<City> visited;
    std::vector<City> unvisited = citys;

    City locate = unvisited.at(0);
    visited.push_back(locate);
    unvisited.erase(unvisited.begin());

    while (unvisited.size() != 0) {
        // 求最短距离
        std::vector<City>::iterator min_distance_iter = unvisited.begin();
        double min_distance = locate.distance(*min_distance_iter);
//        std::cout << "\n dis first: "  << min_distance <<"\t";
        for (std::vector<City>::iterator i = unvisited.begin(); i != unvisited.end() ; ++i) {
            // 遍历当前城市与剩余城市的距离选择最短的
            double distance = locate.distance(*i);
//            std::cout << "dis: " << distance <<"\t";
            if (distance < min_distance) {
                min_distance_iter = i;
                min_distance = distance;
            }
        }
//        std::cout <<"min dis: " << locate.distance(*min_distance_iter) << " lo: " << *min_distance_iter << "\n";
        locate = *min_distance_iter;
        visited.push_back(*min_distance_iter);
        unvisited.erase(min_distance_iter);
    }
    return visited;
}

