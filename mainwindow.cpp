#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString password;

    QString pattern = "abcdefghijklmnopqrstuvwxyz";
    QString upLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString digits = "0123456789";
    QString symbols = "!@#$%^&*()_+=-[]{}";

    if (ui->checkBox->isChecked())
        pattern += upLetters;
    if (ui->checkBox_2->isChecked())
        pattern += digits;
    if (ui->checkBox_3->isChecked())
        pattern += symbols;

    ui->textEdit->clear();

    for (int i = 0; i < 4; i++)
    {
        while (password.size() < ui->spinBox->value())
        {
            password += pattern[rand() % pattern.size()];
        }

        qDebug() << password;

        ui->textEdit->append(password + '\n');

        password.clear();
    }

}

