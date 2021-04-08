#include "coord.h"

double degree2Radian(double deg) { return acos(-1) * deg / 180; }

sVector vec(double x, double y) {
    sVector vec = {
        .x = x,
        .y = y,
    };
    return vec;
}

double length(sVector vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }

sVector add(sVector vec1, sVector vec2) {
    sVector vec = {
        .x = vec1.x + vec2.x,
        .y = vec1.y + vec2.y,
    };
    return vec;
}

sVector sub(sVector vec1, sVector vec2) {
    sVector vec = {
        .x = vec1.x - vec2.x,
        .y = vec1.y - vec2.y,
    };
    return vec;
}

sVector scale(sVector vec, double rate) {
    vec.x *= rate;
    vec.y *= rate;
    return vec;
}

sPolar point2Polor(sVector vec) {
    sPolar plr = {
        .r = length(vec),
        .ang = atan2(vec.y, vec.x),
    };
    return plr;
}

sVector polar2Vector(sPolar plr) {
    sVector vec = {
        .x = plr.r * cos(plr.ang),
        .y = plr.r * sin(plr.ang),
    };
    return vec;
}

sPolar rotatePolar(sPolar plr, double rad) {
    plr.ang += rad;
    return plr;
}

sVector rotateVector(sVector vec, double rad) {
    vec = polar2Vector(rotatePolar(point2Polor(vec), rad));
    return vec;
}
