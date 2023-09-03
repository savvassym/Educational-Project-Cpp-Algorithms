#ifndef PINAKAS_H
#define PINAKAS_H

class Pinakas
{
	private:
		unsigned int *p;		            
		unsigned int  n;    
	public:
		void setArraySize(unsigned int n1); 
		void createArray(); 
		void fillArray();     //100% random
		void fillArraySR();   //50% sorted, 50 % random
		void fillArrayASC();  //Sorted ASC (αυξουσα)
		void fillArrayDESC(); //Sorted DESC (φθινουσα)
		void printArray(); 
		void freeArrayMem(); 
		void copyArray(Pinakas ant);
		void bubbleSort();
		void selectSort();
		void insertSort();
		void quickSort(int left, int right);
};

#endif
