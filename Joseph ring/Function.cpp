/*
ѭ�� ��0��i           => pos=(pos+1)%i
					��ʼֵ:pos=-1;
					����:
				=> pos++;
				if(pos==i){
					pos=0;
				}
*/
#include "Function.h"
#include <iostream>
#include <fstream>
#define Num 41//������
#define KillMan 3//��ɱ�߱���
using namespace std;

void Josephus(int alive) {//Լɪ���㷨
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		exit(EXIT_FAILURE);
	}
	int man[Num] = { 0 };
	int count = 1;
	int i = 0;//����������,��i=KillMan,������ɱ
	int pos = -1;//��������
	while (count <= Num) {//Լɪ��
		do {//������
			pos = (pos + 1) % Num;//pos=(0,1,2,3,4,5,6,.....,40),(0,1,2,.......40)
			if (man[pos] == 0) {
				i++;
			}
			if (i == KillMan) {//������ɱ
				i = 0;//��������
				break;//ֱ��������ɱ����ѭ��
			}
		} while (1);//һֱѭ��
		man[pos] = count;
		out << "��" << pos + 1 << "������ɱ!Լɪ�򻷱��Ϊ:" << man[pos];
		if (count % 2) {
			out << " -> ";
		}
		else {
			out << " -> " << endl;
		}
		count++;
	}
	out << endl;
	out << "��" << alive << "��Ҫ�����˳�ʼλ��Ӧ����һ�����:" << endl;
	alive = Num - alive;
	for (i = 0; i < Num; i++) {
		if (man[i] > alive) {
			out << "���Ա��:" << i + 1 << ",Լɪ�򻷱��:" << man[i] << endl;
		}
	}
	out << endl;
	return;
}