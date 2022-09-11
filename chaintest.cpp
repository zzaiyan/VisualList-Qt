#include "chaintest.h"
#include "ui_chaintest.h"

ChainTest::ChainTest(QWidget* parent) : QWidget(parent), ui(new Ui::ChainTest) {
  ui->setupUi(this);
  screen = ui->screenLabel;
  QPainter painter(screen);
  QPen pen((QColor(0, 0, 0)));
  painter.setPen(pen);
  painter.drawLine(0, 0, 100, 100);
}

ChainTest::~ChainTest() {
  delete ui;
}
