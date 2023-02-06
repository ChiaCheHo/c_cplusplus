#include <string>
using namespace std;

class Ball {
public:
    Ball();
    Ball(double, const char*);
    Ball(double, string&);

    // 實作於類別定義中的函式會自動inline
    double radius() {
        return _radius;
    }

    string& name() {
        return _name;
    }

    void radius(double radius) {
        _radius = radius;
    }

    void name(const char *name) {
        _name = name;
    }

    void name(string& name) {
        _name = name;
    }

    double volumn() {
        return (4 / 3 * 3.14159 * _radius * _radius * _radius);
    }

private:
    double _radius; // Radius
    string _name;   // Name
};