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

private:

	// 내부 저장소 크기.
	// 내부 저장소 크기는 소수(1과 자기자신으로마 나눠지는 수)를 선택하는 게 해시 충돌 방지에 좋음.
	// 사용 가능한 소수 중에서 큰 수를 사용.
	static const int bucketCount = 19;

};