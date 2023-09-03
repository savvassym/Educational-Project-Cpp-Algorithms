#include "Pinakas.h"
#include "RandMT.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) 
{
	
	
	Pinakas a,b;
	int type,n;
	clock_t ct0,ct1;
	double sec1,sec2,sec3,sec4;
	
	ofstream fout;
	
	fout.open("TIME.txt");
	
	cout << "Student" << endl;
	cout << "=======" << endl;
	cout << "Name: Symeonidis Savvas" << endl;
	cout << "AEM: 4268" << endl;
	cout << endl;
	cout << "Computer characteristics" << endl;
	cout << "========================" << endl;
	cout << "CPU: Intel(R)" << endl;	
	cout << " Core(TM)i7-75000U 2.70GHz 2.90GHz" << endl;
	cout << "RAM: 8.00GB" << endl;
	cout << endl;
	cout << "Array Size? ";
	cin >> n;
	
	a.setArraySize(n);
	a.createArray();
		
	b.setArraySize(n);
	b.createArray();
		
	cout << endl;
	cout << "Array types: " << endl;
	cout << "   1. Random 100% " << endl ; 
    cout << "   2. Sorted 50%, Random 50%" << endl ; 
    cout << "   3. Sorted ASC" << endl ; 
    cout << "   4. Sorted DESC" << endl ;
    cout << endl;
	cout << "Choose array type: " ;
	cin >> type;
	cout << endl;
	

	switch(type)
	{
	case(1):
		a.fillArray();
	break;
	
    case(2): 
		a.fillArraySR();		  
	break;
	
    case(3):
		a.fillArrayASC();
	break;	
    
    case(4):
		a.fillArrayDESC();	  
	break;
	
	default:
    cout << "End" << endl;	
	}

	cout << "Sorting --> ";
if(type<=4)
{
	a.copyArray(b);
		//b.printArray();
		ct0 = clock();
		cout << "Bubble...";
	b.bubbleSort();
		ct1 = clock();
		sec1 = double (ct1-ct0)/CLOCKS_PER_SEC;
		fout << "BUBBLE SORT\n" 
			 << "Xronos: " 
		 	 << sec1 << endl;	
			 	 
	a.copyArray(b);
		//b.printArray();
		ct0 = clock();
		cout << "Select...";
	b.selectSort();
		ct1 = clock();
		sec2 = double (ct1-ct0)/CLOCKS_PER_SEC;
		fout << "===========\n"
			 << "SELECT SORT\n"
			 << "Xronos: "
		 	 << sec2 << endl;
		 	 
 	a.copyArray(b);
		//b.printArray();
		ct0 = clock();
		cout << "Insert...";
	b.insertSort();
		ct1 = clock();
		sec3 = double (ct1-ct0)/CLOCKS_PER_SEC;
		fout << "===========\n"
			 << "INSERT SORT\n"
		 	 << "Xronos: "
		 	 << sec3 << endl;
		 	 
	a.copyArray(b);
		//b.printArray();
		ct0 = clock();
		cout << "Quick...";
	b.quickSort(0,n-1);
		ct1 = clock();
		sec4 = double (ct1-ct0)/CLOCKS_PER_SEC;
		fout << "===========\n"
		 	 << "QUICK SORT\n"
		 	 << "Xronos: "
		 	 << sec4 << endl;	
}
	cout << "FINISHED!" << endl;
	  		  	
	a.freeArrayMem();
	fout.close();
	return 0;
}
