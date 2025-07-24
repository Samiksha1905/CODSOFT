#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

int main(){
    int lower,upper,n,guess,count=0,flag=0;
    int Total_chances;

    cout<<"Enter Lower bound: "<<endl;
    cin>>lower;
    cout<<"Enter Upper bound: "<<endl;
    cin>>upper;

    srand(time(0));

    n=(rand() % (upper - lower + 1)) + lower;
    Total_chances= (int)round(log(upper - lower + 1) / log(2));
    cout<<"You've only " <<Total_chances<<" chances to guess the number.\n"<<endl;

    do{
    cout<<"Guess a number: "<<endl;
    cin>>guess;
    count++;
    if(n<guess)
    cout<<"Too High! Try again.\n";
    else if(n>guess)
    cout<<"Too Low! Try again.\n";
    else{
    cout<<"HURRAY! YOU GUESSED IT CORRECTLY\n";
    flag=1;
    break;
    }
}
while(count<Total_chances);


    if(!flag){
    cout<<"The number is: "<<n<<endl;
    cout<<"BETTER LUCK NEXT TIME!"<<endl;
}
    return 0;


}
