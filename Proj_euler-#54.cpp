#include <bits/stdc++.h>
#include <iostream>
// function to find sum of a 2d array along a dimension
std::vector<int> FindSum(int arr[4][15], char dir) {
  // TODO  fix this!
  // default options for col wise summing
  int outer = 15, inner = 4;
  if (dir == 'R') {
    // sum of rows
    outer = 4;
    inner = 15;
  }

  std::vector<int> sumVector;
  for (int i = 0; i < outer; i++) {
    int sum = 0;
    for (int j = 0; j < inner; j++) {
      if (dir == 'R')
        sum += arr[i][j];
      else
        sum += arr[j][i];
    }
    sumVector.push_back(sum);
  }
  return sumVector;
}

void HandtoArray(int (&handArr)[4][15], std::vector<int> handVect) {
  // vector contains one hand = 10 characters
  int count = 0;
  int suit, rank;
  while (count < 10) {
    if (count % 2 == 0) {
      // its suit
      suit = handVect[count];
    } else {
      // its rank, also by now we have already read the suit
      rank = handVect[count];
      // now insert info of suit and rank
      handArr[suit][count] = 1;
    }
    count++;
  }
}

int main() {
  // col : 0-14 : sacrifising two positions for readability
  int MasterHand[2000][4][15] = {};
  // exploiting char type to make a makeshift hashmap
  int cardSuiteValues[256];
  cardSuiteValues['A'] = 14;
  cardSuiteValues['K'] = 13;
  cardSuiteValues['Q'] = 12;
  cardSuiteValues['J'] = 11;
  cardSuiteValues['T'] = 10;

  cardSuiteValues['S'] = 0;
  cardSuiteValues['C'] = 1;
  cardSuiteValues['H'] = 2;
  cardSuiteValues['D'] = 3;

  std::ifstream file("0054_poker.txt");
  if (!file) {
    std::cout << "error";
  }
  int handcount = 0;
  // outer loop for line
  std::string line, word;
  // the loop below fetches hand of two players
  while (std::getline(file, line)) {
    // inner loop for words
    std::stringstream ss(line);
    while (ss >> word) {
      // make a structure for each word
      std::vector<char> oneHand;
      for (char ch : word) {
        if (ch <= '9' && ch >= '0') {
          oneHand.push_back(ch - '0');
        } else {
          oneHand.push_back(cardSuiteValues[ch]);
        }
      }
      // fill MasterHand[handcount]
      HandtoArray(MasterHand[handcount][][], oneHand);
      handcount++;
      oneHand.clear();
    }
  }
}
