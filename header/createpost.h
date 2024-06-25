#ifndef CREATEPOST_H
#define CREATEPOST_H

#include <QDialog>

namespace Ui {
class createpost;
}

class createpost : public QDialog
{
    Q_OBJECT

public:
    explicit createpost(QWidget *parent = nullptr);
    ~createpost();

private slots:
    void on_share_clicked();

private:
    Ui::createpost *ui;
};

#endif // CREATEPOST_H
