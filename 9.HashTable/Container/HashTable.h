#pragma once
#include <vector>
#include "Pair.h"
#include <string>

// 해시테이블 클래스.
class HashTable
{
private:
	using Entry = Pair<std::string, std::string>;

public:
	HashTable();
	~HashTable();

	// 키-값 조합으로 저장할 수 있도록.
	bool Add(const std::string& key, const std::string& value);

	// 삭제-키를 활용해 K-value 조합데이터 삭제.
	bool Delete(const std::string& key);

	bool Find(const std::string& key, Entry& outEntry); // Entry& 는 참조 받아 값을 바꿔야 하기 때문에 앞에 const를 붙이지 않음.
	
	void Print();
	// Getter.
	bool IsEmpty() const; // 해당 함수는 간단하지 않기 때문에 inline 사용하지 않도록 함.
private:

	// 내부 저장소 크기.
	// 내부 저장소 크기는 소수(1과 자기자신으로마 나눠지는 수)를 선택하는 게 해시 충돌 방지에 좋음.
	// 사용 가능한 소수 중에서 큰 수를 사용.
	static const int bucketCount = 19;

	// 이차 저장소(해시 충돌 해결 방법으로 체이닝(Chaining).
	std::vector<Entry> table[bucketCount];
	
};