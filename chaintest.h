#ifndef CHAINTEST_H
#define CHAINTEST_H

#include <QWidget>

namespace Ui {
class ChainTest;
}

class ChainTest : public QWidget
{
  Q_OBJECT

 public:
  explicit ChainTest(QWidget *parent = nullptr);
  ~ChainTest();

 private:
  Ui::ChainTest *ui;
};

#endif // CHAINTEST_H
