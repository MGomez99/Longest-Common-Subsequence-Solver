/*
Recursive Approach
*/

#include "fileparse.h"

//Returns the length of the longest common subsequence recursively
int LCS(string x, string y){
    /*
    * x_char and y_char are the # of characters we are considering within the respective string
    */ 
    //Case 1 (Case Case): considering 0 characters (when length of substr is 0)


    
    if (x.length() == 0 || y.length()== 0){
        return 0;
    }
    //Case 2: If the last characters agree, we add 1 to the running counter and recurse
    if (x[x.length()-1] == y[y.length()-1])
    {
        int retval = 1 + LCS(x.substr(0, x.length()-1), y.substr(0, y.length()-1));

        return retval;
    }
    //Case 2: If the last characters don't agree, we return the greater of the two possibilities (throwing the last character away from one string)
    int retval = max(LCS(x.substr(0, x.length()-1), y), LCS(x, y.substr(0, y.length()-1)));

    return retval;
}
int main(int argc, char** argv){
    string fx = FILE1;
    string fy = FILE2;
    string fo = "output2.txt";
    if(argc == 4){
        fx = argv[1];
        fy = argv[2];
        fo = argv[3];
    }
    else{
        cout << "No input files or output file named. \nDefaulting input to filex.txt and filey.txt and output to output2.txt."<<endl;
    }
    string x = getInput(fx);
    string y = getInput(fy);


    //compute LCS and time it
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    int LCS_Length = LCS(x, y);
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::nanoseconds time_taken = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    string timed = to_string(time_taken.count())+ " nanoseconds";

    //Write to file
    ofstream fp;
    fp.open(fo);
    fp << LCS_Length<<endl;
    fp << timed << endl;
    fp.close();
}