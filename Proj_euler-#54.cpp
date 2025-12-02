#include <bits/stdc++.h>
#include <iostream>

// LOGIC
// we first represent the 'hand' in a 4x13 2d array, where each cell represent
// one card we now find sum of this array along each axis, suit and rank, this
// is the key to find hand type we can find various attributes of this
// 'sum-vector' like max element, count of an element, and also coherence, a
// term i used to denote the closeness of ranks coherence=5 incase of straight.
// and thats it
//
//
//
//
// the structure of ranks are organised as
// 0 1 2 3 4 5 6 7 ... 13 14 | [15]
// * * " " " " " " ... K  A  | size
// we sacrifice the first two cells to improve readability
//
// input file
// rank, suit
// 5 D, 7 S, Q C,...
//
// suitsum structure
// X X X X | R R R R
// ~suits~ | 2 3 4 5 ... A
//  indeces| 4 5 6 7 ... 16
//
//
//  the cardsum structure is of particular importance, it has 3 different
//  meanings, it was initially adopted to improve understandability, while it
//  served its purpose, transfering data between functions require some mental
//  overhead
//
//  its size is 17 (0 to 16)[4+13] for suit sum and rank sum
//
//  immediate rep                   | - - - - 0 1 2 3 4 5 6  7  8  9  10 11 12
//  // when we subtract the begin()+4 meaning                         | - - - -
//  2 3 4 5 6 7 8  9  :  ;  <   =  > // index and the card it represents actual
//  index                    | 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 //
//  physical index [during the coding process, 'index=4' meant a lot to me (not
//  emotional) i could find a lot of interpretations for index 4, the value or
//  the relative space or whatnot; it was aplified by the fact that the coding
//  took 2-3 days. so yeah. naming things is hard]
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

// # standard followed: four of a kind of 8: X8; power:card_value
// now to compare we need functins to find patterns in the sum vector
// i.e., adjacent, maxsum, etc

int FindMaxcount(std::vector<int> cardSum)
// card sum has 4+13 elements
{
  // int one = 0, two = 0, three = 0, four = 0;
  int max = 0;
  for (int i = 4; i < 17; i++) {
    if (cardSum[i] > max) {
      max = cardSum[i];
    }
  }
  return max;
}

int noCoherent(std::vector<int> cardSum, int index) {
  // cardSum has index 0 to 16
  int count = 1;
  while (true) {
    index++;
    if (index > 16) {
      break;
    }
    if (cardSum[index] == 1) {
      count++;
    } else {
      break;
    }
  }
  return count;
}

void insertRest(std::vector<char> &vect, std::vector<int> sum) {
  // we assume 'key' cards are already inserted, only need to push dummy cards
  int indexcard = 14;
  for (auto it = sum.rbegin(); it != sum.rbegin() + 13; it++, indexcard--) {
    if (*it == 1) {
      vect.push_back(indexcard + 48);
    }
  }
}

std::string FindPower(std::vector<int> &cardSum) {
  std::vector<char> power;
  // using max sum we can find some hands
  int samesuit = (std::find(cardSum.begin(), cardSum.begin() + 4, 5) !=
                  cardSum.begin() + 4); // true if found
  auto firstone = std::find(cardSum.begin() + 4, cardSum.end(), 1);
  int oneindex = firstone - (cardSum.begin() + 4) + 2; // inthe range 0 to 13
  int bond = noCoherent(cardSum, oneindex + 2);
  int maxfreq = FindMaxcount(cardSum);

  if (samesuit) {  // flush, royal flush, straight flush
    if (bond == 5) // royal flush, straight flush
    {
      if (oneindex == 13) { // last 5 cards
        // royal flush
        power.push_back('Z');
      } else {
        // str flush
        power.push_back('Y');
        power.push_back(oneindex + 48);
      }
    } else // normal flush
    {
      power.push_back('Q');
      // power.push_back(lastone + 32); // neeed to push all remaining cards
      insertRest(power, cardSum);
    }
  } // end of same suit

  else {
    // not same suit
    if (maxfreq == 4) {
      // 4 of a kind
      power.push_back('X');
      power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 4) -
                      (cardSum.begin() + 4) + 50);
      // not exactly the correct num,
      // but will act as a good measure
      insertRest(power, cardSum);
    } else if (maxfreq == 3) // 3 ok or fullhouse
    {
      if (std::find(cardSum.begin() + 4, cardSum.end(), 2) !=
          cardSum.end()) // there is a two, so fullhouse
      {
        power.push_back('R');
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 3) -
                        (cardSum.begin() + 4) + 50);
        // not exactly the correct num,
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 2) -
                        (cardSum.begin() + 4) + 50);
        // not exactly the correct num,
      } else // no two only a 3ok, push all else
      {
        power.push_back('D');
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 3) -
                        (cardSum.begin() + 4) + 50);
        // not exactly the correct num,
        // push the remaining cards
        insertRest(power, cardSum);
      }

    } else if (maxfreq == 2) // two pair or pair
    {
      if (std::count(cardSum.begin() + 4, cardSum.end(), 2) !=
          2) { // only a pair
        power.push_back('B');
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 2) -
                        (cardSum.begin() + 4) + 50);
      } else { // two pair
        power.push_back('C');
        power.push_back(62 -
                        (std::find(cardSum.rbegin(), cardSum.rend() - 4, 2) -
                         cardSum.rbegin()));
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 2) -
                        (cardSum.begin() + 4) + 50);
      }
      insertRest(power, cardSum);
    } else if (maxfreq == 1) // high card or straight
    {
      if (bond == 5) { // straight, inserts the lowest element
        power.push_back('P');
        power.push_back(std::find(cardSum.begin() + 4, cardSum.end(), 1) -
                        (cardSum.begin() + 4) + 50);
      } else // high card need to push all else
      {
        power.push_back('A');
        insertRest(power, cardSum);
      }
    }
  }
  // return power;
  return std::string(power.begin(), power.end());
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

  // now the final calculations
  int finals = 0;
  for (int i = 0; i < 2000; i += 2) {
    // need to convert the hand from array to sums, then to power, then compare
    auto sum1 = FindSum(MasterHand[i]);
    auto sum2 = FindSum(MasterHand[i + 1]);
    auto pow1 = FindPower(sum1);
    auto pow2 = FindPower(sum2);
    if (pow1 > pow2) {
      finals++;
    }
  }

  // finally
  std::cout << "players one wins: " << finals << std::endl;
}
