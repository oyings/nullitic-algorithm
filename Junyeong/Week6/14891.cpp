#include <iostream>
#include <queue>

// 14891 톱니바퀴

using namespace std;

int K;
char Gear[4][8];
// 데크는 랜덤접근이 안되기 때문에 문자형배열 추가로 선언
deque<char> Gear_deque[4][8];
// 0행은 1번기어, 1행은 2번기어, 2행은 3번기어, 3행은 4번기어를 나타낸다

void clock_wise(int gear_num) {
	Gear_deque[gear_num]->push_front(Gear_deque[gear_num]->back());
	Gear_deque[gear_num]->pop_back();
}

void counter_clock_wise(int gear_num) {
	Gear_deque[gear_num]->push_back(Gear_deque[gear_num]->front());
	Gear_deque[gear_num]->pop_front();
}

void renew_array() {
	for (int gear_num = 0; gear_num < 4; gear_num++) {
		for (int j = 0; j < 8; j++) {
			Gear[gear_num][j] = Gear_deque[gear_num]->front();
			Gear_deque[gear_num]->push_back(Gear_deque[gear_num]->front());
			Gear_deque[gear_num]->pop_front();
		}
	}
}

void solution() {
	cin >> K;
	while (K--) {
		int Gear_num, Direction;
		cin >> Gear_num >> Direction;

		// 이웃하는 이빨의 극이 다르면 반대방향으로 회전
		// 바뀐후에 비교하는것이 아니라 그 때 그 상태 값을 비교한다 -> Gear배열의 변경은 회전연산 후에 적용된다
		switch (Gear_num) {
			case 1:
				if (Direction == -1) {
					// 1이 회전하는지 여부에 따라 맞물린 톱니(2,3,4)를 움직일지 결정
					// 앞선 톱니가 움직이지 않으면 뒤에 위치한 톱니를 움직일 수 없으므로 break처리
					counter_clock_wise(0);
					if (Gear[0][2] != Gear[1][6]) {
						clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[1][2] != Gear[2][6]) {
						counter_clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[2][2] != Gear[3][6]) {
						clock_wise(3);
					}
				}
				else {
					clock_wise(0);
					if (Gear[0][2] != Gear[1][6]) {
						counter_clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[1][2] != Gear[2][6]) {
						clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[2][2] != Gear[3][6]) {
						counter_clock_wise(3);
					}
				}
				break;
			case 2:
				// 3이 회전하는지 여부에 따라 맞물린 톱니(4)를 움직일지 결정
				// 1의 회전과 4의 회전은 서로 관련없다
				if (Direction == -1) {
					counter_clock_wise(1);
					if (Gear[0][2] != Gear[1][6]) {
						clock_wise(0);
					}
					
					if (Gear[1][2] != Gear[2][6]) {
						clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[2][2] != Gear[3][6]) {
						counter_clock_wise(3);
					}
				}
				else {
					clock_wise(1);
					if (Gear[0][2] != Gear[1][6]) {
						counter_clock_wise(0);
					}
					
					if (Gear[1][2] != Gear[2][6]) {
						counter_clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[2][2] != Gear[3][6]) {
						clock_wise(3);
					}
				}
				break;
			case 3:
				if (Direction == -1) {
					// 3이 회전하는지 여부에 따라 맞물린 톱니(4)를 움직일지 결정
					// 1의 회전과 4의 회전은 서로 관련없다
					counter_clock_wise(2);
					if (Gear[2][2] != Gear[3][6]) {
						clock_wise(3);
					}
					
					if (Gear[1][2] != Gear[2][6]) {
						clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[0][2] != Gear[1][6]) {
						counter_clock_wise(0);
					}
				}
				else {
					clock_wise(2);
					if (Gear[2][2] != Gear[3][6]) {
						counter_clock_wise(3);
					}
					
					if (Gear[1][2] != Gear[2][6]) {
						counter_clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[0][2] != Gear[1][6]) {
						clock_wise(0);
					}
				}
				break;
			case 4:
				// 3이 회전하는지 여부에 따라 맞물린 톱니(1,2)를 움직일지 결정
				// 앞선 톱니가 움직이지 않는다면 뒷톱니는 움직일 수 없다
				if (Direction == -1) {
					counter_clock_wise(3);
					if (Gear[2][2] != Gear[3][6]) {
						clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[1][2] != Gear[2][6]) {
						counter_clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[0][2] != Gear[1][6]) {
						clock_wise(0);
					}
				}
				else {
					clock_wise(3);
					if (Gear[2][2] != Gear[3][6]) {
						counter_clock_wise(2);
					}
					else {
						break;
					}
					if (Gear[1][2] != Gear[2][6]) {
						clock_wise(1);
					}
					else {
						break;
					}
					if (Gear[0][2] != Gear[1][6]) {
						counter_clock_wise(0);
					}
				}
				break;
			}
		// 톱니의 회전을 적용시킨다
		renew_array();
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cout << Gear[i][j];
			}
			cout << '\n';
		}*/
	}

	int total = 0;

	if (Gear_deque[0]->front() == '1') {
		total += 1;
	}
	if (Gear_deque[1]->front() == '1') {
		total += 2;
	}
	if (Gear_deque[2]->front() == '1') {
		total += 4;
	}
	if (Gear_deque[3]->front() == '1') {
		total += 8;
	}

	cout << total;
}

int main() {

	for (int i = 0; i < 4; i++) {
		string input_str;
		cin >> input_str;
		for (int j = 0; j < 8; j++) {
			Gear[i][j] = input_str[j];
			Gear_deque[i]->push_back(input_str[j]);
		}
	}

	solution();

	return 0;
}