#ifndef VECTEST_H
#define VECTEST_H

#include <QItemSelectionModel>
#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QWidget>
#include "Vector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class VecTest;
}
QT_END_NAMESPACE

class VecTest : public QWidget {
  Q_OBJECT

 public:
  VecTest(QWidget* parent = nullptr);
  ~VecTest();

 private slots:
  void on_randomButton_clicked();
  void on_resetButton_clicked();
  void on_delButton_clicked();
  void on_setButton_clicked();
  void on_upButton_clicked();
  void on_downButton_clicked();
  void on_insBeforeButton_clicked();
  void on_insAfterButton_clicked();
  void on_delByValue_clicked();

 private:
  Ui::VecTest* ui;
  QStandardItemModel* model;
  QItemSelectionModel* sel;
  Vector<QStandardItem*> vec;

  void refresh();
  void swap(int a, int b);
};
#endif  // VECTEST_H
