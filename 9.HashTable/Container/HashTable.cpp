#include "HashTable.h"

// 해시 함수
// 키를 어떠한 과정을 통해서 숫자로 변환해주는 함수.
int GenerateKey(const std::string& keyString)
{
    // 출력할 해시 변수 선언.
    int hash = 0;

    // 문자열을 문자 배열로 활용해 해시 생성.
    const int length = static_cast<int>(keyString.length());
    for (int ix = 0; ix < length; ++ix)
    {
        // 해시 생성 로직.
        //hash += keyString[ix] * (ix + 1); // => 성능이 좋지는 않음.
        hash = hash * 31 + keyString[ix]; // java의 방식. Hornor's method
    }
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

void HashTable::Add(const std::string& key, const std::string& value)
{
}

void HashTable::Delete(const std::string& key)
{
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
    return false;
}

// 출력 함수.
void HashTable::Print()
{

}

// Getter.
bool HashTable::IsEmpty() const
{

}