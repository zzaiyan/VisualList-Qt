#ifndef CHAINTEST_H
#define CHAINTEST_H

#include <QBrush>
#include <QDebug>
#include <QInputDialog>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QTime>
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

 private slots:
  void on_butPushBack_clicked();
  void on_butPushFront_clicked();
  void on_butReset_clicked();
  void on_butMake_clicked();
  void on_butInsByValue_clicked();

  void on_butPopFront_clicked();

  void on_butPopBack_clicked();

  void on_butDelByValue_clicked();

  void on_butReverse_clicked();

  void on_butRandom_clicked();

 private:
  Ui::ChainTest* ui;
  QLabel* screen;
  QPixmap* pix;
  LinkList<Item>* list;

  void refresh() { screen->setPixmap(*pix); }
  void repaint();
  void sleep(int ms);
};

#endif  // CHAINTEST_H
