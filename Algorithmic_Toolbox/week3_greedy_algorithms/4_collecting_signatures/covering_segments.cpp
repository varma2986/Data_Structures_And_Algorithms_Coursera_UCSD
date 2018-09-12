#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool SortSegmentBasedOnEnd (Segment i,Segment j) { return (i.end<j.end); }

//Logic: Sort Segment based on end points. Check for overlaps
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), SortSegmentBasedOnEnd);
  int current = segments[0].end;
  points.push_back(current);
  for(int i=1; i< segments.size(); i++) {
    if ((current < segments[i].start) || (current > segments[i].end)) {
        current = segments[i].end;
        points.push_back(current);
    }
  }
  return points;
}

/*vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}*/

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
