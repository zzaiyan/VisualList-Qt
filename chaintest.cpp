#include "chaintest.h"
#include "ui_chaintest.h"

ChainTest::ChainTest(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::ChainTest)
{
  ui->setupUi(this);
}

ChainTest::~ChainTest()
{
  delete ui;
}
