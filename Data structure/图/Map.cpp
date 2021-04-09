#include <iostream>

#include "Node.h"
#include "CMap.h"

using namespace std;
/*
	  图的存储 与 图的遍历
*/
/*

		 A
	/   \
   B      D
  / \    / \
 C   F  G — H
 \  /
  E

*/

/*

深度优先遍历：A B C E F D G H
广度优先遍历：A B D C F G F E

邻接矩阵：
  A  B  C  D  E  F  G  H
A     1     1
B  1     1        1
C     1        1  1
D  1                 1  1
E        1
F     1  1
G           1           1
H           1        1

*/
/*Time:2018年9月9日11:48:48    */

int main(void)
{
	CMap* pMap = new CMap(6);//6指的是图的最大容量

	//生成结点,m_iCapacity=6正好对应上
	Node* pNodeA = new Node('A');
	Node* pNodeB = new Node('B');
	Node* pNodeC = new Node('C');
	Node* pNodeD = new Node('D');
	Node* pNodeE = new Node('E');
	Node* pNodeF = new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);

	pMap->printMartrix();

	cout << endl;

	pMap->depthFirstTraverse(0);

	cout << endl;

	pMap->resetNode();

	pMap->breadthFirstTraverse(0);
	cin.get();
	return 0;
}