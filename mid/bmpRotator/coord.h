#pragma once
#include <math.h>

typedef struct _sVector {
	double x, y;
} sVector;

typedef struct _sPolar {
	double r, ang;
} sPolar;

double degree2Radian(double deg);

sVector vec(double x, double y);

double length(sVector vec);

sVector add(sVector vec1, sVector vec2);

sVector sub(sVector vec1, sVector vec2);

sVector scale(sVector vec, double rate);

sPolar vector2Polor(sVector vec);

sVector polar2Vector(sPolar plr);

sPolar rotatePolar(sPolar plr, double rad);

sVector rotateVector(sVector vec, double rad);
