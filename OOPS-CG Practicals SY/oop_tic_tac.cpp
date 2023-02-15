#include<iostream>
using namespace std;

char sq[10]={'0','1','2','3','4','5','6','7','8','9'};

int win(){
    if(sq[1]==sq[2] && sq[2]==sq[3])
        return 1;
    else if(sq[4]==sq[5] && sq[5]==sq[6])
        return 1;
    else if(sq[7]==sq[8] && sq[8]==sq[9])
        return 1;
    else if(sq[1]==sq[4] && sq[4]==sq[7])
        return 1;
    else if(sq[2]==sq[5] && sq[5]==sq[8])
        return 1;
    else if(sq[3]==sq[6] && sq[6]==sq[9])
        return 1;
    else if(sq[1]==sq[5] && sq[5]==sq[9])
        return 1;
    else if(sq[3]==sq[5] && sq[5]==sq[7])
        return 1;
    else if(sq[1]!='1' &&sq[2]!='2' &&sq[3]!='3' &&sq[4]!='4' &&sq[5]!='5' &&sq[6]!='6' &&sq[7]!='7' &&sq[8]!='8' &&sq[9]!='9' )
        return 0;
    else 
        return -1;
}

void board(){
    cout<<"   |   |   "<<endl;
    cout<< sq[1] <<"  |"<<sq[2] <<"  |" <<sq[3] <<endl;
    cout<<"___|___|___"<<endl;

    cout<<"   |   |   "<<endl;
    cout<< sq[4] <<"  |"<<sq[5] <<"  |" <<sq[6] <<endl;
    cout<<"___|___|___"<<endl;

    cout<<"   |   |   "<<endl;
    cout<< sq[7] <<"  |"<<sq[8] <<"  |" <<sq[9] <<endl;
    cout<<"   |   |  "<<endl;
}
int main(){
    cout<<"\n PLAYER 1 == 'X and PLAYER 2 == 'O' \n\n";
    board();
    int player=1 , i ;
    char mark ,sym;
    do{
        if(player%2)
            player=1;
        else 
            player=2;

        if(player==1)
            sym='X';
        else
            sym='O';
        cout<<"player "<<player<<" Enter your mark : ";
        cin>>mark;

        // if(sq[int(mark)]==mark){
        //     if(player==1)
        //         sq[int(mark)]='X';
        //     else   
        //         sq[int(mark)]='Y';
        //     player++;
        // }

        if(mark=='1' && sq[1]==mark){
            sq[1]=sym;
            player++;
        }
        else if(mark=='2' && sq[2]==mark){
            sq[2]=sym;
            player++;
        }
        else if(mark=='3' && sq[3]==mark){
            sq[3]=sym;
            player++;
        }
        else if(mark=='4' && sq[4]==mark){
            sq[4]=sym;
            player++;
        }
        else if(mark=='5' && sq[5]==mark){
            sq[5]=sym;
            player++;
        }
        else if(mark=='6' && sq[6]==mark){
            sq[6]=sym;
            player++;
        }
        else if(mark=='7' && sq[7]==mark){
            sq[7]=sym;
            player++;
        }
        else if(mark=='8' && sq[8]==mark){
            sq[8]=sym;
            player++;
        }
        else if(mark=='9' && sq[9]==mark){
            sq[9]=sym;
            player++;
        }  
        else{
            cout<<"Invalid choice \n";
            continue;
        }
        i=win();
        board();
        if(i==1){
            cout<<"Player "<<--player<<" Wins\n";
        }
    }while(i==-1);

    if(i==0)
        cout<<"Match Tie\n";
    
    return 0;
}

