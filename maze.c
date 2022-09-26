#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,const char* argv[])
{
	char map[10][10]={
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','$','#',' ',' ','#',' ','#','#','#'},
		{'#',' ','#',' ','#','#',' ',' ','#','#'},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ','#',' ','#',' ','#',' ',' ',' '},
		{'#',' ','#',' ',' ',' ','#',' ','#','#'},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ',' ',' ','#',' ','#',' ','#','#'},
		{'#','#','#',' ','#',' ',' ',' ','#','#'},
		{'#','#','#','#','#','#','#','#','#','#'},
	};//  初始化地图数据
	char man_x=1,man_y=1;//记录角色开始位置
	time_t start;
	start=time(NULL);
	for(;;)
	{   //清理屏幕
	    system("clear");             //在头文件stdlib.h
		//显示地图
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				printf("%2c",map[i][j]);
			}
			printf("\n"); 
		}
		//获取方向键并处理
		switch(getch())
		{
			//183上 184下 185右 186左
			
			case 183:if(map[man_x-1][man_y] == ' ')
			{
				map[man_x][man_y]=' ';
				map[--man_x][man_y]='$';// 前--直接减1
			}
			break;
			case 184:if(map[man_x+1][man_y] == ' ')
			{
				map[man_x][man_y]=' ';
				map[++man_x][man_y]='$';
			}
			break;
			case 185:if(map[man_x][man_y+1] == ' ')
			{
				map[man_x][man_y]=' ';
				map[man_x][++man_y]='$';
			}
			break;
			case 186:if(map[man_x][man_y-1] == ' ')
			{
				map[man_x][man_y]=' ';
				map[man_x][--man_y]='$';
			}
			break;
		}
		if(map[man_x][man_y] == map[4][9])       //判断是否到达出口
		{
			system("clear");                     //使最后一步能够显示，也可直接将判断语句放在switch之前
			for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
				{
					printf("%2c",map[i][j]);
				}
				printf("\n");
			}
			printf("成功走出迷宫，游戏胜利！共用时%d秒\n",time(NULL)-start);
			break;
		}

	}
}
