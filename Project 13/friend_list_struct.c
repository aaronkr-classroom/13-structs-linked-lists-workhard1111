#include <stdio.h>

#define MAX_COUNT 5 //친구 등록 가능한 최대 수

typedef char NAME_TYPE[14]; // 13자까지 + NULL무자
typedef unsigned short int US;
typedef struct {
	NAME_TYPE name;
	US age;
	float height;
	float weight;
} Person;

int AddFriend(Person* p_friend, int count) {
	// 입력 가능한 최대 수를 넘었는지 체크함
	if (count < MAX_COUNT) {
		// friend 배열의 count 위치로 이동함
		p_friend = p_friend + count;

		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1. 이름 : ");
		scanf_s("%s", p_friend->name, sizeof(p_friend->name));

		printf("2. 나이 : ");
		scanf_s("%hd", &p_friend->age); // age에 대해 올바른 형식 지정

		printf("3. 키 : ");
		scanf_s("%f", &p_friend->height); // height에 대해 올바른 형식 지정

		printf("4. 몸무게 : ");
		scanf_s("%f", &p_friend->weight); // weight에 대해 올바른 형식 지정

		printf("입력을 완료했습니다.\n");
		return 1;
	}
	else { // 입력 가능한 최대 수를 넘었을 때 오류를 출력함
		printf("최대 인원을 초과하여 입력을 할 수 없습니다.");
		printf("최대 %d명까지만 관리 가능합니다.\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriend(Person* p_friend, int count) {
	if (count > 0) {
		printf("\n등록된 친구 목록\n");
		printf("==========================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s, %3d, %6.2f, %6.2f\n",
				p_friend->name,
				p_friend->age,
				p_friend->height,
				p_friend->weight);
			p_friend++; // 다음 위치에 있는 친구 정보로 주소를 이동하기
		}
		printf("==========================\n");
	}
	else { // 등록된 친구가 없으면 오류를 출력함
		printf("\n등록된 친구가 없습니다!\n\n");
	}
}

int main(void) {
	// 구조체 사용하기
	Person friends[MAX_COUNT];
	int count = 0, menu_num;

	// 무한 루프: 사용자가 3을 누르면 break 문으로 종료시킴
	while (1) {
		// 메뉴를 화면에 출력함
		printf("\t[ 메뉴 ]\t\n");
		printf("\t==========================\t\n");
		printf("1. 친구 추가\n");
		printf("2. 친구 목록 보기\n");
		printf("3. 종료\n");
		printf("\t==========================\t\n");
		printf("번호 선택: \n");
		scanf_s("%d", &menu_num);

		switch (menu_num) {
		case 1:
			/*
			AddFriend 함수가 1을 반환하면 정상적으로
			친구 정보가 추가된 것입니다. 따라서 1을
			반환 했을 때만 등록된 친구 수를 증가시킵니다.
			*/
			if (AddFriend(friends, count))
				count++;
			break;
		case 2:
			ShowFriend(friends, count);  // 수정된 함수 이름
			break;
		case 3:
			break; // while문에서 나가야 겠다....

		default:
			// 번호가 유효하지 않은 경우에 오류 메시지를 출력함
			printf("1~3 번호만 선택할 수 있습니다!!\n\n");
		}
	}

	return 0;
}