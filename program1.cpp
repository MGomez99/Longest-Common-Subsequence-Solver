/*
Bottom-Up DP Approach
*/
#include "fileparse.h"
#include <vector>
vector<vector<int>> table; 


int LCS(string x, string y){
    for(int i = 0; i <= x.length(); i++){
        for(int j = 0; j <= y.length(); j++){
            //Base Case
            if(i == 0 || j == 0){
                table[i][j] = 0;
            }
            //Same Character Case
            else if(x[i] == y[j]){
                table[i][j] = table[i-1][j-1]+1;
            }
            //Differring character case
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[x.length()][y.length()];
}

int main(int argc, char** argv){
    //Get input strings
    string fx = FILE1;
    string fy = FILE2;
    string fo = "output1.txt";
    if(argc == 4){
        fx = argv[1];
        fy = argv[2];
        fo = argv[3];
    }
    else{
        cout << "No input files or output file named. \nDefaulting input to filex.txt and filey.txt and output to output1.txt."<<endl;
    }
    string x = getInput(fx);
    string y = getInput(fy);
    cout << "String x: " << x << "\t Length: "<<x.length()<<endl; //@TODO remove
    cout << "String y: " << y << "\t Length: "<<y.length()<<endl;
    //Set up table
    vector<int> row(y.length()+1, -1);
    row[0] = 0;
    vector<vector<int>> matrix(x.length()+1, row);
    vector<int> row1(y.length()+1, 0);
    matrix[0] = row1;
    table = matrix;    
    //compute LCS and time it
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    int LCS_Length = LCS(x, y);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::nanoseconds time_taken = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    string timed = to_string(time_taken.count())+ " nanoseconds";
    
    //Write to file
    ofstream fp;
    fp.open(fo);
    if(x.length() <= 10 && y.length() <= 10){
        for(int i = 0; i < table.size(); i++){
            string line;
            for(int j = 0; j< y.length(); j++){
                if(j != y.length()-1) line.append(to_string(table[i][j]) + " ");
                else line.append(to_string(table[i][j]));
            }
            fp << line << endl;
        }
    }
    fp << LCS_Length<<endl;
    fp << timed << endl;
    fp.close();
}