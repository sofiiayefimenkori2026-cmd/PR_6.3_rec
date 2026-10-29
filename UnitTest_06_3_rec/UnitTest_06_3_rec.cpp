#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.3_rec/PR_6.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest063rec
{
    TEST_CLASS(UnitTest063rec)
    {
    public:
        TEST_METHOD(TestSumPositiveStandardRec)
        {
            int a[] = { -3, 5, 0, 7, -2, 10 };
            Assert::AreEqual(22, SumPositive(a, 6, 0));
        }

        TEST_METHOD(TestSumPositiveTemplateRec)
        {
            double b[] = { -1.5, 2.5, 3.0, -0.5 };
            Assert::AreEqual(5.5, SumPositiveTemplate(b, 4, 0), 1e-6);
        }

        TEST_METHOD(TestSumPositiveTemplateRecInt)
        {
            int a[] = { -3, 5, 0, 7, -2, 10 };
            Assert::AreEqual(22, SumPositive<int>(a, 6, 0));
        }

        TEST_METHOD(TestCreateRecWithinBounds)
        {
            int a[10];
            Create(a, 10, -5, 5, 0);
            for (int i = 0; i < 10; i++)
            {
                Assert::IsTrue(a[i] >= -5 && a[i] <= 5);
            }
        }
    };
}
