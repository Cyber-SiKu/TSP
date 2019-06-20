//
// Created by siku on 19-6-18.
//

#ifndef TSP_BBM_H
#define TSP_BBM_H

// 分支限界算法

#include <vector>
#include "City.h"
#include "greedy.h"

std::vector<City> brach_bound_methound(const std::vector<City> & citys);

double down_bound(const std::vector<City> &citys);
// 求取下届,必小于最终结果

double min(const double a, const double b);


#endif //TSP_BBM_H
