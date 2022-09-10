#ifndef LISTTEST_H
#define LISTTEST_H

#include <QItemSelectionModel>
#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QWidget>
#include "Vector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ListTest;
}
QT_END_NAMESPACE

class ListTest : public QWidget {
  Q_OBJECT

 public:
  ListTest(QWidget* parent = nullptr);
  ~ListTest();

 private slots:
  void on_randomButton_clicked();
  void on_resetButton_clicked();
  void on_delButton_clicked();
  void on_setButton_clicked();
  void on_upButton_clicked();
  void on_downButton_clicked();
  void on_insBeforeButton_clicked();
  void on_insAfterButton_clicked();

 private:
  Ui::ListTest* ui;
  QStandardItemModel* model;
  QItemSelectionModel* sel;
  Vector<QStandardItem*> vec;

  void refresh();
  void swap(int a, int b);
};
#endif  // LISTTEST_H
