#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

string fizzbuzz(string inp){
	int n = stoi(inp);
	stringstream ss;
	for(int i = 1; i <= n; i++){
		if(i%15 == 0){ss << "FizzBuzz" << endl;}
		else if(i%5 == 0){ss << "Buzz" << endl;}
		else if(i%3 == 0){ss << "Fizz" << endl;}
		else{ss << i << endl;}
	}
}

struct Point{int x; int y;};

int dist(struct Point p1, struct Point p2){
	int x = (p1.x > p2.x) ? (p1.x - p2.x) : (p2.x - p1.x);
	int y = (p1.y > p2.y) ? (p1.y - p2.y) : (p2.y - p1.y);
	return (int) sqrt((x*x) + (y*y));
}

int overlap(string inp){
	//int sz = inp.size(), currIdx = 0;
	struct Point coords[8];
	strinstream ss;
	ss << inp;
	char c;
	ss >> c >> coords[0].x >> c >> coords[0].y >> c >> std::ws >> c >> coords[1].x >> c >> coords[1].y >> c >> std::ws >> c >> coords[2].x >> c >> coords[2].y >> c >> std::ws >> c >> coords[3].x >> c >> coords[3].y >> c >> std::ws >> c >> coords[4].x >> c >> coords[4].y >> c >> std::ws >> c >> coords[5].x >> c >> coords[5].y >> c >> std::ws >> c >> coords[6].x >> c >> coords[6].y >> c >> std::ws >> c >> coords[7].x >> c >> coords[7].y;
	struct Point inter[4];
	inter[0].x = max(coords[0].x, coords[4].x);
	inter[0].y = max(coords[0].y, coords[4].y);//max(coords[3].y, min(coords[0].y, coords[4].y));
	inter[2].x = max(coords[2].x, coords[6].x);
	inter[2].y = max(coords[2].y, coords[6].y);
	inter[1].x = max(coords[1].x, coords[5].x);
	inter[1].y = inter[0].y;
	inter[3].x = max(coords[3].x, coords[7].x);
	inter[3].y = inter[2].y;
	//return dist(inter[0], inter[1]) * dist(inter[1], inter[3]);
	int xx = max(0, min(inter[1].x, inter[3].x) - max(inter[2].x, inter[0].x));
	int yy = max(0, min(inter[1].y, inter[3].y) - max(inter[2].y, inter[0].y));
	//cout << xx << " " << yy;
	return xx*yy;
}

int modulo(string inp){
	int a, b, c, d, e = 1;
	stringstream ss;
	ss << inp;
	char ch;
	ss >> a >> ch >> std::ws >> b >> std::ws >> c;
	d = b%(c-1);
	while(d > 0){
		e *= a; d--;
	}
	return e%c;
}

int main(){
	int type;
	cin >> type;
	string inp;
	getline(cin, inp);
	switch(type){
		case 1:
			cout << fizzbuzz(inp);
			break;
		case 2:
			cout << overlap(inp);
			break;
		case 3:
			cout << modulo(inp);
			break;
	}
	return 0;
}
