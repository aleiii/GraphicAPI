//#pragma once
//#ifdef GRAPHICDRAW_H
//#define GRAPHICDRAW_H

#include <iostream>
#include "GraphicAPI.h"
using namespace std;
namespace ALEI
{
	// Bresenham 算法画直线段
	void line(HDC hdc, int x1, int y1, int x2, int y2);
	// 使用正负法画圆
	void circle(HDC hdc, int x, int y, int r, double r0, double r1);
	// 使用中点算法画椭圆
	void ellipse(HDC hdc, int x0, int y0, int a, int b);
	// 四连通域（内点表示）颜色填充漫水算法
	void Flood_Fill_4(HDC hdc, int x, int y, COLORREF old_color, COLORREF new_color);
	// 阴影线填充算法
	void Shadow_Fill(HDC hdc);
	// 画名字
	void Draw_Name(HDC hdc);
	
}

//#endif