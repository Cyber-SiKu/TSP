//
// Created by siku on 19-6-18.
//

#include <algorithm>
#include <stack>
#include "BBM.h"

std::vector<City> brach_bound_methound(const std::vector<City> &citys) {
    /*
     * FIFO 分支限界算法
     * 使用贪心算法获取上界
     * 按照贪心算法获取的列表做为点活结表序列,按次序选定节点
     * 选定一个节点后，对剩余节点使用贪心算法计算总距离，与已计算的距离进行比较，判定该节点是否是活性节点
     * 不是活性节点则删除
     */
    std::vector<City> visited;
    std::vector<City> unvisited = citys;

    std::vector<City> ret;

    int number_city = citys.size();

    std::vector<City> init = greedy(citys);
    std::vector<City> & PT = init;
    double up = distance_all(PT);
    double down = down_bound(citys);

    // 设置起点
    City pre = *unvisited.begin();
    visited.push_back(pre);
    unvisited.erase(unvisited.begin());
    PT.erase(PT.begin());

    std::stack<std::vector<City>> stack;

    do {
        for (auto i = PT.begin(); i != PT.end(); ++i) {
            City & temp = *i;
            unvisited.erase(i);
            double next_distance = pre.distance(*i) + down_bound(unvisited);
            if (next_distance > up) {
                PT.erase(i);
            } else if (next_distance < up) {
                visited.push_back(*i);
                stack.push(PT);
                PT = greedy(unvisited);
                break; // 跳出该循环
            }
        }
        // for 结束 ?当前找不到最佳路径
        if (PT.size() == 0){
            if (unvisited.size() == 0) {
                // 如果此时所有的城市都已经访问说明这是一种可行的方案，更新up
                double this_distance = distance_all(visited);
                up = min(this_distance, up);
                ret = visited;
                // 然后恢复到上一层。尝试其他方案
                if (stack.empty()) {
                    // 栈中没有元素,没有上层元素
                    break;
                }
                PT = stack.top();
                stack.pop();
                // 恢复现场
                City temp = *visited.rbegin();
                unvisited.push_back(temp);
                visited.erase(visited.end());
            } else {
                // 当前节点活节点表已空，但是仍有节点(城市)未访问
                if (stack.empty()) {
                    break;
                }
                PT = stack.top();
                PT.erase(PT.begin());
                stack.pop();
                // 恢复现场
                City temp = *visited.rbegin();
                unvisited.push_back(temp);
                visited.erase(visited.end());
            }
        }

    } while (unvisited.size() != 0);

    return std::vector<City>(visited);
}

double down_bound(const std::vector<City> &citys) {
    double down = 0.0;
    if (citys.size() != 0) {
        // 不止一个节点
        for (auto i = citys.begin(); i != citys.end(); ++i) {
            double min_dis_1 = i->distance(*(i+1));
            double min_dis_2 = 0;
            for (auto j = citys.begin(); j != citys.end(); ++j) {
                if (i == j) {
                    continue;
                } else if (min_dis_1 > i->distance(*j)) {
                    min_dis_1 = i->distance(*j);
                    min_dis_2 = min_dis_1;
                }
            }
            down += min_dis_1;
            if (min_dis_2 == 0){
                // 第一个就是最短的，没有更新min_distance_2
                min_dis_2 = i->distance(*(citys.begin()+1));
                for (auto j = citys.begin() + 1; j != citys.end(); ++j) {
                    if (i == j) {
                        continue;
                    } else if (min_dis_2 > i->distance(*j)) {
                        min_dis_2 = i->distance(*j);
                    }
                }
            }
            down += min_dis_2;
        }
    } else {
        // 仅有一个节点返回 0
    }
    return down / 2;
}

double min(const double a, const double b) {
    return a <= b ? a : b;
}
