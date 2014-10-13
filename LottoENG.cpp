#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

double Money = 20;
int first=0,second=0,third=0,fourth=0,fifth=0;
int NUMBERS[5][6]; // Storing the numbers
int GAME = 0; // indicates the game rounds

int Order(int *str){//********************************************************** arranges the lotto numbers
	int i, j, temp;
	for (i = 0; i < 6; i++) {
	   for (j = 0; j < 5; j++)	{
	     if (str[j] >str[j+1]) {
	       temp = str[j+1];
	       str[j+1] = str[j];
	       str[j] = temp;
		 }
	   }
	}
	cout<<endl;
	return *str;
}
//********************************************************************************** result
void Result(int *str1, int *str2){
	int count= 0;
	int bonus = 0;
	cout<<"Winning Numbers: ";
	for(int i = 0;i<6;i++){
		for(int j = 0;j<6;j++){
			if(str1[i] == str2[j]){
				cout<<str1[i]<<" ";
				count++;
			}
		}
	}
	if(count != 0)
		cout<<endl;
	for(int k = 0;k<6;k++)
		if(str2[6] == str1[k])
			bonus++;
	if(count == 0)
		cout<<"nothing.. maybe next time!"<<endl;
	//else if(count == 1)
		//cout<<"1개나 0개나ㅋㅋㅋㅋㅋㅋㅋㅋ"<<endl;
	//else if(count == 2)
		//cout<<"꽝이라 하기에도 애매하고....5"<<endl;
	else if(count == 3){
		cout<<"5th place!!"<<endl<<"You just won $5."<<endl;
		Money += 5;
		fifth++;
	}
	else if(count == 4){
		cout<<"4th place!!!"<<endl<<"You just won $50."<<endl;	
		Money += 50;
		fourth++;
	}
	else if(count == 5 && bonus == 1){
		cout<<"Congratulations! 2nd place!!"<<endl;
		cout<<"You just won $40000."<<endl;
		Money += 40000;
		second++;
	}
	else if(count == 5){
		cout<<"Congratulations! 3rd place!"<<endl;
		cout<<"You just won $1000."<<endl;	
		Money += 1000;
		third++;
	}
	else if(count == 6){
		cout<<"Congratulations!! 1st place!!"<<endl;
		cout<<"You just won $3,000,000!!"<<endl;
		Money += 3000000;
		first++;
	}
	cout<<endl;
}
int RandNum(int *PickNumber){//********************************************************** Random number	
	int num1,num2,num3,num4,num5,num6;
	num1 = rand()%45 +1;
			PickNumber[0] = num1;
			while(1){
				num2=rand()%45 +1;
				PickNumber[1] = num2;
				if(num2 != num1)
					break;
			}
			while(1){
				num3=rand()%45 +1;
				PickNumber[2] = num3;
				if(num3 != num1 && num3 != num2)
					break;
			}
			while(1){
				num4=rand()%45 +1;
			PickNumber[3] = num4;
			if(num4 != num1 && num4 != num2 && num4 != num3)
				break;
			}
			while(1){
				num5=rand()%45 +1;
				PickNumber[4] = num5;
				if(num5 != num1 && num5 != num2 && num5 != num3 && num5 != num4)
					break;
			}
			while(1){
				num6=rand()%45 +1;
				PickNumber[5] = num6;
				if(num6 != num1 && num6 != num2 && num6 != num3 && num6 != num4 && num6 != num5)
					break;
			}
	*PickNumber = Order(PickNumber);
	return *PickNumber;
}
void ShowPick(int *str, int acc){
	cout<<"Your numbers for Round["<<acc+1<<"]: ";
	for(int i = 0;i < 6;i++)
		cout<<str[i]<<" ";
}
//**********************************************************************************************************Main Func
int main(void){
	int *Pick1 =(int*)malloc(sizeof(int)*6); // malloc for 5 games
	int *LottoNumber = (int*)malloc(sizeof(int)*7); // malloc for winning number
	int AUTO,count; // Number of AutoSelect
	srand((int)time(NULL));
	while(Money > 0){
		cout<<"----------------------------------------------------Your Money: $"<<Money<<"."<<endl;
		Money -= 5;
		cout<<"**********************Lotto**********************"<<endl;
		// printing Winning number
		*LottoNumber = RandNum(LottoNumber);
			while(1){
				LottoNumber[6]=rand()%45 +1;
				if(LottoNumber[6] != LottoNumber[0] && LottoNumber[6] != LottoNumber[1] && LottoNumber[6] != LottoNumber[2] && LottoNumber[6] != LottoNumber[3] && LottoNumber[6] != LottoNumber[4] && LottoNumber[6] != LottoNumber[5])
					break;
			}
		// cheat key;;
		//cout<<LottoNumber[0]<<" "<<LottoNumber[1]<<" "<<LottoNumber[2]<<" "<<LottoNumber[3]<<" "<<LottoNumber[4]<<" "<<LottoNumber[5]<<" "<<LottoNumber[6]<<endl;
		while(1){
			cout<<"How Many Auto Select? [1-5]: ";	cin>>AUTO;
			if(AUTO > 5 || AUTO < 0)
				cout<<"You typed the wrong number. Try again"<<endl;
			else
				break;
		}
		cout<<"You have "<<5-AUTO<<" Manual Select(s)"<<endl<<endl;
		for(int i = 1; i <= AUTO;i++){
			cout<<"Auto selecting.... "<<i<<" completed!";
			*Pick1 = RandNum(Pick1);
			for(count=0;count<6;count++)
				NUMBERS[GAME][count] = Pick1[count];
			GAME++;
		}
		cout<<"Auto select has completed."<<endl<<endl;
		cout<<"You have "<<5-AUTO<<" manual select."<<endl<<endl;
		while((5 - AUTO) != 0){
			cout<<"Choose 6 numbers between 1 and 45 (inclusive)"<<endl;
			while(1){
				cout<<"First Number: ";	cin>>NUMBERS[GAME][0];
				if(NUMBERS[GAME][0] < 1 || NUMBERS[GAME][0] > 45)
					cout<<"Choose a number between 1 and 45"<<endl;
				else if(NUMBERS[GAME][0] > 0 && NUMBERS[GAME][0] < 46)
					break;
			}
			while(1){
				cout<<"Second Number: ";	cin>>NUMBERS[GAME][1];
				if(NUMBERS[GAME][1] == NUMBERS[GAME][0]){		
					cout<<"You typed the same number as the first number."<<endl;
				}
				else{
					if (NUMBERS[GAME][1] < 1 || NUMBERS[GAME][1] > 45)
						cout << "Choose a number between 1 and 45" << endl;
					else if(NUMBERS[GAME][1] > 0 && NUMBERS[GAME][1] <46)
						break;
				}
			}
			while(1){
				cout<<"Third Number: ";	cin>>NUMBERS[GAME][2];
				if(NUMBERS[GAME][2] == NUMBERS[GAME][0]) cout<<"You typed the same number as the first number."<<endl;
				else if(NUMBERS[GAME][2] == NUMBERS[GAME][1]) cout<<"You typed the same number as the second number."<<endl;
				else {
					if (NUMBERS[GAME][2]< 1 || NUMBERS[GAME][2] > 45)
						cout << "Choose a number between 1 and 45" << endl;
					else if(NUMBERS[GAME][2] > 0 && NUMBERS[GAME][2] <46)
						break;
				}
			}
			while(1){
				cout<<"Fourth Number: ";	cin>>NUMBERS[GAME][3];
				if(NUMBERS[GAME][3] == NUMBERS[GAME][0]) cout<<"You typed the same number as the first number."<<endl;
				else if(NUMBERS[GAME][3] == NUMBERS[GAME][1]) cout<<"You typed the same number as the second number."<<endl;
				else if(NUMBERS[GAME][3] == NUMBERS[GAME][2]) cout<<"You typed the same number as the third number."<<endl;
				else{
					if (NUMBERS[GAME][3] < 1 || NUMBERS[GAME][3] > 45)
						cout << "Choose a number between 1 and 45" << endl;
					else if(NUMBERS[GAME][3] > 0 && NUMBERS[GAME][3] <46)
						break;
				}
			}
			while(1){
				cout << "Fifth Number: ";	cin >> NUMBERS[GAME][4];
				if (NUMBERS[GAME][4] == NUMBERS[GAME][0]) cout << "You typed the same number as the first number." << endl;
				else if (NUMBERS[GAME][4] == NUMBERS[GAME][1]) cout << "You typed the same number as the second number." << endl;
				else if (NUMBERS[GAME][4] == NUMBERS[GAME][2]) cout << "You typed the same number as the third number." << endl;
				else if(NUMBERS[GAME][4] == NUMBERS[GAME][3]){				cout<<"You typed the same number as the fourth number."<<endl;}
				else{
					if (NUMBERS[GAME][4] < 1 || NUMBERS[GAME][4] > 45)
						cout << "Choose a number between 1 and 45" << endl;
					else if(NUMBERS[GAME][4] > 0 && NUMBERS[GAME][4] <46)
						break;
				}
			}
			while(1){
				cout << "Sixth Number: ";	cin >> NUMBERS[GAME][5];
				if (NUMBERS[GAME][5] == NUMBERS[GAME][0]) cout << "You typed the same number as the first number." << endl;
				else if (NUMBERS[GAME][5] == NUMBERS[GAME][1]) cout << "You typed the same number as the second number." << endl;
				else if (NUMBERS[GAME][5] == NUMBERS[GAME][2]) cout << "You typed the same number as the third number." << endl;
				else if (NUMBERS[GAME][5] == NUMBERS[GAME][3]){ cout << "You typed the same number as the fourth number." << endl; }
				else if(NUMBERS[GAME][5] == NUMBERS[GAME][4]){				cout<<"You typed the same number as the fifth number."<<endl;}
				else{
					if (NUMBERS[GAME][5] < 1 || NUMBERS[GAME][5] > 45)
						cout << "Choose a number between 1 and 45" << endl;
					else if(NUMBERS[GAME][5] > 0 && NUMBERS[GAME][5] <46)
						break;
				}
			}
			GAME++;AUTO++;
		}
		GAME=0;cout<<endl;;
		while(GAME != 5){//******* Printing Lotto Numbers
		ShowPick(NUMBERS[GAME],GAME);GAME++;cout<<endl;}
		
			cout<<"Winning Numbers are: ";
			for(int i = 0;i < 7;i++){
				if(i == 6)
					cout<<", and bonus number is: "<<LottoNumber[i]<<endl<<endl;
				else
					cout<<LottoNumber[i]<<" ";
			}
			GAME=0;
			while(GAME <= 4){
				cout<<"Result of Game \#"<<GAME+1<<"!!"<<endl;
				Result(NUMBERS[GAME],LottoNumber);
				GAME++;
			}
			if(Money == 0){
				cout<<"You ran out of cash please deposit."<<endl<<"1. Deposit"<<endl<<"2. Exit"<<endl<<"=>";
				cin>>count;
				if(count == 1){
					cout<<"You deposited $5."<<endl;
					Money += 5;
				}
			}
			cout<<"programmed by Chang-Seop Chris Lee"<<endl<<"2012.04.01"<<endl;
	}		
	free(LottoNumber);
	free(Pick1);
	return 0;
}