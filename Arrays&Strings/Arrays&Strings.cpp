#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>
#include <math.h>
#include <algorithm>


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


bool arePermutation(const std::string& s1, std::string& s2) {
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
        res += str2;
    }
return res;
}


bool isOneEditDistance(std::string s, std::string t) {
  int diff = s.size()-t.size();
  diff = diff > 0 ? diff : -diff;
  if (s == t || diff > 1) { return false; }
  int i = 0; 
  int j = 0; 
  bool diffFound = false;
  while (i<s.size() && j<t.size()) {
    if (s[i] != t[j]) {
      if (diffFound) { return false; }
        if (s.size() >= t.size()) { ++i; }
        if (s.size() <= t.size()) { ++j; }
        diffFound = true;
        } 
        else {
          ++i;
          ++j;
           }
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


int** rotated_matrix(int** mat, int size) {
    int** rot_90 = new int*[size];
    for (int i = 0; i < size; ++i) {
        rot_90[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rot_90[i][j] = mat[size - j - 1][i];
        }
    }
    return rot_90;
}


void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<bool> rows(matrix.size());
    std::vector<bool> cols(matrix[0].size());

    for(int i{}; i < matrix.size(); ++i) {
        for(int j{}; j < matrix[i].size(); ++j) {
            if(matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i{}; i < rows.size(); ++i) {
        if(rows[i]) {
            for(int j{}; j < matrix[0].size(); ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i{}; i < cols.size(); ++i) {
        if(cols[i]) {
            for(int j{}; j < matrix.size(); ++j) {
                matrix[j][i] = 0;
            }
        }
    }
}

bool stringRotate(std::string s1, std::string s2) {
    if(s1.size() == s2.size()) {
        for(int i{}; i < s2.size(); i++) {
            if(s1[i] == s2[0]) {
                return s2 == s1.substr(i,s2.size());
            } else {
                s1.push_back(s1[i]);
            }
        }
    }
    return false;
}



int main() {
  std::string s1 = "epl";
  std::string s2 = "ple";
  std::cout << stringRotate(s1, s2) << std::endl;
}