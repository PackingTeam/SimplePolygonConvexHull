#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SimplePolygonConvexHull/Sklansky72.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(AlgorithmsTests)
	{
	public:
		
		TEST_METHOD(Sklansky1972)
		{
			SimplePolygon testExample1;
			testExample1.points.push_back(Point(0, 0));
			testExample1.points.push_back(Point(50, -5));
			testExample1.points.push_back(Point(30, 20));
			testExample1.points.push_back(Point(50, 40));
			testExample1.points.push_back(Point(40, 20));
			testExample1.points.push_back(Point(90, 0));
			testExample1.points.push_back(Point(50, 50));
			Sklansky72 alg;
			alg.getConvexHull(testExample1);

			// �ڴ˷�����Ӧ���Ĵ����
			vector<int> result;
			result.push_back(0);
			result.push_back(1);
			result.push_back(3);
			result.push_back(4);
			result.push_back(5);
			result.push_back(6);

			for (int i = 0; i < result.size(); i++)
			{
				Assert::AreEqual(result[i], testExample1.convexHull[i]);
			}

			SimplePolygon testExample2;
			testExample2.points.push_back(Point(0, 0));
			testExample2.points.push_back(Point(50, -5));
			testExample2.points.push_back(Point(30, 20));
			testExample2.points.push_back(Point(90, 0));
			testExample2.points.push_back(Point(50, 50));
			alg.getConvexHull(testExample2);

			// �ڴ˷�����Ӧ������ȷ��
			vector<int> result2;
			result2.push_back(0);
			result2.push_back(1);
			result2.push_back(3);
			result2.push_back(4);

			for (int i = 0; i < result2.size(); i++)
			{
				Assert::AreEqual(result2[i], testExample2.convexHull[i]);
			}


		}

	};

	TEST_CLASS(BaseMethodTests)
	{
	public:

		TEST_METHOD(ToLeft)
		{
			// �����Ҵ�ֱ��x��
			Point a(0, 0);
			Point b(0, 5);
			Point c(0, 8);
			Assert::AreEqual(true, toLeft(a, b, c));

			// �����Ҵ�ֱ��x��
			c.setPoint(0,3);
			Assert::AreEqual(false, toLeft(a, b, c));

			// �����Ҵ�ֱ��x��
			c.setPoint(0, -5);
			Assert::AreEqual(false, toLeft(a, b, c));

			// һ�����
			c.setPoint(-5,7);
			Assert::AreEqual(true, toLeft(a, b, c));

			// һ�����
			c.setPoint(67.4,23);
			Assert::AreEqual(false, toLeft(a, b, c));

			// �����Ҵ�ֱ��y��
			a.setPoint(0, 0);
			b.setPoint(2, 0);
			c.setPoint(5, 0);
			Assert::AreEqual(true, toLeft(a, b, c));

			// �����Ҵ�ֱ��y��
			c.setPoint(1, 0);
			Assert::AreEqual(false, toLeft(a, b, c));
			
			// �����Ҵ�ֱ��y��
			c.setPoint(-5, 0);
			Assert::AreEqual(false, toLeft(a, b, c));
		}

	};
}