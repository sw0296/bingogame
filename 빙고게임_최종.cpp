#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int Map[25];
	int inputnum;
	int c_star, r_star;
	int diagonal_star;
	int STAR = 0;
	int bingocount = 0;
	int gamemode;
	bool isFirst = true;
	bool changeline = false;
	int ComMap[25];
	int com_c, com_r;
	int com_diagonal;
	int com_bingo = 0;
	int notinput[25];
	int notinputcount;
	int line;
	for (int i = 0; i < 25; i++)
	{
		int num;
		bool isExist = false;
		//�迭 �ȿ� 1~25���� ���� �� �������
		do
		{
			isExist = false;
			int randomnum = rand() % 25 + 1;
			num = randomnum;

			// �̹� ������ ���ڿ� ���Ͽ� �ߺ� ���� Ȯ��
			for (int j = 0; j < i; j++)
			{
				if (num == Map[j])
				{
					isExist = true;
					break;
				}
			}

		} while (isExist);		// �ߺ���

		Map[i] = num;			// �ߺ� �ƴҽ�
		//1~25 ���� Com �迭
		do
		{
			isExist = false;
			int randomnum = rand() % 25 + 1;
			num = randomnum;
			for (int j = 0; j < i; j++)
			{
				if (num == ComMap[j])
				{
					isExist = true;
					break;
				}
			}
		} while (isExist);
		ComMap[i] = num;
	}

	line = rand() % 12;


	while (true) {						// while���� ��� �ݺ��Ǹ� 5X5 �迭(������)�� ǥ�õ� 
		system("cls");
		cout << endl << "--------------player--------------" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (Map[i * 5 + j] == STAR) {
					cout << "*\t";		// ���ڸ� �Է� ������ *�� ǥ��
				}
				else {
					cout << Map[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}
		cout << endl << "BingoCount " << bingocount << endl;
		cout << endl << "-------------computer-------------" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (ComMap[i * 5 + j] == STAR) {
					cout << "*\t";
				}
				else {
					cout << ComMap[i * 5 + j] << "\t";		//��ǻ���� �������� ���������
					//cout << "��" << "\t";					//��ǻ���� �������� �÷� ������ ������
				}
			}
			cout << endl;
		}
		cout << endl << "BingoCount " << com_bingo << endl;


		if (bingocount >= 5) {
			cout << endl << "��5�� ���� �ϼ���" << endl << "���÷��̾��� �¸���" << endl;
			break;
		}
		else if(com_bingo >= 5){
			cout << endl << "��5�� ���� �ϼ���" << endl << "����ǻ���� �¸���" << endl;
			break;
		}

		bingocount = 0;						//ī��Ʈ�� �ʱ�ȭ �����ν� ������ ���������� ����ɼ� �ֵ��� ���ش�.
		com_bingo = 0;
		cout << "1~25 ������ ���ڸ� �Է��� �ּ���(0 : ����): ";
		cin >> inputnum;					//���� ���� input

		if (inputnum == 0) break;			// 0 ������ ���� ����
		if (inputnum < 0 || inputnum >25) continue;
		//�÷��̾� �����ǿ� �÷��̾ input�� ���� *ǥ��
		for (int i = 0; i < 25; i++) {
			if (inputnum == Map[i]) {
				Map[i] = STAR;
			}
		}
		//�÷��̾ �Է½� com ������ ���� *ǥ��
		for (int i = 0; i < 25; i++) {
			if (inputnum == ComMap[i]) {
				ComMap[i] = STAR;
			}
		}

		int notstar[5];
		int nstarcount = 0;

		//com�� �������� ���ڸ� �����ϴ°��� �ƴ�, ������ ������ �ϳ��� ��� �װ͸� ä��°� 
		if (changeline == true)	line = rand() % 12;
		//0~4 �� ������
		//�������� 0~12�� ���� ����
		if (line == 0) {						// *ǥ�õ��� ���� numã�� input�� �ֱ�
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 0; i < 5; i++) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];					
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}


		}
		if (line == 1) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 5; i < 10; i++) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}

		}
		if (line == 2) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 10; i < 15; i++) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 3) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 15; i < 20; i++) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 4) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 20; i < 25; i++) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		//5~9 �� ������
		if (line == 5) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 0; i < 21; i += 5) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 6) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 1; i < 22; i += 5) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 7) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 2; i < 23; i += 5) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 8) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 3; i < 24; i += 5) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		if (line == 9) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 4; i < 25; i += 5) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		//�����ϴ� �밢��
		if (line == 10) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 0; i < 25; i += 6) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}
		// �����ϴ� �밢��
		if (line == 11) {
			changeline = false;
			nstarcount = 0;
			for (int i = 0; i < 5; i++)		notstar[i] = 0;
			for (int i = 4; i < 21; i += 4) {
				if (ComMap[i] != STAR) {
					notstar[nstarcount++] = ComMap[i];
				}
			}
			if (nstarcount == 0) {
				changeline = true;
			}
			else {
				inputnum = notstar[rand() % nstarcount];
			}
		}


		//com�� input�� ���� �÷��̾� �����ǿ��� *ǥ��
		for (int i = 0; i < 25; i++) {
			if (inputnum == Map[i]) {
				Map[i] = STAR;
			}
		}
		//com�� input�� ���� com�����ǿ��� *ǥ��
		for (int i = 0; i < 25; i++) {
			if (inputnum == ComMap[i]) {
				ComMap[i] = STAR;
			}
		}

		//���� ���� * ī��Ʈ
		for (int i = 0; i < 5; i++) {
			r_star = c_star = 0;					//*�� �ʱ�ȭ�ؼ� �������� �����ϵ���
			com_r = com_c = 0;
			for (int j = 0; j < 5; j++) {
				if (Map[i * 5 + j] == STAR)  ++r_star;
				if (Map[j * 5 + i] == STAR)  ++c_star;
				if (ComMap[i * 5 + j] == STAR)  ++com_r;
				if (ComMap[j * 5 + i] == STAR)  ++com_c;
			}
			if (r_star == 5) ++bingocount;
			if (c_star == 5) ++bingocount;
			if (com_r == 5) ++com_bingo;
			if (com_c == 5) ++com_bingo;
		}
		//�����ϴ� �밢��
		diagonal_star = 0;			//�밢�� *�ʱ�ȭ
		com_diagonal = 0;
		for (int i = 0; i < 25; i += 6) {
			if (Map[i] == STAR)	 ++diagonal_star;
			if (ComMap[i] == STAR)	 ++com_diagonal;
		}
		if (diagonal_star == 5) ++bingocount;
		if (com_diagonal == 5) ++com_bingo;
		//�����ϴ� �밢��
		diagonal_star = 0;
		com_diagonal = 0;
		for (int i = 0; i < 25; i += 4) {
			if (Map[i] == STAR)  ++diagonal_star;
			if (ComMap[i] == STAR)  ++com_diagonal;
		}
		if (diagonal_star == 5) ++bingocount;
		if (com_diagonal == 5) ++com_bingo;

	}

	cout << "������ �����մϴ�.";


	return 0;
}