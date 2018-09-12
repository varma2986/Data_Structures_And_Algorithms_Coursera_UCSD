#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;


  struct thread {
      int id;
      long long next_free_time;
      thread(int id, long long t = 0) : id(id), next_free_time(t){};
      void addtime(long long t) { next_free_time += t; }
      friend bool operator<(const thread &b, const thread &a) {
        if (b.next_free_time != a.next_free_time)
          return b.next_free_time > a.next_free_time;
        else
          return b.id > a.id;
      }
    };
    

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }



  void AssignJobsPriorityQueue() {
      // TODO: replace this code with a faster algorithm.
      assigned_workers_.resize(jobs_.size());
      start_times_.resize(jobs_.size());
      priority_queue<thread, vector<thread>> q;
      for (int i = 0; i < num_workers_; i++) {
        q.push(thread(i));
      }
      for (int i = 0; i < jobs_.size(); ++i) {
        int duration = jobs_[i];
        thread thread_temp = q.top();
        q.pop();
        assigned_workers_[i] = thread_temp.id;
        start_times_[i] = thread_temp.next_free_time; 
        thread_temp.next_free_time += duration;
        q.push(thread_temp);
      }
    }



  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobsPriorityQueue();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
