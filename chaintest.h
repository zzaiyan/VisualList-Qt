#ifndef CHAINTEST_H
#define CHAINTEST_H

#include <QBrush>
#include <QGraphicsView>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QWidget>

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
  QGraphicsScene* scene;
  QLabel* screen;
};

#endif  // CHAINTEST_H
