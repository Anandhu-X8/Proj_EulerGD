#include <bits/stdc++.h>
#include <iostream>

// the structure of ranks are organised as
// 0 1 2 3 4 5 6 7 ... 13 14 | [15]
// * * " " " " " " ... K  A  | size
void printVec(std::vector<int> vec) {
  for (auto a : vec) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}
std::vector<int> FindSum(int arr[4][15], char dir) {
  // output the row wise sum and column wise in an appended manner
  std::vector<int> suitsum(4, 0);
  std::vector<int> ranksum(13, 0);
  // ai recommended this elite approach
  for (int suit = 0; suit < 4; suit++) {
    for (int rank = 2; rank < 15; rank++) {
      if (arr[suit][rank] == 1) {
        suitsum[suit]++;
        ranksum[rank]++;
      }
    }
  }
  suitsum.insert(suitsum.end(), ranksum.begin(), ranksum.end());
  return suitsum;
}
// function to find sum of a 2d array along a dimension
// std::vector<int> FindSum(int arr[4][15], char dir) {
//   // TODO  fix this!
//   // default options for col wise summing
//   int outer = 15, inner = 4;
//   if (dir == 'R') {
//     // sum of rows
//     outer = 4;
//     inner = 15;
//   }
//   std::vector<int> sumVector;
//   for (int i = 0; i < outer; i++) {
//     int sum = 0;
//     for (int j = 0; j < inner; j++) {
//       if (dir == 'R')
//         sum += arr[i][j];
//       else
//         sum += arr[j][i];
//     }
//     sumVector.push_back(sum);
//   }
//   return sumVector;
// }

void HandtoArray(int (&handArr)[4][15], std::vector<int> handVect) {
  // conver a numeric vector to 2d array
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
  // std::cout << "ends here" << std::endl;
  // std::cout << FindSum(MasterHand[0], 'R') << std::endl;
  std::vector<int> dummy = FindSum(MasterHand[0], 'R');
  // for (auto a : dummy) {
  //   std::cout << a << std::endl;
  // }
}
