#include <iostream>
#include <string>
#include<fstream>
using namespace std;


class Person {
public:
    string name;
    string id;
    


    virtual void input() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter ID/Reg No: ";
        getline(cin, id);
    }

    virtual void display() {
        cout << "Name : " << name << endl;
        cout << "ID   : " << id << endl;
    }

    string getName() 
	{
        return name;
    }
};

class Student : public Person {
private:
    int semester;
    string bookIssued;

public:
    Student() {
        semester = 0;
        bookIssued = "None";
    }

    void input()
	 {
        Person::input();
        cout << "Enter Semester: ";
        cin >> semester;
    }

    void display() {
        cout << "-----------------------------\n";
        Person::display();
        cout << "Semester : " << semester << endl;
        cout << "Book     : " << bookIssued << endl;
        cout << "-----------------------------\n";
    }

    void setIssuedBook(string book) //issue book
	{
        bookIssued = book;
    }

    bool hasBook() 
	{
        return (bookIssued != "None"); //book assign or not 
    }
};

class Library {
public:
    void issueBook(Student &s) //direct modify the original student 
	{
        if (s.hasBook()) {
            cout << "\nStudent already has a book issued!\n";
            return;
        }

        int choice;
        cout << "\n--- Available Books ---\n";
        cout << "Issuing to: " << s.getName() << endl; 
        cout << "1. Introduction to Algorithms\n";
        cout << "2. Clean Code\n";
        cout << "3. Think Like a Programmer\n";
        cout << "4. C++ OOP Mastery\n";
        cout << "0. Cancel\n";
        cout << "Select book: ";
        cin >> choice;

        switch (choice) 
		{
        case 1: s.setIssuedBook("Intro to Algorithms"); 
		break;
        case 2: s.setIssuedBook("Clean Code"); 
		break;
        case 3: s.setIssuedBook("Think Like a Programmer"); 
		break;
        case 4: s.setIssuedBook("C++ OOP Mastery");
		 break;
        case 0: return;
        default:
            cout << "Invalid choice!\n";
            return;
        }

        cout << "Book issued successfully!\n";
    }
};

float getGradePoint(string grade)
{
    if (grade == "A"|| grade== "a") 
	{ 
	   return 4; 
	} 
    else if (grade == "A-" || grade == "a-") 
	{ 
	return 3.67;
	 } 
    else if (grade == "B+" || grade == "b+") 
	{ 
	return 3.33;
	 }
    else if (grade == "B" || grade == "b") 
	{ 
	return 3.00;
	 }
    else if (grade == "B-" || grade == "b-")
	 { 
	return 2.67; 
	}
    else if (grade == "C+" || grade == "c+") 
	{ 
	return 2.33; 
	}
    else if (grade == "C" || grade == "c") 
	{ 
	return 2.00;
	 }
    else if (grade == "D" || grade == "d") 
	{ 
	return 1.00; 
	}
    else {
	 return 0.0;
	 }
}

int main()
{
	
	string file_handling;
	
	ifstream i("thanks.txt");
    string c_id, c_pass, id, pass;

    cout << "\t\t\t\t\tCreate Your Account\n";
    cout << "Enter Your University ID: ";
    getline(cin, c_id);
    cout << "Enter Your Password: ";
    getline(cin, c_pass);

    
    system("CLS"); 
    cout<<"Sign in"<<endl;
    int attempts = 0;
    while (id!=c_id  ||  pass!=c_pass)
    {
    	cout<<"\t\t\tYou have left "<<3-attempts<<" chances"<<endl;
    	cout << "\nLogin\n";
        cout << "ID: ";
        getline(cin, id);
        cout << "Password: ";
        getline(cin, pass);
        
        attempts++;
    
    
    if (attempts == 4)
	 {
        cout << "Account locked!\n";
        return 0;
    }
}
cout<<endl;
cout << "\t\t\t.........Credentials matched successfully........." << endl;

    Student students[20];
    Library lib; //obj

    int choice, count = 0;

    do {
    	cout << "\n\t\t\t\t\tWELLCOME TO THE\n\n";
cout << "\t\t\t-----------------------------------\n";
cout << "\t\t\t*                                 *\n";
cout << "\t\t\t*  UNIVERSITY MANAGEMENT SYSTEM   *\n";
cout << "\t\t\t*                                 *\n";
cout << "\t\t\t-----------------------------------\n\n";


        cout << "1. Add Student\n";
        cout << "2. Search Student by ID\n"; 
        cout << "3. Issue Book (By ID)\n"; 
        cout << "4. Calculate GPA\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count <= 20) {
                students[count].input();
                
                bool duplicate = false;
                for(int i = 0; i < count; i++) {
                    if(students[count].id == students[i].id) 
					{
                        duplicate = true;
                        break;
                    }
                }

                if(duplicate) {
                    cout << "\nERROR: A student with ID " << students[count].id << " already exists!\n";
                    cout << "Data discarded.\n";
                } else {
                    cout << "Student added successfully.\n";
                    count++;
                }
            }
            else
                cout << "Student limit reached!\n";
            break;

        case 2:
            {
                string searchID;
                bool found = false;
                
                cin.ignore(); 
                cout << "Enter Student ID to Search: ";
                getline(cin, searchID);

                for (int i = 0; i < count; i++) {
                    if (students[i].id == searchID) {
                        students[i].display();
                        found = true;
                        break; 
                    }
                }

                if (!found) {
                    cout << "No student found with ID: " << searchID << endl;
                }
            }
            break;

        case 3:
            {
                string issueID;
                bool found = false;

                cin.ignore(); 
                cout << "Enter Student ID to issue book: ";
                getline(cin, issueID);

                for(int i = 0; i < count; i++) {
                    if(students[i].id == issueID) {
                        lib.issueBook(students[i]);
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Student with ID " << issueID << " not found!\n";
                }
            }
            break;

        case 4:
        {
            int subjects;
            cout << "Enter number of subjects: ";
            cin >> subjects;

            string subject,grade;
            int credit;
            float totalPoints = 0, totalCredits = 0;

            for (int i = 1; i <= subjects; i++)
             {
                cin.ignore();
                cout << "Subject "<<i<< " Name: ";
                getline(cin, subject);

                cout << "Credit Hours: ";
                cin >> credit;

                cout << "Grade (A, A- ,B+ ,B ,B- ,C+ , C ,D ): ";
                cin >> grade;

                totalPoints += getGradePoint(grade) * credit;
                totalCredits += credit;
            }

            if(totalCredits > 0)
                cout << "Your GPA is: " << (totalPoints / totalCredits) << endl;
            else 
                cout << "Total credits cannot be zero."<<endl;
            break;
        }

        case 0:
            while(!i.eof())
            {
            	getline(i,file_handling, '.');
            	cout<<file_handling;
			}
            break;

        default:
            cout << "Invalid option!"<<endl;
        }

    } while (choice != 0);

    return 0;
}
