#include <iostream>
#include <stack>

using namespace std;
const int LABY_MAX = 24;/*最大迷宫尺寸*/
typedef enum {
    BACKTRACKED,/*所有方向均尝试失败后回溯过的*/
    AVAILABLE,/*原始可用的*/
    ROUTE,/*在当前路径上的*/
    WALL/*不可使用的(墙*/
} Status;/*迷宫单元状态*/

typedef enum {/*单元的相对邻接方向*/
    UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY
} ESWN;/*未定、东、南、西、北、无路可通*/

/// 依次转至下一邻接方向
inline ESWN nextESWN(ESWN eswn) {
    return ESWN(eswn + 1);
}

struct Cell {
    int x, y;/*x坐标\y坐标*/
    Status status;/*类型*/
    ESWN incoming, outgoing;/*进入、走出方向*/
};/*迷宫格点*/
Cell laby[LABY_MAX][LABY_MAX];/*迷宫*/

/// 查询当前位置的相邻格点
inline Cell *neighbor(Cell *cell);

/// 查询当前位置的相邻结点
inline Cell *advance(Cell *cell);

/// 迷宫寻径算法:在单元s至t之间规划
bool labyinth(Cell Lady[LABY_MAX][LABY_MAX], Cell *s, Cell *t);

int main() {
    // TODO
    return 0;
}

Cell *neighbor(Cell *cell) {
    switch (cell->outgoing) {
        case EAST:/*向东*/
            return cell + LABY_MAX;
        case SOUTH:/*向南*/
            return cell + 1;
        case WEST:/*向西*/
            return cell - LABY_MAX;
        case NORTH:/*向北*/
            return cell - 1;
        default:
            exit(-1);
    }
}

Cell *advance(Cell *cell) {
    Cell *next;
    switch (cell->outgoing) {
        case EAST:/*向东*/
            next = cell + LABY_MAX;
            next->incoming = WEST;
            break;
        case SOUTH:/*向南*/
            next = cell + 1;
            next->incoming = NORTH;
            break;
        case WEST:/*向西*/
            next = cell - LABY_MAX;
            next->incoming = EAST;
            break;
        case NORTH:/*向北*/
            next = cell - 1;
            next->incoming = SOUTH;
            break;
        default:
            exit(-1);
    }
    return next;
}

bool labyinth(Cell (*Lady)[24], Cell *s, Cell *t) {
    if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) {
        return false;
    }/*退化情况*/
    stack<Cell *> path;/*用栈记录通路*/
    s->incoming = UNKNOWN;/*起点*/
    s->status = ROUTE;
    path.push(s);
    do {/*从起点出发不断试探、回溯，直到抵达终点，或者穷尽所有可能*/
        Cell *c = path.top();/*检查当前位置(栈顶)*/
        if (c == t) {/*若已抵达终点,则找到了一条通路;否则,(沿尚未试探的方向)向前试探*/
            return true;
        }
        while (NO_WAY > (c->outgoing = nextESWN(c->outgoing))) {/*逐一检查所有方向*/
            if (AVAILABLE == neighbor(c)->status) {/*若所有方向都已尝试过*/
                break;
            }
        }
        if (NO_WAY <= c->outgoing) {/*若所有方向都已尝试过*/
            c->status = BACKTRACKED;
            c = path.top();
            path.pop();
        } else {/*否则,向前试探一步*/
            path.push(c = advance(c));
            c->outgoing = UNKNOWN;
            c->status = ROUTE;
        }
    } while (path.empty());
    return false;
}
