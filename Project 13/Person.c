//Person.c
#include <stdio.h>

typedef unsigned short int us;
typedef struct
{
	char name[12];
	us age;
	float height;
	float weight;
} Person;

int main(void)
{
	Person data; // Person �ڷ������� data ������ ������

	printf("������� ������ �Է��ϼ���\n");
	printf("�̸� : ");
	scanf_s("%s", data.name, sizeof(data.name)); //  ����

	printf("���� : ");
	scanf_s("%hu", &data.age); // hu�� unsigned short int ����

	printf("Ű : ");
	scanf_s("%s", data.height);

	printf("������ : ");
	scanf_s("%f", data.weight);

	printf("\n�Է��� ������ ������ �����ϴ�.\n");

	// Ű�� �����Դ� ù° �ڸ������� �����ֱ� ���� %.1f ������ �����
	printf("%s : %d��, %.1fcm, %.1fkg\n");

	return 0;
}