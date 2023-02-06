#include <string>
#include "Ball.h"
using namespace std;

// 預設建構函式
Ball::Ball() {
    _radius = 0.0;
    _name = "noname ball";
}

Ball::Ball(double radius, const char *name) {
    _radius = radius;
    _name = name;
}

Ball::Ball(double radius, string &name) {
    _radius = radius;
    _name = name;
}
