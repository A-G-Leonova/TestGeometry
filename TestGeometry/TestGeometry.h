#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>



using namespace std;

class Figure {
protected:
    vector <double> center;
    double Radius;
public:
    Figure()
    {
        center = { 0.0, 0.0, 0.0 };
    }
    Figure(vector <double> c)
    {
        center = c;
    }
    vector <double> GetCenter()
    {
        return center;
    }
    double GetRadius()
    {
        return Radius;
    }
    virtual void WriteWhoIAM() {};
    virtual vector<double> PointPert(double t) {
        return center;
    }
    virtual vector<double> DerivativePert(double t) {
        return { 0.0,0.0,0.0 };
    }

};

class Circle : public Figure {
protected:
    //double Radius;
public:
    Circle()
    {
        center = { 0.0,0.0,0.0 };
        Radius = 1.0;
    }
    Circle(double r)
    {
        center = { 0.0,0.0,0.0 };
        Radius = abs(r);
    }
    Circle(vector <double> v)
    {
        center = v;
        Radius = 1.0;
    }
    Circle(vector <double> v, double r)
    {
        center = v;
        Radius = abs(r);
    }

    void WriteWhoIAM() override
    {
        std::cout << "I am Circle" << "\n";
    }
    vector<double> PointPert(double t) override 
    {
        vector<double> point(3);
        point[2] = center[2];
        point[0] = center[0] + Radius * cos(t);
        point[1] = center[1] + Radius * sin(t);
        return point;
    }
    vector<double> DerivativePert(double t) {
        vector<double> point(3);
        point[2] = 0.0;
        point[0] = -Radius * sin(t);
        point[1] = Radius * cos(t);
        return point;
        
    }

};


class Ellipse : public Figure {
protected:
    double Radius2;

public:
    Ellipse()
    {
        center = { 0.0,0.0,0.0 };
        Radius = 1.0;
        Radius2 = 2.0;

    }
    Ellipse(double r1, double r2)
    {
        center = { 0.0,0.0,0.0 };
        Radius = abs(r1);
        Radius2 = abs(r2);

    }
    Ellipse(vector <double> v)
    {
        center = v;
        Radius = 1.0;
        Radius2 = 2.0;
    }
    Ellipse(vector <double> v, double r1, double r2)
    {
        center = v;
        Radius = abs(r1);
        Radius2 = abs(r2);
    }
    double GetRadius2()
    {
        return Radius2;
    }
    void WriteWhoIAM() override
    {
        std::cout << "I am Ellipse" << "\n";
    }
    vector<double> PointPert(double t) override
    {
        vector<double> point(3);
        point[2] = center[2];
        point[0] = center[0] + Radius * cos(t);
        point[1] = center[1] + Radius2 * sin(t);
        return point;
    }
    vector<double> DerivativePert(double t) {
        vector<double> point(3);
        point[2] = 0.0;
        point[0] = -Radius * sin(t);
        point[1] = Radius2 * cos(t);
        return point;

    }
};


class Helix : public Figure {
protected:
    double Step;

public:
    Helix()
    {
        center = { 0.0,0.0,0.0 };
        Radius = 1.0;
        Step = 1.0;

    }
    Helix(double r1, double r2)
    {
        center = { 0.0,0.0,0.0 };
        Radius = abs(r1);
        Step = abs(r2);

    }
    Helix(vector <double> v)
    {
        center = v;
        Radius = 1.0;
        Step = 2.0;
    }
    Helix(vector <double> v, double r1, double r2)
    {
        center = v;
        Radius = abs(r1);
        Step = abs(r2);
    }
    double GetStep()
    {
        return Step;
    }
    void WriteWhoIAM() override
    {
        std::cout << "I am Helix" << "\n";
    }
    vector<double> PointPert(double t) override
    {
        vector<double> point(3);
        point[2] = center[2] +  t*Step/(2*acos(-1.0));
        point[0] = center[0] + Radius * cos(t);
        point[1] = center[1] + Radius * sin(t);
        return point;
    }
    vector<double> DerivativePert(double t) {
        vector<double> point(3);
        point[2] = Step / (2 * acos(-1.0));
        point[0] = -Radius * sin(t);
        point[1] = Radius * cos(t);
        return point;

    }
};

Circle GenerateRandomCircle(double dmin, double dmax)
{
   
    vector<double> c(3);
    double value;
    for (int i = 0; i < 3; i++)
    {
         value = rand() % (int)pow(10, 3);
        value = dmin + (value / pow(10, 3)) * (dmax - dmin);
        c[i] = value;
    }
    value = rand() % (int)pow(10, 3);
    value = dmin + (value / pow(10, 3)) * (dmax - dmin);
    return Circle(c, value);

}

Ellipse GenerateRandomEllipse(double dmin, double dmax)
{
   
    vector<double> c(3);
    double value, value1;
    for (int i = 0; i < 3; i++)
    {
        value = rand() % (int)pow(10, 3);
        value = dmin + (value / pow(10, 3)) * (dmax - dmin);
        c[i] = value;
    }
    value = rand() % (int)pow(10, 3);
    value = dmin + (value / pow(10, 3)) * (dmax - dmin);
    value1 = rand() % (int)pow(10, 3);
    value1 = dmin + (value / pow(10, 3)) * (dmax - dmin);
    return Ellipse(c, value, value1);

}

Helix GenerateRandomHelix(double dmin, double dmax)
{
   
    vector<double> c(3);
    double value, value1;
    for (int i = 0; i < 3; i++)
    {
        value = rand() % (int)pow(10, 3);
        value = dmin + (value / pow(10, 3)) * (dmax - dmin);
        c[i] = value;
    }
    value = rand() % (int)pow(10, 3);
    value = dmin + (value / pow(10, 3)) * (dmax - dmin);
    value1 = rand() % (int)pow(10, 3);
    value1 = dmin + (value / pow(10, 3)) * (dmax - dmin);
    return Helix(c, value, value1);

}


