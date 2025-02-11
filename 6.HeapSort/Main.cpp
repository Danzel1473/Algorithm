#include <iostream>
#include <vector>
// �� ����� (Heapify) �Լ�
void Heapify(std::vector<int>& array, int length, int i)
{
	while (true)
	{
		// �� ������ ���� �ε���
		int largest = i;
		
		// ���� �ڼ� �ε���
		int left = 2 * i + 1;

		// ������ �ڼ� �ε���
		int right = 2 * i + 2;
	
		if (left < length && array[left] > array[largest])
		{
			largest = left;
		}
		if (right < length && array[right] > array[largest])
		{
			largest = right;
		}
		
		if (largest == i) break;

		std::swap(array[i], array[largest]);
		i = largest;
	}
}

// �� ���� �Լ� (HeapSort)
void HeapSort(std::vector<int>& array)
{
	// ��ü ũ��
	int length = (int)array.size();

	for (int i = length / 2 - 1; i >= 0; --i)
	{
		// �� �����
		Heapify(array, length, i);
	}

	// ����
	for (int i = length - 1; i > 0; --i)
	{
		std::swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}

void PrintArray(std::vector<int>& array)
{
	for (int ix = 0; ix < array.size(); ++ix)
	{
		std::cout << array[ix];
		if (ix < array.size() - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	std::vector<int> array = { 5, 8, 1, 3, 124, 179, 12, 231, 4, 125, 13, 34, 5321, 8, 44, 56, 37624, 9, 31 };

	// ���� �� ���
	std::cout << "���� ��: ";
	PrintArray(array);

	HeapSort(array);

	std::cout << "���� ��: ";
	PrintArray(array);

	HeapSort(array);
}