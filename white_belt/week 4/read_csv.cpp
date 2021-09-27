#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	ifstream in("input.txt");
	int m, n;
	int num;

	if (in){
		in >> m >> n;
		for (int i=0; i<m; i++)
		{

			for(int j=0; j<n; j++)
			{
				// getline(in, num, ',');
				in >> num;
				in.ignore(1);

				string cell_delim = (j == n-1)?"":" ";
				cout << setw(10) << right << num << cell_delim;
			}
			if (i<m-1)
				cout << endl;
		}
	}
	return 0;
}