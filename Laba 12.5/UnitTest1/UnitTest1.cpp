#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 15.5/Laba 15.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            // Arrange
            Node* stack = nullptr;
            push(stack, 'c');
            push(stack, 'a');
            push(stack, 'b');
            push(stack, 'd');

            // Act
            sortStack(stack);

            // Assert
            Assert::AreEqual('a', pop(stack));
            Assert::AreEqual('b', pop(stack));
            Assert::AreEqual('c', pop(stack));
            Assert::AreEqual('d', pop(stack));
            Assert::IsNull(stack);
		}
	};
}
