1) "make all" will compile all programs into executables called "programX" on linux and "programX.exe" on windows.
2) "make run" will compiile and run ALL 3 PROGRAMS -one after the other- using "filex.txt" & "filey.txt" as input and "outputX.txt" as outputX
3) when compiling the program, if no input and output is specified then the program defaults to the aforementioned files
4) all programs used vectors (at maximum), strings, and the chrono library to time the runtime of the functions
LCS(string x, string y) computes the length of the longest common subsequence). Main calls this function on two input strings that are read from the input files using the getInput function found in the header file
5) run file with ./program1 inputfile1.txt inputfile2.txt outputfile.txt