#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;
public:
	// 크기가 10인 배열

	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
		cout << "기본 생성자 호출 : 크기 10 배열 생성" << endl;
	}
	// 숫자를 하나 받는 생성자는 해당 숫자에 해당 크기의 배열을 만든다.

	SimpleVector(int customSize) : currentSize(0), currentCapacity(customSize) {
		data = new T[currentCapacity];
		cout << "크기" << currentCapacity << "배열 생성" << endl;

	}
	// 소멸자 등록 
	~SimpleVector() {
		delete[] data;
		cout << "SimpleVector소멸: 총 크기" << currentCapacity << "메모리 해제 완료" << endl;

	}
	// push_back 인자로 받은 원소를 맨 뒤에 추가하고, 반환값 없고, 배열의 크기가 꽉 찼는데 원소가 들어올 경우 작동하지 않는다.

	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;
			cout << "push_back 성공 :" << value << "추가됨" << endl;
		}
		else {
			cout << "배열이 가득 찼습니다." << endl;
		}
	}
	// pop_back 마지막 원소를 제거하고, 만약 제거할 원소가 없다면 아무동작도 하지않고, 인자 및 반환값은 없다.

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
			cout << "pop_back 성공" << data[currentSize - 1] << "제거됨" << endl;

		}
		else {
			cout << "배열이 비어 있습니다." << endl;
		}
	}

	// size는 인자가 없고 현재 원소의 개수 반환
	int size() const {
		return currentSize;
	}
	// capacity 현재 내부 배열의 크기를 반환
	int capacity() const {
		return currentCapacity;
	}

	void print()const {
		cout << "현재 배열 요소";
		for (int i = 0; i < currentSize; ++i) {
			cout << data[i] << "";
		}
		cout << endl;
	}
};
//테스트 
int main() {
	SimpleVector<int> vec1; // 크기 10의 백터 생성
	vec1.push_back(1);  // 1 추가
	vec1.push_back(2);  // 2추가 
	vec1.push_back(3);  // 3추가
	vec1.print();
	cout << "vec1 크기:" << vec1.size() << ", 용량 :" << vec1.capacity() << endl; //현재 저장된 요소 출력

	SimpleVector<int> vec2(5);
	vec2.push_back(10);
	vec2.push_back(20);
	vec2.push_back(30);
	vec2.print();
	cout << "pop_back 실행 후 vec2 요소:";
	vec2.pop_back(); // 마지막 요소 제거
	vec2.print();
	cout << "vec2 크기: " << vec2.size() << ", 용량" << vec2.capacity() << endl;

	// 용량 초과 시 동작 
	for (int i = 0; i < 6; ++i) {  // 용량 초과해서 push_back 실행시도
		vec2.push_back(i * 10);
	}
	cout << "최종 vec2 요소 : ";
	vec2.print();          // 초과 요소는 추가 x

	return 0;
}
