#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string inp = ui->lineEdit->text().toStdString();
    string output = "";

    for(int i=0; i<inp.size(); i++){
        string binary = bitset<8>(int (inp.at(i))).to_string();
        output = output +  binary ;
    }

    int parity = count(output.begin(), output.end(), '1')%2;
    output = output + to_string(parity);

    while(output.find("111111") != output.npos){
        size_t pos = output.find("111111");
        output.insert(pos+5,"0");
}

    ui->label_2->setText(QString::fromStdString(output));
}
