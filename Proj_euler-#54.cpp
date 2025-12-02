#include <bits/stdc++.h>
#include <iostream>

// the structure of ranks are organised as
// 0 1 2 3 4 5 6 7 ... 13 14 | [15]
// * * " " " " " " ... K  A  | size
//
// input file
// rank, suit
// 5 D, 7 S, Q C,...
//
void print2d(int arr[4][15]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 15; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
void printVec(std::vector<int> vec) {
  for (auto a : vec) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}

std::vector<int> FindSum(int arr[4][15]) {
  // output the row wise sum and column wise in an appended manner
  std::vector<int> suitsum(4, 0);
  std::vector<int> ranksum(13, 0);
  // ai recommended this elite approach
  for (int suit = 0; suit < 4; suit++) {
    for (int rank = 2; rank < 15; rank++) {
      if (arr[suit][rank] == 1) {
        // array has elements from position 2 to 14, (13 cards)
        // these must be inserted in position 0 to 12 (13) in the vector
        suitsum[suit]++;
        ranksum[rank - 2]++;
      }
    }
  }
  suitsum.insert(suitsum.end(), ranksum.begin(), ranksum.end());
  return suitsum;
}

void HandtoArray(int (&handArr)[4][15], std::vector<int> handVect) {
  // conver a numeric vector to 2d array
  // vector contains one hand = 10 characters
  // eg: 11 2 2 3 11 0 12 3 14 1
  // in the form rank, suit: 9 C, ...
  int count = 0;
  int suit, rank;
  while (count < 10) {
    if (count % 2 == 0) {
      // its rank
      rank = handVect[count];
    } else {
      // its suit, also by now we have already read the rank
      suit = handVect[count];
      // now insert info of suit and rank
      handArr[suit][rank] = 1;
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
  // need to make a vector for each player hand
  while (std::getline(file, line)) { // line contains two hands
    int plcount = 0;
    // inner loop for words
    std::stringstream ss(line);
    std::vector<int> oneHand;
    while (ss >> word) {
      plcount++;
      // make a structure for each word
      for (char ch : word) {
        if (ch <= '9' && ch >= '0') {
          // numbers will be of the range 2-9
          oneHand.push_back(ch - '0');
        } else {
          oneHand.push_back(cardSuiteValues[ch]);
        }
      }
      if (plcount == 5) // got all for player 1
      {
        HandtoArray(MasterHand[handcount], oneHand);
        handcount++;
        plcount = 0; // will this work in forcing a new loop for player 2?
        oneHand.clear();
      }
      // fill MasterHand[handcount]
      // masternhand has 10 chars -> 5 cards -> so total of 2000 entries 1000
      // dealings
    }
  }
}
