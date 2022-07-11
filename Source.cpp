#include <iostream>
#include <fstream>
#include <string>

class Student {

private :
	std::string rollNumber;
	std::string name;
	float mathMark;
	float physicsMark;
	float computerScienceMark;
	float networksArchitectureMark;
	float englishMark;
	float average;
	char grade;

public : 
	Student()
		: rollNumber("0"), name("none"), mathMark(0), physicsMark(0), computerScienceMark(0), englishMark(0), networksArchitectureMark(0)
		,average(0),grade('F')
	{
	}

	~Student(){}

	void create();
	void search();
	void displayAll();
	void deletes();
	void modify();
		
};


char choose() {

	char choiceInput;
	do {
		std::cout << "\n\n			  Menu\n\n";
		std::cout << "	    1)Create student record\n\n";
		std::cout << "	    2)Search a student's record\n\n";
		std::cout << "	    3)Display all records\n\n";
		std::cout << "	    4)Delete a student's record\n\n";
		std::cout << "	    5)Modify a student's record\n\n";
		std::cout << "	Please choose one instruction [1/2/3/4/5] .. ";

		std::cin >> choiceInput;
		std::cout << "\n";
	} while (choiceInput != '1' && choiceInput != '2' && choiceInput != '3' && choiceInput != '4' && choiceInput != '5');
	return choiceInput;
}

void Student :: create() {

	std::cout << "Enter student's roll number:\n";
	std::cin >> this->rollNumber;
	std::cout << "\n";
	std::cout << "Enter student's name:\n";
	std::cin >> this->name;
	std::cout << "\n";
	std::cout << "All marks should be out of 100\n";
	std::cout << "Enter Math mark\n";
	std::cin >> this->mathMark;
	std::cout << "\n";
	std::cout << "Enter Physics mark\n";
	std::cin >> this->physicsMark;
	std::cout << "\n";
	std::cout << "Enter Computer Science mark\n";
	std::cin >> this->computerScienceMark;
	std::cout << "\n";
	std::cout << "Enter Networks Architecture mark\n";
	std::cin >> this->networksArchitectureMark;
	std::cout << "\n";
	std::cout << "Enter English mark\n";
	std::cin >> this->englishMark;
	std::cout << "\n";

	this->average = (this->mathMark + this->physicsMark + this->computerScienceMark
		+ this->networksArchitectureMark + this->englishMark) / 5;

	if (this->average < 60) this->grade = 'F';
	else if (this->average < 70)  this->grade = 'D';
	else if (this->average < 80)  this->grade = 'C';
	else if (this->average < 90)  this->grade = 'B';
	else   this->grade = 'A';

	std::fstream students;

	students.open("Students.txt", std::ios_base::app);
	students << this->rollNumber << "\n" << this->name << "\n" << this->mathMark << "\n" << this->physicsMark << "\n" << this->computerScienceMark
		<< "\n" << this->networksArchitectureMark << "\n" << this->englishMark << "\n" << this->average << "\n" << this->grade << "\n";

	std::cout << "Student record has been added!\n";
}


void Student :: search() {

	std::string test;

	std::cout << "Please enter the student's roll number : .. ";
	std::cin >> this->rollNumber;
	std::cout << "\n";

	std::fstream students;
	students.open("Students.txt");

	while (std::getline(students, test)) {
		if (test == this->rollNumber)
		{
			std::getline(students, test); std::cout << "The student's name is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Math mark is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Physics mark is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Computer Science mark is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Networks Architecture mark is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's English mark is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Average is :" << test << "\n";
			std::getline(students, test); std::cout << "The student's Grade is :" << test << "\n";
			return;
		}
	}
	std::cout << "\nStudent not found!\n";
}

void Student :: displayAll() {
	std::string test;
	std::fstream students;
	students.open("Students.txt");
	while (std::getline(students, test)) {

		std::cout << "The student's roll number is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's name is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Math mark is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Physics mark is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Computer Science mark is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Networks Architecture mark is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's English mark is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Average is :" << test << "\n";
		std::getline(students, test); std::cout << "The student's Grade is :" << test << "\n";
		std::cout << "\n--------------------------------------\n";
	}
}

void Student::deletes() {
	std::fstream copyFile;
	bool rollNumberFound = false;
	std::string test;
	std::fstream students;
	students.open("Students.txt");
	std::cout << "Please enter the student's roll number:\n";
	std::cin >> this->rollNumber;
	while (std::getline(students, test)) {
		if (test != this->rollNumber) {
			copyFile.open("Copy.txt", std::ios_base::app);
			copyFile << test<<"\n";
			copyFile.close();
		}
		else {
			for (int i = 0; i < 8; i++) { 
				std::getline(students, test);
			}
			 rollNumberFound = true;
		}
	}
	students.close();
	
	remove("Students.txt");
	rename("Copy.txt", "Students.txt");

	if (!rollNumberFound) {
		std::cout << "Student not found!\n";
	}
	else {
		std::cout<<("Student record has been deleted\n");
	}

}

void Student :: modify() {
	deletes();
	create();
}

int main() {
	char choice;
	Student stud;
	while (true) {
		choice = choose();
		switch (choice) {
		case('1'): stud.create();  break;
		case('2'): stud.search(); break;
		case('3'): stud.displayAll(); break;
		case('4'): stud.deletes(); break;
		case('5'): stud.modify(); break;
		}
	}

	return 0;
}