#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 机器结构体
struct Machine {
    int load;           // 当前负载
    int id;             // 机器编号
    vector<int> jobs;   // 分配的作业编号
    Machine(int i) : load(0), id(i) {}
};

// 作业排序（按时间从大到小）
vector<pair<int, int>> sortJobs(const vector<int>& jobs) {
    vector<pair<int, int>> jobList;
    for (int i = 0; i < jobs.size(); ++i) {
        jobList.push_back(make_pair(jobs[i], i + 1));
    }
    sort(jobList.begin(), jobList.end(), greater<pair<int, int>>());
    return jobList;
}

// 初始化机器
vector<Machine> initMachines(int m) {
    vector<Machine> machines;
    for (int i = 0; i < m; ++i) {
        machines.push_back(Machine(i + 1));
    }
    return machines;
}

// 分配作业
void assignJobs(const vector<pair<int, int>>& jobList, vector<Machine>& machines) {
    int m = machines.size();
    int n = jobList.size();
    for (int i = 0; i < n; ++i) {
        // 找到负载最小的机器
        int minIndex = 0;
        for (int j = 1; j < m; ++j) {
            if (machines[j].load < machines[minIndex].load) {
                minIndex = j;
            }
        }
        // 分配作业
        machines[minIndex].jobs.push_back(jobList[i].second);
        machines[minIndex].load += jobList[i].first;
    }
}

// 输出调度结果
void printResult(const vector<Machine>& machines) {
    int maxTime = 0;
    cout << "调度方案如下：" << endl;
    for (int i = 0; i < machines.size(); ++i) {
        cout << "m" << machines[i].id << "机器: ";
        for (int j = 0; j < machines[i].jobs.size(); ++j) {
            cout << "作业" << machines[i].jobs[j] << " ";
        }
        cout << "总时间: " << machines[i].load << endl;
        if (machines[i].load > maxTime)
            maxTime = machines[i].load;
    }
    cout << "总的处理时间是: " << maxTime << endl;
}

// 主调度函数
void scheduleJobs(const vector<int>& jobs, int m) {
    if (m <= 0) {
        cout << "错误：机器数量必须大于0" << endl;
        return;
    }
    if (jobs.empty()) {
        cout << "错误：作业列表不能为空" << endl;
        return;
    }

    vector<pair<int, int>> jobList = sortJobs(jobs);
    vector<Machine> machines = initMachines(m);
    assignJobs(jobList, machines);
    printResult(machines);
}

int main() {
    // 测试数据
    vector<int> jobs = {2, 14, 4, 16, 6, 5, 3};
    int m = 3;

    scheduleJobs(jobs, m);
    system("pause");
    return 0;
}