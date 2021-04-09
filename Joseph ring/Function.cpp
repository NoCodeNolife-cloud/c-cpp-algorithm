/*
循环 从0到i           => pos=(pos+1)%i
					初始值:pos=-1;
					或者:
				=> pos++;
				if(pos==i){
					pos=0;
				}
*/
#include "Function.h"
#include <iostream>
#include <fstream>
#define Num 41//总人数
#define KillMan 3//自杀者报数
using namespace std;

void Josephus(int alive) {//约瑟夫算法
	fstream out("out.txt", ios::app);
	if (!out.is_open()) {
		exit(EXIT_FAILURE);
	}
	int man[Num] = { 0 };
	int count = 1;
	int i = 0;//死亡计数器,当i=KillMan,此人自杀
	int pos = -1;//环计数器
	while (count <= Num) {//约瑟夫环
		do {//环处理
			pos = (pos + 1) % Num;//pos=(0,1,2,3,4,5,6,.....,40),(0,1,2,.......40)
			if (man[pos] == 0) {
				i++;
			}
			if (i == KillMan) {//此人自杀
				i = 0;//计数归零
				break;//直到有人自杀结束循环
			}
		} while (1);//一直循环
		man[pos] = count;
		out << "第" << pos + 1 << "个人自杀!约瑟夫环编号为:" << man[pos];
		if (count % 2) {
			out << " -> ";
		}
		else {
			out << " -> " << endl;
		}
		count++;
	}
	out << endl;
	out << "这" << alive << "需要存活的人初始位置应排在一下序号:" << endl;
	alive = Num - alive;
	for (i = 0; i < Num; i++) {
		if (man[i] > alive) {
			out << "初试编号:" << i + 1 << ",约瑟夫环编号:" << man[i] << endl;
		}
	}
	out << endl;
	return;
}