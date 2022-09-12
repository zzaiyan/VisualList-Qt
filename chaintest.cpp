#include "chaintest.h"
#include "ui_chaintest.h"

#define WIDTH 6

ChainTest::ChainTest(QWidget* parent) : QWidget(parent), ui(new Ui::ChainTest) {
  ui->setupUi(this);
  list = new LinkList<Item>;
  screen = ui->screenLabel;
  pix = new QPixmap(screen->width(), 500);

  qDebug() << screen->width() << screen->height();

  //  for (int i = 0; i < 1; i++)
  //    list->push_back(Item(pix));

  //  repaint();
}

ChainTest::~ChainTest() {
  delete ui;
}

void ChainTest::repaint() {
  pix->fill(Qt::white);
  refresh();

  int cnt = 0;
  for (auto p = list->begin(); p != list->end(); p = p->succ, cnt++) {
    refresh();
    //    sleep(10);
    p->data.drawRect(cnt);
    p->data.drawText(cnt);
  }
  refresh();
}

void ChainTest::sleep(int ms) {
  QTime reachTime = QTime::currentTime().addMSecs(ms);
  while (QTime::currentTime() < reachTime)
    QApplication::processEvents(QEventLoop::AllEvents, 100);
}

void ChainTest::on_butPushBack_clicked() {
  ui->butPushBack->setEnabled(false);
  list->push_back(Item(pix, ui->lineEdit->text()));
  repaint();
  ui->butPushBack->setEnabled(true);
}

void ChainTest::on_butPushFront_clicked() {
  list->insertAfter(list->first(), Item(pix, ui->lineEdit->text()));
  repaint();
}

void ChainTest::on_butReset_clicked() {
  list->clear();
  repaint();
}

void ChainTest::on_butMake_clicked() {
  if (list->size() == 0) {
    list->push_front(Item(pix, QString("Head")));
    repaint();
  }
}
