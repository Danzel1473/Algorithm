#include <iostream>

// ���� ���� �Լ�
void InsertionSort(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		int keyValue = array[i];
		int j = i - 1;

		// ���ø�
		while (j >= 0 && array[j] > keyValue)
		{
			array[j + 1] = array[j];
			--j;
		}

		//�� �����
		array[j + 1] = keyValue;

	}

}

// �迭 ��� �Լ�
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << (i < length - 1 ? ", " : "\n");
	}
}

int main()
{
	int array[] = { 5,2,8,4,1,2,3,1,6,10,14,6,22,51 };
	int length = sizeof(array) / sizeof(int);

	PrintArray(array, length);

	InsertionSort(array, length);

	PrintArray(array, length);
}