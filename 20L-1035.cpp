#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

class Helper
{
public:
	static int StringLenght(char* str)
	{
		int length = 0;
		while (*str != '\0')// counts until null pointer is reached
		{
			length++;
			str++;
		}
		return length;
	}
	static char* GetStringFromBuffer(char* str)// allocates memory for the coming char pointer
	{
		int length = StringLenght(str);
		char* space = new char[++length];
		int i = 0;
		for (; str[i] != '\0'; i++)
			space[i] = str[i];
		space[i] = '\0';
		return space;
	}
	static int* Allocation(int* str)// alloactes memeory to int pointer
	{
		int length = sizeof(str);
		int* space = new int[length];
		int i = 0;
		for (; i<length; i++)
			space[i] = str[i];
		return space;
	}
	static bool isSubstring(char* os, char* ss)// checks if the string is substring
	{
		int M = sizeof(os);
		int N = sizeof(ss);
		for (int i = 0; i <= N - M; i++)
		{
			int r;
			for (r = 0; r < M; r++)
				if (ss[i + r] != os[r])
					break;
			if (r == M)
				return true;
		}
		return false;
	}
};

class StudentEvaluation
{
	friend void PrintStatistics(StudentEvaluation* studentList)//Global
	{
		int* MaxQ = new int[tQ];
		int* MaxA = new int[tA];
		int* MinQ = new int[tQ];
		int* MinA = new int[tA];
		int* AvgQ = new int[tQ]; 
		int* AvgA = new int[tA];

		//initializing
		for (int r = 0; r < tQ; r++)
		{
			MaxQ[r] = 0;
			MinQ[r] = 0;
			AvgQ[r] = 0;
		}
		for (int r = 0; r < tA; r++)
		{
			MaxA[r] = 0;
			MinA[r] = 0;
			AvgA[r] = 0;
		}
		
		// checking min max and storing data in avg
		for(int i=0;i<totalStudents;i++)
		{
			for (int r = 0; r < tQ; r++)
			{
				if (studentList[i].QMarks[r] > MaxQ[r])
					MaxQ[r] = studentList[i].QMarks[r];
				if (studentList[i].QMarks[r] < MinQ[r])
					MinQ[r] = studentList[i].QMarks[r];
				AvgQ[r] += studentList[i].QMarks[r];
			}
			for (int r = 0; r < tA; r++)
			{
				if (studentList[i].AMarks[r] > MaxQ[r])
					MaxA[r] = studentList[i].AMarks[r];
				if (studentList[i].AMarks[r] < MinQ[r])
					MinA[r] = studentList[i].AMarks[r];
				AvgA[r] += studentList[i].AMarks[r];
			}
		}

		// diffrent loops for quiz and assignment beacuse number not necesarily be equal in this case Qt=At=4
		cout << "		";
		for (int r = 0; r < tQ; r++)
		{
			cout <<"Q"<<r+1 << "	";
		}
		for (int r = 0; r < tQ; r++)
		{
			cout <<"A"<<r+1 << "	";
		}

		// displaying total marks of quiz and assignment
		cout << endl<<"Total:		";
		for (int r = 0; r < tQ; r++)
		{
			cout << qTotals[r]<<"	";
		}
		for (int r = 0; r < tQ; r++)
		{
			cout << aTotals[r] << "	";
		}

		//Minimum
		cout <<endl<< "Minimum:	";
		for (int r = 0; r < tQ; r++)
		{
			cout << MinQ[r]<<"	";
		}
		for (int r = 0; r < tQ; r++)
		{
			cout << MinA[r] << "	";
		}

		//Maximum
		cout << endl << "Maximum:	";
		for (int r = 0; r < tQ; r++)
		{
			cout << MaxQ[r] << "	";
		}
		for (int r = 0; r < tQ; r++)
		{
			cout << MaxA[r] << "	";
		}

		//Average
		cout << endl << "Average:	";
		for (int r = 0; r < tQ; r++)
		{
			cout <<fixed<<setprecision(2)<< (AvgQ[r]/totalStudents) << "	";
		}
		for (int r = 0; r < tQ; r++)
		{
			cout << fixed << setprecision(2) << (AvgA[r]/totalStudents) << "	";
		}
		cout << endl << endl;
		//deallocating memory
		delete[] MaxA; MaxA = NULL;
		delete[] MaxQ; MaxQ = NULL;
		delete[] MinA; MinA = NULL;
		delete[] MinQ; MinQ = NULL;
		delete[] AvgA; AvgA = NULL;
		delete[] AvgQ; AvgQ = NULL;
	}
private:
	static int totalStudents, tQ, tA, * qTotals, * aTotals;
	char RollNo[9];
	char* FName;
	char* LName;
	int* QMarks;
	int* AMarks;
	int Total;
public:

	StudentEvaluation()
	{
		for (int i = 0; i < 9; i++)
			RollNo[i] = 0;
		FName = LName = NULL;
		QMarks = AMarks=NULL;
		Total = 0;
	}

	~StudentEvaluation()
	{
		if (FName)
		{
			delete[] FName;
			FName = NULL;
		}
			
		if (LName)
		{
			delete[] LName;
			LName = NULL;
		}
			
		if (QMarks)
		{
			delete[] QMarks;
			QMarks = NULL;
		}
			
		if (AMarks)
		{
			delete[] AMarks;
			AMarks = NULL;
		}

	}
	
	// deleting static members;
	static void deletes()
	{
		delete[] qTotals;
		qTotals = NULL;
		delete[] aTotals;
		aTotals = NULL;
	}

	//getters for static members
	static int GetTotalStu()
	{
		return totalStudents;
	}
	static int GetTQ()
	{
		return tQ;
	}
	static int GetTA()
	{
		return tA;
	}

	int GetTotal()
	{
		return Total;
	}

	char* GetRoll()
	{
		return RollNo;
	}

	//setters for static members
	static void SetTotalstu(int no)
	{
		totalStudents = no;
	}
	static void SetTQ(int no)
	{
		tQ = no;
	}
	static void SetTA(int no)
	{
		tA = no;
	}

	static void SetQT(int *no)
	{
		qTotals = no;
	}

	static void SetAT(int* no)
	{
		aTotals= no;
	}

	//printing details
	void Print()
	{
		cout <<RollNo<<"	"<<FName<<" "<<LName<<"		"<<"|	";
		for (int i = 0; i < tQ; i++)
		{
			cout << QMarks[i]<<"	";
		}
		cout << "|  ";
		for (int i = 0; i < tA; i++)
		{
			cout << AMarks[i]<<"	";
		}
		cout <<"|  "<< Total<<endl;
	}

	// print individual list
	void PrintList()
	{
		cout << "Roll No. :" << RollNo<<endl;
		cout << "Name :" << FName << " " << LName<<endl;
		cout << "Quizes Marks: "<<endl<<endl;
		for (int i = 0; i < tQ; i++)
		{
			cout <<"Q"<<i+1<<": "<< QMarks[i] <<endl;
		}
		cout << endl<<"Assignements Marks: " << endl << endl;
		for (int i = 0; i < tA; i++)
		{
			cout << "A" << i + 1 << ": " << AMarks[i] <<endl;
		}
		cout << "Total: " << Total<<endl<<endl;
	}

	//reading data of each object of class type
	void ReadFromFile(ifstream &fin)
	{
		fin >> RollNo;
		char fName[40];
		char lName[20];
		fin >> fName;
		fin >> lName;

		FName = Helper::GetStringFromBuffer(fName);
		LName = Helper::GetStringFromBuffer(lName);

		//int total = 0;
		QMarks = new int[tQ];
		for (int i = 0; i < tQ; i++) 
		{
			fin >> QMarks[i];
			Total+= QMarks[i];
		}

		AMarks = new int[tA];
		for (int i = 0; i < tA; i++)
		{
			fin >> AMarks[i];
			Total += AMarks[i];
		}
	}

	const StudentEvaluation& operator=(const StudentEvaluation& rhs)// overloaded assignement
	{
		if (&rhs != this)	//Avoid self-assignment
		{
			delete [] FName;
			delete[] LName;

			for (int i = 0; i < 9; i++)
				RollNo[i] = rhs.RollNo[i];
			FName =Helper::GetStringFromBuffer(rhs.FName);
			LName =Helper::GetStringFromBuffer(rhs.LName);
			QMarks =Helper::Allocation( rhs.QMarks);
			AMarks = Helper::Allocation(rhs.AMarks);
			Total = rhs.Total;
		}
		return *this;
	}

	StudentEvaluation(const StudentEvaluation& rhs)//CopyConstructor
	{
		delete[] FName; 
		delete[] LName;

		for (int i = 0; i < 9; i++)
			RollNo[i] = rhs.RollNo[i];
		FName = Helper::GetStringFromBuffer(rhs.FName);
		LName = Helper::GetStringFromBuffer(rhs.LName);
		QMarks = Helper::Allocation(rhs.QMarks);
		AMarks = Helper::Allocation(rhs.AMarks);
		Total = rhs.Total;
	}
};

StudentEvaluation* ReadFromFile()
{
	ifstream fin("GradeSheet.txt");
	int a=0,b=0,c=0;
	if (fin)
	{
		// setting values of total students, tQ and tA
		fin >> a;
		StudentEvaluation::SetTotalstu(a);
		StudentEvaluation* arr = new StudentEvaluation[a];

		fin >> b;
		StudentEvaluation::SetTQ(b);
		int* qTotals = new int[b];
		StudentEvaluation::SetQT(qTotals);

		fin >> c;
		StudentEvaluation::SetTA(c);
		int* aTotals = new int[c];
		StudentEvaluation::SetAT(aTotals);

		// reading data for total marks
		for (int i = 0; i < b; i++)
		{
			fin >> qTotals[i];
		}
		
		for (int i = 0; i < c; i++)
		{
			fin >> aTotals[i];
		}

		for (int i = 0; i < a; i++)
			arr[i].ReadFromFile(fin);
		return arr;
	}
	else
		return 0;
}

StudentEvaluation SearchStudentByRollNo(StudentEvaluation* student)
{
	int a = StudentEvaluation::GetTotalStu();
	char array[9] = { '1','5','L','-','4','0','2','3' ,'\0'};// hardcoded 
	char arr[9] = { '1','5','L','-','1','2','3','4' ,'\0' };// second test case change below to check
	bool yes = false;
	for (int i = 0; i < a; i++)
	{
		char* ptr = student[i].GetRoll();
		if (strcmp(array, ptr) == 0)
		{
			yes = true;
			return student[i];
		}		
	}
	if (!yes)
		cout << "NotFound";
}

void Sorting(StudentEvaluation*& student)
{
	int a = StudentEvaluation::GetTotalStu();
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a - 1; j++)
		{
			int c = student[i].GetTotal(), b = student[j].GetTotal();
			if (c > b)// if successor is less than preceding swap
			{
				StudentEvaluation temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
	}
}

//initializing static members
int StudentEvaluation::totalStudents = 0;
int StudentEvaluation::tQ = 0;
int StudentEvaluation::tA = 0;
int* StudentEvaluation::aTotals= NULL;
int* StudentEvaluation::qTotals = NULL;

int main()
{
	system("color 0D");
		StudentEvaluation* Student = ReadFromFile();
		int count = StudentEvaluation::GetTotalStu();
		if (Student)
		{
			cout << "__________________________________________________ReadDataFromFile____________________________________________________" << endl << endl;
			cout << "RollNo.	" << "	Name			" << "Quizzes					" << "Assignments			" << "Total." << endl;
			cout << endl << "______________________________________________________________________________________________________________________" << endl;
			for (int i = 0; i < count; i++)
			{
				Student[i].Print();
			}

			cout << endl << endl << endl << "____________________________________________________AfterSorting______________________________________________________" << endl << endl;
			cout << "RollNo.	" << "	Name			" << "Quizzes					" << "Assignments			" << "Total." << endl;
			cout << endl << "______________________________________________________________________________________________________________________" << endl;

			Sorting(Student);
			for (int i = 0; i < count; i++)
			{
				Student[i].Print();
			}

			cout << endl << endl << endl << "__________________________________________________StudentInformation____________________________________________________" << endl << endl;

			StudentEvaluation Search = SearchStudentByRollNo(Student);
			if (Search.GetTotal() != 0)
				Search.PrintList();
			cout << endl << endl << endl << "___________________________________________________ClassStatistics______________________________________________________" << endl << endl;
			PrintStatistics(Student);
			delete[] Student;
		}
		else
			cout << "File Not avaiable........."<<endl<<endl;
		StudentEvaluation::deletes();// delete static members
	return 0;
}