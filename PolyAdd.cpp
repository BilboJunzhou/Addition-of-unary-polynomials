/************************************************************************************************************/
/*****************************��������һԪ����ʽ��ʵ������һԪ����ʽ������㷨��*****************************/
/**********************************�¿��� 2006040226 ���ܿ�ѧ�뼼��2��***************************************/
/************************************************************************************************************/


#include<iostream>
#include<queue>
using namespace std;

// һԪ����ʽ�ڵ�
// ����ʵ��1�Ѿ�ʹ�ù��������ʽ�������鴦��������ѡ����н������ݴ���
struct MulaData
{
	double num_1;
	int num_2;
};

// ��ط���
class PolyAdd {
public:
	queue<MulaData> setFormula();// ����һԪ����ʽ
	void showFormula(queue<MulaData> formula);// ���һԪ����ʽ
	queue<MulaData> addFormula(queue<MulaData> formulaOne, queue<MulaData> formulaTwo);// һԪ����ʽ���
};

// ����һԪ����ʽ
queue<MulaData> PolyAdd::setFormula()
{
	queue<MulaData> formula;
	MulaData Num_Get;
	std::cin >> Num_Get.num_1;
	while (Num_Get.num_1 != -1)
	{
		std::cin >> Num_Get.num_2;
		formula.push(Num_Get);
		std::cin >> Num_Get.num_1;
	}
	cout << "��������" << endl;
	return formula;
}

// ���һԪ����ʽ
void PolyAdd::showFormula(queue<MulaData> formula)
{
	MulaData showNum;
	while (!formula.empty())
	{
		showNum = formula.front();
		formula.pop();
		cout << showNum.num_1 << "x^" << showNum.num_2;
		if (!formula.empty()) cout << '+';
	}
	cout << '\n';
}

// һԪ����ʽ���
queue<MulaData> PolyAdd::addFormula(queue<MulaData> formulaOne, queue<MulaData> formulaTwo)
{
	MulaData Save_1, Save_2;
	queue<MulaData> result_Res;
	// �����߲�Ϊ��
	while ((!formulaOne.empty()) && (!formulaTwo.empty())) {
		Save_1 = formulaOne.front(); 
		Save_2 = formulaTwo.front();
		if (Save_1.num_2 == Save_2.num_2) {
			Save_1.num_1 += Save_2.num_2;
			result_Res.push(Save_1);
			formulaOne.pop();
			formulaTwo.pop();
		}
		else if (Save_1.num_2 >= Save_2.num_2) {
			result_Res.push(Save_1);
			formulaOne.pop();
		}
		else {
			result_Res.push(Save_2);
			formulaTwo.pop();
		}
	}
	// ����֮һΪ��
	if (formulaOne.empty()) {
		while (!formulaTwo.empty()) {
			result_Res.push(formulaTwo.front());
			formulaTwo.pop();
		}
	}
	else {
		while (!formulaOne.empty()) {
			result_Res.push(formulaOne.front());
			formulaOne.pop();
		}
	}
	return result_Res;
}





// ���Ժ���
//int main() {
//	queue<MulaData> formula_1;
//	queue<MulaData> formula_2;
//	queue<MulaData> resultFor;
//	PolyAdd RunWay;
//	cout << "������һ��һԪ����ʽ������-1ֹͣ����:\n" << endl;
//	formula_1 = RunWay.setFormula();
//	cout << "�����ڶ���һԪ����ʽ������-1ֹͣ����:\n" << endl;
//	formula_2 = RunWay.setFormula();
//	cout << "�������Ϊ:\n" << endl;
//	RunWay.showFormula(formula_1);
//	RunWay.showFormula(formula_2);
//	cout << "��ӽ��Ϊ:\n" << endl;
//	resultFor = RunWay.addFormula(formula_1, formula_2);
//	RunWay.showFormula(resultFor);
//	return 0;
//}

