//
// Created by siku on 19-6-17.
//

#include "City.h"

City::City(int x,int y):x(x),y(y) {}

double City::distance(const City city) const {
    return sqrt(hypot(double(this->x-city.x), double(this->y-city.y)));
}



void City::display(std::ostream &os) {
    os << "No." << this->number <<": " << "(" << this->x << " , " << this->y << ")";
}

void City::get_data(std::ifstream &in) {
    in >> this->number >> this->x >> this->y;
}

City::City() {
  x = 0;
  y = 0;
}

std::ostream &operator<<(std::ostream &os, City c) {
    c.display(os);
    return os;
}

bool operator==(const City c1, const City c2) {
    return c1.number == c2.number;
}

bool equal(const City c1, const City c2) {
    return c1.number == c2.number;
}


void get_data(std::string file_path, std::vector<City> &citys) {
    std::ifstream in(file_path);
    if (in.is_open()) {
        while (!in.eof()) {
            City c(0, 0);
            c.get_data(in);
            citys.push_back(c);
        }
        citys.pop_back(); // 最后一行会多输入一次，删除
    }
}



double distance_all(const std::vector<City> &route)  {
    double distance = 0.0;
    auto pre = route.begin();
    for (auto i = pre + 1; i != route.end() ; ++i, ++pre) {
        distance += pre->distance(*i);
    }

    // 算上返回距离
    distance = route.begin()->distance(*route.end());

    return distance;
}


//std::string City::data_type() {
//    return std::string("%d, %d");
//}
