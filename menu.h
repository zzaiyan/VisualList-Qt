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

 private:
  Ui::Menu* ui;
  VecTest* vecTest;
  ChainTest* chainTest;
};

#endif  // MENU_H
