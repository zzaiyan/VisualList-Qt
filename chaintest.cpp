#include "chaintest.h"
#include "ui_chaintest.h"

#define WIDTH 5

ChainTest::ChainTest(QWidget* parent) : QWidget(parent), ui(new Ui::ChainTest) {
  ui->setupUi(this);
  list = new LinkList<Item>;
  screen = ui->screenLabel;
  pix = new QPixmap(screen->width(), 500);
  pix->fill(Qt::white);
  qDebug() << screen->width() << screen->height();
  refresh();

  //  for (int i = 0; i < 20; i++)
}

ChainTest::~ChainTest() {
  delete ui;
}

void ChainTest::drawRect(int r) {
  QPainter painter(pix);
  QPen pen(Qt::black);
  painter.setPen(pen);

  int col = r % WIDTH, row = r / WIDTH;
  int x = 100 + 130 * col, y = 75 + 100 * row;

  painter.drawRect(x, y, 80, 50);
  qDebug() << col << row;

  refresh();
}

#undef WIDTH
