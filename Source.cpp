
#include <iostream>
#include <vector>

using namespace std;

class coord
{
private:
	float xPos;
	float yPos;

public:
	coord()
	{
		xPos = 0;
		yPos = 0;
	}
	coord operator*(coord s)
	{
		xPos *= s.xPos;
		yPos *= s.yPos;
		return *this;
	}
	coord(float x, float y) :xPos(x), yPos(y) {}
	void SetCoords()
	{
		
		cout << "X:";
		cin >> xPos;
		cout << "Y:";
		cin >> yPos;
	}
	coord operator- (coord s)
	{
		coord out;
		out.xPos = this->xPos - s.xPos;
		out.yPos = this->yPos - s.yPos;
		return out;
	}
	void showCoords()
	{
		cout << "X:" << xPos << endl << "Y:" << yPos;
	}
	bool operator<(coord x)
	{
		return this->xPos - x.xPos < x.xPos - this->xPos;
	}

	bool operator>(coord x)
	{
		return this->xPos - x.xPos > x.xPos - this->xPos;
	}
	coord operator+(coord s)
	{
		coord out;
		out.xPos = xPos + s.xPos;
		out.yPos = yPos + s.yPos;
		return out;
	}

	void operator=(coord x)
	{
		this->xPos = x.xPos;
		this->yPos = x.yPos;
	}

	float sum()
	{
		return xPos + yPos;
	}

};

coord findClose(coord myCoord, coord* money, int size)
{
	coord closest = money[0];
	
	for (int i = 1; i < size; ++i)
	{
		if (closest < coord(0, 0))
			closest = closest * coord(-1, -1);
		if (myCoord - closest > myCoord - money[i])
			closest = money[i];

	}
	return closest;
}

coord* setMoney(int size)
{

	coord* money = new coord[size];
	for (int i = 0; i < size; i++)
		money[i].SetCoords();
	
	return money;
}

void Work()
{
	cout << "Set you coordinates\n";
	coord myCoord;
	myCoord.SetCoords();
	int size;
	cout << "Enter size: ";
	cin >> size;
	coord* money = setMoney(size);
	coord closest = findClose(myCoord, money, size);
	cout << "Closest coords is\n";
	closest.showCoords();
}



int main()
{
	Work();
	return 0;
}

//  5 5 2 4 4 1 1
//	3 3 2 4 4 1 1