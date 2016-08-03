#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

#include <cstdio>
#include <queue>



struct pos {
    int x;
    int y;
};

int xx, yy;
const int N = 8;

bool check( int x, int y, bool visited[][ 9 ], int cost[][ 9 ] ) {
    if ( x < 0 || x >= N ) return false;
    if ( y < 0 || y >= N ) return false;
    if ( cost[ xx ][ yy ] + ( ( xx * x ) + ( yy * y ) ) >= cost[ x ][ y ] ) return false;
    return true;
}

void bfs( int a, int b, int c, int d ) {
    bool visited[ 9 ][ 9 ];
    int cost[ 9 ][ 9 ], i, j;
    queue< pos > q;
    q.push( ( pos ) { a, b } );
    for ( i = 0; i <= 8; ++i ) {
        for ( j = 0; j <= 8; ++j ) {
            cost[ i ][ j ] = 100000000;
            visited[ i ][ j ] = false;
        }
    }
    cost[ a ][ b ] = 0;

    while ( !q.empty() ) {
        pos p = q.front();
        q.pop();
        xx = p.x;
        yy = p.y;
        visited[ xx ][ yy ] = true;
        if ( check( xx - 1, yy + 2, visited, cost ) ) {
            q.push( ( pos ) { xx - 1, yy + 2 } );
            cost[ xx - 1 ][ yy + 2 ] = cost[ xx ][ yy ] + xx * ( xx - 1 ) + yy * ( yy + 2 );
        }
        if ( check( xx + 1, yy + 2, visited, cost ) ) {
            q.push( ( pos ) { xx + 1, yy + 2 } );
            cost[ xx + 1 ][ yy + 2 ] = cost[ xx ][ yy ] + xx * ( xx + 1 ) + yy * ( yy + 2 );
        }
        if ( check( xx - 1, yy - 2, visited, cost ) ) {
            q.push( ( pos ) { xx - 1, yy - 2 } );
            cost[ xx - 1 ][ yy - 2 ] = cost[ xx ][ yy ] + xx * ( xx - 1 ) + yy * ( yy - 2 );
        }
        if ( check( xx + 1, yy - 2, visited, cost ) ) {
            q.push( ( pos ) { xx + 1, yy - 2 } );
            cost[ xx + 1 ][ yy - 2 ] = cost[ xx ][ yy ] + xx * ( xx + 1 ) + yy * ( yy - 2 );
        }
        if ( check( xx - 2, yy + 1, visited, cost ) ) {
            q.push( ( pos ) { xx - 2, yy + 1 } );
            cost[ xx - 2 ][ yy + 1 ] = cost[ xx ][ yy ] + xx * ( xx - 2 ) + yy * ( yy + 1 );
        }
        if ( check( xx + 2, yy + 1, visited, cost ) ) {
            q.push( ( pos ) { xx + 2, yy + 1 } );
            cost[ xx + 2 ][ yy + 1 ] = cost[ xx ][ yy ] + xx * ( xx + 2 ) + yy * ( yy + 1 );
        }
        if ( check( xx - 2, yy - 1, visited, cost ) ) {
            q.push( ( pos ) { xx - 2, yy - 1 } );
            cost[ xx - 2 ][ yy - 1 ] = cost[ xx ][ yy ] + xx * ( xx - 2 ) + yy * ( yy - 1 );
        }
        if ( check( xx + 2, yy - 1, visited, cost ) ) {
            q.push( ( pos ) { xx + 2, yy - 1 } );
            cost[ xx + 2 ][ yy - 1 ] = cost[ xx ][ yy ] + xx * ( xx + 2 ) + yy * ( yy - 1 );
        }
    }
    if ( !visited[ c ][ d ] ) {
        printf( "-1\n" );
        return;
    }
    printf( "%d\n", cost[ c ][ d ] );
}

int main() {
    int a, b, c, d;

    while ( scanf( "%d", &a ) != EOF ) {
        scanf( "%d%d%d", &b, &c, &d );
        bfs( a, b, c, d );
    }   

    return 0;
}

// int bfs(int a, int b, int c, int d){
// 	// cout << "Function Called\n";
// 	int temp;
// 	pair<int, int> start_vertex = make_pair(a, b);
// 	map<pair<int, int>, bool> V;
// 	queue<pair<int, int> > Q;
// 	Q.push(start_vertex); 
// 	V[start_vertex] = true;
// 	map<pair<int, int>, int> cost;
// 	for(int i = 0  ;i < 8; i++)
// 		for(int j = 0 ;j < 8; j++)
// 			cost[make_pair(i, j)] = 100000000;

// 	cost[make_pair(a,b)] = 0;
// 	while(!Q.empty()) { 
//         pii i = Q.front();
//         // cout << i.fi << " " << i.se << endl;
//         // if(i == make_pair(2, 0)) cout  << "---"<< cost[make_pair(2, 0)] << endl;
//         // get the tail element from queue
//         Q.pop(); 


//         temp = i.fi * (i.fi + 2) + i.se * (i.se + 1);
//         if(!V[make_pair(i.fi + 2, i.se +1)]){
//         	if(i.fi + 2 < 0 || i.se + 1 < 0 || i.fi + 2 > 7 || i.se + 1 > 7);
//         	else{
//         	V[make_pair(i.fi + 2, i.se +1)] = true; 
//         	Q.push(make_pair(i.fi + 2, i.se +1));
//         	cost[make_pair(i.fi + 2, i.se +1)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi + 2 < 0 || i.se + 1 < 0 || i.fi + 2 > 7 || i.se + 1 > 7);
//         	else{
//         	cost[make_pair(i.fi + 2, i.se +1)] =min(cost[i] + temp, cost[make_pair(i.fi + 2, i.se +1)]);}
//         }

//         temp = i.fi * (i.fi - 2) + i.se * (i.se + 1);
//         if(!V[make_pair(i.fi - 2, i.se +1)]){
//         	if(i.fi - 2 < 0 || i.se + 1 < 0 || i.fi - 2 > 7 || i.se + 1 > 7);
//         	else{
//         	V[make_pair(i.fi - 2, i.se +1)] = true; 
//         	Q.push(make_pair(i.fi - 2, i.se +1));
//         	cost[make_pair(i.fi - 2, i.se +1)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi - 2 < 0 || i.se + 1 < 0 || i.fi - 2 > 7 || i.se + 1 > 7);
//         	else{
//         	cost[make_pair(i.fi - 2, i.se +1)] =min(cost[i] + temp, cost[make_pair(i.fi - 2, i.se +1)]);}
//         }


//         temp = i.fi * (i.fi - 2) + i.se * (i.se - 1);
//         if(!V[make_pair(i.fi - 2, i.se - 1)]){
//         	if(i.fi - 2 < 0 || i.se - 1 < 0 || i.fi - 2 > 7 || i.se - 1 > 7);
//         	else{
//         	V[make_pair(i.fi - 2, i.se - 1)] = true; 
//         	Q.push(make_pair(i.fi - 2, i.se - 1));
//         	cost[make_pair(i.fi - 2, i.se -1)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi - 2 < 0 || i.se - 1 < 0 || i.fi - 2 > 7 || i.se - 1 > 7);
//         	else{
//         	cost[make_pair(i.fi - 2, i.se -1)] =min(cost[i] + temp, cost[make_pair(i.fi - 2, i.se -1)]);}
//         }

//         temp = i.fi * (i.fi + 2) + i.se * (i.se - 1);
//         if(!V[make_pair(i.fi + 2, i.se -1)]){
//         	if(i.fi + 2 < 0 || i.se - 1 < 0 || i.fi + 2 > 7 || i.se - 1 > 7);
//         	else{
//         	V[make_pair(i.fi + 2, i.se -1)] = true; 
//         	Q.push(make_pair(i.fi + 2, i.se -1));
//         	cost[make_pair(i.fi + 2, i.se -1)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi + 2 < 0 || i.se - 1 < 0 || i.fi + 2 > 7 || i.se - 1 > 7);
//         	else{
//         	cost[make_pair(i.fi + 2, i.se -1)] =min(cost[i] + temp, cost[make_pair(i.fi + 2, i.se -1)]);}
//         }

//         ////////////////////////////////


//         temp = i.fi * (i.fi + 1) + i.se * (i.se + 2);
//         if(!V[make_pair(i.fi + 1, i.se +2)]){
//         	if(i.fi + 1 < 0 || i.se + 2 < 0 || i.fi + 1 > 7 || i.se + 2 > 7);
//         	else{
//         	V[make_pair(i.fi + 1, i.se +2)] = true; 
//         	Q.push(make_pair(i.fi + 1, i.se +2));
//         	cost[make_pair(i.fi + 1, i.se +2)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi + 1 < 0 || i.se + 2 < 0 || i.fi + 1 > 7 || i.se + 2 > 7);
//         	else{
//         	cost[make_pair(i.fi + 1, i.se +2)] =min(cost[i] + temp, cost[make_pair(i.fi + 1, i.se +2)]);}
//         }

//         temp = i.fi * (i.fi - 1) + i.se * (i.se + 2);
//         if(!V[make_pair(i.fi - 1, i.se +2)]){
//         	if(i.fi - 1 < 0 || i.se + 2 < 0 || i.fi - 1 > 7 || i.se + 2 > 7);
//         	else{
//         	V[make_pair(i.fi - 1, i.se +2)] = true; 
//         	Q.push(make_pair(i.fi - 1, i.se +2));
//         	cost[make_pair(i.fi - 1, i.se +2)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi - 1 < 0 || i.se + 2 < 0 || i.fi - 1 > 7 || i.se + 2 > 7);
//         	else{
//         	cost[make_pair(i.fi - 1, i.se +2)] =min(cost[i] + temp, cost[make_pair(i.fi - 1, i.se +2)]);}
//         }


//         temp = i.fi * (i.fi - 1) + i.se * (i.se - 2);
//         if(!V[make_pair(i.fi - 1, i.se - 2)]){
//         	if(i.fi - 1 < 0 || i.se - 2 < 0 || i.fi - 1 > 7 || i.se - 2 > 7);
//         	else{
//         	V[make_pair(i.fi - 1, i.se - 2)] = true; 
//         	Q.push(make_pair(i.fi - 1, i.se - 2));
//         	cost[make_pair(i.fi - 1, i.se -2)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi - 1 < 0 || i.se - 2 < 0 || i.fi - 1 > 7 || i.se - 2 > 7);
//         	else{
//         	cost[make_pair(i.fi - 1, i.se -2)] =min(cost[i] + temp, cost[make_pair(i.fi - 1, i.se -2)]);}
//         }

//         temp = i.fi * (i.fi + 1) + i.se * (i.se - 2);
//         if(!V[make_pair(i.fi + 1, i.se -2)]){
//         	if(i.fi + 1 < 0 || i.se - 2 < 0 || i.fi + 1 > 7 || i.se - 2 > 7);
//         	else{
//         	V[make_pair(i.fi + 1, i.se -2)] = true; 
//         	Q.push(make_pair(i.fi + 1, i.se -2));
//         	cost[make_pair(i.fi + 1, i.se -2)] = temp + cost[i];}

//         }
//         else{
//         	if(i.fi + 1 < 0 || i.se - 2 < 0 || i.fi + 1 > 7 || i.se - 2 > 7);
//         	else{
//         	cost[make_pair(i.fi + 1, i.se -2)] =min(cost[i] + temp, cost[make_pair(i.fi + 1, i.se -2)]);}
//         }

//     } 
//     return cost[make_pair(c, d)];
// }

// int main(){
// 	int a, b, c, d;

// 		while ( scanf( "%d", &a ) != EOF ) {
// 			scanf( "%d%d%d", &b, &c, &d );
// 			cout << bfs( a, b, c, d ) << endl;
// 		}	
// }