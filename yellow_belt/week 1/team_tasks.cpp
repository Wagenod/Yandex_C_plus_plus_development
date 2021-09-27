#include <iostream> 
#include <tuple>
#include <string>
#include <map>


using namespace std;

enum class TaskStatus {
  	NEW,          // новая
  	IN_PROGRESS,  // в разработке
  	TESTING,      // на тестировании
  	DONE          // завершена
};

// // Объявляем тип-синоним для map<TaskStatus, int>,
// // позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

// void PrintTasks(const map<string, TasksInfo>& tasks){
// 	cout << "----===========================--------" << endl;
// 	for (const auto& item: tasks){
// 		cout << "user: " << item.first << endl;
// 		for (const auto& t: item.second){
// 			switch(t.first){
// 				case TaskStatus::NEW:
// 					cout << "	NEW: " << t.second << endl;
// 					break;
// 				case TaskStatus::IN_PROGRESS:
// 					cout << "	IN_PROGRESS: " << t.second << endl;
// 					break;
// 				case TaskStatus::TESTING:
// 					cout << "	TESTING: " << t.second << endl;
// 					break;
// 				case TaskStatus::DONE:
// 					cout << "	DONE: " << t.second << endl;
// 					break;
// 			}
			
// 		}
// 	}
// 	cout << "----===========================--------" << endl;
// }

// void PrintTasksInfo(TasksInfo tasks_info) {
// 	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
// 	    ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
// 	    ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
// 	    ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
// }


void PrintTasksInfo(const TasksInfo& tasks_info) {
    if (tasks_info.count(TaskStatus::NEW)) {
        std::cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
    }
    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
        std::cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
    }
    if (tasks_info.count(TaskStatus::TESTING)) {
        std::cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
    }
    if (tasks_info.count(TaskStatus::DONE)) {
        std::cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
    }
}

void PrintTasksInfo(const TasksInfo& updated_tasks, const TasksInfo& untouched_tasks) {
    std::cout << "Updated: [";
    PrintTasksInfo(updated_tasks);
    std::cout << "] ";

    std::cout << "Untouched: [";
    PrintTasksInfo(untouched_tasks);
    std::cout << "] ";

    std::cout << std::endl;
}

class TeamTasks {
public:
  	// Получить статистику по статусам задач конкретного разработчика
  	const TasksInfo& GetPersonTasksInfo(const string& person) const{
  		return tasks.at(person);
  	}
  
  	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  	void AddNewTask(const string& person){
  		tasks[person][TaskStatus::NEW]++;
  	}

  	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
  		TasksInfo updated_tasks, untouched_tasks, actual_tasks;

  		if (tasks.count(person) == 0)
  			return {updated_tasks, untouched_tasks};

  		for(const pair<TaskStatus, int>& item: tasks.at(person)){
  			for (int i=1; i <= item.second; i++){
	  			if (task_count > 0){
	  				updated_tasks[TaskStatus(int(item.first) + 1)] += 1;
	  				actual_tasks[TaskStatus(int(item.first) + 1)] += 1;
	  				task_count--;
	  			} else {
	  				if (item.first != TaskStatus::DONE)
	  					untouched_tasks[item.first] += 1;
	  				actual_tasks[item.first] += 1;
	  			}
  			}
  		}

  		tasks[person] = actual_tasks;
  		return {updated_tasks, untouched_tasks};
  	}

private:
	map<string, TasksInfo> tasks;
};


int main(){
    TeamTasks tasks;
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks;
	
std::cout << "\nLisa" << std::endl;

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 5}, {}]

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 1);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 1}, {"TESTING": 4}]

    for (auto i = 0; i < 5; ++i) {
        tasks.AddNewTask("Lisa");
    }

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 4);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 5);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"TESTING": 4, "DONE": 1}, {"TESTING": 4}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"TESTING": 8, "DONE": 2}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"DONE": 8}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 10);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"DONE": 10}
    std::cout << std::endl;

    tasks.AddNewTask("Lisa");

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"NEW": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Lisa", 2);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{"IN_PROGRESS": 1}, {}]

    PrintTasksInfo(tasks.GetPersonTasksInfo("Lisa"));  // {"IN_PROGRESS": 1, "DONE": 10}
    std::cout << std::endl;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Bob", 3);
    PrintTasksInfo(updated_tasks, untouched_tasks);  // [{}, {}]
	return 0;

}