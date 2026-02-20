#include "Container/HashTable.h"
#include <iostream>

int main()
{
	// 해시 테이블 객체 생성.
	HashTable table;

	// 데이터 추가.
	table.Add("Ronnie", "010-123456787");
	table.Add("Bonnie", "010-666666666");
	table.Add("Connie", "010-999999999");
	table.Add("Aonnie", "010-123434334");
	table.Add("Oonnie", "010-515151515");
	table.Add("Ponnie", "010-123451234");

	// 출력.
	table.Print();
	
	// 검색.
	Pair<std::string, std::string> outValue;
	if (table.Find("Baker", outValue))
	{
		std::cout << "검색 성공. Key: "
			<< outValue.key << " | Value: "
			<< outValue.value << "\n";
	}

	// 삭제.
	table.Delete("Ronnie");
	table.Delete("Bonnie");

	table.Print();

	std::cin.get();
}