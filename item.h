#ifndef ITEM_H
#define ITEM_H
#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QPixmap>

#define WIDTH 5

class Item {
  QPixmap* pix;
  int rank;

 public:
  Item(QPixmap* p, int r) : pix(p), rank(r) {}
  void drawRect() {
    QPainter painter(pix);
    QPen pen(Qt::black);
    painter.setPen(pen);

    int col = rank % WIDTH, row = rank / WIDTH;
    int x = 100 + 130 * col, y = 75 + 100 * row;

    painter.drawRect(x, y, 80, 50);
    qDebug() << col << row;
  }
};

#undef WIDTH
#endif  // ITEM_H
