#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	string name;
	string surname;
	int dayOfBirthday;
	int monthOfBirthday;
	int yearOfBirthday;
};


void print(const vector<Student>& students){
	for (auto item: students)
	{
		cout << item.name << "-";
		cout << item.surname <<"-";
		cout << item.dayOfBirthday <<"-";
		cout << item.monthOfBirthday <<"-";
		cout << item.yearOfBirthday <<endl;
	}
}

string getFullName(const Student& st){
	return st.name + " " + st.surname;
}

string getFullDate(const Student& st){
	return to_string(st.dayOfBirthday) + "." + to_string(st.monthOfBirthday) + "." + to_string(st.yearOfBirthday);
}


int main(){

	vector<Student> students;
	int N, M;
	string name_tmp, surname_tmp;
	int dayOfBirthday_tmp, monthOfBirthday_tmp, yearOfBirthday_tmp;

	cin >> N;

	for (int i=1; i<=N;i++){
		Student st;
		cin >> st.name >> st.surname >> st.dayOfBirthday >> st.monthOfBirthday >> st.yearOfBirthday;
		students.push_back(st);
	}

	// print(students);

	cin >> M;
	string command;
	int code;

	

	for (int k=1; k<= M; k++){
		cin >> command >> code;

		if (code > N || code < 1)
		{
			cout << "bad request" << endl;
			continue;
		}

		Student item = students[code - 1];

		if (command == "name"){
			cout << getFullName(item) << endl;
		} else if (command == "date"){
			cout << getFullDate(item) << endl;
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}