//
// Created by siku on 19-6-17.
//

#ifndef TSP_CITY_H
#define TSP_CITY_H

#include <cmath>
#include <ostream>
#include <fstream>
#include <vector>

class City{
private :
    int number;
    int x;
    int y;
public:
    City();
    City(int x, int y);
    double distance(City city); // 返回两个城市之间的距离

    void display(std::ostream &os);

    void get_data(std::ifstream & in);

    friend std::ostream &operator << (std::ostream &os, City c);

};

void get_data(std::string file_path, std::vector<City> &citys);
// 从文件中读取数据

#endif //TSP_CITY_H
