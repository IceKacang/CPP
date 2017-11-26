#include<iostream>
#include"ClassHeader.h"
using namespace std;

int main(){
   Deck myturn;
   myturn.CreateDeck();
   myturn.Shuffle();
   Storage choose=myturn.DrawCard();
   cout<<"The card that you choose is:"<<choose.suit<<" "<<choose.digit<<endl;
   return 0;
}
