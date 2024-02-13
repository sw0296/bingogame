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
		//배열 안에 1~25까지 랜덤 수 집어넣음
		do
		{
			isExist = false;
			int randomnum = rand() % 25 + 1;
			num = randomnum;

			// 이미 생성된 숫자와 비교하여 중복 여부 확인
			for (int j = 0; j < i; j++)
			{
				if (num == Map[j])
				{
					isExist = true;
					break;
				}
			}

		} while (isExist);		// 중복시

		Map[i] = num;			// 중복 아닐시
		//1~25 까지 Com 배열
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


	while (true) {						// while문이 계속 반복되며 5X5 배열(빙고판)이 표시됨 
		system("cls");
		cout << endl << "--------------player--------------" << endl << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (Map[i * 5 + j] == STAR) {
					cout << "*\t";		// 숫자를 입력 받을시 *로 표시
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
					cout << ComMap[i * 5 + j] << "\t";		//컴퓨터의 빙고판을 보고싶을때
					//cout << "▣" << "\t";					//컴퓨터의 빙고판은 ▣로 가리고 싶을때
				}
			}
			cout << endl;
		}
		cout << endl << "BingoCount " << com_bingo << endl;


		if (bingocount >= 5) {
			cout << endl << "★5줄 빙고 완성★" << endl << "★플레이어의 승리★" << endl;
			break;
		}
		else if(com_bingo >= 5){
			cout << endl << "★5줄 빙고 완성★" << endl << "★컴퓨터의 승리★" << endl;
			break;
		}

		bingocount = 0;						//카운트를 초기화 함으로써 루프가 독립적으로 실행될수 있도록 해준다.
		com_bingo = 0;
		cout << "1~25 사이의 숫자를 입력해 주세요(0 : 종료): ";
		cin >> inputnum;					//빙고 숫자 input

		if (inputnum == 0) break;			// 0 누르면 게임 종료
		if (inputnum < 0 || inputnum >25) continue;
		//플레이어 빙고판에 플레이어가 input한 숫자 *표시
		for (int i = 0; i < 25; i++) {
			if (inputnum == Map[i]) {
				Map[i] = STAR;
			}
		}
		//플레이어가 입력시 com 빙고판 숫자 *표시
		for (int i = 0; i < 25; i++) {
			if (inputnum == ComMap[i]) {
				ComMap[i] = STAR;
			}
		}

		int notstar[5];
		int nstarcount = 0;

		//com이 랜덤으로 숫자를 선택하는것이 아닌, 빙고판 라인중 하나를 골라 그것만 채우는것 
		if (changeline == true)	line = rand() % 12;
		//0~4 는 가로줄
		//랜덤으로 0~12번 라인 선택
		if (line == 0) {						// *표시되지 않은 num찾아 input에 넣기
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
		//5~9 는 세로줄
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
		//우측하단 대각선
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
		// 좌측하단 대각선
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


		//com이 input한 숫자 플레이어 빙고판에서 *표시
		for (int i = 0; i < 25; i++) {
			if (inputnum == Map[i]) {
				Map[i] = STAR;
			}
		}
		//com이 input한 숫자 com빙고판에서 *표시
		for (int i = 0; i < 25; i++) {
			if (inputnum == ComMap[i]) {
				ComMap[i] = STAR;
			}
		}

		//가로 세로 * 카운트
		for (int i = 0; i < 5; i++) {
			r_star = c_star = 0;					//*를 초기화해서 루프마다 동작하도록
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
		//우측하단 대각선
		diagonal_star = 0;			//대각선 *초기화
		com_diagonal = 0;
		for (int i = 0; i < 25; i += 6) {
			if (Map[i] == STAR)	 ++diagonal_star;
			if (ComMap[i] == STAR)	 ++com_diagonal;
		}
		if (diagonal_star == 5) ++bingocount;
		if (com_diagonal == 5) ++com_bingo;
		//좌측하단 대각선
		diagonal_star = 0;
		com_diagonal = 0;
		for (int i = 0; i < 25; i += 4) {
			if (Map[i] == STAR)  ++diagonal_star;
			if (ComMap[i] == STAR)  ++com_diagonal;
		}
		if (diagonal_star == 5) ++bingocount;
		if (com_diagonal == 5) ++com_bingo;

	}

	cout << "게임을 종료합니다.";


	return 0;
}