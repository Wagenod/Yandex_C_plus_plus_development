#include <iostream> 
#include <vector>
#include <iomanip>
#include <exception>

using namespace std;

class Matrix{
	
	
	public:
		Matrix(){
			m = {};
		}

		Matrix(const int num_rows, const int num_cols){
			Reset(num_rows, num_cols);
		}

		int GetNumRows() const{
			return m.size();
		}

		int GetNumColumns() const{
			return (m.size() > 0)? m[0].size():0;
		}

		vector<vector<int>> getValues() const{
			return m;
		}

		int At(const int rowIdx, const int columnIdx) const{
			if (rowIdx < 0 || columnIdx < 0 || rowIdx >= GetNumRows() || columnIdx >= GetNumColumns())
				throw out_of_range("Out of range!");
			return m[rowIdx][columnIdx];
		}

		bool isEmpty() const{
			if (GetNumRows()*GetNumColumns() == 0)
				return true;
			return false;
		}

		bool hasEqualShapeTo(const Matrix& another_matr) const{
			if (GetNumRows() == another_matr.GetNumRows() && GetNumColumns() == another_matr.GetNumColumns())
				return true;
			return false;
		}

		int& At(const int rowIdx, const int columnIdx) {
			//cout << "in At&" << endl;
			if (rowIdx < 0 || columnIdx < 0 || rowIdx >= GetNumRows() || columnIdx >= GetNumColumns())
				throw out_of_range("Out of range!");
			return m[rowIdx][columnIdx];
		}

		void Reset(const int newNumRows, const int newNumCols){
			if (newNumCols < 0 || newNumRows < 0)
				throw out_of_range("Out of range!");
			vector<int> row(newNumCols, 0);
			m.assign(newNumRows, row);
		}

	private:
		vector<vector<int>> m;
};


ostream& operator<< (ostream& stream, const Matrix& matr){
	stream << matr.GetNumRows() << " " << matr.GetNumColumns() << endl;
	for (const auto& row: matr.getValues()){
		for (int item: row)
			stream << item << " ";
		stream << endl;
	}
	return stream;
}

istream& operator>> (istream& stream, Matrix& matr){
	int numRows, numCols;
	stream >> numRows >> numCols;
	matr.Reset(numRows, numCols);
	for (int i=0; i<numRows; i++)
		for (int j=0; j<numCols; j++)
			stream >> matr.At(i, j);
	return stream;
}

bool operator== (const Matrix& matr1, const Matrix& matr2){
	if (matr1.isEmpty() && matr2.isEmpty())
		return true;

	if (matr1.hasEqualShapeTo(matr2)){
		for (int i=0; i<matr1.GetNumRows(); i++)
			for (int j=0; j<matr1.GetNumColumns(); j++)
				if (matr1.At(i, j) != matr2.At(i, j))
					return false;
	} else {
		return false;	
	}
	return true;
}



Matrix operator+ (const Matrix& matr1, const Matrix& matr2){
	if (matr1.isEmpty() && matr2.isEmpty())
		return Matrix();

	if (matr1.hasEqualShapeTo(matr2)){
		Matrix sum_matr(matr1.GetNumRows(), matr1.GetNumColumns());
		for (int i=0; i<matr1.GetNumRows(); i++)
			for(int j=0; j<matr2.GetNumColumns(); j++)
				sum_matr.At(i, j) = matr1.At(i, j) + matr2.At(i, j);
		return sum_matr;
	} else{
		throw invalid_argument("Matrixes have different sizes");
	}
}

int main(){
	try {
	  	Matrix one;
  		Matrix two;

  		cin >> one >> two;
  		cout << one + two << endl;
	} catch (exception& ex){
		cout << ex.what() << endl;
	}
	return 0;
}