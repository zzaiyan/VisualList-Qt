#include "home.h"
#include "ui_home.h"

Home::Home(QWidget* parent) : QWidget(parent), ui(new Ui::Home) {
  ui->setupUi(this);
  model = new QStandardItemModel(this);
  model->setHorizontalHeaderItem(0, new QStandardItem("数据"));
  sel = new QItemSelectionModel(model);
  ui->tableView->setModel(model);
  ui->tableView->setModel(model);         //设置数据模型
  ui->tableView->setSelectionModel(sel);  //设置选择模型
  ui->tableView->setColumnWidth(0, 160);
}

Home::~Home() {
  delete model;
  delete ui;
}

void Home::refresh() {
  if (model->rowCount() - vec.size() > 0)
    model->removeRows(vec.size(), model->rowCount() - vec.size());
}

void Home::swap(int a, int b) {
  auto temp = vec[a]->text();
  vec[a]->setText(vec[b]->text());
  vec[b]->setText(temp);
}

void Home::on_randomButton_clicked() {
  auto eleNum = ui->lineEdit->text().toInt();

  for (int i = 0; i < vec.size(); i++)
    delete vec[i];
  vec.clear();

  for (int i = 0; i < eleNum; i++)
    vec.push_back(new QStandardItem(QString::number(rand() % 100)));

  for (int i = 0; i < vec.size(); i++)
    model->setItem(i, 0, vec[i]);

  refresh();
  ui->lineEdit->setText(QString::number(model->rowCount()));
}

void Home::on_resetButton_clicked() {
  for (int i = 0; i < vec.size(); i++)
    delete vec[i];
  vec.clear();
  refresh();
}

void Home::on_delButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
  delete vec[curIndex.row()];
  vec.remove(curIndex.row());
  if (curIndex.row() == model->rowCount() - 1)  //最后一行
    model->removeRow(curIndex.row());           //删除最后一行
  else {
    model->removeRow(curIndex.row());  //删除一行，并重新设置当前选择行
    sel->setCurrentIndex(curIndex, QItemSelectionModel::Select);
  }
}

void Home::on_setButton_clicked() {
  int idx = sel->currentIndex().row();  //获取索引
  vec[idx]->setText(ui->lineEdit->text());
}

void Home::on_upButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  if (curIndex.row() > 0) {
    swap(curIndex.row(), curIndex.row() - 1);
    sel->setCurrentIndex(curIndex.siblingAtRow(sel->currentIndex().row() - 1),
                         QItemSelectionModel::Select);
    sel->select(curIndex, QItemSelectionModel::Deselect);
  }
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
}

void Home::on_downButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  if (curIndex.row() < vec.size() - 1) {
    swap(curIndex.row(), curIndex.row() + 1);
    sel->setCurrentIndex(curIndex.siblingAtRow(sel->currentIndex().row() + 1),
                         QItemSelectionModel::Select);
    sel->select(curIndex, QItemSelectionModel::Deselect);
  }
  //  ui->lineEdit->setText(QString::number(curIndex.row()));
}

void Home::on_insBeforeButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  vec.insert(curIndex.row(), new QStandardItem(ui->lineEdit->text()));
  model->insertRow(curIndex.row());
  model->setItem(curIndex.row(), vec[curIndex.row()]);
  ui->lineEdit->setText(QString::number(vec.size()));
}

void Home::on_insAfterButton_clicked() {
  QModelIndex curIndex = sel->currentIndex();  //获取模型索引
  vec.insert(curIndex.row() + 1, new QStandardItem(ui->lineEdit->text()));
  model->insertRow(curIndex.row() + 1);
  model->setItem(curIndex.row() + 1, vec[curIndex.row() + 1]);
  ui->lineEdit->setText(QString::number(vec.size()));
}
