#include <stdio.h.>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void cointhrow(int *coin);			//����������
void lotto(int * coin);				//�ζ�
void rsp(int *coin);				//����������
void error();						//����
void check(int * coin);				//���� ������ 0�� ��� �����Ŵ
void rock(int **coin, int num);		//�÷��̾ �ָ��� ���� ���
void scissors(int **coin, int num);	//�÷��̾ ������ ���� ���
void paper(int **coin, int num);	//�÷��̾ ���ڱ⸦ ���� ���

int main() {
	int coin = 5;	//ó�� ���� ���� 5��
	int a;
	srand((unsigned)time(NULL));

	while (1) {
		check(&coin);
		printf("===================================���ڰ���=====================================\n");
		printf("1. ���� ������(���� 1 �Ҹ�)\t");			printf("=================\n");
		printf("2. ����(���� 3�Ҹ�)        \t");			printf("||���� �� ��: %d||\n", coin);
		printf("3. ����������(���� 2�Ҹ�)  \t");			printf("=================\n");
		printf("4. ����\n");
		printf("================================================================================\n\n");

		scanf_s("%d", &a);
		while (getchar() != '\n');

		switch (a) {
		case 1:
			cointhrow(&coin);	//����������
			break;

		case 2:
			lotto(&coin);		//����
			break;

		case 3:
			rsp(&coin);			//����������
			break;

		case 4:
			return 0;			//����

		default:
			error();			//1~4�� �ƴ� �� �Է�.
			break;
		}


	}

}



void cointhrow(int *coin) {		//����������

	int num, gamble;

	
	printf("\n\n-1����...\n\n");
	printf("������ �� ���� ������ �� ���� ������ ���� ���ּ���. ���߸� ������ 2�� �帳�ϴ�.\n");
	printf("0. �ո�\n");
	printf("1. �޸�\n");

	scanf_s("%d", &gamble);			//�ո�, �޸� �Է�
	while (getchar() != '\n');

	if (gamble == 0 || gamble == 1) {		
		*coin -= 1;
		num = rand() % 2;
		
		printf("\n");
		printf("3\n"); Sleep(1000); printf("2\n"); Sleep(1000); printf("1\n\n"); Sleep(1000);

		printf("\n\n �츮��~~~!\n\n");
		Sleep(2000);

		if (num == 0) {
			printf("������ �ո��� ���Խ��ϴ�!\n");
			Sleep(2000);
		}
		else {
			printf("�޸��� ���Խ��ϴ�!\n");
			Sleep(2000);
		}

		if (num == gamble) {
			printf("�����մϴ�! 2������ ������ϴ�.\n\n");
			Sleep(2000);
			*coin += 2;
			return;
		}
		else {
			printf("������ �Ҿ����ϴ�...\n\n");
			Sleep(1000);
			return;
		}

	}
	else {		
		printf("\n�ո��̶� �޸� �߿��� �������ּ���. ó������ ���ư��ϴ�.(������ �ٽ� �����ٰԿ�.)\n\n");
		Sleep(1000);
		return;
	}

}

void lotto(int *coin) {		//����

	int num[5], gamble[5];
	int count = 0, i =0, a= 0, tmp =0;

	if (*coin < 3) {
		printf("\n\n������ �����մϴ�. ó������ ���ư��ϴ�.\n\n");
		Sleep(1000);
		return;
	}
	

	printf("\n\n-3����...\n\n");
	printf("0~20 ���� ���� �߿��� 5�� ���ּ���.(���� �ߺ�X)\n");
	printf("��ġ ���� 1�� : +2, ��ġ ���� 2�� : +6, ��ġ ���� 3�� : +15, ��ġ ���� 4�� : +35\n ");
	printf("���� ���߸� +60!!!!\n");
	
	while (1) {
		for (i = 0; i < 5; i++) {

			scanf_s("%d", &gamble[i]);
			while (getchar() != '\n');
		
			if (gamble[i] > 0 && gamble[i] < 21) {}

			else {
				printf("1~20���� ���� �Է��ϼ���!!(3������ �����ٰԿ�)\n\n");
				Sleep(1000);
				return;
			}
		}

		for (i = 0; i < 4;i++) {		//�ߺ� ����
			for (int s = i+1; s < 5; s++) {
				if (gamble[i] == gamble[s]) {
					printf("�ߺ��� ���ڸ� �Է��߽��ϴ�. ó������ ���ư��ϴ�.\n\n");
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

		for (i = 0; i < 4; i++) {		//�ߺ� ����
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

	for (i = 0; i < 5; i++) {			//���� ��ġȮ��
		for (int j = 0; j < 5; j++) {
			if (num[i] == gamble[j]) {
				count += 1;
			}
		}
	}
	
	printf("\n======================");
	printf("\n���� ��ȣ ����!!\n");
	printf("======================\n");
	
	for (int i = 0; i < 5; i++) {
		Sleep(1000);	printf("%d\t", num[i]);
	}
	
	printf("\n");
	Sleep(2000);

	printf("����� ������ ���ڵ���\n");
	
	for (int i = 0; i < 5; i++) {
		Sleep(1000);	printf("%d\t", gamble[i]);
	}
	printf("\n\n");
	Sleep(2000);

	switch (count) {
		case 0:
			printf("����� ���� ���ڴ� 0��\n");
			Sleep(1000);
			printf("������ �Ҿ����ϴ�...\n\n");
			Sleep(2000);
			return;
			break;
		case 1:
			printf("����� ���� ���ڴ� 1��\n");
			Sleep(1000);
			printf("������ 2�� ������ϴ�.(�׷��� ����)\n\n");
			Sleep(2000);
			*coin += 2;
			return;
			break;
		case 2:
			printf("����� ���� ���ڴ� 2��\n");
			Sleep(1000);
			printf("������ 6�� ������ϴ�.\n\n");
			Sleep(2000);
			*coin += 6;
			return;
			break;
		case 3:
			printf("����� ���� ���ڴ� 3��\n");
			Sleep(1000);
			printf("������ 15�� ������ϴ�.\n\n");
			Sleep(2000);
			*coin += 15;
			return;
			break;
		case 4:
			printf("����� ���� ���ڴ� 4��\n");
			Sleep(1000);
			printf("������ 35�� ������ϴ�.\n\n");
			Sleep(2000);
			*coin += 35;
			return;
			break;
		case 5:
			printf("�ڡ١ڡ١ڡ١ڡ١ڡ�\n");
			printf("��� ���ڸ� ������ϴ�!!!\n");
			printf("�ڡ١ڡ١ڡ١ڡ١ڡ�\n");
			Sleep(1000);
			printf("�ڴ�ڡ������� 60�� ������ϴ�!!\n\n");
			Sleep(2000);
			*coin += 60;
			return;
			break;
	}


}

void rsp(int *coin) {		//����������
	int num, gamble;

	if (*coin < 2) {
		printf("\n\n������ �����մϴ�. ó������ ���ư��ϴ�.\n\n");
		Sleep(1000);
		return;
	}

	printf("\n\n-2 ����...\n\n");
	printf("������������ �����ϰڽ��ϴ�~~\n\n");
	printf("���� ���� +0,���� ���� +1, �̱�� ���� +4\n");
	printf("0. �ָ�  1. ����  2. ���ڱ�\n");
	printf("������ ���ðڽ��ϱ�?\n");

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
		printf("�ָ�, ����, ���ڱ� �� �ϳ��� ������! ó������ ���ư��ϴ�.(������ �ٽ� �����ٰԿ�.)\n\n");
		Sleep(1000);
		return;
	}


}

void rock(int **coin, int num) {		//�÷��̾ �ָ��� ���� ���

	if (num == 0) {
		printf("�� : �ָ�\t\t"); printf("��� : �ָ�\n");
		Sleep(1000);
		printf("�����ϴ�!(+1 ����, ������ ����)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}
	else if (num == 1) {
		printf("�� : �ָ�\t\t"); printf("��� : ����\n");
		Sleep(1000);
		printf("�̰���ϴ�!(+4 ����)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}
	else if (num == 2) {
		printf("�� : �ָ�\t\t"); printf("��� : ���ڱ�\n");
		Sleep(1000);
		printf("�����ϴ�!(+0 ����)\n\n");
		Sleep(2000);
		return;
	}


}

void scissors(int **coin, int num) {		//�÷��̾ ������ ���� ���

	if (num == 0) {
		printf("�� : ����\t\t"); printf("��� : �ָ�\n");
		Sleep(1000);
		printf("�����ϴ�!(+0 ����)\n\n");
		Sleep(2000);
		return;
	}
	else if (num == 1) {
		printf("�� : ����\t\t"); printf("��� : ����\n");
		Sleep(1000);
		printf("�����ϴ�!(+1 ����, ������ ����)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}
	else if (num == 2) {
		printf("�� : ����\t\t"); printf("��� : ���ڱ�\n");
		Sleep(1000);
		printf("�̰���ϴ�!(+4 ����)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}


}

void paper(int **coin, int num) {		//�÷��̾ ���ڱ� ���� ���

	if (num == 0) {
		printf("�� : ���ڱ�\t\t"); printf("��� : �ָ�\n");
		Sleep(1000);
		printf("�̰���ϴ�!(+4 ����)\n\n");
		Sleep(2000);
		**coin += 4;
		return;
	}
	else if (num == 1) {
		printf("�� : ���ڱ�\t\t"); printf("��� : ����\n");
		Sleep(1000);
		printf("�����ϴ�!(+0 ����)\n\n");
		Sleep(2000);
		return;
	}
	else if (num == 2) {
		printf("�� : ���ڱ�\t\t"); printf("��� : ���ڱ�\n");
		Sleep(1000);
		printf("�����ϴ�!(+1 ����, ������ ����)\n\n");
		Sleep(2000);
		**coin += 1;
		return;
	}


}

void error() {
	printf("1~4���� �Է����ּ���.\n\n");
	return;
}

void check(int *coin) {		//���� �ִ��� ������ Ȯ��

	if (*coin == 0) {
		printf("������ �����ϴ�. ������ �����մϴ�.\n");
		Sleep(2000);
		exit(0);
	}

	return;
}

