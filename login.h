#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class logIn;
}

class logIn : public QDialog
{
    Q_OBJECT

public:
    explicit logIn(QWidget *parent = nullptr);
    ~logIn();

private:
    Ui::logIn *ui;

    // QDialog interface
public slots:
    void accept();
    void login_ok();
    void login_no();
signals:
    void return_to_entry();
    void login_ok_signal();
    void checkClient(const QString &, const QString &);
    void wrongLogin();

private slots:
    void on_buttonBox_rejected();
};

#endif // LOGIN_H
