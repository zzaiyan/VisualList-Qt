#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "chaintest.h"
#include "vectest.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget {
  Q_OBJECT

 public:
  explicit Menu(QWidget* parent = nullptr);
  ~Menu();

 private slots:
  void on_buttonSeq_clicked();

  void on_buttonLink_clicked();

 private:
  Ui::Menu* ui;
  VecTest* vecTest;
  ChainTest* chainTest;
};

#endif  // MENU_H
