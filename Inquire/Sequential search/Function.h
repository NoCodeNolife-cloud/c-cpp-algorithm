#pragma once
int SearchFun(int a[], int n, int x) {
	int i, f = -1;//未找到返回初始值-1,小于0,判断为未找到
	for (i = 0; i < n; i++) {
		if (x == a[i]) {
			f = i;//找到,返回大于等于0的值,判断为找到,输出结果
			break;
		}
	}
	return f;
}