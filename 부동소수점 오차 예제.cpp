#include <windows.h> // XMVerifyCPUSupport에 필요함
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

const float Epsilon = 0.001f;

bool Equals(float lhs, float rhs)
{
	// lhs와 rhs 사이의 거리가 Epsilon보다 작은가?
	return fabs(lhs - rhs) < Epsilon ? true : false;
}

int main() {

	cout.precision(8);

	// SSE2를 지원하는지 확인한다.
	if (!XMVerifyCPUSupport())
	{
		cout << "DirectXMath를 지원하지 않음";
		return 0;
	}

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	// 수학적으로는 길이가 반드시 1이어야 한다. 수치적으로도 그럴까?
	cout << LU << endl;
	if (LU == 1.0f)
		cout << "길이 1" << endl;
	else
		cout << "길이 1 아님" << endl;

	// 1을 임의의 지수로 거듭제곱해도 여전히 1이어야 한다. 실제로 그럴까?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	
	


	return 0;
}