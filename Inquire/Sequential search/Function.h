#pragma once
int SearchFun(int a[], int n, int x) {
	int i, f = -1;//δ�ҵ����س�ʼֵ-1,С��0,�ж�Ϊδ�ҵ�
	for (i = 0; i < n; i++) {
		if (x == a[i]) {
			f = i;//�ҵ�,���ش��ڵ���0��ֵ,�ж�Ϊ�ҵ�,������
			break;
		}
	}
	return f;
}