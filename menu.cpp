#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget* parent) : QWidget(parent), ui(new Ui::Menu) {
  ui->setupUi(this);
  vecTest = new VecTest;
  chainTest = new ChainTest;
  vecTest->setWindowModality(Qt::ApplicationModal);
  chainTest->setWindowModality(Qt::ApplicationModal);
}

Menu::~Menu() {
  delete ui;
}
