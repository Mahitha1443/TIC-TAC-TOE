#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <limits>
using namespace std;

int horizontalCompare(char a[3][3])
{
    int count;
    char same;
    for(int j =0;j<3;j++)
    {
        count = 0;
        if(a[j][0]==' ')
            continue;
        same = a[j][0];
        for(int i=0; i<3; i++)
        {
            if(same == a[j][i])
            {
                count ++;
            }
        
        }
        
        if(count == 3)  
        {
            return 1;
            break;
        }
        
    }
    return 0;
    
}


int verticalCompare(char a[3][3])
{
    int count ;
    char same;
    
    for(int i =0;i <3 ;i++)
    {
        count = 0;
        same = a[0][i];
    if(same == ' ')
        continue;
        for(int j=0;j<3;j++)
        {
          
        if(same == a[j][i] )
        {
            count ++;
              
        }
         
        }
    if (count == 3)
    {
    return 1;
    break;
    }
        
    }

    return 0;
}


int rightDiagonalCompare(char a[3][3])
{
    int count = 0;
    char same;
    int i =0;    
    int j =0;
    if(a[i][j] ==' ')
    {
    return 0;
    }
    same =a[i][j];
    while(i<3)
    {
    if(same == a[i][j])
    {
    count++;
    i= i+1;
    j=j+1;
    }
    else
    {
    break;
    }
    }
         
    if(count == 3)
    {
        return 1;
    }
         
    return 0;
         
}


int leftDiagonalCompare(char a[3][3])
{
    int count = 0;
    int i =0;    
    int j =2;
    char same;
    if(a[i][j] ==' ')
    {
    return 0;
    }
    same =a[i][j];
    while(i<3)
    {
    if(same == a[i][j])
    {
    count++;
    i= i+1;
    j=j-1;
    }
    else{
    break;
    }
            
    }
    if(count == 3)
    {
    return 1;
    }
    else
    {
    return 0;
    }
    
}


int assign(char a[3][3],int turn,int place)
{
    
    char choice ;
    char player1 = 'x';
    char player2 = '0';
    

    if(turn%2 == 0)
    { 
    choice = player2;
    }
    else{
    choice = player1;
    }
    switch(place)
    {
      case 1: a[0][0]= choice;
                break;
      case 2: a[0][1]= choice;
                break;
      case 3: a[0][2]= choice;
                break;
      case 4: a[1][0]= choice;
                break;
      case 5: a[1][1]= choice;
                break;
      case 6: a[1][2]= choice;
                break;
      case 7: a[2][0]= choice;
                break;
      case 8: a[2][1]= choice;
                break;
      case 9: a[2][2]= choice;
                break; 
      default: cout << "invalid input"<<endl;
    }
      
    if(turn > 9)
    {
    cout << "GAME IS A DRAW " <<endl;
    }
    //use the turn variable to determine who is the winner

  return 0;
  
}


int display(char a[3][3])
{
    for (int i  =0 ;i <3 ;i++)
    {
        for (int j =0;j<3;j++)
        {
        cout << "|" << a[i][j] ;
    
        }
        cout << "|"<<endl;
        if(i == 2)
            break;
         cout <<"--------"<<endl;
    }
    cout <<'\n'<<endl;
    return 0;
}


int beginDisplay(char a[3][3])
{
    
    cout << "----------TIC-TAC-TOE-----------"<<endl;
    display(a);

    
    /* to reassign the spaces to show empty board*/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = ' ';
        }
    }
    display(a);

    return 0;
}

int main(){
    // Write C++ code here
    int place;
    int count=0;
    int inputDeterminer =0;
    static int position = 0;
    char playAgain;
    int iVal[9] = {0,0,0,0,0,0,0,0,0};
    char a[3][3]  ={{'1','2','3'},{'4','5','6'},{'7','8','9'}} ;
    beginDisplay(a);
    
    for(int i = 1 ;i <=9 ;i++)
    {
        
        cout << "give input" <<endl;
         
        //int inputValue =assign(a,i,place);
        if (!(cin >> place)){
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--; // Decrement i to repeat the current iteration
            continue;
        }
        for (int i=1;i<=9;i++)
        {
        if(place == i)
        {
        inputDeterminer =1;
        break;
        }
        }           
        if(inputDeterminer == 0)
        {
        i--;
        cout<<"please provide a valid input from 1 - 10" <<endl;
        continue;
        }
        else{
        inputDeterminer = 0;
        }
        for (int k=0 ;k<9;k++)
        {
        if(place == iVal[k])
        {
        cout << "input already exist"<<endl;
        count =1;
        break;
        }
        }
        if (count ==1)
        {
           i--;
           count =0;
          continue; 
        }
        iVal[position] = place;
        position ++;
        assign(a,i,place);
        display(a);
        /*if (rightDiagonalCompare(a))
        {
            cout << rightDiagonalCompare(a) << endl;
            cout <<"done"<<endl;
            break;
        }*/
        //cout << horizontalCompare(a) <<endl;
    
        if(horizontalCompare(a)||verticalCompare(a)||rightDiagonalCompare(a)||leftDiagonalCompare(a) )
        {
            if(i%2 == 0)
            {
                cout<<"player 2 is winner" <<endl;
            
            
            }
            else
            {
                cout<<"player 1 is winner" <<endl;
           
            
            }
        cout <<"DO YOU WANT TO PLAY AGAIN Y/N "<<endl;
        cin >>  playAgain ;
        /* if((playAgain != 'y')||(playAgain != 'n')||(playAgain != 'Y')||(playAgain != 'N'))
        {
            cout << "enter valid response" <<endl;
        }
        */
        if(playAgain == 'y'||playAgain == 'Y')
        {
            
            i =1;
            system("cls");
            beginDisplay(a);
        }
        else
        {
            break;
        }
    }
    

    
}
cout << "-------GAME OVER-------" <<endl;
Sleep(2000);

return 0;

}
