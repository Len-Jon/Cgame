#include<windows.h>
#include<windows.h>
#include<conio.h>
int main() {
	int hX = 0, hY = 0, len = 4, map[900] ={ 0 }, c = 'd', cl = 'd', i = 0;//hX,hY：头坐标，len：蛇长，map：地图，c：方向，cl：方向缓存，i：循环变量
	srand((unsigned)malloc(!system("mode con:cols=60 lines=30")));//生成随机数种子并初始化页面
	for (map[rand() % 900] = -1; 1; Sleep(100)) {//随机生成食物（-1），循环延时100ms
		if (_kbhit() && (cl = _getch()) && cl < 97 ? (cl += 32) : 1)//判断是否有输入>（输入大写转小写，永真）> 执行下一步
			if (cl == 'a'&&c != 'd' || cl == 'd'&&c != 'a' ||//运算符优先级 && > || 
				cl == 'w'&&c != 's' || cl == 's'&&c != 'w')c = cl;//若输入方向与当前方向相反，不执行方向改变操作
		if (c == 'a'&&--hX < 0 || c == 'd'&&++hX == 30 ||
			c == 'w'&&--hY < 0 || c == 's'&&++hY == 30)exit(0);//根据方向改变蛇头坐标，逻辑短路保证不会误执行，改变后若出界直接退出
		if (map[hY * 30 + hX] && (map[hY * 30 + hX] > 0 ? exit(0), 1 : ++len))//如果头坐标为空地（0），逻辑短路跳过，大于0（蛇身）退出，小于零说明吃到方块，长度自增并进入下一步
			for (i = rand() % 900; map[i] || !(map[i] = -1); i = rand() % 900);//生成一个随机数，如果地图对应位置不为0继续生成随机数，否则在该位置生成方块
		else for (i = 0; i < 900; i++)map[i] > 0 ? map[i] -= 1 : 0;//头坐标为空地，蛇身全部-1，蛇尾就是1-1=0，变空地
		for (system("cls"), map[hY * 30 + hX] = len, i = 0; i < 900; i++)//头坐标赋值为长度，遍历
			_cputs(map[i] > 0 ? "()" : map[i] ? "00" : "  ");//输出
	}
}