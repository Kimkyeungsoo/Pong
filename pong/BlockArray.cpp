#include "BlockArray.h"

BlockArray::BlockArray(const int& x, const int& y)
	: xCount(x), yCount(y)
{
	blockArray = new Block[x * y];

	float xPosition = (1920.0 * 0.5) - (120.0 * (x / 2));
	float yPosition = 0.0;

	int temp = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = temp; j < x + temp; j++)
		{
			blockArray[j].SetPosition(xPosition, yPosition);
			xPosition += 120.0;
		}
		temp += x;
		yPosition += 70.0;
		xPosition = (1920.0 * 0.5) - (120.0 * (x / 2));
	}
}

BlockArray::~BlockArray()
{
	delete[]blockArray;
}

FloatRect BlockArray::GetGlobalBounds(int i)
{
	return blockArray[i].GetGlobalBounds();
}

const RectangleShape& BlockArray::GetShape(int i)
{
	return blockArray[i].GetShape();
}
