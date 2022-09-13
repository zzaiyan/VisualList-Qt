#include "chaintest.h"
#include "ui_chaintest.h"

#define WIDTH 6

ChainTest::ChainTest(QWidget* parent) : QWidget(parent), ui(new Ui::ChainTest) {
  ui->setupUi(this);
  list = new LinkList<Item>;
  screen = ui->screenLabel;
  pix = new QPixmap(screen->width(), 500);

  qDebug() << screen->width() << screen->height();
}

ChainTest::~ChainTest() {
  delete ui;
}

void ChainTest::repaint() {
  pix->fill(Qt::white);
  refresh();

  int cnt = 0;
  for (auto p = list->begin(); p != list->end(); p = p->succ) {
    refresh();
    //    sleep(10);
    p->data.draw(cnt++);
  }
  refresh();
}

void ChainTest::sleep(int ms) {
  QTime reachTime = QTime::currentTime().addMSecs(ms);
  while (QTime::currentTime() < reachTime)
    QApplication::processEvents(QEventLoop::AllEvents, 100);
}

void ChainTest::on_butPushBack_clicked() {
  if (list->size()) {
    ui->butPushBack->setEnabled(false);
    list->push_back(Item(pix, ui->lineEdit->text()));
    repaint();
    ui->butPushBack->setEnabled(true);
  }
}

void ChainTest::on_butPushFront_clicked() {
  if (list->size()) {
    list->insertAfter(list->first(), Item(pix, ui->lineEdit->text()));
    repaint();
  }
}

void ChainTest::on_butReset_clicked() {
  ui->butReset->setEnabled(0);
  ui->butReset->setText("正在清空……");
  while (list->size()) {
    list->pop_back();
    repaint();
    sleep(100);
  }
  ui->butReset->setEnabled(1);
  ui->butReset->setText("清空");
}

void ChainTest::on_butMake_clicked() {
  if (list->size() == 0) {
    list->push_front(Item(pix, QString("Head")));
    repaint();
  }
}

void ChainTest::on_butInsByValue_clicked() {
  if (list->size() > 1) {
    QString e = QInputDialog::getText(this, "输入", "插入到该值之后：");
    if (e.isEmpty())
      return;
    for (auto p = list->begin(); p != list->end(); p = p->succ)
      if (p->data.getData() == e) {
        list->insertAfter(p, Item(pix, ui->lineEdit->text()));
        break;
      }
    repaint();
  }
}

void ChainTest::on_butPopFront_clicked() {
  if (list->size() > 1) {
    list->remove(list->first()->succ);
    repaint();
  }
}

void ChainTest::on_butPopBack_clicked() {
  if (list->size() > 1) {
    list->remove(list->last());
    repaint();
  }
}

void ChainTest::on_butDelByValue_clicked() {
  if (list->size() > 1) {
    QString text = ui->lineEdit->text();
    if (text.isEmpty())
      return;
    for (auto p = list->begin(); p != list->end(); p = p->succ)
      if (p->data.getData() == text) {
        list->remove(p);
      }
    repaint();
  }
}

void ChainTest::on_butReverse_clicked() {
  int cnt = (list->size() - 1) / 2;
  for (auto p1 = list->first()->succ, p2 = list->last(); cnt-- > 0;
       p1 = p1->succ, p2 = p2->pred) {
    auto temp = p1->data.getData();
    p1->data.setData(p2->data.getData());
    p2->data.setData(temp);
  }
  repaint();
}

void ChainTest::on_butRandom_clicked() {
  if (list->size()) {
    ui->butRandom->setEnabled(0);
    ui->butRandom->setText("正在插入……");
    int eleNum = ui->lineEdit->text().toInt();
    for (int i = 0; i < eleNum; i++) {
      list->push_back(Item(pix, QString::number(rand() % 100 + 1)));
      repaint();
      sleep(100);
    }
    ui->butRandom->setEnabled(1);
    ui->butRandom->setText("随机插入");
  }
}
