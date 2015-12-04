#include <iostream>
#include <algorithm>
#include <cstring>

#typedef vector<vector<int>> pos;

using namespace std;

//Place 8 Queens on board such that no queen attacks the other
class 8Queen{
	public:
		int numQueens, boardLen, boardWid;

		8Queen(int n, int l, int w){
			this->numQueens = n;
			this->boardLen = l;
			this->boardWid = w;
		}

		bool checkAttack(int x, int y, pos p, int size){
			for(int i = 0; i < size; i++){
				if(i == p[i][0] || j == p[i][1] || abs(i - p[i][0]) == abs(j - p[i][1])){
					return true;
				}
			}
			return false;
		}

		bool placeQueen(int last, pos *p){
			if(last == this->numQueens){return true;}
			for (int i = 0; i < this->boardLen; i++){
				bool found = false;
				for (int j = 0; j < this->boardWid; j++){
					if(last > 0){
						if(checkAttack(i, j, p, last)){continue;}
					}
					*p->at(last).at(0) = i;
					*p->at(last).at(1) = j;
					if(placeQueen(last+1, p)){
						return true;
					}
				}
			}
			return false;
		}
};

//Detect cycle in graph
class Graph{
	public:
		pos conn; //vector<vector<int>>
		int last = 0; //Last added element to conn
		int size; //Number of edges

		GraphArray(int n){
			this->conn.resize(n);
			this->size = n;
			for (std::vector<vector<int>>::iterator i = this->conn.begin(); i != this->conn.end(); ++i){
				i->resize(2);
			}
		}

		void resize(int n){
			if(this->size == n){return;}
			this->conn.resize(n);
			this->size = n;
			for (std::vector<vector<int>>::iterator i = this->conn.begin(); i != this->conn.end(); ++i){
				i->resize(2);
			}
		}

		void addConn(int a, int b){
			this->conn[this->last][0] = a;
			this->conn[this->last][1] = b;
			this->last++;
			//For ndirected graphs
			this->conn[this->last][0] = b;
			this->conn[this->last][1] = a;
			this->last++;
		}

		bool isCyclic(){
			bool visited[this->size];
			memset(visited, false, sizeof(visited));
			for(int i = 0; i < this->size; i++){
				if(checkCycle(i, visited, -1)){return true;}
			}
			return false;
		}

		bool checkCycle(int n, bool visited[], int p){
			visited[n] = true;
			for (pos::iterator iter = this->conn.begin(); iter != this->conn.end(); ++iter){
				if(!visited[iter->at(0)]){
					if(checkCycle(iter->at(0), visited, n)){return true;}
				}
				else if(!visited[iter->at(1)]){
					if(checkCycle(iter->at(1), visited, n)){return true;}
				}
				else if(iter->at(0) != p || iter->at(1) != p){return true;}
			}
			return false;
		}
};
