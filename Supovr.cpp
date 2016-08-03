#include <bits/stdc++.h>

using namespace std;

int runn[3];
int valid_balls = 0;
int wickets = 0;
char run;
int curr_b = 0;
int out = 3;
int main(){
	while(valid_balls < 6 && wickets < 2){
		// cout << valid_balls << " " << wickets <<endl;
		cin >> run;
		if(run == 'O'){
			wickets++;
			out = curr_b;
			curr_b = 2;
			valid_balls++;
		}
		else if(run == 'W' || run == 'N'){
			continue;
		}
		else{
			valid_balls++;	
			int runi = run - '0';
			runn[curr_b] += runi;
			if(run % 2){
				if(curr_b==0 && wickets ==0) curr_b = 1;
				else if(curr_b == 1 &&  wickets == 0) curr_b = 0;
				else if(curr_b == 0 && wickets == 1) curr_b = 2;
				else if(curr_b == 1 && wickets == 1) curr_b = 2;
				else if(curr_b == 2 && wickets == 1 && out == 1) curr_b = 0;
				else if(curr_b == 2 && wickets == 1 && out == 0) curr_b = 1;
			}
		}
	}
	cout  << runn[0] << endl << runn[1] << endl << runn[2] << endl;
	return 0;
}