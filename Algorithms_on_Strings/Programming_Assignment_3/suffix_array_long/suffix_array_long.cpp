#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::map;




vector<int> ComputeCharClasses(string S, vector<int> order) {
    vector<int> class_;
    class_.resize(S.size());
    class_[order[0]] = 0;
    for (int i = 1; i <= S.size() - 1; i++) {
        if (S[order[i]] != S[order[i - 1]]) {
            class_[order[i]] = class_[order[i - 1]] + 1;
        }
        else
        {
            class_[order[i]] = class_[order[i - 1]];
        }
    }
    return class_;
}
vector<int> SortDoubled(string S, int L, vector<int> order, vector<int> class_) {
    vector<int> count;
    count.resize(S.size());
    vector<int> newOrder;
    newOrder.resize(S.size());

    for (int i = 0; i <= S.size() - 1; i++) {
        count[class_[i]] = count[class_[i]] + 1;
    }
    for (int j = 1; j <= S.size() - 1; j++) {
        count[j] = count[j] + count[j - 1];
    }
    for (int i = S.size() - 1; i >= 0; i--) {
        int start = (order[i] - L + S.size()) % S.size();
        int cl = class_[start];
        count[cl]--;
        newOrder[count[cl]] = start;
    }

    return newOrder;
}
vector<int> UpdateClasses(vector<int> newOrder, vector<int> class_, int L) {
    int n = newOrder.size();
    vector<int> newClass;
    newClass.resize(n);
    newClass[newOrder[0]] = 0;
    for (int i = 1; i <= n - 1; i++) {
        int cur = newOrder[i];
        int prev = newOrder[i - 1];
        int mid = cur + L;
        int midPrev = (prev + L) % n;
        if ((class_[cur] != class_[prev]) || (class_[mid] != class_[midPrev])) {
            newClass[cur] = newClass[prev] + 1;
        }
        else {
            newClass[cur] = newClass[prev];
        }
    }
    return newClass;
}



vector<int> SortCharacters(string S) {
    vector<int> order;
    order.resize(S.size());
    map<char, int> count;
    count.insert(std::pair<char, int>('$', 0));
    count.insert(std::pair<char, int>('A', 0));
    count.insert(std::pair<char, int>('C', 0));
    count.insert(std::pair<char, int>('G', 0));
    count.insert(std::pair<char, int>('T', 0));

    for (int i = 0; i <= S.size() - 1; i++) {
        count[S[i]] = count[S[i]] + 1;
    }
    for (int j = 1; j < count.size(); j++) {
        count[j] = count[j] + count[j - 1];
    }
    for (int i = S.size() - 1; i >= 0; i--) {
        int c = S[i];
        count[c]--;
        order[count[c]] = i;
    }

    return order;
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& S) {
    vector<int> order = SortCharacters(S);
    vector<int> class_ = ComputeCharClasses(S, order);
    int L = 1;
    while (L < S.size()) {
        order = SortDoubled(S, L, order, class_);
        class_ = UpdateClasses(order, class_, L);
        L = 2 * L;
    }

  return order;
}


int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
