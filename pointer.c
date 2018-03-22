#include <iostream>
#include <iomanip>

using namespace std;

// ���� ������ ���α׷��� ����ٶ�.
// ���ڿ� ó���� unsigned char�� �׳� char�� �����ϰ� �����ص� ��
// Ư�� ��Ŷó�������� ��� ���� ���ڷ� ó���ϸ� �Ǳ� ������ ���ڿ� �Լ��� Ȱ���ϸ� ��
// ��ư� ĳ��Ʈ ������ ���� �ʴ� ���� ����
// ���ڿ����� Ư�� ���ڿ��� ã�� ���� ������ �κ��� ����ٶ�. �̶� ĳ��Ʈ ��ȯ�� �ϸ� �ȵ�

int main()
{
	unsigned char arr[] = { 97,66,99,68,69,70,' ','H','O','S','T','\0' };
	char *arrnew = { "aBcD HOST\0"};
	char *host = { "HOST\0" }, *nothost = { "NOST\0" };
	int *newp;
	char *p;

	cout << arr << "\t\t (arr �迭�� ��Ʈ���� ���)" << endl;  // arr �迭�� ��Ʈ���� ���
	cout << &arr << "\t\t (arr �迭�� ù �ּ� �� ���, 16����)" << endl;	// arr[0]�� �ּҸ� ���
	cout << (unsigned long)arr << "\t\t (arr �迭�� ù �ּ� �� ���, 10����)" <<endl;
	cout << ">> test 1 : " << hex << (unsigned long)arr << "\t (arr �迭�� ù �ּ� �� ���, 16����)" << endl;
	cout << (unsigned long *)arr << "\t\t (arr �迭�� ù �ּ� �� ���, 16����)" << endl;
	cout << ">> test 2 : " << hex << (unsigned long *)arr << "\t (arr �迭�� ù �ּ� �� ���, 16����)" << endl;

	unsigned long *test = (unsigned long*)arr;
	cout << test << "\t\t (arr �迭�� ù �ּ� �� ���)"<<endl;	//arr�� ���� �ּҰ� ���
	cout << *test << "\t\t (arr �迭�� ��Ʈ�� 4�� ���, little endian)" << endl;	//*test�� "aBcD"�� ���� ��ȣ���� ���� ������ ȯ���켭 �����
	cout << ">> test 3 : "<<hex << *test << "\t (arr �迭�� ��Ʈ�� 4�� ���, little endian)" << endl; // �̷��� �ڵ��ϸ� �� "ABCD"�� ���� ���� 16�������� ���(little endian)
	cout << ">> test 4 : " << (char *)test << "\t (arr �迭�� ��Ʈ�� ��ü ���)" << endl;
	cout << endl;
	p = (char *)arrnew;
	newp =(int *) p;
	cout << newp << "\t\t (arrnew �迭�� ù �ּ� �� ���, 10����)" << endl;	//arrnew�� ���� �ּҰ� ���
	cout << *newp << "\t\t (arrnew �迭�� ��Ʈ�� 4�� ���, little endian)" << endl;	//*test�� "aBcD"�� ���� ��ȣ���� ���� ������ ȯ���켭 �����
	cout << ">> test 5 : " << hex << *newp << "\t (arrnew �迭�� ��Ʈ�� 4�� ���, little endian)" << endl; // �̷��� �ڵ��ϸ� �� "ABCD"�� ���� ���� 16�������� ���(little endian)
	cout << ">> test 6 : " << (char *)newp << "\t (arrnew �迭�� ��Ʈ�� ��ü ���)" << endl;
	cout << ">> HOST �� : ";
	if (strcmp((char *)p + 5, host) == 0) cout << ">> �� ���ڿ��� ��ġ�մϴ�!\n";
	else cout << ">> �� ���ڿ��� ��ġ���� �ʽ��ϴ� !\n";
	cout << ">> NOST �� : ";
	if (strcmp((char *)p + 5, nothost) == 0) cout << ">> �� ���ڿ��� ��ġ�մϴ�!\n";
	else cout << ">> �� ���ڿ��� ��ġ���� �ʽ��ϴ� !\n";
	cout << endl;



	return 0;
}
