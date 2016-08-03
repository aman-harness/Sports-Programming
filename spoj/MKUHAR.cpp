#include <bits/stdc++.h>

using namespace std;

typedef struct{
	int X; // Ingredient needed for a serving. 
	int Y; // Amount available
	int SM; // Size of smaller package
	int PM; // price of smaller package
	int SV; // Size of larger package
	int PV; // price of larger package
} str;
str details[100];
int m,n;
int maxi;

int calc(int ser, int index){
	// cout << ser << " " << index << endl;
	int value = 0;
	if(details[index].Y > (ser * details[index].X))
		return 0;
	else{

		int amt_r = (ser * details[index].X) - details[index].Y;
		int mini = INT_MAX;
		
		int packets;

		if(amt_r % details[index].SM != 0) packets =  amt_r / details[index].SM + 1;
		else packets =  amt_r / details[index].SM;

		mini = min(mini, packets * details[index].PM);

		if(amt_r % details[index].SV != 0) packets =  amt_r / details[index].SV + 1;
		else packets =  amt_r / details[index].SV;

		int temp = amt_r - details[index].SV;
		int amt = 0;
		for(int i = 1; i < packets; i++){
			temp = amt_r - i * details[index].SV;
			amt += (i) * details[index].PV;

			int as;
			if(temp % details[index].SM != 0) as =  temp / details[index].SM + 1;
			else as =  temp / details[index].SM;

			amt += as * details[index].PM;

			mini = min(mini, amt);
			amt = 0;

		}
		mini = min(mini, packets * details[index].PV);

		packets = amt_r / details[index].SV;
		temp = packets * details[index].PV;

		amt_r -= details[index].SV * packets;
		if(amt_r % details[index].SM != 0) packets =  amt_r / details[index].SM + 1;
		else packets =  amt_r / details[index].SM;

		temp += packets * details[index].PM;
		mini = min(mini, temp);

		return mini;
	} 
}
int Floor(int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( calc(m, 0) <= key )
            l = m;
        else
            r = m;
    }
 
    return l;
}
 

int main(){
	// ifstream cin("input.txt");
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> details[i].X >> details[i].Y >> details[i].SM >> details[i].PM >> details[i].SV >> details[i].PV;
	
	int low = 0;
	int high = Floor(0, 100000, m) + 1;
	// cout << "High - " << high <<endl;
	int temp;
	int med;
	int r = high;
	int l = 0;
	while( r - l > 1 )
	{	
	    med = l + (r - l)/2;
	    int dec = 1;
	    temp = m;
	    for(int i = 0 ; i < n; i++){
	    	int xx = calc(med, i);
	    	if(xx > temp) {
	    		dec = 0;
	    		break;
	    	}
	    	temp -= xx;
	    }
	    // cout << "Med: " << med << " Dec: " << dec<< endl;
	    if(dec)
	        l = med;
	    else
	        r = med;
	}
	cout << l << endl;
	return 0;
}