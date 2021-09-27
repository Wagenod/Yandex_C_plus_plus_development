
#include <iostream>
#include <string>


using namespace std;


struct Specialization {
	string name;

	explicit Specialization(const string& new_name){
		name = new_name;
	}

};

struct Course {
	string name;

	explicit Course(const string& new_name){
		name = new_name;
	}
};

struct Week {
	string name;

	explicit Week(const string& new_name){
		name = new_name;
	}
};


struct LectureTitle {
  string specialization;
  string course;
  string week;

	LectureTitle(const Specialization& new_spec, const Course& new_course, const Week& new_week){
		specialization = new_spec.name;
		course = new_course.name;
		week = new_week.name; 
	}
};




int main(){
	LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
	);

	Specialization("C++");
	return 0;
}