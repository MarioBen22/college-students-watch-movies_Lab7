// Mario Benavides
// Lab 7 - void display needs loop and shows 0 for average

// This program will be used to gather statistical data about the number of movies college students see in a month.
// Ask the user how many students were surveyed and dynamically allocate an array of that size
// Enter the number of movies each student has seen
// Sort the scores and calculate the average.


#include <iostream>
#include <iomanip>
using namespace std;


// Function prototype
void getData(int *, int);
void sortData(int *, int);
double getAvg(int *, int);
void display(int *, int);


// accept the number of students 
int main()
{
	int *Movies, Students;
	double Avg;

	cout << "How many students were surveyed? ";
	cin	 >> Students;
		if( Students < 0)	// input validation
    	{
		cout << "The number of students should be a positive integer." << endl;	
		cin	 >> Students;
		} 

	Movies = new int[Students];
	getData(Movies, Students);
	sortData(Movies, Students);
	Avg = getAvg(Movies, Students);
	display(Movies, Students);

	delete [] Movies; // close memory leak
	Movies = 0;

	return 0;
}


// get the number of movies watched by each college student. 
void getData(int *array, int size)
{
	cout << "Enter the number of movies each student has seen.\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Student " << (i + 1) << ": ";
		cin  >> *(array + i);
			if(*(array+i) < 0)	// input validation
    		{
			cout << "The number of movies should be a positive integer. Try again." << endl;	
			cin  >> *(array + i);
			}
	}
}


// sort the array in ascending order. 
void sortData(int *array, int size)
{
	int scan, minIndex, minValue;

	for (int scan = 0; scan < (size - 1); scan++)
	{
		minIndex = scan;
		minValue = *(array + scan);
		for (int i = scan + 1; i < size; i++)
		{
			if (*(array + i) < minValue)
			{
				minValue = *(array + i);
				minIndex = i;
			}
		}
		*(array + minIndex) = *(array + scan);
		*(array + scan) = minValue;
	}
}


// value-returning function that calculates the average of the movies watched and returns it to the main function.
double getAvg(int *array, int size)
{
	double Sum = 0;
	for (int i = 0; i < size; i++)
	{
		Sum += *(array +i);
	}
	return Sum / size;   //You needed to display average within the getaverage function or in main.  
						//The value doesn't get carried into the display function.  
}


// display the sorted list of the number of movies watched.
void display(int *array, int size)
{
	int *Movies, Students;
	double Avg;
	
	cout << "\nNumber of Movies Watched\n";
	cout << "-------------------------\n";
	
	cout << (*array) << "\n"; 
		cout << *(array+1) << "\n";
			cout << *(array+2) << "\n"; 
		
	cout << "---------------\n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Average: " << Avg << endl; // shows 0 for average
}


