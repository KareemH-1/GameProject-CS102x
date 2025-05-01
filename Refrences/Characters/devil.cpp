#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;


    int chanceShoot(){
        int chance = rand() % 3 + 1;
        
        if(chance == 1) return 1;
        else return 0; 
    }

    int chanceMove(){
        int chance = rand() % 2 + 1;
        
        if(chance == 1) return 1;
        else return 2; 
    }
    
    void drawdevil(int& row, int& col){



    }

    void SpawnFireBall(int rDevil , int cDevil , int& row,int& col, int &r){
        int chance = chanceShoot();
      
        if(chanceShoot()){                                
            r = chanceMove();

            if(r == 1){
                int row = rDevil - 10;
                int col = cDevil - 1;
            }
            else if(r == 2){

                int row = rDevil - 3;
                int col = cDevil - 1;
            }
        }
        if(r==1){{
            for(int i=row;;i--){
                for(int j=col;;j++){
                    cout<<char(232);
                }
            }
        }}
    }

    //asci 
    void drawFireBall(int& row, int& col , int r){
        
    }
    
int main(){
    srand(time(0));
 }