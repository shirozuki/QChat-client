#include "widget.h"
#include "ui_widget.h"
#include "connection.h"
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, [&]()
    {
        QTextStream textStream(socket);
        auto text = textStream.readAll();
        ui->textEdit->append(text);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_clicked()
{
    QTextStream textStream(socket);
    textStream << ui->username->text() << ": " << ui->message->text();
    socket->flush();
    ui->message->clear();
}

void Widget::on_connect_clicked()
{
    Connection connectionDialog(this);
    if (connectionDialog.exec() == QDialog::Rejected)
    {
        return;
    }

    socket->connectToHost(connectionDialog.address(), connectionDialog.port());
}
