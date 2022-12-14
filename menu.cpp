#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget* parent) : QWidget(parent), ui(new Ui::Menu) {
  ui->setupUi(this);
  //  vecTest = nullptr;
  vecTest = new VecTest;
  vecTest->setWindowModality(Qt::ApplicationModal);
  //  chainTest = nullptr;
  chainTest = new ChainTest;
  chainTest->setWindowModality(Qt::ApplicationModal);
}

Menu::~Menu() {
  delete ui;
}

void Menu::on_buttonSeq_clicked() {
  //  if (vecTest)
  //    delete vecTest;
  //  vecTest = new VecTest;
  //  vecTest->setWindowModality(Qt::ApplicationModal);
  //  vecTest->setAttribute(Qt::WA_DeleteOnClose);
  vecTest->show();
}

void Menu::on_buttonLink_clicked() {
  //  if (chainTest)
  //    delete chainTest;
  //  chainTest = new ChainTest;
  //  chainTest->setWindowModality(Qt::ApplicationModal);
  //  chainTest->setAttribute(Qt::WA_DeleteOnClose, true);
  chainTest->show();
}
