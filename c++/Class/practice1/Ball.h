#include <string>
using namespace std;

class Ball {
public:
    Ball();
    Ball(double, const char*);
    Ball(double, string&);
 
    double radius();
    string& name();
 
    void radius(double);
    void name(const char*);
    void name(string&);
 
    double volumn();

private:
    double _radius; // Radius
    string _name;   // Name
};