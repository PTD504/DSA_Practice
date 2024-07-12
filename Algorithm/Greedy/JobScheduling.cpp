/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time before which job needs to be completed to earn the profit.
Constraints:
1 <= N <= 10^5
1 <= Deadline <= N
1 <= Profit <= 500



Solution: PTD504
###########################################
*/

#include <iostream>
#include "Sorting.h"
#include <set>

using namespace Sorting::QuickSort;

/*class Job 
{
public:
    int profit;
    int dead;
    int id;

    Job(int profit = 0, int dead = 0, int id = 0): profit(profit), dead(dead), id(id) {}
    bool operator>(const Job& other) {
        if (this->profit != other.profit) return this->profit > other.profit;
        return this->dead > other->dead;
    }

    bool operator<(const Job& other) {
        if (this->profit != other.profit) return this->profit < other.profit;
    }
};*/

struct Job 
{
    int id;
    int dead;
    int profit;

    bool operator<(const Job& other) {
        if (profit != other.profit) return profit < other.profit;
        return dead < other.dead;
    }

    bool operator>(const Job& other) {
        if (profit != other.profit) return profit > other.profit;
        return dead > other.dead;
    }
};

class Solution 
{
    public:
    
    std::vector<int> JobScheduling(std::vector<Job> arr, int n) 
    { 
        sort(arr);

        int ans = 0, num = 0;
        std::set<int> s;

        for (int i = 0; i < n; ++i) s.insert(i);

        for (int i = n - 1; i >= 0; --i) {
            auto it = s.lower_bound(arr[i].dead);
            if (it == s.begin()) continue;
            it--;
            ans += arr[i].profit;
            num++;
            s.erase(*it);
        }

        return std::vector<int> {num, ans};
    } 
};

int main() {
    int n = 4; // std::cin >> n;
    std::vector<Job> jobs = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};

    Solution obj;

    std::vector<int> ans = obj.JobScheduling(jobs, n);
    
    std::cout << ans[0] << ' ' << ans[1];
}