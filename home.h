#ifndef HOME_H
#define HOME_H

#include <QItemSelectionModel>
#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QWidget>
#include "Vector.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Home;
}
QT_END_NAMESPACE

class Home : public QWidget {
  Q_OBJECT

 public:
  Home(QWidget* parent = nullptr);
  ~Home();

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
  Ui::Home* ui;
  QStandardItemModel* model;
  QItemSelectionModel* sel;
  Vector<QStandardItem*> vec;

  void refresh();
  void swap(int a, int b);
};
#endif  // HOME_H
