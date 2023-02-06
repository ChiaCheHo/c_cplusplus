#include <algorithm>
#include <functional>
#include <memory>
#include <vector>
#include <iostream>

// g++ template_1.cpp -o template_1 -std=gnu++14

// using namespace std;
class test
{
private:
    int t = 0;

public:
    int hello(int t);
    void print() { std::cout << this->t << std::endl; }
    test(/* args */);
    ~test();
};

int test::hello(int t)
{
    // the name of  class varible t and the name of function argument t is same,
    // so using this pointer to segment for programmer
    return this->t = t;
}

test::test(/* args */)
{
}

test::~test()
{
}

template <typename T>
class Calculator
{
private:
    T result = 0;

public:
    T add(T a, T b)
    {
        result = a + b;
        return result;
    }
    T sub(T a, T b)
    {
        result = a - b;
        return result;
    }
    T multiply(T a, T b)
    {
        result = a * b;
        return result;
    }
    T divide(T a, T b)
    {
        result = a / b;
        return result;
    }
    T getResult()
    {
        return result;
    }
    void reset()
    {
        result = 0;
    }
    void print()
    {
        std::cout << "hello test..." << std::endl;
    }
};

// Overload Class Calculator
template <typename T>
class Calculator<std::vector<T>>
{
private:
    std::vector<T> result;
    std::shared_ptr<std::vector<T>> resultv;

public:
    void add(std::vector<T> a, std::vector<T> b)
    {
        std::transform(a.begin(), a.end(), b.begin(),
                       std::back_inserter(result), std::plus<double>());
    }
    void getResult()
    {
        for (auto it = this->result.begin(); it != this->result.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << '\n';
    }
    void addA(std::vector<T> *a, std::vector<T> *b, std::shared_ptr<std::vector<T>> &result)
    // void addA(std::vector<T> *a, std::vector<T> *b, std::shared_ptr<std::vector<T>> *result)
    {
        std::cout << "addA: " << std::endl;
        std::transform(a->begin(), a->end(), b->begin(),
                       result->begin(), std::plus<double>());
        for (auto it = result->begin(); it != result->end(); ++it)
        {
            std::cout << *it << " ";
        }
        // std::transform(a->begin(), a->end(), b->begin(),
        //                (*result)->begin(), std::plus<double>());
        // for (auto it = (*result)->begin(); it != (*result)->end(); ++it)
        // {
        //     std::cout << *it << " ";
        // }
        std::cout << "\n";
    }
    void createResultArray(int n)
    {
        this->resultv = std::make_shared<std::vector<T>>(n);
        std::cout << "this->resultv->size(): " << this->resultv->size() << std::endl;
    }
};

// Print the every elements of the Array a
template <typename T>
std::vector<T> *printVA(std::vector<T> *a)
{
    for (auto it = a->begin(); it != a->end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

void Callee(Calculator<int> &obj)
{
    // https://blog.jaycetyle.com/2019/11/passing-smart-pointer/
    // obj.DoSomething();
    obj.print();
}

void Caller()
{
    std::unique_ptr<Calculator<int>> uniqueObj = std::make_unique<Calculator<int>>();
    Callee(*uniqueObj);
    // Object obj;
    // Callee(obj); // OK !
}

int main(int argc, char const *argv[])
{
    auto cald = std::make_shared<Calculator<double>>();
    cald->divide(5, 3);
    std::cout << cald->getResult() << std::endl;

    auto cali = std::make_shared<Calculator<int>>();
    cali->divide(5, 3);
    std::cout << cali->getResult() << std::endl;

    auto t = std::make_shared<test>();
    t->print();
    t->hello(10);
    t->print();
    auto calv = std::make_shared<Calculator<std::vector<double>>>();
    std::vector<double> aA = {1.1, 2.2, 3.3, 4.4};
    std::vector<double> bA = {1.2, 2.3, 1.3, 4.4};
    std::shared_ptr<std::vector<double>> rA = std::make_shared<std::vector<double>>(aA.size());
    std::cout << "rA vector size: " << rA->size() << std::endl;
    calv->createResultArray(aA.size());
    // calv->addA(&aA, &bA, std::move(rA));
    calv->addA(&aA, &bA, rA);
    // calv->addA(&aA, &bA, &rA);
    printVA(&aA);
    std::vector<double> a = {1.1};
    std::vector<double> b = {1.2};
    // calv->createResultArray(4);
    calv->add(a, b);
    calv->getResult();

    Caller();
    return 0;
}