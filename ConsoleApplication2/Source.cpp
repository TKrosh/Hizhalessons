#include <stdio.h>
#include <stdlib.h>
/*
// ��������� ��� ������������� ���� ������
struct Node {
	int data; // ������ � �������
	Node* next; // ��������� �� ��������� ����
};

// ������� ��� �������� ������ ����
Node* createNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// ������� ��� �������� k-�� ������� �� ������
void removeEveryKthChild(Node** tail, int k, FILE* outputFile) {
	Node* current;
	Node* prev = *tail;
	current = prev->next;
	int count = 1;

	while (current->next != current) {
		if (count == k) {
			fprintf(outputFile, "������ ������� ����� %d\n", current->data);
			prev->next = current->next;
			current = current->next;
			count = 1;
		}
		else {
			prev = current;
			current = current->next;
			count++;
		}
	}
	fprintf(outputFile, "������ ������� ����� %d\n", current->data);

}

int main() {
	FILE* inputFile;
	fopen_s(&inputFile, "input1.txt", "r");
	FILE* outputFile;
	fopen_s(&outputFile, "output12.txt", "w");
	int n, k;
	fscanf_s(inputFile, "%d %d", &n, &k);

	// ������� ����������� ������ �� n �����
	Node* head = createNode(1);
	Node* current = head;
	for (int i = 2; i <= n; i++) {
		current->next = createNode(i);
		current = current->next;
	}

	current->next = head; // �������� ����
	// ������� ������� k-�� �������
	removeEveryKthChild(&current, k, outputFile);
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}
*/