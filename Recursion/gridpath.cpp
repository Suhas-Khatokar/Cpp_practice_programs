#include<iostream>
#include<vector>
using namespace std;


int paths(int m, int n, vector <vector<int>> &maze, int i, int j) {
    //Top left to bottom right, can only go down or right, total no of paths = paths
    //[1, 1, 1] m=2, n=3
    //[1, 1, 1]

    if (i==m && j==n) ;

    paths(m, n, maze, i+1, j);
    paths (m, n, maze, i, j+1);
    paths (m, n, maze, i+1, j+1);


}
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> maze(m, vector<int> (n, 1));
    for (int i=0; i<maze.size(); i++) {
        for (int j=0; j<maze[i].size(); j++) {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    //paths(m, n, maze, 0, 0, 0);
    
    return 0;
}