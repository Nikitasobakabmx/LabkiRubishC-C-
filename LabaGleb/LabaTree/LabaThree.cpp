#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#define COUNT 6
using namespace std;
struct Date{
    int day;
    int manth;
    int year;
};
struct Stud{
    string name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
int main(){
  string path = "C:\\Users\\Nikitka\\Documents\\Coding\\C++\\Labs\\LabaGleb\\LabaTree\\";
  ofstream file;
  do{
  	cout << "input name of file\n";
  	string name;
  	cin >> name;
  	path += name;
	file.open(path);
  }while(!file.is_open());
  cout << "File is open\n";
  cout << "Input list" << endl;
  string data = "";
  Stud students[COUNT];
  for(int i = 0; i < COUNT; i++){
      cin >> students[i].name >> students[i].gendr >>
    	students[i].finish >> students[i].adress >>
    	students[i].grand >> students[i].date.day >>
    	students[i].date.manth >> students[i].date.year;
      data += students[i].name + " " + students[i].gendr + " " + students[i].finish + " " + 
        students[i].adress + " " + students[i].grand + " " + to_string(students[i].date.day) + " " +
        to_string(students[i].date.manth) + " " + to_string(students[i].date.year) + " ";
  for(int k = 0; k<5;k++){
    cin >> students[i].marks[k];
    data += to_string(students[i].marks[k]) + " ";
  }
  cin >> students[i].point;
  data += to_string(students[i].point) + "\n";
  }
  cout<<"Write in file\n";
  file << data;
  file.close();
  getch();
  return 0;
}
