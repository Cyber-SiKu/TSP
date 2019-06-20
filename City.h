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
    double distance(const City city) const; // 返回两个城市之间的距离

    void display(std::ostream &os);

    void get_data(std::ifstream & in);

    friend bool operator ==(const City c1,const City c2) ;
    friend bool equal(const City c1,const City c2) ;


    friend std::ostream &operator << (std::ostream &os, City c);

};

void get_data(std::string file_path, std::vector<City> &citys);
// 从文件中读取数据

double distance_all(const std::vector<City> &route);
bool equal(const City c1,const City c2) ;
bool operator ==(const City c1,const City c2) ;


#endif //TSP_CITY_H
