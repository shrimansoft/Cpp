#include<iostream>

using namespace std;

int partition(int arr[],int low,int high)
{
	int i=low-1;
	int temp;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<arr[high])
		{
			i++;
			temp=arr[j];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	
	return i+1;
}

void Quick_Sort(int arr[], int low,int high)
{
	if(low<high)
	{
		int pi = partition(arr,low,high);
		
		Quick_Sort(arr,pi+1,high);
		Quick_Sort(arr,low,pi-1);
	}
}


int main()
{
	int Arr[11]={8,3,4,1,10,9,6,7,2,0,5};
	Quick_Sort(Arr,0,10);
	//partition(Arr,0,10);


	for(int i=0;i<11;i++)
		cout<<Arr[i]<<endl;
}
