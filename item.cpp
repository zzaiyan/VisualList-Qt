#include "item.h"
#define WIDTH 6

void Item::drawRect(int rank) {
  QPainter painter(pix);
  if (data == "Head")
    painter.setBrush(Qt::yellow);
  else
    painter.setBrush(QColor(222, 222, 222));

  painter.drawRect(getX(rank), getY(rank), 80, 30);
}

void Item::drawText(int rank) {
  QPainter painter(pix);
  if (data == "Head")
    painter.setPen(Qt::red);
  else
    painter.setPen(Qt::black);

  painter.drawText(getX(rank), getY(rank), 80, 30, Qt::AlignCenter, data);
}

void Item::drawArrow(int rank) {
  QPainter painter(pix);
  if (rank == 0)
    return;
  painter.setPen(QPen(QColor(255, 00, 00), 2));

  if (rank % WIDTH == 0) {
    painter.drawLine(getX(rank) - 35, getY(rank) + 15, getX(rank) - 35,
                     getY(rank) - 15);
    painter.drawLine(getX(rank) - 35 + 750, getY(rank) - 15, getX(rank) - 35,
                     getY(rank) - 15);
    painter.drawLine(getX(rank) - 35 + 750, getY(rank) - 15,
                     getX(rank) - 35 + 750, getY(rank) - 45);
    painter.drawLine(getX(rank) - 65 + 750, getY(rank) - 45,
                     getX(rank) - 35 + 750, getY(rank) - 45);
  }

  painter.drawLine(getX(rank) - 35, getY(rank) + 15, getX(rank) - 5,
                   getY(rank) + 15);
  painter.drawLine(getX(rank) - 10, getY(rank) + 20, getX(rank) - 5,
                   getY(rank) + 15);
  painter.drawLine(getX(rank) - 10, getY(rank) + 10, getX(rank) - 5,
                   getY(rank) + 15);
}

#undef WIDTH
