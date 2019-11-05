#include<Windows.h>
#include<stdio.h>//qsort
#include<algorithm>//sort
#include"./time.h"

struct Data {

	UINT Number;
	UINT Score;


};

void ReadData(Data*datas) {

	FILE*file = NULL;
	fopen_s(&file, "./data.txt", "r");

	for (UINT i = 0; i < USHRT_MAX; i++)
		fscanf_s(file, "%d,%d\n", &datas[i].Number, &datas[i].Score);

	fclose(file);


}

void WirteData(Data*datas) {
	FILE*file;
	fopen_s(&file, "ResultData.txt", "w");
	for (UINT i = 0; i < USHRT_MAX; i++)
		fprintf(file, "%d,%d\n", datas[i].Number, datas[i].Score);

	fclose(file);

}

void Swap(Data*a, Data*b) {
	Data temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(Data*datas, int left, int right) {
	int first = left;
	int pivot = datas[first].Score;
	left++;
	while (left <= right) {
		//왼쪽 조건
		while (datas[left].Score <= pivot && left < right) {

			left++;
			//오른쪽 조건
			while (datas[right].Score > pivot&&left <= right) {
				right--;
			}
			if (left < right) {
				Swap(&datas[left], &datas[right]);
			}
			else {
				break;
			}
			
		}
	
	}
	Swap(&datas[first], &datas[right]);
	return right;
}

int Compare(const void*value1, const void*value2) {
	Data*data1 = (Data*)value1;
	Data*data2 = (Data*)value2;
	if (data1->Score > data2->Score)
		return 1;

	else if (data1->Score < data2->Score)
		return -1;
	else
		return 0;
}

void QuickSort(Data*datas, int left, int right) {
	if (left < right) {
		int index = Partition(datas,left, right);

		QuickSort(datas, left, index - 1);
		QuickSort(datas, index + 1, right);
	}
}
bool Compare2(const Data& val, const Data&val2) {

	return val.Score > val.Score;

}
void main() 
{
	Data datas[USHRT_MAX];
	ReadData(datas);

	printf("시간체크\n");
	
	//Timer timer;
	
	//timer.Start(); {
		QuickSort(datas, 0, USHRT_MAX-1);

		WirteData(datas);
	//}

		qsort(datas, USHRT_MAX, sizeof(datas),Compare);

		std::sort(datas, datas + USHRT_MAX, Compare2);
	//timer.End();
	//printf("시간%f\n:",timer.Running());
	system("pause");

}