#include "Pinakas.h"
#include "RandMT.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void  Pinakas::setArraySize(unsigned int  n1)
{	
	n = n1;
}
void  Pinakas::createArray() 
{
	p = new unsigned int[n];
}
void  Pinakas::fillArray() //100% random
{
	RandMT myRandom;
	int i;
	RandMT(time(NULL));
	
	for(i=0; i<n; i++)
	{
		p[i] = myRandom();
	}
}
void  Pinakas::fillArraySR() //50% sorted, 50 % random
{
	RandMT myRandom;
	int j,i,mid;
	mid=(n-1)/2;
	RandMT(time(NULL));
	for(i=0;i<=mid;i++)
	{
		p[i]=i*10;
	}
	for(j=mid+1;j<n;j++)
	{
		p[j]=myRandom();
	}		
}
void  Pinakas::fillArrayASC() //Sorted ASC (αυξουσα)
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=i*10;
	}	
}
void  Pinakas::fillArrayDESC() //Sorted DESC (φθινουσα)
{
	int j,i,temp;
	 
	for(i=0;i<n;i++)
	{
		p[i]=i*10;
	}
	j=i-1;
	i=0;
    while(i<j)
    {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
    	i++;
    	j--;
   }
}

void  Pinakas::printArray()
{	
	int i;
	for(i=0; i<n; i++)
	
		cout << p[i] << " ";
    
	cout << endl;
}
void  Pinakas::freeArrayMem()
{ 
	delete []p;
}
void Pinakas::copyArray(Pinakas ant)
{
	int i;
	for(i=0; i<n; i++)
		ant.p[i] = p[i];
}
void Pinakas::bubbleSort()
{
	int temp,i,j;
	for(i=1; i<n; i++)
	{   
		for(j=n-1; j>=i; j--)             
		if(p[j-1] > p[j])              
		{
			temp = p[j-1];
			p[j-1] = p[j];
			p[j] = temp;
		}
	}
}
void Pinakas::selectSort()
{
	int i,k,j,min;
	for(i=0;i<n-1;i++)
	{
		k=i;
		min=p[i];
		for(j=i+1;j<n;j++)
		{
			if(p[j]<min)
			{
				k=j;
				min=p[j];
			}
		}
		p[k]=p[i];
		p[i]=min;
	}  	
}
void Pinakas::insertSort()
{
	int i,j,x;
	
	for(i=1; i<n; i++)
 	{
 		x = p[i];
 		j = i-1;
 	while( j>=0 &&
		p[j]>x)
 		{
 			p[j+1] = p[j];
 			j = j-1;
 		}
 		p[j+1] = x;
 	} 
}	
void Pinakas::quickSort(int left, int right)
{
int i, j, mid, x;

if(left < right)
 	{
 	i = left;
 	j = right;
 	mid = (left+right)/2;
 	x = p[mid];
 	while(i < j)
 		{
 		while(p[i] < x)
 			i++;
 		while(p[j] > x)
 			j--;
 		if(i < j)
 			{
 			if(p[i] == p[j]) //if equal elements
 				{
 				if(i < mid)
 					i++;
 				if(j > mid)
 					j--;
 				}
 				else // if different elements, swap
 				{
 					swap(p[i],p[j]);
 				}
 			} // if(i<j)
 		} //while(i<j)
 		quickSort(left,j-1);
 		quickSort(j+1,right);
 		} 
}

