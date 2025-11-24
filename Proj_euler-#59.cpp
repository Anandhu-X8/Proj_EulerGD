
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
  int num, count = 0;
  char comma;
  unordered_map<int, int> hash0, hash1, hash2;
  ifstream f("0059_cipher.txt");
  while (f >> num) {
    switch (count % 3) {
    case 0:
      hash0[num]++;
      break;
    case 1:
      hash1[num]++;
      break;
    case 2:
      hash2[num]++;
      break;
    default:
      break;
    }
    f >> comma;
    count++;
  }
  vector<int> tops;
  // hashmap is finished reading
  int best = 0, top;
  for (auto it : hash0) {
    if (it.second > best) {
      best = it.second;
      top = it.first;
    }
  }
  tops.push_back(top);
  best = 0;
  for (auto it : hash1) {
    if (it.second > best) {
      best = it.second;
      top = it.first;
    }
  }
  tops.push_back(top);
  best = 0;
  for (auto it : hash2) {
    if (it.second > best) {
      best = it.second;
      top = it.first;
    }
  }
  tops.push_back(top);
  // cout << "the top element is : " << top << endl;
  vector<int> keys;
  cout << "the tops are\n";

  for (int i = 0; i < 3; i++) {
    //    cout << tops[i] << " ";
    int keynum = tops[i] ^ 32;
    // now print these numbers in letters
    keys.push_back(keynum);
    char key = keynum;
    cout << key << " ";
  }
  f.close();
  ifstream ff("0059_cipher.txt");
  count = 0;
  int res;
  char ch;
  int finals_sum = 0;
  while (ff >> num) {
    switch (count % 3) {
    case 0:
      res = num ^ keys[0];
      finals_sum += res;
      ch = (char)res;
      cout << ch;
      break;
    case 1:
      res = num ^ keys[1];
      finals_sum += res;
      ch = (char)res;
      cout << ch;
      break;
    case 2:
      res = num ^ keys[2];
      finals_sum += res;
      ch = (char)res;
      cout << ch;
      break;
    default:

      break;
    }
    count++;

    ff >> comma;
  }
  int sum = 0;
  cout << "\n sum: " << finals_sum << "\n";

  return 0;
}
