#include "item.h"
#define WIDTH 6

void Item::drawRect(int rank) {
  QPainter painter(pix);
  painter.setPen(Qt::gray);

  painter.drawRect(getX(rank), getY(rank), 80, 30);
}

void Item::drawText(int rank) {
  QPainter painter(pix);
  painter.setPen(Qt::black);

  painter.drawText(getX(rank), getY(rank), 80, 30, Qt::AlignCenter, data);
}

void Item::fillColor(int rank) {
  QPainter painter(pix);
  if (data == "Node")
    painter.setBrush(Qt::red);
  else
    painter.setBrush(Qt::yellow);
}

#undef WIDTH
