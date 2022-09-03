#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <math.h>


bool uniqueCharacters(std::string str) {
    long j = 0;
	for (int i = 0; i < str.size(); i++) {
			if (j & (1 << (str[i] - 65)-1)) {
				return false;
			}
            j |= 1 << (str[i] - 65)-1;
		}
	return true;
}



bool is_permutation(const std::string& s1, std::string& s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  std::unordered_map<char, int> m1;
  std::unordered_map<char, int> m2;
  for (auto x : s1) {
    ++m1[x];
  }
  for (auto x : s2) {
    ++m2[x];
  }
  auto beg1 = m1.begin();
  auto end1 = m1.end();
  auto beg2 = m2.begin();
  auto end2 = m2.end();
  for (; beg1 != end1; ++beg1, ++beg2) {
    if (beg1->second != m2[beg1->first]) {
      return false;
    }
  }
  if (beg2 != end2) {
    return false;
  }
  return true;
}
std::string urlify (std::string str)
{
    std::string res;
    std::string str2 = "%20";

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != ' ')
        res.push_back(str[i]);

        else 
        res+=str2;
    }
return res;
}


bool canPermutePalindrome(std::string s) {
  std::unordered_map<char,int> cnt;
  int n=s.size();
  for(int i=0; i<n; i++) {
    cnt[s[i]]++;
  }
  int isCountOdd=0;
  for(auto it:cnt) {
    if(isCountOdd==1 && it.second%2!=0) return 0;
    else if(it.second%2!=0) isCountOdd++;
    else continue;
  }
  return 1;
}


bool are_one_edit_away(const std::string& s1, std::string& s2) {
  if (abs((int)s1.size() - (int)s2.size()) > 1) {
    return false;
  }
  if (s1.size() == s2.size()) {
    int count{};
    for (int i{}; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        if (count == 0) {
          ++count;
        }
        else {
          return false;
        }
      }
    }
    return true;
  }
  if (s1.size() < s2.size()) {
    int count{};
    for (int i{}; i < s1.size(); ++i) {
      if (s1[i] != s2[i + count]) {
        if (count == 0) {
          ++count;
          --i;
        }
        else {
          return false;
        }
      }
    }
    return true;
  }
  if (s1.size() > s2.size()) {
    int count{};
    for (int i{}; i < s2.size(); ++i) {
      if (s2[i] != s1[i + count]) {
        if (count == 0) {
          ++count;
          --i;
        }
        else {
          return false;
        }
      }
    }
    return true;
  }
  return true;
}


std::string compress(std::string& line) {
  std::string result;
  int index{};
  int size = line.size();
  while (index != size) {
    int count{1};
    while ((index + count < size) && (line[index + count] == line[index])) {
      ++count;
    }
    result += std::to_string(count);
    result.push_back(line[index]);
    index += count;
  }
  return (result.size() < line.size() ? result : line);
}



template <int n>
void rotate(std::array<std::array<int, n>, n>& matrix) {
  for (int i{}; i < n / 2; ++i) {
    for (int j{}; j < n / 2; ++j) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][n - 1 - i];
      matrix[j][n - 1 - i] = matrix[n - 1 - i][n - i - j];
      matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i];
      matrix[n - 1 - j][i] = temp;
    }
  }
  if (n % 2) {
    for (int i{}; i < n / 2; ++i) {
      int j = n / 2;
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][n - 1 - i];
      matrix[j][n - 1 - i] = matrix[n - 1 - i][n - i - j];
      matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i];
      matrix[n - 1 - j][i] = temp;
    }
  }
}



template <int m, int n>
void set_zeroes(std::array<std::array<int, n>, m>& matrix) {
  std::bitset<m> rows;
  std::bitset<n> cols;
  for (int i{}; i < m; ++i) {
    for (int j{}; j < n; ++j) {
      if (matrix[i][j] == 0) {
        rows[i] = true;
        cols[j] = true;
      }
    }
  }
  for (int i{}; i < m; ++i) {
    for (int j{}; j < n; ++j) {
      if (rows[i] || cols[j]) {
        matrix[i][j] = 0;
      }
    }
  }
}



bool is_substring(const std::string& s, const std::string& l) {
  if (s.size() > l.size()) {
    return false;
  }
  if (s.size() == 0) {
    return true;
  }
  unsigned long hash1{};
  unsigned long hash2{};
  for (int i{}; i < s.size(); ++i) {
    hash1 += s[i] * pow(128, s.size() - i - 1);
    hash2 += l[i] * pow(128, s.size() - i - 1);
  }
  if (hash1 == hash2) {
    bool same{true};
    for (int i{}; i < s.size(); ++i) {
      if (s[i] != l[i]) {
        same = false;
        break;
      }
    }
    if (same) {
      return true;
    }
  }
  for (int i = s.size(); i < l.size(); ++i) {
    hash2 -= l[i - s.size()] * pow(128, s.size() - 1);
    hash2 *= 128;
    hash2 += l[i];
    if (hash1 != hash2) {
      continue;
    }
    else {
      bool same{true};
      for (int j{}; j < s.size(); ++j) {
        if (s[j] != l[i - s.size() + j + 1]) {
          same = false;
          break;
        }
      }
      if (same) {
        return true;
      }
    }
  }
  return false;
}

bool is_rotation(const std::string& s1, const std::string& s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  for (int i{}; i < s1.size(); ++i) {
    if (is_substring(s1.substr(0, i), s2)) {
      if (s1.substr(i, s1.size() - i) + s1.substr(0, i) == s2) {
        return true;
      }
    }
  }
  return false;
}



int main() {
  std::string s1 = "ole";
  std::string s2 = "ple";
  std::cout << are_one_edit_away(s1, s2) << std::endl;
}