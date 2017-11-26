#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<sstream>
using namespace std;

/////-----------------------------------------------------
/////This is an example code with using class, structure, 
/////enumeration, vector and random function features
/////in C++ programming.
/////-----------------------------------------------------

enum Suit {Clubs=0, Spades, Diamonds, Hearts};   
const char *suit_str[]={"♣", "♠", "♦", "♥"};
struct Card{
   Suit suit;
   string digit;
};

struct Storage{
   string suit;
   string digit;
};

class Deck{
public:
   void CreateDeck();
   void Shuffle();
   Storage DrawCard();
private:
   Card cards [52];
   Storage card [52];
   Suit card_type;
};

void Deck::CreateDeck(){
   cout<<"Generating a total of 52 cards."<<endl;
   for (int j=0; j<4; j++){
      for (int i=0; i<13; i++){
            switch(j){
               case 0: card_type=Clubs; break;
               case 1: card_type=Spades; break;
               case 2: card_type=Diamonds; break;
               case 3: card_type=Hearts; break;
            }
            cards[i+j*13].suit=card_type;

            switch(i){
               case 0: cards[i+j*13].digit= "A"; break;
               case 9: cards[i+j*13].digit= "10"; break;
               case 10: cards[i+j*13].digit= "J"; break;
               case 11: cards[i+j*13].digit= "Q"; break;
               case 12: cards[i+j*13].digit = "K"; break; 
               default: cards[i+j*13].digit=i+1+'0'; break;
            }
            //cout<<"Debugging: "<<suit_str[cards[i+j*13].suit]<<" "<<cards[i+j*13].digit<<endl;
      }
      //cout<<"Next section"<<endl;
   } 
   cout<<"The cards are successfully generated."<<endl;
}

void Deck::Shuffle(){
   srand(time(0));
   vector<Storage> myvector;
   for(int i=0; i<52; i++){ 
      myvector.push_back(Storage());
      myvector[i].suit=suit_str[cards[i].suit];
      myvector[i].digit=cards[i].digit;
   }
   //for(int i=0; i< 52; i++){
   //   cout<<"Debugging: "<<myvector[i].suit<<" "<<myvector[i].digit<<endl;
   //}
   random_shuffle(myvector.begin(), myvector.end());
   
   for(int i=0; i< 52; i++){
      card[i].suit=myvector[i].suit;
      card[i].digit=myvector[i].digit;
      //cout<<"Debugging: "<<card[i].suit<<" "<<card[i].digit<<endl;
   }
}

Storage Deck::DrawCard(){
   string i;
   int n;
   cout<<"Please choose any number from 1-52 to select your card"<<endl;
   cin>>i;
   stringstream geek(i);
   geek>>n;
   return card[n-1];
}
