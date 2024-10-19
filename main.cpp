#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
string s;

const vector<string> kCodes{"000000", "001111", "010011", "011100",
                            "100110", "101001", "110101", "111010"};

bool TryDecode(const string& p, char& ans) {
  for (auto i = 0; i < kCodes.size(); ++i) {
    const auto& c = kCodes[i];
    if (p == c) {
      ans = 'A' + i;
      return true;
    }

    auto dif = 0;
    for (auto j = 0; j < 6; ++j) {
      if (p[j] != c[j]) {
        ++dif;
      }
    }

    if (dif == 1) {
      ans = 'A' + i;
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> s;
  auto oss = ostringstream{};
  for (auto i = 1; i <= n; ++i) {
    const auto& p = s.substr((i - 1) * 6, 6);

    char x;
    const auto& tf = TryDecode(p, x);

    if (tf) {
      oss << x;
    } else {
      cout << i;
      return 0;
    }
  }

  cout << oss.str();

  return 0;
}