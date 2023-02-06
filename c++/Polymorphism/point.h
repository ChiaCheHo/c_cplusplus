// Fig. 10.1: point.h2
// Point類別定義3
#ifndefPOINT_H4
#definePOINT_H5
classPoint {

public:

    Point( int= 0, int= 0); // 內定建構子

    void setX( int);  // 設定X軸座標
    int getX() const;  // 傳回X軸座標

    void setY( int);  // 設定y軸座標
    int getY() const;  // 傳回y軸座標

    void print() const;  // 輸出Point物件內容

private:

    intx;  // 存放x軸的值
    inty;  // 存放y軸的值

}; // end class Point
#endif