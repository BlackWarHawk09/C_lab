#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int *read_file(char* adress, size_t* len);
void write_f_in(char* adress);

int main()
{
	char file_in_path[] = "C:\\Users\\Heliodoros\\source\\repos\\L5_C\\in_m.txt";
	size_t l;
	size_t* len = &l;
	int i = 0;
	write_f_in(file_in_path);
	int *arr = read_file(file_in_path, len);
    printf("\nArray from file: \n");
	for (i = 0; i < *len; i++) 
		 printf("%d ", arr[i]);
	printf("\n");
	if (arr != 0)
	free(arr);
	system("pause");
	return 0;
}

void write_f_in(char* address)
{
	int n = 10000, i, r;
	FILE* arr_in;
	arr_in = fopen(address, "w");
	if (arr_in != 0)
	{
		fprintf(arr_in, "10000 elements: \n");
		for (i = 0; i < n; n++)
		{
			r = rand() % 100;
			fprintf(arr_in, "%d ", r);
		}
    }
	else 
		printf("Error write_from_user\n");
}

int *read_file(char* address, size_t* len)
{
	FILE* f_in;
	f_in = fopen(address, "r");
	int* arr = 0;
	if (f_in !=  0 )
	{
		fscanf(f_in, "%d", len);
		int i = 0;
		arr = (int*)calloc(*len, sizeof(int));
		while (i < *len)
		{
			fscanf(f_in, "%d", &arr[i]);
			i++;
		}
		fclose(f_in);
		return arr;
	}   
	return 0;
}  

double* arr_copy(double *a, int len);

void write_in_f(char *address);

double* read_file(char *address, int *len);

void write_out_f(char* address, int len, double* arr);

//double* selection_sort(double *arr, int l);

int main()
{
	double start = clock();
	char file_in_path[] = "D:\\in.txt";
	char file_out_path[] = "D:\\out.txt";
	int l;
	int* len = &l;
	int i = 0;
	write_in_f(file_in_path);
	double *arr = read_file(file_in_path, len);
	printf("\nArray from file: \n");
	for (i = 0; i<*len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	double *a = 0;
	a = selection_sort(a, *len);
	write_out_f(file_out_path, *len, a);
	if (arr != NULL)
		free(arr);
	double end = clock();
	printf_s("Runtime %lf\n", (end - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}

void write_in_f(char *address)
{
	int n = 10000, i, r;
	FILE* in_f;
	in_f = fopen(address, "w");
	if (in_f)
	{
		fprintf(in_f, "10000\n");
		for (i = 0; i < n; i++)
		{
			r = rand() % 100;
			fprintf(in_f, "%d ", r);
		}
	}
	else
		printf("Couldn't read file.\n");
}

double* read_file(char *address, int* len)
{
	FILE* in_f;
	in_f = fopen(address, "r");
	double *arr = 0;
	if (in_f)
	{
		fscanf(in_f, "%d", len);
		int i = 0;
		arr = (double*)calloc(*len, sizeof(double));
		while (i<*len)
		{
			fscanf(in_f, "%d", &arr[i]);
			i++;
		}
		fclose(in_f);
		return arr;
	}
	printf("Error in_f\n");
	return 0;
}

double* selection_sort(double *arr, double *a, int len)
{
	a = arr_copy(a, len);
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		double b = a[i];
		a[i] = a[min];
		a[min] = b;
	}
	return a;
}

double* arr_copy(double* a, int len)
{
	double* arr = (double*)calloc(len, sizeof(double));
	int i = 0;
	for (i; i < len; i++)
	{
		arr[i] = a[i];
	}
	return arr;
}

void write_out_f(char* address, int len, double* arr)
{
	int i = 0;
	FILE* f_out;
	f_out = fopen(address, "w");
	if (f_out)
	{
		for (i = 0; i < len; i++)
			fprintf(f_out, "%d ", arr[i]);
		fclose(f_out);
		printf("\nArray sorted: \n");
		for (i = 0; i<len; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
		printf("Error f_out\n");
}