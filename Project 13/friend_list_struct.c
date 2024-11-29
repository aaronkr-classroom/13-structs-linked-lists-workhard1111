#include <stdio.h>

#define MAX_COUNT 5 //ģ�� ��� ������ �ִ� ��

typedef char NAME_TYPE[14]; // 13�ڱ��� + NULL����
typedef unsigned short int US;
typedef struct {
	NAME_TYPE name;
	US age;
	float height;
	float weight;
} Person;

int AddFriend(Person* p_friend, int count) {
	// �Է� ������ �ִ� ���� �Ѿ����� üũ��
	if (count < MAX_COUNT) {
		// friend �迭�� count ��ġ�� �̵���
		p_friend = p_friend + count;

		printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
		printf("1. �̸� : ");
		scanf_s("%s", p_friend->name, sizeof(p_friend->name));

		printf("2. ���� : ");
		scanf_s("%hd", &p_friend->age); // age�� ���� �ùٸ� ���� ����

		printf("3. Ű : ");
		scanf_s("%f", &p_friend->height); // height�� ���� �ùٸ� ���� ����

		printf("4. ������ : ");
		scanf_s("%f", &p_friend->weight); // weight�� ���� �ùٸ� ���� ����

		printf("�Է��� �Ϸ��߽��ϴ�.\n");
		return 1;
	}
	else { // �Է� ������ �ִ� ���� �Ѿ��� �� ������ �����
		printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�.");
		printf("�ִ� %d������� ���� �����մϴ�.\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriend(Person* p_friend, int count) {
	if (count > 0) {
		printf("\n��ϵ� ģ�� ���\n");
		printf("==========================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s, %3d, %6.2f, %6.2f\n",
				p_friend->name,
				p_friend->age,
				p_friend->height,
				p_friend->weight);
			p_friend++; // ���� ��ġ�� �ִ� ģ�� ������ �ּҸ� �̵��ϱ�
		}
		printf("==========================\n");
	}
	else { // ��ϵ� ģ���� ������ ������ �����
		printf("\n��ϵ� ģ���� �����ϴ�!\n\n");
	}
}

int main(void) {
	// ����ü ����ϱ�
	Person friends[MAX_COUNT];
	int count = 0, menu_num;

	// ���� ����: ����ڰ� 3�� ������ break ������ �����Ŵ
	while (1) {
		// �޴��� ȭ�鿡 �����
		printf("\t[ �޴� ]\t\n");
		printf("\t==========================\t\n");
		printf("1. ģ�� �߰�\n");
		printf("2. ģ�� ��� ����\n");
		printf("3. ����\n");
		printf("\t==========================\t\n");
		printf("��ȣ ����: \n");
		scanf_s("%d", &menu_num);

		switch (menu_num) {
		case 1:
			/*
			AddFriend �Լ��� 1�� ��ȯ�ϸ� ����������
			ģ�� ������ �߰��� ���Դϴ�. ���� 1��
			��ȯ ���� ���� ��ϵ� ģ�� ���� ������ŵ�ϴ�.
			*/
			if (AddFriend(friends, count))
				count++;
			break;
		case 2:
			ShowFriend(friends, count);  // ������ �Լ� �̸�
			break;
		case 3:
			break; // while������ ������ �ڴ�....

		default:
			// ��ȣ�� ��ȿ���� ���� ��쿡 ���� �޽����� �����
			printf("1~3 ��ȣ�� ������ �� �ֽ��ϴ�!!\n\n");
		}
	}

	return 0;
}