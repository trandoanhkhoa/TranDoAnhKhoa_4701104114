#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Định nghĩa một công việc
struct Job {
    int id;         // ID công việc
    int deadline;   // Thời hạn hoàn thành công việc
    int profit;     // Lợi nhuận của công việc
};

// So sánh công việc theo lợi nhuận giảm dần
bool compareJobs(const Job& a, const Job& b) {
    return (a.profit > b.profit);
}

// Tìm lợi nhuận tối đa và in ra thứ tự công việc được chọn
void scheduleJobs(const vector<Job>& jobs) {
    int n = jobs.size();

    // Sắp xếp công việc theo lợi nhuận giảm dần
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), compareJobs);

    // Mảng đánh dấu các thời điểm trong lịch trình
    vector<bool> schedule(n, false);

    // Duyệt qua từng công việc đã sắp xếp
    for (int i = 0; i < n; i++) {
        // Tìm vị trí trống gần nhất trước thời hạn hoàn thành công việc
        for (int j = min(n, sortedJobs[i].deadline) - 1; j >= 0; j--) {
            if (!schedule[j]) {
                schedule[j] = true;
                break;
            }
        }
    }

    // In ra thứ tự công việc được chọn
    cout << "Job sequence: ";
    for (int i = 0; i < n; i++) {
        if (schedule[i]) {
            cout << sortedJobs[i].id << " ";
        }
    }
    cout << endl;
}

int main() {
    // Nhập số lượng công việc
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    // Nhập thông tin cho từng công việc
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, deadline, and profit for job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Gọi hàm xếp lịch và in kết quả
    scheduleJobs(jobs);

    return 0;
}
