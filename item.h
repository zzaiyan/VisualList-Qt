#ifndef ITEM_H
#define ITEM_H
#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QPixmap>

#define WIDTH 6

class Item {
  QPixmap* pix;
  QString data;
  //  int rank;

  void drawRect(int rank);
  void drawText(int rank);
  void drawArrow(int rank);

 public:
  Item() {}
  Item(QPixmap* p, const QString& str) : pix(p), data(str) {
    if (str.isEmpty())
      data = "Node";
  }
  ~Item() {}
  void setData(const QString& str) { data = str; }
  QString getData() { return data; }
  void draw(int rank) { drawRect(rank), drawText(rank), drawArrow(rank); }

  static int getX(int rank) {
    int col = rank % WIDTH;
    return 60 + col * 120;
  }
  static int getY(int rank) {
    int row = rank / WIDTH;
    return 30 + row * 60;
  }
  //  int getRank();
};

#undef WIDTH
#endif  // ITEM_H
