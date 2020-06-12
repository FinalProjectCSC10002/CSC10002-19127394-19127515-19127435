#include "Manager.h"

int login(fstream& fstu, fstream& fsta, fstream& flec , Information & person)
{
	string username;
	string password;
	cout << "Enter User name: ";
	getline(cin , username);
	cout << "Enter Password: ";
	getline(cin , password); 

	int n;
	fstu.open("D:\\project data\\person data\\Student.txt" , ios :: in); 
	if (!fstu.is_open())
	{
		cout << " fail";
		return -1;
	}
	fstu >> n;
	Information* student = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		fstu.getline(a, 3);
		getline(fstu , student[i].Class);
		getline(fstu, student[i].id);
		getline(fstu, student[i].password);
		getline(fstu, student[i].fullname);
		fstu >> student[i].dob.year;
		fstu >> student[i].dob.month;
		fstu >> student[i].dob.date;
		string s ; 
		getline(fstu , s);
		if (username == student[i].id && password == student[i].password)
		{
			cout << "Hello student!!! " << student[i].fullname << endl;
			person = student[i] ;
			fstu.close();
			delete [] student ;
			return 2;
		}
	}
	fstu.close();
	delete[] student;
	flec.open("D:\\project data\\person data\\Lecture.txt",ios::in);
	flec >> n;
	Information* lecture = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		flec.getline(a, 3);
		getline(flec, lecture[i].id);
		getline(flec, lecture[i].password);
		getline(flec, lecture[i].fullname);
		getline(flec, lecture[i].degree);
		flec >> lecture[i].male;
		string s ; 
		getline(flec , s);
		if (username == lecture[i].id && password == lecture[i].password)
		{
			cout << "Welcome, Lecturer !!" << lecture[i].fullname << endl;
			person = lecture[i] ;
			flec.close();
			delete [] lecture ;
			return 1;
		}
	}
	flec.close();
	delete[] lecture;
	fsta.open("D:\\project data\\person data\\Staff.txt" , ios :: in);
	fsta >> n;
	Information* staff = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		fsta.getline(a, 3);
		getline(fsta, staff[i].id);
		getline(fsta, staff[i].password);
		getline(fsta, staff[i].fullname);
		fsta >> staff[i].male;
		string s ; 
		getline(fsta , s);
		if (username == staff[i].id && password == staff[i].password)
		{
			cout << "Welcome, Staff !! " << staff[i].fullname << endl;
			person = staff[i] ;
			fsta.close();
			delete [] staff ;
			return 0;
		}
	}
	fsta.close();
	delete[] staff;
	return -1;
}
void show_menu_lecturer()
{
	cout << "LECTURERS MENU " << endl ;
	cout << "-1 - Log out." << endl;
    cout << "0 - View list of courses in the current semester."<< endl ;
    cout << "1 - View list of students of a course." << endl ; 
    cout << "2 - View attendance list of a course." << endl ; 
    cout << "3 - Edit an attendance." << endl ; 
    cout << "4 - Import scoreboard of a course (midterm, final, lab) from a csv file." << endl ; 
    cout << "5 - Edit grade of a student." << endl ; 
    cout << "6 - View a scoreboard." << endl ; 
}
void show_menu_student()
{
	cout << "-1 - Log out." << endl;
    cout << "0 - Check-in." << endl ; 
    cout << "1 - View check-in result." << endl ; 
    cout << "2 - View schedules."  << endl ;
    cout << "3 - View his/her scores of a course." << endl ;
}
void show_menu_staff() {
	cout << "STAFF MENU " << endl ;
	cout << "-1 - Log out." << endl;
	cout << "0 - Import students of a class. " << endl;
	cout << "1 - Add a new student to a class. " << endl;
	cout << "2 - Edit an existing student. " << endl;
	cout << "3 - Remove a student. " << endl;
	cout << "4 - Change students from a class A to class B. " << endl;
	cout << "5 - View list of classes. " << endl;
	cout << "6 - View list of students in a class. " << endl;
	cout << "7 - Create / View academic years and semester." << endl;
	cout << "8 - Import courses from a semester." << endl;
	cout << "9 - Add a new course." << endl;
	cout << "10 - Edit an existing course. " << endl;
	cout << "11 - Remove a course." << endl;
	cout << "12 - Remove a specific student from a course." << endl;
	cout << "13 - Add a specific student to a course." << endl;
	cout << "14 - View list of courses in the current semester. " << endl;
	cout << "15 - View list of students of a course." << endl;
	cout << "16 - View scoreborad of a course. " << endl;
	cout << "17 - Save scoreboard into csv file. " << endl;
	cout << "18 - View attendance list of a course. " << endl;
	cout << "19 - Save list of atandance into csv file. " << endl;
	cout << "20 - Create / View all lecturers." << endl;
}
void showInfo_staff(Information person) 
{
	cout << "-------------Your Information---------" << endl;
	cout << "Full name: " <<  person.fullname  << endl ;
	cout << "Male: ";
	if (person.male == 0)
		cout << "Male" << endl;
	else
		cout << "Female" << endl;
	cout << "Your role: Staff.";
}
void showInfo_lecturer(Information person)
{
	cout << "-------------Your Information---------" << endl;
	cout << "Full name: " <<  person.fullname  << endl ;
	cout << "Male: ";
	if (person.male == 0)
		cout << "Male" << endl;
	else
		cout << "Female" << endl;
	cout << "Your role: Lecturer." << endl ;
	cout << "Standard: " << person.degree << endl ;
}
void showInfo_student(Information person)
{
	cout << "-------------Your Information---------" << endl;
	cout << "Class: " << person.Class  << endl ;
	cout << "ID: " << person.id << endl ;
	cout << "Fullname:" <<  person.fullname  << endl ;
	cout << "Date of Birth: " << person.dob.year << "-" ;
	if(person.dob.month < 10)
		cout << "0" << person.dob.month << "-" ;
	else	
		cout << person.dob.month << "-" ;
	if(person.dob.date < 10)
		cout << "0" << person.dob.date << endl ;
	else
		cout << person.dob.date << endl ;
	
}

void check_password(Information &person , string &pass)
{
        cout << "Enter new password : ";
        cin >> person.password ;
        cout << "Retype your new password : ";
        cin >> pass ;
        if(pass == person.password)
        {
            cout << "Change password successfully ." << endl;
            return ;
        }
        else
        {
            cout << "Enter new password failed , Please enter again" << endl ;
            return check_password(person , pass);
        }
}
void change_password(Information &person)
{
    string pass ;
    cout << "Enter old password : " ;
    cin >> pass ;
	if (pass == person.password)
	{

		check_password(person, pass);

		while (pass != person.password)
		{
			cout << "Password not match  " << endl;
			cout << "Enter old password : ";
			cin >> pass;
			if (pass == person.password)
				check_password(person, pass);
		}

	}
	else
	{
		cout << "Your password invalid !!!" << endl;
	}
}
void saveChangePassword(Information person)
{
    int n = 0 ;
    Information * Student ;
    string temp = "D:\\class data\\Student-" + person.Class + ".txt" ;
    const char * filename1 = temp.c_str() ;
    load_file(filename1, n, Student) ;
    for(int i = 0 ; i < n ; i++)
    {
        if(Student[i].id == person.id)
        {
            Student[i].password = person.password ;
            break ;
        }
    }
    saveStudent(Student, filename1 ,  n) ;
    delete [] Student ;
    const char * filename2 = "D:\\person data\\Student.txt" ;
    load_file(filename2, n, Student);
    for(int i = 0 ; i < n ; i++)
    {
        if(Student[i].id == person.id)
        {
            Student[i].password = person.password ;
            break ;
        }
    }
    saveStudent(Student, filename2, n);
    delete [] Student ;
}

