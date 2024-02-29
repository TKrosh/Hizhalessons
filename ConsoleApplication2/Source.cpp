#include <stdio.h>
#include <stdlib.h>
/*
// Структура для представления узла списка
struct Node {
	int data; // Данные о ребенке
	Node* next; // Указатель на следующий узел
};

// Функция для создания нового узла
Node* createNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Функция для удаления k-го ребенка из списка
void removeEveryKthChild(Node** tail, int k, FILE* outputFile) {
	Node* current;
	Node* prev = *tail;
	current = prev->next;
	int count = 1;

	while (current->next != current) {
		if (count == k) {
			fprintf(outputFile, "Удален ребенок номер %d\n", current->data);
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
	fprintf(outputFile, "Удален ребенок номер %d\n", current->data);

}

int main() {
	FILE* inputFile;
	fopen_s(&inputFile, "input1.txt", "r");
	FILE* outputFile;
	fopen_s(&outputFile, "output12.txt", "w");
	int n, k;
	fscanf_s(inputFile, "%d %d", &n, &k);

	// Создаем циклический список из n ребят
	Node* head = createNode(1);
	Node* current = head;
	for (int i = 2; i <= n; i++) {
		current->next = createNode(i);
		current = current->next;
	}

	current->next = head; // Замыкаем круг
	// Удаляем каждого k-го ребенка
	removeEveryKthChild(&current, k, outputFile);
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}
*/