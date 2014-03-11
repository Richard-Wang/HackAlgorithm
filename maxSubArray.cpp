#include<iostream>
#include<stdlib.h>
using namespace std;

int maxSubArray( int a[], int size, int &SmaxSubArrrayIndex, int &EmaxSubArrayIndex )
{
	if( size < 1)
	{
		cout<<"Array size error"<<endl;
		return -1;
	}
	int sum = 0, curArrayIndex = 0, max = -99999999;
	bool Sflag = false;
	while( curArrayIndex < size )
	{
		sum += a[curArrayIndex];
		if( sum > max )
		{
			max = sum;
			if( Sflag )
			{
				SmaxSubArrrayIndex = EmaxSubArrayIndex = curArrayIndex;
				Sflag = false;
			}
			else
			{
				EmaxSubArrayIndex= curArrayIndex;
			}
			if( sum < 0 )
			{
				sum = 0;
				Sflag = true;
			}
		}
		else if( sum < 0 )
		{
			sum = 0;
			Sflag = true;
		}
		curArrayIndex++;
	}

	return max;
}

int main(void)
{
	int sumOfmaxSubArray = 0, startIndexOfmaxSubArrray = 0, endIndexOfmaxSubArrray = 0; 
	int	array[50], inputNum, arrayLen =0;
	
	cout<<"Please input array, end of 8888: ";
	cin>>inputNum;
	while( inputNum != 8888 )
	{
		array[arrayLen] = inputNum;
		arrayLen++;
		cin>>inputNum;
	}
	sumOfmaxSubArray = maxSubArray( array, arrayLen, startIndexOfmaxSubArrray, endIndexOfmaxSubArrray );
	cout<<"The max subArray is: ";
	for( int i = startIndexOfmaxSubArrray; i < endIndexOfmaxSubArrray + 1; i++ )
	{
		cout<<array[i]<<" ";
	}
	cout<<endl<<"The sum of max subArray is: "<<sumOfmaxSubArray<<endl;
		
	return 0;
}
