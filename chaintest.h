#ifndef CHAINTEST_H
#define CHAINTEST_H

#include <QBrush>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "LinkList.h"
#include "item.h"

namespace Ui {
class ChainTest;
}

class ChainTest : public QWidget {
  Q_OBJECT

 public:
  explicit ChainTest(QWidget* parent = nullptr);
  ~ChainTest();

 private:
  Ui::ChainTest* ui;
  QLabel* screen;
  QPixmap* pix;
  LinkList<Item>* list;

  void refresh() { screen->setPixmap(*pix); }
  void drawRect(int r);
};

#endif  // CHAINTEST_H
