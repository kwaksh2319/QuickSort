#include<Windows.h>
#include<stdio.h>
#include<time.h>
void main() {
	srand((UINT)time(0));

	FILE*file;

	fopen_s(&file, "data.txt", "w");

	for (UINT i = 0; i < USHRT_MAX; i++)//65535->ffff    ff -> 1byte 255
		fprintf(file, "%d,%d\n", i, rand());
	
	fclose(file);
	printf("파일이 생성되있음\n");
	system("pause");
}