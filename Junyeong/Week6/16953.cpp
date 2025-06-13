#include <iostream>
#include <queue>

using namespace std;

// 16953 A → B

int a, b;

void solution() {
	queue<pair<long long int, int>>q;

	q.push({ a,1 });

	// A값을 B로 바꿀 때 까지 수행
	while (!q.empty()) {
		// 2를 곱하는 연산
		long long int multiple_2 = q.front().first * 2;
		// 1을 수의 가장 오른쪽에 추가하는 연산 -> a * 10 + 1로 대체
		long long int plus_1 = q.front().first * 10 + 1;

		// 지금까지 해온 연산 횟수
		long long int count = q.front().second + 1;
		
		// 변환시킨 값이 b를 초과할 경우 큐에 넣지 않는다.
		// front를 감소시키는 연산이 주어지지 않았다.
		// 이미 처리했던 수를 다시 처리하는 경우는 최솟값이 될 수 없으므로 배제
		if (multiple_2 < b) {
			q.push({ multiple_2, count });
		}
		else if (multiple_2 == b) {
			cout << count;
			return;
		}

		if (plus_1 < b) {
			q.push({ plus_1, count });
		}
		else if (plus_1 == b) {
			cout << count;
			return;
		}
		q.pop();
	}

	// 할 수 있는 연산을 다 해봤지만 답을 구하지 못한 경우
	cout << -1;
}

int main() {

	cin >> a >> b;

	solution();
	
	return 0;
}