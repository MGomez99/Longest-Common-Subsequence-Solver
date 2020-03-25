/*
Top-Down DP Approach with memoization
*/
#include "fileparse.h"
#include <vector>
vector<vector<int>> table; 

int LCS(string x, string y, int x_char, int y_char){
    
    //x_char and y_char are the # of characters we are considering within the respective string
    // In all cases we save the result
    
   
    //Case 1 (Case Case): considering 0 characters (when length of substr is 0)
    if (x_char == 0 || y_char == 0){

        table[x_char][y_char] = 0; //shouldn't need to do this if the table is set up properly
        return 0;
    }

    //Check if solution has been previously solved
    if(table[x_char][y_char] != -1){
        return table[x_char][y_char];
    }
    //Case 2: If the last characters agree, we add 1 to the running counter and recurse
    if (x[x_char-1] == y[y_char-1])
    {
        
        table[x_char][y_char] =  1 + LCS(x, y, x_char -1, y_char-1);
        

    }
    //Case 2: If the last characters don't agree, we return the greater of the two possibilities (throwing the last character away from one string)
    else{
        
        table[x_char][y_char] = max(LCS(x, y, x_char-1, y_char), LCS(x, y, x_char, y_char-1));
    }

    return table[x_char][y_char];
 
}
int main(int argc, char** argv){
    string fx = FILE1;
    string fy = FILE2;
    string fo = "output3.txt";
    if(argc == 4){
        fx = argv[1];
        fy = argv[2];
        fo = argv[3];
    }
    else{
        cout << "No input files or output file named. \nDefaulting input to filex.txt and filey.txt and output to output1.txt."<<endl;
    }
    // Get input strings
    string x = getInput(fx);
    string y = getInput(fy);
    //cout << "String x: " << x << "\t Length: "<<x.length()<<endl; //@TODO remove
    //cout << "String y: " << y << "\t Length: "<<y.length()<<endl;
    //Set up table
    vector<int> row(y.length()+1, -1);
    row[0] = 0;
    vector<vector<int>> matrix(x.length()+1, row);
    vector<int> row1(y.length()+1, 0);
    matrix[0] = row1;
    table = matrix;    
    //Compute LCS
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    int LCS_Length = LCS(x, y, x.length(), y.length());

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::nanoseconds time_taken = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    string timed = to_string(time_taken.count())+ " nanoseconds";

    ofstream fp;
    fp.open(fo);
    //Write to file
    fp << LCS_Length<<endl;
    fp << timed << endl;
    fp.close();
}