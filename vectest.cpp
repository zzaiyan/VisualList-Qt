#include "vectest.h"
#include "ui_vectest.h"

VecTest::VecTest(QWidget* parent) : QWidget(parent), ui(new Ui::VecTest) {
  ui->setupUi(this);
  model = new QStandardItemModel(this);
  model->setHorizontalHeaderItem(0, new QStandardItem("数据"));
  sel = new QItemSelectionModel(model);
  ui->tableView->setModel(model);
  ui->tableView->setModel(model);         //设置数据模型
  ui->tableView->setSelectionModel(sel);  //设置选择模型
  //  ui->tableView->setColumnWidth(0, 160);
}

VecTest::~VecTest() {
  delete model;
  delete ui;
}

void VecTest::refresh() {
  if (model->rowCount() - vec.size() > 0)
    model->removeRows(vec.size(), model->rowCount() - vec.size());
}

void VecTest::swap(int a, int b) {
  auto temp = vec[a]->text();
  vec[a]->setText(vec[b]->text());
  vec[b]->setText(temp);
}

void VecTest::on_randomButton_clicked() {
  auto eleNum = ui->lineEdit->text().toInt();

  for (int i = 0; i < vec.size(); i++)
    delete vec[i];
  vec.clear();

  for (int i = 0; i < eleNum; i++)
    vec.push_back(new QStandardItem(QString::number(rand() % 100)));

  //  vec.remove("77");

  model->removeRows(0, model->rowCount());

  for (int i = 0; i < vec.size(); i++)
    model->setItem(i, 0, vec[i]);

  refresh();
  ui->lineEdit->setText(QString::number(model->rowCount()));
}

void VecTest::on_resetButton_clicked() {
  for (int i = 0; i < vec.size(); i++)
    delete vec[i];
  vec.clear();
  refresh();
}

void VecTest::on_delButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
  if (curIndex.row() >= 0 && curIndex.row() < vec.size()) {
    delete vec[curIndex.row()];
    vec.remove(curIndex.row());
    if (curIndex.row() == model->rowCount() - 1)  //最后一行
      model->removeRow(curIndex.row());           //删除最后一行
    else {
      model->removeRow(curIndex.row());  //删除一行，并重新设置当前选择行
      sel->setCurrentIndex(curIndex, QItemSelectionModel::Select);
    }
  }
}

void VecTest::on_setButton_clicked() {
  int idx = sel->currentIndex().row();  //获取索引
  if (idx >= 0 && idx < vec.size())
    vec[idx]->setText(ui->lineEdit->text());
}

void VecTest::on_upButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  if (curIndex.row() > 0 && curIndex.row() < vec.size()) {
    swap(curIndex.row(), curIndex.row() - 1);
    sel->setCurrentIndex(curIndex.siblingAtRow(sel->currentIndex().row() - 1),
                         QItemSelectionModel::Select);
    sel->select(curIndex, QItemSelectionModel::Deselect);
  }
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
}

void VecTest::on_downButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  if (curIndex.row() >= 0 && curIndex.row() < vec.size() - 1) {
    swap(curIndex.row(), curIndex.row() + 1);
    sel->setCurrentIndex(curIndex.siblingAtRow(sel->currentIndex().row() + 1),
                         QItemSelectionModel::Select);
    sel->select(curIndex, QItemSelectionModel::Deselect);
  }
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
}

void VecTest::on_insBeforeButton_clicked() {
  int idx = sel->currentIndex().row();
  if (idx == -1)
    idx = 0;
  vec.insert(idx, new QStandardItem(ui->lineEdit->text()));
  model->insertRow(idx);
  model->setItem(idx, vec[idx]);

  //  ui->lineEdit->setText(QString::number(vec.size()));
}

void VecTest::on_insAfterButton_clicked() {
  int idx = sel->currentIndex().row() + 1;
  if (idx == 0)
    idx = vec.size();
  idx = std::max(idx, 0);
  vec.insert(idx, new QStandardItem(ui->lineEdit->text()));
  model->insertRow(idx);
  model->setItem(idx, vec[idx]);
  //  ui->lineEdit->setText(QString::number(vec.size()));
}

void VecTest::on_delByValue_clicked() {
  auto text = ui->lineEdit->text();
  if (text.isEmpty())
    return;
  for (int i = 0; i < vec.size(); i++)
    if (vec[i]->text() == text) {
      model->removeRow(i);
      delete vec[i];
      vec.remove(i);
      i--;
    }
}
