//txt to txt Parsing program
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    string current_line ,previous_line="";//two strings declared.
    ifstream infile;// function for input file
    ofstream outfile;//function for output file
    infile.open ("input.txt");//open input file
    outfile.open ("output.txt");//open output file
    while(!infile.eof())//loop while reaching end of the file
    {
        getline(infile,current_line);//getting the data line by line in string
        if (current_line != previous_line)// checking for repeatation of line
        {
            previous_line=current_line;//assigning current line to previous line            
            if(current_line[0]==' ' && current_line[1]==' ' && current_line[6]=='.')//checking the 0's, 1st, 7th place char of string
			{
                if (current_line.size() > 7)//checking for size of string
				{
					current_line.erase(current_line.begin(), (current_line.begin() + 8));//removing first 7 char of string
					int size = current_line.size(), i;//two integers: size of string, loop
					for (i = 0; i <= size; i++)//loop until end of string
					{
						int o = 1+i;
						if(current_line[i] == ' ' && current_line[i] == current_line[o])//checking two spaces together
						{
							current_line.erase(current_line.begin() + i);//removing one space if two spaces together
						}
					}
                    outfile<<current_line;// writing data into output file line by line
                    if (i<80)//for checking length of line less then 80 characters
                    {
						outfile<<endl;//if yes go to next line
					}
					else
					{
						outfile<<" !!! Length Exceed !!!"<<endl;//if no write and go to next line
					}
				}
			}	
		}
	}
	outfile.close();//closing the output file
    infile.close();//closing th input file
    return 0;
}
