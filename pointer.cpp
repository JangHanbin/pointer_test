#include <iostream>
#include <iomanip>

using namespace std;

// 내가 수정한 프로그램을 참고바람.
// 문자열 처리에 unsigned char와 그냥 char는 동일하게 생각해도 됨
// 특히 패킷처리에서는 모든 것을 문자로 처리하면 되기 때문에 문자열 함수를 활용하면 됨
// 어렵게 캐스트 연산을 하지 않는 것이 좋음
// 문자열에서 특정 문자열을 찾는 것은 마지막 부분을 참고바람. 이때 캐스트 변환을 하면 안됨

int main()
{
	unsigned char arr[] = { 97,66,99,68,69,70,' ','H','O','S','T','\0' };
	char *arrnew = { "aBcD HOST\0"};
	char *host = { "HOST\0" }, *nothost = { "NOST\0" };
	int *newp;
	char *p;

	cout << arr << "\t\t (arr 배열의 스트링을 출력)" << endl;  // arr 배열내 스트링을 출력
	cout << &arr << "\t\t (arr 배열의 첫 주소 값 출력, 16진법)" << endl;	// arr[0]의 주소를 출력
	cout << (unsigned long)arr << "\t\t (arr 배열의 첫 주소 값 출력, 10진법)" <<endl;
	cout << ">> test 1 : " << hex << (unsigned long)arr << "\t (arr 배열의 첫 주소 값 출력, 16진법)" << endl;
	cout << (unsigned long *)arr << "\t\t (arr 배열의 첫 주소 값 출력, 16진법)" << endl;
	cout << ">> test 2 : " << hex << (unsigned long *)arr << "\t (arr 배열의 첫 주소 값 출력, 16진법)" << endl;

	unsigned long *test = (unsigned long*)arr;
	cout << test << "\t\t (arr 배열의 첫 주소 값 출력)"<<endl;	//arr와 같은 주소값 출력
	cout << *test << "\t\t (arr 배열의 스트링 4자 출력, little endian)" << endl;	//*test는 "aBcD"의 값을 부호없는 정수 값으로 환산헤서 출력함
	cout << ">> test 3 : "<<hex << *test << "\t (arr 배열의 스트링 4자 출력, little endian)" << endl; // 이렇게 코딩하면 위 "ABCD"의 저장 값을 16진법으로 출력(little endian)
	cout << ">> test 4 : " << (char *)test << "\t (arr 배열의 스트링 전체 출력)" << endl;
	cout << endl;
	p = (char *)arrnew;
	newp =(int *) p;
	cout << newp << "\t\t (arrnew 배열의 첫 주소 값 출력, 10진법)" << endl;	//arrnew와 같은 주소값 출력
	cout << *newp << "\t\t (arrnew 배열의 스트링 4자 출력, little endian)" << endl;	//*test는 "aBcD"의 값을 부호없는 정수 값으로 환산헤서 출력함
	cout << ">> test 5 : " << hex << *newp << "\t (arrnew 배열의 스트링 4자 출력, little endian)" << endl; // 이렇게 코딩하면 위 "ABCD"의 저장 값을 16진법으로 출력(little endian)
	cout << ">> test 6 : " << (char *)newp << "\t (arrnew 배열의 스트링 전체 출력)" << endl;
	cout << ">> HOST 비교 : ";
	if (strcmp((char *)p + 5, host) == 0) cout << ">> 두 문자열이 일치합니다!\n";
	else cout << ">> 두 문자열이 일치하지 않습니다 !\n";
	cout << ">> NOST 비교 : ";
	if (strcmp((char *)p + 5, nothost) == 0) cout << ">> 두 문자열이 일치합니다!\n";
	else cout << ">> 두 문자열이 일치하지 않습니다 !\n";
	cout << endl;



	return 0;
}
