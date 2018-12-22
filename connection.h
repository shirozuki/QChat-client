#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();
    QString address() const;
    quint16 port() const;

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::Connection *ui;
    QString serverAddress;
    quint16 serverPort;
};

inline QString Connection::address() const
{
    return serverAddress;
}

inline quint16 Connection::port() const
{
    return serverPort;
}
#endif // CONNECTION_H
