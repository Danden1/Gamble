#include <stdio.h.>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void cointhrow(int *coin);			//동전던지기
void lotto(int * coin);				//로또
void rsp(int *coin);				//가위바위보
void error();						//오류
void check(int * coin);				//동전 개수가 0일 경우 종료시킴
void rock(int **coin, int num);		//플레이어가 주먹을 냈을 경우
void scissors(int **coin, int num);	//플레이어가 가위를 냈을 경우
void paper(int **coin, int num);	//플레이어가 보자기를 냈을 경우

int main() {
	int coin = 5;	//처음 코인 개수 5개
	int a;
	srand((unsigned)time(NULL));

	while (1) {
		check(&coin);
		printf("===================================도박게임=====================================\n");
		printf("1. 동전 던지기(코인 1 소모)\t");			printf("=================\n");
		printf("2. 복권(코인 3소모)        \t");			printf("||코인 개 수: %d||\n", coin);
		printf("3. 가위바위보(코인 2소모)  \t");			printf("=================\n");
		printf("4. 종료\n");
		printf("================================================================================\n\n");

		scanf_s("%d", &a);
		while (getchar() != '\n');

		switch (a) {
		case 1:
			cointhrow(&coin);	//동전던지기
			break;

		case 2:
			lotto(&coin);		//복권
			break;

		case 3:
			rsp(&coin);			//가위바위보
			break;

		case 4:
			return 0;			//종료

		default:
			error();			//1~4가 아닌 수 입력.
			break;
		}


	}

}



void cointhrow(int *coin) {		//동전던지기

	int num, gamble;

	
	printf("\n\n-1코인...\n\n");
	printf("동전의 앞 면이 나올지 뒷 면이 나올지 선택 해주세요. 맞추면 코인을 2개 드립니다.\n");
	printf("0. 앞면\n");
	printf("1. 뒷면\n");

	scanf_s("%d", &gamble);			//앞면, 뒷면 입력
	while (getchar() != '\n');

	if (gamble == 0 || gamble == 1) {		
		*coin -= 1;
		num = rand() % 2;
		
		printf("\n");
		printf("3\n"); Sleep(1000); printf("2\n"); Sleep(1000); printf("1\n\n"); Sleep(1000);

		printf("\n\n 띠리링~~~!\n\n");
		Sleep(2000);

		if (num == 0) {
			printf("동전은 앞면이 나왔습니다!\n");
			Sleep(2000);
		}
		else {
			printf("뒷면이 나왔습니다!\n");
			Sleep(2000);
		}

		if (num == gamble) {
			printf("축하합니다! 2코인을 얻었습니다.\n\n");
			Sleep(2000);
			*coin += 2;
			return;
		}
		else {
			printf("코인을 잃었습니다...\n\n");
			Sleep(1000);
			return;
		}

	}
	else {		
		printf("\n앞면이랑 뒷면 중에서 선택해주세요. 처음으로 돌아갑니다.(코인은 다시 돌려줄게요.)\n\n");
		Sleep(1000);
		return;
	}

}

void lotto(int *coin) {		//복권

	int num[5], gamble[5];
	int count = 0, i =0, a= 0, tmp =0;

	if (*coin < 3) {
		printf("\n\n코인이 부족합니다. 처음으로 돌아갑니다.\n\n");
		Sleep(1000);
		return;
	}
	

	printf("\n\n-3코인...\n\n");
	printf("0~20 까지 숫자 중에서 5번 써주세요.(숫자 중복X)\n");
	printf("일치 숫자 1개 : +2, 일치 숫자 2개 : +6, 일치 숫자 3개 : +15, 일치 숫자 4개 : +35\n ");
	printf("전부 맞추면 +60!!!!\n");
	
	while (1) {
		for (i = 0; i < 5; i++) {

			scanf_s("%d", &gamble[i]);
			while (getchar() != '\n');
		
			if (gamble[i] > 0 && gamble[i] < 21) {}

			else {
				printf("1~20까지 숫자 입력하세요!!(3코인은 돌려줄게요)\n\n");
				Sleep(1000);
				return;
			}
		}

		for (i = 0; i < 4;i++) {		//중복 방지
			for (int s = i+1; s < 5; s++) {
				if (gamble[i] == gamble[s]) {
					printf("중복된 숫자를 입력했습니다. 처음으로 돌아갑니다.\n\n");
					return;
				}
			}
		}
		break;
	}


	*coin -= 3;

	while (1) {

		tmp = 0;

		for (i = 0; i < 5; i++) {
			num[i] = rand() % 21;
		}

		for (i = 0; i < 4; i++) {		//중복 방지
			for (int s = i + 1; s < 5; s++) {
				if (num[i] == num[s])
					tmp += 1;
			}
		}
		if (tmp > 0) {
			continue;
		}
		break;
		
	}

	for (i = 0; i < 5; i++) {			//숫자 일치확인
		for (int j = 0; j < 5; j++) {
			if (num[i] == gamble[j]) {
				count += 1;
			}
		}
	}
	
	printf("\n======================");
	printf("\n복권 번호 공개!!\n");
	printf("======================\n");
	
	for (int i = 0; i < 5; i++) {
		Sleep(1000);	printf("%d\t", num[i]);
	}
	
	printf("\n");
	Sleep(2000);

	printf("당신이 선택한 숫자들은\n");
	
	for (int i = 0; i < 5; i++) {
		Sleep(1000);	printf("%d\t", gamble[i]);
	}
	printf("\n\n");
	Sleep(2000);

	switch (count) {
		case 0:
			printf("당신이 맞춘 숫자는 0개\n");
			Sleep(1000);
			printf("코인을 잃었습니다...\n\n");
			Sleep(2000);
			return;
			break;
		case 1:
			printf("당신이 맞춘 숫자는 1개\n");
			Sleep(1000);
			printf("코인을 2개 얻었습니다.(그러나 손해)\n\n");
			Sleep(2000);
			*coin += 2;
			return;
			break;
		case 2:
			printf("당신이 맞춘 숫자는 2개\n");
			Sleep(1000);
			printf("코인을 6개 얻었습니다.\n\n");
			Sleep(2000);
			*coin += 6;
			return;
			break;
		case 3:
			printf("당신이 맞춘 숫자는 3개\n");
			Sleep(1000);
			printf("코인을 15개 얻었습니다.\n\n");
			Sleep(2000);
			*coin += 15;
			return;
			break;
		case 4:
			printf("당신이 맞춘 숫자는 4개\n");
			Sleep(1000);
			printf("코인을 35개 얻었습니다.\n\n");
			Sleep(2000);
			*coin += 35;
			return;
			break;
		case 5:
			printf("★☆★☆★☆★☆★☆\n");
			printf("모든 숫자를 맞췄습니다!!!\n");
			printf("★☆★☆★☆★☆★☆\n");
			Sleep(1000);
			printf("★대박★코인을 60개 얻었습니다!!\n\n");
			Sleep(2000);
			*coin += 60;
			return;
			break;
	}


}

void rsp(int *coin) {		//가위바위보
	int num, gamble;

	if (*coin < 2) {
		printf("\n\n코인이 부족합니다. 처음으로 돌아갑니다.\n\n");
		Sleep(1000);
		return;
	}

	printf("\n\n-2 코인...\n\n");
	printf("가위바위보를 시작하겠습니다~~\n\n");
	printf("지면 코인 +0,비기면 코인 +1, 이기면 코인 +4\n");
	printf("0. 주먹  1. 가위  2. 보자기\n");
	printf("무엇을 내시겠습니까?\n");

	scanf_s("%d", &gamble);
	while (getchar() != '\n');




	if (gamble > -1 && gamble < 3) {
		*coin -= 2;

		num = rand()%3;
		printf("\n");
		printf("3\n"); Sleep(1000); printf("2\n"); Sleep(1000); printf("1\n\n"); Sleep(1000);

		if (gamble == 0) {
			rock(&coin, num);
			return;
		}

		else if (gamble == 1) {
			scissors(&coin, num);
			return;
		}

		else if (gamble == 2) {
			paper(&coin, num);
			return;
		}

	}
	else {
		printf("주먹, 가위, 보자기 중 하나를 내세요! 처음으로 돌아갑니다.(코인은 다시 돌려줄게요.)\n\n");
		Sleep(1000);
		return;
	}


}

void rock(int **coin, int num) {		//플레이어가 주먹을 냈을 경우

	if (num == 0) {
		printf("나 : 주먹\t\t"); printf("상대 : 주먹\n");
		Sleep(1000);
		printf("비겼습니다!(+1 코인, 하지만 손해)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}
	else if (num == 1) {
		printf("나 : 주먹\t\t"); printf("상대 : 가위\n");
		Sleep(1000);
		printf("이겼습니다!(+4 코인)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}
	else if (num == 2) {
		printf("나 : 주먹\t\t"); printf("상대 : 보자기\n");
		Sleep(1000);
		printf("졌습니다!(+0 코인)\n\n");
		Sleep(2000);
		return;
	}


}

void scissors(int **coin, int num) {		//플레이어가 가위를 냈을 경우

	if (num == 0) {
		printf("나 : 가위\t\t"); printf("상대 : 주먹\n");
		Sleep(1000);
		printf("졋습니다!(+0 코인)\n\n");
		Sleep(2000);
		return;
	}
	else if (num == 1) {
		printf("나 : 가위\t\t"); printf("상대 : 가위\n");
		Sleep(1000);
		printf("비겼습니다!(+1 코인, 하지만 손해)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}
	else if (num == 2) {
		printf("나 : 가위\t\t"); printf("상대 : 보자기\n");
		Sleep(1000);
		printf("이겻습니다!(+4 코인)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}


}

void paper(int **coin, int num) {		//플레이어가 보자기 냈을 경우

	if (num == 0) {
		printf("나 : 보자기\t\t"); printf("상대 : 주먹\n");
		Sleep(1000);
		printf("이겼습니다!(+4 코인)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}
	else if (num == 1) {
		printf("나 : 보자기\t\t"); printf("상대 : 가위\n");
		Sleep(1000);
		printf("졌습니다!(+0 코인)\n\n");
		Sleep(2000);
		return;
	}
	else if (num == 2) {
		printf("나 : 보자기\t\t"); printf("상대 : 보자기\n");
		Sleep(1000);
		printf("비겼습니다!(+1 코인, 하지만 손해)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}


}

void error() {
	printf("1~4까지 입력해주세요.\n\n");
	return;
}

void check(int *coin) {		//코인 있는지 없는지 확인

	if (*coin == 0) {
		printf("코인이 없습니다. 게임을 종료합니다.\n");
		Sleep(2000);
		exit(0);
	}

	return;
}

