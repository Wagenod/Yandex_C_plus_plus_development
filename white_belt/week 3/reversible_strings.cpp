#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString{
public:
	//конструктор по умолчанию
	ReversibleString(){ 
		s = "";
	}

	// параметризованный конструктор
	ReversibleString(string new_string){
		s = new_string;
	}

	void Reverse(){
		reverse(s.begin(), s.end());
	}

	string ToString() const{
		return s;
	}
private:
	string s;
};




int main(){
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
	return 0;
}