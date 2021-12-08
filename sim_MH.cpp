#include <iostream>
#include <ctime>

int main() {
  int simulations = 100000; //Number of simulations
  int stayWins = 0;
  int switchWins = 0;

  srand (time(NULL));

  for(auto i=0; i<simulations;i++) { 
    int door_with_car = rand() % 3 + 1;//winning door
    int door_chosen = rand() % 3 + 1;//let the contestant chose any of 1/2/3 door
    int door_revealed_with_goat;//the door with goat not chosen

    do {
      door_revealed_with_goat = rand() % 3 + 1;
    } while (door_revealed_with_goat == door_chosen || door_revealed_with_goat == door_with_car);
    
    int door_not_chosen;//if door_with_car==door_chosen, then this is the goat-door not revealed
    do {
      door_not_chosen = rand() % 3+1;
    } while (door_not_chosen == door_chosen || door_not_chosen == door_revealed_with_goat);

    int switchChoice = rand() % 2 ;//contestant wants to switch or not?
    if (!switchChoice) {//do not switch
      if (door_chosen == door_with_car)	{
        stayWins++;
      } else {
        switchWins++;
      }
    }
    if (switchChoice) {//switch the choice
      door_chosen = door_not_chosen;
      if (door_chosen == door_with_car)	{
        switchWins++;
      } else {
        stayWins++;
      }
    }
  } 

  std::cout << "Out of "<<simulations<<" games, the contestant won " << stayWins << " times by staying with his/her original choice and won " << switchWins << " times by switching his/her choice.\n\n" ;

  std::cout<< "Probability of winning if switched: ";
  std::cout<< static_cast<double>(switchWins)/(switchWins+stayWins) << std::endl;
  std::cout<< "** Hence the contestant should";
  stayWins>switchWins ? (std::cout<< " stay with the 1st choice.**\n"):(std::cout<< " switch to another door.**\n");

  return 0;
}

