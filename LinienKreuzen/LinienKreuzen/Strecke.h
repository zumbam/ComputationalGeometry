#pragma once
class Strecke
{
public:
	float p1, q1, p2, q2;

	~Strecke();
	Strecke(float _p1, float _p2, float _q1, float _q2);

float CCW(float r1, float r2);
};


