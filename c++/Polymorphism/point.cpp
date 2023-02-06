// Fig. 10.2: point.cpp
// Point類別成員函式定義
#include<iostream>

usingstd::cout;

#include "point.h" // Point類別定義

// 內容建構子
Point::Point( intxValue, intyValue )
    : x( xValue ), y( yValue )
{


} // end Point constructor

// 設定x座標
voidPoint::setX( intxValue )
{
    x = xValue;

} // end function setX

// 回傳 x座標
int Point::getX() const
{
    return x;

}   // end function getX

// 設定 y座標
void Point::setY( int yValue)
{
    y = yValue;

} // end function setY

// 傳回 y座標
int Point::getY() const
{
    return y;

} // end function getY

// 印出 Point物件內容
void Point::print() const
{
    cout<<'['<<getX() <<","<<getY()<<']';

} // end function print