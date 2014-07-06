#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    string current_line ,previous_line="";
    ifstream infile;
    ofstream outfile;
    infile.open ("abs.txt");
    outfile.open ("out.txt");
    while(!infile.eof())
    {
        getline(infile,current_line);
        if (current_line != previous_line)
        {
            previous_line=current_line;            
			int size = current_line.size(), i;
			for (i = 0; i <= size; i++)
			{
				int o = 1+i;
				if(current_line[i] == ' ' && current_line[i] == current_line[o])
				{
					current_line.erase(current_line.begin() + i);
					i--;
				}
			}
            outfile<<current_line;
            if (i<80)
            {
				outfile<<endl;
			}
			else
			{
				outfile<<" !!! Length Exceed !!!"<<endl;
			}
		}
	}
	outfile.close();
    infile.close();
    return 0;
}
