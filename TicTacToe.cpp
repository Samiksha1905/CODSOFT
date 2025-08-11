#include<iostream>
using namespace std;
char square[10]={'o','1','2','3','4','5','6','7','8','9'};
int checkWin();
void ResetGame();
void Board();
bool PlayAgain();

int main(){
    do{
    ResetGame();
    int player=1,i,choice;
    char CurrentPlayer;
    
    do{
        Board();
        player=(player%2)?1:2;
 
        cout<<"Player "<<player<<" Enter a number: ";

        cin>>choice;
        
        CurrentPlayer=(player==1)?'X':'O';
        
        if(choice==1 && square[1]=='1')
        square[1]=CurrentPlayer;
        else if(choice==2 && square[2]=='2')
        square[2]=CurrentPlayer;
        else if(choice==3 && square[3]=='3')
        square[3]=CurrentPlayer;
        else if(choice==4 && square[4]=='4')
        square[4]=CurrentPlayer;
        else if(choice==5 && square[5]=='5')
        square[5]=CurrentPlayer;
        else if(choice==6 && square[6]=='6')
        square[6]=CurrentPlayer;
        else if(choice==7 && square[7]=='7')
        square[7]=CurrentPlayer;
        else if(choice==8 && square[8]=='8')
        square[8]=CurrentPlayer;
        else if(choice==9 && square[9]=='9')
        square[9]=CurrentPlayer;

        else{
            cout<<"Invalid Move. Pls try again!";
            player--;
        }
        i=checkWin();
        player++;
    }
    while(i==-1);

    Board();
    if(i==1)
    cout<<"-->\aPlayer "<<--player<<" wins.\n";
    else
    cout<<"-->\aGame Draw";
    } while(PlayAgain());
    return 0;
}

int checkWin(){
    
    if(square[1]==square[2] && square[2]==square[3])
    return 1;
    else if(square[4]==square[5] && square[5]==square[6])
    return 1;
    else if(square[7]==square[8] && square[8]==square[9])
    return 1;
    else if(square[1]==square[5] && square[5]==square[9])
    return 1;
    else if(square[3]==square[5] && square[5]==square[7])
    return 1;
    else if(square[1]==square[4] && square[4]==square[7])
    return 1;
    else if(square[2]==square[5] && square[5]==square[8])
    return 1;
    else if(square[3]==square[6] && square[6]==square[9])
    return 1;

    else if(square[1]!='1' && square[2]!='2' && square[3]!='3'
    && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7'
    && square[8]!='8' && square[9]!='9')

    return 0;

    else
    return -1;
}

bool PlayAgain() {
    char choice;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

void ResetGame() {
    for (int i = 1; i <= 9; ++i) {
        square[i] = '0' + i;
    }
}


void Board(){
    system("cls");

    cout<<"\n\nTic Tac Toe\n\n";
    cout<<"Player 1(X) - Player 2(O)"<<endl;

    cout<< " " <<square[1]<< "  |  " <<square[2]<< "  |  "  <<square[3]<< " " <<endl;
    
    cout<<"--------------"<<endl;

    cout<< " " <<square[4]<< "  |  " <<square[5]<< "  |  " <<square[6]<<"  "<<endl;

    cout<<"--------------"<<endl;

    cout<< " " <<square[7]<< "  |  " <<square[8]<< "  |  " <<square[9]<< "  " <<endl;
    
}
