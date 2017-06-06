/************************************************************************		
\link	www.twinklingstar.cn
\author Twinkling Star
\date	2014/05/26
\details 
****************************************************************************/
#pragma once

#include "SrGeometricTools.h"
#include "SrDataType.h"
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
using namespace  std;

#define Real		SrReal
#define Point2D		SrPoint2D
#define Vector2D	SrVector2D

#define EPS			SR_EPS

typedef list<Point2D>				PointList;
typedef list<Point2D>::iterator		PointListIterator;

/*
\brief	判断三点p0-p1-p2的朝向，若是逆时针方向，返回1；若是顺时针方向，返回-1；否则，返回0.
*/
int Orientation(const Point2D& p0, const Point2D& p1, const Point2D& p2);

void Divide(PointList& ptList, const Point2D& p0, const Point2D& p1, int sign, PointList& part1, PointList& part2);

void Partition(PointList& ptList, const Point2D& p0, const Point2D& p1, PointList& result);

void RandomPointIndex(int n, int& p0, int& p1);

extern void GenerateSimplePolygon(const Point2D* pts, int numPoint, Point2D*& simple, int& numSimple);