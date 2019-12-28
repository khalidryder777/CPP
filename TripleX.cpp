#include<iostream>
#include<ctime>
void PrintIntroduction(int Difficulty)
{
    
std::cout << "\n\n\nYou have found a 3 digit puzzle in a secret tomb of level "<< Difficulty;
std::cout << "\n Enter the correct 3 digit code to access the tomb";


}
bool PlayGame(int Difficulty)
{   
    PrintIntroduction(Difficulty);
    
    int CodeA = rand() % Difficulty + Difficulty; //genrating random varible in accordence with the difficulty
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;
    
    int CodeSum = CodeA+CodeB+CodeC ;
    int CodeProduct = CodeA*CodeB*CodeC ;
    
    std::cout <<"\n There are three numbers in the code";
    std::cout <<"\n The codes add up to   : "<< CodeSum ;
    std::cout <<"\n The codes multiply to : "<< CodeProduct ;
    std::cout << "\n ";
      
    int GuessA , GuessB , GuessC;
    std:: cout << "Enter the three codes....";
    std::cout << "\n ";
    std::cin >> GuessA >> GuessB >> GuessC ;
    std:: cout << "\n You've entered : " <<" "<< GuessA <<" "<< GuessB <<" "<< GuessC ;
    
    int GuessSum = GuessA+GuessB+GuessC ;
    int GuessProduct = GuessA*GuessB*GuessC ;
    
    std::cout <<"\n Your codes add up to   : "<< GuessSum ;
    std::cout <<"\n Your codes multiply to : "<< GuessProduct ;
    if (GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        std::cout<<"\n You Win ! *** Moving to next level ***";
        return true;
        }
    else
    {
        std::cout<<"\n You loose ! *** Retry the current level ***";
        return false;
        }

}
 
int main()
{   srand(time(NULL)); //create a new random sequence based on time of the day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty<=MaxDifficulty)//Loop the game until all the levels are completed
    {   
        
        bool bLevelComplete=PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any error
        std::cin.ignore();// Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
               

    }
    std::cout<<"\n*** Congractulations ,you have unlocked the TOMB ***";
    return 0;
}