#include "connection.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
}

Connection::~Connection()
{
    delete ui;
}

void Connection::on_ok_clicked()
{
    serverAddress = ui->address->text();
    serverPort = ui->port->value();
    accept();
}

void Connection::on_cancel_clicked()
{
    reject();
}
